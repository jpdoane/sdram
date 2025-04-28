interface sdram_core_if
#(
    parameter ADDR_WIDTH=32,
    parameter DATA_WIDTH=32
)
(   input          clk );
    logic  [  3:0]  wr;
    logic           rd;
    logic  [  7:0]  len;
    logic  [ ADDR_WIDTH-1:0]  addr;
    logic  [ DATA_WIDTH-1:0]  write_data;
    logic           accept;
    logic           ack;
    logic           error;
    logic [ DATA_WIDTH-1:0]   read_data;


    modport man (input  accept, ack, error, read_data, clk,
                    output wr, rd, len, addr, write_data);

    modport sub (input wr, rd, len, addr, write_data, clk,
                 output accept, ack, error, read_data);

    // This throws mutliple driver error...
    // honestly not sure how tasks+interfaces are support to work...
    //
    // task write(
    //     input logic  [ ADDR_WIDTH-1:0]  a,
    //     input logic  [ DATA_WIDTH-1:0]  data
    //     );
    
    //     addr <= a;
    //     write_data <= data;
    //     wr <= '1;
    //     @(posedge clk);
    //     // hold inputs until accepted
    //     while(~accept) @(posedge clk);
    //     wr <= 0;
    //     write_data <= 0;
    // endtask

    // task read(
    //     input logic  [ ADDR_WIDTH-1:0]  a,
    //     output logic  [ DATA_WIDTH-1:0]  data
    //     );
    
    //     addr <= a;
    //     rd <= 1;
    //     @(posedge clk);
    //     // hold inputs until accepted
    //     while(~accept) @(posedge clk); 
    //     rd <= 0;
    //     // hold until data is ready 
    //     while(~ack) @(posedge clk); 
    //     data <= read_data;
    // endtask
    
endinterface

interface sdram_part_if
#(
    parameter ADDR_WIDTH=13,
    parameter COL_WIDTH=9,
    parameter DATA_WIDTH=16
)
(   input                  clk );

    logic                  cke;
    logic                  cs;
    logic                  ras;
    logic                  cas;
    logic                  we;
    logic [ 1:0]           dqm;
    logic [ADDR_WIDTH-1:0] addr;
    logic [ 1:0]           ba;
    logic [DATA_WIDTH-1:0] read_data;
    logic [DATA_WIDTH-1:0] write_data;
    logic                   wr_en;

    modport man (input read_data, clk,
                 output cke, cs, ras, cas, we, dqm, addr, ba, write_data, wr_en);
  
    modport sub (input cke, cs, ras, cas, we, dqm, addr, ba, write_data, wr_en, clk,
                 output read_data);
endinterface

