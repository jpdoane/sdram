`timescale 1ns/1ps

module dual_master_sdram #(
    parameter int ADDR_WIDTH = 25,
    parameter int DATA_WIDTH = 32,
    parameter int WORD_LEN   = DATA_WIDTH/8
)(
    input  logic clk,
    input  logic rst,

    // AXI-Lite subordinate port (has priority over port B)
    input  logic [ADDR_WIDTH-1:0]   axil_awaddr,
    input  logic                    axil_awvalid,
    output logic                    axil_awready,
    input  logic [DATA_WIDTH-1:0]   axil_wdata,
    input  logic [WORD_LEN-1:0]     axil_wstrb,
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

    // Port B: synchronous CPU port, clocked by gated clock = clk & portB_en
    // portB_rdy is set low when SDRAM busy and should stall CPU
    // portB_read_data is valid and sampled on the next cpu clock after read request
    input  logic                    portB_en,
    input  logic [WORD_LEN-1:0]     portB_wr,
    input  logic [ADDR_WIDTH-1:0]   portB_addr,
    input  logic [DATA_WIDTH-1:0]   portB_write_data,
    output logic [DATA_WIDTH-1:0]   portB_read_data,
    output logic                    portB_rdy,

    // SDRAM controller interface
    output logic [WORD_LEN-1:0]     sdram_ctrl_wr,
    output logic                    sdram_ctrl_rd,
    output logic [ADDR_WIDTH-1:0]   sdram_ctrl_addr,
    output logic [DATA_WIDTH-1:0]   sdram_ctrl_write_data,
    input  logic                    sdram_ctrl_rdy,
    input  logic                    sdram_ctrl_rvalid,
    input  logic                    sdram_ctrl_wvalid,
    input  logic                    sdram_ctrl_error,
    input  logic [DATA_WIDTH-1:0]   sdram_ctrl_read_data
);

assign axil_rresp = 2'b00;
assign axil_bresp = 2'b00;

wire axi_rd_req = axil_arvalid;
wire axi_wr_req = axil_awvalid & axil_wvalid;
wire b_wr_req   = portB_en & |portB_wr;
wire b_rd_req   = portB_en & ~b_wr_req;

logic complete_axi_wr, complete_axi_rd, complete_b_wr, complete_b_rd;

// Arbitration state machine
logic [2:0] state, state_next;
localparam STATE_IDLE   = 3'd0;
localparam STATE_AXI_RD = 3'd1;
localparam STATE_AXI_WR = 3'd2;
localparam STATE_B_RD   = 3'd3;
localparam STATE_B_WR   = 3'd4;

always_comb begin
    sdram_ctrl_wr         = '0;
    sdram_ctrl_rd         = 0;
    sdram_ctrl_addr       = '0;
    sdram_ctrl_write_data = '0;

    complete_axi_wr = 1'b0;
    complete_axi_rd = 1'b0;
    complete_b_wr   = 1'b0;
    complete_b_rd   = 1'b0;

    axil_awready = 1'b0;
    axil_wready  = 1'b0;
    axil_arready = 1'b0;

    // portB_rdy: asserted only when the controller can genuinely service
    // a portB transaction this cycle (IDLE + SDRAM ready + AXI not winning).
    portB_rdy  = 0;
    state_next = state;

    unique case (state)
        STATE_IDLE: begin
            if (sdram_ctrl_rdy) begin
                priority case (1'b1)
                    axi_wr_req: begin
                        // AXI wins arbitration; portB_rdy stays 0
                        axil_awready          = 1'b1;
                        axil_wready           = 1'b1;
                        sdram_ctrl_addr       = axil_awaddr[ADDR_WIDTH-1:0];
                        sdram_ctrl_write_data = axil_wdata[DATA_WIDTH-1:0];
                        sdram_ctrl_wr         = axil_wstrb;
                        state_next            = STATE_AXI_WR;
                    end
                    axi_rd_req: begin
                        // AXI wins arbitration; portB_rdy stays 0
                        axil_arready    = 1'b1;
                        sdram_ctrl_addr = axil_araddr[ADDR_WIDTH-1:0];
                        sdram_ctrl_rd   = 1'b1;
                        state_next      = STATE_AXI_RD;
                    end
                    portB_en: begin
                        // portB transaction accepted
                        portB_rdy             = 1;
                        sdram_ctrl_addr       = portB_addr;
                        if (portB_wr==0) begin
                            // read
                            sdram_ctrl_rd   = 1'b1;
                            state_next      = STATE_B_RD;
                        end else begin
                            // write
                            sdram_ctrl_wr         = portB_wr;
                            sdram_ctrl_write_data = portB_write_data;
                            state_next            = STATE_B_WR;
                        end
                    end
                    default: begin
                        // IDLE, SDRAM ready, no requests
                        portB_rdy = 1;
                    end
                endcase
            end
        end
        STATE_AXI_RD: begin
            if (sdram_ctrl_rvalid) begin
                complete_axi_rd = 1;
                state_next      = STATE_IDLE;
            end
        end
        STATE_AXI_WR: begin
            if (sdram_ctrl_wvalid) begin
                complete_axi_wr = 1;
                state_next      = STATE_IDLE;
            end
        end
        STATE_B_RD: begin
            if (sdram_ctrl_rvalid) begin
                complete_b_rd = 1;
                state_next    = STATE_IDLE;
            end
        end
        STATE_B_WR: begin
            if (sdram_ctrl_wvalid) begin
                complete_b_wr = 1;
                state_next    = STATE_IDLE;
            end
        end
    endcase
end

always_ff @(posedge clk) begin
    state <= state_next;
    if (rst) state <= STATE_IDLE;
end

// AXI read response
logic axi_bvalid_r, axi_rvalid_r;
logic [DATA_WIDTH-1:0] axi_rdata_r;

always_ff @(posedge clk) begin
    if (complete_axi_rd) begin
        axi_rdata_r  <= sdram_ctrl_read_data;
        axi_rvalid_r <= 1'b1;
    end else if (axi_rvalid_r && axil_rready) begin
        axi_rdata_r  <= '0;
        axi_rvalid_r <= 1'b0;
    end
    if (rst) begin
        axi_rdata_r  <= '0;
        axi_rvalid_r <= 1'b0;
    end
end
assign axil_rdata  = axi_rdata_r;
assign axil_rvalid = axi_rvalid_r;

// AXI write response
always_ff @(posedge clk) begin
    if (complete_axi_wr)
        axi_bvalid_r <= 1'b1;
    else if (axi_bvalid_r && axil_bready)
        axi_bvalid_r <= 1'b0;
    if (rst) axi_bvalid_r <= 1'b0;
end
assign axil_bvalid = axi_bvalid_r;

// Port B read data latch
always_ff @(posedge clk) begin
    if (complete_b_rd)
        portB_read_data <= sdram_ctrl_read_data;
    if (rst)
        portB_read_data <= '0;
end

endmodule
