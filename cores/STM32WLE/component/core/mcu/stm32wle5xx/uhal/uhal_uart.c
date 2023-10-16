#include <stdarg.h>
#include "uhal_uart.h"

#define BUFFER_SIZE 128

static void (*CLI_HANDLER)(void *);
static void (*LOCK_HANDLER)(void *);
static void (*WAKEUP_HANDLER)(void *);
static void uhal_uart_dma_lpuart_init(void);
static void uhal_uart_dma_uart1_init(void);
void UserDataTreatment(UART_HandleTypeDef *huart, uint8_t* pData, uint16_t Size);

typedef struct uhal_uart_status
{
    bool active;
    uint32_t baudrate;
    SERIAL_WORD_LEN_E dataBits;
    SERIAL_STOP_BIT_E stopBits;
    SERIAL_PARITY_E parity
} uhal_uart_status_t;

static uhal_uart_status_t uart_status[UHAL_UART_MAX];
static SERIAL_WIRE_MODE_E uart_wire_mode[UHAL_UART_MAX];

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
UART_HandleTypeDef huart1;

UART_HandleTypeDef hlpuart1;

DMA_HandleTypeDef hdma_lpuart1_rx;

uint8_t uart2_charRx,uart1_charRx;

DMA_HandleTypeDef hdma_usart1_rx;

uint8_t lpuart_dma_buff[BUFFER_SIZE];

uint8_t uart1_dma_buff[BUFFER_SIZE];

volatile char LpuartDMAdoing = 0;

//----------------------------------------------------------------
//AT CMD
FUND_CIRCULAR_QUEUE_INIT(uint8_t, SERIAL_UART1_rxq, 512);
FUND_CIRCULAR_QUEUE_INIT(uint8_t, SERIAL_UART2_rxq, 512);

static void (*ONEWIRE_HANDLER) (void *);

#ifndef RUI_BOOTLOADER
extern bool udrv_powersave_in_sleep;
static udrv_system_event_t rui_uart_event = {.request = UDRV_SYS_EVT_OP_SERIAL_UART, .p_context = NULL};
#endif

void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    /* Turn LED3 on */

    //BSP_LED_On(LED3);
    while (1)
    {
        NVIC_SystemReset ();
    }

    /* USER CODE END Error_Handler_Debug */
}

void StartReception(SERIAL_PORT Port)
{
    if (Port == SERIAL_UART1) 
    {
        HAL_UART_Receive_DMA(&huart1, (uint8_t*)uart1_dma_buff, BUFFER_SIZE);  
	    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
    }
    if (Port == SERIAL_UART2)
    {
        HAL_UART_Receive_DMA(&hlpuart1, (uint8_t*)lpuart_dma_buff, BUFFER_SIZE);  
	    __HAL_UART_ENABLE_IT(&hlpuart1, UART_IT_IDLE);
    }
}

