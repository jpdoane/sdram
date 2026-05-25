TOP=tb_dual_master_sdram
# TOP=tb_sdram

SRC= \
    ../rtl/sdram_core.sv \
    ../rtl/dual_master_sdram.sv \
    ../rtl/sdram_if.sv \
    ../rtl/taxi_axil_if.sv \
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

clean:
	rm -rf obj_dir *.fst