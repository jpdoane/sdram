`timescale 1ns/1ps

module dual_master_sdram
#(
    parameter int ADDR_WIDTH=32,
    parameter int DATA_WIDTH=32,
    parameter int WORD_LEN=DATA_WIDTH/8
)
(
    input  wire logic    clk,
    input  wire logic    rst,

    // axi interface has priority
    taxi_axil_if.sub     axi_if,

    // port B initiates transaction when portB_en & portB_rdy are both high
    input  logic                   portB_en,            // request read or write
    input  logic[WORD_LEN-1:0]     portB_wr,            // write mask (read on 0)
    input  logic[ADDR_WIDTH-1:0]   portB_addr,
    input  logic[DATA_WIDTH-1:0]   portB_write_data,
    output logic[DATA_WIDTH-1:0]  portB_read_data,
    output logic                  portB_valid,
    output logic                  portB_rdy,

    // sdram controller interface
    output logic  [ WORD_LEN-1:0]       sdram_ctrl_wr,
    output logic                        sdram_ctrl_rd,
    output logic  [ ADDR_WIDTH-1:0]     sdram_ctrl_addr,
    output logic  [ DATA_WIDTH-1:0]     sdram_ctrl_write_data,
    input  logic                       sdram_ctrl_rdy,
    input  logic                       sdram_ctrl_rvalid,
    input  logic                       sdram_ctrl_wvalid,
    input  logic                       sdram_ctrl_error,
    input  logic [ DATA_WIDTH-1:0]     sdram_ctrl_read_data
);



assign axi_if.rresp = 2'b00;
assign axi_if.bresp = 2'b00;
assign axi_if.ruser = '0;
assign axi_if.buser = '0;

wire axi_rd_req = axi_if.arvalid;
wire axi_wr_req = axi_if.awvalid & axi_if.wvalid;
wire b_wr_req = portB_en & |portB_wr;
wire b_rd_req = portB_en & ~b_wr_req;

logic complete_axi_wr, complete_axi_rd, complete_b_wr, complete_b_rd;

// state machine
logic [2:0] state, state_next;
localparam STATE_IDLE   = 3'd0;
localparam STATE_AXI_RD = 3'd1;
localparam STATE_AXI_WR = 3'd2;
localparam STATE_B_RD   = 3'd3;
localparam STATE_B_WR   = 3'd4;

always_comb begin
    sdram_ctrl_wr = '0;
    sdram_ctrl_rd = 0;
    sdram_ctrl_addr = '0;
    sdram_ctrl_write_data = '0;
 
    complete_axi_wr = 1'b0;
    complete_axi_rd = 1'b0;
    complete_b_wr = 1'b0;
    complete_b_rd = 1'b0;

    axi_if.awready = 1'b0;
    axi_if.wready = 1'b0;
    axi_if.arready = 1'b0;

    portB_rdy = 0;
    state_next = state;

    unique case (state)
        STATE_IDLE: begin
            if (sdram_ctrl_rdy) begin
                priority case(1'b1)
                    axi_wr_req: begin
                        axi_if.awready = 1'b1;
                        axi_if.wready = 1'b1;
                        sdram_ctrl_addr = axi_if.awaddr[ADDR_WIDTH-1:0];
                        sdram_ctrl_write_data = axi_if.wdata[DATA_WIDTH-1:0];
                        sdram_ctrl_wr = axi_if.wstrb;
                        // $display("axi_wr_req");
                        state_next = STATE_AXI_WR;
                    end
                    axi_rd_req: begin
                        axi_if.arready = 1'b1;
                        sdram_ctrl_addr = axi_if.araddr[ADDR_WIDTH-1:0];
                        sdram_ctrl_rd = 1'b1;
                        // $display("axi_rd_req");
                        state_next = STATE_AXI_RD;
                    end
                    b_wr_req: begin
                        portB_rdy = 1;
                        sdram_ctrl_addr =portB_addr;
                        sdram_ctrl_write_data = portB_write_data;
                        sdram_ctrl_wr = portB_wr;
                        // $display("b_wr_req");
                        state_next = STATE_B_WR;
                    end
                    b_rd_req: begin
                        portB_rdy = 1;
                        sdram_ctrl_addr = portB_addr;
                        sdram_ctrl_rd = 1'b1;
                        // $display("b_rd_req");
                        state_next = STATE_B_RD;
                    end
                    default: state_next = STATE_IDLE;
                endcase
            end
            // $display("IDLE");
        end
        STATE_AXI_RD: begin
            if(sdram_ctrl_rvalid) begin
                complete_axi_rd = 1;
                state_next = STATE_IDLE;
                // $display("complete_axi_rd");
            end
        end
        STATE_AXI_WR: begin
            if(sdram_ctrl_wvalid) begin
                complete_axi_wr = 1;
                state_next = STATE_IDLE;
                // $display("complete_axi_wr");
            end
        end
        STATE_B_RD: begin
            if(sdram_ctrl_rvalid) begin
                complete_b_rd = 1;
                state_next = STATE_IDLE;
                // $display("complete_b_rd");
            end
        end
        STATE_B_WR: begin
            if(sdram_ctrl_wvalid) begin
                complete_b_wr = 1;
                // $display("complete_b_wr");
                state_next = STATE_IDLE;
            end
        end
    endcase
end

always_ff @(posedge clk) begin
    state <= state_next;
    if (rst) begin
        state <= STATE_IDLE;
    end        
end


// complete axi transactions
logic axi_bvalid, axi_rvalid;
logic [DATA_WIDTH-1:0] axi_rdata;
always_ff @(posedge clk) begin
    if (complete_axi_rd) begin
        axi_rdata[DATA_WIDTH-1:0] <= sdram_ctrl_read_data;
        axi_rvalid <= 1'b1;
    end
    else if(axi_rvalid && axi_if.rready) begin
        axi_rdata <= '0;
        axi_rvalid <= 1'b0;
    end
    if (rst) begin
        axi_rdata <=  '0;
        axi_rvalid <= 1'b0;
    end
end
assign axi_if.rdata = axi_rdata;
assign axi_if.rvalid = axi_rvalid;

always_ff @(posedge clk) begin
    if (complete_axi_wr) begin
        axi_bvalid <= 1'b1;
    end
    else if(axi_bvalid && axi_if.bready) begin
        axi_bvalid <= 1'b0;
    end
    if (rst) begin
        axi_bvalid <= 1'b0;
    end
end
assign axi_if.bvalid = axi_bvalid;

// complete port B transactions
always_ff @(posedge clk) begin
    if (complete_b_rd || complete_b_wr) begin
        portB_read_data[DATA_WIDTH-1:0] <= sdram_ctrl_read_data;
        portB_valid <= 1;
    end
    else if(b_rd_req || b_wr_req) begin
        portB_valid <= 1'b0;
    end
    if (rst) begin
        portB_read_data[DATA_WIDTH-1:0] <= 0;
        portB_valid <= 0;
    end
end


endmodule
