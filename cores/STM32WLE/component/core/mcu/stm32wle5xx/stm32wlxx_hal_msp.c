/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : stm32l5xx_hal_msp.c
  * Description        : This file provides code for the MSP Initialization
  *                      and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "uhal_gpio.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern DMA_HandleTypeDef hdma_spi1_tx;

extern DMA_HandleTypeDef hdma_spi1_rx;

extern DMA_HandleTypeDef hdma_lpuart1_rx;

extern DMA_HandleTypeDef hdma_usart1_rx;

extern UART_HandleTypeDef huart1;

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
* @brief UART MSP Initialization
* This function configures the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  if (huart->Instance==USART1) {
  /** Initializes the peripherals clocks
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    PeriphClkInitStruct.Usart1ClockSelection = RCC_USART1CLKSOURCE_HSI;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    if(PinToGPIOx(UART1_TXD_PIN) == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
    } else if (PinToGPIOx(UART1_TXD_PIN) == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    }
    /**USART1 GPIO Configuration
    PB7     ------> USART1_RX
    PB6     ------> USART1_TX
    */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    if(huart1.AdvancedInit.AdvFeatureInit == UART_ADVFEATURE_SWAP_INIT)
    {
        GPIO_InitStruct.Pin = PinToGPIO_Pin(UART1_RXD_PIN);
        GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    }
    else
    {
        GPIO_InitStruct.Pin = PinToGPIO_Pin(UART1_TXD_PIN) | PinToGPIO_Pin(UART1_RXD_PIN);
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    }
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


    hdma_usart1_rx.Instance = DMA1_Channel4;
    hdma_usart1_rx.Init.Request = DMA_REQUEST_USART1_RX;
    hdma_usart1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart1_rx.Init.Mode = DMA_NORMAL;
    hdma_usart1_rx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_usart1_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(huart,hdmarx,hdma_usart1_rx);
    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  }
  else if(huart->Instance==LPUART1)
  {
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LPUART1;
    if(huart->Init.BaudRate <= 2400)
    {
      PeriphClkInitStruct.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_LSE;
    }
    else
    {
      PeriphClkInitStruct.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_HSI;
    }
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_LPUART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**LPUART1 GPIO Configuration
    PA2     ------> UART2_TX
    PA3     ------> UART2_RX
    */
    GPIO_InitStruct.Pin = PinToGPIO_Pin(UART2_TXD_PIN)|PinToGPIO_Pin(UART2_RXD_PIN);
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_LPUART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* LPUART1 DMA Init */
    /* LPUART1_RX Init */
    hdma_lpuart1_rx.Instance = DMA1_Channel1;
    hdma_lpuart1_rx.Init.Request = DMA_REQUEST_LPUART1_RX;
    hdma_lpuart1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_lpuart1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_lpuart1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_lpuart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_lpuart1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_lpuart1_rx.Init.Mode = DMA_CIRCULAR;
    hdma_lpuart1_rx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_lpuart1_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(huart,hdmarx,hdma_lpuart1_rx);

    // /* LPUART1 interrupt Init */
    HAL_NVIC_SetPriority(LPUART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(LPUART1_IRQn);
  }
}

/**
* @brief UART MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
  if (huart->Instance==USART1) {
    /* Peripheral clock disable */

    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PB7     ------> USART1_RX
    PB6     ------> USART1_TX
    */
    HAL_GPIO_DeInit(PinToGPIOx(UART1_TXD_PIN), PinToGPIO_Pin(UART1_TXD_PIN) | PinToGPIO_Pin(UART1_RXD_PIN));

    /* USART1 DMA DeInit */
    HAL_DMA_DeInit(huart->hdmarx);

    /* USART1 interrupt DeInit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  } 
  else if(huart->Instance==LPUART1)
  {
    /* Peripheral clock disable */
    __HAL_RCC_LPUART1_CLK_DISABLE();

    /**LPUART1 GPIO Configuration
    PA2     ------> LPUART1_TX
    PA3     ------> LPUART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* LPUART1 DMA DeInit */
    HAL_DMA_DeInit(huart->hdmatx);

    /* LPUART1 interrupt DeInit */
    HAL_NVIC_DisableIRQ(LPUART1_IRQn);
  }

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

