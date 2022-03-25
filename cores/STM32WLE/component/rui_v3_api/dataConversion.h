/**@file	dataConversion.h
 *
 * @brief	
 * @author	RAKwireless
 * @version	0.0.0
 * @date	2021.5
 */

#ifndef __DATA_CONVERSION_H__
#define __DATA_CONVERSION_H__

#include <stdio.h>
#include "ruiTop.h"

using namespace std;

/**@brief	This API is to add new type "word"	
 *
 * @note 	This is one overload function of makeWord()
 * @param	uint16_t
 * @return	uint16_t
 *
 */
uint16_t makeWord(uint16_t w);

/**@brief	This API is to add new type "word"	
 *
 * @note 	This is one overload function of makeWord()
 * @param	h
 * @param	l
 * @return	uint16_t
 *
 */
uint16_t makeWord(byte h, byte l);

#define word(...) makeWord(__VA_ARGS__)


#endif 
