# Check if the correct number of arguments is provided
if {[llength $argv] != 4} {
    puts "Usage: tclsh load.tcl <xsa_file> <workspace_path> <platform_name>"
    exit 1
}
set XSA_FILE [lindex $argv 0]
set BIT_FILE [lindex $argv 1]
set TARGET [lindex $argv 2]
set PS7_INIT [lindex $argv 3]

connect -url tcp:127.0.0.1:3121
targets -set -nocase -filter {name =~"APU*"}
rst -system
after 1000
#targets -set -filter {jtag_cable_name =~ "Digilent Arty Z7*" && level==0 && jtag_device_ctx=="jsn-Arty Z7*"}
fpga -file $BIT_FILE
targets -set -nocase -filter {name =~"APU*"}
loadhw -hw $XSA_FILE -mem-ranges [list {0x40000000 0xbfffffff}] -regs
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*"}
source $PS7_INIT
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "*A9*#0"}
dow $TARGET
configparams force-mem-access 0
targets -set -nocase -filter {name =~ "*A9*#0"}
con
