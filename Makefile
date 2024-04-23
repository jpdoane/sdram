PROJ := sdram
# PIN_DEF := hx8kboard.pcf
# DEVICE := hx8k

SIMCOMPILER := iverilog
SIMULATOR := vvp
VIEWER := gtkwave

TOPMODULE := sdram_nes_tb

# SYNTHFLAGS := -p synth_ice40 -top $(TOPMODULE)
# PNRFLAGS := -d $(subst hx,,$(subst lp,,$(DEVICE)))
SIMCOMPFLAGS := -g2012 -pfileline=1
SIMFLAGS := 

TB = sdram_nes_tb

SRCS = $(wildcard hdl/*.sv)
MODELSRC = models/MT48LC8M16A2.v
TBSRCS = tb/$(TB).sv
VVP = sim/$(TB).vvp
VCD = sim/$(TB).vcd

# BINS := $(PROJ).bin
# RPTS := $(patsubst %.bin,%.rpt,$(BINS))
# BLIFS := $(patsubst %.bin,%.blif,$(BINS))
# ASCS := $(patsubst %.bin,%.asc,$(BINS))

all: test

# timing: $(RPTS)

# bitstream: $(BINS)

test: $(VCD)

view: $(VCD)
	gtkwave $(VCD) &

# $(BLIFS): %.blif: %.v $(MODSRCS)
#         yosys '$(SYNTHFLAGS) -blif $@' $^

# $(ASCS): %.asc: $(PIN_DEF) %.blif
#         arachne-pnr $(PNRFLAGS) -o $@ -p $^

# $(BINS): %.bin: %.asc
#         icepack $< $@

# $(RPTS): %.rpt: %.asc
#         icetime -d $(DEVICE) -mtr $@ $<

$(VVP): %.vvp: $(TBSRCS) $(SRCS) $(MODELSRC) 
	$(SIMCOMPILER) $(SIMCOMPFLAGS) $^ -o $@

$(VCD): $(VVP)
	$(SIMULATOR) $(SIMFLAGS) $^
	mv *.vcd sim

clean:
	@rm -f $(VVP) $(VCD) $(BLIFS) $(BINS) $(RPTS)