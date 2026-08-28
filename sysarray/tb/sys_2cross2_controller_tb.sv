module sys_2cross2_controller_tb;
    logic clk;
    logic rst;
    logic start;
    logic valid_a0;
    logic valid_a1;
    logic valid_b0;
    logic valid_b1;
    logic busy;
    logic done;

    sys_2cross2_controller dut(
        .clk(clk),
        .rst(rst),
        .start(start),
        .valid_a0(valid_a0),
        .valid_a1(valid_a1),
        .valid_b0(valid_b0),
        .valid_b1(valid_b1),
        .busy(busy),
        .done(done)
    );
    initial begin
        $dumpfile("sys_2cross2.vcd");
        $dumpvars(0,sys_2cross2_controller);
    end
    initial begin
        clk = 1'b0;
        forever begin
            #5 clk = ~clk;
        end
    end
    initial begin
        rst = 1'b1;
        start = 1'b0;
        repeat (2) @(posedge clk);
        rst = 1'b0;
        @(negedge clk);
        start = 1'b1;
        @(negedge clk);
        start = 1'b0;
        repeat (6) @(posedge clk);
        $finish;
    end
    initial begin
        forever begin
            @(posedge clk);
            $strobe("TIME = %0t, STATE = %0d, START = %0b, Va0 = %0b,Va1 = %0b, Vb0 = %0b,Vb1 = %0b,BUSY = %0b,DONE = %0b",$time,dut.state,start,valid_a0,valid_a1,valid_b0,valid_b1,busy,done);
        end
    end
endmodule
