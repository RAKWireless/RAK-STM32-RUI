#ifndef _UHAL_CRYPTO_H_
#define _UHAL_CRYPTO_H_
#include "stm32wlxx_hal.h"
int uhal_cyrpto_set_key(uint8_t *pKey, uint16_t keySize);
int uhal_cyrpto_set_iv(unsigned char *pIV, uint16_t ivSize);
int uhal_crypto_aes_ecb_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);
int uhal_crypto_aes_ecb_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);
int uhal_crypto_aes_cbc_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);
int uhal_crypto_aes_cbc_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);
int uhal_crypto_aes_ctr_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);
int uhal_crypto_aes_ctr_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize);

#endif
