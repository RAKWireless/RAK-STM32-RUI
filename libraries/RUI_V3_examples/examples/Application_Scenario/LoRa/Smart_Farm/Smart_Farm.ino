/*************************************
 * Download RAK1901/RAK1902 library from https://downloads.rakwireless.com/RUI/RUI3/Library/
 * Besides, install them into Arduino IDE
 *************************************/
#include "rak1901.h"
#include "rak1902.h"

void uplink_routine();

#define SMART_FARM_PERIOD   (20000)
/*************************************

   LoRaWAN band setting:
     RAK_REGION_EU433
     RAK_REGION_CN470
     RAK_REGION_RU864
     RAK_REGION_IN865
     RAK_REGION_EU868
     RAK_REGION_US915
     RAK_REGION_AU915
     RAK_REGION_KR920
     RAK_REGION_AS923

 *************************************/
#define SMART_FARM_BAND     (RAK_REGION_EU868)
#define SMART_FARM_DEVEUI   {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x88}
#define SMART_FARM_APPEUI   {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x0E}
#define SMART_FARM_APPKEY   {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3E}

/** Temperature & Humidity sensor **/
rak1901 th_sensor;
/** Air Pressure sensor **/
rak1902 p_sensor;

/** Packet buffer for sending */
uint8_t collected_data[64] = { 0 };

void recvCallback(SERVICE_LORA_RECEIVE_T * data)
{
    if (data->BufferSize > 0) {
        Serial.println("Something received!");
        for (int i = 0; i < data->BufferSize; i++) {
            Serial.printf("%x", data->Buffer[i]);
        }
        Serial.print("\r\n");
    }
}

void joinCallback(int32_t status)
{
    Serial.printf("Join status: %d\r\n", status);
}

void sendCallback(int32_t status)
{
    if (status == 0) {
        Serial.println("Successfully sent");
    } else {
        Serial.println("Sending failed");
    }
}

void setup()
{
    Serial.begin(115200, RAK_AT_MODE);
    delay(2000);
  
    Serial.println("RAKwireless Smart Farm Example");
    Serial.println("------------------------------------------------------");
  
    // OTAA Device EUI MSB first
    uint8_t node_device_eui[8] = SMART_FARM_DEVEUI;
    // OTAA Application EUI MSB first
    uint8_t node_app_eui[8] = SMART_FARM_APPEUI;
    // OTAA Application Key MSB first
    uint8_t node_app_key[16] = SMART_FARM_APPKEY;
  
    if (!api.system.lpm.set(1)) {
        Serial.printf("LoRaWan Smart Farm - set low power mode is incorrect! \r\n");
        return;
    }
  
    if (!api.lorawan.mode.set()) {
        Serial.printf("LoRaWan Smart Farm - set network working mode is incorrect! \r\n");
        return;
    }
  
    if (!api.lorawan.appeui.set(node_app_eui, 8)) {
        Serial.printf("LoRaWan Smart Farm - set application EUI is incorrect! \r\n");
        return;
    }
    if (!api.lorawan.appkey.set(node_app_key, 16)) {
        Serial.printf("LoRaWan Smart Farm - set application key is incorrect! \r\n");
        return;
    }
    if (!api.lorawan.deui.set(node_device_eui, 8)) {
        Serial.printf("LoRaWan Smart Farm - set device EUI is incorrect! \r\n");
        return;
    }
  
    if (!api.lorawan.band.set(SMART_FARM_BAND)) {
        Serial.printf("LoRaWan Smart Farm - set band is incorrect! \r\n");
        return;
    }
    if (!api.lorawan.deviceClass.set(RAK_LORA_CLASS_A)) {
        Serial.printf("LoRaWan Smart Farm - set device class is incorrect! \r\n");
        return;
    }
    if (!api.lorawan.njm.set(RAK_LORA_OTAA))	// Set the network join mode to OTAA
    {
        Serial.printf("LoRaWan Smart Farm - set network join mode is incorrect! \r\n");
        return;
    }
    if (!api.lorawan.join())	// Join to Gateway
    {
        Serial.printf("LoRaWan Smart Farm - join fail! \r\n");
        return;
    }
  
    Serial.println("++++++++++++++++++++++++++");
    Serial.println("RUI3 Environment Sensing");
    Serial.println("++++++++++++++++++++++++++");
  
    Wire.begin();			// Start I2C Bus
    Serial.printf("RAK1901 init %s\r\n", th_sensor.init()? "success" : "fail");	// Check if RAK1901 init success
    Serial.printf("RAK1902 init %s\r\n", p_sensor.init()? "success" : "fail");	// Check if RAK1902 init success
  
    /** Wait for Join success */
    while (api.lorawan.njs.get() == 0) {
        Serial.print("Wait for LoRaWAN join...");
        api.lorawan.join();
        delay(10000);
    }
  
    if (!api.lorawan.adr.set(true)) {
        Serial.printf("LoRaWan Smart Farm - set adaptive data rate is incorrect! \r\n");
        return;
    }
    if (!api.lorawan.rety.set(1)) {
        Serial.printf("LoRaWan Smart Farm - set retry times is incorrect! \r\n");
        return;
    }
    if (!api.lorawan.cfm.set(1)) {
        Serial.printf("LoRaWan Smart Farm - set confirm mode is incorrect! \r\n");
        return;
    }
  
    /** Check LoRaWan Status*/
    Serial.printf("Duty cycle is %s\r\n", api.lorawan.dcs.get()? "ON" : "OFF");	// Check Duty Cycle status
    Serial.printf("Packet is %s\r\n", api.lorawan.cfm.get()? "CONFIRMED" : "UNCONFIRMED");	// Check Confirm status
    uint8_t assigned_dev_addr[4] = { 0 };
    api.lorawan.daddr.get(assigned_dev_addr, 4);
    Serial.printf("Device Address is %02X%02X%02X%02X\r\n", assigned_dev_addr[0], assigned_dev_addr[1], assigned_dev_addr[2], assigned_dev_addr[3]);	// Check Device Address
    Serial.printf("Uplink period is %ums\r\n", SMART_FARM_PERIOD);
    Serial.println("");
    api.lorawan.registerRecvCallback(recvCallback);
    api.lorawan.registerJoinCallback(joinCallback);
    api.lorawan.registerSendCallback(sendCallback);
    if (api.system.timer.create(RAK_TIMER_0, (RAK_TIMER_HANDLER)uplink_routine, RAK_TIMER_PERIODIC) != true) {
        Serial.printf("LoRaWan Smart Farm - Creating timer failed.\r\n");
        return;
    }
    if (api.system.timer.start(RAK_TIMER_0, SMART_FARM_PERIOD, NULL) != true) {
        Serial.printf("LoRaWan Smart Farm - Starting timer failed.\r\n");
        return;
    }
}

