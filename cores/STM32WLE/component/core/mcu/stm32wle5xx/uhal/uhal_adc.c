#include "uhal_gpio.h"
#include "uhal_adc.h"
#include "variant.h"
ADC_HandleTypeDef hadc;

typedef enum
{
    UHAL_ADC1_ENABLE = 0x01U,   //PB3-->ADC1
    UHAL_ADC2_ENABLE = 0x02U,   //PB4-->ADC2
    UHAL_ADC3_ENABLE = 0x04U,   //PB2-->ADC3
    UHAL_ADC4_ENABLE = 0x08U,   //PA10-->ADC4
    UHAL_ADC5_ENABLE = 0x10U    //PA15-->ADC5
} UHAL_ADC_ENABLEPINTypeDef;
static uint8_t adc_enable_pin = 0x0U;

static uint32_t adc_resolution = ADC_RESOLUTION_10B;
static uint16_t adc_digital_scale = DIGITAL_SCALE_10BITS; 

static UDRV_ADC_RESOLUTION        uhal_adc_resolution = UDRV_ADC_RESOLUTION_10BIT;
static UDRV_ADC_MODE              uhal_adc_mode       = UDRV_ADC_MODE_3_3;

/* Variables for ADC conversion data */
static __IO   uint16_t   uhADCxConvertedData = VAR_CONVERTED_DATA_INIT_VALUE; /* ADC group regular conversion data */

/* Variables for ADC conversion data computation to physical values */
static uint16_t   uhADCxConvertedData_Voltage_mVolt = 0;  /* Value of voltage calculated from ADC conversion data (unit: mV) */

static uint16_t uhal_adc_calc_data_voltage(uint16_t value) 
{
    return  VDDA_APPLI * value / adc_digital_scale;
}

int32_t uhal_adc_read (uint32_t pin, uint16_t *value) {
    ADC_ChannelConfTypeDef sConfig = {0};
    switch (pin) {
        //PB3-->ADC1
        case PB3:
            sConfig.Channel = ADC_CHANNEL_2;
            adc_enable_pin |= UHAL_ADC1_ENABLE;
            break;
        //PB4-->ADC2
        case PB4:
            sConfig.Channel = ADC_CHANNEL_3;
            adc_enable_pin |= UHAL_ADC2_ENABLE;
            break;
        //PB2-->ADC3
        case PB2:
            sConfig.Channel = ADC_CHANNEL_4;
            adc_enable_pin |= UHAL_ADC3_ENABLE;
            break;
        //PA10-->ADC4
        case PA10:
            sConfig.Channel = ADC_CHANNEL_6;
            adc_enable_pin |= UHAL_ADC4_ENABLE;
            break;
        //PA15-->ADC5
        case PA15:
            sConfig.Channel = ADC_CHANNEL_11;
            adc_enable_pin |= UHAL_ADC5_ENABLE;
            break;
        case UDRV_ADC_CHANNEL_TEMPSENSOR:
            sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
            break;
        case UDRV_ADC_CHANNEL_VREFINT:
            sConfig.Channel = ADC_CHANNEL_VREFINT;
            break;
        case UDRV_ADC_CHANNEL_VBAT:
            sConfig.Channel = ADC_CHANNEL_VBAT;
            break;
        default:
            return -UDRV_NACK;

    }
  
    /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
    */
    hadc.Instance = ADC;
    hadc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
    hadc.Init.Resolution = adc_resolution;
    hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    hadc.Init.ScanConvMode = ADC_SCAN_DISABLE;
    hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
    hadc.Init.LowPowerAutoWait = DISABLE;
    hadc.Init.LowPowerAutoPowerOff = DISABLE;
    hadc.Init.ContinuousConvMode = DISABLE;
    hadc.Init.NbrOfConversion = 1;
    hadc.Init.DiscontinuousConvMode = DISABLE;
    hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
    hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    hadc.Init.DMAContinuousRequests = DISABLE;
    hadc.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
    hadc.Init.SamplingTimeCommon1 = ADC_SAMPLETIME_79CYCLES_5;
    hadc.Init.SamplingTimeCommon2 = ADC_SAMPLETIME_1CYCLE_5;
    hadc.Init.OversamplingMode = DISABLE;
    //hadc.Init.Oversampling.Ratio = ADC_OVERSAMPLING_RATIO_16;
    //hadc.Init.Oversampling.RightBitShift = ADC_RIGHTBITSHIFT_4;
    //hadc.Init.Oversampling.TriggeredMode = ADC_TRIGGEREDMODE_SINGLE_TRIGGER;
    hadc.Init.TriggerFrequencyMode = ADC_TRIGGER_FREQ_HIGH;

    if (HAL_ADC_Init(&hadc) != HAL_OK)
    {
      Error_Handler();
    }

    /* Run the ADC calibration in single-ended mode */
    if (HAL_ADCEx_Calibration_Start(&hadc) != HAL_OK)
    {
      /* Calibration Error */
      Error_Handler();
    }

    /** Configure Regular Channel
    */
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;
    if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
    {
      Error_Handler();
    }


    if (HAL_ADC_Start(&hadc) != HAL_OK)
    {
      /* ADC conversion start error */
      Error_Handler();
    }

    HAL_ADC_PollForConversion(&hadc, 10);

    HAL_ADC_Stop(&hadc) ;

    *value = HAL_ADC_GetValue(&hadc);

    if (sConfig.Channel == ADC_CHANNEL_VBAT)
        *value *= 3;


    HAL_ADC_DeInit(&hadc);
    return UDRV_RETURN_OK;
}

