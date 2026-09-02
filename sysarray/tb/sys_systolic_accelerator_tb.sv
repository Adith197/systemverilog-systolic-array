`timescale 1ns/1ps

module sys_systolic_accelerator_tb;
    parameter int N = 4;
    localparam int CYCLE_W = $clog2(2*N+1);
    logic clk;
    logic rst;
    logic start;
    logic clear;
    logic [7:0] A [N][N];
    logic [7:0] B [N][N];
    logic busy;
    logic done;
    logic [31:0] C [N][N];
    sys_systolic_accelerator #(.N(N)) dut (
        .clk(clk),
        .rst(rst),
        .start(start),
        .clear(clear),
        .A(A),
        .B(B),
        .busy(busy),
        .done(done),
        .acc_final(C)
    );
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end
    initial begin
    A[0][0] = 8'd1;
    A[0][1] = 8'd2;
    A[0][2] = 8'd3;
    A[0][3] = 8'd4;
    A[1][0] = 8'd5;
    A[1][1] = 8'd6;
    A[1][2] = 8'd7;
    A[1][3] = 8'd8;
    A[2][0] = 8'd9;
    A[2][1] = 8'd10;
    A[2][2] = 8'd11;
    A[2][3] = 8'd12;
    A[3][0] = 8'd13;
    A[3][1] = 8'd14;
    A[3][2] = 8'd15;
    A[3][3] = 8'd16;
    B[0][0] = 8'd17;
    B[0][1] = 8'd18;
    B[0][2] = 8'd19;
    B[0][3] = 8'd20;
    B[1][0] = 8'd21;
    B[1][1] = 8'd22;
    B[1][2] = 8'd23;
    B[1][3] = 8'd24;
    B[2][0] = 8'd25;
    B[2][1] = 8'd26;
    B[2][2] = 8'd27;
    B[2][3] = 8'd28;
    B[3][0] = 8'd29;
    B[3][1] = 8'd30;
    B[3][2] = 8'd31;
    B[3][3] = 8'd32;
    end
    initial begin
        rst   = 1'b1;
        start = 1'b0;
        clear = 1'b1;
        #20;
        rst   = 1'b0;
        clear = 1'b0;
        #10;
        start = 1'b1;
        #10;
        start = 1'b0;
        wait(done);
        #1;
        $display("");
        $display("================================");
        $display(" MATRIX MULTIPLICATION RESULT");
        $display("================================");
        for (int i = 0; i < N; i++) begin
            for (int j = 0; j < N; j++) begin
                $write("C[%0d][%0d] = %0d    ",
                       i, j, C[i][j]);
            end
            $display("");
        end
        $display("================================");
        #10;
        $finish;
    end
endmodule
