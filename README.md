# sdram

Simple Verilog controller core for the [Alliance AS4C32M16SB](docs/AS4C32M16SB.pdf) or the (drop in equivalent) [Winbond W9825G6KH](docs/w9825g6kh.pdf) 64MB SDRAM modules.

Includes a [board design](board/sdram.pdf) compatible with the [ChipKit shield connector](https://digilent.com/reference/_media/reference/programmable-logic/arty-z7/arty-z7-shield.png) on the [Arty Z7-20](https://digilent.com/reference/programmable-logic/arty-z7/reference-manual)


The primary intent of this project is to support larger ROM memories for [NES fpga project](https://github.com/jpdoane/nesfpga), and that will only simple memory operations as needed by the NES core will be initially supported.
