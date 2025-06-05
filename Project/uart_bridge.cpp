#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include "/usr/share/verilator/include/verilated.h"
#include "obj_dir/Vuart_rx.h"
#include "/usr/share/verilator/include/verilated_vcd_c.h"

// Simulation settings
#define BAUD_RATE 9600
#define CLOCK_FREQ 16000000
#define CLKS_PER_BIT (CLOCK_FREQ / BAUD_RATE)

// Verilator globals
Vuart_rx *top;
VerilatedVcdC *tfp;
vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

// Clock tick with VCD dump
void tick() {
    top->clk = 0;
    top->eval();
    tfp->dump(main_time++);

    top->clk = 1;
    top->eval();
    tfp->dump(main_time++);
}

// Send UART frame (start + 8 data + stop)
bool send_uart_byte(uint8_t byte) {
    // Start bit (low)
    top->i_rx = 0;
    for (int i = 0; i < CLKS_PER_BIT; ++i) tick();

    // Data bits (LSB first)
    for (int i = 0; i < 8; ++i) {
        top->i_rx = (byte >> i) & 1;
        for (int j = 0; j < CLKS_PER_BIT; ++j) tick();
    }

    // Stop bit (high)
    top->i_rx = 1;
    for (int i = 0; i < CLKS_PER_BIT; ++i) tick();
    return 1;


}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " /dev/pts/X\n";
        return 1;
    }

    const char *pty_path = argv[1];
    int fd = open(pty_path, O_RDONLY | O_NOCTTY);
    if (fd < 0) {
        perror("Failed to open PTY");
        return 1;
    }

    // Set PTY to raw mode
    termios t;
    tcgetattr(fd, &t);
    cfmakeraw(&t);
    tcsetattr(fd, TCSANOW, &t);

    // Init Verilator
    Verilated::traceEverOn(true);
    tfp = new VerilatedVcdC;
    top = new Vuart_rx;

    top->i_rx = 1; // UART idle
    top->clk = 0;
    top->eval();

    top->trace(tfp, 99);
    tfp->open("uart_rx.vcd");

    for (int i = 0; i < 100; ++i) tick();


    std::cout << "✅ Listening on " << pty_path << " for UART data...\n";
    // Simulate receiving the letter 'A' (0x41)
    char c=0x41;
if(send_uart_byte(c))
{
    std::cout << "📨 Received char: '" << c << "' (0x" 
    << std::hex << int(c) << std::dec << ")\n";
}
for (int i = 0; i < CLKS_PER_BIT * 30; ++i) tick();


    uint8_t buffer;
    while (read(fd, &buffer, 1) == 1) {

        if(buffer !=0)
        {
            std::cout<<"Data ready \n";
        std::cout << "📨 Received char: '" << buffer << "' (0x" 
                  << std::hex << int(buffer) << std::dec << ")\n";
                  send_uart_byte(buffer);

        }

       
        // Wait until data_ready
        int wait = 0;
        while (!top->data_ready && wait++ < CLKS_PER_BIT * 20) {
            tick();
            //std::cout<<"Still not ready\n";
        }
        

        if (top->data_ready) {
            std::cout << "✅ UART RX Output: '" << char(top->data_out)
                      << "' (0x" << std::hex << int(top->data_out) << std::dec << ")\n";
            top->data_ready = 0; // Reset flag manually
        }
    }

    tfp->close();
    close(fd);
    delete tfp;
    delete top;
    return 0;
}
