#ifndef _SERVICE_DEBUG_H_
#define _SERVICE_DEBUG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include<stdint.h>
void service_debug(const char *fmt, ...);
uint32_t service_set_debug_level(uint8_t level);
uint8_t service_get_debug_level(void);
void service_debug_swo(const char *fmt, ...);
#ifdef __cplusplus
}
#endif

#endif  
