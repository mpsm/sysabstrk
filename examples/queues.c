#include <system/system.h>
#include <system/task.h>
#include <system/queue.h>

#include <stddef.h>
#include <stdio.h>

static queue_t q;

void *producer(void *arg)
{
    uintptr_t id = (uintptr_t)arg;

    printf("Producer %u started\n", (unsigned int)id);

    for(;;) {
        system_delay(id * 1000);
        printf("Producer %u pushed\n", (unsigned int)id);
        queue_push(&q, &id, 1000);
    }

    return NULL;
}

void *consumer(void *arg)
{
    printf("Consumer started\n");

    for(;;) {
        uintptr_t data;
        if(queue_pop(&q, &data, 800)) {
            printf("Consumer received: %u\n", (unsigned int)data);
            continue;
        }
        printf("Consumer timeout\n");
    }

    return NULL;
}

#define PRODUCERS 5

int main(void)
{
    task_t c;
    task_t p[PRODUCERS];
    unsigned int i;

    system_init();

    queue_create(&q, PRODUCERS, sizeof(uintptr_t));
    task_create(&c, consumer, NULL);
    for(i = 0; i < PRODUCERS; ++i) {
        task_create(&p[i], producer, (void*)(uintptr_t)i + 1);
    }
    
    system_start();
    queue_destroy(&q);

    return 0;
}

