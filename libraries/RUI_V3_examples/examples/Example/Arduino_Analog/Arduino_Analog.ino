//Set pin number
#if defined(WISBLOCK_BASE_5005) || defined(WISBLOCK_BASE_5005_O)
uint8_t analogPin = WB_A0;	// potentiometer wiper (middle pin) connected to AIN0(J11 AIN)
			   // outside leads to ground and +3.6V
#else
#warning Please set the right pin refer to the documentation
uint8_t analogPin = 0xFF;	//analog Pins 
#endif

void setup()
{
  // initialize serial communication at 115200 bits per second
  Serial.begin(115200);
  Serial.println("RAKwireless Arduino Analog Example");
  Serial.println("------------------------------------------------------");
}

void loop()
{
  // variable for reading the analog pin value.
  int adc_value = analogRead(analogPin);
  Serial.printf("ADC pin value = %d\r\n", adc_value);	// print analogPin adc value 
  // Vref = +3.6V, Voltage = adcValue * Vref / (2 ^ n - 1);
  Serial.printf("Voltage value = %f V\r\n",
		(float) 3.6 * (float) adc_value / (float) 1023.0);
  delay(1000);
}
