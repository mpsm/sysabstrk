#include <system/system.h>
#include <system/mutex.h>

#include <FreeRTOS/FreeRTOS.h>
#include <FreeRTOS/task.h>
#include <FreeRTOS/semphr.h>

#include <stdbool.h>
#include <stddef.h>

bool
mutex_init(mutex_t *m)
{
    xSemaphoreHandle handle = xSemaphoreCreateMutex();

    *m = (mutex_t)handle;

    return handle != NULL;
}

bool
mutex_lock(mutex_t m, system_tick_t ticks)
{
    return xSemaphoreTake(*(xSemaphoreHandle *)m, ticks) == pdTRUE;
}

bool
mutex_unlock(mutex_t m)
{
    return xSemaphoreGive(*(xSemaphoreHandle *)m) == pdTRUE;
}
