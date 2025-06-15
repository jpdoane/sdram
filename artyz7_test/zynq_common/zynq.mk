# phony targets
.PHONY: target fsbl flash clean

# prevent make from deleting intermediate files and reports
.PRECIOUS: %.xpr %.bit %.bin %.ltx %.xsa %.mcs %.prm
.SECONDARY:

CONFIG ?= config.mk
-include $(CONFIG)


HW_SERVER ?= 127.0.0.1:3121
FLASH_TARGET_ID ?= 3

SRC_PATH ?= $(ROOT)/ps_src
SRC ?= $(wildcard $(SRC_PATH)/*.c)

PROJECT ?= zynq_sdram

WORKSPACE = $(BUILD)/workspace

PLATFORM = artyz7
XSA_FILE = $(BUILD)/$(PROJECT).xsa
BIT = $(BUILD)/$(PROJECT).bit
BIF = $(BUILD)/$(PROJECT).bif
BOOT = $(BUILD)/BOOT.bin

FSBL = $(WORKSPACE)/$(PLATFORM)/export/$(PLATFORM)/sw/boot/fsbl.elf

APPLICATION = sdram_test
TARGET = $(WORKSPACE)/$(APPLICATION)/build/$(APPLICATION).elf

TMPSCRIPT_PY=$(BUILD)/vitis_script.py

fsbl: $(FSBL)
target: $(TARGET)

$(WORKSPACE):
	@echo "Making Vitis workspace $@"
	echo "import vitis" > $(TMPSCRIPT_PY)
	echo "client = vitis.create_client()" >> $(TMPSCRIPT_PY)
	echo "client.set_workspace(\"$(WORKSPACE)\")" >> $(TMPSCRIPT_PY)
	echo "client.close()" >> $(TMPSCRIPT_PY)
	cd $(BUILD); vitis -s $(TMPSCRIPT_PY)

$(WORKSPACE)/$(PLATFORM): | $(WORKSPACE)
	@echo "Making Vitis platform $@"
	echo "import vitis" > $(TMPSCRIPT_PY)
	echo "client = vitis.create_client()" >> $(TMPSCRIPT_PY)
	echo "client.update_workspace(\"$(WORKSPACE)\")" >> $(TMPSCRIPT_PY)
	echo "platform=client.create_platform_component(name=\"$(PLATFORM)\"," >> $(TMPSCRIPT_PY)
	echo "hw_design=\"$(XSA_FILE)\", cpu = \"ps7_cortexa9_0\", os = \"standalone\", domain_name = \"standalone_ps7\")" >> $(TMPSCRIPT_PY)
	echo "client.close()" >> $(TMPSCRIPT_PY)
	cd $(BUILD); vitis -s $(TMPSCRIPT_PY)

$(FSBL): $(XSA_FILE) | $(WORKSPACE)/$(PLATFORM)
	@echo "Making Vitis fsbl $@"
	echo "import vitis" > $(TMPSCRIPT_PY)
	echo "client = vitis.create_client()" >> $(TMPSCRIPT_PY)
	echo "client.update_workspace(\"$(WORKSPACE)\")" >> $(TMPSCRIPT_PY)
	echo "platform=client.get_component(name=\"$(PLATFORM)\")" >> $(TMPSCRIPT_PY)
	echo "platform.build()" >> $(TMPSCRIPT_PY)
	echo "client.close()" >> $(TMPSCRIPT_PY)
	cd $(BUILD); vitis -s $(TMPSCRIPT_PY)

$(WORKSPACE)/$(APPLICATION): | $(WORKSPACE)
	@echo "Making Vitis application $@"
	echo "import vitis" > $(TMPSCRIPT_PY)
	echo "client = vitis.create_client()" >> $(TMPSCRIPT_PY)
	echo "client.update_workspace(\"$(WORKSPACE)\")" >> $(TMPSCRIPT_PY)
	echo "app = client.create_app_component(name=\"$(APPLICATION)\"," >> $(TMPSCRIPT_PY)
	echo "platform = \"$(WORKSPACE)/$(PLATFORM)/export/$(PLATFORM)/$(PLATFORM).xpfm\", domain = \"standalone_ps7\")" >> $(TMPSCRIPT_PY)
	echo "app.import_files(from_loc = \"$(SRC_PATH)\")" >> $(TMPSCRIPT_PY)
	echo "client.close()" >> $(TMPSCRIPT_PY)
	cd $(BUILD); vitis -s $(TMPSCRIPT_PY)

$(TARGET): $(FSBL) $(SRC) |  $(WORKSPACE)/$(APPLICATION)
	@echo "Building target $@"
	echo "import vitis" > $(TMPSCRIPT_PY)
	echo "client = vitis.create_client()" >> $(TMPSCRIPT_PY)
	echo "client.update_workspace(path=\"$(WORKSPACE)\")" >> $(TMPSCRIPT_PY)
	echo "app = client.get_component(name=\"$(APPLICATION)\")" >> $(TMPSCRIPT_PY)
	echo "app.import_files(from_loc = \"$(SRC_PATH)\")" >> $(TMPSCRIPT_PY)
	echo "app.build()" >> $(TMPSCRIPT_PY)
	echo "client.close()" >> $(TMPSCRIPT_PY)
	cd $(BUILD); vitis -s $(TMPSCRIPT_PY)

$(BIF): $(TARGET) $(BIT) $(FSBL)
	echo "the_ROM_image:" > $@
	echo "{" >> $@
	echo "[bootloader]$(FSBL)" >> $@
	echo $(BIT) >> $@
	echo $(TARGET) >> $@
	echo "}" >> $@

$(BOOT): $(BIF)
	bootgen -image $< -arch zynq -o $@ -w

flash: $(BOOT) $(FSBL)
	program_flash -f $(BOOT) -offset 0 -flash_type qspi-x4-single -target_id $(FLASH_TARGET_ID) -fsbl $(FSBL) -url TCP:$(HW_SERVER)

run: $(BOOT) $(FSBL)
	@echo "Running application on ps"
	echo "connect -url TCP:$(HW_SERVER)" > $(BUILD)/run.tcl
	echo "targets -set -nocase -filter {name =~\"APU*\"}" >> $(BUILD)/run.tcl
	echo "rst -system" >> $(BUILD)/run.tcl
	echo "after 1000" >> $(BUILD)/run.tcl
	echo "targets -set -filter {name =~"xc7z020"}" >> $(BUILD)/run.tcl
	echo "fpga -file $(BIT)" >> $(BUILD)/run.tcl
	echo "targets -set -nocase -filter {name =~"APU*"}" >> $(BUILD)/run.tcl
	echo "loadhw -hw $(XSA_FILE) -mem-ranges [list {0x40000000 0xbfffffff}] -regs" >> $(BUILD)/run.tcl
	echo "configparams force-mem-access 1" >> $(BUILD)/run.tcl
	echo "targets -set -nocase -filter {name =~"APU*"}" >> $(BUILD)/run.tcl
	echo "source $(WORKSPACE)/$(APPLICATION)/_ide/psinit/ps7_init.tcl" >> $(BUILD)/run.tcl
	echo "ps7_init" >> $(BUILD)/run.tcl
	echo "ps7_post_config" >> $(BUILD)/run.tcl
	echo "targets -set -nocase -filter {name =~ "*A9*#0"}" >> $(BUILD)/run.tcl
	echo "dow $(TARGET)" >> $(BUILD)/run.tcl
	echo "configparams force-mem-access 0" >> $(BUILD)/run.tcl
	echo "targets -set -nocase -filter {name =~ "*A9*#0"}" >> $(BUILD)/run.tcl
	echo "con" >> $(BUILD)/run.tcl
	xsct $(BUILD)/run.tcl
	