#include <stddef.h>
#include "udrv_serial.h"
#include "udrv_errno.h"
#include "udrv_system.h"
#include "uhal_uart.h"
#include "service_mode.h"
#ifndef RUI_BOOTLOADER
#ifdef SUPPORT_USB
#include "uhal_usb.h"
#endif
#ifdef SUPPORT_BLE
#include "uhal_ble.h"
#endif
#ifdef SUPPORT_NFC
#include "uhal_nfc.h"
#endif
#include "service_nvm.h"
#endif

static uint32_t sgCurPos, sgCnt;
static char sgInBuffer[9];
static uint32_t udrv_serial_timeout = 10000;
static bool udrv_serial_usb_initialized = false;

static struct udrv_serial_api *serial_api[SERIAL_MAX];

struct udrv_serial_api serial_uart_driver =
{
  //uhal_uart_register_cli_handler,
  uhal_uart_init,
  uhal_uart_deinit,
  uhal_uart_write,
  uhal_uart_read,
  uhal_uart_peek,
  uhal_uart_flush,
  uhal_uart_read_available,
  NULL,
  //uhal_uart_suspend,
  //uhal_uart_resume,
};

#ifndef RUI_BOOTLOADER
#ifdef SUPPORT_USB
struct udrv_serial_api serial_usb_driver =
{
  //uhal_usb_register_cli_handler,
  uhal_usb_init,
  uhal_usb_deinit,
  uhal_usb_write,
  uhal_usb_read,
  uhal_usb_peek,
  uhal_usb_flush,
  uhal_usb_read_available,
  uhal_usb_opened,
  //uhal_usb_suspend,
  //uhal_usb_resume,
};
#endif

#ifdef SUPPORT_BLE
struct udrv_serial_api serial_ble_driver =
{
  //uhal_ble_register_cli_handler,
  uhal_ble_serial_init,
  uhal_ble_serial_deinit,
  uhal_ble_serial_write,
  uhal_ble_serial_read,
  uhal_ble_serial_peek,
  uhal_ble_serial_flush,
  uhal_ble_serial_read_available,
  NULL,
  //uhal_ble_suspend,
  //uhal_ble_resume,
};
#endif

#ifdef SUPPORT_NFC
struct udrv_serial_api serial_nfc_driver =
{
  //uhal_ble_register_cli_handler,
  uhal_nfc_serial_init,
  uhal_nfc_serial_deinit,
  uhal_nfc_serial_write,
  uhal_nfc_serial_read,
  uhal_nfc_serial_peek,
  uhal_nfc_serial_flush,
  uhal_nfc_serial_read_available,
  NULL,
  //uhal_nfc_suspend,
  //uhal_nfc_resume,
};
#endif
#endif

void udrv_serial_register_onewire_handler (SERIAL_UART_HANDLER handler)
{
    uhal_uart_register_onewire_handler(handler);
}

//This func only works when AT cmd is disabled & interrupt mode is used.
//It is empty because it should be overridden by users' app.
void app_cli_handler(uint8_t ch) __attribute__((weak));
void app_cli_handler(uint8_t ch) {
}

bool is_udrv_serial_initialized(SERIAL_PORT Port)
{

    if(Port >= SERIAL_UART0 && Port <= SERIAL_UART2){
        if (serial_api[Port]) {
            return true;
        } else {
            return false;
        }
    }
#ifdef SUPPORT_USB
    else if (Port == SERIAL_USB0) {
#ifndef RUI_BOOTLOADER
        if(serial_api[Port]->SERIAL_IS_READY(Port)){
            return true;
        }
        else{
            return false;
        }
#endif
    }
#endif
#ifdef SUPPORT_BLE
    else if (Port == SERIAL_BLE0) {
#ifndef RUI_BOOTLOADER
        if (serial_api[Port]) {
            return true;
        } else {
            return false;
        }
#endif
    }
#endif
#ifdef SUPPORT_NFC
    else if (Port == SERIAL_NFC) {
        if (serial_api[Port]) {
            return true;
        } else {
            return false;
        }
    }
#endif
    return true;
}

