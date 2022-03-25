/*
 * @Author: Daniel
 * @Date: 2021-06-08 11:30:49
 * @LastEditTime: 2021-06-16 16:26:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \rui-v3-all\component\cli\atcmd_multicast.h
 */
#ifndef _ATCMD_MULTICAST_H_
#define _ATCMD_MULTICAST_H_
#include "atcmd.h"

int At_Addmulc(SERIAL_PORT port, char *cmd, stParam *param);
int At_Rmvmulc(SERIAL_PORT port, char *cmd, stParam *param);
int At_Lstmulc(SERIAL_PORT port, char *cmd, stParam *param);

#endif //_ATCMD_GENERAL_H_
