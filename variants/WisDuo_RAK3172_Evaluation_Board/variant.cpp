#include "variant.h"

const uint32_t g_ADigitalPinMap[] =
{
  // P0
  0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 ,
  8 , 9 , 10, 11, 12, 13, 14, 15,
  16, 17, 18, 19, 20, 21, 22, 23,
  24, 25, 26, 27, 28, 29, 30, 31,
  // P1
  32, 33, 34, 35, 36, 37, 38, 39,
  40, 41, 42, 43, 44, 45, 46, 47
};


// Digital PinName array
const PinName digitalPin[] = {
  PA_0,   // D0
  PA_1,   // D1
  PA_2,   // D2
  PA_3,   // D3
  PA_4,   // D4
  PA_5,   // D5
  PA_6,   // D6
  PA_7,   // D7
  PA_8,   // D8
  PA_9,   // D9
  PA_10,  // D10/A0
  PA_11,  // D11/A1
  PA_12,  // D12/A2
  PA_13,  // D13/A3
  PA_14,  // D14/A4
  PA_15,  // D15/A5
  PB_0,   // D16
  PB_2,   // D17/A6
  PB_3,   // D18/A7
  PB_4,   // D19/A8
  PB_5,   // D20
  PB_6,   // D21
  PB_7,   // D22
  PB_8,   // D23
  PB_12,  // D24
  PC_13,  // D25
  PC_14,  // D26
  PC_15,  // D27
  PH_3    // D28
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  10, // A0,  PA10
  11, // A1,  PA11
  12, // A2,  PA12
  13, // A3,  PA13
  14, // A4,  PA14
  15, // A5,  PA15
  17, // A6,  PB2
  18, // A7,  PB3
  19  // A8,  PB4
};

