#ifndef _ATCMD_KEY_ID_H_
#define _ATCMD_KEY_ID_H_
#include "atcmd.h"

int At_AppEui (SERIAL_PORT port, char *cmd, stParam *param);
int At_AppKey (SERIAL_PORT port, char *cmd, stParam *param);
int At_AppSKey (SERIAL_PORT port, char *cmd, stParam *param);
int At_DevAddr (SERIAL_PORT port, char *cmd, stParam *param);
int At_DevEui (SERIAL_PORT port, char *cmd, stParam *param);
int At_NetId (SERIAL_PORT port, char *cmd, stParam *param);
int At_NwkSKey (SERIAL_PORT port, char *cmd, stParam *param);
int At_McRootkey (SERIAL_PORT port, char *cmd, stParam *param);

#endif //_ATCMD_KEY_ID_H_
