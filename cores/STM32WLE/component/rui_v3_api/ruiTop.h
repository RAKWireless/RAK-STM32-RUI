#ifndef __RUI_TOP_H__
#define __RUI_TOP_H__

#include "udrv_delay.h"
#include "udrv_rtc.h"
#include "udrv_adc.h"
#include "udrv_pwm.h"
#include "pin_define.h"
#include "variant.h"
#include "binary.h"

#include <math.h>

enum BitOrder {
	LSBFIRST = 0,
	MSBFIRST = 1
};

  template<class T, class L>
  auto min(const T& a, const L& b) -> decltype((b < a) ? b : a)
  {
    return (b < a) ? b : a;
  }

  template<class T, class L>
  auto max(const T& a, const L& b) -> decltype((b < a) ? b : a)
  {
    return (a < b) ? b : a;
  }

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352


/** @} */

#define HIGH 0x1
#define LOW  0x0
#define CHANGE 2
#define FALLING 3
#define RISING 4

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
#define INPUT_PULLDOWN 0x3 //FIXME

#define LED_BUILTIN GREEN_LED

/**@addtogroup	Bit_and_Byte
 * @{
 */
/**@par	Description
 *     	Reads a bit of a number
 * @par	Syntax
 *	bitRead(value, bit);
 * @param	value		the number from which to read
 * @param	bit		which bit to read, starting at 0 for the least-significant (rightmost) bit	
 *
 * @return	The value of the bit (0 or 1)
 * @par     Example
 * @verbatim
   void setup() {
     Serial.begin(115200);
     Serial.println("Read the bits of 6(0110)");

     Serial.print("bitRead(6, 0) = ");
     Serial.println(bitRead(6, 0));    //print the first bit of 6

     Serial.print("bitRead(6, 1) = ");
     Serial.println(bitRead(6, 1));    //print the second bit of 6

     Serial.print("bitRead(6, 2) = ");
     Serial.println(bitRead(6, 2));    //print the third bit of 6

     Serial.print("bitRead(6, 3) = ");
     Serial.println(bitRead(6, 3));    //print the fourth bit of 6
   }

   void loop() {
   }
   @endverbatim
 */
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)

/**@par	Description
 *     	Sets (writes a 1 to) a bit of a numeric variable
 * @par	Syntax
 *	bitSet(value, bit);
 * @param	value		the numeric variable whose bit to set
 * @param	bit		which bit to set, starting at 0 for the least-significant (rightmost) bit
 *
 * @return	void
 * @par     Example
 * @verbatim
   void setup() {
     Serial.begin(115200);

     Serial.print("Before bitSet(): 6 => ");
     Serial.println(6, BIN);

     Serial.print("After bitSet(6, 0) => ");
     int value = 6;
     int pos = 0;
     Serial.println(bitSet(value,pos), BIN);  //set the first bit of 6(0110) to 1
   }

   void loop() {
   }
   @endverbatim
 */
#define bitSet(value, bit) ((value) |= (1UL << (bit)))

/**@par	Description
 *     	Clears (writes a 0 to) a bit of a numeric variable
 * @par	Syntax
 *	bitClear(value, bit);
 * @param	value		the numeric variable whose bit to clear
 * @param	bit		which bit to clear, starting at 0 for the least-significant (rightmost) bit
 *
 * @return	the value of the numeric variable after the bit at position n is cleared
 * @par     Example
 * @verbatim
   void setup() {
     Serial.begin(115200);

     Serial.print("Before bitClear(): 6 => ");
     Serial.println(6, BIN);

     Serial.print("After bitClear(6, 1) => ");
     int value = 6;
     int pos = 1;
     Serial.println(bitClear(value,ipos), BIN);  // set the second bit of 6(0110) to 0
   }

   void loop() {
   }
   @endverbatim
 */
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))

