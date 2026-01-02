#ifndef RTOS_H
#define RTOS_H

typedef void (*task_func_t)(void);

void rtos_init(void);
void rtos_create_task(task_func_t task);
void rtos_start(void);

#endif
