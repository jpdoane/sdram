
// arbitrate sdram access for two ports
// on simultaneous request, port A has priority
module sdram_arb
(
    input logic          clk,
    input logic          rst,
    sdram_ctrl_if.man ctrl_if,
    sdram_ctrl_if.sub portA_if,
    sdram_ctrl_if.sub portB_if
);

// which port has active request (portA has priority on tie)
wire reqA = (portA_if.rd | (portA_if.wr != 0));
wire reqB = (portB_if.rd | (portB_if.wr != 0));
wire rdyA = ctrl_if.rdy;
wire rdyB = ctrl_if.rdy & !reqA;

logic usingA;
logic usingB;
always_ff @ (posedge clk)
if (rst) begin
    usingA <= 0;
    usingB <= 0;
end else begin
    if (ctrl_if.rvalid | ctrl_if.wvalid | ctrl_if.error) begin
        usingA <= 0;
        usingB <= 0;
    end
    if (reqA & rdyA) usingA <= 1'b1;
    else if (reqB & rdyB) usingB <= 1'b1;
end

always_comb begin
    ctrl_if.wr = '0;
    ctrl_if.rd = 0;
    ctrl_if.addr = '0;
    ctrl_if.write_data = '0;

    if (reqA) begin
        ctrl_if.wr = portA_if.wr;
        ctrl_if.rd = portA_if.rd;
        ctrl_if.addr = portA_if.addr;
        ctrl_if.write_data = portA_if.write_data;
    end
    else if (reqB)  begin
        ctrl_if.wr = portB_if.wr;
        ctrl_if.rd = portB_if.rd;
        ctrl_if.addr = portB_if.addr;
        ctrl_if.write_data = portB_if.write_data;
    end
end

always_comb begin
    portA_if.rdy = rdyA;
    portA_if.error = ctrl_if.error;

    if (usingA) begin
        portA_if.rvalid = ctrl_if.rvalid;
        portA_if.wvalid = ctrl_if.wvalid;
        portA_if.read_data = ctrl_if.read_data;
    end else begin
        portA_if.rvalid = 0;
        portA_if.wvalid = 0;
        portA_if.read_data = '0;
    end
end

always_comb begin
    portB_if.rdy = rdyB;
    portB_if.error = ctrl_if.error;

    if (usingB) begin
        portB_if.rvalid = ctrl_if.rvalid;
        portB_if.wvalid = ctrl_if.wvalid;
        portB_if.read_data = ctrl_if.read_data;
    end else begin
        portB_if.rvalid = 0;
        portB_if.wvalid = 0;
        portB_if.read_data = '0;
    end
end


endmodule
