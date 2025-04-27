PROJ := sdram
# PIN_DEF := hx8kboard.pcf
# DEVICE := hx8k

SIMCOMPILER := iverilog
SIMULATOR := vvp
VIEWER := gtkwave

SIMCOMPFLAGS := -g2012
SIMFLAGS := 

TB = sdram_core_tb

SRCS = hdl/sdram_core_32bit.sv
SRCS += hdl/sdram_arb.v
MODELSRC = models/MT48LC8M16A2_dualbus.v
TBSRCS = tb/$(TB).sv

TEST_OBJ = obj_dir/V$(TB)
$(TEST_OBJ): $(SRCS) $(MODELSRC) $(TBSRCS)
	verilator --binary -j 0 --top $(TB) $^

all: test

test: $(TEST_OBJ)
	$(TEST_OBJ)

view: $(VCD)
	gtkwave $(VCD) &

clean:
	@rm -rf obj_dir