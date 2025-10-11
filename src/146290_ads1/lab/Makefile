.DEFAULT_GOAL := help
LAB := $(word 2,$(MAKECMDGOALS))
EX  := $(word 3,$(MAKECMDGOALS))
ARG := $(word 4,$(MAKECMDGOALS))
$(LAB): ; @:
$(EX):  ; @:
$(ARG): ; @:

.PHONY: help cmake new run test fmt rm
help:
	@echo "make new l1 [e1]"
	@echo "make run l1 [e1]"
	@echo "make test l1 [e1 [case|new|re|rm]]"
	@echo "make rm l1 [e1]"
	@echo "make fmt"

cmake:
	@mkdir -p build && cd build && cmake ..

new:
	@test -n "$(LAB)" || { echo "usage: make new <lab> [ex]"; exit 1; }
	@mkdir -p src/$(LAB)/include src/$(LAB)/src src/$(LAB)/tests
	@if [ -n "$(EX)" ]; then \
	  test ! -e src/$(LAB)/src/$(EX) || { echo "exists: src/$(LAB)/src/$(EX)"; exit 1; } ; \
	  mkdir -p src/$(LAB)/src/$(EX) src/$(LAB)/tests/$(EX)/0 ; \
	  cp template/exercise/src/main.c src/$(LAB)/src/$(EX)/main.c ; \
	  cp template/exercise/tests/0/i.txt src/$(LAB)/tests/$(EX)/0/i.txt ; \
	  cp template/exercise/tests/0/o.txt src/$(LAB)/tests/$(EX)/0/o.txt ; \
	else \
	  cp -R template/lab/. src/$(LAB)/ ; \
	fi

run: cmake
	@test -n "$(LAB)" || { echo "usage: make run <lab> [ex]"; exit 1; }
	@if [ -n "$(EX)" ]; then cd build && cmake --build . --target run_$(LAB)_$(EX) ; \
	else cd build && cmake --build . --target run_$(LAB)_all ; fi

test: cmake
	@test -n "$(LAB)" || { echo "usage: make test <lab> [ex [case|new|re|rm]]"; exit 1; }
	@if [ -z "$(EX)" ]; then \
	  cd build && cmake --build . --target build_$(LAB)_all && ctest -R "^$(LAB)_" --output-on-failure ; \
	else \
	  if [ -z "$(ARG)" ]; then \
	    cd build && cmake --build . --target $(LAB)_$(EX) && ctest -R "^$(LAB)_$(EX)_" --output-on-failure ; \
	  elif [ "$(ARG)" = "new" ] || [ "$(ARG)" = "re" ] || [ "$(ARG)" = "rm" ]; then \
	    scripts/io_case.sh $(LAB) $(EX) $(ARG) ; \
	  else \
	    cd build && cmake --build . --target $(LAB)_$(EX) && ctest -R "^$(LAB)_$(EX)_$(ARG)$$" --output-on-failure ; \
	  fi ; \
	fi


fmt:
	@command -v clang-format >/dev/null || { echo "clang-format not found"; exit 1; }
	@find src include template -type f \( -name "*.c" -o -name "*.h" \) -print0 | xargs -0 clang-format -i

rm:
	@test -n "$(LAB)" || { echo "usage: make rm <lab> [ex]"; exit 1; }
	@if [ -n "$(EX)" ]; then \
	  read -p "remove src/$(LAB)/src/$(EX) and tests? [y/N] " a && [ "$$a" = "y" ] && rm -rf src/$(LAB)/src/$(EX) src/$(LAB)/tests/$(EX) || true ; \
	else \
	  read -p "remove src/$(LAB)? [y/N] " a && [ "$$a" = "y" ] && rm -rf src/$(LAB) || true ; \
	fi