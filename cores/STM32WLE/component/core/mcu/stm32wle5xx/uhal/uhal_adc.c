#include "uhal_adc.h"
#include "variant.h"
ADC_HandleTypeDef hadc;

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
            break;
        //PB4-->ADC2
        case PB4:
            sConfig.Channel = ADC_CHANNEL_3;
            break;
        //PB2-->ADC3
        case PB2:
            sConfig.Channel = ADC_CHANNEL_4;
            break;
        //PA10-->ADC4
        case PA10:
            sConfig.Channel = ADC_CHANNEL_6;
            break;
        //PA15-->ADC5
        case PA15:
            sConfig.Channel = ADC_CHANNEL_11;
            break;
        case 255:
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

