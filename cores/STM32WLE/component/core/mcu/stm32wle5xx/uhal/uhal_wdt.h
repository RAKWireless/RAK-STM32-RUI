#ifndef _UHAL_WDT_H_
#define _UHAL_WDT_H_

#include "udrv_wdt.h"
#include "stm32wlxx_hal.h"

void uhal_wdt_feed(void);

void uhal_wdt_init(uint32_t period);

#endif
