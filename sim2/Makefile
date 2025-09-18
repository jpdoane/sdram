# include ../inc/make.inc

TOP=sdram_axil_tb
VERILATE_TOP=
OBJDIR=obj_dir

# SRCS = sdram_axil_tb2.sv
SRCS = 
SRCS += ../hdl/sdram_core.sv
SRCS += ../hdl/axil_sdram.sv
SRCS += ../hdl/sdram_if.sv
SRCS += ../hdl/taxi_axil_if.sv

SRCS += aximemtest.cpp aximem.cpp

MODELSRC = ../models/MT48LC8M16A2.sv

WAVEFILE=sdram.fst

VERILATOR_FLAGS += -DDEBUG_REG=1
# VERILATOR_FLAGS += --binary -j 0
VERILATOR_FLAGS += -cc --exe
VERILATOR_FLAGS += --build -j
VERILATOR_FLAGS += --timing
VERILATOR_FLAGS += --trace-fst
VERILATOR_FLAGS += -I$(OBJDIR)

# CFLAGS += -I$(OBJDIR)
CFLAGS += -DWAVEFILE=$(WAVEFILE) 

# VERILATOR_SRC=aximemtest2.cpp
# VERILATOR_SRC=aximemtest.cpp aximem.cpp
VERILATOR_TARGET=$(OBJDIR)/V$(TOP)

# include ../inc/make.verilator

$(OBJDIR):
	-mkdir -p $(OBJDIR)

$(OBJDIR)/V%: %.sv $(SRCS) $(MODELSRC) | $(OBJDIR)
	verilator $(VERILATOR_FLAGS) -CFLAGS $(CFLAGS) --top $(basename $(notdir $<)) $^


# $(VERILATOR_TARGET): $(VERILATOR_SRC) $(VMODEL)
# 	-@mkdir $(BUILD_PATH)
# 	g++ $^ $(CCFLAGS) -g -o $@

.DEFAULT_GOAL = $(VERILATOR_TARGET)

# VERILATOR_RUN_FLAGS = +verilator+seed+$(shell bash -c 'echo $$RANDOM')

test: $(VERILATOR_TARGET)
	$< $(VERILATOR_RUN_FLAGS)

view: $(WAVEFILE)
	gtkwave $(WAVEFILE) -a waves.gtkw&

clean:
	rm -rf $(OBJDIR)