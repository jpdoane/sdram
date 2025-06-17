# SPDX-License-Identifier: MIT
###################################################################
#
# Xilinx Vivado FPGA Makefile
#
# Copyright (c) 2016-2025 Alex Forencich
#
###################################################################
#
# Parameters:
# FPGA_TOP - Top module name
# FPGA_FAMILY - FPGA family (e.g. VirtexUltrascale)
# FPGA_DEVICE - FPGA device (e.g. xcvu095-ffva2104-2-e)
# SYN_FILES - list of source files
# INC_FILES - list of include files
# XDC_FILES - list of timing constraint files
# XCI_FILES - list of IP XCI files
# IP_TCL_FILES - list of IP TCL files (sourced during project creation)
# CONFIG_TCL_FILES - list of config TCL files (sourced before each build)
#
# Note: both SYN_FILES and INC_FILES support file list files.  File list
# files are files with a .f extension that contain a list of additional
# files to include, one path relative to the .f file location per line.
# The .f files are processed recursively, and then the complete file list
# is de-duplicated, with later files in the list taking precedence.
#
# Example:
#
# FPGA_TOP = fpga
# FPGA_FAMILY = VirtexUltrascale
# FPGA_DEVICE = xcvu095-ffva2104-2-e
# SYN_FILES = rtl/fpga.v
# XDC_FILES = fpga.xdc
# XCI_FILES = ip/pcspma.xci
# include ../common/vivado.mk
#
###################################################################


# phony targets
.PHONY: fpga vivado program flash tmpclean clean distclean

# prevent make from deleting intermediate files and reports
.PRECIOUS: %.xpr %.bit %.bin %.ltx %.xsa %.mcs %.prm
.SECONDARY:

CONFIG ?= config.mk
-include $(CONFIG)

ROOT ?= $(abspath $(dir $(firstword $(MAKEFILE_LIST))))
BUILD ?= $(ROOT)/build/

HW_SERVER ?= 127.0.0.1:3121
HW_DEVICE_IDX ?= 1

FPGA_TOP ?= fpga
PROJECT ?= $(FPGA_TOP)
XDC_FILES ?= $(BUILD)/$(PROJECT).xdc

# handle file list files
process_f_file = $(call process_f_files,$(addprefix $(dir $1),$(shell cat $1)))
process_f_files = $(foreach f,$1,$(if $(filter %.f,$f),$(call process_f_file,$f),$f))
uniq_base = $(if $1,$(call uniq_base,$(foreach f,$1,$(if $(filter-out $(notdir $(lastword $1)),$(notdir $f)),$f,))) $(lastword $1))
SYN_FILES := $(call uniq_base,$(call process_f_files,$(SYN_FILES)))
INC_FILES := $(call uniq_base,$(call process_f_files,$(INC_FILES)))

ILA_TCL=$(ZYNQ_COMMON)/insert_ila.tcl

###################################################################
# Main Targets
#
# all: build everything (fpga)
# fpga: build FPGA config
# vivado: open project in Vivado
# tmpclean: remove intermediate files
# clean: remove output files and project files
# distclean: remove archived output files
###################################################################

PROJECTFILE = $(BUILD)/$(PROJECT).xpr

all: fpga

synth: $(BUILD)/$(PROJECT).runs/synth_1/$(PROJECT).dcp
impl: $(BUILD)/$(PROJECT).runs/impl_1/$(PROJECT)_routed.dcp

fpga: $(BUILD)/$(PROJECT).bit

vivado: $(PROJECTFILE)
	cd $(BUILD); vivado $<

# tmpclean::
# 	-rm -rf *.log *.jou *.cache *.gen *.hbs *.hw *.ip_user_files *.runs *.xpr *.html *.xml *.sim *.srcs *.str .Xil defines.v
# 	-rm -rf create_project.tcl update_config.tcl run_synth.tcl run_impl.tcl generate_bit.tcl

clean::
	rm -rf $(BUILD)
	
# -rm -rf *.bit *.bin *.ltx *.xsa program.tcl generate_mcs.tcl *.mcs *.prm flash.tcl
# -rm -rf *_utilization.rpt *_utilization_hierarchical.rpt
# -rm -rf rev

distclean:: clean
	-rm -rf rev

###################################################################
# Target implementations
###################################################################

# Vivado project file

# create fresh project if Makefile or IP files have changed
# create_project.tcl: Makefile $(XCI_FILES) $(IP_TCL_FILES)

$(BUILD)/create_project.tcl: $(XCI_FILES) $(IP_TCL_FILES)
	-mkdir $(BUILD)
	rm -rf $(BUILD)/defines.v
	touch $(BUILD)/defines.v
	for x in $(DEFS); do echo '`define' $$x >> $(BUILD)/defines.v; done
	echo "create_project -force -part $(DEVICE_LONG) $(PROJECT)" > $@
	echo "add_files -fileset sources_1 defines.v $(SYN_FILES)" >> $@
	echo "set_property top $(FPGA_TOP) [current_fileset]" >> $@
	echo "add_files -fileset constrs_1 $(XDC_FILES)" >> $@
	for x in $(XCI_FILES); do echo "import_ip $$x" >> $@; done
	for x in $(IP_TCL_FILES); do echo "source $$x" >> $@; done
	for x in $(CONFIG_TCL_FILES); do echo "source $$x" >> $@; done

