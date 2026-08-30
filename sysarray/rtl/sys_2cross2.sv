module sys_2cross2(
    input logic clk,
    input logic rst,
    input logic clear,
    input logic [7:0] a0_in,
    input logic [7:0] a1_in,
    input logic [7:0] b0_in,
    input logic [7:0] b1_in,
    input logic valid_a0,
    input logic valid_a1,
    input logic valid_b0,
    input logic valid_b1,
    output logic [31:0] acc00,
    output logic [31:0] acc01,
    output logic [31:0] acc10,
    output logic [31:0] acc11
);
logic [7:0] a00_wire;
logic [7:0] b00_wire;
logic a_valid00_wire;
logic b_valid00_wire;
logic [7:0] a01_wire;
logic [7:0] b01_wire;
logic a_valid01_wire;
logic b_valid01_wire;
logic [7:0] a10_wire;
logic [7:0] b10_wire;
logic a_valid10_wire;
logic b_valid10_wire;
logic [7:0] a11_wire;
logic [7:0] b11_wire;
logic a_valid11_wire;
logic b_valid11_wire;

PE_systolic pe00(
    .clk(clk),
    .rst(rst),
    .clear(clear),
    .a_in(a0_in),
    .b_in(b0_in),
    .a_valid_in(valid_a0),
    .b_valid_in(valid_b0),
    .a_out(a00_wire),
    .b_out(b00_wire),
    .a_valid_out(a_valid00_wire),
    .b_valid_out(b_valid00_wire),
    .acc(acc00)
);

PE_systolic pe01(
    .clk(clk),
    .rst(rst),
    .clear(clear),
    .a_in(a00_wire),
    .b_in(b1_in),
    .a_valid_in(a_valid00_wire),
    .b_valid_in(valid_b1),
    .a_out(a01_wire),
    .b_out(b01_wire),
    .a_valid_out(a_valid01_wire),
    .b_valid_out(b_valid01_wire),
    .acc(acc01)
);

PE_systolic pe10(
    .clk(clk),
    .rst(rst),
    .clear(clear),
    .a_in(a1_in),
    .b_in(b00_wire),
    .a_valid_in(valid_a1),
    .b_valid_in(b_valid00_wire),
    .a_out(a10_wire),
    .b_out(b10_wire),
    .a_valid_out(a_valid10_wire),
    .b_valid_out(b_valid10_wire),
    .acc(acc10)
);

PE_systolic pe11(
    .clk(clk),
    .rst(rst),
    .clear(clear),
    .a_in(a10_wire),
    .b_in(b01_wire),
    .a_valid_in(a_valid10_wire),
    .b_valid_in(b_valid01_wire),
    .a_out(a11_wire),
    .b_out(b11_wire),
    .a_valid_out(a_valid11_wire),
    .b_valid_out(b_valid11_wire),
    .acc(acc11)
);
endmodule