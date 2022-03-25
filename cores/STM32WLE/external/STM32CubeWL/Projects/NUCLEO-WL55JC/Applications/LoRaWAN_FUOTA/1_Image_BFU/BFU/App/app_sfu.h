/**
  ******************************************************************************
  * @file    app_sfu.h
  * @author  MCD Application Team
  * @brief   This file contains the configuration of SBSFU application.
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
#ifndef APP_SFU_H
#define APP_SFU_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "se_crypto_config.h"

/* Exported constants --------------------------------------------------------*/
/**
  * Use this define to choose the type of Firmware Image Programming you want to use.
  * This version supports only 2 modes:
  *
  * SFU_ENCRYPTED_IMAGE: Encrypted Firmware Image
  *       The image is received in encrypted format.
  *       The image must be decrypted to be installed:
  *         this is done according to the selected crypto scheme,
  *         see @ref SECBOOT_CRYPTO_SCHEME in the SE_CoreBin part.
  *
  * SFU_CLEAR_IMAGE: Clear Firmware Image
  *       The image is received in clear format.
  *       No decrypt operation is needed before installing the image:
  *         the selected crypto scheme must be compatible with this choice,
  *         see @ref SECBOOT_CRYPTO_SCHEME in the SE_CoreBin part.
  *
  *
  */
#if  SECBOOT_CRYPTO_SCHEME == SECBOOT_ECCDSA_WITHOUT_ENCRYPT_SHA256
#define SFU_IMAGE_PROGRAMMING_TYPE SFU_CLEAR_IMAGE
#else
#define SFU_IMAGE_PROGRAMMING_TYPE SFU_ENCRYPTED_IMAGE
#endif /* SECBOOT_CRYPTO_SCHEME */

#define SFU_ENCRYPTED_IMAGE (0U) /*!< The Firmware Image to be installed is downloaded in ENCRYPTED format */
#define SFU_CLEAR_IMAGE     (1U) /*!< The Firmware Image to be installed is downloaded in CLEAR format */

#define SFU_DEBUG_MODE               /*!< Comment this define to optimize memory footprint (debug mode removed)
                                          No more print on terminal during SBSFU execution */

/*#define SFU_VERBOSE_DEBUG_MODE*/   /*!< Uncomment this define when in verbose Debug mode.
                                          this switch activates more debug prints in the console (FSM state info...) */


/*#define SFU_FWIMG_BLOCK_ON_ABNORMAL_ERRORS_MODE*/  /*!< You may uncomment this define when running development tests.
                                                          When this switch is activated, the FWIMG part of SB_SFU will
                                                          block when an abnormal error is encountered */

#if defined(SFU_VERBOSE_DEBUG_MODE) && !defined(SFU_DEBUG_MODE)
#error You cannot activate SFU_VERBOSE_DEBUG_MODE without activating SFU_DEBUG_MODE too.
#endif /* SFU_VERBOSE_DEBUG_MODE && !SFU_DEBUG_MODE */

#if defined(SFU_FWIMG_BLOCK_ON_ABNORMAL_ERRORS_MODE) && !defined(SFU_DEBUG_MODE)
#error SFU_FWIMG_BLOCK_ON_ABNORMAL_ERRORS_MODE is meant to be used in DEBUG mode
#endif /* SFU_FWIMG_BLOCK_ON_ABNORMAL_ERRORS_MODE && !SFU_DEBUG_MODE */

/*#define SFU_TEST_PROTECTION*/       /*!< Auto-test of protections : WRP, PCROP, MPU, FWALL.
                                           Automatically executed @startup */
#if defined(SFU_TEST_PROTECTION)
#undef SFU_DEBUG_MODE                 /*!< Remove definition to optimize memory footprint (debug mode removed) */
#endif /* SFU_TEST_PROTECTION */

/**
  * SB_SFU status LED.
  * The constants below define the LED to be used and the LED blinking frequency to identify some situations.
  * This is useful when no log is enabled.
  *
  * \li The LED blinks every see @ref SFU_COM_YMODEM_DOWNLOAD_TIMEOUT seconds when a local download is waited.
  * \li For the other situations, please check the other defines below.
  */
