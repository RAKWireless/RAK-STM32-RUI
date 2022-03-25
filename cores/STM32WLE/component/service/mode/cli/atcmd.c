#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "variant.h"
#include "atcmd.h"
#include "atcmd_general.h"
#include "atcmd_general_def.h"
#include "atcmd_sleep.h"
#include "atcmd_sleep_def.h"
#include "atcmd_serial_port.h"
#include "atcmd_serial_port_def.h"
#include "atcmd_misc.h"
#include "atcmd_misc_def.h"
#ifndef RUI_BOOTLOADER
#ifdef SUPPORT_LORA
#include "atcmd_key_id.h"
#include "atcmd_key_id_def.h"
#include "atcmd_join_send.h"
#include "atcmd_join_send_def.h"
#include "atcmd_nwk_management.h"
#include "atcmd_nwk_management_def.h"
#include "atcmd_class_b_mode.h"
#include "atcmd_class_b_mode_def.h"
#include "atcmd_info.h"
#include "atcmd_info_def.h"
#include "atcmd_multicast_def.h"
#include "atcmd_multicast.h"
#include "atcmd_supplement.h"
#include "atcmd_supplement_def.h"
#include "atcmd_p2p.h"
#include "atcmd_p2p_def.h"
#include "atcmd_cert.h"
#include "atcmd_cert_def.h"
#endif
#endif
#include "udrv_serial.h"
#include "service_mode_cli.h"
#ifdef rak3172
#include "uhal_system.h"
#endif

void At_RespOK (char* pStr)
{
    atcmd_printf("\r\nOK\r\n");
}

int parseBuff2Param(char* bufCmd, stParam* pParam, uint8_t maxargu)
{
	int buflen, i;
	const char delimiters = ':';

    buflen = strlen (bufCmd);
	if (strlen (bufCmd) == 0) 
		return AT_PARAM_ERROR;

    if(maxargu == 0)
        maxargu = MAX_ARGUMENT;

    pParam->argc = 1;
    pParam->argv[pParam->argc - 1] = &bufCmd[0];
    i = 0;
    while(pParam->argc < maxargu)
    {
        for(; i < buflen ; i++)
        {
            if(bufCmd[i] == delimiters)
            {
                bufCmd[i] = 0;
                break;
            }
        }
        if(i == buflen)
			break;
        if(bufCmd[i + 1] != 0)
        {
            pParam->argc += 1;
            pParam->argv[pParam->argc - 1] = &bufCmd[i + 1];
        }
        else {
            break;
        }
    }
    
	return 0;
}

const char *atcmd_err_tbl[] =
{
	"OK",
	"AT_ERROR",
	"AT_PARAM_ERROR",
	"AT_BUSY_ERROR",
	"AT_TEST_PARAM_OVERFLOW",
	"AT_NO_CLASSB_ENABLE",
	"AT_NO_NETWORK_JOINED",
	"AT_RX_ERROR",
	"AT_MODE_NO_SUPPORT",
};

