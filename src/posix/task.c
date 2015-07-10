#include "system.h"
#include "task.h"

#include <pthread.h>

#include <stdbool.h>
#include <stddef.h>

bool task_create(task_t *tsk, task_routine_t rt, void *arg)
{
    return pthread_create(tsk->handle, NULL, rt, arg) == 0;
}

