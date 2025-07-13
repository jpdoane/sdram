#include <stdio.h>
#include "xil_printf.h"
#include <sleep.h>
#include <stdlib.h>

#define SDRAM_BASEADDR   0x40000000
#define SDRAM_SIZE       0x2000000

u32 map_val(u32 n) { return n; }
u32 map_addr(u32 n) { return n; }

int main()
{
    xil_printf("\n\n\n\n\rSDRAM test on AXI bus: 0x%x\n\r", SDRAM_BASEADDR);
    // print("Press key to start\n\r");
    // inbyte();

    int valid;
	u32 x;
	u32* sdram = (u32*) SDRAM_BASEADDR;
    int Ncheck = 0x800000;

    u32 buf[8];
    int Nrand;
    while (1) {
        xil_printf("Sequential RAM check [0x0-0x%x]...  ", Ncheck*4-1);
        for (int n=0; n < Ncheck; n++)
            sdram[n] = map_val(n);

        valid = 1;
        for (int n=0; n<Ncheck; n++)
        {
            x = sdram[n];
            if(x != map_val(n))
            {
                xil_printf("\r\n n=0x%x, [0x%x]: read 0x%x but expected 0x%x\r\n", n, n*4, x, map_val(n));
                valid = 0;
            }
        }
        if(valid)
            xil_printf("Passed\r\n");
        else
            xil_printf("Failed\r\n");
           
        valid = 1;
        xil_printf("Random access check... ");

        for (int n=0; n < Ncheck/8; n++)
        {
            // write 1-8 random spots in memory
            Nrand = (rand() % 8) + 1;
            for (int i=0; i < Nrand; i++)
            {
                x = rand() & (Ncheck-1);
                buf[i] = x;
                sdram[x] = map_val(x);
            }
            // read back
            for (int i=0; i < Nrand; i++)
            {
                x = sdram[buf[i]];
                if(x != map_val(buf[i]))
                {
                    xil_printf("\r\nn=0x%x, [0x%x]: read 0x%x but expected 0x%x\r\n", buf[i], buf[i]*4, x, map_val(buf[i]));
                    valid = 0;
                }
            }
        }

        if(valid)
            xil_printf("Passed\r\n\n");
        else
            xil_printf("Failed\r\n\n");
           
        print("Press key to rerun...\n\r");
        inbyte();

    }

    return 0;
}
