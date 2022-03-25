#ifndef _ATCMD_SUPPLE_H_
#define _ATCMD_SUPPLE_H_
#include "atcmd.h"

#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
int At_Mask (SERIAL_PORT port, char *cmd, stParam *param);
int At_Chs(SERIAL_PORT port, char *cmd, stParam *param);
int At_Che(SERIAL_PORT port, char *cmd, stParam *param);
#endif
int At_Band (SERIAL_PORT port, char *cmd, stParam *param);
//int At_DelBLEBonds (SERIAL_PORT port, char *cmd, stParam *param);

int At_Trssi(SERIAL_PORT port, char *cmd, stParam *param);
int At_Ttone(SERIAL_PORT port, char *cmd, stParam *param);
int At_Ttx(SERIAL_PORT port, char *cmd, stParam *param);
int At_Trx(SERIAL_PORT port, char *cmd, stParam *param);
int At_Tconf(SERIAL_PORT port, char *cmd, stParam *param);
int At_Tth(SERIAL_PORT port, char *cmd, stParam *param);
int At_Toff(SERIAL_PORT port, char *cmd, stParam *param);
int At_Certif(SERIAL_PORT port, char *cmd, stParam *param);

#endif //_ATCMD_SUPPLE_H_
