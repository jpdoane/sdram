/*
 * SDRAM dual-master test -- Zynq PS side
 *
 * Hardware architecture:
 *   Zynq PS  --[AXI-Lite M00, 0x4000_0000]--> dual_master_sdram AXI port
 *   PL portb_tester (CPU_CLK_DIV=24, N_TEST_WORDS=4096) --> dual_master_sdram portB port
 *   dual_master_sdram --> sdram_core --> sdram_io --> SDRAM chip
 *
 * The PS runs sequential and random AXI read/write tests continuously.
 * Simultaneously, the PL portb_tester independently exercises the portB
 * (synchronous CPU) port on a decimated ~2 MHz clock.  AXI has priority;
 * portB transactions are transparently stalled when AXI is active.
 *
 * LED status (from portb_tester in PL -- runs independently of PS):
 *   LED[0]  portB test complete
 *   LED[1]  portB test PASS  (all 4096 word readbacks matched)
 *   LED[2]  portB test FAIL  (at least one mismatch)
 *   LED[3]  heartbeat blink  (PL clock is running)
 *
 * SW[0]  restart the portB tester (rising edge triggers a new pass)
 *
 * SDRAM base address: 0x4000_0000 (32 MB window, word-addressed)
 */

#include <stdio.h>
#include "xil_printf.h"
#include <sleep.h>
#include <stdlib.h>

#define SDRAM_BASEADDR  0x40000000
#define SDRAM_SIZE      0x2000000   /* 32 MB */
#define NCHECK          0x800000    /* 32M words = full chip */

static inline u32 map_val(u32 n) { return n; }

int main(void)
{
    xil_printf("\r\n\r\n");
    xil_printf("========================================\r\n");
    xil_printf(" SDRAM dual-master test (AXI / portB)\r\n");
    xil_printf(" AXI base: 0x%08x  size: %d MB\r\n",
               SDRAM_BASEADDR, SDRAM_SIZE >> 20);
    xil_printf(" portB tester: running in PL (see LEDs)\r\n");
    xil_printf("========================================\r\n\r\n");

    volatile u32 *sdram = (volatile u32 *)SDRAM_BASEADDR;
    int valid;
    u32 x;
    u32 buf[8];
    int Nrand;

    while (1) {
        /* ---- Sequential write then read-back ---- */
        xil_printf("Sequential check [0x0 .. 0x%x] ... ", NCHECK * 4 - 1);

        for (int n = 0; n < NCHECK; n++)
            sdram[n] = map_val(n);

        valid = 1;
        for (int n = 0; n < NCHECK; n++) {
            x = sdram[n];
            if (x != map_val(n)) {
                xil_printf("\r\n  MISMATCH n=0x%x addr=0x%x "
                           "read=0x%x expected=0x%x\r\n",
                           n, n * 4, x, map_val(n));
                valid = 0;
            }
        }
        xil_printf(valid ? "PASS\r\n" : "FAIL\r\n");

        /* ---- Random access write/read ---- */
        xil_printf("Random access check ... ");
        valid = 1;

        for (int n = 0; n < NCHECK / 8; n++) {
            /* write 1-8 random locations */
            Nrand = (rand() % 8) + 1;
            for (int i = 0; i < Nrand; i++) {
                x = rand() & (NCHECK - 1);
                buf[i] = x;
                sdram[x] = map_val(x);
            }
            /* read back */
            for (int i = 0; i < Nrand; i++) {
                x = sdram[buf[i]];
                if (x != map_val(buf[i])) {
                    xil_printf("\r\n  MISMATCH addr=0x%x "
                               "read=0x%x expected=0x%x\r\n",
                               buf[i] * 4, x, map_val(buf[i]));
                    valid = 0;
                }
            }
        }
        xil_printf(valid ? "PASS\r\n\r\n" : "FAIL\r\n\r\n");

        xil_printf("Press any key to rerun AXI test...\r\n");
        inbyte();
    }

    return 0;
}
