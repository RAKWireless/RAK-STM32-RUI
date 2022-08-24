#ifndef _ATCMD_NWK_MNG_H_
#define _ATCMD_NWK_MNG_H_
#include "atcmd.h"

int At_ADR (SERIAL_PORT port, char *cmd, stParam *param);
int At_Class (SERIAL_PORT port, char *cmd, stParam *param);
int At_DCS (SERIAL_PORT port, char *cmd, stParam *param);
int At_DataRate (SERIAL_PORT port, char *cmd, stParam *param);
int At_RxWin1JoinDelay (SERIAL_PORT port, char *cmd, stParam *param);
int At_RxWin2JoinDelay (SERIAL_PORT port, char *cmd, stParam *param);
int At_PubNwkMode (SERIAL_PORT port, char *cmd, stParam *param);
int At_RxWin1Delay (SERIAL_PORT port, char *cmd, stParam *param);
int At_RxWin2Delay (SERIAL_PORT port, char *cmd, stParam *param);
int At_RxWin2DataRate (SERIAL_PORT port, char *cmd, stParam *param);
int At_RxWin2Freq (SERIAL_PORT port, char *cmd, stParam *param);
int At_TxPower (SERIAL_PORT port, char *cmd, stParam *param);
int At_LinkCheck(SERIAL_PORT port, char *cmd, stParam *param);
int At_Timereq(SERIAL_PORT port, char *cmd, stParam *param);

#endif //_ATCMD_NWK_MNG_H_