void udrv_serial_init (SERIAL_PORT Port, uint32_t BaudRate, SERIAL_WORD_LEN_E DataBits, SERIAL_STOP_BIT_E StopBits, SERIAL_PARITY_E Parity, SERIAL_WIRE_MODE_E WireMode)
{
    if(Port >= SERIAL_UART0 && Port <= SERIAL_UART2) {
        if(serial_api[Port]) {
            serial_api[Port]->SERIAL_DEINIT(Port);
        }
        serial_api[Port] = &serial_uart_driver;

        serial_api[Port]->SERIAL_INIT(Port, BaudRate, DataBits, StopBits, Parity, WireMode);
    }
#ifdef SUPPORT_USB
    else if (Port == SERIAL_USB0) {
#ifndef RUI_BOOTLOADER
        serial_api[Port] = &serial_usb_driver;
        if (udrv_serial_usb_initialized == false) {
            serial_api[Port]->SERIAL_INIT(Port, BaudRate, DataBits, StopBits, Parity, WireMode);
            udrv_serial_usb_initialized = true;
        }
#endif
    }
#endif
#ifdef SUPPORT_BLE
    else if (Port == SERIAL_BLE0) {
#ifndef RUI_BOOTLOADER
        if(serial_api[Port]) {
            serial_api[Port]->SERIAL_DEINIT(Port);
        }
        serial_api[Port] = &serial_ble_driver;

        serial_api[Port]->SERIAL_INIT(Port, BaudRate, DataBits, StopBits, Parity, WireMode);
#endif
    }
#endif
#ifdef SUPPORT_NFC
    else if (Port == SERIAL_NFC) {
        if(serial_api[Port]) {
            serial_api[Port]->SERIAL_DEINIT(Port);
        }
        serial_api[Port] = &serial_nfc_driver;

        serial_api[Port]->SERIAL_INIT(Port, BaudRate, DataBits, StopBits, Parity, WireMode);
    }
#endif
}
void udrv_serial_deinit (SERIAL_PORT Port)
{
    if(Port >= SERIAL_UART0 && Port <= SERIAL_UART2) {
        if(serial_api[Port]) {
            serial_api[Port]->SERIAL_FLUSH(Port, 100);//Wait 10ms to flush. If it is not enough, call udrv_serial_flush().
            serial_api[Port]->SERIAL_DEINIT(Port);
            serial_api[Port] = NULL;
	}
    }
#ifdef SUPPORT_USB
    else if (Port == SERIAL_USB0) {
        if(serial_api[Port]) {
            if (udrv_serial_usb_initialized == true) {
                serial_api[Port]->SERIAL_DEINIT(Port);
                serial_api[Port] = NULL;
                udrv_serial_usb_initialized = false;
            }
        }
    }
#endif
    else if (Port < SERIAL_MAX) {
        if(serial_api[Port]) {
            serial_api[Port]->SERIAL_DEINIT(Port);
            serial_api[Port] = NULL;
        }
    }
}

int32_t udrv_serial_write (SERIAL_PORT Port, uint8_t const *Buffer, int32_t NumberOfBytes)
{
    if((Port >= SERIAL_UART0 && Port <= SERIAL_UART2)
#ifdef SUPPORT_USB
		    || (Port == SERIAL_USB0)
#endif
#ifdef SUPPORT_BLE
		    || (Port == SERIAL_BLE0)
#endif
#ifdef SUPPORT_NFC
		    || (Port == SERIAL_NFC)
#endif
		    ) {
        if (service_nvm_get_lock_status_from_nvm(Port) != SERIAL_WLOCK_OPEN) {
            return -UDRV_TEMP_LOCKED;
        }

        if(serial_api[Port])
            return serial_api[Port]->SERIAL_WRITE(Port, Buffer, NumberOfBytes, udrv_serial_timeout);
        else
            return -UDRV_NOT_INIT;
    } else {
        return -UDRV_WRONG_ARG;
    }
}