void uhal_adc_suspend (void) {
}

void uhal_adc_resume (void) {
}

void uhal_adc_set_resolution (UDRV_ADC_RESOLUTION resolution) {
    switch (resolution) {
        case UDRV_ADC_RESOLUTION_8BIT:
        {
            uhal_adc_resolution = UDRV_ADC_RESOLUTION_8BIT;
            adc_resolution = ADC_RESOLUTION_8B;
            adc_digital_scale = DIGITAL_SCALE_8BITS;
            break;
        }
        case UDRV_ADC_RESOLUTION_10BIT:
        {
            uhal_adc_resolution = UDRV_ADC_RESOLUTION_10BIT;
            adc_resolution = ADC_RESOLUTION_10B;
            adc_digital_scale = DIGITAL_SCALE_10BITS;
            break;
        }
        case UDRV_ADC_RESOLUTION_12BIT:
        case UDRV_ADC_RESOLUTION_14BIT:
        {
            uhal_adc_resolution = UDRV_ADC_RESOLUTION_12BIT;
            adc_resolution = ADC_RESOLUTION_12B;
            adc_digital_scale = DIGITAL_SCALE_12BITS;
            break;
        }
        default:
        {
            uhal_adc_resolution = UDRV_ADC_RESOLUTION_12BIT;
            adc_resolution = ADC_RESOLUTION_12B;
            adc_digital_scale = DIGITAL_SCALE_12BITS;
            break;
        }
    }

}

UDRV_ADC_RESOLUTION uhal_adc_get_resolution (void) {
    return uhal_adc_resolution;
}

void uhal_adc_set_mode (UDRV_ADC_MODE mode) {
    uhal_adc_mode = UDRV_ADC_MODE_3_3;
}

UDRV_ADC_MODE uhal_adc_get_mode (void) {
    return uhal_adc_mode;
}

void uhal_adc_oversampling(uint32_t oversampling)
{
	 //to do
}

