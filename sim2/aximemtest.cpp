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


    u32 data[3] = {0xdeadbeef, 0x12345678, 0xabcd1234};
    u32 d;
    u32 valid = 1;

    for (int i=0; i<3; i++)
    {
        d = data[i];
        vsim->writeword(d, i);
        std::cout << "Wrote [" << i << "] = 0x" << std::hex << d << std::endl;
    }

    for (int i=0; i<3; i++)
    {
        d = vsim->readword(i);
        std::cout << "Read [" << i << "] = 0x" << std::hex << d;
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