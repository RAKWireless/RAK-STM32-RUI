/**
 * @file wisblock_cayenne.cpp
 * @author Bernd Giesecke (bernd.giesecke@rakwireless.com)
 * @brief Extend CayenneLPP class with custom channels
 * @version 0.1
 * @date 2022-04-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "wisblock_cayenne.h"

/** uint16_t level union */
union int_union_s
{
	uint16_t val16 = 0;
	uint8_t val8[2];
};
/** Latitude/Longitude value union */
union latLong_s
{
	uint32_t val32;
	uint8_t val8[4];
};

/**
 * @brief Add GNSS data in Cayenne LPP standard format
 *
 * @param channel LPP channel
 * @param latitude Latitude as read from the GNSS receiver
 * @param longitude Longitude as read from the GNSS receiver
 * @param altitude Altitude as read from the GNSS receiver
 * @return uint8_t bytes added to the data packet
 */
uint8_t WisCayenne::addGNSS_4(uint8_t channel, uint32_t latitude, uint32_t longitude, uint32_t altitude)
{
	// check buffer overflow
	if ((_cursor + LPP_GPS4_SIZE + 2) > _maxsize)
	{
		_error = LPP_ERROR_OVERFLOW;
		return 0;
	}
	_buffer[_cursor++] = channel;
	_buffer[_cursor++] = LPP_GPS4;

	latLong_s pos_union;

	// Save default Cayenne LPP precision
	pos_union.val32 = latitude / 1000; // Cayenne LPP 0.0001 ° Signed MSB
	_buffer[_cursor++] = pos_union.val8[2];
	_buffer[_cursor++] = pos_union.val8[1];
	_buffer[_cursor++] = pos_union.val8[0];

	pos_union.val32 = longitude / 1000; // Cayenne LPP 0.0001 ° Signed MSB
	_buffer[_cursor++] = pos_union.val8[2];
	_buffer[_cursor++] = pos_union.val8[1];
	_buffer[_cursor++] = pos_union.val8[0];

	pos_union.val32 = altitude / 10; // Cayenne LPP 0.01 meter Signed MSB
	_buffer[_cursor++] = pos_union.val8[2];
	_buffer[_cursor++] = pos_union.val8[1];
	_buffer[_cursor++] = pos_union.val8[0];

	return _cursor;
}

/**
 * @brief Add GNSS data in custom Cayenne LPP format
 *        Requires changed decoder in LNS and visualization
 *        Does not work with Cayenne LPP MyDevices
 *
 * @param channel LPP channel
 * @param latitude Latitude as read from the GNSS receiver
 * @param longitude Longitude as read from the GNSS receiver
 * @param altitude Altitude as read from the GNSS receiver
 * @return uint8_t bytes added to the data packet
 */
uint8_t WisCayenne::addGNSS_6(uint8_t channel, uint32_t latitude, uint32_t longitude, uint32_t altitude)
{
	// check buffer overflow
	if ((_cursor + LPP_GPS6_SIZE + 2) > _maxsize)
	{
		_error = LPP_ERROR_OVERFLOW;
		return 0;
	}
	_buffer[_cursor++] = channel;
	_buffer[_cursor++] = LPP_GPS6;

	latLong_s pos_union;

	pos_union.val32 = latitude / 10; // Custom 0.000001 ° Signed MSB
	_buffer[_cursor++] = pos_union.val8[3];
	_buffer[_cursor++] = pos_union.val8[2];
	_buffer[_cursor++] = pos_union.val8[1];
	_buffer[_cursor++] = pos_union.val8[0];

	pos_union.val32 = longitude / 10; // Custom 0.000001 ° Signed MSB
	_buffer[_cursor++] = pos_union.val8[3];
	_buffer[_cursor++] = pos_union.val8[2];
	_buffer[_cursor++] = pos_union.val8[1];
	_buffer[_cursor++] = pos_union.val8[0];

	pos_union.val32 = altitude / 10; // Cayenne LPP 0.01 meter Signed MSB
	_buffer[_cursor++] = pos_union.val8[2];
	_buffer[_cursor++] = pos_union.val8[1];
	_buffer[_cursor++] = pos_union.val8[0];

	return _cursor;
}

/**
 * @brief Add GNSS data in Helium Mapper format
 *
 * @param channel LPP channel
 * @param latitude Latitude as read from the GNSS receiver
 * @param longitude Longitude as read from the GNSS receiver
 * @param altitude Altitude as read from the GNSS receiver
 * @param accuracy Accuracy of reading from the GNSS receiver
 * @param battery Device battery voltage in V
 * @return uint8_t bytes added to the data packet
 */
uint8_t WisCayenne::addGNSS_H(uint32_t latitude, uint32_t longitude, uint16_t altitude, uint16_t accuracy, uint16_t battery)
{
	// check buffer overflow
	if ((_cursor + LPP_GPSH_SIZE) > _maxsize)
	{
		_error = LPP_ERROR_OVERFLOW;
		return 0;
	}

	latLong_s pos_union;

	pos_union.val32 = latitude / 100; // Custom 0.00001 ° Signed MSB
	_buffer[_cursor++] = pos_union.val8[0];
	_buffer[_cursor++] = pos_union.val8[1];
	_buffer[_cursor++] = pos_union.val8[2];
	_buffer[_cursor++] = pos_union.val8[3];

	pos_union.val32 = longitude / 100; // Custom 0.00001 ° Signed MSB
	_buffer[_cursor++] = pos_union.val8[0];
	_buffer[_cursor++] = pos_union.val8[1];
	_buffer[_cursor++] = pos_union.val8[2];
	_buffer[_cursor++] = pos_union.val8[3];

	pos_union.val32 = altitude / 1000;
	_buffer[_cursor++] = pos_union.val8[0];
	_buffer[_cursor++] = pos_union.val8[1];

	pos_union.val32 = accuracy;
	_buffer[_cursor++] = pos_union.val8[0];
	_buffer[_cursor++] = pos_union.val8[1];

	int_union_s batt_level;

	batt_level.val16 = battery;
	_buffer[_cursor++] = batt_level.val8[0];
	_buffer[_cursor++] = batt_level.val8[1];

	return _cursor;
}

/**
 * @brief Add the VOC index
 *
 * @param channel VOC channel
 * @param voc_index VOC index
 * @return uint8_t bytes added to the data packet
 */
uint8_t WisCayenne::addVoc_index(uint8_t channel, uint32_t voc_index)
{
	// check buffer overflow
	if ((_cursor + LPP_VOC_SIZE + 2) > _maxsize)
	{
		_error = LPP_ERROR_OVERFLOW;
		return 0;
	}
	_buffer[_cursor++] = channel;
	_buffer[_cursor++] = LPP_VOC;

	int_union_s voc_union;

	voc_union.val16 = voc_index; // VOC index
	_buffer[_cursor++] = voc_union.val8[1];
	_buffer[_cursor++] = voc_union.val8[0];

	return _cursor;
}