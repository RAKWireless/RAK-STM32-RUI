/**
 * @file custom_at.cpp
 * @author Bernd Giesecke (bernd@giesecke.tk)
 * @brief
 * @version 0.1
 * @date 2022-05-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "main.h"

int freq_send_handler(SERIAL_PORT port, char *cmd, stParam *param);
int status_handler(SERIAL_PORT port, char *cmd, stParam *param);

#ifdef _VARIANT_RAK4630_
#define AT_PRINTF(...)                                           \
	do                                                           \
	{                                                            \
		Serial.printf(__VA_ARGS__);                              \
		Serial.printf("\r\n");                                     \
		char dbg_str[255];                                       \
		uint16_t dbg_size = snprintf(dbg_str, 254, __VA_ARGS__); \
		api.ble.uart.write((uint8_t *)dbg_str, dbg_size);        \
		dbg_size = snprintf(dbg_str, 254, "\r\n");               \
		api.ble.uart.write((uint8_t *)dbg_str, dbg_size);        \
	} while (0)

#elif defined _VARIANT_RAK3172_ || defined _VARIANT_RAK3172_SIP_
#define AT_PRINTF(...)              \
	do                              \
	{                               \
		Serial.printf(__VA_ARGS__); \
		Serial.printf("\r\n");        \
	} while (0)
#endif

/**
 * @brief Add send-frequency AT command
 *
 * @return true if success
 * @return false if failed
 */
bool init_frequency_at(void)
{
	return api.system.atMode.add((char *)"SENDFREQ",
								 (char *)"Set/Get the frequent automatic sending time values in seconds 0 = off, max 2,147,483 seconds",
								 (char *)"SENDFREQ", freq_send_handler);
}

/**
 * @brief Handler for send frequency AT commands
 *
 * @param port Serial port used
 * @param cmd char array with the received AT command
 * @param param char array with the received AT command parameters
 * @return int result of command parsing
 * 			AT_OK AT command & parameters valid
 * 			AT_PARAM_ERROR command or parameters invalid
 */
int freq_send_handler(SERIAL_PORT port, char *cmd, stParam *param)
{
	if (param->argc == 1 && !strcmp(param->argv[0], "?"))
	{
		// Serial.print(cmd);
		// Serial.printf("=%lds\r\n", g_send_repeat_time / 1000);
		AT_PRINTF(cmd);
		AT_PRINTF("=%lds\r\n", g_send_repeat_time / 1000);
	}
	else if (param->argc == 1)
	{
		MYLOG("AT_CMD", "param->argv[0] >> %s", param->argv[0]);
		for (int i = 0; i < strlen(param->argv[0]); i++)
		{
			if (!isdigit(*(param->argv[0] + i)))
			{
				MYLOG("AT_CMD", "%d is no digit", i);
				return AT_PARAM_ERROR;
			}
		}

		uint32_t new_send_freq = strtoul(param->argv[0], NULL, 10);

		MYLOG("AT_CMD", "Requested frequency %ld", new_send_freq);

		g_send_repeat_time = new_send_freq * 1000;

		MYLOG("AT_CMD", "New frequency %ld", g_send_repeat_time);
		// Stop the timer
		udrv_timer_stop(TIMER_0);
		if (g_send_repeat_time != 0)
		{
			// Restart the timer
			udrv_timer_start(TIMER_0, g_send_repeat_time, NULL);
		}
		// Save custom settings
		save_at_setting(SEND_FREQ_OFFSET);
	}
	else
	{
		return AT_PARAM_ERROR;
	}

	return AT_OK;
}

/**
 * @brief Add custom Status AT commands
 *
 * @return true AT commands were added
 * @return false AT commands couldn't be added
 */
bool init_status_at(void)
{
	return api.system.atMode.add((char *)"STATUS",
								 (char *)"Get device information",
								 (char *)"STATUS", status_handler);
}

/** Regions as text array */
char *regions_list[] = {"EU433", "CN470", "RU864", "IN865", "EU868", "US915", "AU915", "KR920", "AS923", "AS923-2", "AS923-3", "AS923-4"};
/** Network modes as text array*/
char *nwm_list[] = {"P2P", "LoRaWAN", "FSK"};