int32_t udrv_serial_printf (SERIAL_PORT Port, const char *fmt, ...)
{
#ifndef RUI_BOOTLOADER
#ifndef STM32WL55xx //Fix me: wait nvm module is ready.
    SERVICE_MODE_TYPE mode = service_nvm_get_mode_type_from_nvm(Port);

    //This API only works in CLI Mode & Custom Mode.
#ifdef SUPPORT_BINARY
    if (mode == SERVICE_MODE_TYPE_PROTOCOL
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
		    || mode == SERVICE_MODE_TYPE_TRANSPARENT
#endif
#endif
		    ) {
        return -UDRV_FORBIDDEN;
    }
#endif
#endif
#endif

    if((Port >= SERIAL_UART0 && Port <= SERIAL_UART2)
#ifdef SUPPORT_USB
		    || (Port == SERIAL_USB0)
#endif
#ifdef SUPPORT_BLE
		    || (Port == SERIAL_BLE0)
#endif
#ifdef SUPPORT_NFC
		    || (Port == SERIAL_NFC)
#endif
		    ) {
        if (service_nvm_get_lock_status_from_nvm(Port) != SERIAL_WLOCK_OPEN) {
            return -UDRV_TEMP_LOCKED;
        }

        if(serial_api[Port]) {
            char print_buf[512];
            va_list aptr;
 
            va_start (aptr, fmt);
            vsprintf (print_buf, fmt, aptr);
            va_end (aptr);
 
            return serial_api[Port]->SERIAL_WRITE(Port, print_buf, strlen(print_buf), udrv_serial_timeout);
        } else {
            return -UDRV_NOT_INIT;
	}
    } else {
        return -UDRV_WRONG_ARG;
    }
}

#ifndef RUI_BOOTLOADER
int32_t udrv_serial_log_printf (const char *fmt, ...)
{
    int32_t ret = 0;

    for (int i = 0 ; i < SERIAL_MAX ; i++) {
        if (service_nvm_get_mode_type_from_nvm((SERIAL_PORT)i) == SERVICE_MODE_TYPE_CLI) {
            if (service_nvm_get_lock_status_from_nvm((SERIAL_PORT)i) != SERIAL_WLOCK_OPEN) {
                continue;
            }

            if(serial_api[(SERIAL_PORT)i]) {
                char print_buf[512];
                va_list aptr;
 
                va_start (aptr, fmt);
                vsprintf (print_buf, fmt, aptr);
                va_end (aptr);

                ret = serial_api[(SERIAL_PORT)i]->SERIAL_WRITE((SERIAL_PORT)i, print_buf, strlen(print_buf), udrv_serial_timeout);
	    }
        }
    }

    return ret;
}
#endif

int32_t udrv_serial_read (SERIAL_PORT Port, uint8_t *Buffer, int32_t NumberOfBytes)
{
    if((Port >= SERIAL_UART0 && Port <= SERIAL_UART2)
#ifdef SUPPORT_USB
		    || (Port == SERIAL_USB0)
#endif
#ifdef SUPPORT_BLE
		    || (Port == SERIAL_BLE0)
#endif
#ifdef SUPPORT_NFC
		    || (Port == SERIAL_NFC)
#endif
		    ) {
        if(serial_api[Port])
            return serial_api[Port]->SERIAL_READ(Port, Buffer, NumberOfBytes, udrv_serial_timeout);
        else
            return -UDRV_NOT_INIT;
    } else {
        return -UDRV_WRONG_ARG;
    }
}

int32_t udrv_serial_peek (SERIAL_PORT Port)
{
    if((Port >= SERIAL_UART0 && Port <= SERIAL_UART2)
#ifdef SUPPORT_USB
		    || (Port == SERIAL_USB0)
#endif
#ifdef SUPPORT_BLE
		    || (Port == SERIAL_BLE0)
#endif
#ifdef SUPPORT_NFC
		    || (Port == SERIAL_NFC)
#endif
		    ) {
        if(serial_api[Port])
            return serial_api[Port]->SERIAL_PEEK(Port);
        else
            return -UDRV_NOT_INIT;
    } else {
        return -UDRV_WRONG_ARG;
    }
}

