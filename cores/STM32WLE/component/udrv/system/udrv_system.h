#ifndef _UDRV_SYSTEM_H_
#define _UDRV_SYSTEM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#ifndef RUI_BOOTLOADER
#include <udrv_timer.h>

#define RANDOM_LENGTH   4
#define SEED_LENGTH   4
#endif

#define EVENT_QUEUE_SIZE                     (128)
#define EVENT_DATA_SIZE                      (8)//(sizeof(udrv_system_event_t))

/**
 * @brief event operation.
 */
typedef enum
{
    UDRV_SYS_EVT_OP_SERIAL_UART            = 0x00,     //operating mode parser - UART0/UART1
#ifdef SUPPORT_USB
    UDRV_SYS_EVT_OP_SERIAL_USB,                        //operating mode parser - USB0
#endif
#ifdef SUPPORT_BLE
    UDRV_SYS_EVT_OP_SERIAL_BLE,                        //operating mode parser - BLE
#endif
#ifdef SUPPORT_LORA
    UDRV_SYS_EVT_OP_LORAWAN,                           //LoRaWAN RX process
    UDRV_SYS_EVT_OP_LORAWAN_JOIN_CB,                   //Consider join request in join callback
#endif
    UDRV_SYS_EVT_OP_USER_APP,                          //user application
    UDRV_SYS_EVT_OP_USER_TIMER,                        //user timer
    UDRV_SYS_EVT_OP_SYS_TIMER,                         //system timer
#ifdef SUPPORT_NFC
    UDRV_SYS_EVT_OP_SERIAL_NFC,                        //operating mode parsr - NFC
#endif
    UDRV_SYS_EVT_OP_SERIAL_FALLBACK,                   //serial fallback to AT mode 
    UDRV_SYS_EVT_OP_RTC,                               //RTC
    UDRV_SYS_EVT_OP_GPIO_INTERRUPT,                    //Interrupt from GPIO
} udrv_system_event_op_t;

typedef struct
{
    udrv_system_event_op_t   request;        //!< Requested operation.
    void                     *p_context;
} udrv_system_event_t;

typedef void (*UDRV_TASK_HANDLER) (void);

void udrv_system_event_init(void);

int32_t udrv_system_event_produce(udrv_system_event_t *event);

void udrv_system_event_consume(void);

void udrv_system_reboot(void);

#if defined(rak11720) && defined(RUI_BOOTLOADER)
void udrv_system_critical_section_begin(uint32_t *mask);

void udrv_system_critical_section_end (uint32_t *mask);
#endif

#ifndef RUI_BOOTLOADER
void udrv_system_critical_section_begin(uint32_t *mask);

void udrv_system_critical_section_end (uint32_t *mask);

unsigned long udrv_system_random (unsigned long maxvalue);

void udrv_system_randomseed(unsigned long seed);

int32_t udrv_system_user_app_timer_create (timer_handler tmr_handler, TimerMode_E mode);

int32_t udrv_system_user_app_timer_start (uint32_t count, void *m_data);

int32_t udrv_system_user_app_timer_stop (void);

int32_t udrv_create_thread(char *name, UDRV_TASK_HANDLER handler);
void udrv_destroy_thread(char *name);
void udrv_destroy_myself(void);
void udrv_thread_lock(void);
void udrv_thread_unlock(void);
#endif

#ifdef __cplusplus
}
#endif

#endif  // #ifndef _UDRV_SYSTEM_H_