#define SFU_STATUS_LED (LED_GREEN)            /*!< LED to be used to provide the SB_SFU status to the end-user */
#define SFU_STOP_NO_FW_BLINK_DELAY     (100U) /*!< Blinks every 100ms when no valid firmware is available and the local
                                                   loader feature is disabled - see @ref SECBOOT_USE_LOCAL_LOADER */
#define SFU_INCORRECT_OB_BLINK_DELAY   (250U) /*!< Blinks every 250ms when an Option Bytes issue is detected */


/**
  * Optional Features Software Configuration
  */
#if !defined(SFU_TEST_PROTECTION)
#define SECBOOT_LOADER SECBOOT_USE_LOCAL_LOADER    /*!< Loader selection inside SBSFU : local/standalone/none */
#else
#define SECBOOT_LOADER SECBOOT_USE_NO_LOADER       /*!< No loader usage forced when SFU_TEST_PROTECTION is set */
#endif /* SFU_TEST_PROTECTION */

#define SECBOOT_USE_LOCAL_LOADER              (1U) /*!< local loader feature integrated into SBSFU (YMODEM over UART) */
#define SECBOOT_USE_STANDALONE_LOADER         (2U) /*!< standalone loader : see specific loader project  */
#define SECBOOT_USE_NO_LOADER                 (3U) /*!< no loader capability at SBSFU stage */

/* Uncomment the define below if you want to use minicom with Linux */
/* #define MINICOM_YMODEM */                       /*!< YMODEM protocol handled by MINICOM (Linux): 128 bytes packets */

#if defined(MINICOM_YMODEM)
/* Minicom does not accept the debug prints during the YMODEM session */
#undef SFU_VERBOSE_DEBUG_MODE
#endif /* MINICOM_YMODEM */

/* Uncomment the define below if you want to remove the swap area
   ==> partial update is not supported in this configuration
   ==> image validation is not supported in this configuration */
/*#define SFU_NO_SWAP*/                              /*!< FW upgrade installation process without swap area */

/* Multi-images configuration :
   - Max : 3 Active images and 3 Download area
   - Not necessary same configuration between SFU_NB_MAX_ACTIVE_IMAGE and SFU_NB_MAX_DWL_AREA
   - Active slot identified with SFU magic (1,2,3) information from header
   - Do not forget to add keys for each image in SE_Corebin/Binary folder
   - Master slot : image started in priority if valid
   - FW image valid all feature authorized from master slot
*/
#define SFU_NB_MAX_ACTIVE_IMAGE 1U                        /*!< 1 active image managed */
#define SFU_NB_MAX_DWL_AREA     1U                        /*!< 1 dwl area managed */
#define MASTER_SLOT             SLOT_ACTIVE_1             /*!< SLOT_ACTIVE_1 identified as master slot */


/* The define below allows disabling all security IPs at once.
 *
 * Enabled: all security IPs (WRP, watchdog...) are disabled.
 * Disabled: the security IPs can be used (if their specific compiler switches are enabled too).
 *
 */

#define SECBOOT_DISABLE_SECURITY_IPS  /*!< Disable all security IPs at once when activated */


#if !defined(SECBOOT_DISABLE_SECURITY_IPS)

/* Uncomment the following defines when in Release mode.
   In debug mode it can be better to disable some of the following protection
   for a better Debug experience (WRP, RDP, IWDG, DAP, etc.) */

#define SFU_WRP_PROTECT_ENABLE
#define SFU_RDP_PROTECT_ENABLE
/*#define SFU_TAMPER_PROTECT_ENABLE */  /*!< WARNING : Tamper protection deactivated. As the tamper tamper pin is
                                             neither connected to GND nor to 5V (floating level), there are too many
                                             spurious tamper event detected */
#define SFU_DAP_PROTECT_ENABLE     /*!< WARNING: Be Careful if enabling this protection. Debugger will be disconnected.
                                        It might be difficult to reconnect the Debugger.*/
