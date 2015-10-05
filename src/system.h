#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <system/base.h>

/* public methods */
void system_init(void);
bool system_start(void);
void system_delay(system_tick_t);

#endif /* __SYSTEM_H__ */
