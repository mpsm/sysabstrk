#ifndef __SYSTEM_QUEUE_H__
#define __SYSTEM_QUEUE_H__

#include <system/system.h>
#include <system/smphr.h>

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    smphr_t sem;
    size_t size;
    size_t element_size;
    size_t elements;
    void *data;
} queue_t;

bool queue_create(queue_t *q, size_t size, size_t elsize);
size_t queue_elements_count(queue_t *q);

#endif /* __SYSTEM_QUEUE_H__ */
