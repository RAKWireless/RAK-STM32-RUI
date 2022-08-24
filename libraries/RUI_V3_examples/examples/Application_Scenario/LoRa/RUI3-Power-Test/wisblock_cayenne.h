/**
 * @file wisblock_cayenne.h
 * @author Bernd Giesecke (bernd.giesecke@rakwireless.com)
 * @brief Extend CayenneLPP class with custom channels
 * @version 0.1
 * @date 2022-04-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef WISBLOCK_CAYENNE_H
#define WISBLOCK_CAYENNE_H

// #include <Arduino.h>
#include <ArduinoJson.h>
#include "My_CayenneLPP.h"

#define LPP_GPS4 136 // 3 byte lon/lat 0.0001 °, 3 bytes alt 0.01 meter (Cayenne LPP default)
#define LPP_GPS6 137 // 4 byte lon/lat 0.000001 °, 3 bytes alt 0.01 meter (Customized Cayenne LPP, higher precision)
#define LPP_VOC 138	 // 2 byte VOC index

// Only Data Size
#define LPP_GPS4_SIZE 9
#define LPP_GPS6_SIZE 11
#define LPP_GPSH_SIZE 14
#define LPP_VOC_SIZE 2

class WisCayenne : public CayenneLPP
{
public:
	WisCayenne(uint8_t size) : CayenneLPP(size) {}

	uint8_t addGNSS_4(uint8_t channel, uint32_t latitude, uint32_t longitude, uint32_t altitude);
	uint8_t addGNSS_6(uint8_t channel, uint32_t latitude, uint32_t longitude, uint32_t altitude);
	uint8_t addGNSS_H(uint32_t latitude, uint32_t longitude, uint16_t altitude, uint16_t accuracy, uint16_t battery);
	uint8_t addVoc_index(uint8_t channel, uint32_t voc_index);

private:
};
#endif