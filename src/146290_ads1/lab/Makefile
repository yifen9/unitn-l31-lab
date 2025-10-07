# ====== User knobs ======
LAB ?= l1                  # current lab, e.g. l1, l2, ...
LAB_DIR := $(LAB)
APP := $(LAB)              # exe name defaults to lab name

# ====== Phony help ======
.PHONY: help
help:
	@echo "make new LAB=l3     # scaffold labs/l3"
	@echo "make format         # clang-format all C/C headers"
	@echo "make build          # build current LAB=$(LAB)"
	@echo "make run            # run labs/$(LAB)/$(APP)"
	@echo "make test           # run unit tests for LAB=$(LAB)"
	@echo "make clean          # clean current lab"
	@echo "make clean-all      # clean all labs"

# ====== Scaffold a new lab ======
.PHONY: new
new:
	@test -n "$(LAB)" || (echo "LAB is empty"; exit 1)
	mkdir -p $(LAB_DIR)/src $(LAB_DIR)/include $(LAB_DIR)/tests
	printf "#include <stdio.h>\nint main(void){puts(\"$(LAB) ok\");return 0;}\n" > $(LAB_DIR)/src/main.c
	printf "# Lab $(LAB)\n\nBuild: \`make\`\nRun: \`./$(APP)\`\n" > $(LAB_DIR)/README.md
	# write a template Makefile into the lab directory
	printf "%s\n" "\
CC?=gcc\n\
CFLAGS?=-O2 -g -Wall -Wextra\n\
CPPFLAGS?=-Iinclude -I../common/include\n\
LDFLAGS?=\n\
SRCS:=\$(wildcard src/*.c) \$(wildcard ../common/src/*.c)\n\
OBJS:=\$(SRCS:.c=.o)\n\
DEPS:=\$(OBJS:.o=.d)\n\
APP?=$(APP)\n\
\n\
.PHONY: all\n\
all: \$(APP)\n\
\n\
\$(APP): \$(OBJS)\n\
\t\$(CC) \$(CFLAGS) \$(LDFLAGS) \$$^ -o \$$@\n\
\n\
%.o: %.c\n\
\t\$(CC) -c \$(CPPFLAGS) \$(CFLAGS) -MMD -MP -MF \$$(@:.o=.d) \$$< -o \$$@\n\
\n\
# simple test runner placeholder\n\
.PHONY: check test\n\
check test:\n\
\t@[ -x tests/test_runner ] && ./tests/test_runner || echo \"(no tests yet)\"\n\
\n\
.PHONY: clean\n\
clean:\n\
\t\$(RM) -r \$(OBJS) \$(DEPS) \$(APP) tests/test_runner\n\
\n\
-include \$(DEPS)\n" > $(LAB_DIR)/Makefile

# ====== Format entire repo ======
.PHONY: format
format:
	@command -v clang-format >/dev/null || { echo "clang-format not found"; exit 1; }
	find ./ -type f \( -name "*.c" -o -name "*.h" \) -print0 | xargs -0 clang-format -i

# ====== Build current lab ======
.PHONY: build
build:
	$(MAKE) -C $(LAB_DIR)

# ====== Run current lab ======
.PHONY: run
run: build
	@$(LAB_DIR)/$(APP)

# ====== Test current lab ======
.PHONY: test
test:
	$(MAKE) -C $(LAB_DIR) check

# ====== Clean ======
.PHONY: clean
clean:
	$(MAKE) -C $(LAB_DIR) clean

.PHONY: clean-all
clean-all:
	@for d in labs/*; do \
	  [ -d "$$d" ] || continue; \
	  $(MAKE) -C "$$d" clean || true; \
	done
