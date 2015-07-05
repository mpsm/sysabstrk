#ifndef __SYSTEM_TASK_H__
#define __SYSTEM_TASK_H__

#include "system_types.h"

#include <stdbool.h>

bool task_create(task_t *tsk, task_routine_t rt, void *arg);

#endif /* __SYSTEM_TASK_H__ */
