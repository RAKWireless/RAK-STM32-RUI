#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <inttypes.h>

#include "HardwareSerial.h"
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "service_nvm.h"
#include "service_mode_cli.h"
#include "service_mode_transparent.h"
#include "service_mode_proto.h"
#include "board_basic.h"

using namespace std;

HardwareSerial::HardwareSerial(SERIAL_PORT port)
{
  HardwareSerial::serialPort = port;
}

HardwareSerial Serial(DEFAULT_SERIAL_CONSOLE);
HardwareSerial Serial0(SERIAL_UART0);
HardwareSerial Serial1(SERIAL_UART1);
HardwareSerial Serial2(SERIAL_UART2);
#ifdef SUPPORT_USB
HardwareSerial Serial3(SERIAL_USB0);
#endif
#ifdef SUPPORT_BLE
HardwareSerial Serial6(SERIAL_BLE0);
#endif

void HardwareSerial::begin(uint32_t baud, uint8_t config, RAK_SERIAL_MODE mode)
{
  SERVICE_MODE_TYPE old_mode, new_mode;

  udrv_serial_init(serialPort, baud, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);
  service_nvm_set_baudrate_to_nvm(baud);
  udrv_serial_enable (serialPort);

  switch (mode) {
     case RAK_AT_MODE:
     {
        new_mode = SERVICE_MODE_TYPE_CLI;
        break;
     }
     case RAK_API_MODE:
     {
        new_mode = SERVICE_MODE_TYPE_PROTOCOL;
        break;
     }
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
              case SERVICE_MODE_TYPE_PROTOCOL:
              {
                  service_mode_proto_deinit(serialPort);
                  break;
              }
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
              case SERVICE_MODE_TYPE_PROTOCOL:
              {
                 service_mode_proto_deinit(serialPort);
                 break;
              }
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
        default:
        {
           //impossible to be here
           break;
        }
     }
  }
}

void HardwareSerial::end()
{
  udrv_serial_disable (serialPort);
}

void HardwareSerial::lock(bool locked)
{
  if (locked) {
    udrv_serial_lock ();
  } else {
    udrv_serial_unlock ();
  }
}

bool HardwareSerial::password(char *new_passwd, size_t len)
{
    if(udrv_serial_set_passwd (new_passwd, len) == UDRV_RETURN_OK)
      return true;
   else return false;
}

bool HardwareSerial::password(String new_passwd)
{
   if(udrv_serial_set_passwd (new_passwd.c_str(), new_passwd.length()) == UDRV_RETURN_OK)
      return true;
   else return false;
}

size_t HardwareSerial::write(const uint8_t *c, size_t size)
{
  return (size_t)udrv_serial_write (serialPort, c, size);
}

int HardwareSerial::available()
{
  return (udrv_serial_read_available(serialPort));
}

int HardwareSerial::read()
{
  uint8_t buf[1];
  if(udrv_serial_read (serialPort, buf, 1) == 0)
    return -1;
  else
    return buf[0];
}

int HardwareSerial::peek()
{
    return (int)udrv_serial_peek(serialPort);
}

void HardwareSerial::flush()
{
    udrv_serial_flush(serialPort);
}

