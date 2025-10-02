FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive LANG=C.UTF-8 LC_ALL=C.UTF-8 PATH=/root/.bun/bin:$PATH

COPY ops/apt /ops/apt

ARG APT_PROFILES="base common"

RUN find /ops/apt -type f -name '*.txt' -exec sed -i 's/\r$//' {} + && \
    for f in /ops/apt/base.txt /ops/apt/common.txt $(for p in $APT_PROFILES; do test -f /ops/apt/courses/${p}.txt && echo /ops/apt/courses/${p}.txt; done); do \
      test -f "$f" && sed -e '$a\' "$f"; \
    done | awk '{sub(/#.*/,""); gsub(/[ \t]+/,"\n"); print}' | sed '/^\s*$/d' | sort -u > /ops/all.txt

RUN apt-get update && xargs -r -a /ops/all.txt apt-get install -y --no-install-recommends && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y --no-install-recommends gnupg && rm -rf /var/lib/apt/lists/*
RUN curl -fsSL "https://keyserver.ubuntu.com/pks/lookup?op=get&search=0x21805a48e6cbba6b991abe76646193862b759810" | gpg --dearmor -o /usr/share/keyrings/ppa-kathara-archive-keyring.gpg
RUN echo "deb [ signed-by=/usr/share/keyrings/ppa-kathara-archive-keyring.gpg ] http://ppa.launchpad.net/katharaframework/kathara/ubuntu jammy main" > /etc/apt/sources.list.d/kathara.list && \
    echo "deb-src [ signed-by=/usr/share/keyrings/ppa-kathara-archive-keyring.gpg ] http://ppa.launchpad.net/katharaframework/kathara/ubuntu jammy main" >> /etc/apt/sources.list.d/kathara.list
RUN apt-get update && apt-get install -y --no-install-recommends kathara && rm -rf /var/lib/apt/lists/*

ENV RUSTUP_HOME=/opt/rustup CARGO_HOME=/opt/cargo PATH=/opt/cargo/bin:$PATH

RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y --profile minimal && rustup default stable

WORKDIR /workspace
