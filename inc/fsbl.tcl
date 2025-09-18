# Check if the correct number of arguments is provided
if {[llength $argv] != 3} {
    puts "Usage: tclsh fsbl.tcl <xsa_file> <workspace_path> <platform_name>"
    exit 1
}
set XSA_FILE [lindex $argv 0]
set WS_PATH [lindex $argv 1]
set PLATFORM [lindex $argv 2]

setws $WS_PATH

platform create -name $PLATFORM -hw $XSA_FILE -no-boot-bsp
domain create -name A9_Standalone -os standalone -proc ps7_cortexa9_0
domain active A9_Standalone
bsp setlib -name xilffs
# bsp config zynq_fsbl_bsp true
platform generate
app create -name zynq_fsbl -platform $PLATFORM -template "Zynq FSBL" -domain A9_Standalone -lang c
app build -name zynq_fsbl