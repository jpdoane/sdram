# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vsdram_axil_tb.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 1
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vsdram_axil_tb \
	Vsdram_axil_tb___024root__DepSet_h5c122e7a__0 \
	Vsdram_axil_tb___024root__DepSet_ha237a3c9__0 \
	Vsdram_axil_tb_sdram_ctrl_if__DepSet_h83250182__0 \
	Vsdram_axil_tb_sdram_dev_if__DepSet_he3fce6e1__0 \
	Vsdram_axil_tb_taxi_axil_if__DepSet_h13f8d36d__0 \
	Vsdram_axil_tb__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vsdram_axil_tb___024root__Slow \
	Vsdram_axil_tb___024root__DepSet_h5c122e7a__0__Slow \
	Vsdram_axil_tb___024root__DepSet_ha237a3c9__0__Slow \
	Vsdram_axil_tb_sdram_ctrl_if__Slow \
	Vsdram_axil_tb_sdram_ctrl_if__DepSet_h83250182__0__Slow \
	Vsdram_axil_tb_sdram_dev_if__Slow \
	Vsdram_axil_tb_sdram_dev_if__DepSet_he3fce6e1__0__Slow \
	Vsdram_axil_tb_taxi_axil_if__Slow \
	Vsdram_axil_tb_taxi_axil_if__DepSet_h13f8d36d__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vsdram_axil_tb__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vsdram_axil_tb__Syms \
	Vsdram_axil_tb__Trace__0__Slow \
	Vsdram_axil_tb__TraceDecls__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_vcd_c \
	verilated_timing \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
