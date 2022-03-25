/**
  ******************************************************************************
  * @file    mapping_sbsfu.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for SBSFU mapping
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright(c) 2017 STMicroelectronics International N.V.
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
#ifndef MAPPING_SBSFU_H
#define MAPPING_SBSFU_H

/******************************************************************************/
/*                               M4 ROM section                               */
/******************************************************************************/

/* M4 SB Code region */
#define M4_SB_REGION_ROM_START          0x08000000
#define M4_SB_REGION_ROM_END            0x080057FF

/* ROM regions definition */
#define M4_SB_ROM_REGION_SIZE          (M4_SB_REGION_ROM_END - M4_SB_REGION_ROM_START + 0x1)

/******************************************************************************/
/*                               M0+ ROM section                              */
/******************************************************************************/

/* KMS Data Storage (NVMS) region protected area */
/* KMS Data Storage need for 2 images : 4 kbytes * 2 ==> 8 kbytes */
#define KMS_DATASTORAGE_START           0x0802A000
#define KMS_DATASTORAGE_END             0x0802BFFF

/* SE IF ROM: used to locate Secure Engine interface code out of MPU isolation     */
#define SE_IF_REGION_ROM_START          (KMS_DATASTORAGE_END + 0x1)
#define SE_IF_REGION_ROM_END            (SE_IF_REGION_ROM_START + 0x15FF)

/* SBSFU Code region */
#define SB_REGION_ROM_START             (SE_IF_REGION_ROM_END + 1)
#define SB_REGION_ROM_END               0x080367FF

/* M0 Vector table with alignment constraint on VECTOR_SIZE */
#define VECTOR_SIZE                     0x200
#define INTVECT_START                   (SB_REGION_ROM_END + 0x1)

/* SE Code region protected by MPU isolation */
#define SE_CODE_REGION_ROM_START        (INTVECT_START + VECTOR_SIZE)
#define SE_CALLGATE_REGION_ROM_START    (SE_CODE_REGION_ROM_START + 4)
#define SE_CALLGATE_REGION_ROM_END      (SE_CODE_REGION_ROM_START + 0xFF)

/* SE Startup                               */
#define SE_STARTUP_REGION_ROM_START     (SE_CALLGATE_REGION_ROM_END + 1)
#define SE_CODE_NOKEY_REGION_ROM_START  (SE_STARTUP_REGION_ROM_START + 0x100)

/* SE Embedded Keys */
#define SE_KEY_REGION_ROM_START         0x0803E800
#define SE_KEY_REGION_ROM_END           0x0803EFFF
#define SE_CODE_REGION_ROM_END          SE_KEY_REGION_ROM_END

/* ROM regions size definition */
#define KMS_DATASTORAGE_SIZE            (KMS_DATASTORAGE_END - KMS_DATASTORAGE_START + 0x1)
#define SE_IF_ROM_REGION_SIZE           (SE_IF_REGION_ROM_END - SE_IF_REGION_ROM_START + 0x1)
#define SB_ROM_REGION_SIZE              (SB_REGION_ROM_END - SB_REGION_ROM_START + 0x1)
#define SE_CALLGATE_REGION_ROM_SIZE     (SE_CALLGATE_REGION_ROM_END - SE_CALLGATE_REGION_ROM_START + 0x1)
#define SE_CODE_NOKEY_REGION_ROM_SIZE   (SE_KEY_REGION_ROM_START - SE_CODE_NOKEY_REGION_ROM_START)
#define SE_KEY_REGION_ROM_SIZE          (SE_KEY_REGION_ROM_END - SE_KEY_REGION_ROM_START + 0x1)
#define SE_ROM_REGION_SIZE              (SE_CODE_REGION_ROM_END - SE_CODE_REGION_ROM_START + 0x1)

/******************************************************************************/
/*                              RAM section                                   */
/*                                                                            */
/******************************************************************************/

/* M4 SB */
#define M4_SB_REGION_RAM_START          0x20000000
#define M4_SB_REGION_RAM_END            (M4_SB_REGION_RAM_START + 0xCDF)

/* M0+/M4 Synchronization flag */
#define M4_M0PLUS_FLAG_RAM_START        (M4_SB_REGION_RAM_END + 0x1)
#define M4_M0PLUS_FLAG_RAM_END          (M4_M0PLUS_FLAG_RAM_START + 0x1F)

/* M4 UserApp : allocation limited to half RAM size */
#define M4_APP_REGION_RAM_START         (M4_M0PLUS_FLAG_RAM_END + 0x1)
#define M4_APP_REGION_RAM_END           0x20007FFF

/* SBSFU RAM region */
#define SB_REGION_RAM_START             (M4_APP_REGION_RAM_END + 0x1)
#define SB_REGION_RAM_END               0x2000D3FF

/* SE RAM region protected area with 1 kBytes alignment constraint (TZIC) ==> 0x2000D400 */
#define SE_REGION_RAM_START             (SB_REGION_RAM_END +0x1)
#define SE_REGION_RAM_STACK_TOP         0x2000DB00                /* Secure Engine's private stack */
#define SE_REGION_RAM_END               0x2000FFFF

/* RAM regions definition */
#define M4_SB_RAM_REGION_SIZE           (M4_SB_REGION_RAM_END - M4_SB_REGION_RAM_START + 0x1)
#define M4_APP_RAM_REGION_SIZE          (M4_APP_REGION_RAM_END - M4_APP_REGION_RAM_START + 0x1)
#define SB_RAM_REGION_SIZE              (SB_REGION_RAM_END - SB_REGION_RAM_START + 0x1)
#define SE_RAM_REGION_SIZE              (SE_REGION_RAM_END - SE_REGION_RAM_STACK_TOP + 0x1)

#endif

