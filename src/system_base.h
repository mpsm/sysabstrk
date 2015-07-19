#ifndef __SYSTEM_BASE_H__
#define __SYSTEM_BASE_H__

#if defined(HAVE_CONFIG_H)
#  include "config.h"
#endif /* defined(HAVE_CONFIG_H) */
#include "system_config.h"

#include <stdint.h>
#include <stdbool.h>

/* type definitions */
typedef uint32_t system_tick_t;

#define SYSTEM_NO_WAIT                  ((uint32_t)0)
#define SYSTEM_MAX_WAIT                 (UINT32_MAX)

#endif /* __SYSTEM_BASE_H__ */
