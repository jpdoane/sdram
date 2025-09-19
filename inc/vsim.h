#ifndef VSIM_H
#define VSIM_H

#include <stdint.h>
#include <string>
#include <iostream>
#include <math.h>
#include "verilated.h"
#include "verilated_fst_c.h"

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;

template <typename Vmodel> class VSim: public Vmodel
{
private:
    VerilatedContext* context;
    VerilatedFstC* traceobj;

    double tick_period;

public:
    VSim(const char* tracefile = nullptr);
    ~VSim();

    void advanceSim(u64 ticks);
    virtual void clock(u64 clk_period);
    virtual void clock(double clk_freq);

    u64 clk_period(double clk_freq) {return u64(1/(clk_freq*tick_period));};
};


template <typename Vmodel> VSim<Vmodel>::VSim(const char* tracefile)
:Vmodel()
{
    context = this->contextp();
    context->debug(0);
    context->randReset(2);

    tick_period = pow(10.0, double(context->timeprecision()));

    if(tracefile)
    {
        context->traceEverOn(true);
        traceobj = new VerilatedFstC;
        this->trace(traceobj, 99);
        traceobj->open(tracefile);
    
        if (traceobj->isOpen()) {
            std::cout << "Logging to wavefile " << tracefile << std::endl;
        }
        else {
            traceobj = nullptr;
            std::cout << "ERROR opening wavefile " << tracefile << std::endl;
        }    
    }
    else
    {
        traceobj = nullptr;
    }
}

template <typename Vmodel> VSim<Vmodel>::~VSim()
{
    if(traceobj) delete traceobj;
}



template <typename Vmodel> void VSim<Vmodel>::advanceSim(u64 ticks)
{   
    u64 tnext;
    while(this->eventsPending())
    {
        tnext = this->nextTimeSlot() - context->time();
        if(tnext >= ticks)
            break;

            context->timeInc(tnext);
            this->eval();
        if (traceobj) traceobj->dump(context->time());
        ticks -= tnext;
    }

    context->timeInc(ticks);
    this->eval();
    if (traceobj) traceobj->dump(context->time());
}

template <typename Vmodel> void VSim<Vmodel>::clock(u64 clk_period)
{
    this->eval();

    advanceSim(clk_period/2);
    this->clk = 0;

    advanceSim(clk_period/2);
    this->clk = 1;

    this->eval();

}

template <typename Vmodel> void VSim<Vmodel>::clock(double clk_freq)
{
    clock(clk_period(clk_freq));
}




#endif