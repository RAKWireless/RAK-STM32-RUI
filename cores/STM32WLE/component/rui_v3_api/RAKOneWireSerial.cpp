#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <inttypes.h>

#include "RAKOneWireSerial.h"
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "service_nvm.h"
#include "service_mode_cli.h"
#include "service_mode_transparent.h"
#include "service_mode_proto.h"
#include "pin_define.h"
#include "board_basic.h"

using namespace std;

RAKOneWireSerial::RAKOneWireSerial(uint32_t pin, rak_onewire_serial_recv_cb callback)
{
  RAKOneWireSerial::pin = pin;

  udrv_serial_register_onewire_handler((SERIAL_CLI_HANDLER)callback);
}

void RAKOneWireSerial::begin(uint32_t baud, uint8_t config, RAK_SERIAL_MODE mode)
{
  SERVICE_MODE_TYPE old_mode, new_mode;

  if (pin == 0xFF) {
    return;
  }

  if (pin == UART0_RXD_PIN)
  {
    udrv_serial_init(SERIAL_UART0, baud, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_ONE_WIRE_RX_PIN_MODE);
    udrv_serial_enable (SERIAL_UART0);
    serialPort = SERIAL_UART0;
  }
  else if (pin == UART0_TXD_PIN)
  {
    udrv_serial_init(SERIAL_UART0, baud, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_ONE_WIRE_TX_PIN_MODE);
    udrv_serial_enable (SERIAL_UART0);
    serialPort = SERIAL_UART0;
  }
  else if (pin == UART1_RXD_PIN)
  {
    udrv_serial_init(SERIAL_UART1, baud, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_ONE_WIRE_RX_PIN_MODE);
    udrv_serial_enable (SERIAL_UART1);
    serialPort = SERIAL_UART1;
  }
  else if (pin == UART1_TXD_PIN)
  {
    udrv_serial_init(SERIAL_UART1, baud, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_ONE_WIRE_TX_PIN_MODE);
    udrv_serial_enable (SERIAL_UART1);
    serialPort = SERIAL_UART1;
  }
  else if (pin == UART2_RXD_PIN)
  {
    udrv_serial_init(SERIAL_UART2, baud, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_ONE_WIRE_RX_PIN_MODE);
    udrv_serial_enable (SERIAL_UART2);
    serialPort = SERIAL_UART2;
  }
  else if (pin == UART2_TXD_PIN)
  {
    udrv_serial_init(SERIAL_UART2, baud, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_ONE_WIRE_TX_PIN_MODE);
    udrv_serial_enable (SERIAL_UART2);
    serialPort = SERIAL_UART2;
  }

  switch (mode) {
     case RAK_AT_MODE:
     {
        new_mode = SERVICE_MODE_TYPE_CLI;
        break;
     }
#ifdef SUPPORT_BINARY
     case RAK_API_MODE:
     {
        new_mode = SERVICE_MODE_TYPE_PROTOCOL;
        break;
     }
#endif
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
     case RAK_PASS_MODE:
     {
        new_mode = SERVICE_MODE_TYPE_TRANSPARENT;
        break;
     }
#endif
#endif
     case RAK_CUSTOM_MODE:
     {
        new_mode = SERVICE_MODE_TYPE_CUSTOM;
        break;
     }
     case RAK_DEFAULT_MODE:
     {
        switch (serialPort) {
            case SERIAL_UART0:
            {
                new_mode = DEFAULT_SERIAL_UART0_MODE;
                break;
            }
            case SERIAL_UART1:
            {
                new_mode = DEFAULT_SERIAL_UART1_MODE;
                break;
            }
            case SERIAL_UART2:
            {
                new_mode = DEFAULT_SERIAL_UART2_MODE;
                break;
            }
#ifdef SUPPORT_USB
            case SERIAL_USB0:
            {
                new_mode = DEFAULT_SERIAL_USB0_MODE;
                break;
            }
#endif
#ifdef SUPPORT_BLE
            case SERIAL_BLE0:
            {
                new_mode = DEFAULT_SERIAL_BLE0_MODE;
                break;
            }
#endif
#ifdef SUPPORT_NFC
            case SERIAL_NFC:
            {
                new_mode = DEFAULT_SERIAL_NFC_MODE;
                break;
            }
#endif
            default:
            {
                /* impossible to be here */
                return;
            }
        }
        break;
     }
     default:
     {
        /* impossible to be here */
        return;
     }
  }

  if ((old_mode = service_nvm_get_mode_type_from_nvm(serialPort)) != new_mode)
  {
     switch (new_mode) {
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
        case SERVICE_MODE_TYPE_TRANSPARENT:
        {
           if (service_lora_get_njs() == false) {
              return;
           }
           break;
        }
#endif
#endif
        default:
        {
           break;
        }
     }

     if (service_nvm_set_mode_type_to_nvm(serialPort, new_mode) != UDRV_RETURN_OK)
     {
         return;
     }

     switch (new_mode) {
        case SERVICE_MODE_TYPE_CLI:
        {
           switch (old_mode)
           {
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
              case SERVICE_MODE_TYPE_TRANSPARENT:
              {
                  service_mode_transparent_deinit(serialPort);
                  break;
              }
#endif
#endif
#ifdef SUPPORT_BINARY
              case SERVICE_MODE_TYPE_PROTOCOL:
              {
                  service_mode_proto_deinit(serialPort);
                  break;
              }
#endif
              default:
              {
                  break;
              }
           }
           service_mode_cli_init(serialPort);
           break;
        }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
        case SERVICE_MODE_TYPE_TRANSPARENT:
        {
           switch (old_mode)
           {
              case SERVICE_MODE_TYPE_CLI:
              {
                 service_mode_cli_deinit(serialPort);
                 break;
              }
#ifdef SUPPORT_BINARY
              case SERVICE_MODE_TYPE_PROTOCOL:
              {
                 service_mode_proto_deinit(serialPort);
                 break;
              }
#endif
              default:
              {
                 break;
              }
           }
           service_mode_transparent_init(serialPort);
           break;
        }
#endif
#endif
#ifdef SUPPORT_BINARY
        case SERVICE_MODE_TYPE_PROTOCOL:
        {
           switch (old_mode)
           {
              case SERVICE_MODE_TYPE_CLI:
              {
                 service_mode_cli_deinit(serialPort);
                 break;
              }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
              case SERVICE_MODE_TYPE_TRANSPARENT:
              {
                 service_mode_transparent_deinit(serialPort);
                 break;
              }
#endif
#endif
              default:
              {
                 break;
              }
           }
           service_mode_proto_init(serialPort);
           break;
        }
#endif
        default:
        {
           //impossible to be here
           break;
        }
     }
  }
}

void RAKOneWireSerial::end()
{
  udrv_serial_disable (serialPort);
}

size_t RAKOneWireSerial::write(const uint8_t *c, size_t size)
{
  return (size_t)udrv_serial_write (serialPort, c, size);
}

int RAKOneWireSerial::available()
{
  return (udrv_serial_read_available(serialPort));
}

int RAKOneWireSerial::read()
{
  uint8_t buf[1];
  if(udrv_serial_read (serialPort, buf, 1) == 0)
    return -1;
  else
    return buf[0];
}

