/**
  ******************************************************************************
  * @file    mapping_fwimg.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for firmware images mapping
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
#ifndef MAPPING_FWIMG_H
#define MAPPING_FWIMG_H

/* Slots  must be aligned on 2048 bytes (0x800) */

/* swap  (4 kbytes) */
#define SWAP_START                   0x08005800
#define SWAP_END                     0x080067FF

/* Active slot #1  (56 kbytes) */
#define SLOT_ACTIVE_1_HEADER         0x0803F800
#define SLOT_ACTIVE_1_START          0x0801C000
#define SLOT_ACTIVE_1_END            0x08029FFF

/* Active slot #2  (28 kbytes) */
#define SLOT_ACTIVE_2_HEADER         0x0803F000
#define SLOT_ACTIVE_2_START          0x08015000
#define SLOT_ACTIVE_2_END            0x0801BFFF

/* Dwl slot #1  (56 kbytes) */
#define SLOT_DWL_1_START             0x08006800
#define SLOT_DWL_1_END               0x080147FF

/* Slots not configured */
#define SLOT_ACTIVE_3_HEADER         0x00000000
#define SLOT_ACTIVE_3_START          0x00000000
#define SLOT_ACTIVE_3_END            0x00000000
#define SLOT_DWL_2_START             0x00000000
#define SLOT_DWL_2_END               0x00000000
#define SLOT_DWL_3_START             0x00000000
#define SLOT_DWL_3_END               0x00000000

#endif
