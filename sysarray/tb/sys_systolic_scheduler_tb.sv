`timescale 1ns/1ps
module sys_systolic_scheduler_tb;
    parameter int N = 2;
    localparam int CYCLE_W = $clog2(2*N+1);
    localparam int LAST_CYCLE = 2*N-2;
    logic [CYCLE_W-1:0] cycle;
    logic [7:0] A [N][N];
    logic [7:0] B [N][N];
    logic [7:0] a_out [N];
    logic [7:0] b_out [N];
    sys_systolic_scheduler #(
        .N(N)
    ) dut (
        .cycle(cycle),
        .A(A),
        .B(B),
        .a_out(a_out),
        .b_out(b_out)
    );
    initial begin
    // A matrix
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


    // B matrix
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
    cycle = '0;
    end
initial begin

    #10;

    for (int c = 0; c <= LAST_CYCLE; c++) begin
        cycle = CYCLE_W'(c);
        #1;

        $write("CYCLE=%0d | A_OUT=", cycle);

        for (int i = 0; i < N; i++)
            $write("%0d ", a_out[i]);

        $write("| B_OUT=");

        for (int i = 0; i < N; i++)
            $write("%0d ", b_out[i]);

        $display("");

        #9;
    end

    $finish;

end
endmodule
