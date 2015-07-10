#ifndef __SYSTEM_SMPHR_H__
#define __SYSTEM_SMPHR_H__

#include <stdbool.h>

typedef struct {
    void *handle;
    unsigned int value;
} smphr_t;

bool smphr_init(smphr_t *s, unsigned int value);
bool smphr_take(smphr_t *s, system_tick_t ticks);
bool smphr_give(smphr_t *s);

#endif /* __SYSTEM_SMPHR_H__ */
