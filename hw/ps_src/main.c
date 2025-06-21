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
    return 0xab00cd00 + (n<<16) + n;
    // return n;
}

int main()
{
    // init_platform();

    print("Hello World SDRAM test\n\r");
    // inbyte();

	u32 x;
    int valid;

	u32* sdram = (u32*) AXI_BASEADDR;

    int Ncheck = 0x10;

    while (1) {
        xil_printf("\n\nInitializing RAM...\r\n");
        for (int n=0; n < Ncheck; n++)
        {
            sdram[n] = ramval(n);
            // xil_printf("write [0x%x] <= 0x%x\r\n", n, ramval(n));
            usleep(100000);
        }

        xil_printf("Reading RAM 0x0...0x%x...\r\n", Ncheck-1);
        valid = 1;
        for (u32 n=0; n<Ncheck; n++)
        {
        x = sdram[n];
            if(x != ramval(n))
            {
                xil_printf("[0x%x] read 0x%x but expected 0x%x\r\n", n, x, ramval(n));
                valid = 0;
            }
            // else
                // xil_printf("read 0x%x\r\n", n);

            usleep(100000);

        }
        if(valid)
            xil_printf("RAM is valid!\r\n");
        else
            xil_printf("RAM has issues :(\r\n");

        usleep(1000000);
    }

    // cleanup_platform();
    return 0;
}
