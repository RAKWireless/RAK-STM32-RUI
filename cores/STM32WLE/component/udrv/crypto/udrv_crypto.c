#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "uhal_crypto.h"
#include "udrv_crypto.h"

int udrv_cyrpto_set_key(uint8_t *pKey, uint16_t keySize)
{
    return uhal_cyrpto_set_key(pKey, keySize);
}

int udrv_cyrpto_set_iv(unsigned char *pIV, uint16_t ivSize)
{
    return uhal_cyrpto_set_iv(pIV, ivSize);
}

int udrv_crypto_aes_ecb_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    return uhal_crypto_aes_ecb_encrypt(input, inputSize, 
                                       output, outputSize);
}

int udrv_crypto_aes_ecb_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    return uhal_crypto_aes_ecb_decrypt(input, inputSize, 
                                       output, outputSize);
}

int udrv_crypto_aes_cbc_encrypt(char *input, uint16_t inputSize, 
                                 unsigned char *output, uint16_t outputSize)
{
    return uhal_crypto_aes_cbc_encrypt(input, inputSize, 
                                       output, outputSize);
}

int udrv_crypto_aes_cbc_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    return uhal_crypto_aes_cbc_decrypt(input, inputSize, 
                                       output, outputSize);   
}

int udrv_crypto_aes_ctr_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    return uhal_crypto_aes_ctr_encrypt(input, inputSize, 
                                       output, outputSize);
}

int udrv_crypto_aes_ctr_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    return uhal_crypto_aes_ctr_decrypt(input, inputSize, 
                                       output, outputSize);  
}