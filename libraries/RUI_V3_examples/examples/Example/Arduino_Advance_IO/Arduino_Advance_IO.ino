
// Set pin number 
#if defined(WISBLOCK_BASE_5005) || defined(WISBLOCK_BASE_5005_O)
uint8_t ledPin = WB_LED2; // Set led pin to Blue Led
uint8_t pulsePin = WB_IO1; // Set pulse Pin to IO1
#else
#warning please set the right pin refer to the documentation.
uint8_t ledPin = 0xFF; // Set any pin to test tone()
uint8_t pulsePin = 0xFF; // Set any pin to be pulse Pin
#endif 
// variable for recording the pulse status timing.
unsigned long duration;

void setup()
{
  // initialize serial communication at 115200 bits per second
  Serial.begin(115200);

  Serial.println("RAKwireless Arduino Advance IO Example");
  Serial.println("------------------------------------------------------");
  // initialize digital pin "pulsePin" as an input with the internal pull-up resistor enabled
  pinMode(pulsePin, INPUT_PULLUP);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // waits for the pin to go from HIGH to LOW, starts timing, then waits for the pin to go HIGH and stops timing.
  // read the pulsePin time value
  duration = pulseIn(pulsePin, LOW);
  Serial.print("Pulse duration = ");
  Serial.print((float)duration / 1000000); // convert microseconds to seconds and print it out
  Serial.println(" sec");

  if (duration >= 15000000) // LED turns off when duration exceed 15 seconds
    noTone(ledPin);
  else if (duration >= 10000000)// LED turns on 5 seconds when duration in 10 ~ 15 seconds
    tone(ledPin, 494, 5000);
  else if (duration >= 5000000)// LED turns on when seconds 5 seconds and less than 10 seconds
    tone(ledPin, 494);
}
