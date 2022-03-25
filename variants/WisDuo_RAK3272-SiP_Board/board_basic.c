#include "board_basic.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "service_battery.h"

batt_level batt_table[] = {
};

uint32_t get_batt_table_size(void) {
    return (sizeof(batt_table)/sizeof(batt_level));
}

