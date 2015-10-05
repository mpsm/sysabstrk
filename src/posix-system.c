#include <system/base.h>
#include <system/system.h>
#include <system/task.h>

#include <time.h>
#include <pthread.h>
#include <signal.h>

#include <stdbool.h>
#include <string.h>

#include "posix-system.h"

#define NSEC_IN_SEC (1000000000L)

static unsigned int task_count = 0;
static task_t *tasks[SYSTEM_CONFIG_MAX_TASKS];

void system_init()
{
    memset(tasks, 0, sizeof(tasks));
}

void system_ticks_to_timespec(system_tick_t ticks, struct timespec *ts)
{
    ts->tv_sec = ticks / SYSTEM_CONFIG_TICKS_1S;
    ticks %= SYSTEM_CONFIG_TICKS_1S;
    ts->tv_nsec = NSEC_IN_SEC / SYSTEM_CONFIG_TICKS_1S * ticks;
}

void system_delay_to_timespec(system_tick_t delay, struct timespec *ts)
{
    struct timespec ct;

    clock_gettime(CLOCK_REALTIME, &ct);
    system_ticks_to_timespec(delay, ts);

    ts->tv_nsec += ct.tv_nsec;
    ts->tv_sec += ct.tv_sec;
    ts->tv_sec += ts->tv_nsec / NSEC_IN_SEC;
    ts->tv_nsec %= NSEC_IN_SEC;
}

bool system_task_reg(task_t *t)
{
    if(task_count < SYSTEM_CONFIG_MAX_TASKS) {
        tasks[task_count] = t;
        task_count++;
        return true;
    }

    return false;
}

bool system_start()
{
    sigset_t sigs;
    unsigned int i = 0;
    int signum;
    bool retval = true;

    /* create full signal set */
    sigfillset(&sigs);
    pthread_sigmask(SIG_BLOCK, &sigs, NULL);

    /* spawn threads */
    for(i = 0; i < task_count; ++i) {
        task_t *t = tasks[i];
        if(pthread_create((pthread_t*)t->handle, NULL, t->rt, t->arg) != 0) {
            return false;
        } 
    }

    /* wait for a signal */
    if(sigwait(&sigs, &signum) != 0) {
        return false;
    }

    /* cancel all running threads */
    for(i = 0; i < task_count; ++i) {
        retval &= pthread_cancel(*(pthread_t *)tasks[i]->handle) == 0;
        retval &= pthread_join(*(pthread_t *)tasks[i]->handle, NULL);
        task_destroy(tasks[i]);
    }

    return retval;
}