/**
 * @brief Print device status over Serial
 *
 * @param port Serial port used
 * @param cmd char array with the received AT command
 * @param param char array with the received AT command parameters
 * @return int result of command parsing
 * 			AT_OK AT command & parameters valid
 * 			AT_PARAM_ERROR command or parameters invalid
 */
int status_handler(SERIAL_PORT port, char *cmd, stParam *param)
{
	String value_str = "";
	int nw_mode = 0;
	int region_set = 0;
	uint8_t key_eui[16] = {0}; // efadff29c77b4829acf71e1a6e76f713

	if (param->argc == 1 && !strcmp(param->argv[0], "?"))
	{
		// Serial.println("Device Status:");
		// value_str = api.system.modelId.get();
		// value_str.toUpperCase();
		// Serial.printf("Module: %s\r\n", value_str.c_str());
		// Serial.printf("Version: %s\r\n", api.system.firmwareVersion.get().c_str());
		// Serial.printf("Send time: %d s\r\n", g_send_repeat_time / 1000);
		// nw_mode = api.lorawan.nwm.get();
		// Serial.printf("Network mode %s\r\n", nwm_list[nw_mode]);
		// if (nw_mode == 1)
		// {
		// 	Serial.printf("Network %s\r\n", api.lorawan.njs.get() ? "joined" : "not joined");
		// 	region_set = api.lorawan.band.get();
		// 	Serial.printf("Region: %d\r\n", region_set);
		// 	Serial.printf("Region: %s\r\n", regions_list[region_set]);
		// 	if (api.lorawan.njm.get())
		// 	{
		// 		Serial.println("OTAA mode");
		// 		api.lorawan.deui.get(key_eui, 8);
		// 		Serial.printf("DevEUI = %02X%02X%02X%02X%02X%02X%02X%02X\r\n",
		// 					  key_eui[0], key_eui[1], key_eui[2], key_eui[3],
		// 					  key_eui[4], key_eui[5], key_eui[6], key_eui[7]);
		// 		api.lorawan.appeui.get(key_eui, 8);
		// 		Serial.printf("AppEUI = %02X%02X%02X%02X%02X%02X%02X%02X\r\n",
		// 					  key_eui[0], key_eui[1], key_eui[2], key_eui[3],
		// 					  key_eui[4], key_eui[5], key_eui[6], key_eui[7]);
		// 		api.lorawan.appkey.get(key_eui, 16);
		// 		Serial.printf("AppKey = %02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X\r\n",
		// 					  key_eui[0], key_eui[1], key_eui[2], key_eui[3],
		// 					  key_eui[4], key_eui[5], key_eui[6], key_eui[7],
		// 					  key_eui[8], key_eui[9], key_eui[10], key_eui[11],
		// 					  key_eui[12], key_eui[13], key_eui[14], key_eui[15]);
		// 	}
		// 	else
		// 	{
		// 		Serial.println("ABP mode");
		// 		api.lorawan.appskey.get(key_eui, 16);
		// 		Serial.printf("AppsKey = %02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X\r\n",
		// 					  key_eui[0], key_eui[1], key_eui[2], key_eui[3],
		// 					  key_eui[4], key_eui[5], key_eui[6], key_eui[7],
		// 					  key_eui[8], key_eui[9], key_eui[10], key_eui[11],
		// 					  key_eui[12], key_eui[13], key_eui[14], key_eui[15]);
		// 		api.lorawan.nwkskey.get(key_eui, 16);
		// 		Serial.printf("NwsKey = %02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X\r\n",
		// 					  key_eui[0], key_eui[1], key_eui[2], key_eui[3],
		// 					  key_eui[4], key_eui[5], key_eui[6], key_eui[7],
		// 					  key_eui[8], key_eui[9], key_eui[10], key_eui[11],
		// 					  key_eui[12], key_eui[13], key_eui[14], key_eui[15]);
		// 		api.lorawan.daddr.set(key_eui, 4);
		// 		Serial.printf("DevAddr = %02X%02X%02X%02X\r\n",
		// 					  key_eui[0], key_eui[1], key_eui[2], key_eui[3]);
		// 	}
		// }
		// else if (nw_mode == 0)
		// {
		// 	Serial.printf("Frequency = %d\r\n", api.lora.pfreq.get());
		// 	Serial.printf("SF = %d\r\n", api.lora.psf.get());
		// 	Serial.printf("BW = %d\r\n", api.lora.pbw.get());
		// 	Serial.printf("CR = %d\r\n", api.lora.pcr.get());
		// 	Serial.printf("Preamble length = %d\r\n", api.lora.ppl.get());
		// 	Serial.printf("TX power = %d\r\n", api.lora.ptp.get());
		// }
		// else
		// {
		// 	Serial.printf("Frequency = %d\r\n", api.lora.pfreq.get());
		// 	Serial.printf("Bitrate = %d\r\n", api.lora.pbr.get());
		// 	Serial.printf("Deviaton = %d\r\n", api.lora.pfdev.get());
		// }
		AT_PRINTF("Device Status:");
		value_str = api.system.modelId.get();
		value_str.toUpperCase();
		AT_PRINTF("Module: %s", value_str.c_str());
		AT_PRINTF("Version: %s", api.system.firmwareVersion.get().c_str());
		AT_PRINTF("Send time: %d s", g_send_repeat_time / 1000);
		nw_mode = api.lorawan.nwm.get();
		AT_PRINTF("Network mode %s", nwm_list[nw_mode]);
		if (nw_mode == 1)
		{
			AT_PRINTF("Network %s", api.lorawan.njs.get() ? "joined" : "not joined");
			region_set = api.lorawan.band.get();
			AT_PRINTF("Region: %d", region_set);
			AT_PRINTF("Region: %s", regions_list[region_set]);
			if (api.lorawan.njm.get())
			{
				AT_PRINTF("OTAA mode");
				api.lorawan.deui.get(key_eui, 8);
				AT_PRINTF("DevEUI = %02X%02X%02X%02X%02X%02X%02X%02X",
						  key_eui[0], key_eui[1], key_eui[2], key_eui[3],
						  key_eui[4], key_eui[5], key_eui[6], key_eui[7]);
				api.lorawan.appeui.get(key_eui, 8);
				AT_PRINTF("AppEUI = %02X%02X%02X%02X%02X%02X%02X%02X",
						  key_eui[0], key_eui[1], key_eui[2], key_eui[3],
						  key_eui[4], key_eui[5], key_eui[6], key_eui[7]);
				api.lorawan.appkey.get(key_eui, 16);
				AT_PRINTF("AppKey = %02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
						  key_eui[0], key_eui[1], key_eui[2], key_eui[3],
						  key_eui[4], key_eui[5], key_eui[6], key_eui[7],
						  key_eui[8], key_eui[9], key_eui[10], key_eui[11],
						  key_eui[12], key_eui[13], key_eui[14], key_eui[15]);
			}
			else
			{
				AT_PRINTF("ABP mode");
				api.lorawan.appskey.get(key_eui, 16);
				AT_PRINTF("AppsKey = %02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
						  key_eui[0], key_eui[1], key_eui[2], key_eui[3],
						  key_eui[4], key_eui[5], key_eui[6], key_eui[7],
						  key_eui[8], key_eui[9], key_eui[10], key_eui[11],
						  key_eui[12], key_eui[13], key_eui[14], key_eui[15]);
				api.lorawan.nwkskey.get(key_eui, 16);
				AT_PRINTF("NwsKey = %02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
						  key_eui[0], key_eui[1], key_eui[2], key_eui[3],
						  key_eui[4], key_eui[5], key_eui[6], key_eui[7],
						  key_eui[8], key_eui[9], key_eui[10], key_eui[11],
						  key_eui[12], key_eui[13], key_eui[14], key_eui[15]);
				api.lorawan.daddr.set(key_eui, 4);
				AT_PRINTF("DevAddr = %02X%02X%02X%02X",
						  key_eui[0], key_eui[1], key_eui[2], key_eui[3]);
			}
		}
		else if (nw_mode == 0)
		{
			AT_PRINTF("Frequency = %d\r\n", api.lora.pfreq.get());
			AT_PRINTF("SF = %d", api.lora.psf.get());
			AT_PRINTF("BW = %d", api.lora.pbw.get());
			AT_PRINTF("CR = %d", api.lora.pcr.get());
			AT_PRINTF("Preamble length = %d", api.lora.ppl.get());
			AT_PRINTF("TX power = %d", api.lora.ptp.get());
		}
		else
		{
			AT_PRINTF("Frequency = %d", api.lora.pfreq.get());
			AT_PRINTF("Bitrate = %d", api.lora.pbr.get());
			AT_PRINTF("Deviaton = %d", api.lora.pfdev.get());
		}
	}
	else
	{
		return AT_PARAM_ERROR;
	}
	return AT_OK;
}

