`timescale 1ns/1ps

module PE_sysarray_tb;
    parameter int N = 2;
    logic clk;
    logic rst;
    logic clear;
    logic [7:0] a_in [N];
    logic [7:0] b_in [N];
    logic a_valid_in [N];
    logic b_valid_in [N];
    logic [31:0] acc [N][N];
    PE_sysarray #(
        .N(N)
    ) dut (
        .clk(clk),
        .rst(rst),
        .clear(clear),
        .a_in(a_in),
        .b_in(b_in),
        .a_valid_in(a_valid_in),
        .b_valid_in(b_valid_in),
        .acc(acc)
    );
    always #5 clk = ~clk;
    initial begin
        $dumpfile("PE_sysarray.vcd");
        $dumpvars(0, PE_sysarray_tb);
        clk = 1'b0;
        rst = 1'b1;
        clear = 1'b1;
        for (int i = 0; i < N; i++) begin
            a_in[i] = 8'd0;
            b_in[i] = 8'd0;
            a_valid_in[i] = 1'b0;
            b_valid_in[i] = 1'b0;
        end
        #20;
        rst = 1'b0;
        clear = 1'b0;
        @(negedge clk);
        a_in[0] = 8'd1;
        a_in[1] = 8'd0;
        b_in[0] = 8'd5;
        b_in[1] = 8'd0;
        a_valid_in[0] = 1'b1;
        a_valid_in[1] = 1'b0;
        b_valid_in[0] = 1'b1;
        b_valid_in[1] = 1'b0;
        @(negedge clk);
        a_in[0] = 8'd2;
        a_in[1] = 8'd3;
        b_in[0] = 8'd7;
        b_in[1] = 8'd6;
        a_valid_in[0] = 1'b1;
        a_valid_in[1] = 1'b1;
        b_valid_in[0] = 1'b1;
        b_valid_in[1] = 1'b1;
        @(negedge clk);
        a_in[0] = 8'd0;
        a_in[1] = 8'd4;
        b_in[0] = 8'd0;
        b_in[1] = 8'd8;
        a_valid_in[0] = 1'b0;
        a_valid_in[1] = 1'b1;
        b_valid_in[0] = 1'b0;
        b_valid_in[1] = 1'b1;
        @(negedge clk);
        for (int i = 0; i < N; i++) begin
            a_in[i] = 8'd0;
            b_in[i] = 8'd0;
            a_valid_in[i] = 1'b0;
            b_valid_in[i] = 1'b0;
        end
        repeat (5)
            @(posedge clk);
        $display("ACC00 = %0d", acc[0][0]);
        $display("ACC01 = %0d", acc[0][1]);
        $display("ACC10 = %0d", acc[1][0]);
        $display("ACC11 = %0d", acc[1][1]);
        $finish;
    end
endmodule