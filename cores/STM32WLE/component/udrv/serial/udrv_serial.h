/**
 * @file        udrv_serial.h
 * @brief       Provide a hardware independent serial driver layer for API layer to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.2
 */

#ifndef _UDRV_SERIAL_H_
#define _UDRV_SERIAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

typedef enum _SERIAL_STATE{
    SERIAL_STATE_DEFAULT = 0,
    SERIAL_STATE_AT_START_1    = 1,    /* A */
    SERIAL_STATE_AT_START_2    = 2,    /* T */
    SERIAL_STATE_AT_START_3    = 3,    /* + */
    SERIAL_STATE_BOOT_1        = 4,    /* B */
    SERIAL_STATE_BOOT_2        = 5,    /* O */
    SERIAL_STATE_BOOT_3        = 6,    /* O */
    SERIAL_STATE_BOOT_4        = 7,    /* T */
    SERIAL_STATE_ATM_1         = 8,    /* A */
    SERIAL_STATE_ATM_2         = 9,    /* T */
    SERIAL_STATE_ATM_3         = 10,   /* M */
    SERIAL_STATE_AT_END        = 11,   /* CRLF */
    SERIAL_STATE_MAX           = 12,
} SERIAL_STATE;

typedef enum _SERIAL_EVENT{
    SERIAL_EVENT_RECV_A_A_CHAR    = 0,
    SERIAL_EVENT_RECV_A_T_CHAR    = 1,
    SERIAL_EVENT_RECV_A_PLUS_CHAR = 2,
    SERIAL_EVENT_RECV_A_B_CHAR    = 3,
    SERIAL_EVENT_RECV_A_O_CHAR    = 4,
    SERIAL_EVENT_RECV_A_M_CHAR    = 5,
    SERIAL_EVENT_RECV_CRLF        = 6,
    SERIAL_EVENT_RECV_OTHER_CHAR  = 7,
    SERIAL_EVENT_MAX              = 8,
} SERIAL_EVENT;

#define SERIAL_NO_TIMEOUT UINT32_MAX

typedef enum _SERIAL_WIRE_MODE_E {
    SERIAL_TWO_WIRE_NORMAL_MODE         = 0x0,
    SERIAL_ONE_WIRE_TX_PIN_MODE         = 0x1,
    SERIAL_ONE_WIRE_RX_PIN_MODE         = 0x2,
} SERIAL_WIRE_MODE_E;

typedef enum _SERIAL_WORD_LEN_E {
    SERIAL_WORD_LEN_5                 = 0x0,  ///< Character's Word Length 5 bits.
    SERIAL_WORD_LEN_6                 = 0x1,  ///< Character's Word Length 6 bits.
    SERIAL_WORD_LEN_7                 = 0x2,  ///< Character's Word Length 7 bits.
    SERIAL_WORD_LEN_8                 = 0x3   ///< Character's Word Length 8 bits.
} SERIAL_WORD_LEN_E;

typedef enum _SERIAL_STOP_BIT_E {
    SERIAL_STOP_BIT_1                 = 0x0,  ///< One stop bit will be transmitted.
    SERIAL_STOP_BIT_2                 = 0x1   ///< Two stop bits (1.5 with 5-bit data) will be transmitted.
} SERIAL_STOP_BIT_E;

typedef enum _SERIAL_PARITY_E {
    SERIAL_PARITY_DISABLE             = 0x0,  ///< No parity bit is transmitted nor expected.
    SERIAL_PARITY_ODD                 = 0x1,  ///< The number of bits including the parity bit must be odd.
    SERIAL_PARITY_EVEN                = 0x3,  ///< The number of bits including the parity bit must be even.
    SERIAL_PARITY_FORCED1             = 0x5,  ///< The parity bit is sent as/checked to be 1.
    SERIAL_PARITY_FORCED0             = 0x7   ///< The parity bit is sent as/checked to be 0.
} SERIAL_PARITY_E;

typedef enum _SERIAL_UART_EVT_E {
    SERIAL_UART_TX_DONE             = 0,
    SERIAL_UART_RX_DONE             = 1,
    SERIAL_UART_ERROR               = 2,
} SERIAL_UART_EVT;

