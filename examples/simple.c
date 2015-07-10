#include <system/system.h>
#include <system/task.h>
#include <system/time.h>

#include <stddef.h>
#include <stdio.h>

void* test(void* arg)
{
    while(true) {
        system_delay(500);
        printf("test\n");
    }
}

int main(void)
{
    task_t test_task;
    printf("System abstraction test - POSIX implementation\n");

    task_create(&test_task, test, NULL);

    system_delay(5000);

    return 0;
}
