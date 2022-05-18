/**@file	Stream.h
 *
 * @brief 	Stream is the base class for character and binary based streams. 
 * 		It is not called directly, but invoked whenever you use a function 
 * 		that relies on it.
 *
 * @author	RAKwireless
 * @version	0.0.0	
 * @date	2021.5
 */
#ifndef __STREAM_H__
#define __STREAM_H__

#include "WString.h"

#include "Print.h"

using namespace std;
class Stream : public Print
{ 
  protected:
    unsigned long timeOut;
    unsigned long startTime;

    int timedRead();
    
    struct MultiTarget {
      const char *str;
      size_t len;
      size_t index;
    };

    int findMulti(struct MultiTarget *targets, int tCount);
  public:
    virtual void flush() = 0;
    virtual int peek() = 0;
    /**@note	See detail in HardwareSerial.h
     */
    virtual int available() = 0;

    /**@note	See detail in HardwareSerial.h
     */
    virtual int read() = 0;

  /**@par	Description
   *      	This API is used to set the timeout value for read/write/flush API.
   * @ingroup	Serial
   * @par	Syntax
   *      	Serial.setTimeout(timeout);
   * @param	timeout   the timeout value
   * @return	void	
   * @par     Example
   * @verbatim
     void setup() {
       Serial.begin(115200);

       //Set Timeout to 5000
       Serial.setTimeout(5000);
       Serial.print("Time out = ");
       Serial.println(Serial.getTimeout());
     }

     void loop() {
     }
     @endverbatim
   */
  void setTimeout(unsigned long timeout);


  /**@par	Description
   *      	This API is used to get the timeout value for read/write/flush API.
   * @ingroup	Serial
   * @par	Syntax
   *      	Serial.getTimeout();
   * @return	The value of timeout(Type: unsigned long)
   * @par     Example
   * @verbatim
     void setup() {
       Serial.begin(115200);

       //Set Timeout to 5000
       Serial.setTimeout(5000);
       Serial.print("Time out = ");
       Serial.println(Serial.getTimeout());
     }

     void loop() {
     }
     @endverbatim
   */
  unsigned long getTimeout(void);
 
  /**@par	Description
   *      	Read characters from Stream into buffer
   * 		terminates if length characters have been read, or timeout (see setTimeout)
   * @note	Serial.readBytes() inherits from the Stream utility class
   * @ingroup	Serial
   * @par	Syntax
   *      	Serial.readBytes(buffer, length);
   *
   * @param	buffer		The buffer to store the bytes in
   * @param	length		The number of bytes to read
   *
   * @return	The number of bytes placed in the buffer(Type: size_t)
   * @par     Example
   * @verbatim
     void setup() {
       Serial.begin(11500, RAK_CUSTOM_MODE);
     }

     void loop() {
       int returnBytes = 0;
       char readBuf[256];

       if (Serial.available > 0) {

         //Read 5 characters in 1 second
         returnBytes = Serial.readBytes(readBuf, 5);

         if (returnBytes == 0)
           Serial.print("read nothing");
         else {
           Serial.print("read: ");
           for (int i=0; i<returnBytes; i++) {
             Serial.print(readBuf[i]);
           }
         }

         Serial.println("");
       }
     }
     @endverbatim
   */ 
  size_t readBytes( char *buffer, size_t length);
  size_t readBytes( uint8_t *buffer, size_t length) { return readBytes((char *)buffer, length); }

  /**@par	Description
   *      	As readBytes with terminator character
   * 		Terminates if length characters have been read, timeout, 
   * 		or if the terminator character  detected
   * @note	Serial.readBytesUntil() inherits from the Stream utility class
   * @ingroup	Serial
   * @par	Syntax
   *      	Serial.readBytesUntil(terminator, buffer, length);
   *
   * @param	terminator	The character to search for
   * @param	buffer		The buffer to store the bytes in
   * @param	length		The number of bytes to read
   *
   * @return	size_t	
   * @par     Example
   * @verbatim
     void setup() {
       Serial.begin(11500, RAK_CUSTOM_MODE);
     }

     void loop() {
       int returnBytes = 0;
       char readBuf[256];

       if (Serial.available > 0) {

         //Read 5 characters in 1 second,or Press ENTER to end reading
         returnBytes = Serial.readBytesUntil('\r', readBuf, 5);

         if (returnBytes == 0)
           Serial.print("read nothing");
         else {
           Serial.print("read: ");
           for (int i=0; i<returnBytes; i++) {
             Serial.print(readBuf[i]);
           }
         }

         Serial.println("");
       }
     }
     @endverbatim
   */
  size_t readBytesUntil( char terminator, char *buffer, size_t length); 
  size_t readBytesUntil( char terminator, uint8_t *buffer, size_t length) { return readBytesUntil(terminator, (char *)buffer, length); }

  /**@par	Description
   *      	Reads characters from a Stream into a String
   * 		The function terminates if it times out (see setTimeout()).
   * @note	Serial.readString() inherits from the Stream utility class\
   * @ingroup	Serial
   * @par	Syntax
   *      	Serial.readString()
   *
   * @return	A String read from a Stream(Type: String)
   * @par     Example
   * @verbatim
     void setup() {
       Serial.begin(115200, RAK_CUSTOM_MODE);
     }

     void loop() {
       String returnString = "";

       if (Serial.available() > 0) {

         //Read 5 characters in 1 second
         returnString = Serial.readString();

         if (returnString == "")
           Serial.print("read nothing");
         else {
           Serial.print("read: ");
           Serial.println(returnString);
         }

         Serial.println("");
       }
     }
     @endverbatim
   */
  String readString();

  /**@par	Description
   *      	readStringUntil() reads characters from the serial buffer into a String. The function terminates if it times out (see setTimeout())
   * @note	Serial.readStringUntil() inherits from the Stream utility class
   * @ingroup	Serial
   * @par	Syntax
   *      	Serial.readStringUntil(terminator);
   * @return	The entire String read from the serial buffer, up to the terminator character(Type: String)
   * @par     Example
   * @verbatim
     void setup() {
       Serial.begin(115200, RAK_CUSTOM_MODE);
     }

     void loop() {
       String returnString = "";

       if (Serial.available > 0) {

         //Read 5 characters in 1 second,or Press ENTER to end reading
         returnString = Serial.readStringUntil('\r');

         if (returnString == "")
           Serial.print("read nothing");
         else {
           Serial.print("read: ");
           Serial.println(returnString);
         }

         Serial.println("");
       }
     }
     @endverbatim

   */
  String readStringUntil(char terminator);

  bool find(const char *target);
  bool find(const uint8_t *target);
  bool find(const char *target, size_t length);
  bool find(const uint8_t *target, size_t length);
  bool find(char target);
  
  bool findUntil(const char *target, const char *terminator);
  bool findUntil(const uint8_t *target, const char *terminator);
  bool findUntil(const char *target, size_t targetLen, const char *terminate, size_t termLen);
  bool findUntil(const uint8_t *target, size_t targetLen, const char *terminate, size_t termLen);
};

#endif
