#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "aes.h"

#include "uhal_crypto.h"
#include "udrv_errno.h"
#include "stm32wlxx_hal_cryp.h"
#define AES128_SIZE 16
#define AES192_SIZE 24
#define AES256_SIZE 32
typedef enum
{
    TYPE_ENCRYPT = 0,
    TYPE_DECRYPT = 1
} AES_Crypt_type_t;

/*
Modes:  ECB (Electronic Code Book) 
        CBC (Cipher Block Chaining) 
        CFB (Cipher FeedBack) 
        OFB (Output FeedBack)
        CTR (Counter)
*/ 
typedef enum 
{
    AES_MODE_ECB,
    AES_MODE_CBC,
    //AES_MODE_CFB,
    //AES_MODE_OFB,
    AES_MODE_CTR
} AES_mode_t;

CRYP_HandleTypeDef hcryp;
DMA_HandleTypeDef hdma_aes_in;
DMA_HandleTypeDef hdma_aes_out;
__ALIGN_BEGIN static uint32_t key[4] __ALIGN_END = {0};
static uint16_t key_size=0;

static uint32_t iv[4] = {0};
static uint16_t iv_size=16;


static void uhal_aes_init(AES_mode_t mode)
{

  /* USER CODE BEGIN AES_Init 0 */

  /* USER CODE END AES_Init 0 */

  /* USER CODE BEGIN AES_Init 1 */

  /* USER CODE END AES_Init 1 */
  hcryp.Instance = AES;
  hcryp.Init.DataType = CRYP_DATATYPE_32B;
  hcryp.Init.KeySize = CRYP_KEYSIZE_128B;
  hcryp.Init.pKey          = (uint32_t *)key;
  hcryp.Init.Algorithm = CRYP_AES_ECB;
  hcryp.Init.DataWidthUnit = CRYP_DATAWIDTHUNIT_WORD;
  hcryp.Init.HeaderWidthUnit = CRYP_HEADERWIDTHUNIT_WORD;
  hcryp.Init.KeyIVConfigSkip = CRYP_KEYIVCONFIG_ALWAYS;
  if (HAL_CRYP_Init(&hcryp) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN AES_Init 2 */
    
  /* USER CODE END AES_Init 2 */
    
} 



static int uhal_crypto_aes_crypt(AES_mode_t mode, AES_Crypt_type_t type,
                             uint32_t *pKey, uint16_t keySize, 
                             uint32_t *pIV, uint16_t ivSize, 
                             char *intputBuffer, uint16_t intputBuffer_size, 
                             unsigned char *outputBuffer, uint16_t outputBuffer_size)
{
    uhal_aes_init(mode);
    if (HAL_CRYP_DeInit(&hcryp) != HAL_OK)
      Error_Handler();
    hcryp.Instance = AES;
    hcryp.Init.DataType = CRYP_DATATYPE_8B;
    hcryp.Init.KeySize = CRYP_KEYSIZE_128B;
    if(mode == AES_MODE_ECB)
    {
        hcryp.Init.Algorithm = CRYP_AES_ECB;
    }
    else if(mode == AES_MODE_CBC)
    {
        hcryp.Init.Algorithm = CRYP_AES_CBC;
        hcryp.Init.pInitVect = pIV;
    }
    else if(mode == AES_MODE_CTR)
    {
        hcryp.Init.Algorithm = CRYP_AES_CTR;
        hcryp.Init.pInitVect = pIV;
    }
    hcryp.Init.pKey          = (uint32_t *)pKey;
    hcryp.Init.DataWidthUnit = CRYP_DATAWIDTHUNIT_BYTE;
    hcryp.Init.HeaderWidthUnit = CRYP_HEADERWIDTHUNIT_WORD;
    hcryp.Init.KeyIVConfigSkip = CRYP_KEYIVCONFIG_ALWAYS;
    if (HAL_CRYP_Init(&hcryp) != HAL_OK)
        Error_Handler();
    
    uint16_t input_len = intputBuffer_size;
    if(intputBuffer_size%16)
        input_len = intputBuffer_size + (16 - intputBuffer_size%16);
    //memset(outputBuffer,'\0',outputBuffer_size);
    uint32_t input_buf[input_len]; 
    memset(input_buf,'\0',input_len);
    memcpy(input_buf,intputBuffer,intputBuffer_size);

/*    udrv_serial_log_printf("input_len:%u\r\n",input_len);
    udrv_serial_log_printf("intputBuffer_size:%u\r\n",intputBuffer_size);
    uint8_t *aa;
    aa = input_buf;
    for(int i =0;i<intputBuffer_size;i++)
        udrv_serial_log_printf("%02x",aa[i]);
        udrv_serial_log_printf("\r\n");
    aa = pIV;
    for(int i =0;i<16;i++)
        udrv_serial_log_printf("%02x",aa[i]);
        udrv_serial_log_printf("\r\n");
    aa = pKey;
    for(int i =0;i<16;i++)
        udrv_serial_log_printf("%02x",aa[i]);
        udrv_serial_log_printf("\r\n");*/

    if(type == TYPE_ENCRYPT)
    {
        if(HAL_CRYP_Encrypt(&hcryp,input_buf,input_len,outputBuffer,0xFF) != HAL_OK)
            return -UDRV_INTERNAL_ERR;
    }
    else if(type == TYPE_DECRYPT)
    {
        if(HAL_CRYP_Decrypt(&hcryp,input_buf,input_len,outputBuffer,0xFF) != HAL_OK)
            return -UDRV_INTERNAL_ERR;
    }
    if (HAL_CRYP_DeInit(&hcryp) != HAL_OK)
        Error_Handler();
    return UDRV_RETURN_OK;

}

int uhal_cyrpto_set_key(uint8_t *pKey, uint16_t keySize)
{
    // ASSERT(keySize == AES128_SIZE || keySize == AES192_SIZE || keySize == AES256_SIZE);
    if(keySize != AES128_SIZE && keySize != AES192_SIZE && keySize != AES256_SIZE)
         return -UDRV_INVALID_KEY_LENGTH;
    uint8_t *ptr = key;
for(int i = 0;i<AES128_SIZE;i=i+4)
{
    ptr[i] = pKey[i+3];
    ptr[i+1] = pKey[i+2];
    ptr[i+2] = pKey[i+1];
    ptr[i+3] = pKey[i];
}
    //memcpy(key, pKey, keySize);
    key_size = keySize;
    return 0;
}

int uhal_cyrpto_set_iv(unsigned char *pIV, uint16_t ivSize)
{
    // ASSERT(ivSize == 16);
    if(ivSize != 16)
        return -UDRV_INVALID_KEY_LENGTH;
    uint8_t *ptr = iv;
for(int i = 0;i<16;i=i+4)
{
    ptr[i] = pIV[i+3];
    ptr[i+1] = pIV[i+2];
    ptr[i+2] = pIV[i+1];
    ptr[i+3] = pIV[i];
}

//    memcpy(iv, pIV, ivSize);
    iv_size = ivSize;
    return 0;
}

int uhal_crypto_aes_ecb_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    // Encryption with AES-ECB
    return uhal_crypto_aes_crypt(AES_MODE_ECB, TYPE_ENCRYPT,
                          (uint32_t *) key, key_size,
                          NULL, 0,
                          input, inputSize, 
                          output, outputSize);
}

