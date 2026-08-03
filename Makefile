ROOT := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
VERILATOR ?= verilator
SEED ?= 12345

SUBMISSION_DIR ?= $(ROOT)submission
TESTBENCH_DIR ?= $(ROOT)testbenches
OBJ_DIR ?= $(ROOT)obj_dir
CHECKER_SCRIPT ?= $(ROOT)run_hart_checker.sh

DUT_SOURCES := $(sort $(wildcard $(SUBMISSION_DIR)/*.v))
TB_FILES := $(sort $(wildcard $(TESTBENCH_DIR)/*.v))
TB_NAMES := $(notdir $(basename $(TB_FILES)))

.PHONY: all help check run test student-tests tb list-testbenches clean

all: check

help:
	@echo "Binarytesting Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  make check              Run the checker against submission/*.v"
	@echo "  make student-tests      Build and run every testbench in testbenches/*.v"
	@echo "  make tb TB=<name>       Build and run one testbench by basename"
	@echo "  make test               Run check and then all student tests"
	@echo "  make list-testbenches   Show discovered testbenches"
	@echo "  make clean              Remove obj_dir/ and generated checker outputs"

list-testbenches:
	@printf '%s\n' $(TB_NAMES)

check: $(CHECKER_SCRIPT)
	@cd $(ROOT) && ./run_hart_checker.sh --mode submission --seed $(SEED)

run: check

test: check student-tests

student-tests: $(addprefix tb-,$(TB_NAMES))

tb:
	@if [ -z "$(TB)" ]; then \
		echo "usage: make tb TB=<testbench basename>" >&2; \
		exit 2; \
	fi
	@$(MAKE) tb-$(TB)

tb-%: $(TESTBENCH_DIR)/%.v $(DUT_SOURCES)
	@mkdir -p $(OBJ_DIR)/tb-$*
	@echo "[verilator] $*"
	@$(VERILATOR) --timing --cc --binary --build \
		-Mdir $(OBJ_DIR)/tb-$* \
		-y $(SUBMISSION_DIR) \
		--top-module $* \
		$< $(DUT_SOURCES)
	@$(OBJ_DIR)/tb-$*/V$*

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(ROOT)hart_checker
	rm -f $(ROOT)result.json
