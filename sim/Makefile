include ../inc/make.inc


TOP=sdram_axil_tb
BUILD_PATH=build

HDL_SOURCE = 
HDL_SOURCE += sdram_axil_tb.sv
HDL_SOURCE += ../hdl/sdram_core.sv
HDL_SOURCE += ../hdl/axil_sdram.sv
HDL_SOURCE += ../hdl/sdram_if.sv
HDL_SOURCE += ../hdl/taxi_axil_if.sv
HDL_SOURCE += ../models/MT48LC8M16A2.sv

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