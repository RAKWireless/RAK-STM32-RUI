/**
 * @file        udrv_crypto.h
 * @brief       Provide a hardware independent AES Crypto driver layer for API layer to use.
 * @author      Rakwireless
 * @version     1.0.0
 * @date        2023.3
 */

#ifndef _UDRV_CRYPTO_H_
#define _UDRV_CRYPTO_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Set encryption/decryption AES key.
 * @retval int
 * 
 * @param  pKey                     encryption/decryption key
 * @param  keySize                  must be 16, 24 or 32
 * 
 * @return                          0 if successful
 */
int udrv_cyrpto_set_key(uint8_t *pKey, uint16_t keySize);

/**
 * @brief Set IV (initialization vector) key.
 * @retval int
 * 
 * @param  pIV                      initialization vector (updated after use) value
 * @param  ivSize                   must be 16
 * 
 * @return                          0 if successful
 */
int udrv_cyrpto_set_iv(unsigned char *pIV, uint16_t ivSize);

/**
 * @brief AES-ECB block encryption
 * @retval int
 * 
 * @param  input                    Buffer holding the input data
 * @param  inputSize                Input block size
 * @param  output                   Buffer holding the output data
 * @param  outputSize               Output block size (Size should be a multiple of 16 bytes)
 * 
 * @return                          0 if successful
 */
int udrv_crypto_aes_ecb_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);

/**
 * @brief AES-ECB block decryption
 * @retval int
 * 
 * @param  input                    Buffer holding the input data
 * @param  inputSize                Input block size
 * @param  output                   Buffer holding the output data
 * @param  outputSize               Output block size (Size should be a multiple of 16 bytes)
 * 
 * @return                          0 if successful
 */
int udrv_crypto_aes_ecb_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);

/**
 * @brief AES-CBC block encryption
 * @retval int
 * 
 * @param  input                    Buffer holding the input data
 * @param  inputSize                Input block size
 * @param  output                   Buffer holding the output data
 * @param  outputSize               Output block size (Size should be a multiple of 16 bytes)
 * 
 * @return                          0 if successful
 */
int udrv_crypto_aes_cbc_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);

/**
 * @brief AES-CBC block decryption
 * @retval int
 * 
 * @param  input                    Buffer holding the input data
 * @param  inputSize                Input block size
 * @param  output                   Buffer holding the output data
 * @param  outputSize               Output block size (Size should be a multiple of 16 bytes)
 * 
 * @return                          0 if successful
 */
int udrv_crypto_aes_cbc_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);

/**
 * @brief AES-CTR block encryption
 * @retval int
 * 
 * @param  input                    Buffer holding the input data
 * @param  inputSize                Input block size
 * @param  output                   Buffer holding the output data
 * @param  outputSize               Output block size (Size should be a multiple of 16 bytes)
 * 
 * @return                          0 if successful
 */
int udrv_crypto_aes_ctr_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);

/**
 * @brief AES-CTR block decryption
 * @retval int
 * 
 * @param  input                    Buffer holding the input data
 * @param  inputSize                Input block size
 * @param  output                   Buffer holding the output data
 * @param  outputSize               Output block size (Size should be a multiple of 16 bytes)
 * 
 * @return                          0 if successful
 */
int udrv_crypto_aes_ctr_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);

#ifdef __cplusplus
}
#endif

#endif //_UDRV_ADC_H_