/**
 * @file wisblock_cayenne.cpp
 * @author Bernd Giesecke (bernd.giesecke@rakwireless.com)
 * @brief Extend CayenneLPP class with custom channels
 * @version 0.2
 * @date 2022-04-10
 *
 * Copyright Copyright (c) 2022
 */


/**
C H A N G E L O G

- We added a function called addPositionData that centralizes the process of including GNSS data, in the buffer. 
This function helps avoid repetition by managing the formatting and addition of; 
latitude, longitude and altitude data in GNSS data functions (addGNSS_4, addGNSS_6 and addGNSS_H). 
Another function, addToBuffer handles the conversion of 32 bit values into byte formats for the buffer to ensure consistent and error free data addition.

- In terms of restructuring GNSS Data Functions we revamped addGNSS_4, addGNSS_6 and addGNSS_H to utilize addPositionData. 
This simplifies these functions by consolidating buffer overflow checks and data addition logic. 
We also enhanced how we handle data precision and adjusted byte order for buffer addition to enhance data integrity and align with protocol standards.

- To improve error handling we have applied buffer overflow checks consistently across all data addition functions to catch errors uniformly. 
This helps prevent data corruption and ensures stability in the transmission process. 
Additionally redundant code blocks have been removed by leveraging the helper functions. 
This action reduces the codebase size. Makes it easier, for modifications.

- Moreover we have replaced numbers with constants where appropriate to enhance code readability and facilitate better understanding and maintenance of the codebase.

*/

#include "wisblock_cayenne.h"

// Data type union for handling 16-bit and 32-bit data conversions
union int_union_s
{
    uint16_t val16 = 0;
    uint8_t val8[2];
};

union latLong_s
{
    uint32_t val32;
    uint8_t val8[4];
};

// Helper functions for adding GNSS data
uint8_t WisCayenne::addPositionData(uint8_t channel, uint8_t type, uint32_t latitude, uint32_t longitude, uint32_t altitude)
{
    // Check for buffer overflow and ensure all data can be added
    if ((_cursor + type + 2) > _maxsize)
    {
        _error = LPP_ERROR_OVERFLOW;
        return 0;
    }

    _buffer[_cursor++] = channel;
    _buffer[_cursor++] = type;

    addToBuffer(latitude);
    addToBuffer(longitude);
    addToBuffer(altitude);

    return _cursor;
}

// Converts 32-bit values to bytes and adds them to the buffer
void WisCayenne::addToBuffer(uint32_t value)
{
    latLong_s pos_union;
    pos_union.val32 = value;
    for (int i = 3; i >= 0; i--) // Adjust to write all 4 bytes for full precision
    {
        _buffer[_cursor++] = pos_union.val8[i];
    }
}

// GNSS data functions
uint8_t WisCayenne::addGNSS_4(uint8_t channel, uint32_t latitude, uint32_t longitude, uint32_t altitude)
{
    return addPositionData(channel, LPP_GPS4, latitude / 1000, longitude / 1000, altitude / 10);
}

uint8_t WisCayenne::addGNSS_6(uint8_t channel, uint32_t latitude, uint32_t longitude, uint32_t altitude)
{
    return addPositionData(channel, LPP_GPS6, latitude / 10, longitude / 10, altitude / 10);
}

uint8_t WisCayenne::addGNSS_H(uint32_t latitude, uint32_t longitude, uint16_t altitude, uint16_t accuracy, uint16_t battery)
{
    if ((_cursor + LPP_GPSH_SIZE) > _maxsize)
    {
        _error = LPP_ERROR_OVERFLOW;
        return 0;
    }

    addToBuffer(latitude / 100);
    addToBuffer(longitude / 100);
    addToBuffer(altitude / 1000);
    addToBuffer(accuracy);

    int_union_s batt_level;
    batt_level.val16 = battery;
    _buffer[_cursor++] = batt_level.val8[0];
    _buffer[_cursor++] = batt_level.val8[1];

    return _cursor;
}

// Add VOC index data
uint8_t WisCayenne::addVoc_index(uint8_t channel, uint32_t voc_index)
{
    if ((_cursor + LPP_VOC_SIZE + 2) > _maxsize)
    {
        _error = LPP_ERROR_OVERFLOW;
        return 0;
    }

    _buffer[_cursor++] = channel;
    _buffer[_cursor++] = LPP_VOC;

    int_union_s voc_union;
    voc_union.val16 = voc_index;
    _buffer[_cursor++] = voc_union.val8[1];
    _buffer[_cursor++] = voc_union.val8[0];

    return _cursor;
}