/**@par	Description
 *     	Writes a bit of a numeric variable
 * @par	Syntax
 *	bitWrite(value, bit, bitvalue);
 * @param	value		the numeric variable to which to write
 * @param	bit		which bit of the number to write, starting at 0 for the least-significant (rightmost) bit
 * @param	bitvalue	the value to write to the bit (0 or 1)
 *
 * @return	void
 * @par     Example
 * @verbatim
   void setup() {
     Serial.begin(115200);

     int target = 6; // set the bitWrite target to 6
     Serial.print("Before bitWrite(): 6 => ");
     Serial.println(target, BIN);

     Serial.print("After bitWrite(target, 0, 1) => ");  // Set the first bit of target to 1
     Serial.println(bitWrite(target, 0,1), BIN);      

     Serial.print("After bitWrite(target, 1, 0) => ");  // Set the second bit of target to 0
     Serial.println(bitWrite(target, 1,0), BIN);

     Serial.print("After bitWrite(target, 2, 0) => ");  // Set the third bit of target to 0
     Serial.println(bitWrite(target, 2,0), BIN);

     Serial.print("After bitWrite(target, 3, 1) => ");  // Set the fourth bit of target to 1
     Serial.println(bitWrite(target, 3,1), BIN);

     Serial.println("");
     Serial.println("target now should be 9(1001)");
     Serial.print("target = ");
     Serial.println(target);
   }

   void loop() {
   }
   @endverbatim
 */
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

/**@par	Description
 *     	Computes the value of the specified bit (bit 0 is 1, bit 1 is 2, bit 2 is 4, etc.)
 * @par	Syntax
 *	bit(b)
 * @param	b		the bit whose value to compute
 * @return	The value of the bit
 * @par     Example
 * @verbatim
   void setup() {
     Serial.begin(115200);

     Serial.print("bit 0: ");
     Serial.println(bit(0));
     Serial.print("bit 3: ");
     Serial.println(bit(3));
   }

   void loop() {
   }
   @endverbatim
 */
#define bit(b) (1UL << (b))

/**@par	Description
 *     	Extracts the low-order (rightmost) byte of a variable (e.g. a word)
 * @par	Syntax
 *	lowByte(w);
 * @param	w		a value of any type
 * @return	byte
 * @par     Example
 * @verbatim
   void setup() {
     Serial.begin(115200);
     Serial.println("Test target 0xABCD");

     Serial.print("lowByte() of 0xABCD = "); // extract the low-order byte of the target
     Serial.println(lowByte(target), HEX);

     Serial.print("highByte() of 0xABCD = "); // extract the low-order byte of the target
     Serial.println(highByte(target), HEX);
   }

   void loop() {
   }
   @endverbatim
 */
#define lowByte(w) ((uint8_t) ((w) & 0xff))

/**@par	Description
 *     	Extracts the high-order (leftmost) byte of a word (or the second lowest byte of a larger data type)
 * @par	Syntax
 *	highByte(w);
 * @param	w		a value of any type
 * @return	byte
 * @par     Example
 * @verbatim
   void setup() {
     Serial.begin(115200);
     Serial.println("Test target 0xABCD");

     Serial.print("lowByte() of 0xABCD = "); // extract the low-order byte of the target
     Serial.println(lowByte(target), HEX);

     Serial.print("highByte() of 0xABCD = "); // extract the low-order byte of the target
     Serial.println(highByte(target), HEX);
   }

   void loop() {
   }
   @endverbatim
 */
#define highByte(w) ((uint8_t) ((w) >> 8))
/** @} */

// Math
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define sq(x) ((x)*(x))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define abs(x) ((x)>0?(x):-(x))
long map(long, long, long, long, long);

long random(long max);
/**@addtogroup	Random
 * @{
 */

/**@par	Description
 *     	The random function generates pseudo-random numbers
 * @par	Syntax
 *	random(max);\n
 * 		rnadom(min, max);
 * @param	min(optional)	lower bound of the random value, inclusive(default = 0)
 * @param	max		upper bound of the random value, exclusive
 *
 * @return	A random number between min and max-1(Type: long)
 * @par     Example
 * @verbatim
   void setup() {
     Serial.begin(115200);//UART0 baudrate 115200
     randomSeed(analogRead(0));
   }

   void loop() {
     Serial.print("Random number(0 ~ 999) : ");
     uint32_t l = random(1000);
     Serial.println(l);	

     //delay 1 second
     delay(1000);
   }
   @endverbatim
 */
