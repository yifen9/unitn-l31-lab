FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive LANG=C.UTF-8 LC_ALL=C.UTF-8 PATH=/root/.bun/bin:$PATH

COPY /ops/apt.txt /ops/apt.txt

RUN set -e; \
    apt-get update \
 && xargs -r -a /ops/apt.txt apt-get install -y --no-install-recommends \
 && rm -rf /var/lib/apt/lists/*

RUN curl -fsSL https://bun.com/install | bash

WORKDIR /workspace