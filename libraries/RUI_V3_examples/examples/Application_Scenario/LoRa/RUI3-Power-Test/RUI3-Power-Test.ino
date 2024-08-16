/**
 * @file WisBlock-Sensor-Node.ino
 * @author Bernd Giesecke (bernd@giesecke.tk)
 * @brief RUI3 based code for easy testing of WisBlock I2C modules
 * @version 0.1
 * @date 2022-04-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "main.h"

/** Initialization results */
bool ret;

/** LoRaWAN packet */
WisCayenne g_solution_data(255);

/** Set the device name, max length is 10 characters */
char g_dev_name[64] = "RUI3 Power Test";

/** Send repeat time */
uint32_t g_send_repeat_time = 0;

// Flag to enable confirmed messages
bool g_confirmed_msg_enabled = false;

/**
 * @brief Callback after packet was received
 *
 * @param data Structure with the received data
 */
void receiveCallback(SERVICE_LORA_RECEIVE_T *data)
{
	MYLOG("RX-CB", "RX, port %d, DR %d, RSSI %d, SNR %d", data->Port, data->RxDatarate, data->Rssi, data->Snr);
	for (int i = 0; i < data->BufferSize; i++)
	{
		Serial.printf("%02X", data->Buffer[i]);
	}
	Serial.print("\r\n");
}

/**
 * @brief Callback after TX is finished
 *
 * @param status TX status
 */
void sendCallback(int32_t status)
{
	// gnss_active = false;
	MYLOG("TX-CB", "TX status %d", status);
#ifndef _VARIANT_RAK3172_SIP_
	digitalWrite(LED_BLUE, LOW);
#endif
	digitalWrite(WB_IO2, LOW);
}

/**
 * @brief Callback after join request cycle
 *
 * @param status Join result
 */
void joinCallback(int32_t status)
{
	// MYLOG("JOIN-CB", "Join result %d", status);
	if (status != 0)
	{
		if (!(ret = api.lorawan.join()))
		{
			Serial.println("+EVT:JOIN FAILED");
		}
	}
	else
	{
		MYLOG("JOIN-CB", "Set the data rate  %s", api.lorawan.dr.set(DR_3) ? "Success" : "Fail");
		MYLOG("JOIN-CB", "Disable ADR  %s", api.lorawan.adr.set(false) ? "Success" : "Fail");
		Serial.println("+EVT:JOINED");
#ifndef _VARIANT_RAK3172_SIP_
		digitalWrite(LED_BLUE, LOW);
#endif
		digitalWrite(WB_IO2, LOW);
	}
}

/**
 * @brief Arduino setup, called once after reboot/power-up
 *
 */
void setup()
{
	// Setup the callbacks for joined and send finished
	api.lorawan.registerRecvCallback(receiveCallback);
	api.lorawan.registerSendCallback(sendCallback);
	api.lorawan.registerJoinCallback(joinCallback);

#ifndef _VARIANT_RAK3172_SIP_
	pinMode(LED_GREEN, OUTPUT);
	digitalWrite(LED_GREEN, HIGH);
	pinMode(LED_BLUE, OUTPUT);
	digitalWrite(LED_BLUE, HIGH);
#endif

	pinMode(WB_IO2, OUTPUT);
	digitalWrite(WB_IO2, HIGH);

	// Use RAK_CUSTOM_MODE supresses AT command and default responses from RUI3
	// Serial.begin(115200, RAK_CUSTOM_MODE);
	// Use "normal" mode to have AT commands available
	Serial.begin(115200);

#ifdef _VARIANT_RAK4630_
	time_t serial_timeout = millis();
	// On nRF52840 the USB serial is not available immediately
	while (!Serial.available())
	{
		if ((millis() - serial_timeout) < 5000)
		{
			delay(100);
			digitalWrite(LED_GREEN, !digitalRead(LED_GREEN));
		}
		else
		{
			break;
		}
	}
#else
	// For RAK3172 just wait a little bit for the USB to be ready
	delay(5000);
#endif

	// Add custom status AT command
	init_status_at();

	MYLOG("SETUP", "RAKwireless %s Node", g_dev_name);
	MYLOG("SETUP", "Setup the device with AT commands first");

	// Get saved sending frequency from flash
	get_at_setting(SEND_FREQ_OFFSET);

	if (api.system.timer.create(RAK_TIMER_0, (RAK_TIMER_HANDLER)sensor_handler, RAK_TIMER_PERIODIC) != true) {
		MYLOG("SETUP", "Creating timer failed.");
	}
	if (g_send_repeat_time != 0)
	{
		if (api.system.timer.start(RAK_TIMER_0, g_send_repeat_time, NULL) != true) {
			MYLOG("SETUP", "Starting timer failed.");
		}
	}

	// Register the custom AT command to set the send frequency
	MYLOG("SETUP", "Add custom AT command %s", init_frequency_at() ? "Success" : "Fail");

#ifndef _VARIANT_RAK3172_SIP_
	// digitalWrite(LED_BLUE, LOW);
	digitalWrite(LED_GREEN, LOW);
#endif
}

/**
 * @brief sensor_handler is a timer function called every
 * g_send_repeat_time milliseconds. Default is 120000. Can be
 * changed in main.h
 *
 */
void sensor_handler(void *)
{
	digitalWrite(WB_IO2, HIGH);
	// MYLOG("SENS", "Start");
#ifndef _VARIANT_RAK3172_SIP_
	digitalWrite(LED_BLUE, HIGH);
#endif

	// Check if the node has joined the network
	if (!api.lorawan.njs.get())
	{
		MYLOG("UPLINK", "Not joined, skip sending");
		digitalWrite(WB_IO2, LOW);
		return;
	}

	// Clear payload
	g_solution_data.reset();

	// Add battery voltage
	g_solution_data.addVoltage(LPP_CHANNEL_BATT, api.system.bat.get());

	send_packet();
}

/**
 * @brief This example is complete timer
 * driven. The loop() does nothing than
 * sleep.
 *
 */
void loop()
{
	api.system.sleep.all();
}

/**
 * @brief Send the data packet that was prepared in
 * Cayenne LPP format by the different sensor and location
 * aqcuision functions
 *
 */
void send_packet(void)
{
	MYLOG("UPLINK", "Send packet with size %d", g_solution_data.getSize());

	// Send the packet
	if (api.lorawan.send(g_solution_data.getSize(), g_solution_data.getBuffer(), 2, g_confirmed_msg_enabled, 1))
	{
		MYLOG("UPLINK", "Packet enqueued");
	}
	else
	{
		MYLOG("UPLINK", "Send failed");
	}
}