at_cmd_info atcmd_info_tbl[] =
{
/* General Command */
    {ATCMD_ATTENTION,/*0*/          At_Attention,          0, "",AT_PERM},
    {ATCMD_REBOOT,   /*1*/          At_Reboot,             0, "triggers a reset of the MCU", ATZ_PERM},
    {ATCMD_ATR,      /*3*/          At_Restore,            0, "restore default parameters", ATR_PERM},
    {ATCMD_BOOT,     /*4*/          At_Dfu,                0, "enter bootloader mode for firmware upgrade", AT_BOOT_PERM},
#ifndef RUI_BOOTLOADER
    {ATCMD_ATE,      /*88*/         At_Echo,               0, "toggle the At Command echo available", ATE_PERM},
    {ATCMD_FSN,      /*hidden*/     At_FSn,                0, "", AT_FSN_PERM},
    {ATCMD_FACTORY , /*hidden*/     At_Factory,            0, "", AT_FACTORY_PERM},
    {ATCMD_SN,       /*87*/         At_Sn,                 0, "get the serial number of the device (max 18 char)", AT_SN_PERM},
    {ATCMD_BAT,      /*15*/         At_GetBat,             0, "get the battery level (volt)", AT_BAT_PERM},
    {ATCMD_BUILDTIME,/*5*/          At_GetFwBuildTime,     0, "get the build time of the firmware", AT_BUILDTIME_PERM},
    {ATCMD_REPOINFO, /*6*/          At_GetFwRepoInfo,      0, "get the commit ID of the firmware", AT_REPOINFO_PERM},
    {ATCMD_FWVER,    /*7*/          At_GetFwVersion,       0, "get the version of the firmware", AT_VER_PERM},
    {ATCMD_CLIVER,   /*8*/          At_GetCliVersion,      0, "get the version of the AT command", AT_CLIVER_PERM},
    {ATCMD_APIVER,   /*9*/          At_GetApiVersion,      0, "get the version of the RUI API", AT_APIVER_PERM},
    {ATCMD_HWMODEL,  /*13*/         At_GetHwModel,         0, "get the string of the hardware model", AT_HWMODEL_PERM},
    {ATCMD_HWID,     /*14*/         At_GetHwID,            0, "get the string of the hardware id", AT_HWID_PERM},
    {ATCMD_ALIAS,    /*89*/         At_Alias,              0, "add an alias name to the device", AT_ALIAS_PERM},
#ifdef rak3172
    {ATCMD_UID,      /*91*/         At_GetUid,             0, "", AT_UID_PERM},
#endif
/* Sleep Command */
    {ATCMD_SLEEP,    /*85*/         At_Sleep,              0, "enter sleep mode for a period of time (ms)", AT_SLEEP_PERM},
    //{ATCMD_AUTOSLEEP,/*86*/         At_AutoSleep,          0, "automatically and periodically enter sleep mode (ms)", },
/* Serial Port Command */
    {ATCMD_LOCK,     /*10*/         At_Lock,               0, "lock the serial port",AT_LOCK_PERM },
    {ATCMD_PWORD,    /*11*/         At_Pword,              0, "set the serial port locking password (max 8 char)", AT_PWORD_PERM},
    {ATCMD_BAUD,     /*12*/         At_Baud,               0, "get or set the serial port baudrate", AT_BAUD_PERM},
    {ATCMD_ATM,      /*72*/         At_AtCmdMode,          0, "switch to AT command mode", AT_ATM_PERM},
    {ATCMD_APM,      /*73*/         At_ApiMode,            0, "switch to API mode", AT_APM_PERM},
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
    {ATCMD_PAM,      /*74*/         At_TransparentMode,    0, "enter data transparent transmission mode", ATD_PERM},
#endif
/* LoRaWAN Keys and IDs */
    {ATCMD_APPEUI,   /*16*/         At_AppEui,             0, "get or set the application EUI (8 bytes in hex)", AT_APPEUI_PERM},
    {ATCMD_APPKEY,   /*17*/         At_AppKey,             0, "get or set the application key (16 bytes in hex)", AT_APPKEY_PERM},
    {ATCMD_APPSKEY,  /*18*/         At_AppSKey,            0, "get or set the application session key (16 bytes in hex)", AT_APPSKEY_PERM},
    {ATCMD_DADDR,    /*19*/         At_DevAddr,            0, "get or set the device address (4 bytes in hex)", AT_DEVADDR_PERM},
    {ATCMD_DEUI,     /*20*/         At_DevEui,             0, "get or set the device EUI (8 bytes in hex)", AT_DEVEUI_PERM},
    {ATCMD_NETID,    /*21*/         At_NetId,              0, "get the network identifier (NetID) (3 bytes in hex)", AT_NETID_PERM},
    {ATCMD_NWKSKEY,  /*22*/         At_NwkSKey,            0, "get or set the network session key (16 bytes in hex)", AT_NWKSKEY_PERM},
/* LoRaWAN Joining and Sending */
    {ATCMD_CFM,      /*23*/         At_CfMode,             0, "get or set the confirm mode (0 = off, 1 = on)", AT_CFM_PERM},
    {ATCMD_CFS,      /*24*/         At_CfStatus,           0, "get the confirmation status of the last AT+SEND (0 = failure, 1 = success)", AT_CFS_PERM},
    {ATCMD_JOIN,     /*25*/         At_Join,               0, "join network", AT_JOIN_PERM},
    {ATCMD_NJM,      /*26*/         At_NwkJoinMode,        0, "get or set the network join mode (0 = ABP, 1 = OTAA)", AT_NJM_PERM},
    {ATCMD_NJS,      /*27*/         At_NwkJoinStatus,      0, "get the join status (0 = not joined, 1 = joined)", AT_NJS_PERM},
    {ATCMD_RECV,     /*28*/         At_Recv,               0, "print the last received data in hex format", AT_RECV_PERM},
    {ATCMD_SEND,     /*29*/         At_Send,               0, "send data along with the application port", AT_SEND_PERM},
    {ATCMD_LPSEND,   /*83*/         At_Lpsend,             0, "send long packet data (max 1000 bytes)", AT_LPSEND_PERM},
    //{ATCMD_USEND,   /*??*/         At_Lpsend,             0, "unified send packet along with the application port", },
    {ATCMD_RETY,     /*30*/         At_Retry,              0, "get or set the number of retransmission of confirm packet data", AT_RETY_PERM},
/* LoRaWAN Network Management */
    {ATCMD_ADR,      /*31*/         At_ADR,                0, "get or set the adaptive data rate setting (0 = off, 1 = on)", AT_ADR_PERM},
    {ATCMD_CLASS,    /*32*/         At_Class,              0, "get or set the device class (A = class A, B = class B, C = class C)", AT_CLASS_PERM},
    {ATCMD_DCS,      /*33*/         At_DCS,                0, "get the ETSI duty cycle setting (0 = disabled, 1 = enabled)", AT_DCS_PERM},
    {ATCMD_DR,       /*34*/         At_DataRate,           0, "get or set the data rate", AT_DR_PERM},
    {ATCMD_JN1DL,    /*35*/         At_RxWin1JoinDelay,    0, "get or set the join accept delay between the end of TX and the join RX window 1 in second", AT_JN1DL_PERM},
    {ATCMD_JN2DL,    /*36*/         At_RxWin2JoinDelay,    0, "get or set the join accept delay between the end of TX and the join RX window 2 in second", AT_JN2DL_PERM},
    {ATCMD_PNM,      /*37*/         At_PubNwkMode,         0, "get or set the public network mode (0 = off, 1 = on)", AT_PNM_PERM},
    {ATCMD_RX1DL,    /*38*/         At_RxWin1Delay,        0, "get or set the delay between the end of TX and the RX window 1 in second (1-15)", AT_RX1DL_PERM},
    {ATCMD_RX2DL,    /*39*/         At_RxWin2Delay,        0, "get or set the delay between the end of TX and the RX window 2 in second (2-16)", AT_RX2DL_PERM},
    {ATCMD_RX2DR,    /*40*/         At_RxWin2DataRate,     0, "get or set the RX2 window data rate", AT_RX2DR_PERM},
    {ATCMD_RX2FQ,    /*41*/         At_RxWin2Freq,         0, "get the RX2 window frequency (Hz)", AT_RX2FQ_PERM},
    {ATCMD_TXP,      /*42*/         At_TxPower,            0, "get or set the transmitting power", AT_TXP_PERM},
    {ATCMD_LINKCHECK,/*43*/         At_LinkCheck,          0, "get or set the link check setting (0 = disabled, 1 = once, 2 = everytime)", AT_LINKCHECK_PERM},
/* LoRaWAN Class B */
    {ATCMD_PGSLOT,   /*44*/         At_PingSlot,           0, "get or set the unicast ping slot periodicity (0-7)", AT_PGSLOT_PERM},
    {ATCMD_BFREQ,    /*45*/         At_BeaconFreq,         0, "get the data rate and beacon frequency (MHz)", AT_BFREQ_PERM},
    {ATCMD_BTIME,    /*46*/         At_BeaconTime,         0, "get the beacon time (seconds since GPS Epoch time)", AT_BTIME_PERM},
    {ATCMD_BGW,      /*47*/         At_BGW,                0, "get the gateway GPS coordinate, NetID and GwID", AT_BGW_PERM},
    {ATCMD_LTIME,    /*48*/         At_LocalTime,          0, "get the local time", AT_LTIME_PERM},
/* LoRaWAN Information */
    {ATCMD_RSSI,     /*49*/         At_Rssi,               0, "get the RSSI of the last received packet", AT_RSSI_PERM},
    {ATCMD_ARSSI,    /*75*/         At_Arssi,              0, "access all open channel RSSI", AT_ARSSI_PERM},
    {ATCMD_SNR,      /*50*/         At_Snr,                0, "get the SNR of the last received packet", AT_SNR_PERM},
/* Supplementary Command */
#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
    {ATCMD_MASK,     /*51*/         At_Mask,               0, "get or set the channel mask to close or open the channel (only for US915, AU915, CN470)", AT_MASK_PERM},
    {ATCMD_CHE,      /*52*/         At_Che,                0, "get or set eight channels mode (only for US915 AU915 CN470)", AT_CHE_PERM},
    {ATCMD_CHS,      /*53*/         At_Chs,                0, "get or set single channels mode (only for US915 AU915 CN470)", AT_CHS_PERM},
#endif
    {ATCMD_BAND,     /*54*/         At_Band,               0, "get or set the active region (0 = EU433, 1 = CN70, 2 = RU864, 3 = IN865, 4 = EU868, 5 = US915, 6 = AU915, 7 = KR920, 8 = AS923)", AT_BAND_PERM},
/* LoRaWAN P2P */
    {ATCMD_NWM,      /*55*/         At_NwkWorkMode,        0, "get or set the network working mode (0 = P2P_LORA, 1 = LoRaWAN, 2 = P2P_FSK)", AT_NWM_PERM},
    {ATCMD_PFREQ,    /*56*/         At_P2pFreq,            0, "configure P2P Frequency", AT_PFREQ_PERM},
    {ATCMD_PSF,      /*57*/         At_P2pSF,              0, "configure P2P Spreading Factor (5-12)", AT_PSF_PERM},
    {ATCMD_PBW,      /*58*/         At_P2pBW,              0, "configure P2P Bandwidth(LORA:125,250,500 FSK:4800-467000)", AT_PBW_PERM},
    {ATCMD_PCR,      /*59*/         At_P2pCR,              0, "configure P2P Code Rate(0=4/5, 1=4/6, 2=4/7, 3=4/8)", AT_PCR_PERM},
    {ATCMD_PPL,      /*60*/         At_P2pPL,              0, "configure P2P Preamble Length (5-65535)", AT_PPL_PERM},
    {ATCMD_PTP,      /*61*/         At_P2pTP,              0, "configure P2P TX Power(5-22)", AT_PTP_PERM},
    {ATCMD_PSEND,    /*62*/         At_P2pSend,            0, "send data in P2P mode", AT_PSEND_PERM},
    {ATCMD_PRECV,    /*63*/         At_P2pRecv,            0, "enter P2P RX mode for a period of time (ms)", AT_PRECV_PERM},
    {ATCMD_PCRYPT,   /*64*/         At_P2pCrypt,           0, "get or set the encryption status of P2P mode", AT_ENCRY_PERM},
    {ATCMD_PKEY,     /*65*/         At_P2pKey,             0, "get or set the encryption key of P2P mode (8 bytes in hex)", AT_ENCKEY_PERM},
    {ATCMD_P2P,      /*66*/         At_P2p,                0, "get or set all P2P parameters", AT_P2P_PERM},
    {ATCMD_PBR,      /*67*/         At_Pbr,                0, "get or set the P2P FSK modem bitrate (600-300000 b/s)", AT_PBR_PERM},
    {ATCMD_PFDEV,    /*68*/         At_Pfdev,              0, "get or set the P2P FSK modem frequency deviation (600-200000 hz)", AT_PFDEV_PERM},
/* LoRaWAN Multicast Group */
    {ATCMD_ADDMULC,  /*69*/         At_Addmulc,            0, "add a new multicast group", AT_ADDMULC_PERM},
    {ATCMD_RMVMULC,  /*70*/         At_Rmvmulc,            0, "delete a multicast group" , AT_RMVMULC_PERM},
    {ATCMD_LSTMULC,  /*71*/         At_Lstmulc,            0, "view multicast group information", AT_LSTMULC_PERM},
/* LoRaWAN Certification */
    {ATCMD_TRSSI,    /*77*/         At_Trssi,              0, "start RF RSSI tone test", AT_TRSSI_PERM},
    {ATCMD_TTONE,    /*78*/         At_Ttone,              0, "start RF tone test", AT_TTONE_PERM},
    {ATCMD_TTX,      /*79*/         At_Ttx,                0, "set number of packets to be sent for PER RF TX test", AT_TTX_PERM},
    {ATCMD_TRX,      /*80*/         At_Trx,                0, "set number of packets to be received for PER RF RX test", AT_TRX_PERM},
    {ATCMD_TCONF,    /*81*/         At_Tconf,              0, "configure LoRa RF test", AT_TCONF_PERM},
    {ATCMD_TTH,      /*82*/         At_Tth,                0, "start RF TX hopping test from Fstart to Fstop, with Fdelta steps", AT_TTH_PERM},
    {ATCMD_TOFF,     /*92*/         At_Toff,               0, "stop ongoing RF test", AT_TOFF_PERM},
    {ATCMD_CERTIF,   /*84*/         At_Certif,             0, "set the module in LoraWAN certification mode (0 = normal mode, 1 = certification mode)", AT_CERTIF_PERM},
    {ATCMD_CW,       /*90*/         At_Cw,                 0, "start continuous wave", AT_CW_PERM}
#endif
/* Miscellaneous Command */
    //{ATCMD_DELBONDS, /*76*/         At_DelBLEBonds,        0, "delete all BLE bond information from flash memory", },
#else
/* Bootloader */
    {ATCMD_BOOTSTATUS ,             At_Bootstatus,         0, "get the status of the bootloader", AT_BOOTSTATUS_PERM},
#endif

};

