module sys_systolic_accelerator #(parameter int N = 4)(
    input logic clk,
    input logic rst,
    input logic start,
    input logic clear,
    input logic [7:0] A [N][N],
    input logic [7:0] B [N][N],
    output logic busy,
    output logic done,
    output logic [31:0] acc_final [N][N]
);
logic [$clog2(2*N+1)-1:0] cycle;
logic valid_a [N];
logic valid_b [N];
logic [7:0] a_sched[N];
logic [7:0] b_sched[N];
sys_systolic_controller #(.N(N)) controller (
    .clk(clk),
    .rst(rst),
    .start(start),
    .cycle(cycle),
    .valid_a(valid_a),
    .valid_b(valid_b),
    .busy(busy),
    .done(done)
);
sys_systolic_scheduler #(.N(N)) scheduler (
    .cycle(cycle),
    .A(A),
    .B(B),
    .a_out(a_sched),
    .b_out(b_sched)
);
PE_sysarray #(.N(N)) pe_array (
    .clk(clk),
    .rst(rst),
    .clear(clear),
    .a_in(a_sched),
    .b_in(b_sched),
    .a_valid_in(valid_a),
    .b_valid_in(valid_b),
    .acc(acc_final)
);
endmodule
