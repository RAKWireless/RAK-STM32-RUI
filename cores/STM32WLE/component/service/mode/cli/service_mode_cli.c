#include <stdint.h>
#include "service_mode_cli.h"
#include "udrv_serial.h"
#include "service_nvm.h"
#ifdef RUI_BOOTLOADER
#include "app_uart.h"
#endif

/* Command Line: */
static char sgCmdBuffer[CLI_BUFFER_SIZE+1];
static char *sgArgV[CLI_ARG_SIZE];
static uint32_t sgArgC;
static uint32_t sgCurPos;

typedef enum _SPECIAL_KEY_STATUS_E {
	NoAnyKeyReceived,
	Key1bReceived,
	Key5bReceived,
}SPECIAL_KEY_STATUS_E;

static SPECIAL_KEY_STATUS_E gSpecialKey = NoAnyKeyReceived;

#ifndef RUI_BOOTLOADER
extern at_cmd_cust_info atcmd_cust_tbl[ATCMD_CUST_TABLE_SIZE];
#endif

#ifdef SUPPORT_ATCMD_HISTORY
static char gCmdHistoryBuffer[CLI_HISTORY_NUM][CLI_BUFFER_SIZE+1];
static char gCmdHistoryIdx;
static char gCmdHistoryCnt;
#endif

#ifdef RUI_BOOTLOADER
static inline void __put_char(SERIAL_PORT port, char c) {
    while (app_uart_put(c) != NRF_SUCCESS);
}
#else
static inline void __put_char(SERIAL_PORT port, char c) {
    udrv_serial_write(port, (unsigned char*)&c,1);
}
#endif

static void Cli_EraseCmdInScreen(SERIAL_PORT port)
{
    uint32_t i;
    for(i= 0;i < (strlen(sgCmdBuffer)+strlen(CLI_PROMPT));i++)
    {
        __put_char(port, 0x08);
        __put_char(port, 0x20);
        __put_char(port, 0x08);
    }
}

#ifdef SUPPORT_ATCMD_HISTORY
#ifndef RUI_BOOTLOADER
static void Cli_PrintCmdInScreen(SERIAL_PORT port)
{
    uint32_t i;
    atcmd_printf("%s", CLI_PROMPT);
    for(i= 0;i<strlen(sgCmdBuffer);i++)
    {
        __put_char(port, sgCmdBuffer[i]);
    }
}

static uint8_t Cli_GetPrevHistoryIdx()
{
    char CmdIdx = gCmdHistoryIdx;
    if(gCmdHistoryIdx == 0)
        CmdIdx =0;
    else
        CmdIdx--;

    return CmdIdx;
}

static uint8_t Cli_GetNextHistoryIdx()
{
    char CmdIdx = gCmdHistoryIdx;

    CmdIdx++;

    if(CmdIdx >= CLI_HISTORY_NUM || CmdIdx > gCmdHistoryCnt)
        CmdIdx--;

    return CmdIdx;
}

static inline void Cli_StoreCmdBufToHistory(uint8_t history)
{
    uint32_t len = strlen((const char*)sgCmdBuffer);
    memcpy(&gCmdHistoryBuffer[history], sgCmdBuffer, len);
    gCmdHistoryBuffer[history][len]=0x00;
}

static inline void Cli_RestoreHistoryToCmdBuf(uint8_t history)
{
    uint32_t len = strlen((const char*)&gCmdHistoryBuffer[history]);
    memcpy(sgCmdBuffer, &gCmdHistoryBuffer[history], len);
    sgCmdBuffer[len]= 0x00;
    sgCurPos = len;
}

static void Cli_MovetoPrevHistoryCmdBuf(SERIAL_PORT port)
{
    uint8_t CmdIdx = gCmdHistoryIdx;
    uint8_t NewCmdIdx = Cli_GetPrevHistoryIdx();
    
    if(!service_nvm_get_atcmd_echo_from_nvm()) 
        return;
    
    if(CmdIdx == NewCmdIdx)
        return;

    Cli_EraseCmdInScreen(port);
    Cli_StoreCmdBufToHistory(CmdIdx);
    Cli_RestoreHistoryToCmdBuf(NewCmdIdx);
    Cli_PrintCmdInScreen(port);
    gCmdHistoryIdx = NewCmdIdx;
}

static void Cli_MovetoNextHistoryCmdBuf(SERIAL_PORT port)
{
    uint8_t CmdIdx = gCmdHistoryIdx;
    uint8_t NewCmdIdx = Cli_GetNextHistoryIdx();

    if(!service_nvm_get_atcmd_echo_from_nvm()) 
        return;
    
    if(CmdIdx == NewCmdIdx)
        return;

    Cli_EraseCmdInScreen(port);
    Cli_StoreCmdBufToHistory(CmdIdx);
    Cli_RestoreHistoryToCmdBuf(NewCmdIdx);
    Cli_PrintCmdInScreen(port);
    gCmdHistoryIdx = NewCmdIdx;
}