long random(long min, long max);

/**@par	Description
 *     	randomSeed() initializes the pseudo-random number generator, causing it to start at an arbitrary point in its random sequence. 
 * 		This sequence, while very long, and random, is always the same.\n
 *
 *		If it is important for a sequence of values generated by random() to differ, on subsequent executions of a sketch, use randomSeed() 
 *		to initialize the random number generator with a fairly random input, such as analogRead() on an unconnected pin
 * @par	Syntax
 *	randomSeed(seed);
 * @param	seed	number to initialize the pseudo-random sequence
 * @return	void
 * @par     Example
 * @verbatim
   void setup() {
     Serial.begin(115200);//UART0 baudrate 115200
     randomSeed(analogRead(0));
   }

   void loop() {
     Serial.print("Random number(0 ~ 999) : ");
     uint32_t l = random(1000);
     Serial.println(l);

     //delay 1 second
     delay(1000);
   }
   @endverbatim
 */
void randomSeed(unsigned long seed);
/**@}*/
 
typedef bool boolean;
typedef uint8_t byte;
typedef unsigned short word;

/**@addtogroup	DigitalIO
 * @{
 */
/**@par	Description
 *     	Configures the specified pin to behave either as an input or an output
 *
 * @par	Syntax
 *	pinMode(pin, mode);
 * @param	pin		the pin which you want to set
 * @param	mode		INPUT, OUTPUT, or INPUT_PULLUP
 *
 * @return	void
 * @par     Example
 * @verbatim
   uint8_t ledPin = 36;   // LED connected to digital pin 36
   uint8_t inputPin = 13; // input connected to digital pin 13 
   
   void setup()
   {
       pinMode(ledPin, OUTPUT);         // sets the digital pin 36 as output  
       pinMode(inputPin, INPUT_PULLUP); // sets the digital pin 13 as input
   }
   
   void loop()
   {
       int val = digitalRead(inputPin); // read the input pin
       if (val == LOW) 
           digitalWrite(ledPin, HIGH); // enable led if input is LOW
       else 
           digitalWrite(ledPin, LOW); // disable led if input is HIGH
   } 
   @endverbatim
 */
void pinMode(uint8_t pin, uint8_t mode);

/**@par	Description
 *     	Write a HIGH or a LOW value to a digital pin.
 *
 * @par	Syntax
 *	digitalWrite(pin, value);
 * @param	pin		the pin which you want to write
 * @param	value		HIGH or LOW
 *
 * @return	void
 * @par     Example
 * @verbatim
   uint8_t ledPin = 36;   // LED connected to digital pin 36
   uint8_t inputPin = 13; // input connected to digital pin 13

   void setup()
   {
       pinMode(ledPin, OUTPUT);         // sets the digital pin 36 as output
       pinMode(inputPin, INPUT_PULLUP); // sets the digital pin 13 as input
   }

   void loop()
   {
       int val = digitalRead(inputPin); // read the input pin
       if (val == LOW)
           digitalWrite(ledPin, HIGH); // enable led if input is LOW
       else
           digitalWrite(ledPin, LOW); // disable led if input is HIGH
   }
   @endverbatim
 */
void digitalWrite(uint8_t pin, uint8_t value);

/**@par	Description
 *     	Reads the value from a specified digital pin, either HIGH or LOW
 *
 * @par	Syntax
 *	digitalRead(pin);
 * @param 	pin		the pin which you want to read
 * @return	HIGH or LOW(Type: int)
 * @par     Example
 * @verbatim
   uint8_t ledPin = 36;   // LED connected to digital pin 36
   uint8_t inputPin = 13; // input connected to digital pin 13

   void setup()
   {
       pinMode(ledPin, OUTPUT);         // sets the digital pin 36 as output
       pinMode(inputPin, INPUT_PULLUP); // sets the digital pin 13 as input
   }

   void loop()
   {
       int val = digitalRead(inputPin); // read the input pin
       if (val == LOW)
           digitalWrite(ledPin, HIGH); // enable led if input is LOW
       else
           digitalWrite(ledPin, LOW); // disable led if input is HIGH
   }
   @endverbatim
 */
