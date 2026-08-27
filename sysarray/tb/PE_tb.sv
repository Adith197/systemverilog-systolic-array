module PE_tb;
    logic clk;
    logic rst;
    logic clear;
    logic valid_in;
    logic [7:0] a_in;
    logic [7:0] b_in;
    logic [31:0] acc;
    logic [7:0] a_out;
    logic [7:0] b_out;
    logic valid_out;
    PE dut (
        .clk(clk),
        .rst(rst),
        .clear(clear),
        .valid_in(valid_in),
        .a_in(a_in),
        .b_in(b_in),
        .a_out(a_out),
        .b_out(b_out),
        .valid_out(valid_out),
        .acc(acc)
    );
    initial begin
        $dumpfile("PE_tb.vcd");
        $dumpvars(0, PE_tb);
    end
    initial begin
        clk = 1'b0;
    end
    initial begin
        forever begin
            #5 clk = ~clk;
        end
    end
    initial begin
        rst=1'b1;
        clear=1'b0;
        valid_in=1'b0;
        a_in=8'd0;
        b_in=8'd0;
        repeat (2) @(posedge clk);
        rst=1'b0;
        @(negedge clk);//after 15 the clock falls from 1 to 0 but MAC doesnt take place 
        a_in=8'd3;
        b_in=8'd2;
        valid_in=1'b1;
        //MAC happens at the nest clock edge where it is an posedge at 
        @(negedge clk);
        a_in=8'd4;
        b_in=8'd5;
        valid_in=1'b1;
        @(negedge clk);
        valid_in=1'b0;
        @(negedge clk);
        a_in=8'd7;
        b_in=8'd2;
        valid_in=1'b1;
        @(negedge clk);
        clear=1'b1;
        valid_in=1'b0;
        @(negedge clk);
        clear = 1'b0;
        repeat (2) @(posedge clk);
        $finish;
    end
    always @(posedge clk) begin
        $strobe("time = %0t,A_in=%0d,B_in=%0d,Valid_in=%0b,A_out=%0d,B_out=%0d,Valid_out=%0b,ACC=%0d",$time,a_in,b_in,valid_in,a_out,b_out,valid_out,acc);
    end
endmodule

