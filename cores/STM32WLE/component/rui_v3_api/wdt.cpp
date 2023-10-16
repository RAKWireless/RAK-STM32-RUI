#include "wdt.h"

bool is_custom_wdt = false;

wdt::wdt() {
}

void wdt::enable(int reset_timer) {
    udrv_wdt_init((uint32_t)reset_timer * 1000);
    is_custom_wdt = true;
}

void wdt::disable(void) {
    is_custom_wdt = true;
}   

void wdt::reset(void) {
    udrv_wdt_feed();
}

