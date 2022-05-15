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

#ifdef SUPPORT_LORA
#include "radio.h"
#include "LoRaMac.h"
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
uint32_t orig_auto_sleep_time;
static bool run_user_app = false;

extern bool udrv_powersave_in_sleep;
extern const char *sw_version;

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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_MSI | RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_11;
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
                case SERVICE_MODE_TYPE_PROTOCOL:
                {
                    service_mode_proto_deinit(port);
                    break;
                }
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
                        case SERVICE_MODE_TYPE_PROTOCOL:
                        {
                            service_mode_proto_recv(SERIAL_UART0, Buf[0]);
                            break;
                        }
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
                        case SERVICE_MODE_TYPE_PROTOCOL:
                        {
                            service_mode_proto_recv(SERIAL_UART1, Buf[0]);
                            break;
                        }
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
                        case SERVICE_MODE_TYPE_PROTOCOL:
                        {
                            service_mode_proto_recv(SERIAL_UART2, Buf[0]);
                            break;
                        }
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
#endif
        case UDRV_SYS_EVT_OP_USER_APP:
        {
            run_user_app = true;
            break;
        }
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

void rui_user_application_timer_handler(void *p_context)
{
    uint32_t curr_auto_sleep_time = service_nvm_get_auto_sleep_time_from_nvm();

    udrv_system_event_produce(&rui_user_app_event);

    if (curr_auto_sleep_time != orig_auto_sleep_time) {
        udrv_system_user_app_timer_stop();
        orig_auto_sleep_time = curr_auto_sleep_time;
        if (curr_auto_sleep_time != 0) {
            udrv_system_user_app_timer_start(curr_auto_sleep_time, NULL);
        }
    }

    udrv_powersave_in_sleep = false;
}

void rui_init(void)
{
    SCB->VTOR = FLASH_BASE | 0x6000;

    HAL_Init();
    SystemClock_Config();
    MX_DMA_Init();
    udrv_timer_init();
    service_nvm_init_config();
    udrv_serial_init(SERIAL_UART1, 115200, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);
    udrv_serial_init(SERIAL_UART2, 115200, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);
#ifdef SUPPORT_LORA
    service_lora_init(service_lora_get_band());
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
    for (int i = 0 ; i < SERIAL_MAX ; i++) {
        if (service_nvm_get_mode_type_from_nvm((SERIAL_PORT)i) == SERVICE_MODE_TYPE_PROTOCOL) {
            service_mode_proto_init((SERIAL_PORT)i);
        }
    }

    udrv_system_event_init();
    udrv_system_user_app_timer_create((timer_handler)rui_user_application_timer_handler, HTMR_PERIODIC);
    if ((orig_auto_sleep_time = service_nvm_get_auto_sleep_time_from_nvm()) != 0) {
        udrv_system_user_app_timer_start(orig_auto_sleep_time, NULL);
    }
}

void rui_running(void)
{
    udrv_system_event_consume();
}

void main(void)
{
    //system init
    rui_init();

    //user init
    rui_setup();

#ifdef TOGGLE_LED_PER_SEC
    if (udrv_system_timer_create(SYSTIMER_LED, OnTimerEvent, HTMR_PERIODIC) == UDRV_RETURN_OK)
    {
        udrv_system_timer_start(SYSTIMER_LED, 1000, NULL);
    }
#endif

#ifdef SUPPORT_LORA
    udrv_serial_log_printf("Current Work Mode: ");
    switch (service_lora_get_nwm())
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
            udrv_serial_log_printf("LoRa FSK.\r\n");
            break;
        }
    }
#endif

    //XXX: dirty workaround for 0x20000528
    {
        extern int _sidata, _sdata, _edata;
        if (0x20000528 > (uint32_t)&_sdata && 0x20000528 < (uint32_t)&_edata)
        {
            uint8_t buff[4];
            uint32_t offset = 0x20000528 - (uint32_t)&_sdata;
            udrv_flash_read((uint32_t)&_sidata+offset, 4, buff);
            for (int j = 0 ; j < 4 ; j++) {
                if (*(uint8_t *)(0x20000528+j) != buff[j]) {
                    *(uint8_t *)(0x20000528+j) = buff[j];
                }
            }
        }
    }

    while(1)
    {
        //system loop
        rui_running();

        //user loop
        if (run_user_app) {
            rui_loop();
            run_user_app = false;
        }

        if (orig_auto_sleep_time != 0) {
            udrv_mcu_sleep_ms(POWERSAVE_NO_TIMEOUT);
        } else {
            run_user_app = true;
        }
    }
}
