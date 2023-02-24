#include "uhal_spimst.h"
#include "uhal_gpio.h"
#include "stm32wlxx_hal.h"

#ifdef HAL_SPI_MODULE_ENABLED
SPI_HandleTypeDef hspi1 = 
{
    .Instance = SPI1,
    .Init.Mode = SPI_MODE_MASTER,
    .Init.Direction = SPI_DIRECTION_2LINES,
    .Init.DataSize = SPI_DATASIZE_8BIT,
    .Init.CLKPolarity = SPI_POLARITY_LOW,
    .Init.CLKPhase = SPI_PHASE_1EDGE,
    .Init.NSS = SPI_NSS_SOFT,
    .Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32,
    .Init.FirstBit = SPI_FIRSTBIT_MSB,
    .Init.TIMode = SPI_TIMODE_DISABLE,
    .Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE,
    .Init.CRCPolynomial = 7,
    .Init.CRCLength = SPI_CRC_LENGTH_DATASIZE,
    .Init.NSSPMode = SPI_NSS_PULSE_DISABLE
};
DMA_HandleTypeDef hdma_spi1_tx;
DMA_HandleTypeDef hdma_spi1_rx;
#endif
enum
{
  TRANSFER_WAIT,
  TRANSFER_COMPLETE,
  TRANSFER_ERROR
};

__IO uint32_t wTransferState = TRANSFER_WAIT;
typedef struct uhal_spimst_status {
    bool active;
} uhal_spimst_status_t;

static uhal_spimst_status_t spimst_status[UDRV_SPIMST_MAX];

void uhal_spimst_setup_mode(udrv_spimst_port port, ENUM_SPI_MST_CPHA_T CPHA, ENUM_SPI_MST_CPOL_T CPOL) {
    if (CPHA == SPI_MST_CPOL_0)
        hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
    else if (CPHA == SPI_MST_CPOL_1)
        hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
    if (CPOL == SPI_MST_CPOL_0)
        hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
    else if (CPOL == SPI_MST_CPOL_1) 
        hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
}

void uhal_spimst_setup_freq(udrv_spimst_port port, uint32_t clk_Hz) {
    uint32_t prescaler = HAL_RCC_GetHCLKFreq()/clk_Hz;
    if (prescaler >= 256)
        hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
    else if (prescaler >= 128)
        hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
    else if (prescaler >= 64)
        hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
    else if (prescaler >= 32)
        hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
    else if (prescaler >= 16)
        hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    else if (prescaler >= 8)
        hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
    else if (prescaler >= 4)
        hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
    else
        hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
}

void uhal_spimst_setup_byte_order(udrv_spimst_port port, bool msb_first) {
    if (msb_first)
        hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    else
        hspi1.Init.FirstBit = SPI_FIRSTBIT_LSB;
}

static void spimst_init(udrv_spimst_port port) {
    /* GPIO Ports Clock Enable */
    //__HAL_RCC_GPIOA_CLK_ENABLE();
    HAL_SPI_Init(&hspi1);
    /* DMA1_Channel2_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA1_Channel2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Channel2_IRQn);
    /* DMA1_Channel3_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA1_Channel3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Channel3_IRQn);

}

void uhal_spimst_init(udrv_spimst_port port) {
    if (port >= UDRV_SPIMST_MAX) 
        return;
    spimst_init(port);
    spimst_status[port].active = true;
}

static void spimst_deinit(udrv_spimst_port port) {
    HAL_SPI_DeInit(&hspi1);
}

void uhal_spimst_deinit(udrv_spimst_port port) {
    if (port >= UDRV_SPIMST_MAX) 
        return;
    spimst_deinit(port);
    spimst_status[port].active = false;
}

int8_t uhal_spimst_trx(udrv_spimst_port port, uint8_t *write_data, uint32_t write_length, uint8_t *read_data, uint32_t read_length, uint32_t csn) {
    int8_t result;
    bool set_logic = false;
    if (uhal_gpio_get_dir(csn) != GPIO_DIR_OUT)
        uhal_gpio_set_dir(csn, GPIO_DIR_OUT);
    if(uhal_gpio_get_logic(csn) != GPIO_LOGIC_LOW)
    {
        uhal_gpio_set_logic(csn, GPIO_LOGIC_LOW);
        set_logic = true;
    }
    wTransferState = TRANSFER_WAIT;
    if (write_length > read_length)
        result = HAL_SPI_TransmitReceive_DMA(&hspi1, write_data, read_data, write_length);
    else
        result = HAL_SPI_TransmitReceive_DMA(&hspi1, write_data, read_data, read_length);
    while (wTransferState == TRANSFER_WAIT);
    if (set_logic)
        uhal_gpio_set_logic(csn, GPIO_LOGIC_HIGH);
    return result;
}

void uhal_spimst_suspend(void) {
}

void uhal_spimst_resume(void) {
    for (int i = UDRV_SPIMST_0 ; i < UDRV_SPIMST_MAX ; i++) {
        if (spimst_status[i].active == true) {
            spimst_init(i);
        }
    }
}

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
  wTransferState = TRANSFER_COMPLETE;
}

void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
  wTransferState = TRANSFER_ERROR;
}