uint32_t At_CmdGetTotalNum (void)
{
    return sizeof(atcmd_info_tbl)/sizeof(at_cmd_info);
}

#ifndef RUI_BOOTLOADER
at_cmd_cust_info atcmd_cust_tbl[ATCMD_CUST_TABLE_SIZE];
#endif

static int At_CmdList (SERIAL_PORT port, stParam *param)
{
    int i = 0;
    char * perm = "NULL";
    atcmd_printf("\r\n");
    int num = sizeof(atcmd_info_tbl)/sizeof(at_cmd_info);
    for(i = 0;i<num;i++)
    {
        if(strlen(atcmd_info_tbl[i].CmdUsage)) {
            if (atcmd_info_tbl[i].permission & ATCMD_PERM_DISABLE)
                perm = "Disable";
            else if (atcmd_info_tbl[i].permission & ATCMD_PERM_WRITEONCEREAD)
                perm = "R*";
            else
                if (atcmd_info_tbl[i].permission & ATCMD_PERM_READ)
                    if (atcmd_info_tbl[i].permission & ATCMD_PERM_WRITE)
                        perm = "RW";
                    else
                        perm = "R";
                else if (atcmd_info_tbl[i].permission & ATCMD_PERM_WRITE)
                    perm = "W";
            atcmd_printf("%s,%s: %s\r\n", atcmd_info_tbl[i].atCmd, perm, atcmd_info_tbl[i].CmdUsage);
        }
    }
#ifndef RUI_BOOTLOADER
    for(i = 0;i<ATCMD_CUST_TABLE_SIZE;i++)
    {
        if (atcmd_cust_tbl[i].atCmd != NULL) {
            uint8_t cust_atcmd_buff[CLI_BUFFER_SIZE+4];

            sprintf(cust_atcmd_buff, "%s%s", "ATC+", atcmd_cust_tbl[i].atCmd);

            if( strlen(atcmd_cust_tbl[i].CmdUsage)) {
                if (atcmd_cust_tbl[i].permission & ATCMD_PERM_DISABLE)
                    perm = "Disable";
            else if (atcmd_cust_tbl[i].permission & ATCMD_PERM_WRITEONCEREAD)
                perm = "R*";
            else
                if (atcmd_cust_tbl[i].permission & ATCMD_PERM_READ)
                    if (atcmd_cust_tbl[i].permission & ATCMD_PERM_WRITE)
                        perm = "RW";
                    else
                        perm = "R";
                else if (atcmd_cust_tbl[i].permission & ATCMD_PERM_WRITE)
                    perm = "W";
            atcmd_printf("%s,%s: %s, %s\r\n", cust_atcmd_buff, perm, atcmd_cust_tbl[i].title, atcmd_cust_tbl[i].CmdUsage);
            }
        }
    }
#endif

    return AT_OK;
}

