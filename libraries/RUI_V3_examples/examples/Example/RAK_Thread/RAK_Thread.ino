
#if defined(WISBLOCK_BASE_5005) || defined(WISBLOCK_BASE_5005_O)
uint8_t ledPin = LED_BLUE;
uint8_t inputPin = WB_IO1;
#else
#warning Please set a right pin refer to the documentation
uint8_t ledPin = 0xFF;
uint8_t inputPin = 0xFF;
#endif

int buttonState;

rt rtBlink;
rt rtButton;

int blinkThread(struct rt *rt) {
    RT_BEGIN(rt);

    for (;;) {
        if (buttonState == HIGH) {
            digitalWrite(ledPin, HIGH);
            RT_SLEEP(rt, 200);
            digitalWrite(ledPin, LOW);
            RT_SLEEP(rt, 100);
        } else {
            digitalWrite(ledPin, LOW);
            RT_YIELD(rt);
        }
    }

    RT_END(rt);
}

int buttonThread(struct rt *rt) {
    RT_BEGIN(rt);
    for (;;) {
        buttonState = digitalRead(inputPin);
        RT_YIELD(rt);
    }
    RT_END(rt);
}

void setup()
{
    Serial.begin(115200);

    Serial.println("RAKwireless RAK Thread Example");
    Serial.println("------------------------------------------------------");
    pinMode(ledPin, OUTPUT);
    pinMode(inputPin, INPUT);
    buttonState = digitalRead(inputPin);
    RT_INIT(&rtBlink);
    RT_INIT(&rtButton);
}

void loop()
{
    RT_SCHEDULE(blinkThread(&rtBlink));
    RT_SCHEDULE(buttonThread(&rtButton));
}