# source config TCL scripts if any source file has changed
$(BUILD)/update_config.tcl: $(CONFIG_TCL_FILES) $(SYN_FILES) $(INC_FILES) $(XDC_FILES)
	echo "open_project -quiet $(PROJECTFILE)" > $@
	for x in $(CONFIG_TCL_FILES); do echo "source $$x" >> $@; done

$(PROJECTFILE): $(BUILD)/create_project.tcl $(BUILD)/update_config.tcl
	cd $(BUILD); vivado -nojournal -nolog -mode batch $(foreach x,$?,-source $x)

# synthesis run
$(BUILD)/$(PROJECT).runs/synth_1/$(PROJECT).dcp: $(BUILD)/create_project.tcl $(BUILD)/update_config.tcl $(SYN_FILES) $(INC_FILES) $(XDC_FILES) | $(PROJECTFILE)
	echo "open_project $(PROJECTFILE)" > $(BUILD)/run_synth.tcl
	echo "reset_run synth_1" >> $(BUILD)/run_synth.tcl
	echo "launch_runs -jobs 4 synth_1" >> $(BUILD)/run_synth.tcl
	echo "wait_on_run synth_1" >> $(BUILD)/run_synth.tcl
	cd $(BUILD); vivado -nojournal -nolog -mode batch -source $(BUILD)/run_synth.tcl

# add ila
$(BUILD)/debug_nets.ltx: $(BUILD)/$(PROJECT).runs/synth_1/$(PROJECT).dcp
	echo "open_project $(PROJECTFILE)" > $(BUILD)/add_ila.tcl
	echo "open_run synth_1" >> $(BUILD)/add_ila.tcl
	echo "source $(ILA_TCL)" >> $(BUILD)/add_ila.tcl
	echo "batch_insert_ila 1024" >> $(BUILD)/add_ila.tcl
	cd $(BUILD); vivado -nojournal -nolog -mode batch -source $(BUILD)/add_ila.tcl

# implementation run
$(BUILD)/$(PROJECT).runs/impl_1/$(PROJECT)_routed.dcp: $(BUILD)/$(PROJECT).runs/synth_1/$(PROJECT).dcp $(BUILD)/debug_nets.ltx
	echo "open_project $(PROJECTFILE)" > $(BUILD)/run_impl.tcl
	echo "reset_run impl_1" >> $(BUILD)/run_impl.tcl
	echo "launch_runs -jobs 4 impl_1" >> $(BUILD)/run_impl.tcl
	echo "wait_on_run impl_1" >> $(BUILD)/run_impl.tcl
	echo "open_run impl_1" >> $(BUILD)/run_impl.tcl
	echo "report_utilization -file $(PROJECT)_utilization.rpt" >> $(BUILD)/run_impl.tcl
	echo "report_utilization -hierarchical -file $(PROJECT)_utilization_hierarchical.rpt" >> $(BUILD)/run_impl.tcl
	cd $(BUILD); vivado -nojournal -nolog -mode batch -source $(BUILD)/run_impl.tcl

# output files (including potentially bit, bin, ltx, and xsa)
$(BUILD)/$(PROJECT).bit $(BUILD)/$(PROJECT).bin $(BUILD)/$(PROJECT).ltx $(BUILD)/$(PROJECT).xsa: $(BUILD)/$(PROJECT).runs/impl_1/$(PROJECT)_routed.dcp
	echo "open_project $(PROJECTFILE)" > $(BUILD)/generate_bit.tcl
	echo "open_run impl_1" >> $(BUILD)/generate_bit.tcl
	echo "write_bitstream -force -bin_file $(PROJECT).runs/impl_1/$(PROJECT).bit" >> $(BUILD)/generate_bit.tcl
	echo "write_debug_probes -force $(PROJECT).runs/impl_1/$(PROJECT).ltx" >> $(BUILD)/generate_bit.tcl
	echo "write_hw_platform -fixed -force -include_bit $(PROJECT).xsa" >> $(BUILD)/generate_bit.tcl
	cd $(BUILD); vivado -nojournal -nolog -mode batch -source $(BUILD)/generate_bit.tcl
	ln -f -s $(BUILD)/$(PROJECT).runs/impl_1/$(PROJECT).bit $(BUILD)
	ln -f -s $(BUILD)/$(PROJECT).runs/impl_1/$(PROJECT).bin $(BUILD)
	if [ -e $(BUILD)/$(PROJECT).runs/impl_1/$(PROJECT).ltx ]; then ln -f -s $(BUILD)/$(PROJECT).runs/impl_1/$(PROJECT).ltx $(BUILD); fi
	mkdir -p rev
	COUNT=100; \
	while [ -e rev/$(PROJECT)_rev$$COUNT.bit ]; \
	do COUNT=$$((COUNT+1)); done; \
	cp -pv $(BUILD)/$(PROJECT).runs/impl_1/$(PROJECT).bit rev/$(PROJECT)_rev$$COUNT.bit; \
	cp -pv $(BUILD)/$(PROJECT).runs/impl_1/$(PROJECT).bin rev/$(PROJECT)_rev$$COUNT.bin; \
	if [ -e $(BUILD)/$(PROJECT).runs/impl_1/$(PROJECT).ltx ]; then cp -pv $(BUILD)/$(PROJECT).runs/impl_1/$(PROJECT).ltx rev/$(PROJECT)_rev$$COUNT.ltx; fi; \
	if [ -e $(BUILD)/$(PROJECT).xsa ]; then cp -pv $(BUILD)/$(PROJECT).xsa rev/$(PROJECT)_rev$$COUNT.xsa; fi

