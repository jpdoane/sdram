PROJECT=zynq_sdram

ROOT = $(abspath $(dir $(firstword $(MAKEFILE_LIST))))
BUILD = $(ROOT)/build
ZYNQ_COMMON = $(ROOT)/zynq_common

# PL hdl firmware
SDRAM_HDL = $(ROOT)/../hdl

SYN_FILES = 
SYN_FILES += $(SDRAM_HDL)/sdram_axi_core.v
SYN_FILES += $(SDRAM_HDL)/sdram_axi_pmem.v
SYN_FILES += $(SDRAM_HDL)/sdram_axi.v
SYN_FILES += $(SDRAM_HDL)/sdram_if.sv
SYN_FILES += $(SDRAM_HDL)/taxi_axil_if.sv
SYN_FILES += $(SDRAM_HDL)/axil_sdram.sv
SYN_FILES += $(SDRAM_HDL)/sdram_core_pc3.sv
# SYN_FILES += $(SDRAM_HDL)/sdram_core_ref.sv
SYN_FILES += $(ROOT)/sdram_io2.sv
SYN_FILES +=  $(ROOT)/top.sv
FPGA_TOP = zynq_sdram

# constraints
XDC_FILES = $(ZYNQ_COMMON)/artyz7.xdc

# PS software
IP_TCL_FILES = $(ZYNQ_COMMON)/zynq_ps.tcl
# IP_TCL_FILES = $(ZYNQ_COMMON)/zynq_ps_ila.tcl
PS_SOURCE = $(ROOT)/ps_src/main.c

include $(ZYNQ_COMMON)/vivado.mk
include $(ZYNQ_COMMON)/zynq.mk

TTY_DEV = /dev/ttyUSB0
tty:
	sudo screen $(TTY_DEV) 115200