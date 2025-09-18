#ifndef AXIMEM_H
#define AXIMEM_H

#include <stdint.h>
#include "Vsdram_axil_tb.h"
#include "verilated.h"
#include "verilated_fst_c.h"


typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;

class AxiMem{

private:
    Vsdram_axil_tb* top;
    VerilatedContext* context;
    double tick_period;
    u64 ticks_per_clk;
    u64 ticks_per_qtrclk;
    VerilatedFstC* tfp;

    void advanceSim(u64 ticks);

public:
    AxiMem(VerilatedContext* context, double clk_freqMHz, VerilatedFstC* tfp = nullptr);
    ~AxiMem();
    void boot();

    void clock();

    void writeword(u32 data, u32 addr, u8 mask = 0xf);
    u32 readword(u32 addr);
};

#endif