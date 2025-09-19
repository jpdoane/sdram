#include "aximem.h"
#include <iostream>
#include <math.h>

AxiMem::AxiMem(double clk_freqMHz, const char* tracefile)
{
    vsim = new VSim<Vsdram_axil_tb>(tracefile);

    clk_period = vsim->clk_period(clk_freqMHz*1e6);

    vsim->awaddr = 0;
	vsim->awvalid = 0;
	vsim->wstrb = 0;
	vsim->wdata = 0;
	vsim->wvalid = 0;
	vsim->bready = 0;
	vsim->araddr = 0;
	vsim->arvalid = 0;
	vsim->rready = 0;

	vsim->rst = 1;
}

AxiMem::~AxiMem()
{
    vsim->final();    
    delete vsim;
}

void AxiMem::boot()
{
    std::cout << "SDRAM Reset..." << std::endl;

    vsim->rst = 1;
    for(int i=0; i<2;i++)
        clock();
    std::cout << "SDRAM Boot..." << std::endl;

    vsim->rst = 0;
    for(int i=0; i<1000;i++)
        clock();

    std::cout << "SDRAM Ready..." << std::endl;
}


void AxiMem::writeword(u32 data, u32 addr, u8 mask)
{
    vsim->awaddr = addr;
    vsim->wdata = data;
    vsim->wstrb = mask;
    vsim->awvalid = 1;
    vsim->wvalid = 1;
    vsim->eval();
    while(!(vsim->awready && vsim->wready)) clock();
    clock();
    vsim->awvalid = 0;
    vsim->wvalid = 0;
    vsim->awaddr = 0;
    vsim->wstrb = 0;
    vsim->wdata = 0;
    vsim->bready = 1;
    vsim->eval();
    while(!vsim->bvalid) clock();
    clock();
    vsim->bready = 0;
}

u32 AxiMem::readword(u32 addr)
{
    vsim->araddr = addr;
    vsim->arvalid = 1;
    vsim->eval();
    while(!vsim->arready) clock();
    clock();
    vsim->arvalid = 0;
    vsim->araddr = 0;
    vsim->rready = 1;
    vsim->eval();
    while(!vsim->rvalid) clock();
    u32 rdata = vsim->rdata;
    clock();
    vsim->rready = 0;
    return rdata;
}
