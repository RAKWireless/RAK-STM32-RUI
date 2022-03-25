/**
  ******************************************************************************
  * @file    se_low_level.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for Secure Engine low level interface
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
#ifndef SE_LOW_LEVEL_H
#define SE_LOW_LEVEL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "se_def.h"

/* Secure Engine needs to know the slots configuration for the Read/Write services in protected area
   (see @ref SE_IMG_Write, see @ref SE_IMG_Read) */
#include "sfu_fwimg_regions.h"

#include "stm32wlxx_hal.h"

/** @addtogroup SE
  * @{
  */

/** @addtogroup SE_HARDWARE
  * @{
  */

/** @defgroup SE_HARDWARE_Exported_Constants Exported Constants
  * @{
  */
/**
  * @brief flash handling constants: these constants are used in se_fwimg.c
  */

/**
  * @}
  */

/** @defgroup SE_HARDWARE_Exported_Macros Exported Macros
  * @{
  */

/** @defgroup SE_HARDWARE_Exported_Macros_CRC CRC Settings
  * @{
  */

/**
  * @brief Set CRC 32 of the BootInfoTypeDef pointer passed as parameter
  * The CRC is computed with the structure without its CRC field and the length is provided to SE_CRC_Calculate in
  * 32-bit word.
  * Please note that this works only if the CRC field is kept as the last uint32_t of the SE_BootInfoTypeDef structure.
  */
#define SE_BOOT_CONFIG_SET_CRC_32(x)    \
  do{                                  \
    (x)->CRC32 = SE_CRC_Calculate ((uint32_t*)(x), (sizeof(SE_BootInfoTypeDef)-sizeof(uint32_t))/sizeof(uint32_t));\
  }while(0)

/**
  * @brief Set CRC of the BootInfoTypeDef pointer passed as parameter
  */
#define SE_BOOT_CONFIG_SET_CRC(x)      SE_BOOT_CONFIG_SET_CRC_32(x)

/**
  * @}
  */

/** @defgroup SE_HARDWARE_Exported_Macros_CodeIsolation Code Isolation Settings
  * @brief These settings configure the way the Secure Engine is isolated from the rest of the code.
  * @{
  */

/**
  * MPU : Enter/Exit secured area ==> nothing to do
  */
#define ENTER_PROTECTED_AREA() do { /* do nothing */; } while(0)
#define EXIT_PROTECTED_AREA() do { /* do nothing */; } while(0)

/** @addtogroup SE_LOW_LEVEL_Exported_Functions
  * @{
  */
void SE_LL_CORE_Cleanup(void);

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup SE_HARDWARE_Exported_Functions
  * @{
  */

/** @addtogroup SE_HARDWARE_Exported_CRC_Functions
  * @{
  */
SE_ErrorStatus SE_LL_CRC_Config(void);
SE_ErrorStatus SE_LL_CRC_Init(void);
SE_ErrorStatus SE_LL_CRC_DeInit(void);
uint32_t SE_LL_CRC_Calculate(uint32_t pBuffer[], uint32_t uBufferLength);

/**
  * @}
  */

/** @addtogroup SE_HARDWARE_Exported_FLASH_Functions
  * @{
  */
SE_ErrorStatus SE_LL_FLASH_Erase(uint8_t *pStart, uint32_t Length);
SE_ErrorStatus SE_LL_FLASH_Write(uint8_t *pDestination, const uint8_t *pSource, uint32_t Length);
SE_ErrorStatus SE_LL_FLASH_Read(uint8_t *pDestination, const uint8_t *pSource, uint32_t Length);

void NMI_Handler(void);
void HardFault_Handler(void);
/**
  * @}
  */

/** @addtogroup SE_HARDWARE_Exported_FLASH_EXT_Functions
  * @{
  */
SE_ErrorStatus SE_LL_FLASH_EXT_Decrypt_Init(SE_FwRawHeaderTypeDef *pxSE_Metadata);
/**
  * @}
  */

/** @addtogroup SE_BUFFER_CHECK_Exported_RAM_Functions
  * @{
  */

SE_ErrorStatus SE_LL_Buffer_in_ram(void *pBuff, uint32_t Length);
SE_ErrorStatus SE_LL_Buffer_in_SBSFU_ram(const void *pBuff, uint32_t Length);
SE_ErrorStatus SE_LL_Buffer_part_of_SE_ram(const void *pBuff, uint32_t Length);
SE_ErrorStatus SE_LL_Buffer_part_of_SE_rom(const void *pBuff, uint32_t Length);
/**
  * @}
  */

/** @addtogroup SE_LOCK_KEYS_Exported_Functions
  * @{
  */
SE_ErrorStatus SE_LL_Lock_Keys(void);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* SE_LOW_LEVEL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

