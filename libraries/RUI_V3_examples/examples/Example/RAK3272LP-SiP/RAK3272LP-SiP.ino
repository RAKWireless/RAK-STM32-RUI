
void setup()
{
    uint32_t baudrate = Serial.getBaudrate();
    Serial.begin(baudrate);
    Serial.println("RAKwireless RAK3272LP-SiP Example");
    Serial.println("------------------------------------------------------");
}

void loop()
{
    /* Destroy this busy loop and use timer to do what you want instead,
     * so that the system thread can auto enter low power mode by api.system.lpm.set(1); */
    api.system.scheduler.task.destroy();
}
