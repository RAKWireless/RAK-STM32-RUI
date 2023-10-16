#ifndef _UHAL_TRNG_H_
#define _UHAL_TRNG_H_

#include <stdint.h>

void uhal_trng_init(void);
void uhal_trng_get_values(uint8_t *output, uint32_t length);

#endif
