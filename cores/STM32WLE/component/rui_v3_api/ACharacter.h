/**@file	ACharacter.h
 *
 * @par	Description
 *     	Provide functions of characters what Arduino use
 * @author	Rakwireless
 * @version	0.0.0
 * @date	2021.5
 */
#ifndef __A_CHARACTER_H__
#define __A_CHARACTER_H__

#include <ctype.h>

/**@addtogroup	Characters
 * @{
 */

/**@par	Description
 *     	Analyse if a char is alphanumeric (that is a letter or a numbers). Returns true if thisChar contains either a number or a letter
 * @par	Syntax
 *     	isAlphaNumeric(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is alphanumeric
 * @retval	FALSE : The character is not alphanumeric
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isAlphaNumeric(myChar)) { // tests if myChar isa letter or a number
       Serial.println("The character is alphanumeric");
     }
     else {
       Serial.println("The character is not alphanumeric");
     }
   }

   void loop() {
   }
   @endverbatim
 */
inline boolean isAlphaNumeric(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is alpha (that is a letter). Returns true if thisChar contains a letter
 * @par	Syntax
 *     	isAlpha(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is a letter
 * @retval	FALSE : The character is not a letter
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isAlpha(myChar)) {  // tests if myChar is a letter
       Serial.println("The character is a letter");
     }
     else {
       Serial.println("The character is not a letter");
     }
   }

   void loop() {
   }
   @endverbatim
 */
inline boolean isAlpha(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is Ascii. Returns true if thisChar contains an Ascii character
 * @par	Syntax
 *     	isAscii(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is Ascii
 * @retval	FALSE : The character is not Ascii
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isAscii(myChar)) {  // tests if myChar is an Ascii character
       Serial.println("The character is Ascii");
     }
     else {
       Serial.println("The character is not Ascii");
     }
   }

   void loop() {
   }
   @endverbatim

 */
inline boolean isAscii(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is a space character. Returns true if the argument is a space or horizontal tab ('\t')
 * @par	Syntax
 *     	isWhitespace(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is a space or tab
 * @retval	FALSE : The character is not a space or tab
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isWhitespace(myChar)) { // tests if myChar is a space character
       Serial.println("The character is a space or tab");
     }
     else {
       Serial.println("The character is not a space or tab");
     }
   }

   void loop() {
   }
   @endverbatim
 */
inline boolean isWhitespace(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is a control character. Returns true if thisChar is a control character
 * @par	Syntax
 *     	isControl(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is a control character
 * @retval	FALSE : The character is not a control character
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isControl(myChar)) {  // tests if myChar is a control character
       Serial.println("The character is a control character");
     }
     else {
       Serial.println("The character is not a control character");
     }
   }

   void loop() {
   }
   @endverbatim
 */
inline boolean isControl(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is a digit (that is a number). Returns true if thisChar is a number
 * @par	Syntax
 *     	isDigit(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is a number
 * @retval	FALSE : The character is not a number
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isDigit(myChar)) {  // tests if myChar is a digit
       Serial.println("The character is a number");
     }
     else {
       Serial.println("The character is not a number");
     }
   }  

   void loop() {
   }
   @endverbatim
 */
inline boolean isDigit(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is printable with some content (space is printable but has no content). Returns true if thisChar is printable
 * @par	Syntax
 *     	isGraph(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is printable
 * @retval	FALSE : The character is not printable
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isGraph(myChar)) {  // tests if myChar is a printable character but not a blank space.
       Serial.println("The character is printable");
     }
     else {
       Serial.println("The character is not printable");
     }
   }

   void loop() {
   }
   @endverbatim
 */
inline boolean isGraph(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is lower case (that is a letter in lower case). Returns true if thisChar contains a letter in lower case
 * @par	Syntax
 *     	isLowerCase(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is lower case
 * @retval	FALSE : The character is not lower case
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isLowerCase(myChar)) {  // tests if myChar is a lower case letter
       Serial.println("The character is lower case");
     }
     else {
       Serial.println("The character is not lower case");
     }
   }

   void loop() {
   }
   @endverbatim
 */
inline boolean isLowerCase(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is printable (that is any character that produces an output, even a blank space). Returns true if thisChar is printable
 * @par	Syntax
 *     	isPrintAble(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is printable
 * @retval	FALSE : The character is not printable
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isPrintable(myChar)) {  // tests if myChar is printable char
       Serial.println("The character is printable");
     }
     else {
       Serial.println("The character is not printable");
     }
   }

   void loop() {
   }
   @endverbatim
 */
inline boolean isPrintable(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is punctuation (that is a comma, a semicolon, an exclamation mark and so on). Returns true if thisChar is punctuation
 * @par	Syntax
 *     	isPunct(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is a punctuation
 * @retval	FALSE : The character is not a punctuation
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isPunct(myChar)) {  // tests if myChar is a punctuation character
       Serial.println("The character is a punctuation");
     }
     else {
       Serial.println("The character is not a punctuation");
     }
   }  

   void loop() {
   }
   @endverbatim
 */