/**
* @brief RTC MSP Initialization
* This function configures the hardware resources used in this example
* @param hrtc: RTC handle pointer
* @retval None
*/
void HAL_RTC_MspInit(RTC_HandleTypeDef* hrtc)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(hrtc->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspInit 0 */
  /* USER CODE END RTC_MspInit 0 */
  /** Initializes the peripherals clocks
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;

    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_RTC_ENABLE();
    __HAL_RCC_RTCAPB_CLK_ENABLE();
    /* RTC interrupt Init */
    HAL_NVIC_SetPriority(TAMP_STAMP_LSECSS_SSRU_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TAMP_STAMP_LSECSS_SSRU_IRQn);
    HAL_NVIC_SetPriority(RTC_Alarm_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(RTC_Alarm_IRQn);
  /* USER CODE BEGIN RTC_MspInit 1 */

  /* USER CODE END RTC_MspInit 1 */
  }

}

/**
* @brief RTC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hrtc: RTC handle pointer
* @retval None
*/
void HAL_RTC_MspDeInit(RTC_HandleTypeDef* hrtc)
{
  if(hrtc->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspDeInit 0 */

  /* USER CODE END RTC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_RTC_DISABLE();
    __HAL_RCC_RTCAPB_CLK_DISABLE();

    /* RTC interrupt DeInit */
    HAL_NVIC_DisableIRQ(TAMP_STAMP_LSECSS_SSRU_IRQn);
    HAL_NVIC_DisableIRQ(RTC_Alarm_IRQn);
  /* USER CODE BEGIN RTC_MspDeInit 1 */

  /* USER CODE END RTC_MspDeInit 1 */
  }

}

#ifdef HAL_SPI_MODULE_ENABLED
void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hspi->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspInit 0 */

  /* USER CODE END SPI1_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_SPI1_CLK_ENABLE();

    if(PinToGPIOx(SPIM1_SCK) == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
    } else if (PinToGPIOx(SPIM1_SCK) == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    }

    /**SPI1 GPIO Configuration
    PA6     ------> SPI1_MISO
    PA7     ------> SPI1_MOSI
    PA5     ------> SPI1_SCK
    PA4     ------> SPI1_NSS
    */

    GPIO_InitStruct.Pin = PinToGPIO_Pin(SPIM1_SCK) | PinToGPIO_Pin(SPIM1_MISO);
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(PinToGPIOx(SPIM1_SCK), &GPIO_InitStruct);

    GPIO_InitStruct.Pin = PinToGPIO_Pin(SPIM1_MOSI);
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(PinToGPIOx(SPIM1_MOSI), &GPIO_InitStruct);

    /* SPI1 DMA Init */
    /* SPI1_TX Init */
    hdma_spi1_tx.Instance = DMA1_Channel3;
    hdma_spi1_tx.Init.Request = DMA_REQUEST_SPI1_TX;
    hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_spi1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_tx.Init.Mode = DMA_NORMAL;
    hdma_spi1_tx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_spi1_tx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(hspi,hdmatx,hdma_spi1_tx);

    /* SPI1_RX Init */
    hdma_spi1_rx.Instance = DMA1_Channel2;
    hdma_spi1_rx.Init.Request = DMA_REQUEST_SPI1_RX;
    hdma_spi1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_spi1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_rx.Init.Mode = DMA_NORMAL;
    hdma_spi1_rx.Init.Priority = DMA_PRIORITY_HIGH;
    if (HAL_DMA_Init(&hdma_spi1_rx) != HAL_OK)
    {
      Error_Handler();
    }
    __HAL_LINKDMA(hspi,hdmarx,hdma_spi1_rx);
  }
}
#endif

void HAL_SPI_MspDeInit(SPI_HandleTypeDef* hspi)
{
  if(hspi->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspDeInit 0 */
    /* Reset peripherals */
    __HAL_RCC_SPI1_FORCE_RESET();
    __HAL_RCC_SPI1_RELEASE_RESET();

  /* USER CODE END SPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI1_CLK_DISABLE();

    /**SPI1 GPIO Configuration
    PA6     ------> SPI1_MISO
    PA7     ------> SPI1_MOSI
    PA5     ------> SPI1_SCK
    */
    HAL_GPIO_DeInit(PinToGPIOx(SPIM1_SCK), PinToGPIO_Pin(SPIM1_SCK) | PinToGPIO_Pin(SPIM1_MISO) | PinToGPIO_Pin(SPIM1_MOSI));

    /* SPI1 DMA DeInit */
    HAL_DMA_DeInit(hspi->hdmatx);
    HAL_DMA_DeInit(hspi->hdmarx);
  /* USER CODE BEGIN SPI1_MspDeInit 1 */

  /* USER CODE END SPI1_MspDeInit 1 */
  }

}

