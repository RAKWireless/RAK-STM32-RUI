/**
  ******************************************************************************
  * @file    fw_update_app.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for Firmware Update module
  *          functionalities.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef FW_UPDATE_APP_H
#define FW_UPDATE_APP_H

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

void FW_UPDATE_Run(void);
void FW_UPDATE_MULTIPLE_RunMenu(void);
void FW_VALIDATE_RunMenu(void);

#ifdef __cplusplus
}
#endif

#endif /* FW_UPDATE_APP_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

