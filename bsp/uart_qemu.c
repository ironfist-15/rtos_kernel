#include "uart.h"

#define UART0 ((volatile char *)0x10000000)

void uart_putc(char c) {
    *UART0 = c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}