#if 0 //Define in uhal_adc.c
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
    if(PinToGPIOx(_ADC1) == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
    } else if (PinToGPIOx(_ADC1) == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    }

    //ADC2
    if(PinToGPIOx(_ADC2) == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
    } else if (PinToGPIOx(_ADC2) == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    }

    //ADC3
    if(PinToGPIOx(_ADC3) == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
    } else if (PinToGPIOx(_ADC3) == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    }
    
    //ADC4
    if(PinToGPIOx(_ADC4) == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
    } else if (PinToGPIOx(_ADC4) == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    }

    //ADC5
    if(PinToGPIOx(_ADC5) == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
    } else if (PinToGPIOx(_ADC5) == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE();
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
    GPIO_InitStruct.Pin = PinToGPIO_Pin(_ADC1);
    HAL_GPIO_Init(PinToGPIOx(_ADC1), &GPIO_InitStruct);

    //ADC2
    GPIO_InitStruct.Pin = PinToGPIO_Pin(_ADC2);
    HAL_GPIO_Init(PinToGPIOx(_ADC2), &GPIO_InitStruct);

    //ADC3
    GPIO_InitStruct.Pin = PinToGPIO_Pin(_ADC3);
    HAL_GPIO_Init(PinToGPIOx(_ADC3), &GPIO_InitStruct);

    //ADC4
    GPIO_InitStruct.Pin = PinToGPIO_Pin(_ADC4);
    HAL_GPIO_Init(PinToGPIOx(_ADC4), &GPIO_InitStruct);

    //ADC5
    GPIO_InitStruct.Pin = PinToGPIO_Pin(_ADC5);
    HAL_GPIO_Init(PinToGPIOx(_ADC5), &GPIO_InitStruct);

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
    HAL_GPIO_DeInit(PinToGPIOx(_ADC1), PinToGPIO_Pin(_ADC1));
    HAL_GPIO_DeInit(PinToGPIOx(_ADC2), PinToGPIO_Pin(_ADC2));
    HAL_GPIO_DeInit(PinToGPIOx(_ADC3), PinToGPIO_Pin(_ADC3));
    HAL_GPIO_DeInit(PinToGPIOx(_ADC4), PinToGPIO_Pin(_ADC4));
    HAL_GPIO_DeInit(PinToGPIOx(_ADC5), PinToGPIO_Pin(_ADC5));

  /* USER CODE BEGIN ADC_MspDeInit 1 */

  /* USER CODE END ADC_MspDeInit 1 */
  }

}
#endif

/**
* @brief TIM_PWM MSP Initialization
* This function configures the hardware resources used in this example
* @param htim_pwm: TIM_PWM handle pointer
* @retval None
*/
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm)
{
  if(htim_pwm->Instance==TIM1)
  {
    /* Peripheral clock enable */
    __HAL_RCC_TIM1_CLK_ENABLE();
  } else if (htim_pwm->Instance==TIM2) {
    /* Peripheral clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();
  }
}

/**
* @brief TIM_PWM MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param htim_pwm: TIM_PWM handle pointer
* @retval None
*/
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef* htim_pwm)
{
  if(htim_pwm->Instance==TIM1)
  {
    /* Peripheral clock disable */
    __HAL_RCC_TIM1_CLK_DISABLE();
  } else if (htim_pwm->Instance==TIM2) {
    /* Peripheral clock disable */
    __HAL_RCC_TIM2_CLK_DISABLE();
  }

}


void HAL_CRYP_MspInit(CRYP_HandleTypeDef* hcryp)
{
  if(hcryp->Instance==AES)
  {
  /* USER CODE BEGIN AES_MspInit 0 */

  /* USER CODE END AES_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_AES_CLK_ENABLE();
    /* AES interrupt Init */
    HAL_NVIC_SetPriority(AES_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(AES_IRQn);
  /* USER CODE BEGIN AES_MspInit 1 */
  /* USER CODE END AES_MspInit 1 */
  }

}


void HAL_CRYP_MspDeInit(CRYP_HandleTypeDef* hcryp)
{
  if(hcryp->Instance==AES)
  {
  /* USER CODE BEGIN AES_MspDeInit 0 */

  /* USER CODE END AES_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_AES_CLK_DISABLE();

    /* AES interrupt DeInit */
    HAL_NVIC_DisableIRQ(AES_IRQn);
  /* USER CODE BEGIN AES_MspDeInit 1 */
  /* Disable CRYP Interrupt */
  /* USER CODE END AES_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
