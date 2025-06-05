# 📡 Verilog UART Receiver + Verilator Simulation

A complete simulation of a UART Receiver designed in Verilog, simulated using Verilator and driven by real-time UART data over a Linux PTY (e.g., from QEMU or ESP32).

---

## 🚀 Project Highlights

- 🛠️ Verilog RTL design of a UART RX module (start bit, 8 data bits, stop bit)
- 🧪 C++ testbench with Verilator for full-cycle simulation
- 🔌 Real-time input from `/dev/pts/X` using QEMU, `echo`, or physical UART
- 📈 Waveform tracing using GTKWave (`.vcd` file)

---

## 💻 Features

- Accurate UART sampling at 9600 baud, 16 MHz simulated clock
- FSM-based UART RX logic: idle → start → receive → stop
- Signals exposed for waveform debugging (`clk`, `i_rx`, `data_out`, `state`, etc.)
- UART input characters printed live in C++ and recorded in VCD

---

## 📦 Project Structure

| File            | Description                                 |
|-----------------|---------------------------------------------|
| `uart_rx.v`     | Verilog UART Receiver (parametrized)        |
| `main.cpp`      | Verilator testbench + PTY UART bridge       |
| `uart_rx.vcd`   | Output waveform viewable in GTKWave         |

---

## 🧰 Tools Used

- Verilator
- GTKWave
- QEMU (or ESP32)
- Linux (PTY support)
- C++17

---

## ▶️ How to Run

```bash
# 1. Compile using Verilator
verilator -Wall --cc uart_rx.v --trace --exe main.cpp
make -C obj_dir -f Vuart_rx.mk Vuart_rx

# 2. Run QEMU (or ESP32 UART) and get PTY path (e.g., /dev/pts/3)
qemu-system-arm -M versatilepb -serial pty -nographic -kernel UART.bin

# 3. Run simulation with the PTY
./obj_dir/Vuart_rx /dev/pts/3

# 4. View waveform
gtkwave uart_rx.vcd
