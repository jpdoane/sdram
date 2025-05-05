PROJ := sdram
SIMCOMPILER := iverilog
SIMULATOR := vvp
VIEWER := gtkwave

SIMCOMPFLAGS := -g2012
SIMFLAGS := 

TB = sdram_core_tb

SRCS = hdl/sdram_core.sv
SRCS += hdl/sdram_if.sv
SRCS += hdl/sdram_arb.v
MODELSRC = models/MT48LC8M16A2.v
TBSRCS = tb/$(TB).sv

TEST_OBJ = obj_dir/V$(TB)
VCD = $(TB).vcd

VERILATOR_FLAGS = --binary -j 0
VERILATOR_FLAGS += --trace

VERILATOR_RUN_FLAGS = +verilator+seed+$(shell bash -c 'echo $$RANDOM')

$(TEST_OBJ): $(SRCS) $(MODELSRC) $(TBSRCS)
	verilator $(VERILATOR_FLAGS) --top $(TB) $^

all: test

test: $(TEST_OBJ)
	$(TEST_OBJ) $(VERILATOR_RUN_FLAGS)

view: $(VCD)
	gtkwave $(VCD) &

clean:
	@rm -rf obj_dir
	@rm *.vcd	