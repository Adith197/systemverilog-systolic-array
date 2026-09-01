`timescale 1ns/1ps

module PE (
    input logic clk,
    input logic rst,
    input logic clear,
    input logic valid_in,
    input logic [7:0] a_in,
    input logic [7:0] b_in,
    output logic [7:0] a_out,
    output logic [7:0] b_out,
    output logic valid_out,
    output logic [31:0] acc
);
logic [7:0] a_reg;
logic [7:0] b_reg;
logic valid_reg;
logic [31:0] acc_reg;
always_ff @(posedge clk) begin
    if (rst) begin
        a_reg <= 8'd0;
        b_reg <= 8'd0;
        acc_reg <= 32'd0;
        valid_reg <= 1'b0;
    end
    else begin
        a_reg <=a_in;
        b_reg <=b_in;
        valid_reg <= valid_in;
        if (clear) begin
            acc_reg <=32'd0;
        end
        else if (valid_in) begin
            acc_reg <= acc_reg + (a_in * b_in);
        end
    end
end
assign a_out = a_reg;
assign b_out = b_reg;
assign valid_out = valid_reg;
assign acc = acc_reg;
endmodule