int digitalRead(uint8_t pin);
/** @} */

/**@addtogroup	AnalogIO
 * @{
 */
/**@par	Description
 *     	Reads the value from the specified analog pin
 *
 * @par	Syntax
 *	analogRead(pin);
 * @param	pin		the name of the analog input pin to read from
 * @return	The analog reading on the pin(Type: int)
 */
int analogRead(uint8_t pin);

/**@par	Description
 *     	Configures the reference voltage used for analog input 
 *
 * @par	Syntax
 *	analogReference(type);
 * @param	type		which type of reference to use\n
 * 				Type List:\n
 * 				RAK_ADC_MODE_DEFAULT\n
 * 				RAK_ADC_MODE_3_0\n
 * 				RAK_ADC_MODE_2_4\n
 * 				RAK_ADC_MODE_1_8\n
 * 				RAK_ADC_MODE_1_2\n
 *
 * @return	void
 */
void analogReference(uint8_t type);

/**@par	Description
 *     	Writes an analog value (PWM wave) to a pin. Can be used to light a LED at varying brightnesses or drive a motor at various speeds. After a call to analogWrite(), 
 * 		the pin will generate a steady rectangular wave of the specified duty cycle until the next call to analogWrite()
 * @par	Syntax
 *	analogWrite(pin, value)
 * @param	pin		the pin which you want to read	
 * @param	value		the duty cycle: between 0 (always off) and 255 (always on)
 *
 * @return	void
 * @par		Example
 * @verbatim
   int val = 0; // variable to write the LED pin
   bool state = false;
   bool ledSwitch = false;
   
   void valChage()
   {
     state = !state;
     if(val == 0)
       ledSwitch = !ledSwitch;
   }
   
   void setup() {
     // put your setup code here, to run once:
     pinMode(GREEN_LED, OUTPUT);
     pinMode(BLUE_LED, OUTPUT);
   }
   
   void loop() {
     // put your main code here, to run repeatedly:
     if(val == 0 || val == 255)
        valChage();
   
     // To determine to make the led lighter or darker
     if(state)
       val++;
     else
       val--;
     // To switch the lighting led
     if(ledSwitch)
       analogWrite(GREEN_LED ,val); // Light the green led
     else
       analogWrite(BLUE_LED, val); //Light the blue led
   
   }

   @endverbatim
 */
void analogWrite(uint8_t pin, int value);

/**@par	Description
 *     	analogReadResolution() is an extension of the Analog API for the Zero, Due, 
 * 		MKR family, Nano 33 (BLE and IoT) and Portenta.
 *
 *		Sets the size (in bits) of the value returned by analogRead(). 
 *		It defaults to 10 bits (returns values between 0-1023) for backward 
 *		compatibility with AVR based boards.
 *
 * @par	Syntax
 *	analogReadResolution(bits);
 * @param	bits		determines the resolution (in bits) of the value returned by 
 * 				the analogRead() function. You can set this between 1 and 32. 
 * 				You can set resolutions higher than the supported 12 or 16 bits, 
 * 				but values returned by analogRead() will suffer approximation
 * @return	void
 */
void analogReadResolution(uint8_t bits);

/**@par	Description
 *     	analogWriteResolution() is an extension of the Analog API for the Arduino Due.\n
 *		analogWriteResolution() sets the resolution of the analogWrite() function. 
 *		It defaults to 8 bits (values between 0-255) for backward compatibility 
 *		with AVR based boards.
 *
 * @par	Syntax
 *	analogWriteResolution(bits);
 * @param	bits		determines the resolution (in bits) of the values used in the 
 * 				analogWrite() function. The value can range from 1 to 32. 
 * 				If you choose a resolution higher or lower than your board’s 
 * 				hardware capabilities, the value used in analogWrite() will be 
 * 				either truncated if it’s too high or padded with zeros if it’s too low
 * @return	void
 */
