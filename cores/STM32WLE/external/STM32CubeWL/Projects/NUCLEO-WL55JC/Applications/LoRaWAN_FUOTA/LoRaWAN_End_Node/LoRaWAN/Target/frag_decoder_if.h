/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    frag_decoder_if.h
  * @author  MCD Application Team
  * @brief   Applicative interfaces of LoRa-Alliance fragmentation decoder
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FRAG_DECODER_IF_H__
#define __FRAG_DECODER_IF_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sfu_fwimg_regions.h"
#include "LmhpFragmentation.h"

/* USER CODE BEGIN include */

/* USER CODE END include */

/* Exported defines ----------------------------------------------------------*/
#define INTEROP_TEST_MODE                           0

#if (INTEROP_TEST_MODE == 1)
/*!
  * Maximum number of fragment that can be handled.
  *
  * \remark This parameter has an impact on the memory footprint.
  */
#define FRAG_MAX_NB                                 20

/*!
  * Maximum fragment size that can be handled.
  *
  * \remark This parameter has an impact on the memory footprint.
  */
#define FRAG_MAX_SIZE                               50

/*!
  * Maximum number of extra frames that can be handled.
  *
  * \remark This parameter has an impact on the memory footprint.
  */
#define FRAG_MAX_REDUNDANCY                         5

#else /* INTEROP_TEST_MODE == 0 */
/*!
  * Maximum number of fragment that can be handled.
  *
  * \remark This parameter has an impact on the memory footprint.
  * \note FRAG_MAX_NB = (SLOT_DWL_1_END - SLOT_DWL_1_START) / FRAG_MAX_SIZE
  */
#define FRAG_MAX_NB                                 716

/*!
  * Maximum fragment size that can be handled.
  *
  * \remark This parameter has an impact on the memory footprint.
  */
#define FRAG_MAX_SIZE                               120

/*!
  * Maximum number of extra frames that can be handled.
  *
  * \remark This parameter has an impact on the memory footprint.
  * \note FRAG_MAX_NB * 0.10 (with redundancy = 10 %)
  */
#define FRAG_MAX_REDUNDANCY                         72

#endif /* INTEROP_TEST_MODE */

#define FRAG_DECODER_SWAP_REGION_START              ((uint32_t)(SlotStartAdd[SLOT_SWAP]))

#define FRAG_DECODER_SWAP_REGION_SIZE               ((uint32_t)(SlotEndAdd[SLOT_SWAP] - SlotStartAdd[SLOT_SWAP] + 1U))

#define FRAG_DECODER_DWL_REGION_START               ((uint32_t)(SlotStartAdd[SLOT_DWL_1]))

#define FRAG_DECODER_DWL_REGION_SIZE                ((uint32_t)(SlotEndAdd[SLOT_DWL_1] - SlotStartAdd[SLOT_DWL_1] + 1U))

/* USER CODE BEGIN ED */

/* USER CODE END ED */

/* Exported types ------------------------------------------------------------*/

/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* External variables --------------------------------------------------------*/
extern const LmhpFragmentationParams_t FRAG_DECODER_IF_FragmentationParams;

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions ------------------------------------------------------- */

/**
  * Initialize final uncoded data buffer
  *
  * \retval status Write operation status [0: Success, -1 Fail]
  */
int32_t FRAG_DECODER_IF_Erase(void);

/**
  * Writes `data` buffer of `size` starting at address `addr`
  *
  * \param [IN] addr Address start index to write to.
  * \param [IN] data Data buffer to be written.
  * \param [IN] size Size of data buffer to be written.
  *
  * \retval status Write operation status [0: Success, -1 Fail]
  */
int32_t FRAG_DECODER_IF_Write(uint32_t addr, uint8_t *data, uint32_t size);

/**
  * Reads `data` buffer of `size` starting at address `addr`
  *
  * \param [IN] addr Address start index to read from.
  * \param [IN] data Data buffer to be read.
  * \param [IN] size Size of data buffer to be read.
  *
  * \retval status Read operation status [0: Success, -1 Fail]
  */
int32_t FRAG_DECODER_IF_Read(uint32_t addr, uint8_t *data, uint32_t size);

/**
  * Notifies the progress of the current fragmentation session
  *
  * \param [IN] fragCounter Fragment counter
  * \param [IN] fragNb      Number of fragments
  * \param [IN] fragSize    Size of fragments
  * \param [IN] fragNbLost  Number of lost fragments
  */
void FRAG_DECODER_IF_OnProgress(uint16_t fragCounter, uint16_t fragNb, uint8_t fragSize, uint16_t fragNbLost);

/**
  * Notifies that the fragmentation session is finished
  *
  * \param [IN] status Fragmentation session status [FRAG_SESSION_ONGOING,
  *                                                  FRAG_SESSION_FINISHED or
  *                                                  FragDecoder.Status.FragNbLost]
  * \param [IN] size   Received file size
  */
void FRAG_DECODER_IF_OnDone(int32_t status, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif /* __FRAG_DECODER_IF_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
