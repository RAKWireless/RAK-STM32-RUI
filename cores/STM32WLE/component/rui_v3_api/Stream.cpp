#include "Arduino.h"
#include "Stream.h"
#include "udrv_serial.h"

int Stream::timedRead()
{
  int c;
  startTime = millis();
  do {
    c = read();
    if (c >= 0)
        return c;
  } while(millis() - startTime < getTimeout());
  return -1;
}

size_t Stream::readBytes(char *buf,size_t length)
{
  size_t count = 0;
  while (count < length){
    int c = timedRead();
    if(c < 0) break;
    *buf++ = (char)c;
    count++;  
  }
  return count;
}

size_t Stream::readBytesUntil(char terminator, char *buf, size_t length)
{
  if (length < 1) return 0;
  size_t index = 0;
  while (index < length){
    int c = timedRead();
    if (c < 0 || c == terminator) break;
    *buf++ = (char)c;
    index++;
  } 
  return index;
}

String Stream::readString()
{
  String ret;
  int c = timedRead();
  while(c >= 0){
    ret += (char)c;
    c = timedRead();
  }
  return ret;
}

String Stream::readStringUntil(char terminator)
{
  String ret;
  int c = timedRead();
  while (c >=0 && c != terminator){
    ret += (char)c;
    c = timedRead();
  }
  return ret;
}

void Stream::setTimeout(unsigned long timeout)
{
  udrv_serial_set_timeout(timeout);
}

unsigned long Stream::getTimeout()
{
  return udrv_serial_get_timeout();
}

bool Stream::find(const char *target)
{
  return findUntil(target, strlen(target), NULL, 0);
}

bool Stream::find(const uint8_t *target)
{
  return find((const char *)target);
}

bool Stream::find(const char *target, size_t length)
{
  return findUntil(target, length, NULL, 0);
}

bool Stream::find(const uint8_t *target, size_t length)
{
  return find((const char *)target, length);
}

bool Stream::find(char target)
{
    return find(&target, 1);
}

bool Stream::findUntil(const char *target, const char *terminator)
{
  return findUntil(target, strlen(target), terminator, strlen(terminator));
}

bool Stream::findUntil(const uint8_t *target, const char *terminator)
{
  return findUntil((const char *)target, terminator);
}

bool Stream::findUntil(const char *target, size_t targetLen, const char *terminator, size_t termLen)
{
  if (terminator == NULL) {
    MultiTarget t[1] = {{target, targetLen, 0}};
    return findMulti(t, 1) == 0 ? true : false;
  } else {
    MultiTarget t[2] = {{target, targetLen, 0}, {terminator, termLen, 0}};
    return findMulti(t, 2) == 0 ? true : false;
  }  
}

bool Stream::findUntil(const uint8_t *target, size_t targetLen, const char *terminate, size_t termLen)
{
  return findUntil((const char *)target, targetLen, terminate, termLen);
}

int Stream::findMulti(struct Stream::MultiTarget *targets, int tCount)
{
  for (struct MultiTarget *t = targets; t < targets + tCount; ++t) {
    if (t->len <= 0) {
      return t - targets;
    }
  }

  while (1) {
    int c = timedRead();
    if (c < 0) {
      return -1;
    }

    for (struct MultiTarget *t = targets; t < targets + tCount; ++t) {
      if (c == t->str[t->index]) {
        if (++t->index == t->len) {
          return t - targets;
        } else {
          continue;
        }
      }

      if (t->index == 0) {
        continue;
      }

      int origIndex = t->index;
      do {
        --t->index;
        if (c != t->str[t->index]) {
          continue;
        }

        if (t->index == 0) {
          t->index++;
          break;
        }

        int diff = origIndex - t->index;
        size_t i;
        for (i = 0; i < t->index; ++i) {
          if (t->str[i] != t->str[i + diff]) {
            break;
          }
        }

        if (i == t->index) {
          t->index++;
          break;
        }

      } while (t->index);
    }
  }
  // unreachable
  return -1;
}
