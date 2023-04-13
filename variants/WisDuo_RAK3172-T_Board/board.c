#include "board.h"
#include "stm32wlxx_hal.h"

void BoardGetUniqueId(uint8_t *id)
{
    //service_lora_get_dev_eui(id, 8);
}

void BoardCriticalSectionBegin(uint32_t *mask)
{
    uhal_sys_board_critical_section_begin(mask);
}

void BoardCriticalSectionEnd(uint32_t *mask)
{
    uhal_sys_board_critical_section_end(mask);
}

void BoardInitMcu(void)
{
}

/*Example uint8_t BoardGetHardwareFreq(void) 

uint8_t hardwareFreq = BoardGetHardwareFreq();
uint8_t* hardwareFreq_log[2] = {"RAK3172L","RAK3172H"};
udrv_serial_log_printf("%s\r\n",hardwareFreq_log[hardwareFreq]);

*/

uint8_t BoardGetHardwareFreq(void)
{
    uint8_t hardwareFreq = 0;
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /*Configure GPIO pin : PB12 */
    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    hardwareFreq  = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);

    HAL_GPIO_DeInit(GPIOB,GPIO_PIN_12);
    return hardwareFreq;
}

