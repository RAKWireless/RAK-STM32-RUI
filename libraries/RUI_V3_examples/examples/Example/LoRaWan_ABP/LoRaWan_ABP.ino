bool ret;
void recv_cb(SERVICE_LORA_RECEIVE_T *data)
{
  Serial.println("Something received!");
  for (int i = 0; i < data->BufferSize; i++)
  {
    Serial.printf("%x", data->Buffer[i]);
  }
  Serial.print("\r\n");
}

void join_cb(int32_t status)
{
  Serial.printf("Join status: %d\r\n", status);
}

void send_cb(int32_t status)
{
  Serial.printf("Send status: %d\r\n", status);
}

void setup()
{
  Serial.begin(115200, RAK_AT_MODE);

  Serial.println("RAKwireless LoRaWan ABP Example");
  Serial.println("------------------------------------------------------");
  // ABP Device Address
  uint8_t node_dev_addr[4] = {0x05, 0x05, 0x06, 0x06};
  // ABP Application Session Key
  uint8_t node_app_skey[16] = {0x25, 0xC4, 0xF1, 0xD1, 0x78, 0xC8, 0x8D, 0x01, 0xA8, 0x80, 0xC2, 0x79, 0xA7, 0x9F, 0x34, 0x3B};
  // ABP Network Session Key
  uint8_t node_nwk_skey[16] = {0xD6, 0x03, 0x37, 0xAC, 0x97, 0x4C, 0x43, 0x2F, 0xF3, 0x7A, 0xF9, 0xA7, 0x9B, 0xE8, 0x50, 0xF7};

  if(!(ret = api.lorawan.daddr.set(node_dev_addr, 4)))
  {
       Serial.printf("LoRaWan ABP - set device addr is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.appskey.set(node_app_skey, 16)))
  {
       Serial.printf("LoRaWan ABP - set apps key is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.nwkskey.set(node_nwk_skey, 16)))
  {
       Serial.printf("LoRaWan ABP - set network session key is incorrect! \r\n");
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
       Serial.printf("LoRaWan ABP - set band is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.njm.set(0)))
  {
       Serial.printf("LoRaWan ABP - set network join mode is incorrect! \r\n");
       return;
  }
  if(!(ret = api.lorawan.join()))
  {
       Serial.printf("LoRaWan ABP - join fail! \r\n");
       return;
  }
  
  api.lorawan.registerRecvCallback(recv_cb);
  api.lorawan.registerJoinCallback(join_cb);
  api.lorawan.registerSendCallback(send_cb);

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
  uint8_t rbuff[16];
  uint8_t payload[] = "example";

  Serial.print("Network Join Status=");
  Serial.println(api.lorawan.njs.get());

  api.lorawan.deui.get(rbuff, 8);
  Serial.print("Device EUI=0x");
  for (int i = 0; i < 8; i++)
  {
    Serial.printf("%02x", rbuff[i]);
  }
  Serial.print("\r\n");

  api.lorawan.appeui.get(rbuff, 8);
  Serial.print("Application EUI=0x");
  for (int i = 0; i < 8; i++)
  {
    Serial.printf("%02x", rbuff[i]);
  }
  Serial.print("\r\n");

  api.lorawan.appkey.get(rbuff, 16);
  Serial.print("Application Key=0x");
  for (int i = 0; i < 8; i++)
  {
    Serial.printf("%02x", rbuff[i]);
  }
  Serial.print("\r\n");

  api.lorawan.appskey.get(rbuff, 16);
  Serial.print("Application Session Key=0x");
  for (int i = 0; i < 16; i++)
  {
    Serial.printf("%02x", rbuff[i]);
  }
  Serial.print("\r\n");

  api.lorawan.nwkskey.get(rbuff, 16);
  Serial.print("Network Session Key=0x");
  for (int i = 0; i < 16; i++)
  {
    Serial.printf("%02x", rbuff[i]);
  }
  Serial.print("\r\n");

  api.lorawan.netid.get(rbuff, 16);
  Serial.print("24-bit Network Identifier(NetId)=0x");
  for (int i = 0; i < 3; i++)
  {
    Serial.printf("%02x", rbuff[i]);
  }
  Serial.print("\r\n");

  api.lorawan.daddr.get(rbuff, 16);
  Serial.print("Device Address=0x");
  for (int i = 0; i < 4; i++)
  {
    Serial.printf("%02x", rbuff[i]);
  }
  Serial.print("\r\n");

  if(!(ret = api.lorawan.send(sizeof(payload), payload, 129, false, 0)))
  {
       Serial.printf("LoRaWan ABP - send fail! \r\n");
       return;
  }
  delay(1000);
}
