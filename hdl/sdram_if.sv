interface sdram_ctrl_if
#(
    parameter int ADDR_WIDTH=32,
    parameter int DATA_WIDTH=32,
    parameter int WORD_LEN=DATA_WIDTH/8
)
();
    logic  [ WORD_LEN-1:0]  wr;
    logic           rd;
    logic  [ ADDR_WIDTH-1:0]  addr;
    logic  [ DATA_WIDTH-1:0]  write_data;
    logic           rdy;
    logic           rvalid;
    logic           wvalid;
    logic           error;
    logic [ DATA_WIDTH-1:0]   read_data;


    modport man (input  rdy, rvalid, wvalid, error, read_data,
                    output wr, rd, addr, write_data);

    modport sub (input wr, rd, addr, write_data,
                 output rdy, rvalid, wvalid, error, read_data);

    task write(
        ref logic  clk,
        input logic  [ ADDR_WIDTH-1:0]  a,
        input logic  [ DATA_WIDTH-1:0]  data
        );
    
        addr <= a;
        write_data <= data;
        wr <= '1;
        while(~rdy) @(posedge clk);
        wr <= 0;
        write_data <= 0;
        while(~wvalid) @(posedge clk);
    endtask

    task read(
        ref logic  clk,
        input logic  [ ADDR_WIDTH-1:0]  a,
        output logic  [ DATA_WIDTH-1:0]  data
        );
    
        addr <= a;
        rd <= 1;
        while(~rdy) @(posedge clk);
        rd <= 0;
        while(~rvalid) @(posedge clk);
        data = read_data;
    endtask
    
endinterface

interface sdram_dev_if
#(
    parameter ADDR_WIDTH=24,
    parameter COL_WIDTH=9,
    parameter ROW_WIDTH=ADDR_WIDTH-COL_WIDTH-3
)
();

    logic                   cke;
    logic                   cs;
    logic                   ras;
    logic                   cas;
    logic                   we;
    logic [ 1:0]            dqm;
    logic [ROW_WIDTH-1:0]   addr;
    logic [ 1:0]            ba;
    logic [15:0]            read_data;
    logic [15:0]            write_data;
    logic                   wr_en;

    modport man (input read_data,
                 output cke, cs, ras, cas, we, dqm, addr, ba, write_data, wr_en);
  
    modport sub (input cke, cs, ras, cas, we, dqm, addr, ba, write_data, wr_en, 
                 output read_data);
endinterface

