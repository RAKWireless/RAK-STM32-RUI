#ifndef _ATCMD_P2P_H_
#define _ATCMD_P2P_H_
#include "atcmd.h"

int At_NwkWorkMode (SERIAL_PORT port, char *cmd, stParam *param);

int At_P2pFreq (SERIAL_PORT port, char *cmd, stParam *param);

int At_P2pSF (SERIAL_PORT port, char *cmd, stParam *param);

int At_P2pBW (SERIAL_PORT port, char *cmd, stParam *param);

int At_P2pCR (SERIAL_PORT port, char *cmd, stParam *param);

int At_P2pPL (SERIAL_PORT port, char *cmd, stParam *param);

int At_P2pTP (SERIAL_PORT port, char *cmd, stParam *param);

int At_P2pSend (SERIAL_PORT port, char *cmd, stParam *param);

int At_P2pRecv (SERIAL_PORT port, char *cmd, stParam *param);

int At_P2pCrypt (SERIAL_PORT port, char *cmd, stParam *param);

int At_P2pKey (SERIAL_PORT port, char *cmd, stParam *param);

int At_P2p(SERIAL_PORT port, char *cmd, stParam *param);

int At_Pbr(SERIAL_PORT port, char *cmd, stParam *param);

int At_Pfdev(SERIAL_PORT port, char *cmd, stParam *param);

#endif //_ATCMD_INFO_H_
