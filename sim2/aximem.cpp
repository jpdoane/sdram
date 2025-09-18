#include "aximem.h"
#include <iostream>
#include <math.h>

AxiMem::AxiMem(VerilatedContext* context, double clk_freqMHz, VerilatedFstC* tfp)
:context(context), tfp(tfp)
{

    double clk_period = 1e-6/clk_freqMHz;
    tick_period = pow(10.0, -double(Verilated::timeprecision()));
    ticks_per_clk = u64(clk_period/tick_period);
    ticks_per_qtrclk = ticks_per_clk/4;

    std::cout << "clk_period:" << clk_period << std::endl;
    std::cout << "tick_period:" << tick_period << std::endl;
    std::cout << "ticks_per_clk:" << ticks_per_clk << std::endl;
    std::cout << "ticks_per_qtrclk:" << ticks_per_qtrclk << std::endl;

    top = new Vsdram_axil_tb{context, "sdram_axi_tb"};

    top->trace (tfp, 99);

	top->awaddr = 0;
	top->awvalid = 0;
	top->wstrb = 0;
	top->wdata = 0;
	top->wvalid = 0;
	top->bready = 0;
	top->araddr = 0;
	top->arvalid = 0;
	top->rready = 0;

	top->rst = 1;

    for(int i=0; i<1000;i++)
        clock();

	top->rst = 0;


    std::cout << "SDRAM Ready..." << std::endl;
    clock();
}

AxiMem::~AxiMem()
{
    top->final();    
    delete top;
}

void AxiMem::advanceSim(u64 ticks)
{   
    u64 tnext;
    while(top->eventsPending())
    {
        tnext = top->nextTimeSlot() - context->time();
        if(tnext >= ticks)
            break;

        context->timeInc(tnext);
        top->eval();
        if (tfp) tfp->dump(context->time());
        ticks -= tnext;
    }

    context->timeInc(ticks);
    top->eval();
    if (tfp) tfp->dump(context->time());
    return;
}


void AxiMem::clock()
{
    top->clk = 0;
    top->sdram_clk = 1;
    advanceSim(ticks_per_qtrclk);

    top->clk = 0;
    top->sdram_clk = 0;
    advanceSim(ticks_per_qtrclk);

    top->clk = 1;
    top->sdram_clk = 0;
    advanceSim(ticks_per_qtrclk);

    top->clk = 1;
    top->sdram_clk = 1;
    advanceSim(ticks_per_qtrclk);
}


void AxiMem::writeword(u32 data, u32 addr, u8 mask)
{
    top->awaddr = addr;
    top->wdata = data;
    top->wstrb = mask;
    top->awvalid = 1;
    top->wvalid = 1;
    while(!(top->awready && top->wready)) clock();
    clock();
    top->awvalid = 0;
    top->wvalid = 0;
    top->awaddr = 0;
    top->wstrb = 0;
    top->wdata = 0;
    top->bready = 1;
    while(!top->bvalid) clock();
    clock();
    top->bready = 0;
}

u32 AxiMem::readword(u32 addr)
{
    top->araddr = addr;
    top->arvalid = 1;
    while(!top->arready) clock();
    clock();
    top->arvalid = 0;
    top->araddr = 0;
    top->rready = 1;
    while(!top->rvalid) clock();
    u32 rdata = top->rdata;
    clock();
    top->rready = 0;
    return rdata;
}
