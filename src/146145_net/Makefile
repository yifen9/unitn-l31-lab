.DEFAULT_GOAL := help
SHELL := /usr/bin/env bash
LAB_ROOT ?= kathara-lab
LAB := $(word 2,$(MAKECMDGOALS))

.PHONY: help start stop quit status list

help:
	@echo "Usage:"
	@echo "  make start <lab>"
	@echo "  make stop <lab>"
	@echo "  make quit"
	@echo "  make status"
	@echo "  make list"

start:
	@test -n "$(LAB)" || { echo "lab required"; exit 1; }
	@cd "$(LAB_ROOT)/$(LAB)" && bash ./start-lab.sh

stop:
	@test -n "$(LAB)" || { echo "lab required"; exit 1; }
	@cd "$(LAB_ROOT)/$(LAB)" && bash ./stop-lab.sh

quit:
	@kathara wipe -f

status:
	@kathara list

list:
	@find "$(LAB_ROOT)" -mindepth 1 -maxdepth 1 -type d -printf '%f\n' 2>/dev/null || ls -1 "$(LAB_ROOT)"

%:
	@:
