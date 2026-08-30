module sys_2cross2_scheduler(
    input logic clk,
    input logic rst,
    input logic start,
    input logic [7:0] A00,
    input logic [7:0] A01,
    input logic [7:0] A10,
    input logic [7:0] A11,
    input logic [7:0] B00,
    input logic [7:0] B01,
    input logic [7:0] B10,
    input logic [7:0] B11,
    output logic [7:0] a0_out,
    output logic [7:0] a1_out,
    output logic [7:0] b0_out,
    output logic [7:0] b1_out,
    output logic valid_a0,
    output logic valid_a1,
    output logic valid_b0,
    output logic valid_b1,
    output logic busy,
    output logic done
);
logic [2:0] cycle;
logic active;
logic done_reg;
always_ff @(posedge clk) begin
    if (rst) begin
        cycle <= 3'd0;
        active <= 1'b0;
        done_reg <= 1'b0;
    end
    else begin
        done_reg <= 1'b0;
        if(start && !active) begin
            cycle <= 3'd0;
            active <= 1'b1;
        end
        else if(active) begin
            if(cycle == 3'd3) begin
                active <= 1'b0;
                done_reg <= 1'b1;
            end
            else begin
                cycle <= cycle + 3'd1;
            end
        end
    end
end

always_comb begin
    a0_out = 8'd0;
    a1_out = 8'd0;
    b0_out = 8'd0;
    b1_out = 8'd0;
    valid_a0 = 1'b0;
    valid_a1 = 1'b0;
    valid_b0 = 1'b0;
    valid_b1 = 1'b0;
    busy = active;
    done = done_reg;
    if (active) begin
        case (cycle)
            3'd0: begin
                a0_out = A00;
                b0_out = B00;
                valid_a0 = 1'b1;
                valid_b0 = 1'b1;
            end
            3'd1: begin
                a0_out = A01;
                a1_out = A10;
                b0_out = B10;
                b1_out = B01;
                valid_a0 = 1'b1;
                valid_a1 = 1'b1;
                valid_b0 = 1'b1;
                valid_b1 = 1'b1;
            end
            3'd2: begin
                a1_out = A11;
                b1_out = B11;
                valid_a1 = 1'b1;
                valid_b1 = 1'b1;
            end
            3'd3: begin
                
            end
            default: begin
                
            end
        endcase
    end
end
endmodule

