module PE_chain_tb;
    logic clk;
    logic rst;
    logic clear;
    logic valid_in;
    logic [7:0] a_in;
    logic [7:0] b_in;
    logic [7:0] a_out;
    logic [7:0] b_out;
    logic valid_out;
    logic [31:0] acc0;
    logic [31:0] acc1;

    PE_chain dut (
        .clk(clk),
        .rst(rst),
        .clear(clear),
        .valid_in(valid_in),
        .a_in(a_in),
        .b_in(b_in),
        .a_out(a_out),
        .b_out(b_out),
        .valid_out(valid_out),
        .acc0(acc0),
        .acc1(acc1)
    );
    initial begin
        $dumpfile("PE_chain_tb.vcd");
        $dumpvars(0, PE_tb);
    end
    initial begin
        clk = 1'b0;
        forever begin
            #5 clk = ~clk;
        end 
    end
    initial begin
        rst = 1'b1;
        clear = 1'b0;
        valid_in = 1'b0;
        a_in = 8'd0;
        b_in = 8'd0;
        repeat (2) @(posedge clk);
        rst = 1'b0;
        @(negedge clk);
        a_in = 8'd3;
        b_in = 8'd2;
        valid_in = 1'b1;
        @(negedge clk);
        a_in = 8'd4;
        b_in = 8'd5;
        valid_in = 1'b1;
        @(negedge clk);
        a_in = 8'd7;
        b_in = 8'd2;
        valid_in = 1'b1;
        @(negedge clk);
        valid_in = 1'b0;
        repeat (2) @(posedge clk);
        $finish;
    end
    initial begin
        forever begin
            @(posedge clk);
            $strobe("Time=%0t,A_IN=%0d,B_IN=%0d,VALID_IN=%0b,A_OUT=%0d,B_OUT=%0d,VALID_OUT=%0b,ACC0=%0d,ACC1=%0d",$time,a_in,b_in,valid_in,a_out,b_out,valid_out,acc0,acc1);
        end
    end
endmodule
