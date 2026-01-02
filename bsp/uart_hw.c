#include "uart.h"

#define UART_BASE   0x40000000   // change to MCU's correct UART peripheral base
#define UART_TX     (*(volatile unsigned int *)(UART_BASE + 0x00))
#define UART_STATUS (*(volatile unsigned int *)(UART_BASE + 0x18))

void uart_putc(char c) {
    while (!(UART_STATUS & 0x01)); 
    UART_TX = c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}
