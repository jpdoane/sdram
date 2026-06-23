TOP=tb_dual_master_sdram
# TOP=tb_sdram

SRC= \
    ../rtl/sdram_core.sv \
    ../rtl/dual_master_sdram.sv \
    ../models/MT48LC8M16A2.sv \
    $(TOP).sv 

##
## xsim
##

# SNAPSHOT   = sim_snapshot
# Targets
# all: simulate
# compile:
# 	xvlog -sv $(SRC)
# elaborate: compile
# 	xelab -debug typical -top $(TOP) -snapshot $(SNAPSHOT)
# simulate: elaborate
# 	xsim $(SNAPSHOT) -runall


##
## verilator
##

all:
	verilator \
	    --binary \
	    --timing \
	    -Wall \
	    -Wno-fatal \
		--trace-fst \
	    $(SRC) \
	    --top-module $(TOP)

	./obj_dir/V$(TOP)

wave:
	gtkwave $(TOP).fst

## Hardware-in-the-loop test via Python + xsct subprocess
## Requires: board connected, hw_server reachable, bitfile built.
## Optional overrides:
##   BITFILE=<path>   select a specific revision bitfile
##   XSA=<path>       matching .xsa
##   HIL_ARGS=...     extra args passed to hil_test.py (e.g. --no-program --test 2)
BITFILE  ?= ../hw/build/zynq_sdram.bit
XSA      ?= ../hw/build/zynq_sdram.xsa
HIL_ARGS ?=

hil:
	python3 hil_test.py --bitfile $(BITFILE) --xsa $(XSA) $(HIL_ARGS)

clean:
	rm -rf obj_dir *.fst