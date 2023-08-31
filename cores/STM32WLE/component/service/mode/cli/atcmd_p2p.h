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

int At_iqInver(SERIAL_PORT port, char *cmd, stParam *param);

int At_syncword(SERIAL_PORT port, char *cmd, stParam *param);

int At_rfFrequency(SERIAL_PORT port, char *cmd, stParam *param);

int At_txOutputPower(SERIAL_PORT port, char *cmd, stParam *param);

int At_bandwidth(SERIAL_PORT port, char *cmd, stParam *param);

int At_speradingFactor(SERIAL_PORT port, char *cmd, stParam *param);

int At_codingrate(SERIAL_PORT port, char *cmd, stParam *param);

int At_preambleLength(SERIAL_PORT port, char *cmd, stParam *param);

int At_symbolTimeout(SERIAL_PORT port, char *cmd, stParam *param);

int At_fixLengthPayload(SERIAL_PORT port, char *cmd, stParam *param);

#endif //_ATCMD_INFO_H_