void analogWriteResolution(uint8_t bits);
/** @} */

/**@addtogroup	AdvancedIO
 * @{
 */

/**@par	Description
 *     	Generates a square wave of the specified frequency (and 50% duty cycle) on a pin. 
 * 		A duration can be specified, otherwise the wave continues until a call to noTone(). 
 *
 * 		Only one tone can be generated at a time. If a tone is already playing on a 
 * 		different pin, the call to tone() will have no effect. If the tone is playing 
 * 		on the same pin, the call will set its frequency.
 * @par	Syntax
 *	tone(pin, frequency);\n
 * 		tone(pin, frequency, duration);
 * @param	pin			The device pin on which to generate the tone
 * @param	frequency		The frequency of the tone in hertz
 * @param	duration(optional)	The duration of the tone in milliseconds(default = no timeout)
 *
 * @return	void
 * @par     Example
 * @verbatim
   uint8_t ledPin = 36; 
   uint8_t pulsePin = 13;
   unsigned long duration;
   
   void setup() {
     Serial.begin(115200);
     pinMode(pulsePin, INPUT_PULLUP);
     pinMode(ledPin, OUTPUT);
   }
   
   void loop() {
     duration = pulseIn(pulsePin, LOW);
     Serial.print("Pulse duration = ");
     Serial.print((float)duration/1000000);
     Serial.println(" sec");
   
     if(duration >= 15000000)
       noTone(ledPin);
     else if(duration >= 10000000)
       tone(ledPin, 494, 5000);
     else if(duration >= 5000000)
       tone(ledPin, 494);
   }
   @endverbatim
 */
void tone(uint8_t pin, uint32_t frequency, uint64_t duration = 0);

/**@par	Description
 *     	Stops the generation of a square wave triggered by tone()
 *
 * @par	Syntax
 *	noTone(pin);
 * @param	pin		The device pin on which to stop generating the tone 
 * @return	void
 * @par     Example
 * @verbatim
   uint8_t ledPin = 36;
   uint8_t pulsePin = 13;
   unsigned long duration;

   void setup() {
     Serial.begin(115200);
     pinMode(pulsePin, INPUT_PULLUP);
     pinMode(ledPin, OUTPUT);
   }

   void loop() {
     duration = pulseIn(pulsePin, LOW);
     Serial.print("Pulse duration = ");
     Serial.print((float)duration/1000000);
     Serial.println(" sec");

     if(duration >= 15000000)
       noTone(ledPin);
     else if(duration >= 10000000)
       tone(ledPin, 494, 5000);
     else if(duration >= 5000000)
       tone(ledPin, 494);
   }
   @endverbatim
 */
void noTone(uint8_t pin);

/**@par	Description
 *     	Shifts out a byte of data one bit at a time. Starts from either the most 
 * 		(i.e. the leftmost) or least (rightmost) significant bit. 
 * 		Each bit is written in turn to a data pin, after which a clock pin is 
 * 		pulsed (taken high, then low) to indicate that the bit is available.
 *
 * @par	Syntax
 *	shiftOut(dataPin, clockPin, bitOrder, val);
 * @param	dataPin		the pin on which to output each bit
 * @param	clockPin	the pin to toggle once the dataPin has been set to the correct value
 * @param	bitOrder	which order to shift out the bits; either MSBFIRST or LSBFIRST
 * @param	val		the data to shift out
 *
 * @return	void
 */
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);

