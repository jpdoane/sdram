include ../inc/make.inc


TOP=sdram_axil_tb
BUILD_PATH=build

RTL_SOURCE = 
RTL_SOURCE += sdram_axil_tb.sv
RTL_SOURCE += ../rtl/sdram_core.sv
RTL_SOURCE += ../rtl/axil_sdram.sv
RTL_SOURCE += ../rtl/sdram_if.sv
RTL_SOURCE += ../rtl/taxi_axil_if.sv
RTL_SOURCE += ../models/MT48LC8M16A2.sv

VERILATOR_FLAGS += -DDEBUG_SDRAM=0
VERILATOR_FLAGS += --timing # enable delays in rtl
VERILATOR_FLAGS += --Mdir $(BUILD_PATH)

TEST_SRC=aximemtest.cpp aximem.cpp
TEST_TARGET=$(BUILD_PATH)/memtest

include ../inc/make.verilator

CCFLAGS += -DWAVEFILE=$(WAVEFILE)
CCFLAGS += -I$(BUILD_PATH) -I../inc

.PHONY: test
test: $(TEST_TARGET)
	$<

.DEFAULT_GOAL = test

$(TEST_TARGET): $(TEST_SRC) $(VMODEL)
	g++ $^ $(CCFLAGS) -g -o $@

clean::
	rm -rf $(BUILD_PATH)