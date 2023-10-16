#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "uhal_trng.h"
#include "udrv_trng.h"

void udrv_trng_init(void)
{
    uhal_trng_init();
}

void udrv_trng_get_values(uint8_t *output, uint32_t length)
{
    uhal_trng_get_values(output, length);
}