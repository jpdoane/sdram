/******************************************************************************
* Copyright (C) 2023 Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/
/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
// #include "platform.h"
#include "xil_printf.h"

#include <sleep.h>
#define AXI_BASEADDR 0x40000000

// u32 ramval(u32 n) { return 0xdeadbeef + (n<<16); }
u32 ramval(u32 n){
    return n;
    // return n;
}


u32 hash32(u32 x) {
    int n = 12;
    do // repeat for n from 12 downto 1
        x = ((x>>8)^x)*0x6B+n;
    while( --n!=0 );
    return x;
}

int main()
{
    // init_platform();

    print("Hello World SDRAM test.  Press key to start\n\r");
    inbyte();

    while(1)
    {
        u32 x;
        u32 valid = 1;
    
        u32* sdram = (u32*) AXI_BASEADDR;
    
        // int Ncheck = 1 << 22;
    
        // ram is 4M x 4 x 16bit = 8M x 32bit words = 0x800000 words
        u32 Ncheck = 0x400000;
        // u32 Ncheck = 0x101;
                     
        // while (valid) {
            xil_printf("\n\nInitializing RAM...\r\n");
            for (u32 n=0; n < Ncheck; n++)
                sdram[n] = ramval(n);
    
            xil_printf("Reading RAM 0x0...0x%x...\r\n", Ncheck-1);
            for (u32 n=0; n<Ncheck; n++)
            {
                x = sdram[n];
                if(x != ramval(n))
                {
                    xil_printf("[0x%x] (0x%x) read 0x%x but expected 0x%x\r\n", n, n << 2, x, ramval(n));
                    valid = 0;
                    // break;
                }
            }
        // }
    
        if(valid)
            xil_printf("RAM is valid!\r\n");
        else
            xil_printf("RAM has issues :(\r\n");

            
    print("Press key to rerun\n\r");
    inbyte();
        
    }

    return 0;
}
