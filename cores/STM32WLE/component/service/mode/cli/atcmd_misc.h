#ifndef _ATCMD_MISC_H_
#define _ATCMD_MISC_H_
#include "atcmd.h"

#ifndef RUI_BOOTLOADER
int At_Factory (SERIAL_PORT port, char *cmd, stParam *param);/* hidden AT command */
#endif

#endif //_ATCMD_MISC_H_
