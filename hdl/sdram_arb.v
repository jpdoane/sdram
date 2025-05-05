
// arbitrate sdram access for two ports
// on simultaneous request, port A has priority
module sdram_arb
(
    input logic          clk,
    input logic          rst,
    sdram_core_if.man core_if,
    sdram_core_if.sub portA_if,
    sdram_core_if.sub portB_if
);


// which port has active request (portA has priority on tie)
logic usingA;
logic usingB;
wire reqA = (portA_if.rd | (portA_if.wr != 0)) & !usingB;
wire reqB = (portB_if.rd | (portB_if.wr != 0)) & !reqA;

// which port is currently using core
logic acceptA;
logic acceptB;

always_ff @ (posedge clk)
if (rst) begin
    usingA <= 0;
    usingB <= 0;
    acceptA <= 0;
    acceptB <= 0;
end else begin
    if (core_if.accept | core_if.error) begin
        usingA <= 0;
        usingB <= 0;
    end
    usingA <= reqA;
    usingB <= reqB;
end

// port -> core signals are assigned immediately on request
always_comb begin
    core_if.wr = '0;
    core_if.rd = 0;
    core_if.addr = '0;
    core_if.write_data = '0;

    // portA_if.accept = 0;
    // portB_if.accept = 0;

    if (reqA) begin
        core_if.wr = portA_if.wr;
        core_if.rd = portA_if.rd;
        core_if.addr = portA_if.addr;
        core_if.write_data = portA_if.write_data;
    end
    if (reqB)  begin
        core_if.wr = portB_if.wr;
        core_if.rd = portB_if.rd;
        core_if.addr = portB_if.addr;
        core_if.write_data = portB_if.write_data;

        // portB_if.accept = core_if.accept;
    end
end

// core -> port signals are assigned through completion of transaction
always_comb begin
    portA_if.accept = 0;
    portA_if.ack = 0;
    portA_if.error = 0;
    portA_if.read_data = '0;

    portB_if.accept = 0;
    portB_if.ack = 0;
    portB_if.error = 0;
    portB_if.read_data = '0;
    if (usingA) begin
        portA_if.accept = core_if.accept;
        portA_if.ack = core_if.ack;
        portA_if.error = core_if.error;
        portA_if.read_data = core_if.read_data;
    end
    if (usingB)  begin
        portB_if.accept = core_if.accept;
        portB_if.ack = core_if.ack;
        portB_if.error = core_if.error;
        portB_if.read_data = core_if.read_data;
    end
end

endmodule
