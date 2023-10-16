#ifndef _ATCMD_GENERAL_H_
#define _ATCMD_GENERAL_H_
#include "atcmd.h"

int At_Attention (SERIAL_PORT port, char *cmd, stParam *param);
int At_Reboot (SERIAL_PORT port, char *cmd, stParam *param);
int At_Restore (SERIAL_PORT port, char *cmd, stParam *param);
int At_Debug (SERIAL_PORT port, char *cmd, stParam *param);
int At_Dfu (SERIAL_PORT port, char *cmd, stParam *param);
#ifndef RUI_BOOTLOADER
int At_Echo (SERIAL_PORT port, char *cmd, stParam *param);
int At_FSn (SERIAL_PORT port, char *cmd, stParam *param);/* hidden AT command */
int At_Sn (SERIAL_PORT port, char *cmd, stParam *param);
int At_GetBat (SERIAL_PORT port, char *cmd, stParam *param);
int At_GetFwBuildTime (SERIAL_PORT port, char *cmd, stParam *param);
int At_GetFwRepoInfo (SERIAL_PORT port, char *cmd, stParam *param);
int At_GetFwVersion (SERIAL_PORT port, char *cmd, stParam *param);
int At_GetCusFwVersion (SERIAL_PORT port, char *cmd, stParam *param);
int At_GetCliVersion (SERIAL_PORT port, char *cmd, stParam *param);
int At_GetApiVersion (SERIAL_PORT port, char *cmd, stParam *param);
int At_GetHwModel (SERIAL_PORT port, char *cmd, stParam *param);
int At_GetHwID (SERIAL_PORT port, char *cmd, stParam *param);
int At_Alias (SERIAL_PORT port, char *cmd, stParam *param);
int At_GetSysVolt (SERIAL_PORT port, char *cmd, stParam *param);
int At_Bootver (SERIAL_PORT port, char *cmd, stParam *param);
#endif
#if defined(rak3172) || defined(rak3172T)
int At_GetUid (SERIAL_PORT port, char *cmd, stParam *param);
#endif
#ifdef SUPPORT_BLE
int At_BLEMac (SERIAL_PORT port, char *cmd, stParam *param);
int At_BLEDTM (SERIAL_PORT port, char *cmd, stParam *param);
#endif

#endif //_ATCMD_GENERAL_H_
