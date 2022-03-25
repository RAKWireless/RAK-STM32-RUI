#ifndef _ATCMD_CLASS_B_MODE_H_
#define _ATCMD_CLASS_B_MODE_H_
#include "atcmd.h"

int At_PingSlot (SERIAL_PORT port, char *cmd, stParam *param);
int At_BeaconFreq (SERIAL_PORT port, char *cmd, stParam *param);
int At_BeaconTime (SERIAL_PORT port, char *cmd, stParam *param);
int At_BGW (SERIAL_PORT port, char *cmd, stParam *param);
int At_LocalTime (SERIAL_PORT port, char *cmd, stParam *param);

#endif //_ATCMD_CLASS_B_MODE_H_
