#ifndef __SYSTEM_TASK_H__
#define __SYSTEM_TASK_H__

#include <system/base.h>

#include <stdbool.h>

/* task descriptor */
typedef void* task_t;

/* task routine */
typedef void (*task_routine_t)(void *arg);

bool task_create(task_t *tsk, task_routine_t rt, void *arg);
void task_destroy(task_t tsk);

#endif /* __SYSTEM_TASK_H__ */
