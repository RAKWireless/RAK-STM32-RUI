#include "board.h"
#include "stm32wlxx_hal.h"

void BoardGetUniqueId(uint8_t *id)
{
    //service_lora_get_dev_eui(id, 8);
}

void BoardCriticalSectionBegin(uint32_t *mask)
{
    *mask = __get_PRIMASK();
    __disable_irq();
}

void BoardCriticalSectionEnd(uint32_t *mask)
{
    __set_PRIMASK( *mask );
}

void BoardInitMcu(void)
{
}