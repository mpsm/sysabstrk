#include <system/system.h>
#include <system/queue.h>
#include <system/smphr.h>

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

bool queue_create(queue_t *q, size_t size, size_t elsize)
{
    q->size = size;
    q->element_size = elsize;
    q->elements = 0;
    q->data = malloc(size * elsize);

    return q->data != NULL && smphr_init(&q->sem, size);
}

size_t queue_elements_count(queue_t *q)
{
    return q->elements;
}
