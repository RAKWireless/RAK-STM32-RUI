#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* Includes ------------------------------------------------------------------*/
#include "stm32wlxx_ll_rcc.h"
#include "stm32wlxx_ll_bus.h"
#include "stm32wlxx_ll_system.h"
#include "stm32wlxx_ll_exti.h"
#include "stm32wlxx_ll_cortex.h"
#include "stm32wlxx_ll_utils.h"
#include "stm32wlxx_ll_pwr.h"
#include "stm32wlxx_ll_dma.h"
#include "stm32wlxx_ll_rng.h"
#include "stm32wlxx_ll_gpio.h"

#include "uhal_trng.h"
#include "udrv_errno.h"

#if (USE_TIMEOUT == 1)
#define RNG_GENERATION_TIMEOUT   20
#endif /* USE_TIMEOUT */

/**
  * @brief RNG Initialization Function
  * @param None
  * @retval None
  */
static void MX_RNG_Init(void)
{

    /* USER CODE BEGIN RNG_Init 0 */

    /* USER CODE END RNG_Init 0 */

    LL_RCC_SetRNGClockSource(LL_RCC_RNG_CLKSOURCE_PLL);

    /* Peripheral clock enable */
    LL_AHB3_GRP1_EnableClock(LL_AHB3_GRP1_PERIPH_RNG);

    /* USER CODE BEGIN RNG_Init 1 */

    /* USER CODE END RNG_Init 1 */
    LL_RNG_Enable(RNG);
    /* USER CODE BEGIN RNG_Init 2 */

    /* USER CODE END RNG_Init 2 */

}

void uhal_trng_init(void)
{
    LL_RCC_PLL_ConfigDomain_RNG(LL_RCC_PLLSOURCE_MSI, LL_RCC_PLLM_DIV_4, 8, LL_RCC_PLLQ_DIV_2);
    LL_RCC_PLL_EnableDomain_RNG();
    LL_RCC_PLL_Enable();

    /* Wait till PLL is ready */
    while(LL_RCC_PLL_IsReady() != 1)
    {
    }
    
    MX_RNG_Init();
}

void uhal_trng_get_values(uint8_t *output, uint32_t length)
{
    /* Initialize random numbers generation */
    LL_RNG_Enable(RNG);

    /* Generate Random 32bit Numbers */
    int index = length/4;
    
    while(index--)
    {
        #if (USE_TIMEOUT == 1)
        Timeout = RNG_GENERATION_TIMEOUT;
        #endif /* USE_TIMEOUT */

        /* Wait for DRDY flag to be raised */
        while (!LL_RNG_IsActiveFlag_DRDY(RNG))
        {
            #if (USE_TIMEOUT == 1)
                /* Check Systick counter flag to decrement the time-out value */
                if (LL_SYSTICK_IsActiveCounterFlag()) 
                { 
                if(Timeout-- == 0)
                {
                    /* Time-out occurred. Set LED to blinking mode */
                    LED_Blinking(LED_BLINK_SLOW);
                }
                } 
            #endif /* USE_TIMEOUT */
        }

        /* Check if error occurs */
        if (   (LL_RNG_IsActiveFlag_CECS(RNG) )
            || (LL_RNG_IsActiveFlag_SECS(RNG))  )
        {
            /* Clock or Seed Error detected. Set LED to blinking mode (Error type)*/
            NVIC_SystemReset();
        }

        /* Otherwise, no error detected : Value of generated random number could be retrieved
            and stored in dedicated array */
        uint32_t rng = LL_RNG_ReadRandData32(RNG);
        memcpy(output, &rng, sizeof(rng));

        output += 4;
        length -= 4;
    }

    if(length != 0)
    {
        #if (USE_TIMEOUT == 1)
        Timeout = RNG_GENERATION_TIMEOUT;
        #endif /* USE_TIMEOUT */

        /* Wait for DRDY flag to be raised */
        while (!LL_RNG_IsActiveFlag_DRDY(RNG))
        {
            #if (USE_TIMEOUT == 1)
                /* Check Systick counter flag to decrement the time-out value */
                if (LL_SYSTICK_IsActiveCounterFlag()) 
                { 
                if(Timeout-- == 0)
                {
                    /* Time-out occurred. Set LED to blinking mode */
                    LED_Blinking(LED_BLINK_SLOW);
                }
                } 
            #endif /* USE_TIMEOUT */
        }

        /* Check if error occurs */
        if (   (LL_RNG_IsActiveFlag_CECS(RNG) )
            || (LL_RNG_IsActiveFlag_SECS(RNG))  )
        {
            /* Clock or Seed Error detected. Set LED to blinking mode (Error type)*/
            NVIC_SystemReset();
        }

        /* Otherwise, no error detected : Value of generated random number could be retrieved
            and stored in dedicated array */
        uint32_t rng = LL_RNG_ReadRandData32(RNG);
        memcpy(output, &rng, length);
    }

    /* Stop random numbers generation */
    LL_RNG_Disable(RNG);
}
