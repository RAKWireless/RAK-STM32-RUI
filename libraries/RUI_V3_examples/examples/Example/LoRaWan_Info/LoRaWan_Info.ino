bool ret;
void setup()
{
  Serial.begin(115200);

  Serial.println("RAKwireless LoRaWan Info Example");
  Serial.println("------------------------------------------------------");
  // OTAA Device EUI MSB
  uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0xA8};
  // OTAA Application EUI MSB
  uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
  // OTAA Application Key MSB
  uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3F};

  if(!(ret = api.lorawan.appeui.set(node_app_eui, 8)))
  {
       Serial.printf("LoRaWan Info - set device EUI is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.appkey.set(node_app_key, 16)))
  {
       Serial.printf("LoRaWan Info - set application EUI is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.deui.set(node_device_eui, 8)))
  {
       Serial.printf("LoRaWan Info - set application key is incorrect! \r\n");
       return;
  }

  /*************************************
   *
   * LoRaWAN band setting:
   *   EU433: 0
   *   CN470: 1
   *   RU864: 2
   *   IN865: 3
   *   EU868: 4
   *   US915: 5
   *   AU915: 6
   *   KR920: 7
   *   AS923: 8
   *
   * ************************************/

  if(!(ret = api.lorawan.band.set(4)))
  {
       Serial.printf("LoRaWan Info - set band is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.njm.set(1)))
  {
       Serial.printf("LoRaWan Info - set network join mode is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.join()))
  {
       Serial.printf("LoRaWan Info - join fail! \r\n");
       return;
  }

  /**Wait for Join success */
  while (api.lorawan.njs.get() == 0)
  {
    Serial.print("Waiting for Lorawan join...");
    api.lorawan.join();
    delay(10000);
  }
}

void loop()
{
  RAK_LORA_chan_rssi chan_arssi;

  Serial.print("Get RSSI =");
  Serial.println(api.lorawan.rssi.get());

  Serial.print("Get Signal Noise Ratio =");
  Serial.println(api.lorawan.snr.get());

  Serial.print("Get LoRaWAN protocol version =");
  Serial.println(api.lorawan.ver.get());

  Serial.print("Get All open channel RSSI =");
  while (api.lorawan.arssi(&chan_arssi) == true)
  {
    if (chan_arssi.mask != 0)
    {
      Serial.printf("channel : %d,mask : %d, rssi : %d\r\n", chan_arssi.chan, chan_arssi.mask, chan_arssi.rssi);
    }
  }

  Serial.print("\r\n");
  delay(1000);
}
