`timescale 1ns/1ps

module PE_sysarray #(parameter int N=4)(
    input logic clk,
    input logic rst,
    input logic clear,
    input logic [7:0] a_in[N],
    input logic [7:0] b_in[N],
    input logic a_valid_in[N],
    input logic b_valid_in[N], 
    output logic [31:0] acc[N][N]
);  
logic [7:0] a_wire [N][N];
logic [7:0] b_wire [N][N];
logic valid_a_wire [N][N];
logic valid_b_wire [N][N];
genvar i,j;
generate 
    for (i=0;i<N;i++) begin :row
        for (j=0;j<N;j++) begin :col
            PE_systolic pe(
                .clk(clk),
                .rst(rst),
                .clear(clear),
                .a_in(j==0 ? a_in[i]:a_wire[i][j-1]),
                .b_in(i==0 ? b_in[j]:b_wire[i-1][j]),
                .a_valid_in(j==0 ? a_valid_in[i]:valid_a_wire[i][j-1]),
                .b_valid_in(i==0 ? b_valid_in[j]:valid_b_wire[i-1][j]),
                .a_out(a_wire[i][j]),
                .b_out(b_wire[i][j]),
                .a_valid_out(valid_a_wire[i][j]),
                .b_valid_out(valid_b_wire[i][j]),
                .acc(acc[i][j])
            );
        end
    end
endgenerate
endmodule