int At_Parser (SERIAL_PORT port, char *buff, int len)
{
    int i, j, help = 0;
    int	nRet = AT_ERROR;
    int is_write = 0;
    char cmd[MAX_CMD_LEN], operat = 0; //cmd len 32 should be enough
    stParam param;

#if 0
    //FIXME: array index is out of bound
    buff[len] = 0x0;  //chomp!! replace \r\n with null string
    len++;
#endif

    memset(&param, 0, sizeof(stParam));
    if( (1==len) && (buff[0]=='\r' || buff[0]=='\n')){
        nRet = AT_OK;
        goto exit;
    }
    
    if (0 == len) {
        atcmd_printf("\r\n%s\r\n", atcmd_err_tbl[AT_PARAM_ERROR]);
        return AT_PARAM_ERROR;
    }

    for(i = 0; i < MAX_CMD_LEN; i++)
    {
        if(buff[i] == '\0' || buff[i] == '=' || buff[i] == ' ')
        {
            memcpy(cmd, buff, i);
            operat = buff[i];
            cmd[i] = '\0';
            break;
        }
    }
    if (i == MAX_CMD_LEN)  //AT command len exceed MAX_CMD_LEN
    {
        nRet = AT_ERROR;
        goto exit_rsp;
    }

    if (cmd[i-1] == '?') {
        help = 1;
	cmd[i-1] = '\0';
    }

    for(i = 0; i < sizeof(atcmd_info_tbl)/sizeof(at_cmd_info); i++)
    {
#if 0
        atcmd_printf("atCmd = %s\r\n", atcmd_info_tbl[i].atCmd);
        atcmd_printf("buff=%s\r\n",buff);
        atcmd_printf("cmd=%s\r\n",cmd);
        atcmd_printf("strlen=%d\r\n",strlen(atcmd_info_tbl[i].atCmd));
#endif

        //if(strncasecmp(atcmd_info_tbl[i].atCmd, cmd, strlen(atcmd_info_tbl[i].atCmd)) == 0)    
        if(strcasecmp(atcmd_info_tbl[i].atCmd, cmd) == 0)
        {
            if(operat != 0)
                parseBuff2Param(buff + strlen(atcmd_info_tbl[i].atCmd) + 1, &param, atcmd_info_tbl[i].maxargu);

            if (help) {
                if (i == 0) {//Attention AT Command
                    atcmd_printf("\r\nAT+<CMD>?: help on <CMD>\r\nAT+<CMD>: run <CMD>\r\nAT+<CMD>=<value>: set the value\r\nAT+<CMD>=?: get the value\r\n");
                    //followed by the help of all commands:
                    At_CmdList(port, &param);
		} else {
                    atcmd_printf("%s: %s\r\n", atcmd_info_tbl[i].atCmd, atcmd_info_tbl[i].CmdUsage);
		}
		nRet = AT_OK;
            } else {
                if (atcmd_info_tbl[i].permission & ATCMD_PERM_DISABLE)
                {
                    nRet = AT_ERROR;
                    goto exit_rsp;
                } 
                if (!strcmp(param.argv[0], "?") && !(atcmd_info_tbl[i].permission & (ATCMD_PERM_READ | ATCMD_PERM_WRITEONCEREAD)))
                {
                    nRet = AT_ERROR;
                    goto exit_rsp;
                }
                else if (strcmp(param.argv[0], "?"))
                {
                    is_write = 1;
                    if (atcmd_info_tbl[i].permission & ATCMD_PERM_WRITEONCEREAD)
                    {
                        if (atcmd_info_tbl[i].permission & ATCMD_PERM_ISWRITE)
                        {
                            nRet = AT_ERROR;
                            goto exit_rsp;
                        }
                    }
                    else if (!(atcmd_info_tbl[i].permission & ATCMD_PERM_WRITE))
                    {
                        nRet = AT_ERROR;
                        goto exit_rsp;
                    }
                }
                nRet = atcmd_info_tbl[i].pfHandle(port, atcmd_info_tbl[i].atCmd, &param);
                if ((nRet == AT_OK) && (atcmd_info_tbl[i].permission & ATCMD_PERM_WRITEONCEREAD))
                    if (!(atcmd_info_tbl[i].permission & ATCMD_PERM_ISWRITE) && is_write)
                        atcmd_info_tbl[i].permission |= ATCMD_PERM_ISWRITE;
            }
            goto exit_rsp;
        }
    }

#ifndef RUI_BOOTLOADER
    for(j = 0; j < ATCMD_CUST_TABLE_SIZE ; j++)
    {
        if (atcmd_cust_tbl[j].atCmd != NULL) {
            if((strncasecmp("ATC+", cmd, 4) == 0) && (strcasecmp(atcmd_cust_tbl[j].atCmd, cmd+4) == 0))
            {
                uint8_t cust_atcmd_buff[CLI_BUFFER_SIZE+4];

                if(operat != 0)
                    parseBuff2Param(buff + 4 + strlen(atcmd_cust_tbl[j].atCmd) + 1, &param, atcmd_cust_tbl[j].maxargu);

                sprintf(cust_atcmd_buff, "%s%s", "ATC+", atcmd_cust_tbl[j].atCmd);

                if (help) {
                    atcmd_printf("%s: %s\r\n", cust_atcmd_buff, atcmd_cust_tbl[j].CmdUsage);
	            nRet = AT_OK;
                } else {
                    if (atcmd_cust_tbl[j].permission & ATCMD_PERM_DISABLE)
                    {
                        nRet = AT_ERROR;
                        goto exit_rsp;
                    }
                    if (!strcmp(param.argv[0], "?") && !(atcmd_cust_tbl[j].permission & (ATCMD_PERM_READ | ATCMD_PERM_WRITEONCEREAD)))
                    {
                        nRet = AT_ERROR;
                        goto exit_rsp;
                    }
                    else if (strcmp(param.argv[0], "?"))
                    {
                        is_write = 1;
                        if (atcmd_cust_tbl[j].permission & ATCMD_PERM_WRITEONCEREAD)
                        {
                            if (atcmd_cust_tbl[j].permission & ATCMD_PERM_ISWRITE)
                            {
                                nRet = AT_ERROR;
                                goto exit_rsp;
                            }
                        }
                        else if (!(atcmd_cust_tbl[j].permission & ATCMD_PERM_WRITE))
                        {
                            nRet = AT_ERROR;
                            goto exit_rsp;
                        }
                    }
                    nRet = atcmd_cust_tbl[j].pfHandle(port, cust_atcmd_buff, &param);
                    if ((nRet == AT_OK) && (atcmd_cust_tbl[j].permission & ATCMD_PERM_WRITEONCEREAD))
                        if (!(atcmd_cust_tbl[j].permission & ATCMD_PERM_ISWRITE) && is_write)
                            atcmd_cust_tbl[j].permission |= ATCMD_PERM_ISWRITE;
                }
                goto exit_rsp;
            }
        }
    }
#endif

exit_rsp:
    if (nRet < sizeof(atcmd_err_tbl)/sizeof(char *)) {
        atcmd_printf("%s", atcmd_err_tbl[nRet]);
    } else {
        atcmd_printf("%s", atcmd_err_tbl[1]);
    }

    if (i == sizeof(atcmd_info_tbl)/sizeof(at_cmd_info)
#ifndef RUI_BOOTLOADER
		    && j == ATCMD_CUST_TABLE_SIZE
#endif
		    ) {
        atcmd_printf("\r\n%s: Command not found!!", cmd);
    }
exit:
    return nRet;
}

