
void setup()
{
  Serial.println("RAKwireless RAK3272-SiP Example");
  Serial.println("------------------------------------------------------");
}

void loop()
{
  /* Destroy this busy loop and use timer to do what you want instead,
   * so that the system thread can auto enter low power mode by api.system.lpm.set(1); */
  api.system.scheduler.task.destroy();
}