typedef enum _SERIAL_PORT
{
    SERIAL_UART0 = 0,       // Use UART0 for I/O
    SERIAL_UART1,           // Use UART1 for I/O
    SERIAL_UART2,           // Use UART2 for I/O
#ifdef SUPPORT_USB
    SERIAL_USB0,            // Use USB0 for I/O
#endif
#ifdef SUPPORT_BLE
    SERIAL_BLE0,            // Use BLE for I/O
#endif
#ifdef SUPPORT_NFC
    SERIAL_NFC,             // Use NFC for I/O
#endif
    SERIAL_MAX,
} SERIAL_PORT;

typedef enum _SERIAL_WLOCK_STATE
{
    SERIAL_WLOCK_OPEN   = 0,
    SERIAL_WLOCK_LOCKED = 1,
    SERIAL_WLOCK_DISABLED = 2,
} SERIAL_WLOCK_STATE;

typedef void (*SERIAL_CLI_HANDLER) (SERIAL_PORT, void *);
typedef void (*SERIAL_UART_HANDLER) (SERIAL_PORT, SERIAL_UART_EVT);

//The structure of serial function 
struct udrv_serial_api {
    void (*SERIAL_INIT) (SERIAL_PORT Port, uint32_t BaudRate, SERIAL_WORD_LEN_E DataBits, SERIAL_STOP_BIT_E StopBits, SERIAL_PARITY_E Parity, SERIAL_WIRE_MODE_E WireMode);
    void (*SERIAL_DEINIT) (SERIAL_PORT Port);
    int32_t (*SERIAL_WRITE) (SERIAL_PORT Port, uint8_t const *Buffer, int32_t NumberOfBytes, uint32_t Timeout);
    int32_t (*SERIAL_READ) (SERIAL_PORT Port, uint8_t *Buffer, int32_t NumberOfBytes, uint32_t Timeout);
    int32_t (*SERIAL_PEEK) (SERIAL_PORT Port);
    void (*SERIAL_FLUSH) (SERIAL_PORT Port, uint32_t Timeout);
    int32_t (*SERIAL_READ_AVAIL) (SERIAL_PORT Port);
    bool (*SERIAL_IS_READY) (SERIAL_PORT Port);
    //void (*SERIAL_SUSPEND) (void);
    //void (*SERIAL_RESUME) (void);
};

/**
 * @brief       This API is used to register a one-wire handler.
 * @retval      void
 * @param       SERIAL_CLI_HANDLER handler: the handler function to handle the received characters
 */
void udrv_serial_register_onewire_handler (SERIAL_UART_HANDLER handler);

/**
 * @brief       This API is used to check if a specified serial port is initialized.
 * @retval      bool
 * @param       SERIAL_PORT Port: the specified serial port to be checked
 */
bool is_udrv_serial_initialized(SERIAL_PORT Port);

/**
 * @brief       This API is used to initialize a specified serial port.
 * @retval      void
 * @param       SERIAL_PORT Port: the specified serial port to be initialized
 * @param       uint32_t BaudRate: the initialized value of baud rate setting
 * @param       SERIAL_WORD_LEN_E DataBits: the initialized value of data bits setting
 * @param       SERIAL_STOP_BIT_E StopBits: the initialized value of stop bits setting
 * @param       SERIAL_PARITY_E Parity: the initialized value of parity bits setting
 * @param       SERIAL_WIRE_MODE_E WireMode: the initialized value of wire mode
 */
void udrv_serial_init (SERIAL_PORT Port, uint32_t BaudRate, SERIAL_WORD_LEN_E DataBits, SERIAL_STOP_BIT_E StopBits, SERIAL_PARITY_E Parity, SERIAL_WIRE_MODE_E WireMode);

/**
 * @brief       This API is used to deinitialize a specified serial port.
 * @retval      void
 * @param       SERIAL_PORT Port: the specified serial port to be deinitialized
 */
void udrv_serial_deinit (SERIAL_PORT Port);

/***************************************************************************************
 * @brief       This API is used to write a byte sequence to a specified serial port in CLI mode.
 * @retval      int32_t
 * @return      number of bytes sent successfully
 * @param       SERIAL_PORT Port: the specified serial port
 * @param       uint8_t const *Buffer: 
 * @param       int32_t NumberOfBytes:
 */
int32_t udrv_serial_write (SERIAL_PORT Port, uint8_t const *Buffer, int32_t NumberOfBytes);

