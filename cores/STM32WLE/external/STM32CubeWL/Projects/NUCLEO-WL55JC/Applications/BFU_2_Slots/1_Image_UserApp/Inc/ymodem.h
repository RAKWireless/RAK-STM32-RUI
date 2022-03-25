/**
  ******************************************************************************
  * @file    ymodem.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for Ymodem functionalities.
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
#ifndef YMODEM_H_
#define YMODEM_H_

/** @addtogroup USER_APP User App Example
  * @{
  */

/** @addtogroup  FW_UPDATE Firmware Update Example
  * @{
  */
/* Compiler switches ---------------------------------------------------------*/
#ifndef MINICOM_YMODEM /* Avoid redefinition from app_sfu.h */
/* Uncomment the switch below if you are using Minicom (Linux) */
/* YMODEM protocol handled by Minicom instead of Teraterm: 128B packets instead of 1kB packets */
/* #define MINICOM_YMODEM */
#endif /* MINICOM_YMODEM */
/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/

typedef enum
{
  COM_OK       = 0x00U,  /*!< OK */
  COM_ERROR    = 0x01U,  /*!< Error */
  COM_ABORT    = 0x02U,  /*!< Abort */
  COM_TIMEOUT  = 0x03U,  /*!< Timeout */
  COM_DATA     = 0x04U,  /*!< Data */
  COM_LIMIT    = 0x05U   /*!< Limit*/
} COM_StatusTypeDef;     /*!< Comm status structures definition */

typedef struct
{
  HAL_StatusTypeDef(* Ymodem_HeaderPktRxCpltCallback)(uint32_t uFileSize);
  HAL_StatusTypeDef(* Ymodem_DataPktRxCpltCallback)(uint8_t *pData, uint32_t uFlashDestination, uint32_t uSize);
} YMODEM_CallbacksTypeDef;

/* Exported constants --------------------------------------------------------*/
/* Packet structure defines */
#ifndef MINICOM_YMODEM
/* Teraterm YMODEM */
#define PACKET_HEADER_SIZE      ((uint32_t)3U)    /*!<Header Size*/
#define PACKET_DATA_INDEX       ((uint32_t)4U)    /*!<Data Index*/
#define PACKET_START_INDEX      ((uint32_t)1U)    /*!<Start Index*/
#define PACKET_NUMBER_INDEX     ((uint32_t)2U)    /*!<Packet Number Index*/
#define PACKET_CNUMBER_INDEX    ((uint32_t)3U)    /*!<Cnumber Index*/
#else
/* Minicom YMODEM */
#define PACKET_HEADER_SIZE      ((uint32_t)6U)    /*!<Header Size*/
#define PACKET_DATA_INDEX       ((uint32_t)7U)    /*!<Data Index*/
#define PACKET_START_INDEX      ((uint32_t)4U)    /*!<Start Index*/
#define PACKET_NUMBER_INDEX     ((uint32_t)5U)    /*!<Packet Number Index*/
#define PACKET_CNUMBER_INDEX    ((uint32_t)6U)    /*!<Cnumber Index*/
#endif /* MINICOM_YMODEM */
#define PACKET_TRAILER_SIZE     ((uint32_t)2U)    /*!<Trailer Size*/
#define PACKET_OVERHEAD_SIZE    (PACKET_HEADER_SIZE + PACKET_TRAILER_SIZE - 1U) /*!<Overhead Size*/
#define PACKET_SIZE             ((uint32_t)128U)  /*!<Packet Size*/
#define PACKET_1K_SIZE          ((uint32_t)1024U) /*!<Packet 1K Size*/

/* /-------- Packet in IAP memory ------------------------------------------\
 * | 0      |  1    |  2     |  3   |  4      | ... | n+4     | n+5  | n+6  |
 * |------------------------------------------------------------------------|
 * | unused | start | number | !num | data[0] | ... | data[n] | crc0 | crc1 |
 * \------------------------------------------------------------------------/
 * the first byte is left unused for memory alignment reasons                 */

#define FILE_NAME_LENGTH        ((uint32_t)64U)  /*!< File name length*/
#define FILE_SIZE_LENGTH        ((uint32_t)16U)  /*!< File size length*/

#define SOH                     ((uint8_t)0x01U)  /*!< start of 128-byte data packet */
#define STX                     ((uint8_t)0x02U)  /*!< start of 1024-byte data packet */
#define EOT                     ((uint8_t)0x04U)  /*!< end of transmission */
#define ACK                     ((uint8_t)0x06U)  /*!< acknowledge */
#define NAK                     ((uint8_t)0x15U)  /*!< negative acknowledge */
#define CA                      ((uint8_t)0x18U)  /*!< two of these in succession aborts transfer */
#define CRC16                   ((uint8_t)0x43U)  /*!< 'C' == 0x43, request 16-bit CRC */
#define RB                      ((uint8_t)0x72U)  /*!< Startup sequence */
#define NEGATIVE_BYTE           ((uint8_t)0xFFU)  /*!< Negative Byte*/

#define ABORT1                  ((uint8_t)0x41U)  /* 'A' == 0x41, abort by user */
#define ABORT2                  ((uint8_t)0x61U)  /* 'a' == 0x61, abort by user */

#define NAK_TIMEOUT             ((uint32_t)0x100000U)  /*!< NAK Timeout*/
#define DOWNLOAD_TIMEOUT        ((uint32_t)1000U) /* One second retry delay */
#define MAX_ERRORS              ((uint32_t)5U)    /*!< Maximum number of retry*/

/* Exported functions ------------------------------------------------------- */
void Ymodem_Init(void);
COM_StatusTypeDef Ymodem_Receive(uint32_t *puSize, uint32_t uFlashDestination, YMODEM_CallbacksTypeDef *appCb);

/**
  * @}
  */

/**
  * @}
  */

#endif  /* YMODEM_H_ */

/*******************(C)COPYRIGHT STMicroelectronics ********END OF FILE********/
