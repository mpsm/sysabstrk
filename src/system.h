#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#if defined(HAVE_CONFIG_H)
#  include "config.h"
#endif /* defined(HAVE_CONFIG_H) */
#include "system-config.h"

#include <stdint.h>
#include <stdbool.h>

/* type definitions */
typedef uint32_t system_tick_t;

/* public methods */
void system_init(void);
bool system_start(void);

#endif /* __SYSTEM_H__ */
