#include <system/system.h>
#include <system/task.h>
#include "system-posix.h"

#include <pthread.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

bool task_create(task_t *tsk, task_routine_t rt, void *arg)
{
    tsk->rt = rt;
    tsk->arg = arg;
    tsk->handle = malloc(sizeof(pthread_t));

    return system_task_reg(tsk);
}

