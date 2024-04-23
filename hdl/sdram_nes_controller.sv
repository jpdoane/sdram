`timescale 1ns / 100ps

// sdram controller for use in NES
// ram is clocked at 8x ppu clock (~42HMz)

// in main operational mode:
//  every 8 cycles is ppu read
//  every 24 cycles is cpu read
// 8-cycle period:
// 1:   Activate PPU Bank
// 2:   Activate CPU Bank (1st pass)
// 3:   Read/Write PPU
// 4:   Read/Write CPU (1st pass)
// 5:   PPU data valid 
// 6:   CPU data valid (1st pass) or autorefresh (as needed)
// 7:   NOP
// 8:   NOP

// sync manually restarts this cycle (e.g. to align with cpu/ppu clicks)

module sdram_nes_controller #(
    parameter ADDR_DEPTH            = 23, // per bank
    parameter COL_DEPTH             = 10,
    parameter TICKS_REFRESH         = 12,
    parameter TICKS_STARTUP         = 500
    )(
    // main clocks
    input logic clk, rst,
    input logic sync,       // sync the start of 24-clock cycle
    output logic rdy,       // ram ready for rd/wr commands

    //ppu interface
    // inputs are latched on cycle 7mod8
    // read data is valid on cycle 0mod8
    input logic [7:0] ppu_data_wr,
    input logic [ADDR_DEPTH-1:0] ppu_addr,
    input logic ppu_rd, ppu_wr,
    output logic [7:0] ppu_data_rd,

    //cpu interface
    // inputs are latched on cycle 23
    // read data is valid on cycle 8
    input logic [7:0] cpu_data_wr,
    input logic [ADDR_DEPTH-1:0] cpu_addr,
    input logic cpu_rd, cpu_wr,
    output logic [7:0] cpu_data_rd,

    // sdram pins
    output logic [12:0] sdram_a,
    output logic [1:0] sdram_bs,
    output logic sdram_cs_n,
    output logic sdram_ras_n,
    output logic sdram_cas_n,
    output logic sdram_we_n,
    output logic [1:0] sdram_dqm,
    output logic sdram_cke,

    // sdram datra iopins
    input logic [15:0] sdram_din,
    output logic [15:0] sdram_dout,
    output logic sdram_dout_en
);

// sdram control words for sdram_cmd
localparam SDRAM_ACTIVATE           =   3'b011;
localparam SDRAM_PRECHARGE          =   3'b010; //A10: all vs bank
localparam SDRAM_WRITE              =   3'b100; //A10: auto precharge
localparam SDRAM_READ               =   3'b101; //A10: auto precharge
localparam SDRAM_MODE_SET           =   3'b000;
localparam SDRAM_NOP                =   3'b111;
localparam SDRAM_BURST_STOP         =   3'b110;
localparam SDRAM_AUTO_REFRESH       =   3'b001; //cke H->H
localparam SDRAM_SELF_REFRESH_ENTRY =   3'b001; //cke H->L
localparam SDRAM_SELF_REFRESH_EXIT  =   3'b110; //cke L->H
localparam SDRAM_ACTIVE_POWER_DOWN  =   3'b110; //cke H->L
localparam SDRAM_POWER_DOWN_EXIT    =   3'b110; //cke L->H

localparam STATE_BOOT       = 3'h0;
localparam STATE_PRECHARGE  = 3'h1;
localparam STATE_MODESET    = 3'h2;
localparam STATE_REFRESH    = 3'h3;
localparam STATE_MAIN       = 3'h4;
localparam STATE_ACTIVATE   = 3'h5;
localparam STATE_READ       = 3'h6;
localparam STATE_WRITE      = 3'h7;

localparam SDMODE_BURST1 = 3'h0;
localparam SDMODE_BURST2 = 3'h1;
localparam SDMODE_BURST4 = 3'h2;
localparam SDMODE_BURST8 = 3'h3;
localparam SDMODE_BURSTPAGE = 3'h7;
localparam SDMODE_SEQUENTIAL = 1'b0;
localparam SDMODE_INTERLEAVE = 1'b1;
localparam SDMODE_BURSTWRITE = 1'b0;
localparam SDMODE_SINGLEWRITE = 1'b0;
localparam CAS_LATENCY           = 3'h2;
localparam sdmode = {5'b0, SDMODE_SINGLEWRITE, 2'b0, CAS_LATENCY, SDMODE_SEQUENTIAL, SDMODE_BURST1};

logic [4:0] cycle; // 24 count cycles
wire tick = cycle == 5'd23; // trigger tick each time 24-cycle repeats
logic [9:0] ticks;
logic reset_ticks;
logic [3:0] state, state_next;
wire refresh_cycle = cycle==5'd21;

// ppu and cpu specific controller signals
logic [15:0] ppu_sdram_data_out, cpu_sdram_data_out;
logic ppu_sdram_data_out_en, cpu_sdram_data_out_en;
logic [12:0] ppu_sdram_a, cpu_sdram_a;
logic [2:0] sdram_cmd, ppu_sdram_cmd, cpu_sdram_cmd;
logic [1:0] ppu_sdram_dqm, cpu_sdram_dqm;
logic cpu_en, ppu_en;
assign {sdram_ras_n, sdram_cas_n, sdram_we_n} = sdram_cmd;

always_ff @(posedge clk)
begin
    if (rst) begin
        state <= STATE_BOOT;
        ticks <= 0;
        cycle <= 0;
    end else begin
            
        if (sync || tick) cycle <= 0;
        else cycle <= cycle + 1;

        if(reset_ticks) begin
            ticks <= 0;
        end
        else if(tick) ticks <= ticks+1;
    
        state <= state_next;
    end
end

logic test;
always @(*)
begin
    sdram_a = 13'b0;
    sdram_bs = 2'b0;
    sdram_cs_n = 1'b0;
    sdram_dqm = 2'b11;
    sdram_dout = 0;
    sdram_dout_en = 1'b0;
    sdram_cke = 1'b1;
    sdram_cmd = SDRAM_NOP;
    rdy = 0;
    state_next = state;
    reset_ticks = 0;
    cpu_en = 0;
    ppu_en = 0;
    test = 0;
    
    case(state)
        // boot sequence is:
        //      >200us of NOP
        //      precharge all
        //      set mode reg
        //      refresh 8x
        //      main loop
        STATE_BOOT: begin 
            // After power up, an initial pause of 200 μ S is required. To prevent data contention on the DQ bus 
            // during power up, it is required that the DQM and CKE pins be held high during the initial pause period.
            if (ticks == TICKS_STARTUP-1) begin
                reset_ticks = 1;
                state_next = STATE_PRECHARGE;
            end
        end
        STATE_PRECHARGE: begin 
            sdram_cmd = SDRAM_PRECHARGE;
            sdram_a[10] = 1;
            state_next = STATE_MODESET;
        end
        STATE_MODESET: begin
            sdram_cmd = SDRAM_MODE_SET;
            sdram_a = sdmode;
            sdram_bs = 2'b0;
            state_next = STATE_REFRESH;
            reset_ticks = 1;
        end
        STATE_REFRESH: begin
            if(refresh_cycle) sdram_cmd = SDRAM_AUTO_REFRESH;
            if (ticks == 8) begin
                // proceed to main loop afer 8 refresh cycles
                reset_ticks = 1;
                state_next = STATE_MAIN;
            end
        end
        STATE_MAIN: begin            
            rdy = 1;
            cpu_en = (cycle[4:3] == 0); // only enable cpu on 1st 8 cycles
            ppu_en = 1;
            if (cycle[0] == 0) begin
                // $display("ppu cycle %d time %t", cycle, $time);
                // ppu interleaved cycles

                sdram_dout = ppu_sdram_data_out;
                sdram_dout_en = ppu_sdram_data_out_en;
                sdram_a = ppu_sdram_a;
                sdram_cmd = ppu_sdram_cmd;
                sdram_dqm = ppu_sdram_dqm;
                sdram_bs = 2'h0;
            end else if (cpu_en && cycle[0]) begin
                // $display("cpu cycle %d time %t", cycle, $time);
                // cpu interleaved cycles (1/3 of time)

                sdram_dout = cpu_sdram_data_out;
                sdram_dout_en = cpu_sdram_data_out_en;
                sdram_a = cpu_sdram_a;
                sdram_cmd = cpu_sdram_cmd;
                sdram_dqm = cpu_sdram_dqm;
                sdram_bs = 2'h1;
            end else if (refresh_cycle && ticks==TICKS_REFRESH-1) begin
                // $display("refresh cycle %d time %t", cycle, $time);
                // refresh as needed 
                sdram_cmd = SDRAM_AUTO_REFRESH;                
                reset_ticks = 1;
            end
        end
        default: begin end
    endcase
end

sdram_interleavedbank_controller
#(  .BANK(0),
    .ADDR_DEPTH(ADDR_DEPTH),
    .COL_DEPTH(COL_DEPTH)
) u_ppu_controller (
    .clk(clk),
    .rst(rst),
    .en(ppu_en),
    .cycle(cycle[2:0]),
    .data_in(ppu_data_wr),
    .addr(ppu_addr),
    .rd(ppu_rd),
    .wr(ppu_wr),
    .data_out(ppu_data_rd),
    .sdram_data_in(sdram_din),
    .sdram_data_out(ppu_sdram_data_out),
    .sdram_data_out_en(ppu_sdram_data_out_en),
    .sdram_a(ppu_sdram_a),
    .sdram_cmd(ppu_sdram_cmd),
    .sdram_dqm(ppu_sdram_dqm)
    );

sdram_interleavedbank_controller
#( .BANK(1),
    .ADDR_DEPTH(ADDR_DEPTH),
    .COL_DEPTH(COL_DEPTH)
) u_cpu_controller (
    .clk(clk),
    .rst(rst),
    .en(cpu_en),
    .cycle(cycle[2:0]),
    .data_in(cpu_data_wr),
    .addr(cpu_addr),
    .rd(cpu_rd),
    .wr(cpu_wr),
    .data_out(cpu_data_rd),
    .sdram_data_in(sdram_din),
    .sdram_data_out(cpu_sdram_data_out),
    .sdram_data_out_en(cpu_sdram_data_out_en),
    .sdram_a(cpu_sdram_a),
    .sdram_cmd(cpu_sdram_cmd),
    .sdram_dqm(cpu_sdram_dqm)
    );


endmodule