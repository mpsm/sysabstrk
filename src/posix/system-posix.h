#ifndef __SYSTEM_POSIX_H__
#define __SYSTEM_POSIX_H__

#include <system/system.h>
#include <time.h>

void system_ticks_to_timespec(system_tick_t ticks, struct timespec *ts);

#endif /* __SYSTEM_POSIX_H__ */
