#include "board.h"
#include "stm32wlxx_hal.h"

void BoardGetUniqueId(uint8_t *id)
{
    //service_lora_get_dev_eui(id, 8);
}

void BoardCriticalSectionBegin(uint32_t *mask)
{
    uhal_sys_board_critical_section_begin(mask);
}

void BoardCriticalSectionEnd(uint32_t *mask)
{
    uhal_sys_board_critical_section_end(mask);
}

void BoardInitMcu(void)
{
}
