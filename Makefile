PROJ := sdram
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
VVP = sim/$(TB).vvp
VCD = sim/$(TB).vcd

all: test

test: $(VCD)

view: $(VCD)
	gtkwave $(VCD) &


$(VVP): %.vvp: $(TBSRCS) $(SRCS) $(MODELSRC) 
	$(SIMCOMPILER) $(SIMCOMPFLAGS) $^ -o $@

$(VCD): $(VVP)
	$(SIMULATOR) $(SIMFLAGS) $^

clean:
	@rm -f $(VVP) $(VCD) $(BLIFS) $(BINS) $(RPTS)