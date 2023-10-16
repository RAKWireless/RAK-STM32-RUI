#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/* Includes ------------------------------------------------------------------*/
#include "app.h"

#include "main.h"
#include "board.h"


#include "udrv_errno.h"
#include "udrv_serial.h"
#include "udrv_timer.h"
#include "udrv_system.h"
#include "service_nvm.h"
#include "service_mode.h"
#include "service_mode_cli.h"
#include "udrv_powersave.h"
#include "service_debug.h"
#ifdef SUPPORT_MULTITASK
#include "uhal_sched.h"

extern bool sched_start;

extern tcb_ thread_pool[THREAD_POOL_SIZE];
extern tcb_ *current_thread;
extern unsigned long int current_sp;
#else
bool no_busy_loop = false;
#endif

#ifdef SUPPORT_WDT
#include "udrv_wdt.h"
extern bool is_custom_wdt;
#endif

#ifdef SUPPORT_LORA
#include "radio.h"
#include "LoRaMac.h"

extern service_lora_join_cb service_lora_join_callback;
#endif

#define LED1_PIN GPIO_PIN_0
#define LED1_GPIO_PORT GPIOA
#define LED1_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define LED1_GPIO_CLK_DISABLE() __HAL_RCC_GPIOA_CLK_DISABLE()

#define LED2_PIN GPIO_PIN_1
#define LED2_GPIO_PORT GPIOA
#define LED2_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define LED2_GPIO_CLK_DISABLE() __HAL_RCC_GPIOA_CLK_DISABLE()


static udrv_system_event_t rui_user_app_event = {.request = UDRV_SYS_EVT_OP_USER_APP, .p_context = NULL};
static bool run_user_app = false;

extern bool udrv_powersave_in_sleep;
extern const char *sw_version;
extern const char *build_date ;
extern const char *build_time ;

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_MSI | RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_11;
  RCC_OscInitStruct.LSIDiv = RCC_LSI_DIV1;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the SYSCLKSource, HCLK, PCLK1 and PCLK2 clocks dividers
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK3 | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.AHBCLK3Divider = RCC_SYSCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{
  /* DMA controller clock enable */
  __HAL_RCC_DMAMUX1_CLK_ENABLE();
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
}

#ifdef TOGGLE_LED_PER_SEC
void OnTimerEvent()
{
  HAL_GPIO_TogglePin(GPIOA, LED2_PIN);
}
#endif
/********************************************************************/
/* RUI handler functions                                            */
/********************************************************************/

