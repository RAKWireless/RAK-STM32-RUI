#include "uhal_twimst.h"

/**@brief   Sleep until an event is received. */
static void power_manage(void)
{
#ifndef RUI_BOOTLOADER
    __SEV();
    __WFE();
    __WFE();
#endif
}

#define TWI_TIMEOUT			10000

I2C_HandleTypeDef hi2c2;

typedef struct uhal_twimst_status {
    bool active;
} uhal_twimst_status_t;

static uhal_twimst_status_t twimst_status[UDRV_TWIMST_MAX];

static void twimst_init(udrv_twimst_port port) {
   // __HAL_RCC_GPIOB_CLK_ENABLE();

    hi2c2.Instance = I2C2;
    if (hi2c2.Init.Timing == NULL) {
        hi2c2.Init.Timing = 0x0070085C;
    }
    hi2c2.Init.OwnAddress1 = 0;
    hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c2.Init.OwnAddress2 = 0; 
    hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
    hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    hi2c2.Mode = HAL_I2C_MODE_MASTER;
    if (HAL_I2C_Init(&hi2c2) != HAL_OK)
    { 
        Error_Handler();
    } 
    /** Configure Analogue filter
    */
    if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
    {
      Error_Handler();
    }
    /** Configure Digital filter
    */
    if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
    {
      Error_Handler();
    }
    /** I2C Fast mode Plus enable
    */
    HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_I2C2);
}

void uhal_twimst_init(udrv_twimst_port port) {
    twimst_init(port);

    twimst_status[port].active = true;
}

static void twimst_deinit(udrv_twimst_port port) {
    if (HAL_I2C_DeInit(&hi2c2) != HAL_OK)
    { 
        Error_Handler();
    } 
}

void uhal_twimst_deinit(udrv_twimst_port port) {
    twimst_deinit(port);

    twimst_status[port].active = false;
}

void uhal_twimst_setup_freq(udrv_twimst_port port, uint32_t clk_Hz) {
    if (clk_Hz <= 100000) {
        hi2c2.Init.Timing = 0x10300ADB;
    } else if (clk_Hz <= 250000) {
        hi2c2.Init.Timing = 0x00700D9F;
    } else {
        hi2c2.Init.Timing = 0x0070085C;
    }

    if (hi2c2.Instance != NULL) {
        HAL_I2C_DeInit(&hi2c2);

        if (HAL_I2C_Init(&hi2c2) != HAL_OK)
        { 
            Error_Handler();
        } 
        /** Configure Analogue filter
        */
        if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
        {
          Error_Handler();
        }
        /** Configure Digital filter
        */
        if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
        {
          Error_Handler();
        }
        /** I2C Fast mode Plus enable
        */
        HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_I2C2);
    }
}	

int32_t uhal_twimst_write(udrv_twimst_port port, uint8_t twi_addr, uint8_t *data, uint16_t len, bool send_stop)
{
    uint32_t err_code = 0;
    uint32_t XferOptions;

    if (send_stop) {
        XferOptions = I2C_LAST_FRAME;
    } else {
        XferOptions = I2C_FIRST_FRAME;
    }
    if (HAL_I2C_Master_Seq_Transmit_IT(&hi2c2, twi_addr << 1, data, len, XferOptions) != HAL_OK) {
        return -UDRV_NACK;
    }

    while (HAL_I2C_GetState(&hi2c2) != HAL_I2C_STATE_READY);
    {
        //power_manage();
    }

    if (HAL_I2C_GetError(&hi2c2) == HAL_I2C_ERROR_AF) {
        return -UDRV_NACK;
    }

    return UDRV_RETURN_OK;
}

int32_t uhal_twimst_read(udrv_twimst_port port, uint8_t twi_addr, uint8_t * data, uint16_t len)
{
    uint32_t err_code = 0;

    if (HAL_I2C_Master_Seq_Receive_IT(&hi2c2, twi_addr << 1, data, len, I2C_LAST_FRAME) != HAL_OK) { 
       return -UDRV_NACK;
    }

    while (HAL_I2C_GetState(&hi2c2) != HAL_I2C_STATE_READY)
    {
        //power_manage();
    }

    if (HAL_I2C_GetError(&hi2c2) == HAL_I2C_ERROR_AF) {
        return -UDRV_NACK;
    }

    return UDRV_RETURN_OK;
}

void uhal_twimst_suspend(void)
{
}

void uhal_twimst_resume(void)
{
    for (int i = UDRV_TWIMST_0 ; i < UDRV_TWIMST_MAX ; i++) {
        if (twimst_status[i].active == true) {
            twimst_init(i);
    }
    }
}

void I2C2_EV_IRQHandler(void)
{
    HAL_I2C_EV_IRQHandler(&hi2c2);
}

/**
  * @brief This function handles I2C1 Error Interrupt.
  */
void I2C2_ER_IRQHandler(void)
{
    HAL_I2C_ER_IRQHandler(&hi2c2);
}

/**
* @brief I2C MSP Initialization
* This function configures the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(hi2c->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspInit 0 */

  /* USER CODE END I2C2_MspInit 0 */
  /** Initializes the peripherals clocks
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2C2;
    PeriphClkInitStruct.I2c2ClockSelection = RCC_I2C2CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    if(PinToGPIOx(I2C2_SCL) == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
    } else if (PinToGPIOx(I2C2_SCL) == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    }

    /**I2C2 GPIO Configuration
    PA11     ------> I2C2_SDA
    PA12     ------> I2C2_SCL
    */
    GPIO_InitStruct.Pin = PinToGPIO_Pin(I2C2_SCL) | PinToGPIO_Pin(I2C2_SDA);
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
    HAL_GPIO_Init(PinToGPIOx(I2C2_SCL), &GPIO_InitStruct);

    /* Peripheral clock enable */
    __HAL_RCC_I2C2_CLK_ENABLE();
  /* USER CODE BEGIN I2C2_MspInit 1 */
    HAL_NVIC_SetPriority(I2C2_EV_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(I2C2_EV_IRQn);
    HAL_NVIC_SetPriority(I2C2_ER_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(I2C2_ER_IRQn);

  /* USER CODE END I2C2_MspInit 1 */
  }

}
/**
* @brief I2C MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
{
  if(hi2c->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspDeInit 0 */

  /* USER CODE END I2C2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C2_CLK_DISABLE();

    /**I2C2 GPIO Configuration
    PB7     ------> I2C2_SDA
    PB8     ------> I2C2_SCL
    */
    HAL_GPIO_DeInit(PinToGPIOx(I2C2_SCL), PinToGPIO_Pin(I2C2_SCL) | PinToGPIO_Pin(I2C2_SDA));

    /* I2C1 interrupt DeInit */
    HAL_NVIC_DisableIRQ(I2C2_EV_IRQn);
    HAL_NVIC_DisableIRQ(I2C2_ER_IRQn);
    
  /* USER CODE BEGIN I2C2_MspDeInit 1 */
  
  /* USER CODE END I2C2_MspDeInit 1 */
  }
  
}

