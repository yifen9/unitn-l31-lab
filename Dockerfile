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

RUN apt-get update && apt-get install -y --no-install-recommends ca-certificates curl \
 && rm -rf /var/lib/apt/lists/* \
 && CLI_FLAVOR=musl curl -fsSL https://raw.githubusercontent.com/yifen9/c-labkit/main/packaging/cli/linux/install.sh | bash \
 && c-labkit-cli --version

 RUN apt-get update && apt-get install -y --no-install-recommends build-essential autoconf automake libtool pkg-config git tar gzip libgmp-dev libffi-dev \
 && POLYML_TAG=$(git ls-remote --tags --refs https://github.com/polyml/polyml.git 'v*' | awk -F/ '{print $3}' | sort -V | tail -n1) \
 && curl -fsSL "https://github.com/polyml/polyml/archive/refs/tags/${POLYML_TAG}.tar.gz" -o /tmp/polyml.tar.gz \
 && tar -xzf /tmp/polyml.tar.gz -C /tmp \
 && cd "/tmp/polyml-${POLYML_TAG#v}" \
 && test -f configure || autoreconf -fi \
 && ./configure --prefix=/usr \
 && make -j"$(nproc)" \
 && make install \
 && ldconfig \
 && cd / \
 && rm -rf /tmp/polyml* \
 && apt-get purge -y --auto-remove build-essential autoconf automake libtool pkg-config git \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