void rui_event_handler_func(void *data, uint16_t size) {
    udrv_system_event_t *event = (udrv_system_event_t *)data;
    switch (event->request) {
        case UDRV_SYS_EVT_OP_SERIAL_FALLBACK:
        {
            SERIAL_PORT port = (SERIAL_PORT)event->p_context;
            SERVICE_MODE_TYPE mode = service_nvm_get_mode_type_from_nvm(port);

            /* escape now immediately */
            switch (mode)
            {
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                case SERVICE_MODE_TYPE_TRANSPARENT:
                {
                    service_mode_transparent_deinit(port);
                    break;
                }
#endif
#endif
#ifdef SUPPORT_BINARY
                case SERVICE_MODE_TYPE_PROTOCOL:
                {
                    service_mode_proto_deinit(port);
                    break;
                }
#endif
                default:
                {
                    break;
                }
            }
            service_mode_cli_init(port);
            service_nvm_set_mode_type_to_nvm(port, SERVICE_MODE_TYPE_CLI);
            break;
        }
        case UDRV_SYS_EVT_OP_SERIAL_UART:
        {
            if (service_nvm_get_mode_type_from_nvm(SERIAL_UART0) != SERVICE_MODE_TYPE_CUSTOM) {
                while (udrv_serial_read_available(SERIAL_UART0) > 0) {
                    uint8_t Buf[1];
                    int32_t count = udrv_serial_read (SERIAL_UART0, Buf, 1);
                    SERIAL_WLOCK_STATE state;
                    switch (service_nvm_get_mode_type_from_nvm(SERIAL_UART0)) {
                        case SERVICE_MODE_TYPE_CLI:
                        {
                            if ((state = udrv_serial_get_lock_state(SERIAL_UART0)) == SERIAL_WLOCK_OPEN) {
                                service_mode_cli_handler(SERIAL_UART0, Buf[0]);
                            } else if (state == SERIAL_WLOCK_LOCKED) {
                                udrv_serial_wlock_handler(SERIAL_UART0, Buf[0]);
                            }
                            break;
                        }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                        case SERVICE_MODE_TYPE_TRANSPARENT:
                        {
                            service_mode_transparent_handler(SERIAL_UART0, Buf[0]);
                            break;
                        }
#endif
#endif
#ifdef SUPPORT_BINARY
                        case SERVICE_MODE_TYPE_PROTOCOL:
                        {
                            service_mode_proto_recv(SERIAL_UART0, Buf[0]);
                            break;
                        }
#endif
                        default:
                        {
                            break;
                        }
                    }
                }
            }
            if (service_nvm_get_mode_type_from_nvm(SERIAL_UART1) != SERVICE_MODE_TYPE_CUSTOM) {
                while (udrv_serial_read_available(SERIAL_UART1) > 0) {
                    uint8_t Buf[1];
                    int32_t count = udrv_serial_read (SERIAL_UART1, Buf, 1);
                    SERIAL_WLOCK_STATE state;
                    switch (service_nvm_get_mode_type_from_nvm(SERIAL_UART1)) {
                        case SERVICE_MODE_TYPE_CLI:
                        {
                            if ((state = udrv_serial_get_lock_state(SERIAL_UART1)) == SERIAL_WLOCK_OPEN) {
                                service_mode_cli_handler(SERIAL_UART1, Buf[0]);
                            } else if (state == SERIAL_WLOCK_LOCKED) {
                                udrv_serial_wlock_handler(SERIAL_UART1, Buf[0]);
                            }
                            break;
                        }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                        case SERVICE_MODE_TYPE_TRANSPARENT:
                        {
                            service_mode_transparent_handler(SERIAL_UART1, Buf[0]);
                            break;
                        }
#endif
#endif
#ifdef SUPPORT_BINARY
                        case SERVICE_MODE_TYPE_PROTOCOL:
                        {
                            service_mode_proto_recv(SERIAL_UART1, Buf[0]);
                            break;
                        }
#endif
                        default:
                        {
                            break;
                        }
                    }
                }
            }
            if (service_nvm_get_mode_type_from_nvm(SERIAL_UART2) != SERVICE_MODE_TYPE_CUSTOM) {
                while (udrv_serial_read_available(SERIAL_UART2) > 0) {
                    uint8_t Buf[1];
                    int32_t count = udrv_serial_read (SERIAL_UART2, Buf, 1);
                    SERIAL_WLOCK_STATE state;
                    switch (service_nvm_get_mode_type_from_nvm(SERIAL_UART2)) {
                        case SERVICE_MODE_TYPE_CLI:
                        {
                            if ((state = udrv_serial_get_lock_state(SERIAL_UART2)) == SERIAL_WLOCK_OPEN) {
                                service_mode_cli_handler(SERIAL_UART2, Buf[0]);
                            } else if (state == SERIAL_WLOCK_LOCKED) {
                                udrv_serial_wlock_handler(SERIAL_UART2, Buf[0]);
                            }
                            break;
                        }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                        case SERVICE_MODE_TYPE_TRANSPARENT:
                        {
                            service_mode_transparent_handler(SERIAL_UART2, Buf[0]);
                            break;
                        }
#endif
#endif
#ifdef SUPPORT_BINARY
                        case SERVICE_MODE_TYPE_PROTOCOL:
                        {
                            service_mode_proto_recv(SERIAL_UART2, Buf[0]);
                            break;
                        }
#endif
                        default:
                        {
                            break;
                        }
                    }
                }
            }
            break;
        }
#ifdef SUPPORT_LORA
        case UDRV_SYS_EVT_OP_LORAWAN:
        {
            // Processes the LoRaMac events
            LoRaMacProcess( );

            // Call all packages process functions
            LmHandlerPackagesProcess( );
            break;
        }
        case UDRV_SYS_EVT_OP_LORAWAN_JOIN_CB:
        {
            if (service_lora_join_callback != NULL) {
                service_lora_join_callback(event->p_context);
            }
            break;
        }
#endif
        case UDRV_SYS_EVT_OP_USER_TIMER:
        case UDRV_SYS_EVT_OP_SYS_TIMER:
        {
            udrv_system_timer_handler_handler(event->p_context);
            break;
        }
        case UDRV_SYS_EVT_OP_GPIO_INTERRUPT:
        {
            udrv_gpio_handler_handler(event->p_context);
            break;
        }
        default:
        {
            break;
        }
    }
}

void rui_init(void)
{
    uint32_t baudrate;
    SCB->VTOR = FLASH_BASE | 0x6000;

    HAL_Init();
    SystemClock_Config();
    MX_DMA_Init();
    udrv_timer_init();
    service_nvm_init_config();
    baudrate = service_nvm_get_baudrate_from_nvm();
    udrv_serial_init(SERIAL_UART1, baudrate, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);
    udrv_serial_init(SERIAL_UART2, baudrate, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);
#if defined(SUPPORT_LORA)
    service_lora_init(service_nvm_get_band_from_nvm());
#elif defined(SUPPORT_LORA_P2P)
    BoardInitMcu();
    service_lora_p2p_init();
#endif


    for (int i = 0 ; i < SERIAL_MAX ; i++) {
        if (service_nvm_get_mode_type_from_nvm((SERIAL_PORT)i) == SERVICE_MODE_TYPE_CLI) {
            service_mode_cli_init((SERIAL_PORT)i);
        }
    }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
    for (int i = 0 ; i < SERIAL_MAX ; i++) {
        if (service_nvm_get_mode_type_from_nvm((SERIAL_PORT)i) == SERVICE_MODE_TYPE_TRANSPARENT) {
            if (service_lora_get_njs() == false) {
                service_nvm_set_mode_type_to_nvm((SERIAL_PORT)i, SERVICE_MODE_TYPE_CLI);
                service_mode_cli_init((SERIAL_PORT)i);
                continue;
            }
            service_mode_transparent_init((SERIAL_PORT)i);
        }
    }
#endif
#endif
#ifdef SUPPORT_BINARY
    for (int i = 0 ; i < SERIAL_MAX ; i++) {
        if (service_nvm_get_mode_type_from_nvm((SERIAL_PORT)i) == SERVICE_MODE_TYPE_PROTOCOL) {
            service_mode_proto_init((SERIAL_PORT)i);
        }
    }
#endif

#ifdef SUPPORT_WDT
    is_custom_wdt = false;
#endif

    udrv_system_event_init();
}