void udrv_serial_flush (SERIAL_PORT Port)
{
    if(Port >= SERIAL_UART0 && Port <= SERIAL_UART2) {
        if(serial_api[Port]) {
            serial_api[Port]->SERIAL_FLUSH(Port, udrv_serial_timeout);
        }
    }
}

void udrv_serial_wlock_handler (SERIAL_PORT port, uint8_t ch) {
    uint8_t answer[9];
    uint32_t answer_len = service_nvm_get_serial_passwd_from_nvm(answer, 9);

    switch (ch)
    {
        case 0x08: /* Backspace key */
        case 0x7f: /* del key */
            if ( 0 < sgCurPos ) {
                sgInBuffer[--sgCurPos] = 0x00;
                sgCnt--;
            }
            break;
        case 0x0a: /* Enter */
        case 0x0d: /* Enter */
            if (sgCnt != 0) {
                serial_api[port]->SERIAL_WRITE(port, "\r\n", 2, udrv_serial_timeout);
                if (sgCnt == 9 && !strncasecmp(sgInBuffer, "AT+LOCK=?", 9)) {
                    serial_api[port]->SERIAL_WRITE(port, "AT+LOCK=locked\r\nOK\r\n", 21, udrv_serial_timeout);
                } else if (sgCnt == answer_len && !memcmp(sgInBuffer, answer, answer_len)) {
                    udrv_serial_unlock();
                } else {
                    serial_api[port]->SERIAL_WRITE(port, "COMMAND_LOCKED\r\n", 17, udrv_serial_timeout);
                }
            }
            //serial_api[port]->SERIAL_WRITE(port, "\r\n", 2, udrv_serial_timeout);
            sgCurPos = 0;
            sgCnt = 0;
            memset(sgInBuffer, 0, 9);
            break;

        default: /* other characters */
            if ( 9 > sgCurPos ) {
                sgInBuffer[sgCurPos++] = ch;
                serial_api[port]->SERIAL_WRITE(port, &ch, 1, udrv_serial_timeout);
            }
            sgCnt++;
            break;
    }
}

void udrv_serial_lock (void)
{
    for (int i = 0 ; i < SERIAL_MAX ; i++) {
        if (service_nvm_get_lock_status_from_nvm((SERIAL_PORT)i) == SERIAL_WLOCK_OPEN) {
            service_nvm_set_lock_status_to_nvm((SERIAL_PORT)i, SERIAL_WLOCK_LOCKED);
            sgCurPos = 0;
            sgCnt = 0;
            memset(sgInBuffer, 0, 9);
        }
    }
}

void udrv_serial_unlock (void)
{
    for (int i = 0 ; i < SERIAL_MAX ; i++) {
        if (service_nvm_get_lock_status_from_nvm((SERIAL_PORT)i) == SERIAL_WLOCK_LOCKED) {
            service_nvm_set_lock_status_to_nvm((SERIAL_PORT)i, SERIAL_WLOCK_OPEN);
        }
    }
}

int32_t udrv_serial_get_passwd (char *passwd, uint32_t len) {
    if (len < 9) {
        return -UDRV_WRONG_ARG;
    }

    return service_nvm_get_serial_passwd_from_nvm(passwd, len);
}

int32_t udrv_serial_set_passwd (const char *passwd, uint32_t len) {
    if (len > 8) {
        return -UDRV_WRONG_ARG;
    }

    for (int i = 0 ; i < len ; i++) {
        if ((uint8_t)passwd[i] < 0x20 || (uint8_t)passwd[i] > 0x7E) {
            return -UDRV_WRONG_ARG;
        }
    }

    return service_nvm_set_serial_passwd_to_nvm(passwd, len);
}

