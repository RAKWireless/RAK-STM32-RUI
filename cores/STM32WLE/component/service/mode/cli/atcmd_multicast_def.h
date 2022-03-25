/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_multicast LoRaWAN Multicast Group
 *
 * This section provides a set of multicast group commands.
 * 
 * @subsection ATCMD_multicast_1 AT+ADDMULC: Add a new multicast group
 *
 * This command add a new multicast group to configure multicast parameters.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+ADDMULC?           | --              | AT+ADDMULC: add a new multicast group                             | OK                 |
 * | AT+ADDMULC=\<Input\>  | \<Class\>:\<Dev Addr\>:\<Nwk SKey\>:\<App SKey\>:\<Freq\>:\<DR\>:\<Periodicity\>            |     | OK / AT_PARAM_ERROR|
 * | Example<br>AT+ADDMULC=| B:01020304:0102030405060708:0102030405060708:868000000:0:0               | --       | OK                 |
 *
 * @subsection ATCMD_multicast_2 AT+RMVMULC: Remove a multicast group
 *
 * This command allows the remove of a configured multicast group.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+RMVMULC?           | --              | AT+RMVMULC: delete a multicast group                              | OK                 |
 * | AT+RMVMULC=\<Input\>  | <Dev Addr>      | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+RMVMULC=| 01020304        | --                                                                | OK                 |
 *
 * @subsection ATCMD_multicast_3 AT+LSTMULC: multicast group list
 *
 * This command can view all the current configured multicast group information.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+LSTMULC?           | --              | AT+LSTMULC: view multicast group information                      | OK                 |
 * | AT+LSTMULC=\<Input\>  | --              | MC1:\<Class\>:\<Dev Addr\>:\<Nwk SKey\>:\<App SKey\>:\<Freq\>:\<DR\>:\<Periodicity\>                                                                  | OK                 |
 * | Example<br>AT+LSTMULC=| --              | MC1:C:01020304:0102030405060708:0102030405060708:868000000:0:0<br>MC2:C:01020304:0102030405060708:0102030405060708:868000000:0:0                                                                | OK                 |
 *
 */
#ifndef _ATCMD_MULTICAST_DEF_H_
#define _ATCMD_MULTICAST_DEF_H_

//### following AT CMD, has doc ###
#define ATCMD_ADDMULC          "AT+ADDMULC"
#define ATCMD_RMVMULC          "AT+RMVMULC"
#define ATCMD_LSTMULC          "AT+LSTMULC"

#endif //
