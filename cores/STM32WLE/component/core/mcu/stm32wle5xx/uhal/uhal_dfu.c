#include "uhal_dfu.h"
#include "udrv_flash.h"

void uhal_enter_dfu (void)
{
    uint8_t buff = 0xFF;

    udrv_flash_write(0x08004000, 1, &buff);
    NVIC_SystemReset();
}

