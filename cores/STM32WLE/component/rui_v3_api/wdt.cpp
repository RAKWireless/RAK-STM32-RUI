#include "wdt.h"

wdt::wdt() {
}

void wdt::enable(int reload_value) {
    udrv_wdt_init((uint32_t)reload_value);
}

void wdt::feed(void) {
    udrv_wdt_feed();
}

