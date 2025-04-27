
// arbitrate sdram access for two ports
// on simultaneous request, port A has priority
module sdram_arb
(
     input logic          clk_i
    ,input logic          rst_i

    ,input  logic [  3:0]  portA_wr_i
    ,input  logic          portA_rd_i
    ,input  logic [  7:0]  portA_len_i
    ,input  logic [ 31:0]  portA_addr_i
    ,input  logic [ 31:0]  portA_write_data_i
    ,output logic          portA_accept_o         // command accepted 
    ,output logic          portA_ack_o            // command completed
    ,output logic          portA_error_o
    ,output logic [ 31:0]  portA_read_data_o

    ,input  logic [  3:0]  portB_wr_i
    ,input  logic          portB_rd_i
    ,input  logic [  7:0]  portB_len_i
    ,input  logic [ 31:0]  portB_addr_i
    ,input  logic [ 31:0]  portB_write_data_i
    ,output logic          portB_accept_o
    ,output logic          portB_ack_o
    ,output logic          portB_error_o
    ,output logic [ 31:0]  portB_read_data_o

    ,output logic  [  3:0]  core_wr_o
    ,output logic           core_rd_o
    ,output logic  [  7:0]  core_len_o
    ,output logic  [ 31:0]  core_addr_o
    ,output logic  [ 31:0]  core_write_data_o
    ,input  logic           core_accept_i
    ,input  logic           core_ack_i
    ,input  logic           core_error_i
    ,input  logic [ 31:0]    core_read_data_i
);

wire reqA = portA_rd_i | (portA_wr_i != 0);
wire reqB = portB_rd_i | (portB_wr_i != 0);

// which port is currently using core
logic usingA;
logic usingB;
wire lockA = reqA & !usingB;
wire lockB = reqB & !(usingA | reqA);
wire ackA = usingA & core_ack_i;
wire ackB = usingB & core_ack_i;

always_ff @ (posedge clk_i)
if (rst_i) begin
    usingA   <= 0;
    usingB   <= 0;
end else begin
     // current transaction complete
    if (ackA) usingA <= 0;
    if (ackB) usingB <= 0;
    if (lockA) usingA <= 1;
    if (lockB) usingB <= 1;
end

always_comb begin
    portA_accept_o = 0;
    portA_ack_o = 0;
    portA_error_o = 0;
    portA_read_data_o = '0;

    portB_accept_o = 0;
    portB_ack_o = 0;
    portB_error_o = 0;
    portB_read_data_o = '0;

    core_wr_o = '0;
    core_rd_o = 0;
    core_len_o = '0;
    core_addr_o = '0;
    core_write_data_o = '0;

    // port -> core signals are assigned immediately on request
    if (lockA | (usingA & !ackA)) begin
        core_wr_o = portA_wr_i;
        core_rd_o = portA_rd_i;
        core_len_o = portA_len_i;
        core_addr_o = portA_addr_i;
        core_write_data_o = portA_write_data_i;
    end else if (lockB | (usingB & !ackB))  begin
        core_wr_o = portB_wr_i;
        core_rd_o = portB_rd_i;
        core_len_o = portB_len_i;
        core_addr_o = portB_addr_i;
        core_write_data_o = portB_write_data_i;
    end

    // core -> port signals are assigned through completion of transaction
    if (usingA) begin
        portA_accept_o = core_accept_i;
        portA_ack_o = core_ack_i;
        portA_error_o = core_error_i;
        portA_read_data_o = core_read_data_i;
    end else if (usingB)  begin
        portB_accept_o = core_accept_i;
        portB_ack_o = core_ack_i;
        portB_error_o = core_error_i;
        portB_read_data_o = core_read_data_i;
    end


end

endmodule
