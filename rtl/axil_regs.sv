`timescale 1ns/1ps

// axil_regs.sv
//
// AXI-Lite subordinate providing read/write access to 16 x 32-bit registers.
//
// Address map (byte addresses, 4-byte aligned):
//   0x00  reg[0]
//   0x04  reg[1]
//   ...
//   0x3C  reg[15]
//
// Writes: accepted in a single cycle when both awvalid and wvalid are
//         asserted (simple subordinate -- does not support split AW/W).
// Reads:  registered one cycle after arvalid; rvalid asserts the next cycle.
// Out-of-range addresses return 0 on read and are silently ignored on write.

module axil_regs #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int N_REGS     = 16
)(
    input  logic                    clk,
    input  logic                    rst,

    // AXI-Lite subordinate port
    input  logic [ADDR_WIDTH-1:0]   axil_awaddr,
    input  logic                    axil_awvalid,
    output logic                    axil_awready,

    input  logic [DATA_WIDTH-1:0]   axil_wdata,
    input  logic [DATA_WIDTH/8-1:0] axil_wstrb,
    input  logic                    axil_wvalid,
    output logic                    axil_wready,

    output logic [1:0]              axil_bresp,
    output logic                    axil_bvalid,
    input  logic                    axil_bready,

    input  logic [ADDR_WIDTH-1:0]   axil_araddr,
    input  logic                    axil_arvalid,
    output logic                    axil_arready,

    output logic [DATA_WIDTH-1:0]   axil_rdata,
    output logic [1:0]              axil_rresp,
    output logic                    axil_rvalid,
    input  logic                    axil_rready,

    // Register file (readable/writable from the application side)
    output logic [DATA_WIDTH-1:0]   regs [N_REGS]
);

    localparam int STRB_W    = DATA_WIDTH / 8;
    localparam int IDX_BITS  = $clog2(N_REGS);
    // Upper address bits above the register index must be zero for a valid access
    localparam int UPPER_W   = ADDR_WIDTH - IDX_BITS - 2;  // -2 for byte offset

    // -----------------------------------------------------------------------
    // Write path
    // -----------------------------------------------------------------------

    // Accept write when both address and data are valid simultaneously.
    wire wr_en = axil_awvalid & axil_wvalid;

    assign axil_awready = wr_en;
    assign axil_wready  = wr_en;
    assign axil_bresp   = 2'b00;  // OKAY

    always_ff @(posedge clk) begin
        if (rst) begin
            axil_bvalid <= 1'b0;
            for (int i = 0; i < N_REGS; i++)
                regs[i] <= '0;
        end else begin
            // Write response handshake
            if (axil_bvalid && axil_bready)
                axil_bvalid <= 1'b0;

            // Register write with byte-strobe
            if (wr_en) begin
                axil_bvalid <= 1'b1;
                // Valid if upper address bits are all zero (in-range access)
                if (axil_awaddr[ADDR_WIDTH-1 -: UPPER_W] == '0) begin
                    for (int b = 0; b < STRB_W; b++) begin
                        if (axil_wstrb[b])
                            regs[axil_awaddr[IDX_BITS+1:2]][b*8 +: 8] <= axil_wdata[b*8 +: 8];
                    end
                end
            end
        end
    end

    // -----------------------------------------------------------------------
    // Read path
    // -----------------------------------------------------------------------

    assign axil_arready = 1'b1;   // always ready to accept a read address
    assign axil_rresp   = 2'b00;  // OKAY

    always_ff @(posedge clk) begin
        if (rst) begin
            axil_rvalid <= 1'b0;
            axil_rdata  <= '0;
        end else begin
            if (axil_rvalid && axil_rready)
                axil_rvalid <= 1'b0;

            if (axil_arvalid && (!axil_rvalid || axil_rready)) begin
                axil_rvalid <= 1'b1;
                if (axil_araddr[ADDR_WIDTH-1 -: UPPER_W] == '0)
                    axil_rdata <= regs[axil_araddr[IDX_BITS+1:2]];
                else
                    axil_rdata <= '0;
            end
        end
    end

endmodule
