PROJ := sdram
SIMCOMPILER := iverilog
SIMULATOR := vvp
VIEWER := gtkwave

SIMCOMPFLAGS := -g2012
SIMFLAGS := 

TB = sdram_tb

SRCS = hdl/sdram_core.sv
SRCS += hdl/sdram_if.sv
SRCS += hdl/sdram_arb.v
SRCS += hdl/axil_sdram.sv
SRCS += hdl/taxi_axil_if.sv
MODELSRC = models/MT48LC8M16A2.v

TEST_OBJ = obj_dir/V$(TB)
VCD = sdram.vcd

VERILATOR_FLAGS = --binary -j 0
VERILATOR_FLAGS += --trace

# VERILATOR_RUN_FLAGS = +verilator+seed+$(shell bash -c 'echo $$RANDOM')

obj_dir/V% : tb/%.sv $(SRCS) $(MODELSRC)
	verilator $(VERILATOR_FLAGS) --top $(basename $(notdir $<)) $^

all: test

test: obj_dir/Vsdram_tb
	$< $(VERILATOR_RUN_FLAGS)

testaxi: obj_dir/Vsdram_axil_tb
	$< $(VERILATOR_RUN_FLAGS)

view: $(VCD)
	gtkwave $(VCD) &

clean:
	-@rm -rf obj_dir
	-@rm *.vcd	