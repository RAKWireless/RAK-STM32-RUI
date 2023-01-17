/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_general General Command
 *
 * This section describes the commands related to "attention" help list, link control and CPU reset. 
 * 
 * @subsection ATCMD_general_1 AT: attention
 *
 * This command is used to check that the link is working properly.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT                 | --                 | --                                                                | OK                 |
 *
 * @subsection ATCMD_general_2 AT?: short help
 *
 * This command provides short help for all the supported commands.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT?                | --                 | AT+\<CMD\>?: help on \<CMD\><br>AT+\<CMD\>: run \<CMD\><br>AT+\<CMD\>=\<value\>: set the value<br>AT+\<CMD\>=?: get the value<br> \<followed by the help of all commands\>                                                                | OK                 |
 *
 * @subsection ATCMD_general_3 ATZ: MCU reset
 *
 * This command is used to trig a CPU reset.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | ATZ?               | --                 | ATZ: triggers a reset of the MCU                                  | OK                 |
 * | ATZ                | --                 | No return value and return code. The MCU is reset.                | --                 |
 *
 * @subsection ATCMD_general_4 ATR: Restore default parameters
 *
 * This command is used to restore all parameters to the initial default values.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | ATR?               | --                 | ATR: restore default parameters                                   | OK                 |
 * | ATR                | --                 | No return value and return code.                                  | OK                 |
 * | Example<br>ATR     | --                 | --                                                                | OK                 |
 *
 * @subsection ATCMD_general_5 AT+BOOT: Bootloader mode
 *
 * This command is used to enter Bootloader mode to upgrade firmware.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BOOT?           | --                 | AT+BOOT: enter bootloader mode for firmware upgrade               | OK                 |
 * | AT+BOOT            | --                 | No return value and return code. The MCU is reset and enters bootloader mode.                                  | --                 |
 *
 * @subsection ATCMD_general_6 ATE: Set command echo
 *
 * This command is used to see the AT command input on the Serial Terminal.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | ATE?               | --                 | ATE: see the AT command input on the Serial Terminal              | OK                 |
 * | ATE                | --                 | No return value and return code.                                  | --                 |
 *
 * @subsection ATCMD_general_7 AT+SN: get the serial number of the device
 *
 * This command allows the user to access the serial number of the device.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+SN?             | --                 | AT+SN: get the serial number of the device (max 18 char)          | OK                 |
 * | AT+SN=?            | --                 | <1-18 char>                                                       | OK                 |
 *
 * @subsection ATCMD_general_8 AT+BAT: battery level
 *
 * This command allows the user to access the battery level.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BAT?            | --                 | AT+BAT: get the battery level (volt)                              | OK                 |
 * | AT+BAT=?           | --                 | <float>                                                           | OK                 |
 * | Example<br>AT+BAT=?| --                 | 3.0                                                               | OK                 |
 *
 * @subsection ATCMD_general_9 AT+BUILDTIME: build time of the firmware
 *
 * This command allows the user to access the build time of the firmware.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BUILDTIME?      | --                 | AT+BUILDTIME: get the build time of the firmware                  | OK                 |
 * | AT+BUILDTIME=?     | --                 | <string>-<string>                                                 | OK                 |
 *
 * @subsection ATCMD_general_10 AT+REPOINFO: code repository information of the firmware
 *
 * This command allows the user to access the commit ID of the firmware.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+REPOINFO?       | --                 | AT+REPOINFO: get the commit ID of the firmware                    | OK                 |
 * | AT+REPOINFO=?      | --                 | <string>,<string>,<string>,<string>,<string>,<string>,<string>,<string>,                            | OK                 |
 *
 * @subsection ATCMD_general_11 AT+VER: version of the firmware
 *
 * This command allows the user to access the version of the firmware.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+VER?            | --                 | AT+VER: get the version of the firmware                           | OK                 |
 * | AT+VER=?           | --                 | <string>                                                          | OK                 |
 * | Example<br>AT+VER=?| --                 | 1.0.0                                                             | OK                 |
 *
 * @subsection ATCMD_general_12 AT+CLIVER: version of the AT command
 *
 * This command allows the user to access the version of the AT command.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+CLIVER?         | --                 | AT+CLIVER: get the version of the AT command                      | OK                 |
 * | AT+CLIVER=?        | --                 | <string>                                                          | OK                 |
 * | Example<br>AT+CLIVER=?| --              | 1.0.0                                                             | OK                 |
 *
 * @subsection ATCMD_general_13 AT+APIVER: version of the RUI API
 *
 * This command allows the user to access the version of the RUI API.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+APIVER?         | --                 | AT+APIVER: get the version of the RUI API                         | OK                 |
 * | AT+APIVER=?        | --                 | <string>                                                          | OK                 |
 * | Example<br>AT+APIVER=?| --              | 1.0.0                                                             | OK                 |
 *
 * @subsection ATCMD_general_14 AT+HWMODEL: hardware model of the firmware
 *
 * This command allows the user to access the hardware model of the firmware.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+HWMODEL?        | --                 | AT+HWMODEL: get the string of the hardware model                  | OK                 |
 * | AT+HWMODEL=?       | --                 | <string>                                                          | OK                 |
 * | Example<br>AT+HWMODEL=?| --             | rak4631                                                           | OK                 |
 *
 * @subsection ATCMD_general_15 AT+HWID: hardware ID of the firmware
 *
 * This command allows the user to access the hardware ID of the firmware.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+HWID?           | --                 | AT+HWID: get the string of the hardware ID                        | OK                 |
 * | AT+HWID=?          | --                 | <string>                                                          | OK                 |
 * | Example<br>AT+HWID=?| --                | nrf52840                                                          | OK                 |
 *
 * @subsection ATCMD_general_16 AT+ALIAS: alias name of the device
 *
 * This command allows the user to set an alias name for device.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+ALIAS?           | --                 | AT+ALIAS: add an alias name to the device                        | OK                 |
 * | AT+ALIAS=?          | --                 | <string, 16 char>                                                | OK                 |
 * | AT+ALIAS=\<Input\>  | <string,16 char>   | --                                                               | OK / AT_PARAM_ERROR|
 * | Example<br>AT+ALIAS=  | mydevice         | --                                                               | OK                 |
 * | Example<br>AT+ALIAS=?| --                | mydevice                                                         | OK                 |
 *
 */

#ifndef _ATCMD_GENERAL_DEF_H_
#define _ATCMD_GENERAL_DEF_H_

#define ATCMD_ATTENTION             "AT"
#define ATCMD_REBOOT                "ATZ"
#define ATCMD_ATR                   "ATR"
#define ATCMD_BOOT                  "AT+BOOT"
#define ATCMD_ATE                   "ATE"
#define ATCMD_FSN                   "AT+FSN"
#define ATCMD_SN                    "AT+SN"
#define ATCMD_BAT                   "AT+BAT"
#define ATCMD_BUILDTIME             "AT+BUILDTIME"
#define ATCMD_REPOINFO              "AT+REPOINFO"
#define ATCMD_FWVER                 "AT+VER"
#define ATCMD_CLIVER                "AT+CLIVER"
#define ATCMD_APIVER                "AT+APIVER"
#define ATCMD_HWMODEL               "AT+HWMODEL"
#define ATCMD_HWID                  "AT+HWID"
#define ATCMD_ALIAS                 "AT+ALIAS"
#ifdef rak3172
#define ATCMD_UID                   "AT+UID"
#endif

#endif //_ATCMD_GENERAL_DEF_H_
