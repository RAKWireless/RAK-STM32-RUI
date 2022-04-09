#include "variant.h"

#define PORT_GPIO_BASE_ADDR 0x48000000UL
#define PORT_GPIO_BASE_OFFSET 0x00000400UL
#define PORT_GPIO_NUMBER 16

const uint32_t g_ADigitalPinMap[] =
{
  // GPIOA
  0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 ,
  8 , 9 , 10, 11, 12, 13, 14, 15,

  // GPIOB
  16, 17, 18, 19, 20, 21, 22, 23,
  24, 25, 26, 27, 28, 29, 30, 31,

  // GPIOC
  32, 33, 34, 35, 36, 37, 38, 39,
  40, 41, 42, 43, 44, 45, 46, 47
};


void initVariant()
{
}

uint32_t PinToPort(uint32_t pin) {
    return PORT_GPIO_BASE_ADDR + ((pin / PORT_GPIO_NUMBER) * PORT_GPIO_BASE_OFFSET);
}
