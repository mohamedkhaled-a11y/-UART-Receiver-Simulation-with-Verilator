#define UART1_BASE 0x101f2000
volatile unsigned int* const UART1DR = (unsigned int*)(UART1_BASE);

void uart_send_char(char c) {
    *UART1DR = c;  // Write to UART1
}

void uart_send_string(const char* str) {
    while (*str) {
        uart_send_char(*str++);
    }
}

void main(void) {
    uart_send_string("A");
    while (1);
}
