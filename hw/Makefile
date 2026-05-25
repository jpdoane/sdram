PROJECT=zynq_sdram

ROOT = $(abspath $(dir $(firstword $(MAKEFILE_LIST))))
BUILD = $(ROOT)/build
ZYNQ_COMMON = $(ROOT)/zynq_common

# PL rtl firmware
SDRAM_RTL = $(ROOT)/../rtl

SYN_FILES = 
SYN_FILES += $(SDRAM_RTL)/sdram_if.sv
SYN_FILES += $(SDRAM_RTL)/taxi_axil_if.sv
SYN_FILES += $(SDRAM_RTL)/axil_sdram.sv
SYN_FILES += $(SDRAM_RTL)/sdram_core.sv
SYN_FILES += $(SDRAM_RTL)/sdram_io.sv
SYN_FILES +=  $(ROOT)/top.sv
FPGA_TOP = zynq_sdram

# constraints
XDC_FILES = $(ZYNQ_COMMON)/artyz7.xdc

# PS software
IP_TCL_FILES = $(ZYNQ_COMMON)/zynq_ps.tcl
PS_SOURCE = $(ROOT)/ps_src/main.c

include $(ZYNQ_COMMON)/vivado.mk
include $(ZYNQ_COMMON)/zynq.mk

TTY_DEV = /dev/ttyUSB0
tty:
	sudo screen $(TTY_DEV) 115200