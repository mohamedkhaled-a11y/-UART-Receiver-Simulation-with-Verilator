module uart_rx #(parameter CLKS_PER_BIT = 16)
(
    input wire i_rx,
    input wire clk,
    output reg [7:0] data_out,
    output wire data_ready
);

localparam Idle = 0, start = 1, datarcv = 2, stop = 3;

reg [1:0] state = Idle;
reg [2:0] bit_index = 0;
reg [7:0] data_buffer = 0;
reg dataReady = 0;
reg [15:0] counter = 0;

reg rx_buffer = 1'b1;
reg rx = 1'b1;

assign data_ready = dataReady;

always @(posedge clk) begin
    rx_buffer <= i_rx;
    rx <= rx_buffer;
end

always @(posedge clk) begin
    case (state)
        Idle: begin
            data_buffer <= 0;
            dataReady <= 0;
            counter <= 0;
            bit_index <= 0;
            if (~rx)
                state <= start;
        end

        start: begin
            if (counter == (CLKS_PER_BIT - 1)/2) begin
                if (rx == 0) begin
                    counter <= 0;
                    state <= datarcv;
                end else begin
                    state <= Idle;
                end
            end else begin
                counter <= counter + 1;
            end
        end

        datarcv: begin 
            if (counter < CLKS_PER_BIT - 1) begin
                counter <= counter + 1;
            end else begin
                data_buffer[bit_index] <= rx;
                counter <= 0;
                if (bit_index == 7) begin 
                    state <= stop;
                end else begin  
                    bit_index <= bit_index + 1;
                end
            end
        end

        stop: begin 
            if (counter < CLKS_PER_BIT - 1) begin
                counter <= counter + 1;
            end else begin 
                dataReady <= 1;
                data_out <= data_buffer;
                counter <= 0;
                state <= Idle; 
            end
        end

        default: state <= Idle;
    endcase
end

endmodule

