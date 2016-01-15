#ifndef __SYSTEM_POSIX_TASK_H__
#define __SYSTEM_POSIX_TASK_H__

#include <system/base.h>
#include <system/task.h>

#include <pthread.h>

typedef struct {
    task_routine_t rt;
    void *arg;
    pthread_t *handle;
} posix_task_t;

#endif /* __SYSTEM_POSIX_TASK_H__ */
