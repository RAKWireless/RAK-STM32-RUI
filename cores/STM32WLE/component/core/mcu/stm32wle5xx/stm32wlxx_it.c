/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    UART/UART_ReceptionToIdle_CircularDMA/Src/stm32wlxx_it.c
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
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
#ifdef SUPPORT_MULTITASK
#include "uhal_sched.h"

extern tcb_ thread_pool[THREAD_POOL_SIZE];
extern tcb_ *run_queue;
extern tcb_ *current_thread;
extern tcb_ *next_thread;

extern volatile unsigned long int total_tasks;
extern unsigned long int current_sp;
extern unsigned long int next_sp;
extern bool sched_start;
extern bool sched_pending;
#endif

/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32wlxx_it.h"
#include "uhal_uart.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern SUBGHZ_HandleTypeDef hsubghz;
extern RTC_HandleTypeDef hrtc;
extern ADC_HandleTypeDef hadc;

extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_rx;

extern DMA_HandleTypeDef hdma_spi1_tx;
extern DMA_HandleTypeDef hdma_spi1_rx;

extern UART_HandleTypeDef hlpuart1;
extern DMA_HandleTypeDef hdma_lpuart1_rx;
extern I2C_HandleTypeDef hi2c2;
extern CRYP_HandleTypeDef hcryp;


static void USER_UART_IRQHandler(UART_HandleTypeDef *huart);
/******************************************************************************/
/*           Cortex Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
uint8_t Switch_timer=1;
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
    __HAL_RCC_APB1_FORCE_RESET();
  __HAL_RCC_APB1_RELEASE_RESET();

  __HAL_RCC_APB2_FORCE_RESET();
  __HAL_RCC_APB2_RELEASE_RESET();

  __HAL_RCC_APB3_FORCE_RESET();
  __HAL_RCC_APB3_RELEASE_RESET();

  __HAL_RCC_AHB1_FORCE_RESET();
  __HAL_RCC_AHB1_RELEASE_RESET();

  __HAL_RCC_AHB2_FORCE_RESET();
  __HAL_RCC_AHB2_RELEASE_RESET();

  __HAL_RCC_AHB3_FORCE_RESET();
  __HAL_RCC_AHB3_RELEASE_RESET();

  __HAL_RCC_SUBGHZ_FORCE_RESET();
  __HAL_RCC_SUBGHZ_RELEASE_RESET();

  __HAL_RCC_BACKUPRESET_FORCE();
  __HAL_RCC_BACKUPRESET_RELEASE();
NVIC_SystemReset();
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  __HAL_RCC_APB1_FORCE_RESET();
  __HAL_RCC_APB1_RELEASE_RESET();

  __HAL_RCC_APB2_FORCE_RESET();
  __HAL_RCC_APB2_RELEASE_RESET();

  __HAL_RCC_APB3_FORCE_RESET();
  __HAL_RCC_APB3_RELEASE_RESET();

  __HAL_RCC_AHB1_FORCE_RESET();
  __HAL_RCC_AHB1_RELEASE_RESET();

  __HAL_RCC_AHB2_FORCE_RESET();
  __HAL_RCC_AHB2_RELEASE_RESET();

  __HAL_RCC_AHB3_FORCE_RESET();
  __HAL_RCC_AHB3_RELEASE_RESET();

  __HAL_RCC_SUBGHZ_FORCE_RESET();
  __HAL_RCC_SUBGHZ_RELEASE_RESET();

  __HAL_RCC_BACKUPRESET_FORCE();
  __HAL_RCC_BACKUPRESET_RELEASE();

  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
__attribute__((naked)) void PendSV_Handler(void)
{
#ifdef SUPPORT_MULTITASK
    if (sched_start == false || sched_pending == true) {
        __asm("BX LR");
    }
    /* USER CODE BEGIN PendSV_IRQn 0 */
    __asm("CPSID I");
    __asm("PUSH  {r4-r11}");

    if (current_thread == NULL) {
        current_thread = run_queue;
        current_sp = (unsigned long int)(current_thread->sp);
        __asm("LDR R10, =current_sp");
        __asm("LDR SP,[R10,#0x00]");
        __asm("POP {R4-R11}");
        //if (total_tasks == 1) {
            //sched_start = false;
        //}
        __asm("CPSIE I");
        __asm("BX LR");
    }

    if (current_thread->next == NULL) {
        next_thread = run_queue;
    } else {
        next_thread = current_thread->next;
    }

    current_sp = (unsigned long int)&current_thread->sp;
    __asm("LDR r10, =current_sp");
    __asm("LDR r11, [r10]");
    __asm("STR sp,[r11,#0x00]");

    next_sp = (unsigned long int)(next_thread->sp);
    __asm("LDR r10, =next_sp");
    __asm("LDR sp,[r10,#0x00]");
    current_thread = next_thread;

    __asm("POP {r4-r11}");
    __asm("CPSIE I");
    __asm("BX LR");
#endif
}

