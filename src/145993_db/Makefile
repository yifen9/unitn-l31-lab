.DEFAULT_GOAL := help
SHELL := /usr/bin/env bash

.PHONY: help start stop quit status list

help:
	@echo "Usage:"
	@echo "  make start"
	@echo "  make stop"
	@echo "  make quit"
	@echo "  make status"
	@echo "  make list"

start:
	@cd "scripts" && bash ./start.sh

stop:
	@cd "scripts" && bash ./stop.sh

%:
	@:
