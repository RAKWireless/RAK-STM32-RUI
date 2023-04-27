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

void uhal_wdt_init(uint32_t period)
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
    hiwdg.Init.Prescaler = IWDG_PRESCALER_64;
    hiwdg.Init.Window = IWDG_WINDOW;
    
    switch(period){
    	case 0x00FA:				//250s
		hiwdg.Init.Reload = 0x007D;
		break;
	case 0x01F4:				//500s
		hiwdg.Init.Reload = 0x00FA;
		break;
	case 0x03E8:				//1000s
		hiwdg.Init.Reload = 0x01F4;
		break;
	case 0x07D0:				//2000s
		hiwdg.Init.Reload = 0x03E8;
		break;
	case 0x0FA0:				//4000s
                hiwdg.Init.Reload = 0x07D0;
		break;
	case 0x1F40:				//8000s
                hiwdg.Init.Reload = 0x0FA0;
		break;
	default:
                hiwdg.Init.Reload = 0x0FA0;
		break;

    }

    if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
    {
      Error_Handler();
    }

}


