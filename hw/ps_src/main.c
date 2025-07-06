#include <stdio.h>
#include "xil_printf.h"
#include <sleep.h>

#define SDRAM_BASEADDR   0x40000000
#define SDRAM_SIZE       0x2000000

u32 map_val(u32 n) { return n; }
u32 map_addr(u32 n) { return n; }

int main()
{
    xil_printf("\n\n\n\n\rSDRAM check on AXI bus: 0x%x\n\r", SDRAM_BASEADDR);
    print("Press key to start\n\r");
    inbyte();

    int valid;
	u32 x;
	u32* sdram = (u32*) SDRAM_BASEADDR;
    int Ncheck = 0x800000;

    while (1) {
        xil_printf("Sequential initialization of elements 0x0-0x%x...\r\n", Ncheck*4-1);
        for (int n=0; n < Ncheck; n++)
            sdram[n] = map_val(n);

        xil_printf("Sequential Check...\r\n");
        valid = 1;
        for (int n=0; n<Ncheck; n++)
        {
            // xil_printf("reading 0x%x...\r\n", n);
            x = sdram[n];
            if(x != map_val(n))
            {
                xil_printf("n=0x%x, [0x%x]: read 0x%x but expected 0x%x\r\n", n, n*4, x, map_val(n));
                valid = 0;
            }
        }
        if(valid)
            xil_printf("Passed :)\r\n\n");
        else
            xil_printf("Failed :(\r\n\n");
           
        print("Press key to continue\n\r");
        inbyte();
    }

    return 0;
}
