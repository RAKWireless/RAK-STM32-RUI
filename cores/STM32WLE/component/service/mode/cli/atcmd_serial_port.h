#ifndef _ATCMD_SERIAL_PORT_H_
#define _ATCMD_SERIAL_PORT_H_
#include "atcmd.h"

int At_Lock (SERIAL_PORT port, char *cmd, stParam *param);
int At_Pword (SERIAL_PORT port, char *cmd, stParam *param);
int At_Baud (SERIAL_PORT port, char *cmd, stParam *param);
int At_AtCmdMode (SERIAL_PORT port, char *cmd, stParam *param);
int At_ApiMode (SERIAL_PORT port, char *cmd, stParam *param);
int At_TransparentMode (SERIAL_PORT port, char *cmd, stParam *param);

#endif //_ATCMD_SERIAL_PORT_H_
