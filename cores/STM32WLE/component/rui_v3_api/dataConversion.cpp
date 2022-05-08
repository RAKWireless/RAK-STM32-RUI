#include "dataConversion.h"

uint16_t makeWord(uint16_t w) {return w; }
uint16_t makeWord(unsigned char h, unsigned char l) {return (h << 8) | l; }
