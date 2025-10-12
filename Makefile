.DEFAULT_GOAL := help
SHELL := /usr/bin/env bash
CMD := $(word 2,$(MAKECMDGOALS))
MSG := $(strip $(wordlist 3,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS)))

.PHONY: help git

help:
	@echo "Usage:"
	@echo "  make git init"
	@echo "  make git update"
	@echo "  make git commit <message>"

git:
	@test -n "$(CMD)" || { echo "subcommand required: init|update|commit"; exit 1; }
	@if [ "$(CMD)" = "init" ]; then \
		eval "$$(ssh-agent -s)"; \
		ssh-add $$HOME/.ssh/id_ed25519; \
		git config user.name yifen9; \
		git config user.email mail@yifen9.li; \
	elif [ "$(CMD)" = "update" ]; then \
		git fetch --all -p && git pull origin main && git submodule update --init --recursive && git submodule update --recursive --remote; \
	elif [ "$(CMD)" = "commit" ]; then \
		test -n "$(MSG)" || { echo "commit message required"; exit 1; }; \
		git add -A; \
		git diff --staged --quiet && { echo "nothing to commit"; exit 0; }; \
		git commit -m "$(MSG)"; \
		git push origin main; \
	else \
		echo "unknown subcommand: $(CMD)"; exit 1; \
	fi

%:
	@:
