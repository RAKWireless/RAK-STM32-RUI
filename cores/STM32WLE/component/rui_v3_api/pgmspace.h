/**@file	pgmspace.h
 *
 * @brief
 * @author	RAKwireless
 * @version	0.0.0
 * @date	2021.5
 */
#ifndef __PGMSPACE_H__
#define __PGMSPACE_H__

#define __ATTR_PROGMEM__ __attribute__((section(".progmem")))

#define PROGMEM __ATTR_PROGMEM__

#define PGM_P const char *

#define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];}))

class __FlashStringHelper;
#define F(string_literal) (reinterpret_cast<const __FlashStringHelper *>(PSTR(string_literal)))

#define FPSTR(pstr_pointer) (reinterpret_cast<const __FlashStringHelper *>(pstr_pointer))

#endif