static void Cli_RecordInHistoryCmdBuf()
{
    uint32_t i = CLI_HISTORY_NUM-2;
    uint32_t len;

    if(sgCurPos)
    {
        //shift history log
        for(; i>0 ; i--)
        {
            len = strlen((const char*)&gCmdHistoryBuffer[i]);
            memcpy(&gCmdHistoryBuffer[i+1], &gCmdHistoryBuffer[i], len);
            gCmdHistoryBuffer[i+1][len] = 0x00;
        }

        //copy buf to index 1
        len = strlen((const char*)&sgCmdBuffer);
        memcpy(&gCmdHistoryBuffer[1], &sgCmdBuffer, len);
        gCmdHistoryBuffer[1][len] = 0x00;

        //Record how much history we record
        gCmdHistoryCnt++;
        if(gCmdHistoryCnt>=CLI_HISTORY_NUM)
            gCmdHistoryCnt = CLI_HISTORY_NUM-1;
    }

    //Reset buf
    gCmdHistoryBuffer[0][0]=0x00;
    gCmdHistoryIdx = 0;
}
#endif
#endif

void service_mode_cli_handler(SERIAL_PORT port, uint8_t ch) {
    switch (ch)
    {
        case 0x1b: /* Special Key, read again for real data */
            gSpecialKey = Key1bReceived;
            break;
        case 0x08: /* Backspace key */
        case 0x7f: /* del key */
            gSpecialKey = NoAnyKeyReceived;
            if ( 0 < sgCurPos ) {
                sgCurPos --;
                sgCmdBuffer[sgCurPos] = 0x00;
                __put_char(port, 0x08);
                __put_char(port, 0x20);
                __put_char(port, 0x08);
            }
            break;
	case 0x0a: /* Enter */
        case 0x0d: /* Enter */
            gSpecialKey = NoAnyKeyReceived;
#ifdef SUPPORT_ATCMD_HISTORY
#ifndef RUI_BOOTLOADER
            Cli_RecordInHistoryCmdBuf();
#endif
#endif
            if(strlen(sgCmdBuffer) > 0) {
                //atcmd_printf("\r\n^sgCmdBuffer=%s^,len=%d, buf_len=%d\r\n",sgCmdBuffer,strlen(sgCmdBuffer), CLI_BUFFER_SIZE);
                if(service_nvm_get_atcmd_echo_from_nvm()) {
                    __put_char(port, 0x0a);
                    __put_char(port, 0x0d);
                }
                At_Parser(port, sgCmdBuffer,strlen(sgCmdBuffer));
                atcmd_printf("\r\n%s", CLI_PROMPT);
            }

            //if ( 0 !=sgCurPos ) {
            //    atcmd_printf("\r\nCommand not found!!\r\n");
            //}

            memset(sgCmdBuffer, 0x00, sizeof(sgCmdBuffer));
            sgCurPos = 0;
            break;

        default: /* other characters */
            if(gSpecialKey == Key1bReceived && ch == 0x5b) {
                gSpecialKey = Key5bReceived;
            } else if (gSpecialKey == Key5bReceived && ch == 0x41) {//up arrow key
                gSpecialKey = NoAnyKeyReceived;
#ifdef SUPPORT_ATCMD_HISTORY
#ifndef RUI_BOOTLOADER
                Cli_MovetoNextHistoryCmdBuf(port);
#endif
#endif
            } else if (gSpecialKey == Key5bReceived && ch == 0x42) {//down arrow key
                gSpecialKey = NoAnyKeyReceived;
#ifdef SUPPORT_ATCMD_HISTORY
#ifndef RUI_BOOTLOADER
                Cli_MovetoPrevHistoryCmdBuf(port);
#endif
#endif
	    } else {
                gSpecialKey = NoAnyKeyReceived;
                if ( (CLI_BUFFER_SIZE-1) > sgCurPos ) {
                    sgCmdBuffer[sgCurPos++] = ch;
                    sgCmdBuffer[sgCurPos] = 0x00;
                    if(service_nvm_get_atcmd_echo_from_nvm()) {
                        __put_char(port, ch);
                    }
                }
	    }
            break;
    }
}

void service_mode_cli_init(SERIAL_PORT port) {
    atcmd_printf("\r\n%s", CLI_PROMPT);

    memset( (void *)sgArgV, 0, sizeof(uint8_t *)*5 );
    memset(sgCmdBuffer, 0x00, sizeof(sgCmdBuffer));
    sgCurPos = 0;
    sgArgC = 0;
    update_permisssion();
}

void service_mode_cli_deinit(SERIAL_PORT port) {
}

#ifndef RUI_BOOTLOADER
bool service_mode_cli_register(const char *cmd, const char *title, PF_handle handle, uint8_t maxargu, const char *usage, uint8_t perm) {
    if (cmd == NULL || title == NULL || handle == NULL || usage == NULL || perm == NULL) {
        return false;
    }

    for (int i = 0 ; i < ATCMD_CUST_TABLE_SIZE ; i++) {
        if (atcmd_cust_tbl[i].atCmd == NULL) {
            atcmd_cust_tbl[i].atCmd = cmd;
            atcmd_cust_tbl[i].title = title;
            atcmd_cust_tbl[i].pfHandle = handle;
            atcmd_cust_tbl[i].maxargu = maxargu;
            atcmd_cust_tbl[i].CmdUsage = usage;
            atcmd_cust_tbl[i].permission = perm;
            return true;
        }
    }

    return false;
}
#endif
