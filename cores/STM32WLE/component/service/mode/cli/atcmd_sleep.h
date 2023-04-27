#ifndef _ATCMD_SLEEP_H_
#define _ATCMD_SLEEP_H_
#include "atcmd.h"

int At_Sleep(SERIAL_PORT port, char *cmd, stParam *param);
int At_AutoSleep(SERIAL_PORT port, char *cmd, stParam *param);
int At_AutoSleepLevel(SERIAL_PORT port, char *cmd, stParam *param);

#endif //_ATCMD_SLEEP_H_
