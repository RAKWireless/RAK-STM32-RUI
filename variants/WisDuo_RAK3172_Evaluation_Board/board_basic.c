#include "board_basic.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "service_battery.h"

batt_level batt_table[] = {
	{ SERVICE_BATT_3V0, 491}, 
	{ SERVICE_BATT_3V1, 492}, 
	{ SERVICE_BATT_3V2, 494}, 
	{ SERVICE_BATT_3V3, 495}, 
	{ SERVICE_BATT_3V4, 496}, 
	{ SERVICE_BATT_3V5, 504}, 
	{ SERVICE_BATT_3V6, 516}, 
	{ SERVICE_BATT_3V7, 525}, 
	{ SERVICE_BATT_3V8, 534}, 
	{ SERVICE_BATT_3V9, 543}, 
	{ SERVICE_BATT_4V0, 551}, 
	{ SERVICE_BATT_4V1, 560}, 
	{ SERVICE_BATT_4V2, 567}, 
};

uint32_t get_batt_table_size(void) {
    return (sizeof(batt_table)/sizeof(batt_level));
}

