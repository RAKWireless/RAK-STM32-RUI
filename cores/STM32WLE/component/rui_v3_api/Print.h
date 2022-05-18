#ifndef __PRINT_H__
#define __PRINT_H__

#include <inttypes.h>
#include <stdio.h>

#include "Printable.h"
#include "pgmspace.h"
#include "WString.h"

//define for convertion
#define DEC 10
#define HEX 16
#define OCT 8
#ifdef  BIN
#undef  BIN
#endif
#define BIN 2

using namespace std;

class Print 
{
  protected:
    void setWriteError(int err = 1)
    {
      write_error = err;
    }
  private:
    size_t printNumber(uint64_t, uint8_t);
    size_t printFloat(double, int);
    int write_error;
  public:
    Print() : write_error(0) {}

    int getWriteError()
    {
      return write_error;
    }
    void clearWriteError()
    {
      setWriteError(0);
    }

    virtual size_t write(uint8_t) = 0;
    virtual size_t write(const uint8_t *, size_t size);

    size_t write(const char *str)
    {
      if (str == NULL) {
        return 0;
      }
      return write((const uint8_t *)str, strlen(str));
    }
    size_t write(const char *buffer, size_t size)
    {
      return write((const uint8_t *)buffer, size);
    }
    size_t write(String str)
    {
        return write((const uint8_t *)str.c_str(), str.length());
    }

    //print
    size_t print(const __FlashStringHelper *);
    size_t print(const char *);
    size_t print(const String &);
    size_t print(char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);

    /**@par	Description
     *      	Prints data to the serial port as human-readable ASCII text. This command can take many forms. 
     * 		Numbers are printed using an ASCII character for each digit. Floats are similarly printed as ASCII digits, 
     * 		defaulting to two decimal places. Bytes are sent as a single character. Characters and strings are sent as is
     * @ingroup Serial
     * @par	Syntax
     *      	Serial.print(val);\n
     * 		Serial.print(val,format);
     * @param	val	 the value to print,Allow any data type
     * @return	returns the number of bytes written, though reading that number is optional(Type: size_t)
     * @par     Example
     * @verbatim
     void setup() {
       Serial.begin(9600); // open the serial port at 9600 bps:
     }
     
     void loop() {
       // print labels
       Serial.print("NO FORMAT");  // prints a label
       Serial.print("\t");         // prints a tab
     
       Serial.print("DEC");
       Serial.print("\t");
     
       Serial.print("HEX");
       Serial.print("\t");
     
       Serial.print("OCT");
       Serial.print("\t");
     
       Serial.print("BIN");
       Serial.println();        // carriage return after the last label
     
       for (int x = 0; x < 64; x++) { // only part of the ASCII chart, change to suit
         // print it out in many formats:
         Serial.print(x);       // print as an ASCII-encoded decimal - same as "DEC"
         Serial.print("\t\t");  // prints two tabs to accomodate the label lenght
     
         Serial.print(x, DEC);  // print as an ASCII-encoded decimal
         Serial.print("\t");    // prints a tab
     
         Serial.print(x, HEX);  // print as an ASCII-encoded hexadecimal
         Serial.print("\t");    // prints a tab
     
         Serial.print(x, OCT);  // print as an ASCII-encoded octal
         Serial.print("\t");    // prints a tab
     
         Serial.println(x, BIN);  // print as an ASCII-encoded binary
         // then adds the carriage return with "println"
         delay(200);            // delay 200 milliseconds
       }
       Serial.println();        // prints another carriage return
     } 
       @endverbatim
     */
    size_t print(long, int = DEC);
    size_t print(unsigned long,int = DEC);
    size_t print(double, int = 2);

    //println
    size_t println(const __FlashStringHelper *);
    size_t println(const char *);
    size_t println(const String &s);
    size_t println(char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC);
    /**@par	Description
     *      	Prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') 
     *		 and a newline character (ASCII 10, or '\n'). This command takes the same forms as Serial.print().
     * @ingroup Serial
     * @par	Syntax
     *      	Serial.println(val);\n
     * 		Serial.println(val,format);
     * @param	val	 the value to print,Allow any data type
     * @return	returns the number of bytes written, though reading that number is optional(Type: size_t)
     * @par     Example
     * @verbatim
     int analogValue = 0;    // variable to hold the analog value
     
     void setup() {
       // open the serial port at 9600 bps:
       Serial.begin(9600);
     }
     
     void loop() {
       // read the analog input on pin 0:
       analogValue = analogRead(0);
     
       // print it out in many formats:
       Serial.println(analogValue);       // print as an ASCII-encoded decimal
       Serial.println(analogValue, DEC);  // print as an ASCII-encoded decimal
       Serial.println(analogValue, HEX);  // print as an ASCII-encoded hexadecimal
       Serial.println(analogValue, OCT);  // print as an ASCII-encoded octal
       Serial.println(analogValue, BIN);  // print as an ASCII-encoded binary
     
       // delay 10 milliseconds before the next reading:
       delay(10);
     }
       @endverbatim
     */
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2);
    size_t println(void);

    //long long
    void println(int64_t, uint8_t = DEC);
    void print(int64_t, uint8_t = DEC);
    void println(uint64_t, uint8_t = DEC);
    void print(uint64_t, uint8_t = DEC);
    
    /**@par	Description
     *   	 to output formated text over Serial without the need to create a char array first, fill it with snprintf() and then send it with Serial.println
     * @ingroup	Serial
     * @par	Syntax
     *      	Serial.printf(val)
     *
     * @param	val
     * @return	returns the number of bytes written, though reading that number is optional(Type: size_t)
     * @par	Example
     * @verbatim
       
       int exampleNum = 123;
       
       void setup()
       {
         Serial.begin(115200);
       }
       
       void loop()
       {
         Serial.printf("The example number = %d\r\n", exampleNum);
       }
     
       @endverbatim
     */
    size_t printf(const char *val, ...);

};

#endif
