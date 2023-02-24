/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_serial_port Serial Port Command
 * 
 * @subsection ATCMD_serial_port_1 AT+LOCK: Lock the AT command serial port
 *
 * This command locks the AT command serial port.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+LOCK?           | --                 | AT+LOCK: lock the serial port                                     | OK                 |
 * | AT+LOCK=?          | --                 | <string>                                                          | OK                 |
 * | AT+LOCK            | --                 | --                                                                | OK                 |
 * | Example<br>AT+LOCK=?| --                | unlocked                                                          | OK                 |
 *
 * @subsection ATCMD_serial_port_2 AT+PWORD: the password for locking the AT command serial port
 *
 * This command sets the password for locking the AT command serial port.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PWORD?          | --                 | AT+PWORD: set the serial port locking password (max 8 char)       | OK                 |
 * | AT+PWORD=?         | --                 | <1-8 hex>                                                         | OK                 |
 * | AT+PWORD=\<Input\> | <1-8 hex>          | --                                                                | OK                 |
 * | Example<br>AT+PWORD=88888888  | <1-8 hex>          | --                                                     | OK                 |
 *
 * @subsection ATCMD_serial_port_3 AT+BAUD: the serial port baudrate
 *
 * This command allows the user to access the serial port baudrate.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BAUD?           | --                 | AT+BAUD: get or set the serial port baudrate                      | OK                 |
 * | AT+BAUD=?          | --                 | \<integer\>                                                       | OK                 |
 * | AT+BAUD=\<input\>  | \<integer\>        | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+BAUD=| 115200             | --                                                                | OK                 |
 * | Example<br>AT+BAUD=| abc                | --                                                                | AT_PARAM_ERROR     |
 * | Example<br>AT+BAUD=?| --                | 115200                                                            | OK                 |
 *
 * @subsection ATCMD_serial_port_4 AT+ATM: AT command mode
 *
 * This command provides a way to switch to AT command mode
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+ATM?            | --                 | AT+ATM: switch to AT command mode                                 | OK                 |
 * | AT+ATM             | --                 |                                                                   | OK                 |
 * 
 * @subsection ATCMD_serial_port_5 AT+APM: API mode
 *
 * This command provides a way to switch to API mode
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+APM?            | --                 | AT+APM: switch to API mode                                        | OK                 |
 * | AT+APM             | --                 |                                                                   | OK                 |
 *
 */
#if defined(SUPPORT_LORA) && defined(SUPPORT_PASSTHRU)
/**
 * @subsection ATCMD_serial_port_6 ATD: pass through mode
 *
 * This command provides a way to switch to pass through mode
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | ATD?               | --                 | ATD: switch to pass through mode                                  | OK                 |
 * | ATD                | --                 |                                                                   | OK                 |
 * | ATD=\<param\>      | <fport>            |                                                                   | OK / AT_PARAM_ERROR|
 * 
 * @subsection ATCMD_serial_port_7 +++: Exit transparent transmission mode
 *
 * This command provides Exit data transparent transmission mode
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | +++                | --                 | --                                                                | --                 |
 * 
 *
 */
#endif

#ifndef _ATCMD_SERIAL_PORT_DEF_H_
#define _ATCMD_SERIAL_PORT_DEF_H_

#define ATCMD_LOCK                  "AT+LOCK"
#define ATCMD_PWORD                 "AT+PWORD"
#define ATCMD_BAUD                  "AT+BAUD"
#define ATCMD_ATM                   "AT+ATM"
#define ATCMD_APM                   "AT+APM"
#if defined(SUPPORT_LORA) && defined(SUPPORT_PASSTHRU)
#define ATCMD_PAM                   "ATD"
#endif
#endif //_ATCMD_SERIAL_PORT_DEF_H_
