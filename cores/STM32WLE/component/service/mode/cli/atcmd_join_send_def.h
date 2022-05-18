#ifdef SUPPORT_LORA
/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_join_send LoRaWAN Joining and Sending
 *
 * This section gives description of the commands related to the join procedure and to the data path. 
 * 
 * @subsection ATCMD_join_send_1 AT+CFM: confirm mode
 *
 * This command allows the user to access the notification on received data coming from network.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+CFM?            | --                 | AT+CFM: get or set the confirm mode (0 = off, 1 = on)             | OK                 |
 * | AT+CFM=?           | --                 | 0 or 1                                                            | OK                 |
 * | AT+CFM=\<Param\>   | 0 or 1             | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+CFM= | 1                  | --                                                                | OK                 |
 * | Example<br>AT+CFM=?|                    | 1                                                                 | OK                 |
 *
 * @subsection ATCMD_join_send_2 AT+CFS: confirm status
 *
 * This command allows the user to access the status of the last "SEND" command
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+CFS?            | --                 | AT+CFS: get the confirmation status of the last AT+SEND (0 = failure, 1 = success)     | OK                 |
 * | AT+CFS=?           | --                 | 0 or 1                                                            | OK                 |
 * | Example<br>AT+CFS=?|                    | 0                                                                 | OK                 |
 *
 * @subsection ATCMD_join_send_3 AT+JOIN: AT+JOIN: join LoRa network
 *
 * This command does a join request to the network.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+JOIN?           | --                 | AT+JOIN: join network                                             | OK                 |
 * | AT+JOIN=?          | --                 | \<integer1\>,\<integer2\>,\<integer3\>,\<integer4\>               | OK / AT_BUSY_ERROR |
 * | AT+JOIN=\<input\>  | \<integer1\>:\<integer2\>:\<integer3\>:\<integer4\>                 | --               | OK / AT_BUSY_ERROR |
 * | Example<br>AT+JOIN=? | --               | 0,0,8,0                                                           | OK                 |
 * | Example<br>AT+JOIN=| 1,1,10,8           | --                                                                | OK                 |
 *
 * <integer1> represents manually join network: 0 means stop to join network; 1 means start to join network. The default value is 0.<br>
 * <integer2> represents automatically join network: 0 means stop automatically joining network; 1 means start automatically joining network. The default value is 0.<br>
 * <integer3> represents the join attempt period. The acceptance values are 7 to 255 (in seconds). The default value is 8.<br>
 * <integer4> represents the maximum number of join attempts. The acceptance values are 0 to 255 (in seconds). The default value is 0.<br>
 *
 * This is an asynchronous command. OK means that the join is being run. The completion of the JOIN can be verified with AT+NJS=?.
 *
 * @subsection ATCMD_join_send_4 AT+NJM: LoRa network join mode
 *
 * This command allows the user to access the network join mode.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+NJM?            | --                 | AT+NJM: get or set the network join mode (0 = ABP, 1 = OTAA)      | OK                 |
 * | AT+NJM=?           | --                 | 0 or 1                                                            | OK                 |
 * | AT+NJM=\<input\>   | 0 or 1             | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+NJM= | 1                  | --                                                                | OK                 |
 * | Example<br>AT+NJM= | 2                  | --                                                                | AT_PARAM_ERROR     |
 * | Example<br>AT+NJM=?|                    | 1                                                                 | OK                 |
 *
 * @subsection ATCMD_join_send_5 AT+NJS: LoRa network join status
 *
 * This command allows the user to access the current status of the LoRa link.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+NJS?            | --                 | AT+NJS: get the join status (0 = not joined, 1 = joined)          | OK                 |
 * | AT+NJS=?           | --                 | 0 or 1                                                            | OK                 |
 * | Example<br>AT+NJS=?|                    | 0 (network not joined)                                            | OK                 |
 * | Example<br>AT+NJS=?|                    | 1 (network joined)                                                | OK                 |
 *
 * @subsection ATCMD_join_send_6 AT+RECV: last received data
 *
 * This command allows the user to access the last received data in hex format.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+RECV?            | --                 | AT+RECV: : print the last received data in hex format            | OK                 |
 * | AT+RECV=?           | --                 | Raw (HEX)                                                        | OK                 |
 * | Example<br>AT+RECV=?|                    | 45:112233                                                        | OK                 |
 *
 * @subsection ATCMD_join_send_7 AT+SEND: send data
 *
 * This command provides the way to send data on a dedicated port number.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+SEND?           | --                 | AT+SEND: send data along with the application port                | OK                 |
 * | AT+SEND=<input>    | \<port\>:\<payload\>                 |                                                 | OK / AT_PARAM_ERROR / AT_BUSY_ERROR / AT_NO_NETWORK_JOINED                 |
 * | Example<br>AT+SEND=| 12:112233          |                                                                   | OK                 |
 *
 * @subsection ATCMD_join_send_8 AT+LPSEND: This command provides the way to send long packet data
 *
 * This command provides the way to send long packet data
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+LPSEND?         | --                 | AT+LPSEND: send long packet data (max 1024 bytes)                 | OK                 |
 * | AT+LPSEND=<port>:<ack>:<payload> |<port>:<ack>:<payload>|                                                   | OK / AT_PARAM_ERROR|
 * | Example<br>AT+LPSEND=| 2:1:123456       | --                                                                | OK                 |
 *
 * @subsection ATCMD_join_send_9 AT+RETY: set the number of retransmission of confirm packet data
 *
 * This command configure the number of retransmission of confirm packet data.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+RETY?           | --                 | AT+RETY: get or set the number of retransmission of confirm packet data                | OK                 |
 * | AT+RETY=<input>    | [0,1,2,3,4,5,6,    |                                                                   | OK / AT_PARAM_ERROR|
 * | Example<br>AT+RETY=| 2                  |                                                                   | OK                 |
 *
 */
#endif

#ifndef _ATCMD_JOIN_SEND_DEF_H_
#define _ATCMD_JOIN_SEND_DEF_H_

//### following AT CMD, has doc ###
//joining and sending data atcmd
#define ATCMD_CFM              "AT+CFM"
#define ATCMD_CFS              "AT+CFS"
#define ATCMD_JOIN             "AT+JOIN"
#define ATCMD_NJM              "AT+NJM"
#define ATCMD_NJS              "AT+NJS"
#define ATCMD_RECV             "AT+RECV"
#define ATCMD_SEND             "AT+SEND"
#define ATCMD_LPSEND           "AT+LPSEND"
#define ATCMD_USEND            "AT+USEND"
#define ATCMD_RETY             "AT+RETY"
#endif //_ATCMD_JOIN_SEND_DEF_H_