void rui_running(void)
{
#ifdef SUPPORT_WDT
    udrv_wdt_feed();//Consider software reset case, reload WDT counter first.
#endif

    udrv_system_event_consume();
}

#ifdef SUPPORT_MULTITASK
void rui_system_thread(void)
{
    while (1) {
        rui_running();
        if (service_nvm_get_auto_sleep_time_from_nvm() && uhal_sched_run_queue_empty()) {
            udrv_sleep_ms(0);
        }
    }
}

void rui_user_thread(void)
{
    //user init
    rui_setup();

#ifdef SUPPORT_WDT
    if(!is_custom_wdt) {
        udrv_wdt_init(WDT_FEED_PERIOD);
        udrv_wdt_feed();//Consider software reset case, reload WDT counter first.
    }
#endif

    while (1) {
        rui_loop();
    }
}
#endif

void main(void)
{
    //system init
    rui_init();

    //SWO clk
    __HAL_RCC_GPIOB_CLK_ENABLE();

#if 1
    //dirty workaround
    {
        extern int _sidata, _sdata, _edata;
        extern const at_cmd_info atcmd_info_tbl[];

        uint32_t offset = (uint32_t)atcmd_info_tbl - (uint32_t)&_sdata;
        uint32_t length = sizeof(at_cmd_info)*At_CmdGetTotalNum();

        for (uint32_t i = 0 ; i < length ; i+=4) {
            uint8_t buff[4];
            udrv_flash_read((uint32_t)&_sidata+offset+i, 4, buff);
            for (int j = 0 ; j < 4 ; j++) {
                if (*(uint8_t *)((uint32_t)&_sdata+offset+i+j) != buff[j]) {
                    *(uint8_t *)((uint32_t)&_sdata+offset+i+j) = buff[j];
                }
            }
        }
    }
#endif

#ifndef SUPPORT_MULTITASK
    //user init
    rui_setup();
#ifdef SUPPORT_WDT
    if(!is_custom_wdt) {
        udrv_wdt_init(UDRV_WDT_FEED_PERIOD);
        udrv_wdt_feed();//Consider software reset case, reload WDT counter first.
    }
#endif
#endif

#ifdef TOGGLE_LED_PER_SEC
    if (udrv_system_timer_create(SYSTIMER_LED, OnTimerEvent, HTMR_PERIODIC) == UDRV_RETURN_OK)
    {
        udrv_system_timer_start(SYSTIMER_LED, 1000, NULL);
    }
#endif

#ifdef rak3172T
    /* Only RAK3172 supports hardware high and low frequency detection */
    uint8_t hardware_freq = 0;
    hardware_freq =  BoardGetHardwareFreq();
    if(hardware_freq)
    {
        service_debug("RAK3172T-H ");
    }
    else
    {
        service_debug("RAK3172T-L ");
    }
    service_debug("Version:%s %s\r\n",sw_version,build_date);
#endif


#if defined(SUPPORT_LORA) || defined(SUPPORT_LORA_P2P)
    udrv_serial_log_printf("Current Work Mode: ");
#ifdef SUPPORT_LORA
    switch (service_lora_get_nwm())
#else
    switch (service_lora_p2p_get_nwm())
#endif
    {
        case SERVICE_LORA_P2P:
        {
            udrv_serial_log_printf("LoRa P2P.\r\n");
            break;
        }
        case SERVICE_LORAWAN:
        {
            udrv_serial_log_printf("LoRaWAN.\r\n");
            break;
        }
        case SERVICE_LORA_FSK:
        {
            udrv_serial_log_printf("FSK.\r\n");
            break;
        }
    }
#endif

#ifdef SUPPORT_MULTITASK
    memset(thread_pool, 0, sizeof(tcb_)*THREAD_POOL_SIZE);

    uhal_sched_create_sys_thread("sys thread", rui_system_thread);
    uhal_sched_create_thread("usr thread", rui_user_thread);

    uhal_sched_init();

    sched_start = true;

    while (1) {
        __asm("WFI");
    }
#else
    while(1)
    {
        //system loop
        rui_running();

        //user loop
        if (!no_busy_loop) {
            rui_loop();
        } else {
            if (service_nvm_get_auto_sleep_time_from_nvm()) {
                udrv_sleep_ms(0);
            }
        }
    }
#endif
}