/**@par	Description
 *     	Shifts in a byte of data one bit at a time. Starts from either the most 
 * 		(i.e. the leftmost) or least (rightmost) significant bit. For each bit, 
 * 		the clock pin is pulled high, the next bit is read from the data line, 
 * 		and then the clock pin is taken low. 
 * 
 * @par	Syntax
 *	byte incoming = shiftIn(dataPin, clockPin, bitOrder);
 * @param	dataPin		the pin on which to output each bit
 * @param	cloackPin	the pin to toggle once the dataPin has been set to the correct value
 * @param	bitOrder	which order to shift out the bits; either MSBFIRST or LSBFIRST
 *
 * @return	The value read(Type: byte);
 */
uint32_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

/**@par	Description
 *     	Reads a pulse (either HIGH or LOW) on a pin. For example, if value is HIGH, 
 * 		pulseIn() waits for the pin to go from LOW to HIGH, starts timing, then waits 
 * 		for the pin to go LOW and stops timing. Returns the length of the pulse in 
 * 		microseconds or gives up and returns 0 if no complete pulse was received 
 * 		within the timeout.
 *
 * @par	Syntax
 *	pulseIn(pin, state);\n
 * 		pulseIn(pin, state, timeout);
 * @param	pin			the pin on which you want to read a pulse
 * @param	state			type of pulse to read: either HIGH or LOW
 * @param	timeout(optional)	the number of microseconds to wait for the pulse to start;
 * 					default is one second
 *
 * @return	The length of the pulse (in microseconds) or 0 if no pulse started before the timeout(Type: unsgined long)
 * @par     Example
 * @verbatim
   uint8_t ledPin = 36;
   uint8_t pulsePin = 13;
   unsigned long duration;

   void setup() {
     Serial.begin(115200);
     pinMode(pulsePin, INPUT_PULLUP);
     pinMode(ledPin, OUTPUT);
   }

   void loop() {
     duration = pulseIn(pulsePin, LOW);
     Serial.print("Pulse duration = ");
     Serial.print((float)duration/1000000);
     Serial.println(" sec");

     if(duration >= 15000000)
       noTone(ledPin);
     else if(duration >= 10000000)
       tone(ledPin, 494, 5000);
     else if(duration >= 5000000)
       tone(ledPin, 494);
   }
   @endverbatim
 */
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

/**@par	Description
 *     	pulseInLong() is an alternative to pulseIn() which is better at handling 
 * 		long pulse and interrupt affected scenarios
 *
 * @par	Syntax
 *	pulseInLong(pin, state);\n
 * 		pulseInLong(pin, state, timeout);
 * @param	pin			the pin on which you want to read a pulse
 * @param	state			type of pulse to read: either HIGH or LOW
 * @param	timeout(optional)	the number of microseconds to wait for the pulse to start;
 * 					default is one second
 *
 * @return	The length of the pulse (in microseconds) or 0 if no pulse started before the timeout(Type: unsigned long)
 */
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);
/** @} */

/**@addtogroup	Interrupts
 * @{
 */
/**@par	Description
 *      	Re-enables interrupts (after they’ve been disabled by noInterrupts()
 * @par	Syntax
 *	interrupts();
 * @return	void
 * @par     Example
 * @verbatim
   void setup() {
   }

   void loop() {
     noInterrupts();
     // critical, time-sensitive code here
     interrupts();
     // other code here
   }
   @endverbatim
 */
void interrupts(void);

/**@par	Description
 *     	Disables interrupts (you can re-enable them with interrupts())
 * @par	Syntax
 *	noInterrupts();
 * @return	void
 * @par     Example
 * @verbatim
   void setup() {
   }

   void loop() {
     noInterrupts();
     // critical, time-sensitive code here
     interrupts();
     // other code here
   }
   @endverbatim
 */
void noInterrupts(void);

