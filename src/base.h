#ifndef __SYSTEM_BASE_H__
#define __SYSTEM_BASE_H__

#if defined(HAVE_CONFIG_H)
#  include "config.h"
#endif /* defined(HAVE_CONFIG_H) */

#if !defined(SYSTEM_CONFIG_TICKS_1S)
#  define SYSTEM_CONFIG_TICKS_1S                  (1000)
#endif

#if !defined(SYSTEM_CONFIG_MAX_TASKS)
#  define SYSTEM_CONFIG_MAX_TASKS                 (10)
#endif

#include <stdint.h>
#include <stdbool.h>

/* type definitions */
typedef uint32_t system_tick_t;

#define SYSTEM_NO_WAIT                  ((uint32_t)0)
#define SYSTEM_MAX_WAIT                 (UINT32_MAX)

#endif /* __SYSTEM_BASE_H__ */
