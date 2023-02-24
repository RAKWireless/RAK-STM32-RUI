/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_bootloader Bootloader Command
 * 
 * @subsection ATCMD_bootloader_1 AT+VER: Version of the Bootloader (bootloader only)
 *
 * This command allows the user to access the version of the bootloader. (bootloader only)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+VER=?           | --                 | RUI nRF52840 Bootloader v0.6                                      | OK                 |
 *
 * @subsection ATCMD_bootloader_2 AT+VERSION: Version of the Bootloader (bootloader only)
 *
 * This command allows the user to access the version of the bootloader. (bootloader only)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+VERSION         | --                 | RUI nRF52840 Bootloader v0.6                                      | OK                 |
 *
 * @subsection ATCMD_bootloader_3 AT+BOOTSTATUS: the status of the bootloader (bootloader only)
 *
 * This command gets the status of the bootloader. (bootloader only)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BOOTSTATUS      | --                 | Boot Mode                                                         | OK                 |
 *
 * @subsection ATCMD_bootloader_4 AT+RUN: leaving boot mode (bootloader only)
 *
 * This command leaves bootloader and boot into application. (bootloader only)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+RUN             | --                 | Stop Boot Mode                                                    | --                 |
 *
 * @subsection ATCMD_bootloader_5 AT+RESET: device reset (bootloader only)
 *
 * This command resets device. (bootloader only)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+RESET           | --                 | --                                                                | --                 |
 */
#ifdef stm32
/** 
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_bootloader Bootloader Command
 * 
 * @subsection ATCMD_bootloader_6 AT+UPDATE: Y-modem receiving process (stm32 bootloader only)
 *
 * This command starts Y-modem receiving process. (bootloader only)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+UPDATE          | --                 | Start firmware upgrade...                                         | --                 |
 *
 */
#endif 

#ifndef _ATCMD_BOOTLOADER_DEF_H_
#define _ATCMD_BOOTLOADER_DEF_H_

#define ATCMD_BOOTSTATUS            "AT+BOOTSTATUS"
#define ATCMD_FACTORY               "AT+FACTORY"
#endif //_ATCMD_BOOTLOADER_DEF_H_
