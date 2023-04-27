#ifndef _UDRV_WDT_H_
#define _UDRV_WDT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define UDRV_WDT_FEED_PERIOD     8*1000

void udrv_wdt_feed(void);

void udrv_wdt_init(uint32_t period);

#ifdef __cplusplus
}
#endif

#endif  // #ifndef _UDRV_WDT_H_
