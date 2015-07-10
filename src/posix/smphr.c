#include <system/system.h>
#include <system/smphr.h>
#include "system-posix.h"

#include <semaphore.h>
#include <time.h>

#include <stdbool.h>

bool smphr_init(smphr_t *s, unsigned int value)
{
    s->value = value;
    return sem_init((sem_t *)&s->handle, 0, value) == 0;
}

bool smphr_take(smphr_t *s, system_tick_t ticks)
{
    struct timespec wait;

    if(ticks == 0) {
        return sem_trywait((sem_t *)&s->handle) == 0;
    }

    system_ticks_to_timespec(ticks, &wait);
    return sem_timedwait((sem_t *)&s->handle, &wait) == 0;
}

bool smphr_give(smphr_t *s)
{
    return sem_post((sem_t *)&s->handle) == 0;
}

