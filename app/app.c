#include "../kernel/rtos.h"
#include "../bsp/uart.h"

static int led_count = 0;
static int sensor_count = 0;

void led_task(void) {
    if (led_count < 10) {
        uart_puts("LED\n");
        led_count++;
    }
}

void sensor_task(void) {
    if (sensor_count < 10) {
        uart_puts("SENSOR\n");
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
