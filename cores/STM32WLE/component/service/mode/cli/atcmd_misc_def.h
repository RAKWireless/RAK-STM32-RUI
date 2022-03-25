/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_misc Miscellaneous Command
 * 
 * @subsection ATCMD_misc_1 AT+BOOTSTATUS: the status of the bootloader
 *
 * This command gets the status of the bootloader.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BOOTSTATUS?     | --                 | AT+BOOTSTATUS: get the status of the bootloader                   | OK                 |
 * | AT+BOOTSTATUS      | --                 | --                                                                | OK                 |
 *
 */

#ifndef _ATCMD_MISC_DEF_H_
#define _ATCMD_MISC_DEF_H_

#define ATCMD_BOOTSTATUS            "AT+BOOTSTATUS"
#define ATCMD_FACTORY               "AT+FACTORY"
#endif //_ATCMD_MISC_DEF_H_
