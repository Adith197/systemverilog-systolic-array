`timescale 1ns/1ps

module sys_systolic_controller #(parameter int N = 2)(
    input logic clk,
    input logic rst,
    input logic start,
    output logic [$clog2(2*N+1)-1:0] cycle,//log funtion based 2 to return the cycle number to the scheduler
    output logic valid_a [N],
    output logic valid_b [N],
    output logic busy,
    output logic done
);
localparam int CYCLE_W = $clog2(2*N+1);
localparam int LAST_CYCLE = 2*N-2;
localparam int DRAIN_W = $clog2(N+1);
typedef enum logic [1:0]{
    IDLE,
    RUN,
    DRAIN,
    DONE
}state_t;
state_t state;
logic [DRAIN_W-1:0] drain_count;
always_ff @(posedge clk) begin
    if (rst) begin
        state <= IDLE;
        cycle <= '0;
        drain_count <= '0;
    end
    else begin
        case (state)
            IDLE :begin
                cycle <= '0;
                drain_count <= '0;
                if (start) begin
                    state <= RUN;
                end
            end
            RUN :begin
                if (cycle == CYCLE_W'(LAST_CYCLE)) begin
                    state <= DRAIN;
                    drain_count <= '0;
                end
                else begin
                    cycle <= cycle+1'b1;
                end
            end
            DRAIN :begin
                if(drain_count == DRAIN_W'(N-1)) begin
                    state <= DONE;
                end
                else begin
                    drain_count <= drain_count+1'b1;
                end
            end
            DONE :begin
                state <= IDLE;
                cycle <= '0;
                drain_count <= '0;
            end
            default :begin
                state <= IDLE;
                cycle <= '0;
                drain_count <= '0;
            end
        endcase
    end
end

always_comb begin
    busy = 1'b0;
    done = 1'b0;
    for (int i=0;i<N;i++) begin
        valid_a[i] = 1'b0;
        valid_b[i] = 1'b0;
    end
    case (state)
        RUN: begin
            busy = 1'b1;
            for (int i=0 ;i<N;i++) begin
                if (cycle>=CYCLE_W'(i) && cycle<CYCLE_W'(i+N)) begin
                    valid_a[i] = 1'b1;
                end
                if (cycle>=CYCLE_W'(i) && cycle<CYCLE_W'(i+N)) begin
                    valid_b[i] = 1'b1;
                end
            end
        end
        DRAIN: begin
            busy = 1'b1;
        end
        DONE :begin
            done = 1'b1;
        end
        default :begin
        end
    endcase
end
endmodule