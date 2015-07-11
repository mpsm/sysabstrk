#ifndef __SYSTEM_QUEUE_H__
#define __SYSTEM_QUEUE_H__

#include <system/system.h>
#include <system/smphr.h>
#include <system/mutex.h>

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    smphr_t sem;
    mutex_t mtx;
    size_t size;
    size_t element_size;
    size_t elements;
    size_t index;
    void *data;
} queue_t;

bool queue_create(queue_t *q, size_t size, size_t elsize);
size_t queue_elements_count(queue_t *q);
bool queue_push(queue_t *q, void *el, system_tick_t ticks);
bool queue_pop(queue_t *q, void *el, system_tick_t ticks);

#endif /* __SYSTEM_QUEUE_H__ */
