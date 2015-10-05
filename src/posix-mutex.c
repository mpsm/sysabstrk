#include <system/base.h>
#include <system/smphr.h>
#include <system/mutex.h>

#include <stdbool.h>

bool mutex_init(mutex_t *m)
{
    return smphr_init((smphr_t *)m, 1);
}

bool mutex_lock(mutex_t *m, system_tick_t t)
{
    return smphr_take((smphr_t *)m, t);
}

bool mutex_unlock(mutex_t *m)
{
    return smphr_give((smphr_t *)m);
}
