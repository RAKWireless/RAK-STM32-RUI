#include <stddef.h>
#include "udrv_dfu.h"
#include "uhal_dfu.h"

void udrv_enter_dfu (void)
{ 
    return uhal_enter_dfu();
}

