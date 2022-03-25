/**
  @page 1_Image_SECoreBin / Secure Engine Core binary generation.

  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    readme.txt
  * @brief   Secure Engine Core binary generation.
  *          SE Core binary exports SE CallGate function entry point for
  *          FU Application.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                               www.st.com/SLA0044
  *
  ******************************************************************************
  @endverbatim

@par Application Description

This application is used to generate Secure Engine Core binary file to be linked
with Boot & Firmware Update application (BFU).
SE Core binary exports a single entry point to SE CallGate function and a startup method for data initialization.
It is based on the Secure Engine Middleware.

Generated SE Core Binary embeds Key Management Services accessible through this same single entry point using APIs
defined by tKMS interface.

It has to be compiled before BFU project.

Three cryptographic schemes are provided as example to illustrate the cryptographic operations. The default
cryptographic scheme uses both symmetric (AES-CBC) and asymmetric (ECDSA) cryptography. Two alternate schemes are
provided and can be selected thanks to SECBOOT_CRYPTO_SCHEME compiler switch named :
   - SECBOOT_ECCDSA_WITH_AES128_CBC_SHA256 (default)
   - SECBOOT_ECCDSA_WITHOUT_ENCRYPT_SHA256
   - SECBOOT_AES128_GCM_AES128_GCM_AES128_GCM

For more details, refer to UM2262 "Getting started with SBSFU - software expansion for STM32Cube"
available from the STMicroelectronics microcontroller website www.st.com.

@par Keywords

Security, KMS, SBSFU

@par Directory contents

   - 1_Image_SECoreBin/Src/ca_low_level.c                      Low level implementations of the Cryptographic API (CA) module
   - 1_Image_SECoreBin/Src/kms_low_level.c                     Key Management Services low level interface
   - 1_Image_SECoreBin/Src/nvms_low_level.c                    Non volatile memory storage low level interface
   - 1_Image_SECoreBin/Src/se_low_level.c                      Low level interface
   - 1_Image_SECoreBin/Inc/ca_conf.h                           Configuration for Cryptographic API (CA) module functionalities
   - 1_Image_SECoreBin/Inc/ca_low_level.h                      Header for ca_low_level.c
   - 1_Image_SECoreBin/Inc/kms_config.h                        Key Management Services configuration file
   - 1_Image_SECoreBin/Inc/kms_low_level.h                     Header for kms_low_level.c
   - 1_Image_SECoreBin/Inc/kms_mem_pool_def.h                  KMS memory pool definition file
   - 1_Image_SECoreBin/Inc/kms_platf_objects_config.h.pattern  Header for Key Management Services embedded objects definitions pattern
                                                                Appropriate cryptographic scheme keys are injected into it by the prebuild script (see below)
   - 1_Image_SECoreBin/Inc/kms_platf_objects_interface.h       Header for Key Management Services embedded objects references (labels, IDs...)
                                                                Exported to KMS user to ease embedded object usage
   - 1_Image_SECoreBin/Inc/mbed_crypto_config.h                mbed-crypto configuration file
   - 1_Image_SECoreBin/Inc/nvms_low_level.h                    Header for nvms_low_level.c
   - 1_Image_SECoreBin/Inc/se_crypto_config.h                  Crypto scheme configuration (crypto scheme used by the bootloader)
   - 1_Image_SECoreBin/Inc/se_def_metadata.h                   Firmware metadata (header) definition
   - 1_Image_SECoreBin/Inc/se_low_level.h                      Header file for low level interface
   - 1_Image_SECoreBin/Inc/stm32wlxx_hal_conf.h                HAL configuration file
   - 1_Image_SECoreBin/Binary/ECCKEY1.txt                      Private ECCDSA key for signature verification
   - 1_Image_SECoreBin/Binary/nonce.bin                        Number used only once for firmware encryption
   - 1_Image_SECoreBin/Binary/OEM_KEY_COMPANY1_key_AES_CBC.bin Public key for AES CBC encryption
   - 1_Image_SECoreBin/Binary/OEM_KEY_COMPANY1_key_AES_GCM.bin Public key for AES GCM encryption

@par Hardware and Software environment

   - This example runs on STM32WL55xx devices
   - This example has been tested with NUCLEO-WL55JC RevC board and can be easily tailored to any other supported device and
     development board.
   - An up-to-date version of ST-LINK firmware is required. Upgrading ST-LINK firmware is a feature provided by
     STM32Cube programmer available on www.st.com.
   - Microsoft Windows has a limitation whereby paths to files and directories cannot be longer than 256 characters.
     Paths to files exceeding that limits cause tools (e.g. compilers, shell scripts) to fail reading from or writing
     to such files. As a workaround, it is advised to use the subst.exe command from within a command prompt to set up
     a local drive out of an existing directory on the hard drive, such as:
     C:\> subst X: <PATH_TO_CUBEFW>\Firmware

   
@par IDE prebuild script

In order to ease the development process, a prebuild script ("prebuild.bat") is integrated in each IDE project.
This preliminary processing is in charge of:
   - determining the requested cryptographic scheme
   - generating the appropriate keys in <IDE folder>/kms_platf_objects_config.h (from injection of BFU & Blob importation
     keys into the KMS embedded objects pattern file)
   - generating the appropriate script to prepare the firmware image ("postbuild.bat") when building the UserApp project

A known limitation of this integration occurs when you update a cryptographic parameter (for instance the cryptographic
key). The IDE does not track this update so you need to force the rebuild of the project manually.

@par How to use it ?

In order to generate Secure Engine Core binary file, you must do the following :
   - Open your preferred toolchain
   - Rebuild the project

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
