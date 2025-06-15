PROJECT=zynq_sdram

# FPGA settings
FPGA_PART = xc7z020clg400-1
FPGA_TOP = zynq_sdram
FPGA_ARCH = zynq7

ROOT = $(abspath $(dir $(firstword $(MAKEFILE_LIST))))
BUILD = $(ROOT)/build

ZYNQ_COMMON = $(ROOT)/zynq_common

# ps config
IP_TCL_FILES = $(ZYNQ_COMMON)/zynq_ps.tcl
PS_SOURCE = $(ROOT)/ps_src/main.c

# Files for synthesis
SDRAM_HDL = $(ROOT)/../hdl
SYN_FILES += $(SDRAM_HDL)/sdram_if.sv
SYN_FILES += $(SDRAM_HDL)/taxi_axil_if.sv
SYN_FILES += $(SDRAM_HDL)/axil_sdram.sv
SYN_FILES += $(SDRAM_HDL)/sdram_core.sv
SYN_FILES += $(ROOT)/sdram_io.sv
SYN_FILES +=  $(ROOT)/top.sv

# XDC files
XDC_FILES = $(ZYNQ_COMMON)/artyz7.xdc
# XDC_FILES += $(ROOT)/debug.xdc


include $(ZYNQ_COMMON)/vivado.mk
include $(ZYNQ_COMMON)/zynq.mk



