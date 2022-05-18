#ifdef SUPPORT_LORA
/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_supplement Supplementary Command
 *
 * This section provides a set of supplementary commands.
 * 
 * @subsection ATCMD_supplement_1 AT+MASK: Access the channel mask to close or open the channel.
 *
 * This command configures the channel of the device by setting the hexadecimal channel mask.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+MASK?           | --                 | AT+MASK: get or set the channel mask to close or open the channel (only for US915, AU915, CN470)     | OK                 |
 * | AT+MASK=?          | --                 | <2 hex>                                                           | OK                 |
 * | AT+MASK=\<Input\>  | <2 hex>            | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+MASK=| 0001               | --                                                                | OK                 |
 * | Example<br>AT+MASK=?|                   | 0001                                                              | OK                 |
 *
 * @subsection ATCMD_supplement_2 AT+BAND: active region
 *
 * This command get or set the active region
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BAND?           | --                 | AT+BAND: get or set the active region (0 = EU433, 1 = CN470, 2 = RU864, 3 = IN865, 4 = EU868, 5 = US915, 6 = AU915, 7 = KR920, 8 = AS923-1 , 9 = AS923-2 , 10 = AS923-3 , 11 = AS923-4)                             | OK                 |
 * | AT+BAND=?          | --                 | [0,1,2,3,4,5,6,7,8,9,10,11]                                               | OK                 |
 * | AT+BAND=\<Input\>  | [0,1,2,3,4,5,6,7,8,9,10,11]| --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+BAND=| 1                  | --                                                                | OK                 |
 * | Example<br>AT+BAND=?|                   | 3                                                                 | OK                 |
 *
 * @subsection ATCMD_supplement_3 AT+CHE: get or set eight channels mode (only for US915 AU915 CN470)
 *
 * This command get or set eight channels mode (only for US915 AU915 CN470)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+CHE?            | --                 | AT+CHE: get or set eight channels mode (only for US915 AU915 CN470)                         | OK            |
 * | AT+CHE=?           | --                 | [0,1,2,3,4,5,6,7,8]                                               | OK                 |
 * | AT+CHE=\<Input\>   | [0,1,2,3,4,5,6,7,8]| --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+CHE= | 1                  | --                                                                | OK                 |
 * | Example<br>AT+CHE=?|                    | 3                                                                 | OK                 |
 *
 * @subsection ATCMD_supplement_4 AT+CHS: get or set single channels mode (only for US915 AU915 CN470)
 *
 * This command get or set single channels mode (only for US915 AU915 CN470)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+CHS?            | --                 | AT+CHE: get or set single channels mode (only for US915 AU915 CN470) | OK            |
 * | AT+CHS=?           | --                 | Frequency                                                         | OK                 |
 * | AT+CHS=\<Input\>   | Frequency          |                                                                   | OK / AT_PARAM_ERROR|
 * | Example<br>AT+CHS= | 902300000          | --                                                                | OK                 |
 * | Example<br>AT+CHS=?|                    | 902300000                                                         | OK                 |
 *
 *
 */
#endif 
 

#ifndef _ATCMD_SUPPLE_DEF_H_
#define _ATCMD_SUPPLE_DEF_H_

#define ATCMD_ATE              "ATE"
#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
#define ATCMD_MASK             "AT+MASK"
#define ATCMD_CHS              "AT+CHS"
#define ATCMD_CHE              "AT+CHE"
#endif
#define ATCMD_BAND             "AT+BAND"

//#define ATCMD_DELBONDS         "AT+DELBONDS"

#endif //_ATCMD_SUPPLE_DEF_H_