/**
 * @brief       This API is like printf() to format any kinds of data type into a byte sequence,
 *              and write it to a specified serial port.
 * @retval      int32_t
 * @return      number of bytes sent successfully
 * @param       SERIAL_PORT Port: the specified serial port
 * @param       const char *fmt: 
 */
int32_t udrv_serial_printf (SERIAL_PORT Port, const char *fmt, ...);

#ifndef RUI_BOOTLOADER
/**
 * @brief       This API is like printf() to format any kinds of data type into a byte sequence,
 *              and write it to every serial port in AT Command Mode.
 * @retval      int32_t
 * @return      number of bytes sent successfully
 * @param       const char *fmt: 
 */
int32_t udrv_serial_log_printf (const char *fmt, ...);
#endif

/**
 * @brief       This API is used to read a byte sequence from a specified serial port.
 * @retval      int32_t
 * @return      number of bytes received successfully
 * @param       SERIAL_PORT Port: the specified serial port
 * @param       uint8_t const *Buffer: 
 * @param       int32_t NumberOfBytes:
 */
int32_t udrv_serial_read (SERIAL_PORT Port, uint8_t *Buffer, int32_t NumberOfBytes);

/**
 * @brief       This API is used to peek a byte from a specified serial port.
 * @retval      int32_t
 * @return      the successfully peeked byte
 * @param       SERIAL_PORT Port: the specified serial port
 */
int32_t udrv_serial_peek (SERIAL_PORT Port);

/**
 * @brief       This API is used to wait a specified serial port to complete data writing.
 * @retval      void
 * @param       SERIAL_PORT Port: the specified serial port
 */
void udrv_serial_flush (SERIAL_PORT Port);

/**
 * @brief       This API is used to lock a specified serial port.
 * @retval      void
 */
void udrv_serial_lock (void);

/**
 * @brief       This API is used to maunually unlock a specified serial port.
 * @retval      void
 */
void udrv_serial_unlock (void);

/**
 * @brief       This API is used to get the unlock password for a specified serial port.
 * @retval      int32_t
 * @param       char *passwd:
 * @param       uint32_t len:
 */
int32_t udrv_serial_get_passwd (char *passwd, uint32_t len);

/**
 * @brief       This API is used to set the unlock password for a specified serial port.
 * @retval      int32_t
 * @param       const char *passwd:
 * @param       uint32_t len:
 */
int32_t udrv_serial_set_passwd (const char *passwd, uint32_t len);

/**
 * @brief       This API is used to get the lock state of a specified serial port.
 * @retval      SERIAL_WLOCK_STATE
 * @param       SERIAL_PORT Port: the specified serial port
 */
SERIAL_WLOCK_STATE udrv_serial_get_lock_state (SERIAL_PORT Port);

/**
 * @brief       This API is used to disable a specified serial port.
 * @retval      void
 * @param       SERIAL_PORT Port: the specified serial port
 */
void udrv_serial_disable (SERIAL_PORT Port);

/**
 * @brief       This API is used to enable a specified serial port.
 * @retval      void
 * @param       SERIAL_PORT Port: the specified serial port
 */
void udrv_serial_enable (SERIAL_PORT Port);

/**
 * @brief       This API is used to get the number of bytes available for reading from
 *              the specified serial port.
 * @retval      int32_t
 * @return      the number of bytes available for reading from the specified serial port
 * @param       SERIAL_PORT Port: the specified serial port
 */
int32_t udrv_serial_read_available(SERIAL_PORT Port);

/**
 * @brief       This API is used to get the timeout value for read/write/flush API.
 * @retval      uint32_t
 */
uint32_t udrv_serial_get_timeout ();

/**
 * @brief       This API is used to set the timeout value for read/write/flush API.
 * @retval      void
 * @param       uint32_t timeout: the timeout value
 */
void udrv_serial_set_timeout (uint32_t timeout);

/**
 * @brief   Suspend serial hardware before entering sleep mode.
 *
 */
void udrv_serial_suspend();

/**
 * @brief   Resume serial hardware after leaving sleep mode.
 *
 */
void udrv_serial_resume();

/**
 * @brief   Let AT+BOOT and AT+ATM works in any serial mode.
 *
 */
#ifndef RUI_BOOTLOADER
void serial_fallback_handler(SERIAL_PORT port, uint8_t ch);
#endif

#ifdef __cplusplus
}
#endif

#endif  // #ifndef _UDRV_SERIAL_H_