inline boolean isPunct(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is a white-space character. Returns true if the argument is a space, form feed ('\f'), newline ('\n'), 
 * 		carriage return ('\r'), horizontal tab ('\t'), or vertical tab ('\v')
 * @par	Syntax
 *     	isSpace(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is white-space
 * @retval	FALSE : The character is not white-space
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isSpace(myChar)) {  // tests if myChar is a white-space character
       Serial.println("The character is white-space");
     }
     else {
       Serial.println("The character is not white-space");
     }
   }
     
   void loop() {
   }
   @endverbatim
 */
inline boolean isSpace(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is upper case (that is, a letter in upper case). Returns true if thisChar is upper case
 * @par	Syntax
 *     	isUpperCase(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is upper case
 * @retval	FALSE : The character is not upper case
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isUpperCase(myChar)) {  // tests if myChar is an upper case letter
       Serial.println("The character is upper case");
     }
     else {
       Serial.println("The character is not upper case");
     }
   }

   void loop() {
   }
   @endverbatim
 */
inline boolean isUpperCase(int thisChar) __attribute__((always_inline));

/**@par	Description
 *     	Analyse if a char is an hexadecimal digit (A-F, 0-9). Returns true if thisChar contains an hexadecimal digit
 * @par	Syntax
 *     	isHexadecimalDigit(thisChar);
 * @param	thisChar	variable(Type: char)
 * @return	bool
 * @retval	TRUE  : The character is an hexadecimal digit
 * @retval	FALSE : The character is not an hexadecimal digit
 * @par     Example
 * @verbatim
   char mychar = 'A';

   void setup() {
     Serial.begin(115200);

     if (isHexadecimalDigit(myChar)) { // tests if myChar is an hexadecimal digit
       Serial.println("The character is an hexadecimal digit");
     }
     else {
       Serial.println("The character is not an hexadecimal digit");
     }
   }   

   void loop() {
   }
   @endverbatim
 */
inline boolean isHexadecimalDigit(int thisChar) __attribute__((always_inline));
/** @} */

inline int toAscii(int thisChar) __attribute__((always_inline));
inline int toLowerCase(int thisChar) __attribute__((always_inline));
inline int toUpperCase(int thisChar)__attribute__((always_inline));


// Checks for an alphanumeric character. 
// It is equivalent to (isalpha(c) || isdigit(c)).
inline boolean isAlphaNumeric(int c)  {
  return ( isalnum(c) == 0 ? false : true); }


// Checks for an alphabetic character. 
// It is equivalent to (isupper(c) || islower(c)).
inline boolean isAlpha(int c) {
  return ( isalpha(c) == 0 ? false : true); }


// Checks whether c is a 7-bit unsigned char value 
// that fits into the ASCII character set.
inline boolean isAscii(int c) {
  return ( isascii (c) == 0 ? false : true); }


// Checks for a blank character, that is, a space or a tab.
inline boolean isWhitespace(int c) {
  return ( isblank (c) == 0 ? false : true); }


// Checks for a control character.
inline boolean isControl(int c) {
  return ( iscntrl (c) == 0 ? false : true); }


// Checks for a digit (0 through 9).
inline boolean isDigit(int c) {
  return ( isdigit (c) == 0 ? false : true); }


// Checks for any printable character except space.
inline boolean isGraph(int c) {
  return ( isgraph (c) == 0 ? false : true); }


// Checks for a lower-case character.
inline boolean isLowerCase(int c) {
  return (islower (c) == 0 ? false : true); }


// Checks for any printable character including space.
inline boolean isPrintable(int c) {
  return ( isprint (c) == 0 ? false : true); }


// Checks for any printable character which is not a space 
// or an alphanumeric character.
inline boolean isPunct(int c) {
  return ( ispunct (c) == 0 ? false : true); }


// Checks for white-space characters. For the avr-libc library, 
// these are: space, formfeed ('\f'), newline ('\n'), carriage 
// return ('\r'), horizontal tab ('\t'), and vertical tab ('\v').
inline boolean isSpace(int c) {
  return ( isspace (c) == 0 ? false : true); }


// Checks for an uppercase letter.
inline boolean isUpperCase(int c) {
  return ( isupper (c) == 0 ? false : true); }


// Checks for a hexadecimal digits, i.e. one of 0 1 2 3 4 5 6 7 
// 8 9 a b c d e f A B C D E F.
inline boolean isHexadecimalDigit(int c) {
  return ( isxdigit (c) == 0 ? false : true); }


// Converts c to a 7-bit unsigned char value that fits into the 
inline int toAscii(int c) {
  return toascii (c); }

// Converts the letter c to lower case, if possible.
inline int toLowerCase(int c)
{
  return tolower (c);
}


// Converts the letter c to upper case, if possible.
inline int toUpperCase(int c) {
  return toupper (c); }

#endif //end ACharacter.h

