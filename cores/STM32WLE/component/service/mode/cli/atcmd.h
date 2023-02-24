#ifndef _ATCMD_H_
#define _ATCMD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <udrv_serial.h>
#include "atcmd_queue.h"
#include "atcmd_permission.h"
#ifdef RUI_BOOTLOADER
#include "app_uart.h"
extern int is_dfu_mode;
#endif


#ifdef RUI_BOOTLOADER
static void atcmd_printf(const char *fmt, ...) {
    char print_buf[512];
    va_list aptr;
    va_start (aptr, fmt);
    vsprintf (print_buf, fmt, aptr);
    va_end (aptr);
    for (int i = 0 ; i < strlen(print_buf); i++) {
        while (app_uart_put(print_buf[i]) != NRF_SUCCESS);
    }
}
#else
#define atcmd_printf(fmt, ...)  udrv_serial_log_printf(fmt, ##__VA_ARGS__)
#endif

#define MAX_CMD_LEN (32)
#define MAX_ARGUMENT 25
/* ATCMD PERMISSION */
typedef enum AT_PERM_{
    ATCMD_PERM_WRITE = 1 << 0,
    ATCMD_PERM_READ = 1 << 1,
    ATCMD_PERM_WRITEONCEREAD = 1 << 2,
    ATCMD_PERM_ISWRITE = 1 << 3,
    ATCMD_PERM_DISABLE = 1 << 4,
}AT_PERMISSION;


/* Error code definition */
typedef enum AT_ERRNO_E_{
        AT_OK = 0,
        AT_ERROR,
        AT_PARAM_ERROR,
        AT_BUSY_ERROR,
        AT_TEST_PARAM_OVERFLOW,
        AT_NO_CLASSB_ENABLE,
        AT_NO_NETWORK_JOINED,
        AT_RX_ERROR,
        AT_MODE_NO_SUPPORT,
        AT_COMMAND_NOT_FOUND,
}AT_ERRNO_E;

typedef struct _stParam
{
    char*	argv[MAX_ARGUMENT];
    int	argc;
} stParam;

typedef int (*PF_handle) (SERIAL_PORT port, char* cmd, stParam *param);
typedef struct _at_cmd_info
{
    char*              atCmd;
    PF_handle          pfHandle;
    uint8_t            maxargu;
    const char         *CmdUsage;
    uint8_t            permission;
} at_cmd_info;

typedef struct _at_cmd_cust_info
{
    char*              atCmd;
    char*              title;
    PF_handle          pfHandle;
    uint8_t            maxargu;
    const char         *CmdUsage;
    uint8_t            permission;
} at_cmd_cust_info;

uint32_t At_CmdGetTotalNum (void);
int At_Parser (SERIAL_PORT port, char *buff, int len);
void At_RespOK (char* pStr);
void StrToHex(uint8_t *pbDest, const char *pbSrc, int nLen);
uint8_t at_separate_param(const char *param, char **argv, uint32_t *argc);
uint8_t at_check_hex_param(const char *p_str, uint32_t str_len, uint8_t *p_hex);
uint8_t at_check_alphanumeric_param(const char *p_str, uint32_t str_len);
uint8_t at_check_hex_uint16(const char *p_str, uint16_t *value);
uint8_t at_check_hex_uint32(const char *p_str, uint32_t *value);
uint8_t at_check_digital_uint32_t(const char *p_str, uint32_t *value);
void update_permission();
uint8_t at_error_code_form_udrv(int8_t udrv_code);
#ifdef __cplusplus
}
#endif

#endif