void uplink_routine()
{
    /** Get sensor RAK1901 values */
    th_sensor.update();
  
    float temp_f = th_sensor.temperature();
    float humid_f = th_sensor.humidity();
    float press_f = p_sensor.pressure(MILLIBAR);
    Serial.printf("T %.2f H %.2f P %.2f\r\n", temp_f, humid_f, press_f);
  
    uint16_t t = (uint16_t) (temp_f * 10.0);
    uint16_t h = (uint16_t) (humid_f * 2);
    uint32_t pre = (uint32_t) (press_f * 10);
    //uint16_t batt = (uint16_t)(api.system.bat.get() / 10);
  
    /** Cayenne Low Power Payload */
    uint8_t data_len = 0;
    collected_data[data_len++] = 0x01;	//Data Channel: 1
    collected_data[data_len++] = 0x67;	//Type: Temperature Sensor
    collected_data[data_len++] = (uint8_t) (t >> 8);
    collected_data[data_len++] = (uint8_t) t;
    collected_data[data_len++] = 0x02;	//Data Channel: 2
    collected_data[data_len++] = 0x68;	//Type: Humidity Sensor
    collected_data[data_len++] = (uint8_t) h;
    collected_data[data_len++] = 0x03;	//Data Channel: 3
    collected_data[data_len++] = 0x73;	//Type: Barometer
    collected_data[data_len++] = (uint8_t) ((pre & 0x0000FF00) >> 8);
    collected_data[data_len++] = (uint8_t) (pre & 0x000000FF);
    //collected_data[data_len++] = 0x04;  //Data Channel: 4
    //collected_data[data_len++] = 0x02;  //Type: Analog Input
    //collected_data[data_len++] = (uint8_t)(batt >> 8);
    //collected_data[data_len++] = (uint8_t)batt;
  
    Serial.println("Data Packet:");
    for (int i = 0; i < data_len; i++) {
        Serial.printf("0x%02X ", collected_data[i]);
    }
    Serial.println("");
  
    /** Send the data package */
    if (api.lorawan.send(data_len, (uint8_t *) & collected_data, 2, true, 1)) {
        Serial.println("Sending is requested");
    } else {
        Serial.println("Sending failed");
    }
}

void loop()
{
    /* Destroy this busy loop and use timer to do what you want instead,
     * so that the system thread can auto enter low power mode by api.system.lpm.set(1); */
    api.system.scheduler.task.destroy();
}
