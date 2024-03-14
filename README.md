# sdram

Simple Verilog controller core for [AS4C32M16SB-6](https://www.mouser.com/datasheet/2/12/AllianceMemory_512M_SDRAM_Bdie_AS4C32M16SB_7TXN_6T-1826888.pdf) or [W9825G6KH-6](https://www.mouser.com/datasheet/2/949/w9825g6kh_a04-1489735.pdf) 64MB SDRAM module.

Includes a board design compatible with the [ChipKit shield connector](https://digilent.com/reference/_media/reference/programmable-logic/arty-z7/arty-z7-shield.png) on the [Arty Z7-20](https://digilent.com/reference/programmable-logic/arty-z7/reference-manual)

The primary intent of this project is to support larger ROM memories for [NES fpga project](https://github.com/jpdoane/nesfpga), and that will only simple memory operations as needed by the NES core will be initially supported.
