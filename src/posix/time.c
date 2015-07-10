#include <system/system.h>
#include <system/time.h>

#include <time.h>

#include <stddef.h>

void system_delay(system_tick_t ticks)
{
    struct timespec delay;

    delay.tv_sec = ticks / SYSTEM_CONFIG_TICKS_1S;
    ticks %= SYSTEM_CONFIG_TICKS_1S;
    delay.tv_nsec = 1000000000L / SYSTEM_CONFIG_TICKS_1S * ticks;

    nanosleep(&delay, NULL);
}
