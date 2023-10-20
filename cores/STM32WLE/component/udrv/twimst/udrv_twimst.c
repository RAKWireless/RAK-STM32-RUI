#include "udrv_twimst.h"
#include "udrv_errno.h"
#include "uhal_twimst.h"

static struct udrv_twimst_api *twimst_api[UDRV_TWIMST_MAX];
struct udrv_twimst_api twimst_driver =
{
  uhal_twimst_init,
  uhal_twimst_deinit,
  uhal_twimst_setup_freq,
  uhal_twimst_write,
  uhal_twimst_read,
  uhal_twimst_suspend,
  uhal_twimst_resume,
};

void udrv_twimst_init (udrv_twimst_port port) {
    if(port < UDRV_TWIMST_MAX) {
        if(twimst_api[port]) {
            twimst_api[port]->TWIMST_DEINIT(port);
	}
	twimst_api[port] = &twimst_driver;

	twimst_api[port]->TWIMST_INIT(port);
    }
    return;
}

void udrv_twimst_deinit (udrv_twimst_port port) {
    if(port < UDRV_TWIMST_MAX) {
	if(twimst_api[port]) {
            twimst_api[port]->TWIMST_DEINIT(port);
	    twimst_api[port] = NULL;
	}
    }
}

void udrv_twimst_setup_freq (udrv_twimst_port port, uint32_t clk_Hz) {
    if(port < UDRV_TWIMST_MAX) {
        if(!twimst_api[port]) {
            twimst_api[port] = &twimst_driver;
	}
	twimst_api[port]->TWIMST_SETUP_FREQ(port, clk_Hz);
    }
    return;
}

int32_t udrv_twimst_write (udrv_twimst_port port, uint8_t address, uint8_t *data, uint16_t length, bool send_stop) {
    if(port < UDRV_TWIMST_MAX) {
        if(twimst_api[port]) 
	    return twimst_api[port]->TWIMST_WRITE(port, address, data, length, send_stop);
        else
	    return -UDRV_NOT_INIT;
    } else {
        return -UDRV_WRONG_ARG;
    }   
}

int32_t udrv_twimst_read (udrv_twimst_port port, uint8_t address, uint8_t *data, uint16_t length) {
    if(port < UDRV_TWIMST_MAX) {
        if(twimst_api[port])
	    return twimst_api[port]->TWIMST_READ(port, address, data, length);
	else
	    return -UDRV_NOT_INIT;
    } else {
        return -UDRV_WRONG_ARG;
    }
}

void udrv_twimst_suspend (void) {
    twimst_driver.TWIMST_SUSPEND();
    return;
}

void udrv_twimst_resume (void) {
    twimst_driver.TWIMST_RESUME();
    return;
}
