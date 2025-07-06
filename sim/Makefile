PROJ := sdram
SIMCOMPILER := iverilog
SIMULATOR := vvp
VIEWER := gtkwave

SIMCOMPFLAGS := -g2012
SIMFLAGS := 

SRCS =
# SRCS += ../hdl/sdram_core.sv
SRCS += ../hdl/sdram_core_pc2.sv
SRCS += ../hdl/sdram_core_ref.sv
SRCS += ../hdl/sdram_if.sv
# SRCS += ../hdl/sdram_arb.sv
SRCS += ../hdl/axil_sdram.sv
SRCS += ../hdl/taxi_axil_if.sv
MODELSRC = ../models/MT48LC8M16A2.sv

OBJDIR = obj_dir
VCD = sdram.vcd

VERILATOR_FLAGS = --binary -j 0
VERILATOR_FLAGS += --trace

all: test

$(OBJDIR):
	-mkdir -p $(OBJDIR)

# VERILATOR_RUN_FLAGS = +verilator+seed+$(shell bash -c 'echo $$RANDOM')

$(OBJDIR)/V%: %.sv $(SRCS) $(MODELSRC) | $(OBJDIR)
	verilator $(VERILATOR_FLAGS) --top $(basename $(notdir $<)) $^

test: $(OBJDIR)/Vsdram_pc_tb
	$< $(VERILATOR_RUN_FLAGS)

testpc: $(OBJDIR)/Vsdram_pc_tb
	$< $(VERILATOR_RUN_FLAGS)

testaxi: $(OBJDIR)/Vsdram_axil_tb
	$< $(VERILATOR_RUN_FLAGS)

testarb: $(OBJDIR)/Vsdram_arb_tb
	$< $(VERILATOR_RUN_FLAGS)

testref: $(OBJDIR)/Vsdram_ref_tb
	$< $(VERILATOR_RUN_FLAGS)

view: $(VCD)
	gtkwave $(VCD) -a waves.gtkw&

viewref:
	gtkwave sdram_ref.vcd -a waves_ref.gtkw&

clean:
	-@rm -rf obj_dir
	-@rm *.vcd	