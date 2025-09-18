#include "aximem.h"
#include <iostream>

#define QUOTE2(X) #X
#define QUOTE(X) QUOTE2(X)

int main(void)
{
    double clk_freqMHz=50;

    VerilatedContext* context = new VerilatedContext;
    context->debug(0);
    context->randReset(2);


    context->traceEverOn(true);
    VerilatedFstC* tfp = new VerilatedFstC;

    std::string tracefile = QUOTE(WAVEFILE);

    AxiMem* vsim = new AxiMem(context, clk_freqMHz, tfp);

    tfp->open(tracefile.c_str());

    if (tfp->isOpen()) {
        std::cout << "Logging to wavefile " << tracefile << std::endl;
    }
    else {
        tfp = nullptr;
        std::cout << "ERROR opening wavefile " << tracefile << std::endl;
    }

    vsim->boot();

    u32 data[16] = {
    0x5ac118ed,
    0xf5d5a6d0,
    0xc7731a0a,
    0x9dd9764e,
    0x4d1a6503,
    0x6e549599,
    0xda26f7e5,
    0x941541e2,
    0x9f261c88,
    0xef0c808f,
    0x06e669b0,
    0xd7b1dd6a,
    0xc16bbb50,
    0x892721e9,
    0xcdde42e2,
    0x66965900};

    u32 addr[16] = {
        0x732bf0,
        0xad71b0,
        0xe96660,
        0x654fb0,
        0x047090,
        0x336940,
        0xad3ca0,
        0x377b30,
        0xb5f660,
        0xc7c570,
        0x736fc0,
        0x142d70,
        0x4dea10,
        0x2c4830,
        0xeccb40,
        0x7f8ba0};

    // u32 addr[16] = {
    //     0x00,
    //     0x10,
    //     0x20,
    //     0x30,
    //     0x40,
    //     0x50,
    //     0x60,
    //     0x70,
    //     0x80,
    //     0x90,
    //     0xa0,
    //     0xb0,
    //     0xc0,
    //     0xd0,
    //     0xe0,
    //     0xf0};
        

    u32 d,a;
    u32 valid = 1;
    size_t N = sizeof(data)/sizeof(data[0]);
    
    std::cout << std::hex;
    for (int i=0; i<N; i++)
    {
        d = data[i];
        a = addr[i];
        vsim->writeword(d, a);

        std::cout << "Wrote [0x" << a << "] = 0x"  << d << std::endl;
    }

    for (int i=0; i<N; i++)
    {
        a = addr[i];
        d = vsim->readword(a);
        std::cout << "Read [0x" << a << "] = 0x" << d << std::endl;
        if(d != data[i])
        {
            std::cout << "\tError!" << std::endl;
            valid = 0;            
        }
    }


    context->traceEverOn(false);
    if(tfp){
        tfp->close();
        delete tfp;
        tfp = nullptr;
    }

    if(valid)
        std::cout << "Test Passed :)" << std::endl;
    else
    {
        std::cout << "Test Failed :(" << std::endl;
        valid = 0;            
    }

    return !valid;
}