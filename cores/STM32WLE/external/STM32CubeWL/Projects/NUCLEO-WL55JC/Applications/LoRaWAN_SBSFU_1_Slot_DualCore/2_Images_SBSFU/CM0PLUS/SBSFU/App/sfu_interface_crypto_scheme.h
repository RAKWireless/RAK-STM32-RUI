/**
  ******************************************************************************
  * @file    sfu_interface_crypto_scheme.c
  * @author  MCD Application Team
  * @brief   Secure Engine Interface module.
  *          This file provides set of firmware functions to manage SE Interface
  *          functionalities. These services are used by the bootloader.
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
#ifndef SFU_KMS_H
#define SFU_KMS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Exported functions ------------------------------------------------------- */
SE_ErrorStatus SFU_Decrypt_Init(SE_StatusTypeDef *peSE_Status, SE_FwRawHeaderTypeDef *pxSE_Metadata,
                                uint32_t SE_FwType);
SE_ErrorStatus SFU_Decrypt_Append(SE_StatusTypeDef *peSE_Status, const uint8_t *pInputBuffer, int32_t InputSize,
                                  uint8_t *pOutputBuffer, int32_t *pOutputSize);
SE_ErrorStatus SFU_Decrypt_Finish(SE_StatusTypeDef *peSE_Status, uint8_t *pOutputBuffer, int32_t *pOutputSize);
SE_ErrorStatus SFU_AuthenticateFW_Init(SE_StatusTypeDef *peSE_Status, SE_FwRawHeaderTypeDef *pxSE_Metadata,
                                       uint32_t SE_FwType);
SE_ErrorStatus SFU_AuthenticateFW_Append(SE_StatusTypeDef *peSE_Status, const uint8_t *pInputBuffer, int32_t InputSize,
                                         uint8_t *pOutputBuffer, int32_t *pOutputSize);
SE_ErrorStatus SFU_AuthenticateFW_Finish(SE_StatusTypeDef *peSE_Status, uint8_t *pOutputBuffer, int32_t *pOutputSize);
SE_ErrorStatus SFU_VerifyHeaderSignature(SE_StatusTypeDef *peSE_Status, SE_FwRawHeaderTypeDef *pxFwRawHeader);

#define SE_Decrypt_Init( peSE_Status,  pxSE_Metadata, SE_FwType ) \
  SFU_Decrypt_Init( peSE_Status,  pxSE_Metadata, SE_FwType )

#define SE_Decrypt_Append( peSE_Status, pInputBuffer, InputSize, pOutputBuffer, pOutputSize ) \
  SFU_Decrypt_Append( peSE_Status, pInputBuffer, InputSize, pOutputBuffer, pOutputSize )

#define SE_Decrypt_Finish( peSE_Status, pOutputBuffer, pOutputSize ) \
  SFU_Decrypt_Finish( peSE_Status, pOutputBuffer, pOutputSize )


#define SE_AuthenticateFW_Init( peSE_Status, pxSE_Metadata, SE_FwType ) \
  SFU_AuthenticateFW_Init( peSE_Status, pxSE_Metadata, SE_FwType )

#define SE_AuthenticateFW_Append( peSE_Status, pInputBuffer, InputSize, pOutputBuffer, pOutputSize ) \
  SFU_AuthenticateFW_Append( peSE_Status, pInputBuffer, InputSize, pOutputBuffer, pOutputSize )

#define SE_AuthenticateFW_Finish( peSE_Status, pOutputBuffer, pOutputSize ) \
  SFU_AuthenticateFW_Finish( peSE_Status, pOutputBuffer, pOutputSize )

#define SE_VerifyHeaderSignature( peSE_Status, pxFwRawHeader ) \
  SFU_VerifyHeaderSignature( peSE_Status, pxFwRawHeader )

#ifdef __cplusplus
}
#endif


#endif /* SFU_KMS_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
