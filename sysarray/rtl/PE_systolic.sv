module PE_systolic(
     input logic clk,
     input logic rst,
     input logic clear,
     input logic [7:0] a_in,
     input logic [7:0] b_in,
     input logic a_valid_in,
     input logic b_valid_in, 
     output logic [7:0] a_out,
     output logic [7:0] b_out,
     output logic a_valid_out,
     output logic b_valid_out,
     output logic [31:0] acc
);
logic [7:0] a_reg;
logic [7:0] b_reg;
logic a_valid_reg;
logic b_valid_reg;
logic [31:0] acc_reg;

always_ff @(posedge clk)
begin
    if (rst)begin
        a_reg <= 8'd0;
        b_reg <= 8'd0;
        a_valid_reg <= 1'b0;
        b_valid_reg <= 1'b0;
        acc_reg <= 32'd0;
    end
    else begin
        a_reg <= a_in;
        a_valid_reg <= a_valid_in;
        b_reg <= b_in;
        b_valid_reg <= b_valid_in;
        if (clear) begin
            acc_reg <= 32'd0;
        end

        else if (a_valid_in && b_valid_in) begin
            acc_reg <= acc_reg + (a_in*b_in);
        end
    end
end
assign a_out       = a_reg;
assign a_valid_out = a_valid_reg;
assign b_out       = b_reg;
assign b_valid_out = b_valid_reg;
assign acc = acc_reg;
endmodule