SERIAL_WLOCK_STATE udrv_serial_get_lock_state (SERIAL_PORT Port)
{
    if((Port >= SERIAL_UART0 && Port <= SERIAL_UART2)
#ifdef SUPPORT_USB
		    || (Port == SERIAL_USB0)
#endif
#ifdef SUPPORT_BLE
		    || (Port == SERIAL_BLE0)
#endif
#ifdef SUPPORT_NFC
		    || (Port == SERIAL_NFC)
#endif
		    ) {
        return service_nvm_get_lock_status_from_nvm(Port);
    } else {
        return SERIAL_WLOCK_OPEN;
    }
}

void udrv_serial_disable (SERIAL_PORT Port)
{
    if((Port >= SERIAL_UART0 && Port <= SERIAL_UART2)
#ifdef SUPPORT_USB
		    || (Port == SERIAL_USB0)
#endif
#ifdef SUPPORT_BLE
		    || (Port == SERIAL_BLE0)
#endif
#ifdef SUPPORT_NFC
		    || (Port == SERIAL_NFC)
#endif
		    ) {
        service_nvm_set_lock_status_to_nvm(Port, SERIAL_WLOCK_DISABLED);
        sgCurPos = 0;
        sgCnt = 0;
        memset(sgInBuffer, 0, 9);
    }
}

void udrv_serial_enable (SERIAL_PORT Port)
{
    if((Port >= SERIAL_UART0 && Port <= SERIAL_UART2)
#ifdef SUPPORT_USB
		    || (Port == SERIAL_USB0)
#endif
#ifdef SUPPORT_BLE
		    || (Port == SERIAL_BLE0)
#endif
#ifdef SUPPORT_NFC
		    || (Port == SERIAL_NFC)
#endif
		    ) {
        if (service_nvm_get_lock_status_from_nvm(Port) != SERIAL_WLOCK_LOCKED)
            service_nvm_set_lock_status_to_nvm(Port, SERIAL_WLOCK_OPEN);
        sgCurPos = 0;
        sgCnt = 0;
        memset(sgInBuffer, 0, 9);
    }
}


int32_t udrv_serial_read_available(SERIAL_PORT Port) {
    if((Port >= SERIAL_UART0 && Port <= SERIAL_UART2)
#ifdef SUPPORT_USB
		    || (Port == SERIAL_USB0)
#endif
#ifdef SUPPORT_BLE
		    || (Port == SERIAL_BLE0)
#endif
#ifdef SUPPORT_NFC
		    || (Port == SERIAL_NFC)
#endif
		    ) {
        if(serial_api[Port]) {
            return serial_api[Port]->SERIAL_READ_AVAIL(Port);
	} else {
            return -UDRV_NOT_INIT;
        }
    } else {
        return -UDRV_WRONG_ARG;
    }
}

uint32_t udrv_serial_get_timeout () {
    return udrv_serial_timeout;
}

void udrv_serial_set_timeout (uint32_t timeout) {
    udrv_serial_timeout = timeout;
}

void udrv_serial_suspend(void) {
    uhal_uart_suspend();
    return;
}

void udrv_serial_resume(void) {
    uhal_uart_resume();
    return;
}

#ifndef RUI_BOOTLOADER
static udrv_system_event_t rui_serial_fallback_event = {.request = UDRV_SYS_EVT_OP_SERIAL_FALLBACK, .p_context = NULL};

static SERIAL_STATE serial_state[SERIAL_MAX];

