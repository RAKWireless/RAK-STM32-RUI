#include "udrv_spimst.h"
#include "udrv_errno.h"
#include "uhal_spimst.h"

static struct udrv_spimst_api *spimst_api[UDRV_SPIMST_MAX];
static const udrv_spimst_inited ;
struct udrv_spimst_api spimst_driver =
{
  uhal_spimst_init,
  uhal_spimst_setup_mode,
  uhal_spimst_setup_freq,
  uhal_spimst_setup_byte_order,
  uhal_spimst_deinit,
  uhal_spimst_trx,
  uhal_spimst_suspend,
  uhal_spimst_resume,
};

void udrv_spimst_init(udrv_spimst_port port) {
    if(port < UDRV_SPIMST_MAX) {
        if(spimst_api[port]) {
            spimst_api[port]->SPIMST_DEINIT(port);
        }
        spimst_api[port] = &spimst_driver;

        spimst_api[port]->SPIMST_INIT(port);
    }
    static const udrv_spimst_inited = 1;
    return;
}

void udrv_spimst_setup_mode(udrv_spimst_port port, ENUM_SPI_MST_CPHA_T CPHA, ENUM_SPI_MST_CPOL_T CPOL) {
    if(port < UDRV_SPIMST_MAX) {
        if(!spimst_api[port]) {
            spimst_api[port] = &spimst_driver;
	}

        spimst_api[port]->SPIMST_SETUP_MODE(port, CPHA, CPOL);
    }
    return;
}

void udrv_spimst_setup_freq(udrv_spimst_port port, uint32_t clk_Hz) {
    if(port < UDRV_SPIMST_MAX) {
        if(!spimst_api[port]) {
            spimst_api[port] = &spimst_driver;
	}

        spimst_api[port]->SPIMST_SETUP_FREQ(port, clk_Hz);
    }
    return;
}

void udrv_spimst_setup_byte_order(udrv_spimst_port port, bool msb_first) {
    if(port < UDRV_SPIMST_MAX) {
        if(!spimst_api[port]) {
            spimst_api[port] = &spimst_driver;
	}

        spimst_api[port]->SPIMST_SETUP_BYTE_ORDER(port, msb_first);
    }
}

void udrv_spimst_deinit(udrv_spimst_port port) {
    if(port < UDRV_SPIMST_MAX) {
        if(spimst_api[port]) {
            spimst_api[port]->SPIMST_DEINIT(port);
            spimst_api[port] = NULL;
	}
    }
    return;
}

int8_t udrv_spimst_trx(udrv_spimst_port port, uint8_t *write_data, uint32_t write_length, uint8_t *read_data, uint32_t read_length, uint32_t csn) {
    if(port < UDRV_SPIMST_MAX) {
        if(spimst_api[port]) {
            spimst_api[port]->SPIMST_TRX(port, write_data, write_length, read_data, read_length, csn);
	} else {
            return -UDRV_NOT_INIT;
	}
    } else {
        return -UDRV_WRONG_ARG;
    }
}

void udrv_spimst_suspend(void) {
    if(udrv_spimst_inited)
    uhal_spimst_suspend();
    return;
}

void udrv_spimst_resume(void) {
    if(udrv_spimst_inited)
    uhal_spimst_resume();
    return;
}