program: $(BUILD)/$(PROJECT).bit
	echo "open_hw_manager" > $(BUILD)/program.tcl
	echo "connect_hw_server -url TCP:$(HW_SERVER)" >> $(BUILD)/program.tcl
	echo "open_hw_target" >> $(BUILD)/program.tcl
	echo "current_hw_device [lindex [get_hw_devices] $(HW_DEVICE_IDX)]" >> $(BUILD)/program.tcl
	echo "refresh_hw_device -update_hw_probes false [current_hw_device]" >> $(BUILD)/program.tcl
	echo "set_property PROGRAM.FILE {$(PROJECT).bit} [current_hw_device]" >> $(BUILD)/program.tcl
	echo "program_hw_devices [current_hw_device]" >> $(BUILD)/program.tcl
	echo "exit" >> $(BUILD)/program.tcl
	cd $(BUILD); vivado -nojournal -nolog -mode batch -source $(BUILD)/program.tcl

$(BUILD)/$(PROJECT).mcs $(BUILD)/$(PROJECT).prm: $(BUILD)/$(PROJECT).bit
	echo "write_cfgmem -force -format mcs -size 16 -interface SPIx4 -loadbit {up 0x0000000 $*.bit} -checksum -file $*.mcs" > $(BUILD)/generate_mcs.tcl
	echo "exit" >> $(BUILD)/generate_mcs.tcl
	vivado -nojournal -nolog -mode batch -source $(BUILD)/generate_mcs.tcl
	mkdir -p rev
	COUNT=100; \
	while [ -e rev/$*_rev$$COUNT.bit ]; \
	do COUNT=$$((COUNT+1)); done; \
	COUNT=$$((COUNT-1)); \
	for x in .mcs .prm; \
	do cp $(BUILD)/$*$$x rev/$*_rev$$COUNT$$x; \
	echo "Output: rev/$*_rev$$COUNT$$x"; done;

# flash: $(PROJECT).mcs $(PROJECT).prm
# 	echo "open_hw_manager" > flash.tcl
# 	echo "connect_hw_server" >> flash.tcl
# 	echo "open_hw_target" >> flash.tcl
# 	echo "current_hw_device [lindex [get_hw_devices] 0]" >> flash.tcl
# 	echo "refresh_hw_device -update_hw_probes false [current_hw_device]" >> flash.tcl
# 	echo "create_hw_cfgmem -hw_device [current_hw_device] [lindex [get_cfgmem_parts {mt25ql128-spi-x1_x2_x4}] 0]" >> flash.tcl
# 	echo "current_hw_cfgmem -hw_device [current_hw_device] [get_property PROGRAM.HW_CFGMEM [current_hw_device]]" >> flash.tcl
# 	echo "set_property PROGRAM.FILES [list \"$(PROJECT).mcs\"] [current_hw_cfgmem]" >> flash.tcl
# 	echo "set_property PROGRAM.PRM_FILES [list \"$(PROJECT).prm\"] [current_hw_cfgmem]" >> flash.tcl
# 	echo "set_property PROGRAM.ERASE 1 [current_hw_cfgmem]" >> flash.tcl
# 	echo "set_property PROGRAM.CFG_PROGRAM 1 [current_hw_cfgmem]" >> flash.tcl
# 	echo "set_property PROGRAM.VERIFY 1 [current_hw_cfgmem]" >> flash.tcl
# 	echo "set_property PROGRAM.CHECKSUM 0 [current_hw_cfgmem]" >> flash.tcl
# 	echo "set_property PROGRAM.ADDRESS_RANGE {use_file} [current_hw_cfgmem]" >> flash.tcl
# 	echo "set_property PROGRAM.UNUSED_PIN_TERMINATION {pull-none} [current_hw_cfgmem]" >> flash.tcl
# 	echo "create_hw_bitstream -hw_device [current_hw_device] [get_property PROGRAM.HW_CFGMEM_BITFILE [current_hw_device]]" >> flash.tcl
# 	echo "program_hw_devices [current_hw_device]" >> flash.tcl
# 	echo "refresh_hw_device [current_hw_device]" >> flash.tcl
# 	echo "program_hw_cfgmem -hw_cfgmem [current_hw_cfgmem]" >> flash.tcl
# 	echo "boot_hw_device [current_hw_device]" >> flash.tcl
# 	echo "exit" >> flash.tcl
# 	vivado -nojournal -nolog -mode batch -source flash.tcl
