/**
  ******************************************************************************
  * @file    sfu_test.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for Test Protections functionalities.
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
#ifndef SFU_TEST_H
#define SFU_TEST_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "app_sfu.h"

#if defined(SFU_TEST_PROTECTION)

/* Exported types ------------------------------------------------------------*/
typedef enum
{
  TEST_WRITE_FLASH = 0U,                /* Writing test in FLASH */
  TEST_READ_FLASH,                      /* Reading test in FLASH */
  TEST_ERASE_FLASH,                     /* Erasing test in FLASH */
  TEST_WRITE_RAM,                       /* Writing test in RAM */
  TEST_READ_RAM,                        /* Reading test in RAM */
  TEST_EXECUTE,                         /* Execution function test */
  TEST_END,                             /* Last test : Success ! */
} TestType;

typedef enum
{
  TEST_IN_PROGRESS = 0U,                /* Test in progress */
  TEST_COMPLETED,                       /* Test ended : success */
  TEST_ERROR,                           /* Test aborted : error */
} TestStatus;


#define PROTECT_MSG_LEN (35U)           /* message to be displayed length           */
typedef struct
{
  uint32_t address;                     /* address to be tested */
  uint8_t msg[PROTECT_MSG_LEN];         /* message to be displayed when testing */
  TestType type;                        /* type of test */
} ProtectionTest_t;

/* Exported constants --------------------------------------------------------*/
/* Magic number saved in DR0 backup register */
#define MAGIC_TEST_DONE          0xAAA2
#define MAGIC_TEST_INIT          0xAAA3

/* Exported functions ------------------------------------------------------- */
void SFU_TEST_Init(void);
void SFU_TEST_Reset(void);
void SFU_TEST_Error(void);

#endif /* SFU_TEST_PROTECTION */

#ifdef __cplusplus
}
#endif

#endif /* SFU_TEST_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

