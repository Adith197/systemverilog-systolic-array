`timescale 1ns/1ps

module sys_systolic_controller_tb;

    parameter int N = 4;

    logic clk;
    logic rst;
    logic start;

    logic [$clog2(2*N+1)-1:0] cycle;

    logic valid_a [N];
    logic valid_b [N];

    logic busy;
    logic done;


    sys_systolic_controller #(
        .N(N)
    ) dut (
        .clk(clk),
        .rst(rst),
        .start(start),

        .cycle(cycle),

        .valid_a(valid_a),
        .valid_b(valid_b),

        .busy(busy),
        .done(done)
    );


    always #5 clk = ~clk;


    initial begin

        $dumpfile("sys_systolic_controller.vcd");
        $dumpvars(0, sys_systolic_controller_tb);

    end


    initial begin

        clk   = 1'b0;
        rst   = 1'b1;
        start = 1'b0;

        #20;

        rst = 1'b0;

        @(negedge clk);
        start = 1'b1;

        @(negedge clk);
        start = 1'b0;

    end


    always @(posedge clk) begin

        $write("TIME=%0t | CYCLE=%0d | BUSY=%b DONE=%b | VA=",
               $time, cycle, busy, done);

        for (int i = 0; i < N; i++)
            $write("%b", valid_a[i]);

        $write(" VB=");

        for (int i = 0; i < N; i++)
            $write("%b", valid_b[i]);

        $display("");

    end


    always @(posedge clk) begin

        if (done) begin
            $display("Controller DONE at TIME=%0t", $time);
            #10;
            $finish;
        end

    end

endmodule