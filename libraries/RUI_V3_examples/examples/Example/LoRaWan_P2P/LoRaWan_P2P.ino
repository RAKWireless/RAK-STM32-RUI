
long startTime;

void setup()
{
  Serial.begin(115200);

  Serial.println("RAKwireless LoRaWan P2P Example");
  Serial.println("------------------------------------------------------");
  delay(2000);
  startTime = millis();

  Serial.println("P2P Start");

  Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
  Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");
  Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
  Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
  Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
  Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
  Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");

  randomSeed(millis());
}

void loop()
{
  uint8_t payload[] = "payload";

  int rxDelay = random(3000, 5000);

  /* Receive P2P data every 10 seconds**/
  if (millis() - startTime >= 10 * 1000)
  {
    Serial.printf("P2P Rx start for %d millisSconds\r\n", rxDelay);
    startTime = millis();
    Serial.printf("P2P set Rx mode %s\r\n", api.lorawan.precv(rxDelay) ? "Success" : "Fail");
    delay(rxDelay);
  }
  else
  {

    Serial.printf("P2P send %s\r\n", api.lorawan.psend(sizeof(payload), payload) ? "Success" : "Fail");
    delay(1000);
  }
}
