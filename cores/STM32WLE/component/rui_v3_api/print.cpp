#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include "udrv_serial.h"
#include "board_basic.h"

#include "Print.h"
#include "Arduino.h"

using namespace std;

// ================= Public Methods ==================

/* default implementation: may be overridden */
size_t Print::write(const uint8_t *buffer, size_t size)
{
  // return (size_t)udrv_serial_write (DEFAULT_SERIAL_CONSOLE, buffer, size);
  size_t n = 0;
  while (size--) {
    if (write(*buffer++)) n++;
  }
  return n;
}

//print-F(string)
size_t Print::print(const __FlashStringHelper *ifsh)
{
  PGM_P p = reinterpret_cast<PGM_P>(ifsh);
  return print(p);
}

//print-const char *
size_t Print::print(const char *s)
{
  String str = s;
  return print(str);
}

//print-String
size_t Print::print(const String &s)
{
  return write((const uint8_t *)s.c_str(), s.length());
}

//print-const char
size_t Print::print(char str[])
{
  return write((const uint8_t *)str, strlen(str));
}

//print-unsigned char
size_t Print::print(unsigned char b, int base)
{
  return print((unsigned long) b, base);
}

//print-char
size_t Print::print(char c)
{
  char *buf = &c;
  return write((const uint8_t *)buf, 1);
}

//print-int
size_t Print::print(int n, int base)
{
  return print((long) n, base);
}

//print-unsigned int
size_t Print::print(unsigned int n, int base)
{
  return print((unsigned long) n, base);
}

//print-long
size_t Print::print(long n,int base)
{
  if (base == 0) {
    //return write((const uint8_t *)n), strlen((const uint8_t *)n);
  } else if (base == 10){
      if (n < 0) {
	int t = print("-");
	n = -n;
	return printNumber(n,10) + t;
      }
      return printNumber(n, 10);
  }  else {
       return printNumber(n, base );
  }
}

//print-double
size_t Print::print(double n,int digits)
{
  return printFloat(n, digits);
}

//print-unsigned long
size_t Print::print(unsigned long n, int base)
{
//  if (base == 0) return write(n);
  return printNumber(n, base);
}

//main println util 
size_t Print::println(void) 
{
  return print((const char *)"\r\n");
}

//println-F(string)
size_t Print::println(const __FlashStringHelper *ifsh)
{
  PGM_P p = reinterpret_cast<PGM_P>(ifsh);
  size_t n = print(p);
  n += println();
  return n;
}

//println-const char *
size_t Print::println(const char *s)
{
  size_t n = print(s);
  n += println();
  return n;
}

//println-String
size_t Print::println(const String &s)
{
  size_t n = print(s);
  n += println();
  return n;
}

//println-const char[]
size_t Print::println(char str[])
{
  size_t n = print(str);
  n += println();
  return n;
}

//println-char
size_t Print::println(char c)
{
  size_t n = print(c);
  n += println();
  return n;
}

//println-unsigned char
size_t Print::println(unsigned char b, int base)
{
  size_t n = print(b, base);
  n += println();
  return n;
}

//println-int
size_t Print::println(int num, int base)
{
  size_t n = print(num, base);
  n += println();
  return n;
}

//println-unsigned int
size_t Print::println(unsigned int num, int base)
{
  size_t n = print(num, base);
  n += println();
  return n;
}

//println-long 
size_t Print::println(long num, int base)
{
  size_t n = print(num, base);
  n += println();
  return n;
}

//println-unsigned long 
size_t Print::println(unsigned long num, int base)
{
  size_t n = print(num, base);
  n += println();
  return n;
}

//println-double
size_t Print::println(double num,int digits)
{
  size_t n = print(num, digits);
  n += println();
  return n;
}

//long long
void Print::println(int64_t n, uint8_t base)
{
  print(n, base);
  println();
}

void Print::print(int64_t n, uint8_t base)
{
  if (n < 0) {
    print("-");
    n = -n;
  }
  if (base < 2) {
    base = 2;
  }
  print((uint64_t)n, base);
}

void Print::println(uint64_t n, uint8_t base)
{
  print(n, base);
  println();
}

void Print::print(uint64_t n, uint8_t base)
{
  if (base < 2) {
    base = 2;
  }
  printNumber(n, base);
}

//printf
size_t Print::printf(const char *val, ...)
{
  char buf[256];
  int len;

  va_list ap;
  va_start(ap, val);

  len = vsnprintf(buf, 256, val, ap);
  this->write(buf, len);

  va_end(ap);
  return len;
}

// ================== Private Methods ==================

size_t Print::printNumber(uint64_t n, uint8_t base)
{
  char buf[8 * sizeof(long) + 1];
  char *str = &buf[sizeof(buf) - 1];
  *str = '\0';

  // prevent crash if called with base == 1
  if (base < 2) base = 10;

  do {
    char c = n % base;
    n /= base;

    *--str = c < 10 ? c + '0' : c + 'A' - 10;
  } while(n);

  return write((const uint8_t *)str, strlen(str));
}

size_t Print::printFloat(double number,int digits)
{
  size_t n = 0;

  //determin nan,inf,overflow
  if (isnan(number)) return print("nan"); //not a number
  if (isinf(number)) return print("inf"); //infinite
  if (number > 4294967040.0) return print ("ovf"); //overflow 
  if (number <-4294967040.0) return print ("ovf"); //overflow
 
  //handle negetive numbers
  if(number < 0.0)
  {
    n += print("-");
    number = -number;
  }

  //print the integer part of the number
  unsigned long intPart = (unsigned long)number;
  double remainder = number - (double)intPart;
  n += print(intPart);

  //print the decimal point, but only if there are digits beyond
  if (digits > 0)
  {
    n += print(".");	  
  }

  //print the digits one by one
  while (digits-- > 0)
  {
    remainder *= 10.0;
    unsigned int toPrint = (unsigned int)(remainder);
    n += print(toPrint);
    remainder -= toPrint;
  }

  return n;
}
