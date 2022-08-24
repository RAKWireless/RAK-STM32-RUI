#ifdef RAK5010_EVB

#ifndef _ATCMD_CELLULAR_H_
#define _ATCMD_CELLULAR_H_
#include "atcmd.h"

#define ATCELL_BUFFER_SIZE (1500)

int At_Cellular (SERIAL_PORT port, char *cmd, stParam *param);

#endif //_ATCMD_CELLULAR_H_

#endif //RAK5010_EVB
