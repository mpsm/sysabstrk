#include <system/system.h>
#include <time.h>

#include "system-posix.h"

#define NSEC_IN_SEC (1000000000L)

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
