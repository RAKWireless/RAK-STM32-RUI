/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_general General Command
 *
 * This section describes the commands related to attention, reset, restore to default, device firmware upgrade, echo, FW version, battery level, etc.
 * 
 * @subsection ATCMD_general_1 AT: Attention
 *
 * This command is used to check that the link is working properly.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT                 | --                 | --                                                                | OK                 |
 *
 * @subsection ATCMD_general_2 AT?: Short Help
 *
 * This command provides short help for all the supported commands.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT?                | --                 | AT+\<CMD\>?: help on \<CMD\><br>AT+\<CMD\>: run \<CMD\><br>AT+\<CMD\>=\<value\>: set the value<br>AT+\<CMD\>=?: get the value<br> \<followed by the help of all commands\>                                                                | OK                 |
 *
 * @subsection ATCMD_general_3 ATZ: MCU Reset
 *
 * This command is used to trig a MCU reset.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | ATZ?               | --                 | ATZ: triggers a reset of the MCU                                  | OK                 |
 * | ATZ                | --                 | --                                                                | --                 |
 *
 * @subsection ATCMD_general_4 ATR: Restore Default Parameters
 *
 * This command is used to restore all parameters to the initial default values.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | ATR?               | --                 | ATR: restore default parameters                                   | OK                 |
 * | ATR                | --                 | --                                                                | OK / AT_PARAM_ERROR / AT_BUSY_ERROR / AT_ERROR |
 * | Example<br>ATR     | --                 | --                                                                | OK                 |
 *
 * @subsection ATCMD_general_5 AT+BOOT: Bootloader Mode
 *
 * This command is used to enter Bootloader mode to upgrade firmware.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BOOT?           | --                 | AT+BOOT: enter bootloader mode for firmware upgrade               | OK                 |
 * | AT+BOOT            | --                 | --                                                                | --                 |
 *
 * @subsection ATCMD_general_6 ATE: Command Echo
 *
 * This command is used to show or hide the AT command input.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | ATE?               | --                 | ATE: show or hide the AT command input                            | OK                 |
 * | ATE                | --                 | --                                                                | --                 |
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
 * @subsection ATCMD_general_8 AT+BAT: Battery Level
 *
 * This command allows the user to access the battery level.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BAT?            | --                 | AT+BAT: get the battery level (volt)                              | OK                 |
 * | AT+BAT=?           | --                 | <float>                                                           | OK                 |
 * | Example<br>AT+BAT=?| --                 | 3.000000                                                          | OK                 |
 *
 * @subsection ATCMD_general_9 AT+BUILDTIME: Build Time of the Firmware
 *
 * This command allows the user to access the build time of the firmware.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BUILDTIME?      | --                 | AT+BUILDTIME: get the build time of the firmware                  | OK                 |
 * | AT+BUILDTIME=?     | --                 | <string>-<string>                                                 | OK                 |
 * | Example<br>AT+BUILDTIME=?     | --      | 20220324-153217                                                   | OK                 |
 *
 * @subsection ATCMD_general_10 AT+REPOINFO: Repository Information
 *
 * This command allows the user to access the commit ID of the firmware.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+REPOINFO?       | --                 | AT+REPOINFO: get the commit ID of the firmware                    | OK                 |
 * | AT+REPOINFO=?      | --                 | <string>:<string>:<string>:<string>:<string>:<string>:<string>:<string>,                            | OK                 |
 * | Example<br>AT+REPOINFO=?     | --       | 713fbcca:6ecbb45f:e198f620:b43f5395:4a6defb9:c9438443:5ccb8eec:70e5bb3f                                                   | OK                 |
 *
 * @subsection ATCMD_general_11 AT+VER: Version of the Firmware
 *
 * This command allows the user to access the version of the firmware.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+VER?            | --                 | AT+VER: get the version of the firmware                           | OK                 |
 * | AT+VER=?           | --                 | <string>                                                          | OK                 |
 * | Example<br>AT+VER=?| --                 | 1.0.0                                                             | OK                 |
 *
 * @subsection ATCMD_general_12 AT+CLIVER: Version of the AT Command
 *
 * This command allows the user to access the version of the AT command.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+CLIVER?         | --                 | AT+CLIVER: get the version of the AT command                      | OK                 |
 * | AT+CLIVER=?        | --                 | <string>                                                          | OK                 |
 * | Example<br>AT+CLIVER=?| --              | 1.0.0                                                             | OK                 |
 *
 * @subsection ATCMD_general_13 AT+APIVER: Version of the RUI API
 *
 * This command allows the user to access the version of the RUI API.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+APIVER?         | --                 | AT+APIVER: get the version of the RUI API                         | OK                 |
 * | AT+APIVER=?        | --                 | <string>                                                          | OK                 |
 * | Example<br>AT+APIVER=?| --              | 1.0.0                                                             | OK                 |
 *
 * @subsection ATCMD_general_14 AT+HWMODEL: Hardware Model
 *
 * This command allows the user to access the string of the hardware model.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+HWMODEL?        | --                 | AT+HWMODEL: get the string of the hardware model                  | OK                 |
 * | AT+HWMODEL=?       | --                 | <string>                                                          | OK                 |
 * | Example<br>AT+HWMODEL=?| --             | rak4631                                                           | OK                 |
 *
 * @subsection ATCMD_general_15 AT+HWID: Hardware ID
 *
 * This command allows the user to access the string of the hardware ID.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+HWID?           | --                 | AT+HWID: get the string of the hardware ID                        | OK                 |
 * | AT+HWID=?          | --                 | <string>                                                          | OK                 |
 * | Example<br>AT+HWID=?| --                | nrf52840                                                          | OK                 |
 *
 * @subsection ATCMD_general_16 AT+ALIAS: Alias Name of the Device
 *
 * This command allows the user to set an alias name for device.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+ALIAS?           | --                 | AT+ALIAS: add an alias name to the device                        | OK                 |
 * | AT+ALIAS=?          | --                 | <string, 16 char>                                                | OK                 |
 * | AT+ALIAS=\<Input\>  | <string,16 char>   | --                                                               | OK / AT_PARAM_ERROR / AT_ERROR|
 * | Example<br>AT+ALIAS=| mydevice           | --                                                               | OK                 |
 * | Example<br>AT+ALIAS=?| --                | mydevice                                                         | OK                 |
 *
 * @subsection ATCMD_general_17 AT+SYSV: get the System Voltage
 *
 * This command allows the user to get the System Voltage.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+SYSV?           | --                 | AT+SYSV: get the System Voltage                                   | OK                 |
 * | AT+SYSV=?          | --                 | <float>                                                           | OK                 |
 * | Example<br>AT+SYSV=?| --                | 3.0                                                              | OK                 |
 *
 * @subsection ATCMD_general_18 AT+BLEMAC: get or set the BLE Mac address
 *
 * This command allows the user to get or set the BLE Mac address
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BLEMAC?         | --                 | AT+BLEMAC: get or set the BLE Mac address                         | OK                 |
 * | AT+BLEMAC=?        | --                 | <string>:<string>:<string>:<string>:<string>:<string>             | OK                 |
 * | AT+BLEMAC=\<Input\>| <string,12 char>   | <string>                                                          | OK                 |
 * | Example<br>AT+BLEMAC=?| --              | dc:a1:26:1e:e6:84                                                 | OK                 |
 * | Example<br>AT+BLEMAC=| ffffffffffff     | --                                                                | OK                 |
 *
 * @subsection ATCMD_general_19 AT+BOOTVER: get the version of RUI Bootloader
 *
 * This command allows the user to get the version of RUI Bootloader
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BOOTVER?        | --                 | AT+BOOTVER: get the version of RUI Bootloader                     | OK                 |
 * | AT+BOOTVER=?       | --                 | <string>                                                          | OK                 |
 * | Example<br>AT+BOOTVER=?| --             | RUI STM32WLE5CC Bootloader v0.5                                   | OK                 |
 */

