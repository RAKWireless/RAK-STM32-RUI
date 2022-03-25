#ifndef _UDRV_DELAY_H_
#define _UDRV_DELAY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void udrv_app_delay_ms (uint32_t ms_time);
void udrv_app_delay_us (uint32_t us_time);
void udrv_delay_ms (uint32_t ms_time);
void udrv_delay_us (uint32_t us_time);

#ifdef __cplusplus
}
#endif

#endif  // #ifndef _UDRV_DELAY_H_
