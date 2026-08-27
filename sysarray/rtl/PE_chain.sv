module PE_chain (
    input logic clk,
    input logic rst,
    input logic clear,
    input logic valid_in,
    input logic [7:0] a_in,
    input logic [7:0] b_in,
    output logic [7:0] a_out,
    output logic [7:0] b_out,
    output logic valid_out,
    output logic [31:0] acc0,
    output logic [31:0] acc1
);
logic [7:0] a_wire;
logic [7:0] b_wire;
logic valid_wire;

PE pe0 (
    .clk(clk),
    .rst(rst),
    .clear(clear),
    .valid_in(valid_in),
    .a_in(a_in),
    .b_in(b_in),
    .a_out(a_wire),
    .b_out(b_wire),
    .valid_out(valid_wire),
    .acc(acc0)
);
PE pe1 (
    .clk(clk),
    .rst(rst),
    .clear(clear),
    .valid_in(valid_wire),
    .a_in(a_wire),
    .b_in(b_wire),
    .a_out(a_out),
    .b_out(b_out),
    .valid_out(valid_out),
    .acc(acc1)
);
endmodule
