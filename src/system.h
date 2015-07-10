#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <stdint.h>

/* type definitions */
typedef uint32_t system_tick_t;

/* public methods */
void system_init(void);
void system_start(void);

#endif /* __SYSTEM_H__ */