/**@par	Description
 *     	Digital Pins With Interrupts
 * @par	Syntax
 *	attachInterrupt(pin, ISR, mode);
 * @see		https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
 * @param	pin		the number of the interrupt
 * @param	ISR			the ISR to call when the interrupt occurs; this function must take no parameters and return nothing. 
 * 					This function is sometimes referred to as an interrupt service routine
 * @param	mode			defines when the interrupt should be triggered(LOW,CHANGE,RISING,FALLING)
 *
 * @return	void
 * @par     Example
 * @verbatim
   uint8_t ledPin = 36;
   uint8_t interruptPin = 13;
   volatile byte state = LOW;
   long startTime = 0;
   
   void blink()
   {
       state = !state;
   }
   
   void setup()
   {
       pinMode(ledPin, OUTPUT);
       pinMode(interruptPin, INPUT_PULLUP);
       attachInterrupt(interruptPin, blink, CHANGE);
       startTime = millis();
   }
   
   void loop()
   {
       //After 20sec will disable ISR for pin13
       if(millis() - startTime >= 20*1000)
           detachInterrupt(13);
      
       digitalWrite(ledPin, state);
   }
   @endverbatim
 */
void attachInterrupt(uint32_t pin, void (*userFunc)(void), int mode);

/**@par	Description
 *     	Turns off the given interrupt
 * @par	Syntax
 *	detachInterrupt(pin);
 * @param	pin		the number of the interrupt to disable
 * @return	void
 * @par     Example
 * @verbatim
   uint8_t ledPin = 36;
   uint8_t interruptPin = 13;
   volatile byte state = LOW;
   long startTime = 0;
   
   void blink()
   {
       state = !state;
   }
   
   void setup()
   {
       pinMode(ledPin, OUTPUT);
       pinMode(interruptPin, INPUT_PULLUP);
       attachInterrupt(interruptPin, blink, CHANGE);
       startTime = millis();
   }
   
   void loop()
   {
       //After 20sec will disable ISR for pin13
       if(millis() - startTime >= 20*1000)
           detachInterrupt(13);
      
       digitalWrite(ledPin, state);
   }
   @endverbatim
 */
void detachInterrupt(uint32_t pin);

void yield(void);

/** @} */

#include "wiring.h"
#include "ACharacter.h"
#include "WString.h"
#include "app.h"
#include "RAKUnifiedApi.h"
#include "HardwareSerial.h"
#include "Wire.h"
#include "SPI.h"

/**@addtogroup	RUI_Arduino_Data_Type
 * @{
 */

typedef enum{
    RAK_ADC_RESOLUTION_8BIT = UDRV_ADC_RESOLUTION_8BIT,    ///< 8 bit resolution
    RAK_ADC_RESOLUTION_10BIT = UDRV_ADC_RESOLUTION_10BIT,  ///< 10 bit resolution
    RAK_ADC_RESOLUTION_12BIT = UDRV_ADC_RESOLUTION_12BIT,  ///< 12 bit resolution
    RAK_ADC_RESOLUTION_14BIT = UDRV_ADC_RESOLUTION_14BIT,  ///< 14 bit resolution
} RAK_ADC_RESOLUTION;

typedef enum{
    RAK_ADC_MODE_DEFAULT = UDRV_ADC_MODE_DEFAULT,  ///< default range which depends on platform
    RAK_ADC_MODE_3_0 = UDRV_ADC_MODE_3_0,          ///< maximum 3.0V
    RAK_ADC_MODE_2_4 = UDRV_ADC_MODE_2_4,          ///< maximum 2.4V
    RAK_ADC_MODE_1_8 = UDRV_ADC_MODE_1_8,          ///< maximum 1.8V
    RAK_ADC_MODE_1_2 = UDRV_ADC_MODE_1_2,          ///< maximum 1.2V
} RAK_ADC_MODE;

typedef enum{
    RAK_PWM_RESOLUTION_8BIT = UDRV_PWM_RESOLUTION_8BIT,    ///< 8 bit resolution
    RAK_PWM_RESOLUTION_10BIT = UDRV_PWM_RESOLUTION_10BIT,  ///< 10 bit resolution
    RAK_PWM_RESOLUTION_12BIT = UDRV_PWM_RESOLUTION_12BIT,  ///< 12 bit resolution
    RAK_PWM_RESOLUTION_14BIT = UDRV_PWM_RESOLUTION_14BIT,  ///< 14 bit resolution
} RAK_PWM_RESOLUTION;

/**@}*/

#endif
