#include <system/system.h>
#include <time.h>

#include "system-posix.h"

void system_ticks_to_timespec(system_tick_t ticks, struct timespec *ts)
{
    ts->tv_sec = ticks / SYSTEM_CONFIG_TICKS_1S;
    ticks %= SYSTEM_CONFIG_TICKS_1S;
    ts->tv_nsec = 1000000000L / SYSTEM_CONFIG_TICKS_1S * ticks;
}
