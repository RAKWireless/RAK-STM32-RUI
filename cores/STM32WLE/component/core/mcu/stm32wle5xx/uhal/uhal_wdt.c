#include "uhal_wdt.h"

#define IWDG_WINDOW   0xFFF
#define IWDG_RELOAD   0xFFF

IWDG_HandleTypeDef hiwdg;

static uint32_t IwdgStatus = 0;

static uint32_t WaitingDelay = 0;

void uhal_wdt_feed(void)
{
    if (HAL_IWDG_Refresh(&hiwdg) != HAL_OK) {
        Error_Handler();
    }
}

/**
 * @brief WDT events handler.
 */
void uhal_wdt_event_handler(void)
{
//No use for stm32
}

void uhal_wdt_timer_handler(void * p_context)
{
//No use for stm32
    uhal_wdt_feed();
}

void uhal_wdt_init(void)
{
    /*Check if the system has resumed from WWDG reset*/
    if (__HAL_RCC_GET_FLAG(RCC_FLAG_IWDGRST) != 0x00u)
    {
      /* WWDGRST flag set*/
      IwdgStatus = 1;
  
    }
  
    /* Clear reset flags in any case */
    __HAL_RCC_CLEAR_RESET_FLAGS();
    IwdgStatus = 0;
  
    /*WWDG init*/
    hiwdg.Instance = IWDG;
    hiwdg.Init.Prescaler = IWDG_PRESCALER_256;
    hiwdg.Init.Window = IWDG_WINDOW; // 32768 ms
    hiwdg.Init.Reload = IWDG_RELOAD; // 32768 ms
    if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
    {
      Error_Handler();
    }

}