/**
* @brief ADC MSP Initialization
* This function configures the hardware resources used in this example
* @param hadc: ADC handle pointer
* @retval None
*/
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hadc->Instance==ADC)
  {
  /* USER CODE BEGIN ADC_MspInit 0 */

  /* USER CODE END ADC_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_ADC_CLK_ENABLE();

    //ADC1
    if (adc_enable_pin & UHAL_ADC1_ENABLE) {
        if(PinToGPIOx(_ADC1) == GPIOA) {
            __HAL_RCC_GPIOA_CLK_ENABLE();
        } else if (PinToGPIOx(_ADC1) == GPIOB) {
            __HAL_RCC_GPIOB_CLK_ENABLE();
        }
    }

    //ADC2
    if (adc_enable_pin & UHAL_ADC2_ENABLE) {
        if(PinToGPIOx(_ADC2) == GPIOA) {
            __HAL_RCC_GPIOA_CLK_ENABLE();
        } else if (PinToGPIOx(_ADC2) == GPIOB) {
            __HAL_RCC_GPIOB_CLK_ENABLE();
        }
    }

    //ADC3
    if (adc_enable_pin & UHAL_ADC3_ENABLE) {
        if(PinToGPIOx(_ADC3) == GPIOA) {
            __HAL_RCC_GPIOA_CLK_ENABLE();
        } else if (PinToGPIOx(_ADC3) == GPIOB) {
            __HAL_RCC_GPIOB_CLK_ENABLE();
        }
    }

    //ADC4
    if (adc_enable_pin & UHAL_ADC4_ENABLE) {
        if(PinToGPIOx(_ADC4) == GPIOA) {
            __HAL_RCC_GPIOA_CLK_ENABLE();
        } else if (PinToGPIOx(_ADC4) == GPIOB) {
            __HAL_RCC_GPIOB_CLK_ENABLE();
        }
    }

    //ADC5
    if (adc_enable_pin & UHAL_ADC5_ENABLE) {
        if(PinToGPIOx(_ADC5) == GPIOA) {
            __HAL_RCC_GPIOA_CLK_ENABLE();
        } else if (PinToGPIOx(_ADC5) == GPIOB) {
            __HAL_RCC_GPIOB_CLK_ENABLE();
        }
    }

    /**ADC GPIO Configuration
    PB3     ------> _ADC1
    PB4     ------> _ADC2
    PB2     ------> _ADC3
    PA10    ------> _ADC4
    PA15    ------> _ADC5
    */
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    //ADC1
    if (adc_enable_pin & UHAL_ADC1_ENABLE) {
        GPIO_InitStruct.Pin = PinToGPIO_Pin(_ADC1);
        HAL_GPIO_Init(PinToGPIOx(_ADC1), &GPIO_InitStruct);
    }

    //ADC2
    if (adc_enable_pin & UHAL_ADC2_ENABLE) {
        GPIO_InitStruct.Pin = PinToGPIO_Pin(_ADC2);
        HAL_GPIO_Init(PinToGPIOx(_ADC2), &GPIO_InitStruct);
    }

    //ADC3
    if (adc_enable_pin & UHAL_ADC3_ENABLE) {
        GPIO_InitStruct.Pin = PinToGPIO_Pin(_ADC3);
        HAL_GPIO_Init(PinToGPIOx(_ADC3), &GPIO_InitStruct);
    }

    //ADC4
    if (adc_enable_pin & UHAL_ADC4_ENABLE) {
        GPIO_InitStruct.Pin = PinToGPIO_Pin(_ADC4);
        HAL_GPIO_Init(PinToGPIOx(_ADC4), &GPIO_InitStruct);
    }

    //ADC5
    if (adc_enable_pin & UHAL_ADC5_ENABLE) {
        GPIO_InitStruct.Pin = PinToGPIO_Pin(_ADC5);
        HAL_GPIO_Init(PinToGPIOx(_ADC5), &GPIO_InitStruct);
    }

  /* USER CODE BEGIN ADC_MspInit 1 */

  /* USER CODE END ADC_MspInit 1 */
  }

}

/**
* @brief ADC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hadc: ADC handle pointer
* @retval None
*/
void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc)
{
  if(hadc->Instance==ADC)
  {
  /* USER CODE BEGIN ADC_MspDeInit 0 */

  /* USER CODE END ADC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC_CLK_DISABLE();

    /**ADC GPIO Configuration
    PB3     ------> _ADC1
    PB4     ------> _ADC2
    PB2     ------> _ADC3
    PA10    ------> _ADC4
    PA15    ------> _ADC5
    */
    if (adc_enable_pin & UHAL_ADC1_ENABLE) {
        HAL_GPIO_DeInit(PinToGPIOx(_ADC1), PinToGPIO_Pin(_ADC1));
        adc_enable_pin &= ~UHAL_ADC1_ENABLE;
    }
    if (adc_enable_pin & UHAL_ADC2_ENABLE) {
        HAL_GPIO_DeInit(PinToGPIOx(_ADC2), PinToGPIO_Pin(_ADC2));
        adc_enable_pin &= ~UHAL_ADC2_ENABLE;
    }
    if (adc_enable_pin & UHAL_ADC3_ENABLE) {
        HAL_GPIO_DeInit(PinToGPIOx(_ADC3), PinToGPIO_Pin(_ADC3));
        adc_enable_pin &= ~UHAL_ADC3_ENABLE;
    }
    if (adc_enable_pin & UHAL_ADC4_ENABLE) {
        HAL_GPIO_DeInit(PinToGPIOx(_ADC4), PinToGPIO_Pin(_ADC4));
        adc_enable_pin &= ~UHAL_ADC4_ENABLE;
    }
    if (adc_enable_pin & UHAL_ADC5_ENABLE) {
        HAL_GPIO_DeInit(PinToGPIOx(_ADC5), PinToGPIO_Pin(_ADC5));
        adc_enable_pin &= ~UHAL_ADC5_ENABLE;
    }

  /* USER CODE BEGIN ADC_MspDeInit 1 */

  /* USER CODE END ADC_MspDeInit 1 */
  }

}