#ifdef SUPPORT_MULTITASK
static void set_pendsv() {
	// Set the 28th Bit to trigger PendSV interrupt
	*(unsigned long int volatile *)0xE000ED04 = (1U << 28);
}
#endif

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */
  HAL_IncTick();
#ifdef SUPPORT_MULTITASK
  Switch_timer++;
  if (sched_start == true && Switch_timer % 20 ==0) {
    set_pendsv();
    Switch_timer=1;
  }
#endif

  /* USER CODE END SysTick_IRQn 0 */
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}



void RTC_Alarm_IRQHandler(void)
{
  /* USER CODE BEGIN RTC_Alarm_IRQn 0 */

  /* USER CODE END RTC_Alarm_IRQn 0 */
  HAL_RTC_AlarmIRQHandler(&hrtc);
  /* USER CODE BEGIN RTC_Alarm_IRQn 1 */

  /* USER CODE END RTC_Alarm_IRQn 1 */
}


void SUBGHZ_Radio_IRQHandler(void)
{
  /* USER CODE BEGIN SUBGHZ_Radio_IRQn 0 */

  /* USER CODE END SUBGHZ_Radio_IRQn 0 */
  HAL_SUBGHZ_IRQHandler(&hsubghz);
  /* USER CODE BEGIN SUBGHZ_Radio_IRQn 1 */

  /* USER CODE END SUBGHZ_Radio_IRQn 1 */
}


void TAMP_STAMP_LSECSS_SSRU_IRQHandler(void)
{
  /* USER CODE BEGIN TAMP_STAMP_LSECSS_SSRU_IRQn 0 */

  /* USER CODE END TAMP_STAMP_LSECSS_SSRU_IRQn 0 */
  HAL_RTCEx_SSRUIRQHandler(&hrtc);
  /* USER CODE BEGIN TAMP_STAMP_LSECSS_SSRU_IRQn 1 */

  /* USER CODE END TAMP_STAMP_LSECSS_SSRU_IRQn 1 */
}

/******************************************************************************/
/* STM32WLxx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32wlxx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 Channel 1 Interrupt.
  */
void DMA1_Channel1_IRQHandler(void)
{
  
  /* USER CODE BEGIN DMA1_Channel1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_lpuart1_rx);
  /* USER CODE END DMA1_Channel1_IRQn 0 */
  /* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

  /* USER CODE END DMA1_Channel1_IRQn 1 */
}

void DMA1_Channel2_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_spi1_rx);
}
void DMA1_Channel3_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_spi1_tx);
}

/**
  * @brief This function handles USART2 Interrupt.
  */
void DMA1_Channel4_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_usart1_rx);
}

void USART1_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart1);
  USER_UART_IRQHandler(&huart1);  
}

void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */

  /* USER CODE END USART2_IRQn 0 */
  /* USER CODE BEGIN USART2_IRQn 1 */

  /* USER CODE END USART2_IRQn 1 */
}

void EXTI0_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void EXTI1_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
}

void EXTI2_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
}

void EXTI3_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
}

void EXTI4_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void EXTI9_5_IRQHandler(void)
{
    if (EXTI->PR1 & (GPIO_PIN_5)) {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
    } else if (EXTI->PR1 & (GPIO_PIN_6)) {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
    } else if (EXTI->PR1 & (GPIO_PIN_7)) {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
    } else if (EXTI->PR1 & (GPIO_PIN_8)) {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
    } else if (EXTI->PR1 & (GPIO_PIN_9)) {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
    }
}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI->PR1 & (GPIO_PIN_10)) {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
    } else if (EXTI->PR1 & (GPIO_PIN_11)) {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
    } else if (EXTI->PR1 & (GPIO_PIN_12)) {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
    } else if (EXTI->PR1 & (GPIO_PIN_13)) {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
    } else if (EXTI->PR1 & (GPIO_PIN_14)) {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
    } else if (EXTI->PR1 & (GPIO_PIN_15)) {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
    }
}

void ADCx_IRQHandler(void)
{
  HAL_ADC_IRQHanlder(&hadc);
}

void LPUART1_IRQHandler(void)
{
  HAL_UART_IRQHandler(&hlpuart1);
  USER_UART_IRQHandler(&hlpuart1);  
}

void USER_UART_IRQHandler(UART_HandleTypeDef *huart)
{
    if(LPUART1 == huart->Instance)                                   
    {
        if(RESET != __HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE) )   
        {
            __HAL_UART_CLEAR_IDLEFLAG(huart);                    
         
            USAR_UART_IDLECallback(huart);                          
        }
    }
    else if((USART1 == huart->Instance))
    {
        if(RESET != __HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE) )   
        {
            __HAL_UART_CLEAR_IDLEFLAG(huart);                    
         
            USAR_UART_IDLECallback(huart);                          
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

void AES_IRQHandler(void)
{
  /* USER CODE BEGIN AES_IRQn 0 */

  /* USER CODE END AES_IRQn 0 */
  HAL_CRYP_IRQHandler(&hcryp);
  /* USER CODE BEGIN AES_IRQn 1 */

  /* USER CODE END AES_IRQn 1 */
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
