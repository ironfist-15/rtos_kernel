#include "../kernel/rtos.h"

#define UART0 ((volatile char *)0x10000000)

static void uart_putc(char c) {
    *UART0 = c;
}

static void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

static int led_count = 0;
static int sensor_count = 0;

#define LED_LIMIT 10
#define SENSOR_LIMIT 10

void led_task(void) {
    if (led_count < LED_LIMIT) {
        uart_puts("LED_Operation\n");
        led_count++;
    }
}

void sensor_task(void) {
    if (sensor_count < SENSOR_LIMIT) {
        uart_puts("SENSOR_Operation\n");
        sensor_count++;
    }
}

int main(void) {
    rtos_init();
    rtos_create_task(led_task);
    rtos_create_task(sensor_task);
    rtos_start();
    return 0;
}