static void uart_init(SERIAL_PORT port, uint32_t baudrate, SERIAL_WORD_LEN_E datalen,SERIAL_STOP_BIT_E stop,
SERIAL_PARITY_E parity, SERIAL_WIRE_MODE_E WireMode)
{
    //service_debug("baudrate %d datalen %d stop %d parity %d\r\n",
    //baudrate,datalen,stop,parity);

    UART_InitTypeDef uart;

    switch (stop)
    {            
        case SERIAL_STOP_BIT_1 : uart.StopBits = UART_STOPBITS_1 ; break;          
        case SERIAL_STOP_BIT_2 : uart.StopBits = UART_STOPBITS_2 ; break;  
        default : uart.StopBits = UART_STOPBITS_1 ; break ;
    }

    switch (parity)
    {            
        case SERIAL_PARITY_DISABLE : uart.Parity = UART_PARITY_NONE ; break;          
        case SERIAL_PARITY_ODD :  uart.Parity = UART_PARITY_ODD ; break;          
        case SERIAL_PARITY_EVEN : uart.Parity = UART_PARITY_EVEN ; break;          
        default : uart.Parity = UART_PARITY_NONE ; break ;
    }

    //If there is parity check, the data length is processed
    if(parity)
    {
        switch (datalen)
        {            
            // Note : N bit + 1 parity = WordLength
            case SERIAL_WORD_LEN_6 : uart.WordLength = UART_WORDLENGTH_7B ; break;         
            case SERIAL_WORD_LEN_7 : uart.WordLength = UART_WORDLENGTH_8B ; break;          
            case SERIAL_WORD_LEN_8 : uart.WordLength = UART_WORDLENGTH_9B ; break;  
            default : uart.WordLength = UART_WORDLENGTH_8B ; break ;
        }
    }
    else
    {
        switch (datalen)
        {            
            case SERIAL_WORD_LEN_7 : uart.WordLength = UART_WORDLENGTH_7B ; break;          
            case SERIAL_WORD_LEN_8 : uart.WordLength = UART_WORDLENGTH_8B ; break;  
            default : uart.WordLength = UART_WORDLENGTH_8B ; break ;
        }
    }

    if (port == SERIAL_UART1) 
    {
        uhal_uart_dma_uart1_init();

        uart_wire_mode[SERIAL_UART1] = WireMode;

        huart1.Instance = USART1;
        huart1.Init.BaudRate = baudrate;
        huart1.Init.WordLength = uart.WordLength;
        huart1.Init.StopBits = uart.StopBits;
        huart1.Init.Parity = uart.Parity;
        huart1.Init.Mode = UART_MODE_TX_RX;
        huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
        huart1.Init.OverSampling = UART_OVERSAMPLING_16;
        huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
        huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
        if(WireMode != SERIAL_TWO_WIRE_NORMAL_MODE)
        {
            huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_SWAP_INIT;
            huart1.AdvancedInit.Swap = UART_ADVFEATURE_SWAP_ENABLE;
            if (HAL_HalfDuplex_Init(&huart1) != HAL_OK)
                Error_Handler();
        }
        else{
            huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
            if (HAL_UART_Init(&huart1) != HAL_OK)
                Error_Handler();
        }
        if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
        {
            Error_Handler();
        }
        if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
        {
            Error_Handler();
        }
        if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
        {
            Error_Handler();
        }
        StartReception(port);
        UART_WakeUpTypeDef WakeUpSelection;
        WakeUpSelection.WakeUpEvent   = UART_WAKEUP_ON_READDATA_NONEMPTY;
        if (HAL_UARTEx_StopModeWakeUpSourceConfig(&huart1, WakeUpSelection) != HAL_OK)
        {
            Error_Handler();
        }

	    __HAL_RCC_WAKEUPSTOP_CLK_CONFIG(RCC_STOP_WAKEUPCLOCK_HSI);

    } 
    else if (port == SERIAL_UART2) {
        
        uart_wire_mode[SERIAL_UART2] = WireMode;

        uhal_uart_dma_lpuart_init();

        hlpuart1.Instance = LPUART1;
        hlpuart1.Init.BaudRate = baudrate;
        hlpuart1.Init.WordLength = uart.WordLength;
        hlpuart1.Init.StopBits = uart.StopBits;
        hlpuart1.Init.Parity = uart.Parity;
        hlpuart1.Init.Mode = UART_MODE_TX_RX;
        hlpuart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
        hlpuart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
        hlpuart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
        hlpuart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
        hlpuart1.FifoMode = UART_FIFOMODE_DISABLE;
        if (HAL_UART_Init(&hlpuart1) != HAL_OK)
        {
            Error_Handler();
        }
        if (HAL_UARTEx_SetTxFifoThreshold(&hlpuart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
        {
            Error_Handler();
        }
        if (HAL_UARTEx_SetRxFifoThreshold(&hlpuart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
        {
            Error_Handler();
        }
        if (HAL_UARTEx_DisableFifoMode(&hlpuart1) != HAL_OK)
        {
            Error_Handler();
        }
        
        StartReception(port);

        UART_WakeUpTypeDef WakeUpSelection;
        WakeUpSelection.WakeUpEvent   = UART_WAKEUP_ON_READDATA_NONEMPTY;
        if (HAL_UARTEx_StopModeWakeUpSourceConfig(&hlpuart1, WakeUpSelection) != HAL_OK)
        {
            Error_Handler();
        }
	 
	    EXTI->IMR1 |= EXTI_IMR1_IM28;
        __HAL_UART_ENABLE_IT(&hlpuart1, UART_IT_WUF);
        //HAL_UARTEx_EnableStopMode(&hlpuart1);
	    __HAL_RCC_WAKEUPSTOP_CLK_CONFIG(RCC_STOP_WAKEUPCLOCK_HSI);
    }
}

static void uart_deinit(SERIAL_PORT port)
{
    if (port == SERIAL_UART2) {
        if (HAL_UART_DeInit(&hlpuart1) != HAL_OK)
        {
            Error_Handler();
        }
    } else if (port == SERIAL_UART1) {
        if (HAL_UART_DeInit(&huart1) != HAL_OK)
        {
            Error_Handler();
        }
    }
}

void uhal_uart_register_onewire_handler (SERIAL_CLI_HANDLER handler)
{
    ONEWIRE_HANDLER = handler;
}

void uhal_uart_register_cli_handler(SERIAL_CLI_HANDLER handler)
{
    CLI_HANDLER = handler;
}

void uhal_uart_register_lock_handler(SERIAL_CLI_HANDLER handler)
{
    LOCK_HANDLER = handler;
}

void uhal_uart_register_wakeup_handler(SERIAL_CLI_HANDLER handler)
{
    WAKEUP_HANDLER = handler;
}

void uhal_uart_init(SERIAL_PORT Port, uint32_t BaudRate, SERIAL_WORD_LEN_E DataBits, SERIAL_STOP_BIT_E StopBits, SERIAL_PARITY_E Parity, SERIAL_WIRE_MODE_E WireMode)
{
    uart_init(Port, BaudRate, DataBits ,StopBits ,Parity, WireMode);

    uart_status[Port].active = true;
    uart_status[Port].baudrate = BaudRate;
    uart_status[Port].dataBits = DataBits;
    uart_status[Port].stopBits = StopBits;
    uart_status[Port].parity = Parity;
    return;
}

void uhal_uart_deinit(SERIAL_PORT Port)
{
    uart_deinit(Port);

    uart_status[Port].active = false;
    return;
}

int32_t uhal_uart_write(SERIAL_PORT Port, uint8_t const *Buffer, int32_t NumberOfBytes, uint32_t Timeout)
{
    uint32_t err_code = HAL_OK;
    if (Port == SERIAL_UART1) {
        
        if(uart_wire_mode[Port] == SERIAL_ONE_WIRE_TX_PIN_MODE || uart_wire_mode[Port] == SERIAL_ONE_WIRE_RX_PIN_MODE)
        {
            HAL_HalfDuplex_EnableTransmitter(&huart1);
            err_code = HAL_UART_Transmit(&huart1, Buffer, NumberOfBytes, Timeout);
            HAL_HalfDuplex_EnableReceiver(&huart1);
        }
        else
            err_code = HAL_UART_Transmit(&huart1, Buffer, NumberOfBytes, Timeout);
    } else if (Port == SERIAL_UART2)
    {
        err_code = HAL_UART_Transmit(&hlpuart1, Buffer , NumberOfBytes,Timeout);
    }  
    switch (err_code)
    {
    case HAL_OK:
        return UDRV_RETURN_OK;
    case HAL_BUSY:
        return -UDRV_BUSY;
    case HAL_ERROR:
    default:
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_uart_read(SERIAL_PORT Port, uint8_t *Buffer, int32_t NumberOfBytes, uint32_t Timeout)
{
    if (Port == SERIAL_UART1) {
        return (int32_t)fund_circular_queue_out(&SERIAL_UART1_rxq, Buffer, NumberOfBytes);
    } else if (Port == SERIAL_UART2) {
        return (int32_t)fund_circular_queue_out(&SERIAL_UART2_rxq, Buffer, NumberOfBytes);
    }
    return -UDRV_INTERNAL_ERR;
}

int32_t uhal_uart_peek(SERIAL_PORT Port)
{
    uint8_t ch;

    if (Port == SERIAL_UART1) {
        return (int32_t)fund_circular_queue_peek(&SERIAL_UART1_rxq, &ch);
    } else if (Port == SERIAL_UART2) {
        return (int32_t)fund_circular_queue_peek(&SERIAL_UART2_rxq, &ch);
    }
    return -UDRV_INTERNAL_ERR;
}

void uhal_uart_flush(SERIAL_PORT Port, uint32_t Timeout)
{
    if (Port == SERIAL_UART1) {
        fund_circular_queue_reset(&SERIAL_UART1_rxq);
    } else if (Port == SERIAL_UART2) {
        fund_circular_queue_reset(&SERIAL_UART2_rxq);
    }
}

int32_t uhal_uart_read_available(SERIAL_PORT Port)
{
    if (Port == SERIAL_UART1) {
        return (size_t)fund_circular_queue_utilization_get(&SERIAL_UART1_rxq);
    } else if (Port == SERIAL_UART2) {
        return (size_t)fund_circular_queue_utilization_get(&SERIAL_UART2_rxq);
    }
    return -UDRV_INTERNAL_ERR;
}

void uhal_uart_suspend(void)
{

    for (int i = SERIAL_UART0 ; i < UHAL_UART_MAX ; i++) 
    {
        if (uart_status[i].active == true) 
        {
            if(i == SERIAL_UART2)
            {
                /* Turn off DMA and idle interrupt */
                while (__HAL_UART_GET_FLAG(&hlpuart1, USART_ISR_BUSY) == SET);
                while (__HAL_UART_GET_FLAG(&hlpuart1, USART_ISR_REACK) == RESET);

                HAL_UARTEx_EnableStopMode(&hlpuart1);
                __HAL_UART_CLEAR_IDLEFLAG(&hlpuart1);   
                __HAL_UART_DISABLE_IT(&hlpuart1, UART_IT_IDLE);
                HAL_UART_DMAStop(&hlpuart1); 
                HAL_DMA_DeInit((&hlpuart1)->hdmarx);
            }
            if(i == SERIAL_UART1)  //RAK3172 uart1
            {
                LL_USART_ClearFlag_ORE(USART1);
                //while (LL_USART_IsActiveFlag_BUSY(USART1) == 1);
                //while (LL_USART_IsActiveFlag_REACK(USART1) == 0);
                LL_USART_ClearFlag_WKUP(USART1);
                LL_USART_EnableInStopMode(USART1);
                LL_USART_EnableIT_WKUP(USART1);
                LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_26);
            }
	    }
    }
   
}

void uhal_uart_resume(void)
{
    for (int i = SERIAL_UART0 ; i < UHAL_UART_MAX ; i++) {
        if (i == SERIAL_UART2 || i == SERIAL_UART1) {//LPUART doesn't need to be re-initialized.
            continue;
        }
 
        if (uart_status[i].active == true) {
            uart_init(i, uart_status[i].baudrate, uart_status[i].dataBits ,uart_status[i].stopBits,
            uart_status[i].parity, uart_wire_mode[i]);
	}
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance==LPUART1)
    {
        /* When DMA is full, pop all data first and receive it idleWhen DMA is full
        pop all data first and receive it idle */
        HAL_UART_DMAStop(huart); 
#ifndef RUI_BOOTLOADER
        for (int i = 0 ; i < BUFFER_SIZE ; i++) {
            serial_fallback_handler(SERIAL_UART2, lpuart_dma_buff[i]);
        }
#endif
        fund_circular_queue_in(&SERIAL_UART2_rxq, lpuart_dma_buff, BUFFER_SIZE);
        HAL_UART_Receive_DMA(huart, (uint8_t*)lpuart_dma_buff, BUFFER_SIZE);     
    }
    if (huart->Instance==USART1)
    {
        HAL_UART_DMAStop(huart); 
#ifndef RUI_BOOTLOADER
        for (int i = 0 ; i < BUFFER_SIZE ; i++) {
            serial_fallback_handler(SERIAL_UART1, uart1_dma_buff[i]);
        }
#endif
        fund_circular_queue_in(&SERIAL_UART1_rxq, uart1_dma_buff, BUFFER_SIZE);
        HAL_UART_Receive_DMA(huart, (uint8_t*)uart1_dma_buff, BUFFER_SIZE);  
    }
#ifndef RUI_BOOTLOADER
    udrv_system_event_produce(&rui_uart_event);
#endif
}

void uhal_uart_dma_lpuart_init()
{
     /* DMA controller clock enable */
    __HAL_RCC_DMAMUX1_CLK_ENABLE();
    __HAL_RCC_DMA1_CLK_ENABLE();

    /* DMA interrupt init */
    /* DMA1_Channel1_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
}

void uhal_uart_dma_uart1_init()
{
     /* DMA controller clock enable */
    __HAL_RCC_DMAMUX1_CLK_ENABLE();
    __HAL_RCC_DMA1_CLK_ENABLE();

    /* DMA interrupt init */
    /* DMA1_Channel1_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA1_Channel4_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
}


void USAR_UART_IDLECallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance==LPUART1)
    {
        uint16_t data_length;
        HAL_UART_DMAStop(huart);                                                    
        data_length  = BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_lpuart1_rx); 

#ifndef RUI_BOOTLOADER
        for (int i = 0 ; i < data_length ; i++) {
            serial_fallback_handler(SERIAL_UART2, lpuart_dma_buff[i]);
        }
#endif
        fund_circular_queue_in(&SERIAL_UART2_rxq, lpuart_dma_buff, data_length);
        HAL_UART_Receive_DMA(huart, (uint8_t*)lpuart_dma_buff, BUFFER_SIZE); 
  
        if(LpuartDMAdoing == 1 )
        {
            LpuartDMAdoing = 0;
            udrv_powersave_wake_unlock();
        }

    }
    if(huart->Instance==USART1) 
    {
        uint16_t data_length;
        HAL_UART_DMAStop(huart);                                                    
        data_length  = BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart1_rx); 
        /*loop test*/
        //HAL_UART_Transmit(&hlpuart1, uart1_dma_buff, data_length, 1000);
        //HAL_UART_Transmit(&huart1, uart1_dma_buff, data_length, 1000);
#ifndef RUI_BOOTLOADER
        for (int i = 0 ; i < data_length ; i++) {
            serial_fallback_handler(SERIAL_UART1, uart1_dma_buff[i]);
        }
#endif
        fund_circular_queue_in(&SERIAL_UART1_rxq, uart1_dma_buff, data_length);
        HAL_UART_Receive_DMA(huart, (uint8_t*)uart1_dma_buff, BUFFER_SIZE);

        if(LpuartDMAdoing == 1 )
        {
            LpuartDMAdoing = 0;
            udrv_powersave_wake_unlock();
        }

    } 
#ifndef RUI_BOOTLOADER
        udrv_system_event_produce(&rui_uart_event);
#endif
}


void UserDataTreatment(UART_HandleTypeDef *huart, uint8_t* pData, uint16_t Size)
{
  /*
   * This function might be called in any of the following interrupt contexts :
   *  - DMA TC and HT events
   *  - UART IDLE line event
   *
   * pData and Size defines the buffer where received data have been copied, in order to be processed.
   * During this processing of already received data, reception is still ongoing.
   *
   */
  uint8_t* pBuff = pData;
  uint8_t  i;

  /* Implementation of loopback is on purpose implemented in direct register access,
     in order to be able to echo received characters as fast as they are received.
     Wait for TC flag to be raised at end of transmit is then removed, only TXE is checked */
  for (i = 0; i < Size; i++)
  {
    while (!(__HAL_UART_GET_FLAG(huart, UART_FLAG_TXE))) {}
    huart->Instance->TDR = *pBuff;
    pBuff++;
  }

}

void HAL_UARTEx_WakeupCallback(UART_HandleTypeDef *huart)
{

    uint8_t rdr_register; 
    udrv_powersave_in_sleep = false;

    rdr_register = huart->Instance->RDR ;
if(huart->Instance==LPUART1)
{
    HAL_UARTEx_DisableStopMode(&hlpuart1);
    /* Reinitialize DMA receive mode */
    hdma_lpuart1_rx.Instance = DMA1_Channel1;
    hdma_lpuart1_rx.Init.Request = DMA_REQUEST_LPUART1_RX;
    hdma_lpuart1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_lpuart1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_lpuart1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_lpuart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_lpuart1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_lpuart1_rx.Init.Mode = DMA_NORMAL;
    hdma_lpuart1_rx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_lpuart1_rx) != HAL_OK)
    {
      Error_Handler();
    }
    __HAL_LINKDMA(huart,hdmarx,hdma_lpuart1_rx);
    StartReception(SERIAL_UART2);
}
if(huart->Instance==USART1)
{
    HAL_UARTEx_DisableStopMode(&huart1);
    /* Reinitialize DMA receive mode */
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
    StartReception(SERIAL_UART1);
}

#ifndef RUI_BOOTLOADER
    if(huart->Instance==LPUART1)
    serial_fallback_handler(SERIAL_UART2, rdr_register);
#endif
    if(huart->Instance==LPUART1)
    fund_circular_queue_in(&SERIAL_UART2_rxq, &rdr_register, 1);
   
#ifndef RUI_BOOTLOADER
    udrv_system_event_produce(&rui_uart_event);
#endif 
    if(LpuartDMAdoing == 0 )
    {
        LpuartDMAdoing = 1;
        udrv_powersave_wake_lock();
    }
}