#ifndef _ATCMD_GENERAL_DEF_H_
#define _ATCMD_GENERAL_DEF_H_

#define ATCMD_ATTENTION             "AT"
#define ATCMD_REBOOT                "ATZ"
#define ATCMD_ATR                   "ATR"
#define ATCMD_BOOT                  "AT+BOOT"
#define ATCMD_BOOTVER               "AT+BOOTVER"
#define ATCMD_DEBUG					"AT+DEBUG"
#define ATCMD_ATE                   "ATE"
#define ATCMD_FSN                   "AT+FSN"
#define ATCMD_SN                    "AT+SN"
#define ATCMD_BAT                   "AT+BAT"
#define ATCMD_BUILDTIME             "AT+BUILDTIME"
#define ATCMD_REPOINFO              "AT+REPOINFO"
#define ATCMD_FWVER                 "AT+VER"
#define ATCMD_CUSFWVER              "AT+FIRMWAREVER"
#define ATCMD_CLIVER                "AT+CLIVER"
#define ATCMD_APIVER                "AT+APIVER"
#define ATCMD_HWMODEL               "AT+HWMODEL"
#define ATCMD_HWID                  "AT+HWID"
#define ATCMD_ALIAS                 "AT+ALIAS"
#define ATCMD_SYSV                  "AT+SYSV"
#ifdef rak3172
#define ATCMD_UID                   "AT+UID"
#endif
#ifdef SUPPORT_BLE
#define ATCMD_BLEMAC                "AT+BLEMAC"
#endif

#endif //_ATCMD_GENERAL_DEF_H_