#ifndef RUI_BOOTLOADER
void StrToHex(uint8_t *pbDest, const char *pbSrc, int nLen)
{
    char h1,h2;
    char s1,s2;
    int i;

    for (i=0; i<nLen/2; i++)
    {
        h1 = pbSrc[2*i];
        h2 = pbSrc[2*i+1];

        s1 = toupper(h1) - 0x30;
        if (s1 > 9)
            s1 -= 7;

        s2 = toupper(h2) - 0x30;
        if (s2 > 9)
            s2 -= 7;
        pbDest[i] = s1*16 + s2;
    }

}

uint8_t at_check_hex_param(const char *p_str, uint32_t str_len, uint8_t *p_hex)
{
    uint32_t len = strlen(p_str);
    uint16_t i;

    /* Length verification */
    if ((len != str_len) || (len%2 != 0))
        return 1;

    /* Hex check */
    for (i=0; i<len; i++)   // hex string check
    {
        if (!isxdigit(p_str[i]))
            return 1;
    }

    /* String to hex */
    if (p_hex != NULL)
        StrToHex(p_hex, p_str, len);

    return 0;
}

uint8_t at_check_alphanumeric_param(const char *p_str, uint32_t str_len)
{
    uint32_t len = strlen(p_str);
    uint32_t i;

    /* Length verification */
    if (len != str_len)
        return 1;

    /* Hex check */
    for (i=0; i<len; i++)
    {
        if (!isalnum(p_str[i])) // check if character is alphanumeric
            return 1;
    }

    return 0;
}

