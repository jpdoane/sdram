/****************************************************************************************
*
*    File Name:  MT48LC8M16A2.V  
*      Version:  0.0f
*         Date:  July 8th, 1999
*        Model:  BUS Functional
*    Simulator:  Model Technology (PC version 5.2e PE)
*
* Dependencies:  None
*
*       Author:  Son P. Huynh
*        Email:  sphuynh@micron.com
*        Phone:  (208) 368-3825
*      Company:  Micron Technology, Inc.
*        Model:  MT48LC8M16A2 (2Meg x 16 x 4 Banks)
*
*  Description:  Micron 128Mb SDRAM Verilog model
*
*   Limitation:  - Doesn't check for 4096 cycle refresh
*
*         Note:  - Set simulator resolution to "ps" accuracy
*                - Set Debug = 0 to disable $display messages
*
*   Disclaimer:  THESE DESIGNS ARE PROVIDED "AS IS" WITH NO WARRANTY 
*                WHATSOEVER AND MICRON SPECIFICALLY DISCLAIMS ANY 
*                IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
*                A PARTICULAR PURPOSE, OR AGAINST INFRINGEMENT.
*
*                Copyright � 1998 Micron Semiconductor Products, Inc.
*                All rights researved
*
* Rev   Author          Phone         Date        Changes
* ----  ----------------------------  ----------  ---------------------------------------
* 0.0f  Son Huynh       208-368-3825  07/08/1999  - Fix tWR = 1 clk + 7.5 ns (Auto)
*       Micron Technology Inc.                    - Fix tWR = 15 ns (Manual)
*                                                 - Fix tRP (Autoprecharge to AutoRefresh)
*
* 0.0a  Son Huynh       208-368-3825  05/13/1998  - First Release (from 64Mb rev 0.0e)
*       Micron Technology Inc.
****************************************************************************************/

// make separate rd/wr bus to avoid tristate sim issues