/**
 * @brief Get setting from flash
 *
 * @param setting_type type of setting, valid values
 * 			GNSS_OFFSET for GNSS precision and data format
 * @return true read from flash was successful
 * @return false read from flash failed or invalid settings type
 */
bool get_at_setting(uint32_t setting_type)
{
	uint8_t flash_value[16];
	switch (setting_type)
	{
	// case GNSS_OFFSET:
	// 	if (!api.system.flash.get(GNSS_OFFSET, flash_value, 2))
	// 	{
	// 		MYLOG("AT_CMD", "Failed to read GNSS value from Flash");
	// 		return false;
	// 	}
	// 	if (flash_value[1] != 0xAA)
	// 	{
	// 		MYLOG("AT_CMD", "Invalid GNSS settings, using default");
	// 		gnss_format = 0;
	// 		save_at_setting(GNSS_OFFSET);
	// 	}
	// 	if (flash_value[0] > HELIUM_MAPPER)
	// 	{
	// 		MYLOG("AT_CMD", "No valid GNSS value found, set to default, read 0X%0X", flash_value[0]);
	// 		gnss_format = 0;
	// 		return false;
	// 	}
	// 	gnss_format = flash_value[0];
	// 	MYLOG("AT_CMD", "Found GNSS format to %d", flash_value[0]);
	// 	return true;
	// 	break;
	case SEND_FREQ_OFFSET:
		if (!api.system.flash.get(SEND_FREQ_OFFSET, flash_value, 5))
		{
			MYLOG("AT_CMD", "Failed to read send frequency from Flash");
			return false;
		}
		if (flash_value[4] != 0xAA)
		{
			MYLOG("AT_CMD", "No valid send frequency found, set to default, read 0X%02X 0X%02X 0X%02X 0X%02X",
				  flash_value[0], flash_value[1],
				  flash_value[2], flash_value[3]);
			g_send_repeat_time = 0;
			save_at_setting(SEND_FREQ_OFFSET);
			return false;
		}
		MYLOG("AT_CMD", "Read send frequency 0X%02X 0X%02X 0X%02X 0X%02X",
			  flash_value[0], flash_value[1],
			  flash_value[2], flash_value[3]);
		g_send_repeat_time = 0;
		g_send_repeat_time |= flash_value[0] << 0;
		g_send_repeat_time |= flash_value[1] << 8;
		g_send_repeat_time |= flash_value[2] << 16;
		g_send_repeat_time |= flash_value[3] << 24;
		MYLOG("AT_CMD", "Send frequency found %ld", g_send_repeat_time);
		return true;
		break;
	default:
		return false;
	}
}