uint8_t at_check_hex_uint16(const char *p_str, uint16_t *value)
{
    uint8_t val[2];

    if (0 != at_check_hex_param(p_str, 4, val))
        return 1;

    *value = val[0]<<8 | val[1];

    return 0;
}

uint8_t at_check_hex_uint32(const char *p_str, uint32_t *value)
{
    uint8_t val[4];

    if (0 != at_check_hex_param(p_str, 8, val))
        return 1;

    *value = val[0]<<24 | val[1]<<16 | val[2]<<8 | val[3];

    return 0;
}

uint8_t at_check_digital_uint32_t(const char *p_str, uint32_t *value)
{
#define MAXIMUM_NB_DIGITS 10
    uint32_t digit;
    uint32_t str_len = strlen(p_str);

    if (str_len > MAXIMUM_NB_DIGITS)
        return 1;

    if(strspn(p_str, "0123456789")!=strlen(p_str))
        return 1;
        
    digit = atoi(p_str);
    if (digit == 0)
    {
        if (str_len == 1)
        {
            if (value != NULL)
                *value = 0;
            return 0;
        }
        else
            return 1;
    }

    for (uint8_t i=0; i<MAXIMUM_NB_DIGITS; i++)
    {
        uint32_t tmp = digit/pow(10, i);
        if (tmp != 0)
        {
            continue;
        }
        else
        {
            if (str_len != i)
                return 1;
            break;
        }
    }

    if (value != NULL)
        *value = digit;
    return 0;
}


void update_permisssion()
{
    atcmd_permission_item item;
    int i,j;
    int items = atcmd_queue_utilization_get();
    if (!atcmd_queue_is_empty())
    {
        for (j = 0; j < items; j++)
        {
            atcmd_queue_pop(&item,j);
            for(i = 0; i < sizeof(atcmd_info_tbl)/sizeof(at_cmd_info); i++)
                if(strcasecmp(atcmd_info_tbl[i].atCmd, item.atcmd_id) == 0)
                    atcmd_info_tbl[i].permission = item.permission;
        }
    }
}

#endif
