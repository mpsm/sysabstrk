#ifndef __SYSTEM_MUTEX_H__
#define __SYSTEM_MUTEX_H__

#include <system/system.h>
#include <system/smphr.h>

#include <stdbool.h>

typedef smphr_t mutex_t;

bool mutex_init(mutex_t *m);
bool mutex_lock(mutex_t *m, system_tick_t t);
bool mutex_unlock(mutex_t *m);

#endif /* __SYSTEM_MUTEX_H__ */