/**
 * @brief Save setting to flash
 *
 * @param setting_type type of setting, valid values
 * 			GNSS_OFFSET for GNSS precision and data format
 * @return true write to flash was successful
 * @return false write to flash failed or invalid settings type
 */
bool save_at_setting(uint32_t setting_type)
{
	uint8_t flash_value[16] = {0};
	bool wr_result = false;
	switch (setting_type)
	{
	// case GNSS_OFFSET:
	// 	flash_value[0] = gnss_format;
	// 	flash_value[1] = 0xAA;
	// 	return api.system.flash.set(GNSS_OFFSET, flash_value, 2);
	// 	break;
	case SEND_FREQ_OFFSET:
		flash_value[0] = (uint8_t)(g_send_repeat_time >> 0);
		flash_value[1] = (uint8_t)(g_send_repeat_time >> 8);
		flash_value[2] = (uint8_t)(g_send_repeat_time >> 16);
		flash_value[3] = (uint8_t)(g_send_repeat_time >> 24);
		flash_value[4] = 0xAA;
		MYLOG("AT_CMD", "Writing send frequency 0X%02X 0X%02X 0X%02X 0X%02X ",
			  flash_value[0], flash_value[1],
			  flash_value[2], flash_value[3]);
		wr_result = api.system.flash.set(SEND_FREQ_OFFSET, flash_value, 5);
		// MYLOG("AT_CMD", "Writing %s", wr_result ? "Success" : "Fail");
		wr_result = true;
		return wr_result;
		break;
	default:
		return false;
		break;
	}
	return false;
}
