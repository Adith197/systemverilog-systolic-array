module sys_2cross2_controller(
    input logic clk,
    input logic rst,
    input logic start,
    output logic valid_a0,
    output logic valid_a1,
    output logic valid_b0,
    output logic valid_b1,
    output logic busy,
    output logic done
);

typedef enum logic[2:0]{
    IDLE,
    S1,
    S2,
    S3,
    S4,
    DONE
}state_t;
state_t state;

always_ff @(posedge clk) begin
    if (rst) begin
        state <= IDLE;
    end
    else begin
        case (state)
            IDLE: begin 
                if(start)begin
                    state <= S1;
                end
            end
            S1: begin
                state <= S2;
            end
            S2: begin
                state<=S3;
            end
            S3: begin
                state <= S4;
            end
            S4: begin
                state <= DONE;
            end
            DONE: begin
                state <= IDLE;
            end
            default : begin
                state <= IDLE;
            end
        endcase
    end
end

always_comb begin
    valid_a0 = 1'b0;
    valid_a1 = 1'b0;
    valid_b0 = 1'b0;
    valid_b1 = 1'b0;
    busy = 1'b0;
    done = 1'b0;
    case(state)
        S1: begin
            valid_a0 = 1'b1;
            valid_b0 = 1'b1;
            busy = 1'b1;
        end
        S2: begin
            valid_a0 = 1'b1;
            valid_a1 = 1'b1;
            valid_b0 = 1'b1;
            valid_b1 = 1'b1;
            busy = 1'b1;
        end
        S3: begin
            valid_a1 = 1'b1;
            valid_b1 = 1'b1;
            busy = 1'b1;
        end
        S4: begin
            busy = 1'b1;
        end
        DONE: begin
            done = 1'b1;
        end
        default : begin
            
        end
    endcase
end
endmodule