int uhal_crypto_aes_ecb_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    // Decryption with AES-ECB
    return uhal_crypto_aes_crypt(AES_MODE_ECB, TYPE_DECRYPT,
                          (uint32_t *) key, key_size,
                          NULL, 0,
                          input, inputSize, 
                          output, outputSize);
}

int uhal_crypto_aes_cbc_encrypt(char *input, uint16_t inputSize, 
                                 unsigned char *output, uint16_t outputSize)
{
    uint32_t iv_enc[4] = {0};

    memcpy(iv_enc, iv, iv_size);

    // Encryption with AES128-CBC
    return uhal_crypto_aes_crypt(AES_MODE_CBC, TYPE_ENCRYPT,
                          (uint32_t *) key, key_size,
                          (uint32_t *) iv_enc, sizeof(iv_enc),
                          input, inputSize, 
                          output, outputSize);
}

int uhal_crypto_aes_cbc_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    uint32_t iv_dec[4] = {0};

    memcpy(iv_dec, iv, iv_size);

    // Encryption with AES128-CBC
    return uhal_crypto_aes_crypt(AES_MODE_CBC, TYPE_DECRYPT,
                          (uint32_t *) key, key_size,
                          (uint32_t *) iv_dec, sizeof(iv_dec),
                          input, inputSize, 
                          output, outputSize);    
}

int uhal_crypto_aes_ctr_encrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    // Encryption with AES-ECB
    uint32_t iv_dec[4] = {0};

    memcpy(iv_dec, iv, iv_size);
    return uhal_crypto_aes_crypt(AES_MODE_CTR, TYPE_ENCRYPT,
                          (uint32_t *) key, key_size,
                          (uint32_t *) iv_dec, sizeof(iv_dec),
                          input, inputSize, 
                          output, outputSize);
}

int uhal_crypto_aes_ctr_decrypt(char *input, uint16_t inputSize, 
                                unsigned char *output, uint16_t outputSize)
{
    // Decryption with AES-ECB
    uint32_t iv_dec[4] = {0};

    memcpy(iv_dec, iv, iv_size);
    return uhal_crypto_aes_crypt(AES_MODE_CTR, TYPE_DECRYPT,
                          (uint32_t *) key, key_size,
                          (uint32_t *) iv_dec, sizeof(iv_dec),
                          input, inputSize, 
                          output, outputSize);
}
#if defined( AES_ENC_PREKEYED ) || defined( AES_DEC_PREKEYED )

return_type aes_set_key ( const uint8_t key[], length_type keylen, aes_context ctx[1] )
{
    return uhal_cyrpto_set_key(key,keylen);
}

#endif


#if defined( AES_ENC_PREKEYED )

return_type aes_encrypt( const uint8_t in[N_BLOCK], uint8_t out[N_BLOCK], const aes_context ctx[1] )
{
    return uhal_crypto_aes_ecb_encrypt(in,N_BLOCK,out,N_BLOCK);
}

return_type aes_cbc_encrypt( const uint8_t *in, uint8_t *out, int32_t n_block, uint8_t iv[N_BLOCK], const aes_context ctx[1] )
{
    uhal_cyrpto_set_iv(iv,N_BLOCK);
    return uhal_crypto_aes_cbc_encrypt(in,n_block*16,out,n_block*16);

}
#endif

#if defined( AES_DEC_PREKEYED )

return_type aes_decrypt( const uint8_t in[N_BLOCK], uint8_t out[N_BLOCK], const aes_context ctx[1] )
{
    return uhal_crypto_aes_ecb_decrypt(in,N_BLOCK,out,N_BLOCK);
}
return_type aes_cbc_decrypt( const uint8_t *in, uint8_t *out, int32_t n_block, uint8_t iv[N_BLOCK], const aes_context ctx[1] )
{
    uhal_cyrpto_set_iv(iv,N_BLOCK);
    return uhal_crypto_aes_cbc_decrypt(in,n_block*16,out,n_block*16);
}
#endif
