#ifndef __SERVICE_MODE_CLI_HANDLER_H__
#define __SERVICE_MODE_CLI_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

//standard libary include
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "atcmd.h"

#define CLI_BUFFER_SIZE   (2048)//FIXME Consider AT+LPSEND
#define CLI_HISTORY_NUM (5)
#define CLI_ARG_SIZE		(20)
#define CLI_PROMPT			("")

inline int get_cli_buffer_len(void);

//typedef void (*CliCmdFunc) ( s32, char  ** );
typedef int (*CliCmdFunc) ( int32_t, char* argv[] );

typedef struct CLICmds_st
{
        const char           *Cmd;
        CliCmdFunc          CmdHandler;
        const char           *CmdUsage;

} CLICmds, *PCLICmds;

void service_mode_cli_init(SERIAL_PORT port);
void service_mode_cli_deinit(SERIAL_PORT port);
void service_mode_cli_handler(SERIAL_PORT port, uint8_t ch);
#ifndef RUI_BOOTLOADER
bool service_mode_cli_register(const char *cmd, const char *title, PF_handle handle, uint8_t maxargu, const char *usage, uint8_t perm);
#else
int Cli_RAK(SERIAL_PORT port, uint8_t ch);
#endif

int At_Parser (SERIAL_PORT port, char *buff, int len);

#ifdef __cplusplus
}
#endif

#endif /* __SERVICE_MODE_CLI_HANDLER_H__ */