#define SFU_DMA_PROTECT_ENABLE
/* #define SFU_IWDG_PROTECT_ENABLE */   /*!< WARNING:
                                        1. Be Careful if enabling this protection. IWDG will be active also after
                                           switching to UserApp: a refresh is needed.
                                        2. The IWDG reload in the SB_SFU code will have to be tuned depending on your
                                           platform (flash size...)*/
#define SFU_MPU_PROTECT_ENABLE     /*!< MPU protection:
                                        Enables/Disables the MPU protection.
                                        If Secure Engine isolation is ensured by MPU (see SFU_ISOLATE_SE_WITH_MPU in
                                        SE_CoreBin\Inc\se_low_level.h), then this switch also enables/disables it, in
                                        addition to the overall MPU protection. */
#define SFU_MPU_USERAPP_ACTIVATION /*!< MPU protection during UserApp execution : Only active slot(s) considered as an
                                        executable area */


/*#define SFU_FINAL_SECURE_LOCK_ENABLE */   /*!< WARNING: Should be enabled at the end of product development and test
                                                 steps.
                                                 When enabling this lock, Static protections cannot be modified any more
                                                 and Debug is finally disabled. */

#if defined(SFU_FINAL_SECURE_LOCK_ENABLE)
#define SFU_PROTECT_RDP_LEVEL  (OB_RDP_LEVEL_2)  /*!< RDP level2 for product on the field. Final OB lock, Debug
                                                      completely disabled, OB update no more possible  */


#else
#define SFU_PROTECT_RDP_LEVEL  (OB_RDP_LEVEL_1)  /*!< RDP level is set as 1 for debugging purposes. A product on the
                                                      field should set it as Level2 */
#endif /* SFU_FINAL_SECURE_LOCK_ENABLE */

#endif /* !SECBOOT_DISABLE_SECURITY_IPS */

/**
  * The define below (SECBOOT_OB_DEV_MODE) determines if the OPTION BYTES should be handled in Development mode or not.
  * This define is taken into account only if RDP level 2 is not set.
  * If RDP level 2 is set no modification can be done anyway.
  *
  * Enabled: Option Bytes Development Mode enabled.
  *          SB_SFU uses a "check and apply" strategy when checking the Option Bytes configuration.
  *          If an OB is not set though it should be then this setting is automatically corrected.
  *          This applies only as long as RDP level 2 is not set.
  *
  * Disabled: Option Bytes Development Mode disabled.
  *           In this mode the Option Bytes are supposed to be already configured properly when the software starts for
              the first time.
  *           SB_SFU checks the Option Bytes configuration but does not correct it.
  *           If a problem is detected an error message is reported and the execution stops.
  */
#define SECBOOT_OB_DEV_MODE


#define SFU_IWDG_TIMEOUT  ((uint32_t)15) /*!< IWDG timeout in seconds (the max. value that can be set here depends on
                                              the prescaler settings: IWDG_PRESCALER_XXX. ) */


/**
  * Application Configuration
  *
  */
#define SFU_FW_VERSION_START_NUM (1U)    /*!< The very first version number a Firmware can have
                                              You can also define an upper bound here if you plan to use it */

#define SFU_FW_VERSION_INIT_NUM (1U)     /*!< The version number accepted when the header is not valid (either because 
                                              no FW installed or due to an attack attempt). Could be different from
                                              SFU_FW_VERSION_START_NUM */

/**
  * Features compatibility control
  */
#if defined(SFU_NO_SWAP) && defined(ENABLE_IMAGE_STATE_HANDLING)
#warning "ENABLE_IMAGE_STATE_HANDLING not compatible with SFU_NO_SWAP process"
#endif
#if defined(SFU_SECURE_USER_PROTECT_ENABLE) && defined(ENABLE_IMAGE_STATE_HANDLING)
#warning "ENABLE_IMAGE_STATE_HANDLING not compatible with SFU_SECURE_USER_PROTECT_ENABLE process"
#endif


#ifdef __cplusplus
}
#endif

#endif /* APP_SFU_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
