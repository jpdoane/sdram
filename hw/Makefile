PROJECT=zynq_sdram
FPGA_TOP = zynq_sdram

ROOT = $(abspath $(dir $(firstword $(MAKEFILE_LIST))))
BUILD = $(ROOT)/build
ZYNQ_TOOLS = $(ROOT)/zynq_tools

# board 
DEVICE_LONG = xc7z020clg400-1
DEVICE_SHORT = xc7z020

# tools
HW_SERVER = 127.0.0.1:3121
FLASH_TARGET_ID = 3
TTY_DEV = /dev/ttyUSB0

# configure ila debug
ILA_DEBUG = 1 #set to nonzero to insert ila

# RTL sources
SDRAM_RTL = $(ROOT)/../rtl
RTL_FILES  = $(SDRAM_RTL)/dual_master_sdram.sv
RTL_FILES += $(SDRAM_RTL)/sdram_core.sv
RTL_FILES += $(SDRAM_RTL)/sdram_io.sv
RTL_FILES += $(SDRAM_RTL)/clk_div.sv
RTL_FILES += $(ROOT)/rtl/portb_tester.sv
RTL_FILES += $(ROOT)/top.sv

# constraints
XDC_FILES = $(ZYNQ_TOOLS)/boards/artyz7.xdc
XDC_FILES += $(ZYNQ_TOOLS)/boards/arty_sdram.xdc
XDC_FILES += $(ROOT)/clocks.xdc

# TCL sources (eg. PS with AXI)
TCL_FILES = $(ZYNQ_TOOLS)/zynq_ps.tcl

# TCL project-specific config (run before all other scripts)
CONFIG_TCL_FILES = $(ROOT)/config.tcl          

# PS software
PS_SOURCE = $(ROOT)/ps_src/main.c

include $(ZYNQ_TOOLS)/vivado.mk
include $(ZYNQ_TOOLS)/zynq.mk

