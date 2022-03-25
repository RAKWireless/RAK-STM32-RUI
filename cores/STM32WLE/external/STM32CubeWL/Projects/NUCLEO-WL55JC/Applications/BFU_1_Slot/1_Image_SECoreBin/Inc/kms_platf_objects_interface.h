/**
  ******************************************************************************
  * @file    kms_platf_objects_interface.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for Key Management Services (KMS)
  *          module platform objects management configuration interface
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#ifndef KMS_PLATF_OBJECTS_INTERFACE_H
#define KMS_PLATF_OBJECTS_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

/* KMS exported Object handles for Secure Boot */

/* SBSFU Root CA Certificate */
#define KMS_SBSFU_ROOT_CA_CRT_LABEL           "SBSFURootCACertificate"  /*!< SBSFU Root CA Certificate Label */
#define KMS_SBSFU_ROOT_CA_CRT_OBJECT_HANDLE   ((CK_OBJECT_HANDLE)9)  /*!< SBSFU Root CA Certificate object handle */

/* OEM Interm CA Certificate */
#define KMS_SBSFU_OEM_INTM_CA_CRT_1_LABEL           "OEMIntermCACertificate_1"  /*!< OEM 1 Interm CA Certificate */
#define KMS_SBSFU_OEM_INTM_CA_CRT_2_LABEL           "OEMIntermCACertificate_2"  /*!< OEM 2 Interm CA Certificate */
#define KMS_SBSFU_OEM_INTM_CA_CRT_3_LABEL           "OEMIntermCACertificate_3"  /*!< OEM 3 Interm CA Certificate */
#define KMS_SBSFU_OEM_INTM_CA_CRT_1_OBJECT_HANDLE   ((CK_OBJECT_HANDLE)10)  /*!< OEM 1 Interm CA Certificate object handle */
#define KMS_SBSFU_OEM_INTM_CA_CRT_2_OBJECT_HANDLE   ((CK_OBJECT_HANDLE)11)  /*!< OEM 2 Interm CA Certificate object handle */
#define KMS_SBSFU_OEM_INTM_CA_CRT_3_OBJECT_HANDLE   ((CK_OBJECT_HANDLE)12)  /*!< OEM 3 Interm CA Certificate object handle */


#define KMS_SBSFU_KEY_1_AES128_OBJECT_HANDLE            ((CK_OBJECT_HANDLE)3)
#define KMS_SBSFU_KEY_2_AES128_OBJECT_HANDLE            ((CK_OBJECT_HANDLE)4)
#define KMS_SBSFU_KEY_3_AES128_OBJECT_HANDLE            ((CK_OBJECT_HANDLE)5)
#define KMS_SBSFU_KEY_1_ECDSA_OBJECT_HANDLE             ((CK_OBJECT_HANDLE)6)
#define KMS_SBSFU_KEY_2_ECDSA_OBJECT_HANDLE             ((CK_OBJECT_HANDLE)7)
#define KMS_SBSFU_KEY_3_ECDSA_OBJECT_HANDLE             ((CK_OBJECT_HANDLE)8)

/* KMS exported Object handles for tKMS test application */
#define KMS_KEY_RSA2048_OBJECT_HANDLE                 ((CK_OBJECT_HANDLE)21)
#define KMS_KEY_AES128_OBJECT_HANDLE                  ((CK_OBJECT_HANDLE)13)
#define KMS_KEY_AES256_OBJECT_HANDLE                  ((CK_OBJECT_HANDLE)14)
#define KMS_KEY_AES128_DERIVABLE_OBJECT_HANDLE        ((CK_OBJECT_HANDLE)22)

#ifdef __cplusplus
}
#endif

#endif /* KMS_PLATF_OBJECTS_INTERFACE_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

