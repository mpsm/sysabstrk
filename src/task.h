#ifndef __SYSTEM_TASK_H__
#define __SYSTEM_TASK_H__

#include "system.h"
#include <stdbool.h>

/* task descriptor */
typedef void* (*task_routine_t)(void *arg);
typedef struct {
    void *handle;
    void *arg;
    task_routine_t rt;
} task_t;

bool task_create(task_t *tsk, task_routine_t rt, void *arg);

#endif /* __SYSTEM_TASK_H__ */
