#ifndef AXIMEM_H
#define AXIMEM_H

#include <stdint.h>
#include "vsim.h"
#include "Vsdram_axil_tb.h"


class AxiMem
{
private:
    VSim<Vsdram_axil_tb>* vsim;
    u64 clk_period;

public:
    AxiMem(double clk_freqMHz, const char* tracefile = nullptr);
    ~AxiMem();
    void boot();

    void clock() { vsim->clock(clk_period); }

    void writeword(u32 data, u32 addr, u8 mask = 0xf);
    u32 readword(u32 addr);
};

#endif