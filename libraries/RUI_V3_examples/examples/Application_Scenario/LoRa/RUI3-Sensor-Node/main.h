/**
 * @file main.h
 * @author Bernd Giesecke (bernd@giesecke.tk)
 * @brief Globals and Includes
 * @version 0.1
 * @date 2022-04-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Arduino.h>
#ifndef _MAIN_H_
#define _MAIN_H_

#if defined _VARIANT_RAK3172_ || defined _VARIANT_RAK3172_SIP_
/****************************************************************/
/* GNSS Location Tracker with RAK3172                           */
/* Due to limited memory and flash size, if code is used for    */
/* location tracking, some other modules need to be disabled    */
/*                                                              */
/* THIS IS ONLY REQUIRED FOR RAK3172 !                          */
/****************************************************************/
// Enable/disable GNSS module for RAK3172 -> defined => tracker function
// #define IS_GNSS_TRACKER_RAK3172
#else
#define IS_GNSS_TRACKER_RAK3172
#endif
// Debug
// Debug output set to 0 to disable app debug output
#ifndef MY_DEBUG
#define MY_DEBUG 1
#endif

#if MY_DEBUG > 0
#define MYLOG(tag, ...)                  \
	do                                   \
	{                                    \
		if (tag)                         \
			Serial.printf("[%s] ", tag); \
		Serial.printf(__VA_ARGS__);      \
		Serial.printf("\n");             \
	} while (0);                         \
	delay(100)
#else
#define MYLOG(...)
#endif

#ifndef RAK_REGION_AS923_2
#define RAK_REGION_AS923_2 9
#endif
#ifndef RAK_REGION_AS923_3
#define RAK_REGION_AS923_3 10
#endif
#ifndef RAK_REGION_AS923_4
#define RAK_REGION_AS923_4 11
#endif

// Globals
extern char g_dev_name[];
extern bool g_has_rak15001;

/** Settings valid marker */
#define LORAWAN_DATA_MARKER 0x55

/** Structure for the device setup */
struct s_lorawan_settings
{
	// Just a marker for the Flash
	uint8_t valid_mark_1 = 0xAA;
	// Just a marker for the Flash
	uint8_t valid_mark_2 = LORAWAN_DATA_MARKER;
#if defined _VARIANT_RAK3172_ || defined _VARIANT_RAK3172_SIP_
#if RUI_DEV == 1
	// OTAA Device EUI MSB
	uint8_t node_device_eui[8] = {0xac, 0x1f, 0x09, 0xff, 0xf8, 0x68, 0x31, 0x72};
#else
	// OTAA Device EUI MSB
	uint8_t node_device_eui[8] = {0xac, 0x1f, 0x09, 0xff, 0xfe, 0x05, 0x37, 0xa1};
#endif
	// OTAA Application EUI MSB
	uint8_t node_app_eui[8] = {0xac, 0x1f, 0x09, 0xff, 0xf8, 0x68, 0x31, 0x72};
	// OTAA Application Key MSB
	uint8_t node_app_key[16] = {0xef, 0xad, 0xff, 0x29, 0xc7, 0x7b, 0x48, 0x29, 0xac, 0xf7, 0x1e, 0x1a, 0x6e, 0x76, 0xf7, 0x13};
#endif
#if defined _VARIANT_RAK4630_ || defined _VARIANT_RAK11720_
	// OTAA Device EUI MSB
	uint8_t node_device_eui[8] = {0xAC, 0x1F, 0x09, 0xFF, 0xFE, 0x05, 0x71, 0x10};
	// OTAA Application EUI MSB
	uint8_t node_app_eui[8] = {0xAC, 0x1F, 0x09, 0xFF, 0xFE, 0x05, 0x71, 0x10};
	// OTAA Application Key MSB
	uint8_t node_app_key[16] = {0x2B, 0x84, 0xE0, 0xB0, 0x9B, 0x68, 0xE5, 0xCB, 0x42, 0x17, 0x6F, 0xE7, 0x53, 0xDC, 0xEE, 0x79};
#endif
	// ABP Device Address MSB
	uint32_t node_dev_addr = 0x26021FB4;
	// ABP Network Session Key MSB
	uint8_t node_nws_key[16] = {0x32, 0x3D, 0x15, 0x5A, 0x00, 0x0D, 0xF3, 0x35, 0x30, 0x7A, 0x16, 0xDA, 0x0C, 0x9D, 0xF5, 0x3F};
	// ABP Application Session key MSB
	uint8_t node_apps_key[16] = {0x3F, 0x6A, 0x66, 0x45, 0x9D, 0x5E, 0xDC, 0xA6, 0x3C, 0xBC, 0x46, 0x19, 0xCD, 0x61, 0xA1, 0x1E};
	// Flag for OTAA or ABP
	bool otaa_enabled = true;
	// Flag for ADR on or off
	bool adr_enabled = false;
	// Flag for public or private network
	bool public_network = true;
	// Flag to enable duty cycle
	bool duty_cycle_enabled = false;
	// Default is off
	uint32_t send_repeat_time = 0;
	// Number of join retries
	uint8_t join_trials = 5;
	// TX power 0 .. 10
	uint8_t tx_power = 0;
	// Data rate 0 .. 15 (validity depnends on Region)
	uint8_t data_rate = 3;
	// LoRaWAN class 0: A, 1: B, 2: C
	uint8_t lora_class = 0;
	// Subband channel selection 1 .. 9
	uint8_t subband_channels = 1;
	// Flag if node joins automatically after reboot
	bool auto_join = false;
	// Data port to send data
	uint8_t app_port = 2;
	// Flag to enable confirmed messages
	bool confirmed_msg_enabled = false;
#if defined _VARIANT_RAK3172_ || defined _VARIANT_RAK3172_SIP_
	// Fixed LoRaWAN lorawan_region
	uint8_t lora_region = RAK_REGION_AS923_3;
#endif
#if defined _VARIANT_RAK4630_ || defined _VARIANT_RAK11720_
	// Fixed LoRaWAN lorawan_region
	uint8_t lora_region = RAK_REGION_EU868;
#endif
	// Flag for LoRaWAN or LoRa P2P
	bool lorawan_enable = true;
	// Frequency in Hz
	uint32_t p2p_frequency = 916000000;
	// Tx power 0 .. 22
	uint8_t p2p_tx_power = 22;
	// Bandwidth 0: 125 kHz, 1: 250 kHz, 2: 500 kHz, 3: Reserved
	uint8_t p2p_bandwidth = 0;
	// Spreading Factor SF7..SF12
	uint8_t p2p_sf = 7;
	// Coding Rate 1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8
	uint8_t p2p_cr = 1;
	// Preamble length
	uint8_t p2p_preamble_len = 8;
	// Symbol timeout
	uint16_t p2p_symbol_timeout = 0;
	// Command from BLE to reset device
	bool resetRequest = true;
};

extern s_lorawan_settings g_lorawan_settings;
void log_settings(void);

/** Module stuff */
#include "module_handler.h"
#endif // _MAIN_H_
