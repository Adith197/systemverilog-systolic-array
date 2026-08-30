module sys_2cross2_scheduler_tb;
    logic clk;
    logic rst;
    logic start;
    logic [7:0] A00;
    logic [7:0] A01;
    logic [7:0] A10;
    logic [7:0] A11;
    logic [7:0] B00;
    logic [7:0] B01;
    logic [7:0] B10;
    logic [7:0] B11;
    logic [7:0] a0_out;
    logic [7:0] a1_out;
    logic [7:0] b0_out;
    logic [7:0] b1_out;
    logic valid_a0;
    logic valid_a1;
    logic valid_b0;
    logic valid_b1;
    logic busy;
    logic done;

    sys_2cross2_scheduler dut(
        .clk(clk),
        .rst(rst),
        .start(start),
        .A00(A00),
        .A01(A01),
        .A10(A10),
        .A11(A11),
        .B00(B00),
        .B01(B01),
        .B10(B10),
        .B11(B11),
        .a0_out(a0_out),
        .a1_out(a1_out),
        .b0_out(b0_out),
        .b1_out(b1_out),
        .valid_a0(valid_a0),
        .valid_a1(valid_a1),
        .valid_b0(valid_b0),
        .valid_b1(valid_b1),
        .busy(busy),
        .done(done)
    );
    initial begin
        clk = 1'b0;
        forever begin
            #5 clk = ~clk;
        end
    end
    initial begin
        rst = 1'b1;
        start = 1'b0;
        A00 = 8'd1;
        A01 = 8'd2;
        A10 = 8'd3;
        A11 = 8'd4;
        B00 = 8'd5;
        B01 = 8'd6;
        B10 = 8'd7;
        B11 = 8'd8;
        repeat (2) @(posedge clk);
        rst = 1'b0;
        @(negedge clk);
        start = 1'b1;
        @(negedge clk);
        start = 1'b0;
        repeat (5) @(posedge clk);
        $finish;
    end
    initial begin

        forever begin
            @(posedge clk);
            $strobe("TIME=%0t | START=%0b BUSY=%0b DONE=%0b | A0=%0d A1=%0d VA0=%0b VA1=%0b | B0=%0d B1=%0d VB0=%0b VB1=%0b",$time,start,busy,done,a0_out,a1_out,valid_a0,valid_a1,b0_out,b1_out,valid_b0,valid_b1);
        end
    end
endmodule


