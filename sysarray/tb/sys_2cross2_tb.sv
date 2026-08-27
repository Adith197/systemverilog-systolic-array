module sys_2cross2_tb;

    logic clk;
    logic rst;
    logic clear;
    logic [7:0] a0_in;
    logic [7:0] a1_in;
    logic [7:0] b0_in;
    logic [7:0] b1_in;
    logic valid_a0;
    logic valid_a1;
    logic valid_b0;
    logic valid_b1;
    logic [31:0] acc00;
    logic [31:0] acc01;
    logic [31:0] acc10;
    logic [31:0] acc11;

    sys_2cross2 dut(
        .clk(clk),
        .rst(rst),
        .clear(clear),
        .a0_in(a0_in),
        .a1_in(a1_in),
        .b0_in(b0_in),
        .b1_in(b1_in),
        .valid_a0(valid_a0),
        .valid_a1(valid_a1),
        .valid_b0(valid_b0),
        .valid_b1(valid_b1),
        .acc00(acc00),
        .acc01(acc01),
        .acc10(acc10),
        .acc11(acc11)
    );
    initial begin
        $dumpfile("sys_2cross2.vcd");
        $dumpvars(0,sys_2cross2_tb);
    end
    initial begin
        clk = 1'b0;
        forever begin
            #5 clk = ~clk;
        end
    end
    initial begin
        rst = 1'b1;
        a0_in = 8'd0;
        a1_in = 8'd0;
        b0_in = 8'd0;
        b1_in = 8'd0;
        clear = 1'b0;
        valid_a0 = 1'b0;
        valid_a1 = 1'b0;
        valid_b0 = 1'b0;
        valid_b1 = 1'b0;
        repeat (2) @(posedge clk);
        rst = 1'b0;
        @(negedge clk)
        a0_in = 8'd1;
        valid_a0 = 1'b1;
        b0_in = 8'd5;
        valid_b0=1'b1;
        @(negedge clk)
        a0_in = 8'd2;
        valid_a0 = 1'b1;
        b0_in = 8'd7;
        valid_b0 = 1'b1;
        a1_in = 8'd3;
        valid_a1 = 1'b1;
        b1_in = 8'd6;
        valid_b1 = 1'b1;
        @(negedge clk)
        a0_in = 8'd0;
        valid_a0 = 1'b0;
        a1_in = 8'd4;
        valid_a1 = 1'b1;
        b0_in = 8'd0;
        valid_b0 = 1'b0;
        b1_in = 8'd8;
        valid_b1 = 1'b1;
        @(negedge clk);
        a0_in = 8'd0;
        a1_in = 8'd0;
        b0_in = 8'd0;
        b1_in = 8'd0;
        valid_a0 = 1'b0;
        valid_a1 = 1'b0;
        valid_b0 = 1'b0;
        valid_b1 = 1'b0;
        repeat (2) @(posedge clk);
        $finish;
    end
initial begin
    forever begin
        @(posedge clk);
        $strobe("TIME=%0t | A0=%0d V=%0b | A1=%0d V=%0b | B0=%0d V=%0b | B1=%0d V=%0b | ACC00=%0d | ACC01=%0d | ACC10=%0d | ACC11=%0d",$time,a0_in, valid_a0,a1_in, valid_a1,b0_in, valid_b0,b1_in, valid_b1,acc00,acc01,acc10,acc11);
    end
end

endmodule;
