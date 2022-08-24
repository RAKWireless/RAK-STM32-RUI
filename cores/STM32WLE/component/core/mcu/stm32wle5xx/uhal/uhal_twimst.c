#include "uhal_twimst.h"

/**@brief   Sleep until an event is received. */
static void power_manage(void)
{
#ifndef RUI_BOOTLOADER
    __SEV();
    __WFE();
    __WFE();
#endif
}

#define TWI_TIMEOUT			10000

I2C_HandleTypeDef hi2c2;

typedef struct uhal_twimst_status {
    bool active;
} uhal_twimst_status_t;

static uhal_twimst_status_t twimst_status[UDRV_TWIMST_MAX];

static void twimst_init(udrv_twimst_port port) {
   // __HAL_RCC_GPIOB_CLK_ENABLE();

    hi2c2.Instance = I2C2;
    if (hi2c2.Init.Timing == NULL) {
        hi2c2.Init.Timing = 0x0070085C;
    }
    hi2c2.Init.OwnAddress1 = 0;
    hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c2.Init.OwnAddress2 = 0; 
    hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
    hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    hi2c2.Mode = HAL_I2C_MODE_MASTER;
    if (HAL_I2C_Init(&hi2c2) != HAL_OK)
    { 
        Error_Handler();
    } 
    /** Configure Analogue filter
    */
    if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
    {
      Error_Handler();
    }
    /** Configure Digital filter
    */
    if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
    {
      Error_Handler();
    }
    /** I2C Fast mode Plus enable
    */
    HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_I2C2);
}

void uhal_twimst_init(udrv_twimst_port port) {
    twimst_init(port);

    twimst_status[port].active = true;
}

static void twimst_deinit(udrv_twimst_port port) {
    if (HAL_I2C_DeInit(&hi2c2) != HAL_OK)
    { 
        Error_Handler();
    } 
}

void uhal_twimst_deinit(udrv_twimst_port port) {
    twimst_deinit(port);

    twimst_status[port].active = false;
}

void uhal_twimst_setup_freq(udrv_twimst_port port, uint32_t clk_Hz) {
    if (clk_Hz <= 100000) {
        hi2c2.Init.Timing = 0x10300ADB;
    } else if (clk_Hz <= 250000) {
        hi2c2.Init.Timing = 0x00700D9F;
    } else {
        hi2c2.Init.Timing = 0x0070085C;
    }

    if (hi2c2.Instance != NULL) {
        HAL_I2C_DeInit(&hi2c2);

        if (HAL_I2C_Init(&hi2c2) != HAL_OK)
        { 
            Error_Handler();
        } 
        /** Configure Analogue filter
        */
        if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
        {
          Error_Handler();
        }
        /** Configure Digital filter
        */
        if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
        {
          Error_Handler();
        }
        /** I2C Fast mode Plus enable
        */
        HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_I2C2);
    }
}	

int32_t uhal_twimst_write(udrv_twimst_port port, uint8_t twi_addr, uint8_t *data, uint16_t len, bool send_stop)
{
    uint32_t err_code = 0;
    uint32_t XferOptions;

    if (send_stop) {
        XferOptions = I2C_LAST_FRAME;
    } else {
        XferOptions = I2C_FIRST_FRAME;
    }
    if (HAL_I2C_Master_Seq_Transmit_IT(&hi2c2, twi_addr << 1, data, len, XferOptions) != HAL_OK) {
        return -UDRV_NACK;
    }

    while (HAL_I2C_GetState(&hi2c2) != HAL_I2C_STATE_READY);
    {
        //power_manage();
    }

    if (HAL_I2C_GetError(&hi2c2) == HAL_I2C_ERROR_AF) {
        return -UDRV_NACK;
    }

    return UDRV_RETURN_OK;
}

int32_t uhal_twimst_read(udrv_twimst_port port, uint8_t twi_addr, uint8_t * data, uint16_t len)
{
    uint32_t err_code = 0;

    if (HAL_I2C_Master_Seq_Receive_IT(&hi2c2, twi_addr << 1, data, len, I2C_LAST_FRAME) != HAL_OK) { 
       return -UDRV_NACK;
    }

    while (HAL_I2C_GetState(&hi2c2) != HAL_I2C_STATE_READY)
    {
        //power_manage();
    }

    if (HAL_I2C_GetError(&hi2c2) == HAL_I2C_ERROR_AF) {
        return -UDRV_NACK;
    }

    return UDRV_RETURN_OK;
}

void uhal_twimst_suspend(void)
{
}

void uhal_twimst_resume(void)
{
    for (int i = UDRV_TWIMST_0 ; i < UDRV_TWIMST_MAX ; i++) {
        if (twimst_status[i].active == true) {
            twimst_init(i);
    }
    }
}

