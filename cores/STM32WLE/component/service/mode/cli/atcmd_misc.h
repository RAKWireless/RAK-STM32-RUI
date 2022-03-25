#ifndef _ATCMD_MISC_H_
#define _ATCMD_MISC_H_
#include "atcmd.h"

#ifdef RUI_BOOTLOADER
int At_Bootstatus(SERIAL_PORT port, char *cmd, stParam *param);
#endif

#endif //_ATCMD_MISC_H_