static SERIAL_EVENT serial_transitions[SERIAL_STATE_MAX][SERIAL_EVENT_MAX] = {
    [SERIAL_STATE_DEFAULT] = { [SERIAL_EVENT_RECV_A_A_CHAR]    = SERIAL_STATE_AT_START_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
    [SERIAL_STATE_AT_START_1] = { [SERIAL_EVENT_RECV_A_A_CHAR] = SERIAL_STATE_AT_START_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_AT_START_2,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
    [SERIAL_STATE_AT_START_2] = { [SERIAL_EVENT_RECV_A_A_CHAR] = SERIAL_STATE_AT_START_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_AT_START_3,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
    [SERIAL_STATE_AT_START_3] = { [SERIAL_EVENT_RECV_A_A_CHAR] = SERIAL_STATE_ATM_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_BOOT_1,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
    [SERIAL_STATE_BOOT_1] = { [SERIAL_EVENT_RECV_A_A_CHAR]     = SERIAL_STATE_AT_START_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_BOOT_2,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
    [SERIAL_STATE_BOOT_2] = { [SERIAL_EVENT_RECV_A_A_CHAR]     = SERIAL_STATE_AT_START_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_BOOT_3,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
    [SERIAL_STATE_BOOT_3] = { [SERIAL_EVENT_RECV_A_A_CHAR]     = SERIAL_STATE_AT_START_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_BOOT_4,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
    [SERIAL_STATE_BOOT_4] = { [SERIAL_EVENT_RECV_A_A_CHAR]     = SERIAL_STATE_AT_START_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_AT_END,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
    [SERIAL_STATE_ATM_1] = { [SERIAL_EVENT_RECV_A_A_CHAR]      = SERIAL_STATE_AT_START_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_ATM_2,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
    [SERIAL_STATE_ATM_2] = { [SERIAL_EVENT_RECV_A_A_CHAR]      = SERIAL_STATE_AT_START_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_ATM_3,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
    [SERIAL_STATE_ATM_3] = { [SERIAL_EVENT_RECV_A_A_CHAR]      = SERIAL_STATE_AT_START_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_AT_END,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
    [SERIAL_STATE_AT_END] = { [SERIAL_EVENT_RECV_A_A_CHAR]     = SERIAL_STATE_AT_START_1,
                               [SERIAL_EVENT_RECV_A_T_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_PLUS_CHAR] = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_B_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_O_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_A_M_CHAR]    = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_CRLF]        = SERIAL_STATE_DEFAULT,
                               [SERIAL_EVENT_RECV_OTHER_CHAR]  = SERIAL_STATE_DEFAULT,},
};

static SERIAL_EVENT serial_ch2evt(uint8_t ch) {
    switch (ch) {
        case 'a':
        case 'A':
        {
            return SERIAL_EVENT_RECV_A_A_CHAR;
        }
        case 't':
        case 'T':
        {
            return SERIAL_EVENT_RECV_A_T_CHAR;
        }
        case '+':
        {
            return SERIAL_EVENT_RECV_A_PLUS_CHAR;
        }
        case 'b':
        case 'B':
        {
            return SERIAL_EVENT_RECV_A_B_CHAR;
        }
        case 'o':
        case 'O':
        {
            return SERIAL_EVENT_RECV_A_O_CHAR;
        }
        case 'm':
        case 'M':
        {
            return SERIAL_EVENT_RECV_A_M_CHAR;
        }
        case 0x0a:
        case 0x0d:
        {
            return SERIAL_EVENT_RECV_CRLF;
        }
        default:
        {
            return SERIAL_EVENT_RECV_OTHER_CHAR;
        }
    }
}

void serial_fallback_handler(SERIAL_PORT port, uint8_t ch) {
    SERIAL_STATE orig_state = serial_state[port];
    SERVICE_MODE_TYPE mode = service_nvm_get_mode_type_from_nvm(port);

    if (mode == SERVICE_MODE_TYPE_CLI) {
        return;
    }

    serial_state[port] = serial_transitions[serial_state[port]][serial_ch2evt(ch)];

    if (serial_state[port] == SERIAL_STATE_AT_END && orig_state == SERIAL_STATE_BOOT_4) {
        serial_state[port] = SERIAL_STATE_DEFAULT;
        udrv_enter_dfu();
    } else if (serial_state[port] == SERIAL_STATE_AT_END && orig_state == SERIAL_STATE_ATM_3) {
        serial_state[port] = SERIAL_STATE_DEFAULT;
        rui_serial_fallback_event.p_context = (void *)port;
        udrv_system_event_produce(&rui_serial_fallback_event);
    }
}

#endif