`timescale 1ns / 100ps
 
module MT48LC8M16A2
#(
    parameter Debug=0,
    parameter IO_LATENCY_NS=5.0,
    // Timing Parameters for -75 (PC133) and CAS Latency = 2
    parameter tAC  =   6.0,
    parameter tHZ  =   7.0,
    parameter tOH  =   2.7,
    parameter tMRD =   2.0,     // 2 clk Cycles
    parameter tRAS =  44.0,
    parameter tRC  =  66.0,
    parameter tRCD =  20.0,
    parameter tRP  =  20.0,
    parameter tRRD =  15.0,
    parameter tWRa =   7.5,     // A2 Version - Auto precharge mode only (1 clk + 7.5 ns)
    parameter tWRp =  15.0     // A2 Version - Precharge mode only (15 ns)
    
)
(
    input logic clk,
    sdram_dev_if.sub sdram_dev_if
);

    localparam dev_ADDR_WIDTH = sdram_dev_if.ADDR_WIDTH;
    localparam dev_ROW_WIDTH = sdram_dev_if.ROW_WIDTH;
    localparam dev_BANK_WIDTH = sdram_dev_if.BANK_WIDTH;
    localparam dev_COL_WIDTH = sdram_dev_if.COL_WIDTH;
    localparam BANK_DEPTH = 2 ** (dev_ROW_WIDTH+dev_COL_WIDTH);                                  // 2 Meg

    localparam READ_LATENCY = IO_LATENCY_NS*2;

    wire [15:0]            dev_read_data;
    wire                    dev_cke =        sdram_dev_if.cke;
    wire                    dev_cs =         sdram_dev_if.cs;
    wire [ 2:0]             dev_cmd =        sdram_dev_if.cmd;
    wire [ 1:0]             dev_dqm =        sdram_dev_if.dqm;
    wire [dev_ROW_WIDTH-1:0]    dev_addr =   sdram_dev_if.addr;
    wire [ 1:0]             dev_ba =         sdram_dev_if.ba;
    wire [15:0]             dev_write_data = sdram_dev_if.write_data;
    wire                    dev_wr_en =      sdram_dev_if.wr_en;
    assign                 #READ_LATENCY sdram_dev_if.read_data = dev_read_data;


    reg       [15 : 0] Bank0 [0 : BANK_DEPTH-1];
    reg       [15 : 0] Bank1 [0 : BANK_DEPTH-1];
    reg       [15 : 0] Bank2 [0 : BANK_DEPTH-1];
    reg       [15 : 0] Bank3 [0 : BANK_DEPTH-1];
 
    reg                   [1 : 0] Bank_addr [0 : 3];                // Bank Address Pipeline
    reg        [dev_COL_WIDTH - 1 : 0] Col_addr [0 : 3];                 // Column Address Pipeline
    reg                   [3 : 0] Command [0 : 3];                  // Command Operation Pipeline
    reg                   [1 : 0] Dqm_reg0, Dqm_reg1;               // DQM Operation Pipeline
    reg       [dev_ROW_WIDTH - 1 : 0] B0_row_addr, B1_row_addr, B2_row_addr, B3_row_addr;
 
    reg       [dev_ROW_WIDTH - 1 : 0] Mode_reg;
    reg       [15 : 0] Dq_reg, Dq_dqm;
    reg        [dev_COL_WIDTH - 1 : 0] Col_temp, Burst_counter;
 
    reg                           Act_b0, Act_b1, Act_b2, Act_b3;   // Bank Activate
    reg                           Pc_b0, Pc_b1, Pc_b2, Pc_b3;       // Bank Precharge
 
    reg                   [1 : 0] Bank_precharge     [0 : 3];       // Precharge Command
    reg                           A10_precharge      [0 : 3];       // addr[10] = 1 (All banks)
    reg                           Auto_precharge     [0 : 3];       // RW AutoPrecharge (Bank)
    reg                           Read_precharge     [0 : 3];       // R  AutoPrecharge
    reg                           Write_precharge    [0 : 3];       //  W AutoPrecharge
    integer                       Count_precharge    [0 : 3];       // RW AutoPrecharge (Counter)
    reg                           RW_interrupt_read  [0 : 3];       // RW Interrupt Read with Auto Precharge
    reg                           RW_interrupt_write [0 : 3];       // RW Interrupt Write with Auto Precharge
 
    reg                           Data_in_enable;
    reg                           Data_out_enable;
 
    reg                   [1 : 0] Bank, Previous_bank;
    reg       [dev_ROW_WIDTH - 1 : 0] Row;
    reg        [dev_COL_WIDTH - 1 : 0] Col, Col_brst;
 
    // Internal system clock
    reg                           CkeZ, Sys_clk;
 
    // Commands Decode
    wire      Active_enable    = ~dev_cs & (dev_cmd == 3'b011);   // ~dev_ras &  dev_cas &  dev_we
    wire      Aref_enable      = ~dev_cs & (dev_cmd == 3'b001);   // ~dev_ras & ~dev_cas &  dev_we
    wire      Burst_term       = ~dev_cs & (dev_cmd == 3'b110);   //  dev_ras &  dev_cas & ~dev_we
    wire      Mode_reg_enable  = ~dev_cs & (dev_cmd == 3'b000);   // ~dev_ras & ~dev_cas & ~dev_we
    wire      Prech_enable     = ~dev_cs & (dev_cmd == 3'b010);   // ~dev_ras &  dev_cas & ~dev_we
    wire      Read_enable      = ~dev_cs & (dev_cmd == 3'b101);   //  dev_ras & ~dev_cas &  dev_we
    wire      Write_enable     = ~dev_cs & (dev_cmd == 3'b100);   //  dev_ras & ~dev_cas & ~dev_we
 
    // Burst Length Decode
    wire      Burst_length_1   = ~Mode_reg[2] & ~Mode_reg[1] & ~Mode_reg[0];
    wire      Burst_length_2   = ~Mode_reg[2] & ~Mode_reg[1] &  Mode_reg[0];
    wire      Burst_length_4   = ~Mode_reg[2] &  Mode_reg[1] & ~Mode_reg[0];
    wire      Burst_length_8   = ~Mode_reg[2] &  Mode_reg[1] &  Mode_reg[0];
 
    // CAS Latency Decode
    wire      Cas_latency_2    = ~Mode_reg[6] &  Mode_reg[5] & ~Mode_reg[4];
    wire      Cas_latency_3    = ~Mode_reg[6] &  Mode_reg[5] &  Mode_reg[4];
 
    // Write Burst Mode
    wire      Write_burst_mode = Mode_reg[9];
 
    // reg       Debug;                         // Debug messages : 1 = On
    wire      Dq_chk           = Sys_clk & Data_in_enable;      // Check setup/hold time for DQ
 
    // assign    dq               = Dq_reg;                        // DQ buffer
    assign    dev_read_data               = Dq_reg;                        // DQ buffer
 
    // Commands Operation
    `define   ACT       0
    `define   NOP       1
    `define   READ      2
    `define   READ_A    3
    `define   WRITE     4
    `define   WRITE_A   5
    `define   PRECH     6
    `define   A_REF     7
    `define   BST       8
    `define   LMR       9
  
    // Timing Check variable
    integer   MRD_chk;
    integer   WR_counter [0 : 3];
    time      WR_chk [0 : 3];
    time      RC_chk, RRD_chk;
    time      RAS_chk0, RAS_chk1, RAS_chk2, RAS_chk3;
    time      RCD_chk0, RCD_chk1, RCD_chk2, RCD_chk3;
    time      RP_chk0, RP_chk1, RP_chk2, RP_chk3;
 
    initial begin
    //    Debug = 1'b0;
 
        Dq_reg = '0;
        {Data_in_enable, Data_out_enable} = 0;
        {Act_b0, Act_b1, Act_b2, Act_b3} = 4'b0000;
        {Pc_b0, Pc_b1, Pc_b2, Pc_b3} = 4'b0000;
        {WR_chk[0], WR_chk[1], WR_chk[2], WR_chk[3]} = 0;
        {WR_counter[0], WR_counter[1], WR_counter[2], WR_counter[3]} = 0;
        {RW_interrupt_read[0], RW_interrupt_read[1], RW_interrupt_read[2], RW_interrupt_read[3]} = 0;
        {RW_interrupt_write[0], RW_interrupt_write[1], RW_interrupt_write[2], RW_interrupt_write[3]} = 0;
        {MRD_chk, RC_chk, RRD_chk} = 0;
        {RAS_chk0, RAS_chk1, RAS_chk2, RAS_chk3} = 0;
        {RCD_chk0, RCD_chk1, RCD_chk2, RCD_chk3} = 0;
        {RP_chk0, RP_chk1, RP_chk2, RP_chk3} = 0;
        $timeformat (-9, 0, " ns", 12);
        //$readmemh("bank0.txt", Bank0);
        //$readmemh("bank1.txt", Bank1);
        //$readmemh("bank2.txt", Bank2);
        //$readmemh("bank3.txt", Bank3);
    end
 
    // System clock generator
    always begin
        @ (posedge clk) begin
            Sys_clk = CkeZ;
            CkeZ = dev_cke;
        end
        @ (negedge clk) begin
            Sys_clk = 1'b0;
        end
    end
 
    always @ (posedge Sys_clk) begin
        // Internal Commamd Pipelined
        Command[0] = Command[1];
        Command[1] = Command[2];
        Command[2] = Command[3];
        Command[3] = `NOP;
 
        Col_addr[0] = Col_addr[1];
        Col_addr[1] = Col_addr[2];
        Col_addr[2] = Col_addr[3];
        Col_addr[3] = {dev_COL_WIDTH{1'b0}};
 
        Bank_addr[0] = Bank_addr[1];
        Bank_addr[1] = Bank_addr[2];
        Bank_addr[2] = Bank_addr[3];
        Bank_addr[3] = 2'b0;
 
        Bank_precharge[0] = Bank_precharge[1];
        Bank_precharge[1] = Bank_precharge[2];
        Bank_precharge[2] = Bank_precharge[3];
        Bank_precharge[3] = 2'b0;
 
        A10_precharge[0] = A10_precharge[1];
        A10_precharge[1] = A10_precharge[2];
        A10_precharge[2] = A10_precharge[3];
        A10_precharge[3] = 1'b0;
 
        // dqm pipeline for Read
        Dqm_reg0 = Dqm_reg1;
        Dqm_reg1 = dev_dqm;
 
        // Read or Write with Auto Precharge Counter
        if (Auto_precharge[0] == 1'b1) begin
            Count_precharge[0] = Count_precharge[0] + 1;
        end
        if (Auto_precharge[1] == 1'b1) begin
            Count_precharge[1] = Count_precharge[1] + 1;
        end
        if (Auto_precharge[2] == 1'b1) begin
            Count_precharge[2] = Count_precharge[2] + 1;
        end
        if (Auto_precharge[3] == 1'b1) begin
            Count_precharge[3] = Count_precharge[3] + 1;
        end
 
        // tMRD Counter
        MRD_chk = MRD_chk + 1;
 
        // tWR Counter for Write
        WR_counter[0] = WR_counter[0] + 1;
        WR_counter[1] = WR_counter[1] + 1;
        WR_counter[2] = WR_counter[2] + 1;
        WR_counter[3] = WR_counter[3] + 1;
 
        // Auto Refresh
        if (Aref_enable == 1'b1) begin
            if (Debug) $display ("at time %t AREF : Auto Refresh", $time);
            // Auto Refresh to Auto Refresh
            if ($time - RC_chk < tRC) begin
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: tRC violation during Auto Refresh", $time);
            end
            // Precharge to Auto Refresh
            if ($time - RP_chk0 < tRP || $time - RP_chk1 < tRP || $time - RP_chk2 < tRP || $time - RP_chk3 < tRP) begin
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: tRP violation during Auto Refresh", $time);
            end
            // Precharge to Refresh
            if (Pc_b0 == 1'b0 || Pc_b1 == 1'b0 || Pc_b2 == 1'b0 || Pc_b3 == 1'b0) begin
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: All banks must be Precharge before Auto Refresh", $time);
            end
            // Record Current tRC time
            RC_chk = $time;
        end
 
        // Load Mode Register
        if (Mode_reg_enable == 1'b1) begin
            // Decode CAS Latency, Burst Length, Burst Type, and Write Burst Mode
            if (Pc_b0 == 1'b1 && Pc_b1 == 1'b1 && Pc_b2 == 1'b1 && Pc_b3 == 1'b1) begin
                Mode_reg = dev_addr;
                if (Debug) begin
                    $display ("at time %t LMR  : Load Mode Register", $time);
                    // CAS Latency
                    if (dev_addr[6 : 4] == 3'b010)
                        $display ("                            CAS Latency      = 2");
                    else if (dev_addr[6 : 4] == 3'b011)
                        $display ("                            CAS Latency      = 3");
                    else
                        $display ("                            CAS Latency      = Reserved");
                    // Burst Length
                    if (dev_addr[2 : 0] == 3'b000)
                        $display ("                            Burst Length     = 1");
                    else if (dev_addr[2 : 0] == 3'b001)
                        $display ("                            Burst Length     = 2");
                    else if (dev_addr[2 : 0] == 3'b010)
                        $display ("                            Burst Length     = 4");
                    else if (dev_addr[2 : 0] == 3'b011)
                        $display ("                            Burst Length     = 8");
                    else if (dev_addr[3 : 0] == 4'b0111)
                        $display ("                            Burst Length     = Full");
                    else
                        $display ("                            Burst Length     = Reserved");
                    // Burst Type
                    if (dev_addr[3] == 1'b0)
                        $display ("                            Burst Type       = Sequential");
                    else if (dev_addr[3] == 1'b1)
                        $display ("                            Burst Type       = Interleaved");
                    else
                        $display ("                            Burst Type       = Reserved");
                    // Write Burst Mode
                    if (dev_addr[9] == 1'b0)
                        $display ("                            Write Burst Mode = Programmed Burst Length");
                    else if (dev_addr[9] == 1'b1)
                        $display ("                            Write Burst Mode = Single Location Access");
                    else
                        $display ("                            Write Burst Mode = Reserved");
                end
            end else begin
 
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: all banks must be Precharge before Load Mode Register", $time);
            end
            // REF to LMR
            if ($time - RC_chk < tRC) begin
 
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: tRC violation during Load Mode Register", $time);
            end
            // LMR to LMR
            if (MRD_chk < tMRD) begin
 
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: tMRD violation during Load Mode Register", $time);
            end
            MRD_chk = 0;
        end
 
        // Active Block (Latch Bank Address and Row Address)
        if (Active_enable == 1'b1) begin
            if (dev_ba == 2'b00 && Pc_b0 == 1'b1) begin
                {Act_b0, Pc_b0} = 2'b10;
                B0_row_addr = dev_addr [dev_ROW_WIDTH - 1 : 0];
                RCD_chk0 = $time;
                RAS_chk0 = $time;
                if (Debug) $display ("at time %t ACT  : Bank = 0 Row = %d", $time, dev_addr);
                // Precharge to Activate Bank 0
                if ($time - RP_chk0 < tRP) begin
 
           //->tb.test_control.error_detected;
                   $display ("at time %t ERROR: tRP violation during Activate bank 0", $time);
                end
            end else if (dev_ba == 2'b01 && Pc_b1 == 1'b1) begin
                {Act_b1, Pc_b1} = 2'b10;
                B1_row_addr = dev_addr [dev_ROW_WIDTH - 1 : 0];
                RCD_chk1 = $time;
                RAS_chk1 = $time;
                if (Debug) $display ("at time %t ACT  : Bank = 1 Row = %d", $time, dev_addr);
                // Precharge to Activate Bank 1
                if ($time - RP_chk1 < tRP) begin
 
           //->tb.test_control.error_detected;
                    $display ("at time %t ERROR: tRP violation during Activate bank 1", $time);
                end
            end else if (dev_ba == 2'b10 && Pc_b2 == 1'b1) begin
                {Act_b2, Pc_b2} = 2'b10;
                B2_row_addr = dev_addr [dev_ROW_WIDTH - 1 : 0];
                RCD_chk2 = $time;
                RAS_chk2 = $time;
                if (Debug) $display ("at time %t ACT  : Bank = 2 Row = %d", $time, dev_addr);
                // Precharge to Activate Bank 2
                if ($time - RP_chk2 < tRP) begin
 
           //->tb.test_control.error_detected;
                    $display ("at time %t ERROR: tRP violation during Activate bank 2", $time);
                end
            end else if (dev_ba == 2'b11 && Pc_b3 == 1'b1) begin
                {Act_b3, Pc_b3} = 2'b10;
                B3_row_addr = dev_addr [dev_ROW_WIDTH - 1 : 0];
                RCD_chk3 = $time;
                RAS_chk3 = $time;
                if (Debug) $display ("at time %t ACT  : Bank = 3 Row = %d", $time, dev_addr);
                // Precharge to Activate Bank 3
                if ($time - RP_chk3 < tRP) begin
 
           //->tb.test_control.error_detected;
                    $display ("at time %t ERROR: tRP violation during Activate bank 3", $time);
                end
            end else if (dev_ba == 2'b00 && Pc_b0 == 1'b0) begin
 
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: Bank 0 is not Precharged.", $time);
            end else if (dev_ba == 2'b01 && Pc_b1 == 1'b0) begin
 
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: Bank 1 is not Precharged.", $time);
            end else if (dev_ba == 2'b10 && Pc_b2 == 1'b0) begin
 
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: Bank 2 is not Precharged.", $time);
            end else if (dev_ba == 2'b11 && Pc_b3 == 1'b0) begin
 
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: Bank 3 is not Precharged.", $time);
            end
            // Active Bank A to Active Bank B
            if ((Previous_bank != dev_ba) && ($time - RRD_chk < tRRD)) begin
 
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: tRRD violation during Activate bank = %d", $time, dev_ba);
            end
            // Load Mode Register to Active
            if (MRD_chk < tMRD ) begin
 
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: tMRD violation during Activate bank = %d", $time, dev_ba);
            end
            // Auto Refresh to Activate
            if ($time - RC_chk < tRC) begin
 
           //->tb.test_control.error_detected;
                $display ("at time %t ERROR: tRC violation during Activate bank = %d", $time, dev_ba);
            end
            // Record variables for checking violation
            RRD_chk = $time;
            Previous_bank = dev_ba;
        end
 
        // Precharge Block
        if (Prech_enable == 1'b1) begin
            if (dev_addr[10] == 1'b1) begin
                {Pc_b0, Pc_b1, Pc_b2, Pc_b3} = 4'b1111;
                {Act_b0, Act_b1, Act_b2, Act_b3} = 4'b0000;
                RP_chk0 = $time;
                RP_chk1 = $time;
                RP_chk2 = $time;
                RP_chk3 = $time;
                if (Debug) $display ("at time %t PRE  : Bank = ALL",$time);
                // Activate to Precharge all banks
                if (($time - RAS_chk0 < tRAS) || ($time - RAS_chk1 < tRAS) ||
                    ($time - RAS_chk2 < tRAS) || ($time - RAS_chk3 < tRAS)) begin
 
           //->tb.test_control.error_detected;
                    $display ("at time %t ERROR: tRAS violation during Precharge all bank", $time);
                end
                // tWR violation check for write
                if (($time - WR_chk[0] < tWRp) || ($time - WR_chk[1] < tWRp) ||
                    ($time - WR_chk[2] < tWRp) || ($time - WR_chk[3] < tWRp)) begin
 
           //->tb.test_control.error_detected;
                    $display ("at time %t ERROR: tWR violation during Precharge all bank", $time);
                end
            end else if (dev_addr[10] == 1'b0) begin
                if (dev_ba == 2'b00) begin
                    {Pc_b0, Act_b0} = 2'b10;
                    RP_chk0 = $time;
                    if (Debug) $display ("at time %t PRE  : Bank = 0",$time);
                    // Activate to Precharge Bank 0
                    if ($time - RAS_chk0 < tRAS) begin
 
               //->tb.test_control.error_detected;
                        $display ("at time %t ERROR: tRAS violation during Precharge bank 0", $time);
                    end
                end else if (dev_ba == 2'b01) begin
                    {Pc_b1, Act_b1} = 2'b10;
                    RP_chk1 = $time;
                    if (Debug) $display ("at time %t PRE  : Bank = 1",$time);
                    // Activate to Precharge Bank 1
                    if ($time - RAS_chk1 < tRAS) begin
 
               //->tb.test_control.error_detected;
                        $display ("at time %t ERROR: tRAS violation during Precharge bank 1", $time);
                    end
                end else if (dev_ba == 2'b10) begin
                    {Pc_b2, Act_b2} = 2'b10;
                    RP_chk2 = $time;
                    if (Debug) $display ("at time %t PRE  : Bank = 2",$time);
                    // Activate to Precharge Bank 2
                    if ($time - RAS_chk2 < tRAS) begin
 
               //->tb.test_control.error_detected;
                        $display ("at time %t ERROR: tRAS violation during Precharge bank 2", $time);
                    end
                end else if (dev_ba == 2'b11) begin
                    {Pc_b3, Act_b3} = 2'b10;
                    RP_chk3 = $time;
                    if (Debug) $display ("at time %t PRE  : Bank = 3",$time);
                    // Activate to Precharge Bank 3
                    if ($time - RAS_chk3 < tRAS) begin
 
               //->tb.test_control.error_detected;
                        $display ("at time %t ERROR: tRAS violation during Precharge bank 3", $time);
                    end
                end
                // tWR violation check for write
                if ($time - WR_chk[dev_ba] < tWRp) begin
 
           //->tb.test_control.error_detected;
                    $display ("at time %t ERROR: tWR violation during Precharge bank %d", $time, dev_ba);
                end
            end
            // Terminate a Write Immediately (if same bank or all banks)
            if (Data_in_enable == 1'b1 && (Bank == dev_ba || dev_addr[10] == 1'b1)) begin
                Data_in_enable = 1'b0;
            end
            // Precharge Command Pipeline for Read
            if (Cas_latency_3 == 1'b1) begin
                Command[2] = `PRECH;
                Bank_precharge[2] = dev_ba;
                A10_precharge[2] = dev_addr[10];
            end else if (Cas_latency_2 == 1'b1) begin
                Command[1] = `PRECH;
                Bank_precharge[1] = dev_ba;
                A10_precharge[1] = dev_addr[10];
            end
        end
 
        // Burst terminate
        if (Burst_term == 1'b1) begin
            // Terminate a Write Immediately
            if (Data_in_enable == 1'b1) begin
                Data_in_enable = 1'b0;
            end
            // Terminate a Read Depend on CAS Latency
            if (Cas_latency_3 == 1'b1) begin
                Command[2] = `BST;
            end else if (Cas_latency_2 == 1'b1) begin
                Command[1] = `BST;
            end
            if (Debug) $display ("at time %t BST  : Burst Terminate",$time);
        end
 
        // Read, Write, Column Latch
        if (Read_enable == 1'b1 || Write_enable == 1'b1) begin
            // Check to see if bank is open (ACT)
            if ((dev_ba == 2'b00 && Pc_b0 == 1'b1) || (dev_ba == 2'b01 && Pc_b1 == 1'b1) ||
                (dev_ba == 2'b10 && Pc_b2 == 1'b1) || (dev_ba == 2'b11 && Pc_b3 == 1'b1)) begin
 
           //->tb.test_control.error_detected;
                $display("at time %t ERROR: Cannot Read or Write - Bank %d is not Activated (%d)", $time, dev_ba, Pc_b0);
            end
            // Activate to Read or Write
            if ((dev_ba == 2'b00) && ($time - RCD_chk0 < tRCD))
          begin
         //->tb.test_control.error_detected;
                 $display("at time %t ERROR: tRCD violation during Read or Write to Bank 0", $time);
          end
 
            if ((dev_ba == 2'b01) && ($time - RCD_chk1 < tRCD))
          begin
         //->tb.test_control.error_detected;
                 $display("at time %t ERROR: tRCD violation during Read or Write to Bank 1", $time);
          end
            if ((dev_ba == 2'b10) && ($time - RCD_chk2 < tRCD))
          begin
         //->tb.test_control.error_detected;
                 $display("at time %t ERROR: tRCD violation during Read or Write to Bank 2", $time);
          end
            if ((dev_ba == 2'b11) && ($time - RCD_chk3 < tRCD))
          begin
         //->tb.test_control.error_detected;
                 $display("at time %t ERROR: tRCD violation during Read or Write to Bank 3", $time);
          end
            // Read Command
            if (Read_enable == 1'b1) begin
                // CAS Latency pipeline
                if (Cas_latency_3 == 1'b1) begin
                    if (dev_addr[10] == 1'b1) begin
                        Command[2] = `READ_A;
                    end else begin
                        Command[2] = `READ;
                    end
                    Col_addr[2] = dev_addr[dev_COL_WIDTH-1 : 0];
                    Bank_addr[2] = dev_ba;
                end else if (Cas_latency_2 == 1'b1) begin
                    if (dev_addr[10] == 1'b1) begin
                        Command[1] = `READ_A;
                    end else begin
                        Command[1] = `READ;
                    end
                    Col_addr[1] = dev_addr[dev_COL_WIDTH-1 : 0];
                    Bank_addr[1] = dev_ba;
                end
 
                // Read interrupt Write (terminate Write immediately)
                if (Data_in_enable == 1'b1) begin
                    Data_in_enable = 1'b0;
                end
 
            // Write Command
            end else if (Write_enable == 1'b1) begin
                if (dev_addr[10] == 1'b1) begin
                    if (Debug) $display ("at time %t WRITE: Write Bank %d addr %d with Autoprecharge", $time, dev_ba, dev_addr);
                    Command[0] = `WRITE_A;
                end else begin
                    if (Debug) $display ("at time %t WRITE: Write Bank %d addr %d without Autoprecharge", $time, dev_ba, dev_addr);
                    Command[0] = `WRITE;
                end
                Col_addr[0] = dev_addr[dev_COL_WIDTH-1 : 0];
                Bank_addr[0] = dev_ba;
 
                // Write interrupt Write (terminate Write immediately)
                if (Data_in_enable == 1'b1) begin
                    Data_in_enable = 1'b0;
                end
 
                // Write interrupt Read (terminate Read immediately)
                if (Data_out_enable == 1'b1) begin
                    Data_out_enable = 1'b0;
                end
            end
 
            // Interrupting a Write with Autoprecharge
            if (Auto_precharge[Bank] == 1'b1 && Write_precharge[Bank] == 1'b1) begin
                RW_interrupt_write[Bank] = 1'b1;
                if (Debug) $display ("at time %t NOTE : Read/Write Bank %d interrupt Write Bank %d with Autoprecharge", $time, dev_ba, Bank);
            end
 
            // Interrupting a Read with Autoprecharge
            if (Auto_precharge[Bank] == 1'b1 && Read_precharge[Bank] == 1'b1) begin
                RW_interrupt_read[Bank] = 1'b1;
                if (Debug) $display ("at time %t NOTE : Read/Write Bank %d interrupt Read Bank %d with Autoprecharge", $time, dev_ba, Bank);
            end
 
            // Read or Write with Auto Precharge
            if (dev_addr[10] == 1'b1) begin
                Auto_precharge[dev_ba] = 1'b1;
                Count_precharge[dev_ba] = 0;
                if (Read_enable == 1'b1) begin
                    Read_precharge[dev_ba] = 1'b1;
                end else if (Write_enable == 1'b1) begin
                    Write_precharge[dev_ba] = 1'b1;
                end
            end
        end
 
        //  Read with Auto Precharge Calculation
        //      The device start internal precharge:
        //          1.  CAS Latency - 1 cycles before last burst
        //      and 2.  Meet minimum tRAS requirement
        //       or 3.  Interrupt by a Read or Write (with or without AutoPrecharge)
        if ((Auto_precharge[0] == 1'b1) && (Read_precharge[0] == 1'b1)) begin
            if ((($time - RAS_chk0 >= tRAS) &&                                                      // Case 2
                ((Burst_length_1 == 1'b1 && Count_precharge[0] >= 1) ||                             // Case 1
                 (Burst_length_2 == 1'b1 && Count_precharge[0] >= 2) ||
                 (Burst_length_4 == 1'b1 && Count_precharge[0] >= 4) ||
                 (Burst_length_8 == 1'b1 && Count_precharge[0] >= 8))) ||
                 (RW_interrupt_read[0] == 1'b1)) begin                                              // Case 3
                    Pc_b0 = 1'b1;
                    Act_b0 = 1'b0;
                    RP_chk0 = $time;
                    Auto_precharge[0] = 1'b0;
                    Read_precharge[0] = 1'b0;
                    RW_interrupt_read[0] = 1'b0;
                    if (Debug) $display ("at time %t NOTE : Start Internal Auto Precharge for Bank 0", $time);
            end
        end
        if ((Auto_precharge[1] == 1'b1) && (Read_precharge[1] == 1'b1)) begin
            if ((($time - RAS_chk1 >= tRAS) &&
                ((Burst_length_1 == 1'b1 && Count_precharge[1] >= 1) || 
                 (Burst_length_2 == 1'b1 && Count_precharge[1] >= 2) ||
                 (Burst_length_4 == 1'b1 && Count_precharge[1] >= 4) ||
                 (Burst_length_8 == 1'b1 && Count_precharge[1] >= 8))) ||
                 (RW_interrupt_read[1] == 1'b1)) begin
                    Pc_b1 = 1'b1;
                    Act_b1 = 1'b0;
                    RP_chk1 = $time;
                    Auto_precharge[1] = 1'b0;
                    Read_precharge[1] = 1'b0;
                    RW_interrupt_read[1] = 1'b0;
                    if (Debug) $display ("at time %t NOTE : Start Internal Auto Precharge for Bank 1", $time);
            end
        end
        if ((Auto_precharge[2] == 1'b1) && (Read_precharge[2] == 1'b1)) begin
            if ((($time - RAS_chk2 >= tRAS) &&
                ((Burst_length_1 == 1'b1 && Count_precharge[2] >= 1) || 
                 (Burst_length_2 == 1'b1 && Count_precharge[2] >= 2) ||
                 (Burst_length_4 == 1'b1 && Count_precharge[2] >= 4) ||
                 (Burst_length_8 == 1'b1 && Count_precharge[2] >= 8))) ||
                 (RW_interrupt_read[2] == 1'b1)) begin
                    Pc_b2 = 1'b1;
                    Act_b2 = 1'b0;
                    RP_chk2 = $time;
                    Auto_precharge[2] = 1'b0;
                    Read_precharge[2] = 1'b0;
                    RW_interrupt_read[2] = 1'b0;
                    if (Debug) $display ("at time %t NOTE : Start Internal Auto Precharge for Bank 2", $time);
            end
        end
        if ((Auto_precharge[3] == 1'b1) && (Read_precharge[3] == 1'b1)) begin
            if ((($time - RAS_chk3 >= tRAS) &&
                ((Burst_length_1 == 1'b1 && Count_precharge[3] >= 1) || 
                 (Burst_length_2 == 1'b1 && Count_precharge[3] >= 2) ||
                 (Burst_length_4 == 1'b1 && Count_precharge[3] >= 4) ||
                 (Burst_length_8 == 1'b1 && Count_precharge[3] >= 8))) ||
                 (RW_interrupt_read[3] == 1'b1)) begin
                    Pc_b3 = 1'b1;
                    Act_b3 = 1'b0;
                    RP_chk3 = $time;
                    Auto_precharge[3] = 1'b0;
                    Read_precharge[3] = 1'b0;
                    RW_interrupt_read[3] = 1'b0;
                    if (Debug) $display ("at time %t NOTE : Start Internal Auto Precharge for Bank 3", $time);
            end
        end
 
        // Internal Precharge or Bst
        if (Command[0] == `PRECH) begin                         // Precharge terminate a read with same bank or all banks
            if (Bank_precharge[0] == Bank || A10_precharge[0] == 1'b1) begin
                if (Data_out_enable == 1'b1) begin
                    Data_out_enable = 1'b0;
                end
            end
        end else if (Command[0] == `BST) begin                  // BST terminate a read to current bank
            if (Data_out_enable == 1'b1) begin
                Data_out_enable = 1'b0;
            end
        end
 
        if (Data_out_enable == 1'b0) begin
            Dq_reg <= #tOH '0;
        end
 
        // Detect Read or Write command
        if (Command[0] == `READ || Command[0] == `READ_A) begin
            Bank = Bank_addr[0];
            Col = Col_addr[0];
            Col_brst = Col_addr[0];
            if (Bank_addr[0] == 2'b00) begin
                Row = B0_row_addr;
            end else if (Bank_addr[0] == 2'b01) begin
                Row = B1_row_addr;
            end else if (Bank_addr[0] == 2'b10) begin
                Row = B2_row_addr;
            end else if (Bank_addr[0] == 2'b11) begin
                Row = B3_row_addr;
            end
            Burst_counter = 0;
            Data_in_enable = 1'b0;
            Data_out_enable = 1'b1;
        end else if (Command[0] == `WRITE || Command[0] == `WRITE_A) begin
            Bank = Bank_addr[0];
            Col = Col_addr[0];
            Col_brst = Col_addr[0];
            if (Bank_addr[0] == 2'b00) begin
                Row = B0_row_addr;
            end else if (Bank_addr[0] == 2'b01) begin
                Row = B1_row_addr;
            end else if (Bank_addr[0] == 2'b10) begin
                Row = B2_row_addr;
            end else if (Bank_addr[0] == 2'b11) begin
                Row = B3_row_addr;
            end
            Burst_counter = 0;
            Data_in_enable = 1'b1;
            Data_out_enable = 1'b0;
        end
 
        // DQ buffer (Driver/Receiver)
        if (Data_in_enable == 1'b1) begin                                   // Writing Data to Memory
            // Array buffer
            if (Bank == 2'b00) Dq_dqm = Bank0 [{Row, Col}];
            if (Bank == 2'b01) Dq_dqm = Bank1 [{Row, Col}];
            if (Bank == 2'b10) Dq_dqm = Bank2 [{Row, Col}];
            if (Bank == 2'b11) Dq_dqm = Bank3 [{Row, Col}];
            // dqm operation
            if (dev_dqm[0] == 1'b0) Dq_dqm [ 7 : 0] = dev_write_data [ 7 : 0];
            if (dev_dqm[1] == 1'b0) Dq_dqm [15 : 8] = dev_write_data [15 : 8];
            // if (dev_dqm[0] == 1'b0) Dq_dqm [ 7 : 0] = dq [ 7 : 0];
            // if (dev_dqm[1] == 1'b0) Dq_dqm [15 : 8] = dq [15 : 8];

            // Write to memory
            if (Bank == 2'b00) Bank0 [{Row, Col}] = Dq_dqm;
            if (Bank == 2'b01) Bank1 [{Row, Col}] = Dq_dqm;
            if (Bank == 2'b10) Bank2 [{Row, Col}] = Dq_dqm;
            if (Bank == 2'b11) Bank3 [{Row, Col}] = Dq_dqm;

            // Output result
            if (dev_dqm == 2'b11) begin
                if (Debug) $display("at time %t WRITE: Bank = %d Row = %d, Col = %d, Data = Hi-Z due to DQM", $time, Bank, Row, Col);
            end else begin
                if (Debug) $display("at time %t WRITE: Bank = %d Row = %d, Col = %d, Data = %h, dqm = %b", $time, Bank, Row, Col, Dq_dqm, dev_dqm);
                // Record tWR time and reset counter
                WR_chk [Bank] = $time;
                WR_counter [Bank] = 0;
            end
            // Advance burst counter subroutine
            #tHZ Burst;
        end else if (Data_out_enable == 1'b1) begin                         // Reading Data from Memory
            // Array buffer
            if (Bank == 2'b00) Dq_dqm [15 : 0] = Bank0 [{Row, Col}];
            if (Bank == 2'b01) Dq_dqm [15 : 0] = Bank1 [{Row, Col}];
            if (Bank == 2'b10) Dq_dqm [15 : 0] = Bank2 [{Row, Col}];
            if (Bank == 2'b11) Dq_dqm [15 : 0] = Bank3 [{Row, Col}];
            // dqm operation
            if (Dqm_reg0[0] == 1'b1) Dq_dqm [ 7 : 0] = 8'b0;
            if (Dqm_reg0[1] == 1'b1) Dq_dqm [15 : 8] = 8'b0;
            // Display result
            Dq_reg [15 : 0] = #tAC Dq_dqm [15 : 0];
            if (Dqm_reg0 == 2'b11) begin
                if (Debug) $display("at time %t READ : Bank = %d Row = %d, Col = %d, Data = Hi-Z due to DQM", $time, Bank, Row, Col);
            end else begin
                if (Debug) $display("at time %t READ : Bank = %d Row = %d, Col = %d, Data = %h, dqm = %b", $time, Bank, Row, Col, Dq_reg, Dqm_reg0);
            end
            // Advance burst counter subroutine
            Burst;
        end
    end
 
    //  Write with Auto Precharge Calculation
    //      The device start internal precharge:
    //          1.  tWR Clock after last burst
    //      and 2.  Meet minimum tRAS requirement
    //       or 3.  Interrupt by a Read or Write (with or without AutoPrecharge)
    always @ (WR_counter[0]) begin
        if ((Auto_precharge[0] == 1'b1) && (Write_precharge[0] == 1'b1)) begin
            if ((($time - RAS_chk0 >= tRAS) &&                                                          // Case 2
               (((Burst_length_1 == 1'b1 || Write_burst_mode == 1'b1) && Count_precharge [0] >= 1) ||   // Case 1
                 (Burst_length_2 == 1'b1 && Count_precharge [0] >= 2) ||
                 (Burst_length_4 == 1'b1 && Count_precharge [0] >= 4) ||
                 (Burst_length_8 == 1'b1 && Count_precharge [0] >= 8))) ||
                 (RW_interrupt_write[0] == 1'b1 && WR_counter[0] >= 2)) begin                           // Case 3 (stop count when interrupt)
                    Auto_precharge[0] = 1'b0;
                    Write_precharge[0] = 1'b0;
                    RW_interrupt_write[0] = 1'b0;
                    #tWRa;                          // Wait for tWR
                    Pc_b0 = 1'b1;
                    Act_b0 = 1'b0;
                    RP_chk0 = $time;
                    if (Debug) $display ("at time %t NOTE : Start Internal Auto Precharge for Bank 0", $time);
            end
        end
    end
    always @ (WR_counter[1]) begin
        if ((Auto_precharge[1] == 1'b1) && (Write_precharge[1] == 1'b1)) begin
            if ((($time - RAS_chk1 >= tRAS) &&
               (((Burst_length_1 == 1'b1 || Write_burst_mode == 1'b1) && Count_precharge [1] >= 1) || 
                 (Burst_length_2 == 1'b1 && Count_precharge [1] >= 2) ||
                 (Burst_length_4 == 1'b1 && Count_precharge [1] >= 4) ||
                 (Burst_length_8 == 1'b1 && Count_precharge [1] >= 8))) ||
                 (RW_interrupt_write[1] == 1'b1 && WR_counter[1] >= 2)) begin
                    Auto_precharge[1] = 1'b0;
                    Write_precharge[1] = 1'b0;
                    RW_interrupt_write[1] = 1'b0;
                    #tWRa;                          // Wait for tWR
                    Pc_b1 = 1'b1;
                    Act_b1 = 1'b0;
                    RP_chk1 = $time;
                    if (Debug) $display ("at time %t NOTE : Start Internal Auto Precharge for Bank 1", $time);
            end
        end
    end
    always @ (WR_counter[2]) begin
        if ((Auto_precharge[2] == 1'b1) && (Write_precharge[2] == 1'b1)) begin
            if ((($time - RAS_chk2 >= tRAS) &&
               (((Burst_length_1 == 1'b1 || Write_burst_mode == 1'b1) && Count_precharge [2] >= 1) || 
                 (Burst_length_2 == 1'b1 && Count_precharge [2] >= 2) ||
                 (Burst_length_4 == 1'b1 && Count_precharge [2] >= 4) ||
                 (Burst_length_8 == 1'b1 && Count_precharge [2] >= 8))) ||
                 (RW_interrupt_write[2] == 1'b1 && WR_counter[2] >= 2)) begin
                    Auto_precharge[2] = 1'b0;
                    Write_precharge[2] = 1'b0;
                    RW_interrupt_write[2] = 1'b0;
                    #tWRa;                          // Wait for tWR
                    Pc_b2 = 1'b1;
                    Act_b2 = 1'b0;
                    RP_chk2 = $time;
                    if (Debug) $display ("at time %t NOTE : Start Internal Auto Precharge for Bank 2", $time);
            end
        end
    end
    always @ (WR_counter[3]) begin
        if ((Auto_precharge[3] == 1'b1) && (Write_precharge[3] == 1'b1)) begin
            if ((($time - RAS_chk3 >= tRAS) &&
               (((Burst_length_1 == 1'b1 || Write_burst_mode == 1'b1) && Count_precharge [3] >= 1) || 
                 (Burst_length_2 == 1'b1 && Count_precharge [3] >= 2) ||
                 (Burst_length_4 == 1'b1 && Count_precharge [3] >= 4) ||
                 (Burst_length_8 == 1'b1 && Count_precharge [3] >= 8))) ||
                 (RW_interrupt_write[3] == 1'b1 && WR_counter[3] >= 2)) begin
                    Auto_precharge[3] = 1'b0;
                    Write_precharge[3] = 1'b0;
                    RW_interrupt_write[3] = 1'b0;
                    #tWRa;                          // Wait for tWR
                    Pc_b3 = 1'b1;
                    Act_b3 = 1'b0;
                    RP_chk3 = $time;
                    if (Debug) $display ("at time %t NOTE : Start Internal Auto Precharge for Bank 3", $time);
            end
        end
    end
 
    task Burst;
        begin
            // Advance Burst Counter
            Burst_counter = Burst_counter + 1;
 
            // Burst Type
            if (Mode_reg[3] == 1'b0) begin                                  // Sequential Burst
                Col_temp = Col + 1;
            end else if (Mode_reg[3] == 1'b1) begin                         // Interleaved Burst
                Col_temp[2] =  Burst_counter[2] ^  Col_brst[2];
                Col_temp[1] =  Burst_counter[1] ^  Col_brst[1];
                Col_temp[0] =  Burst_counter[0] ^  Col_brst[0];
            end
 
            // Burst Length
            if (Burst_length_2) begin                                       // Burst Length = 2
                Col [0] = Col_temp [0];
            end else if (Burst_length_4) begin                              // Burst Length = 4
                Col [1 : 0] = Col_temp [1 : 0];
            end else if (Burst_length_8) begin                              // Burst Length = 8
                Col [2 : 0] = Col_temp [2 : 0];
            end else begin                                                  // Burst Length = FULL
                Col = Col_temp;
            end
 
            // Burst Read Single Write            
            if (Write_burst_mode == 1'b1) begin
                Data_in_enable = 1'b0;
            end
 
            // Data Counter
            if (Burst_length_1 == 1'b1) begin
                if (Burst_counter >= 1) begin
                    Data_in_enable = 1'b0;
                    Data_out_enable = 1'b0;
                end
            end else if (Burst_length_2 == 1'b1) begin
                if (Burst_counter >= 2) begin
                    Data_in_enable = 1'b0;
                    Data_out_enable = 1'b0;
                end
            end else if (Burst_length_4 == 1'b1) begin
                if (Burst_counter >= 4) begin
                    Data_in_enable = 1'b0;
                    Data_out_enable = 1'b0;
                end
            end else if (Burst_length_8 == 1'b1) begin
                if (Burst_counter >= 8) begin
                    Data_in_enable = 1'b0;
                    Data_out_enable = 1'b0;
                end
            end
        end
    endtask
 
    // Timing Parameters for -75 (PC133) and CAS Latency = 2
    specify
        specparam
                    tAH  =  0.8,                                        // addr, ba Hold Time
                    tAS  =  1.5,                                        // addr, ba Setup Time
                    tCH  =  2.5,                                        // Clock High-Level Width
                    tCL  =  2.5,                                        // Clock Low-Level Width
                    tCK  = 10,                                          // Clock Cycle Time
                    tDH  =  0.8,                                        // Data-in Hold Time
                    tDS  =  1.5,                                        // Data-in Setup Time
                    tCKH =  0.8,                                        // CKE Hold  Time
                    tCKS =  1.5,                                        // CKE Setup Time
                    tCMH =  0.8,                                        // CS#, RAS#, CAS#, WE#, DQM# Hold  Time
                    tCMS =  1.5;                                        // CS#, RAS#, CAS#, WE#, DQM# Setup Time
        $width    (posedge clk,           tCH);
        $width    (negedge clk,           tCL);
        $period   (negedge clk,           tCK);
        $period   (posedge clk,           tCK);
        $setuphold(posedge clk,    dev_cke,   tCKS, tCKH);
        $setuphold(posedge clk,    dev_cs,  tCMS, tCMH);
        $setuphold(posedge clk,    dev_cas, tCMS, tCMH);
        $setuphold(posedge clk,    dev_ras, tCMS, tCMH);
        $setuphold(posedge clk,    dev_we,  tCMS, tCMH);
        $setuphold(posedge clk,    dev_addr,  tAS,  tAH);
        $setuphold(posedge clk,    dev_ba,    tAS,  tAH);
        $setuphold(posedge clk,    dev_dqm,   tCMS, tCMH);
        // $setuphold(posedge Dq_chk, dq,    tDS,  tDH);
        $setuphold(posedge Dq_chk, dev_write_data,    tDS,  tDH);
    endspecify
 
endmodule
