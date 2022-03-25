bool ret;
void setup()
{
  Serial.begin(115200);

  Serial.println("RAKwireless LoRaWan OTAA Example");
  Serial.println("------------------------------------------------------");
  // OTAA Device EUI MSB
  uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
  // OTAA Application EUI MSB
  uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
  // OTAA Application Key MSB
  uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

  if(!(ret = api.lorawan.appeui.set(node_app_eui, 8)))
  {
       Serial.printf("LoRaWan OTAA - set device EUI is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.appkey.set(node_app_key, 16)))
  {
       Serial.printf("LoRaWan OTAA - set application EUI is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.deui.set(node_device_eui, 8)))
  {
       Serial.printf("LoRaWan OTAA - set application key is incorrect! \r\n");
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
       Serial.printf("LoRaWan OTAA - set band is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.njm.set(1)))
  {
       Serial.printf("LoRaWan OTAA - set network join mode is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.join()))
  {
       Serial.printf("LoRaWan OTAA - join fail! \r\n");
       return;
  }
}

void loop()
{
  uint8_t rbuff[16];

  Serial.print("Network Join Status=");
  Serial.println(api.lorawan.njs.get());

  api.lorawan.appskey.get(rbuff, 16);
  Serial.print("Application Session Key=0x");
  for (int i = 0; i < 16; i++)
  {
    Serial.printf("%x", rbuff[i]);
  }
  Serial.print("\r\n");

  api.lorawan.nwkskey.get(rbuff, 16);
  Serial.print("Network Session Key=0x");
  for (int i = 0; i < 16; i++)
  {
    Serial.printf("%x", rbuff[i]);
  }
  Serial.print("\r\n");

  api.lorawan.netid.get(rbuff, 16);
  Serial.print("24-bit Network Identifier(NetId)=0x");
  for (int i = 0; i < 3; i++)
  {
    Serial.printf("%x", rbuff[i]);
  }
  Serial.print("\r\n");

  api.lorawan.daddr.get(rbuff, 16);
  Serial.print("Device Address=0x");
  for (int i = 0; i < 4; i++)
  {
    Serial.printf("%x", rbuff[i]);
  }
  Serial.print("\r\n");
  delay(1000);
}
