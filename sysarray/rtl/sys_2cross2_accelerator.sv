module sys_2cross2_accelerator (
    input logic clk,
    input logic rst,
    input logic start,
    input logic clear,
    input logic [7:0] A00,
    input logic [7:0] A01,
    input logic [7:0] A10,
    input logic [7:0] A11,
    input logic [7:0] B00,
    input logic [7:0] B01,
    input logic [7:0] B10,
    input logic [7:0] B11,
    output logic busy,
    output logic done,
    output logic [31:0] acc00,
    output logic [31:0] acc01,
    output logic [31:0] acc10,
    output logic [31:0] acc11
);
logic [7:0] a0_sched;
logic [7:0] a1_sched;
logic [7:0] b0_sched;
logic [7:0] b1_sched;
logic valid_a0;
logic valid_a1;
logic valid_b0;
logic valid_b1;
logic scheduler_busy;
logic scheduler_done;
logic ctrl_valid_a0;
logic ctrl_valid_a1;
logic ctrl_valid_b0;
logic ctrl_valid_b1;
logic ctrl_busy;
logic ctrl_done;

sys_2cross2_controller controller (
        .clk(clk),
        .rst(rst),
        .start(start),
        .valid_a0(ctrl_valid_a0),
        .valid_a1(ctrl_valid_a1),
        .valid_b0(ctrl_valid_b0),
        .valid_b1(ctrl_valid_b1),
        .busy(ctrl_busy),
        .done(ctrl_done)
);
sys_2cross2_scheduler scheduler (
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
        .a0_out(a0_sched),
        .a1_out(a1_sched),
        .b0_out(b0_sched),
        .b1_out(b1_sched),
        .valid_a0(valid_a0),
        .valid_a1(valid_a1),
        .valid_b0(valid_b0),
        .valid_b1(valid_b1),
        .busy(scheduler_busy),
        .done(scheduler_done)
);
sys_2cross2 array (
        .clk(clk),
        .rst(rst),
        .clear(clear),
        .a0_in(a0_sched),
        .a1_in(a1_sched),
        .b0_in(b0_sched),
        .b1_in(b1_sched),
        .valid_a0(valid_a0),
        .valid_a1(valid_a1),
        .valid_b0(valid_b0),
        .valid_b1(valid_b1),
        .acc00(acc00),
        .acc01(acc01),
        .acc10(acc10),
        .acc11(acc11)
);
assign busy = scheduler_busy;
assign done = scheduler_done;
endmodule