#include "rtos.h"

#define MAX_TASKS 2

static task_func_t tasks[MAX_TASKS];
static int task_count = 0;

void rtos_init(void) {
    task_count = 0;
}

void rtos_create_task(task_func_t task) {
    if (task_count < MAX_TASKS) {
        tasks[task_count++] = task;
    }
}

void rtos_start(void) {
    // Cooperative round-robin (Stage-0)
    while (1) {
        for (int i = 0; i < task_count; i++) {
            tasks[i]();
        }
    }
}
