module sys_2cross2_accelerator_tb;
    logic clk;
    logic rst;
    logic clear;
    logic start;
    logic [7:0] A00;
    logic [7:0] A01;
    logic [7:0] A10;
    logic [7:0] A11;
    logic [7:0] B00;
    logic [7:0] B01;
    logic [7:0] B10;
    logic [7:0] B11;
    logic busy;
    logic done;
    logic [31:0] acc00;
    logic [31:0] acc01;
    logic [31:0] acc10;
    logic [31:0] acc11;
    sys_2cross2_accelerator dut (
        .clk(clk),
        .rst(rst),
        .start(start),
        .clear(clear),
        .A00(A00),
        .A01(A01),
        .A10(A10),
        .A11(A11),
        .B00(B00),
        .B01(B01),
        .B10(B10),
        .B11(B11),
        .busy(busy),
        .done(done),
        .acc00(acc00),
        .acc01(acc01),
        .acc10(acc10),
        .acc11(acc11)
    );
    initial begin
        $dumpfile("sys_2cross2_accel.vcd");
        $dumpvars(0,sys_2cross2_accelerator);
    end
    initial begin
        clk = 1'b0;
        forever begin 
            #5 clk = ~clk;
        end
    end
    initial begin
        rst = 1'b1;
        clear = 1'b1;
        start = 1'b0;
        A00 = 8'd0;
        A01 = 8'd0;
        A10 = 8'd0;
        A11 = 8'd0;
        B00 = 8'd0;
        B01 = 8'd0;
        B10 = 8'd0;
        B11 = 8'd0;
        repeat (2) @(posedge clk);
        rst = 1'b0;
        clear = 1'b0;
        A00 = 8'd1;
        A01 = 8'd2;
        A10 = 8'd3;
        A11 = 8'd4;
        B00 = 8'd5;
        B01 = 8'd6;
        B10 = 8'd7;
        B11 = 8'd8;
        @(negedge clk);
        start = 1'b1;
        @(negedge clk);
        start = 1'b0;
        wait(done);
        $display("Accelerator DONE");
        $display("ACC00 = %0d", acc00);
        $display("ACC01 = %0d", acc01);
        $display("ACC10 = %0d", acc10);
        $display("ACC11 = %0d", acc11);
        repeat (2) @(posedge clk);
        $finish;
    end
    initial begin

    forever begin

            @(posedge clk);

           $strobe(
            "TIME=%0t | START=%0b BUSY=%0b DONE=%0b | ACC00=%0d ACC01=%0d ACC10=%0d ACC11=%0d",
             $time,
             start,
             busy,
             done,
             acc00,
             acc01,
             acc10,
             acc11
            );

        end

    end
endmodule