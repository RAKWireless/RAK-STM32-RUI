#include <stddef.h>
#include "udrv_wdt.h"
#include "uhal_wdt.h"

void udrv_wdt_feed(void) {
    uhal_wdt_feed();
}

void udrv_wdt_init(uint32_t period) {
    uhal_wdt_init(period);
}
