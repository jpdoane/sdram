connect -url tcp:127.0.0.1:3121
targets -set -nocase -filter {name =~"APU*"}
rst -system
after 1000
targets -set -filter {name =~"xc7z020"}
fpga -file zynq_sdram.bit
targets -set -nocase -filter {name =~"APU*"}
loadhw -hw zynq_sdram.xsa -mem-ranges [list {0x40000000 0xbfffffff}] -regs
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*"}
source ps7_init.tcl
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "*A9*#0"}
dow zynq_sdram.elf
configparams force-mem-access 0
targets -set -nocase -filter {name =~ "*A9*#0"}
con
