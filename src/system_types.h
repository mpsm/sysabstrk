#ifndef __SYSTEM_TYPES_H__
#define __SYSTEM_TYPES_H__

/* TODO: configure different system types */
#include <pthread.h>
typedef pthread_t task_t;
typedef void* (*task_routine_t)(void*);

#endif /* __SYSTEM_TYPES_H__ */
