#ifndef __SERVICE_MODE_PROTO_BUILTIN_HANDLER_H__
#define __SERVICE_MODE_PROTO_BUILTIN_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

//standard libary include
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum SERVICE_MODE_PROTO_ATCMD_ID_ {
/* General Command */
    SERVICE_MODE_PROTO_ATCMD_ATTENTION = 0,   /*0*/
    SERVICE_MODE_PROTO_ATCMD_REBOOT    = 1,   /*1*/
    SERVICE_MODE_PROTO_ATCMD_ATR       = 3,   /*3*/
    SERVICE_MODE_PROTO_ATCMD_BOOT      = 4,   /*4*/
    SERVICE_MODE_PROTO_ATCMD_SN        = 87,  /*87*/
    SERVICE_MODE_PROTO_ATCMD_BAT       = 15,  /*15*/
    SERVICE_MODE_PROTO_ATCMD_BUILDTIME = 5,   /*5*/
    SERVICE_MODE_PROTO_ATCMD_REPOINFO  = 6,   /*6*/
    SERVICE_MODE_PROTO_ATCMD_FWVER     = 7,   /*7*/
    SERVICE_MODE_PROTO_ATCMD_CUSFWVER  = 96,   /*96*/
    SERVICE_MODE_PROTO_ATCMD_CLIVER    = 8,   /*8*/
    SERVICE_MODE_PROTO_ATCMD_APIVER    = 9,   /*9*/
    SERVICE_MODE_PROTO_ATCMD_HWMODEL   = 13,  /*13*/
    SERVICE_MODE_PROTO_ATCMD_HWID      = 14,  /*14*/
    SERVICE_MODE_PROTO_ATCMD_ALIAS     = 89,  /*89*/
    SERVICE_MODE_PROTO_ATCMD_SYSV      = 92,  /*92*/
    //SERVICE_MODE_PROTO_ATCMD_UID       = 91,  /*91*/
    SERVICE_MODE_PROTO_ATCMD_BLEMAC    = 94,  /*94*/
    SERVICE_MODE_PROTO_ATCMD_BOOTVER   = 95,  /*95*/
/* Sleep Command */
    SERVICE_MODE_PROTO_ATCMD_SLEEP     = 85,  /*85*/
    SERVICE_MODE_PROTO_ATCMD_AUTOSLEEP = 86,  /*86*/
/* Serial Port Command */
    SERVICE_MODE_PROTO_ATCMD_LOCK      = 10,  /*10*/
    SERVICE_MODE_PROTO_ATCMD_PWORD     = 11,  /*11*/
    SERVICE_MODE_PROTO_ATCMD_BAUD      = 12,  /*12*/
    SERVICE_MODE_PROTO_ATCMD_ATM       = 72,  /*72*/
    SERVICE_MODE_PROTO_ATCMD_APM       = 73,  /*73*/
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
    SERVICE_MODE_PROTO_ATCMD_PAM       = 74,  /*74*/
#endif
/* LoRaWAN Keys and IDs */
    SERVICE_MODE_PROTO_ATCMD_APPEUI    = 16,  /*16*/
    SERVICE_MODE_PROTO_ATCMD_APPKEY    = 17,  /*17*/
    SERVICE_MODE_PROTO_ATCMD_APPSKEY   = 18,  /*18*/
    SERVICE_MODE_PROTO_ATCMD_DADDR     = 19,  /*19*/
    SERVICE_MODE_PROTO_ATCMD_DEUI      = 20,  /*20*/
    SERVICE_MODE_PROTO_ATCMD_NETID     = 21,  /*21*/
    SERVICE_MODE_PROTO_ATCMD_NWKSKEY   = 22,  /*22*/
/* LoRaWAN Joining and Sending */
    SERVICE_MODE_PROTO_ATCMD_CFM       = 23,  /*23*/
    SERVICE_MODE_PROTO_ATCMD_CFS       = 24,  /*24*/
    SERVICE_MODE_PROTO_ATCMD_JOIN      = 25,  /*25*/
    SERVICE_MODE_PROTO_ATCMD_NJM       = 26,  /*26*/
    SERVICE_MODE_PROTO_ATCMD_NJS       = 27,  /*27*/
    SERVICE_MODE_PROTO_ATCMD_RECV      = 28,  /*28*/
    SERVICE_MODE_PROTO_ATCMD_SEND      = 29,  /*29*/
    SERVICE_MODE_PROTO_ATCMD_LPSEND    = 83,  /*83*/
    //SERVICE_MODE_PROTO_ATCMD_USEND     = ??,  /*??*/
    SERVICE_MODE_PROTO_ATCMD_RETY      = 30,  /*30*/
/* LoRaWAN Network Management */
    SERVICE_MODE_PROTO_ATCMD_ADR       = 31,  /*31*/
    SERVICE_MODE_PROTO_ATCMD_CLASS     = 32,  /*32*/
    SERVICE_MODE_PROTO_ATCMD_DCS       = 33,  /*33*/
    SERVICE_MODE_PROTO_ATCMD_DR        = 34,  /*34*/
    SERVICE_MODE_PROTO_ATCMD_JN1DL     = 35,  /*35*/
    SERVICE_MODE_PROTO_ATCMD_JN2DL     = 36,  /*36*/
    SERVICE_MODE_PROTO_ATCMD_PNM       = 37,  /*37*/
    SERVICE_MODE_PROTO_ATCMD_RX1DL     = 38,  /*38*/
    SERVICE_MODE_PROTO_ATCMD_RX2DL     = 39,  /*39*/
    SERVICE_MODE_PROTO_ATCMD_RX2DR     = 40,  /*40*/
    SERVICE_MODE_PROTO_ATCMD_RX2FQ     = 41,  /*41*/
    SERVICE_MODE_PROTO_ATCMD_TXP       = 42,  /*42*/
    SERVICE_MODE_PROTO_ATCMD_LINKCHECK = 43,  /*43*/
/* LoRaWAN Class B */
    SERVICE_MODE_PROTO_ATCMD_PGSLOT    = 44,  /*44*/
    SERVICE_MODE_PROTO_ATCMD_BFREQ     = 45,  /*45*/
    SERVICE_MODE_PROTO_ATCMD_BTIME     = 46,  /*46*/
    SERVICE_MODE_PROTO_ATCMD_BGW       = 47,  /*47*/
    SERVICE_MODE_PROTO_ATCMD_LTIME     = 48,  /*48*/
/* LoRaWAN Information */
    SERVICE_MODE_PROTO_ATCMD_RSSI      = 49,  /*49*/
    SERVICE_MODE_PROTO_ATCMD_ARSSI     = 75,  /*75*/
    SERVICE_MODE_PROTO_ATCMD_SNR       = 50,  /*50*/
/* Supplementary Command */
    SERVICE_MODE_PROTO_ATCMD_MASK      = 51,  /*51*/
    SERVICE_MODE_PROTO_ATCMD_CHE       = 52,  /*52*/
    SERVICE_MODE_PROTO_ATCMD_CHS       = 53,  /*53*/
    SERVICE_MODE_PROTO_ATCMD_BAND      = 54,  /*54*/
/* LoRaWAN P2P */
    SERVICE_MODE_PROTO_ATCMD_NWM       = 55,  /*55*/
    SERVICE_MODE_PROTO_ATCMD_PFREQ     = 56,  /*56*/
    SERVICE_MODE_PROTO_ATCMD_PSF       = 57,  /*57*/
    SERVICE_MODE_PROTO_ATCMD_PBW       = 58,  /*58*/
    SERVICE_MODE_PROTO_ATCMD_PCR       = 59,  /*59*/
    SERVICE_MODE_PROTO_ATCMD_PPL       = 60,  /*60*/
    SERVICE_MODE_PROTO_ATCMD_PTP       = 61,  /*61*/
    SERVICE_MODE_PROTO_ATCMD_PSEND     = 62,  /*62*/
    SERVICE_MODE_PROTO_ATCMD_PRECV     = 63,  /*63*/
    SERVICE_MODE_PROTO_ATCMD_PCRYPT    = 64,  /*64*/
    SERVICE_MODE_PROTO_ATCMD_PKEY      = 65,  /*65*/
    SERVICE_MODE_PROTO_ATCMD_P2P       = 66,  /*66*/
    SERVICE_MODE_PROTO_ATCMD_PBR       = 67,  /*67*/
    SERVICE_MODE_PROTO_ATCMD_PFDEV     = 68,  /*68*/
/* LoRaWAN Multicast Group */
    SERVICE_MODE_PROTO_ATCMD_ADDMULC   = 69,  /*69*/
    SERVICE_MODE_PROTO_ATCMD_RMVMULC   = 70,  /*70*/
    SERVICE_MODE_PROTO_ATCMD_LSTMULC   = 71,  /*71*/
/* LoRaWAN RF Test */
    //SERVICE_MODE_PROTO_ATCMD_TRSSI     = 77,  /*77*/
    //SERVICE_MODE_PROTO_ATCMD_TTONE     = 78,  /*78*/
    //SERVICE_MODE_PROTO_ATCMD_TTX       = 79,  /*79*/
    //SERVICE_MODE_PROTO_ATCMD_TRX       = 80,  /*80*/
    //SERVICE_MODE_PROTO_ATCMD_TCONF     = 81,  /*81*/
    //SERVICE_MODE_PROTO_ATCMD_TTH       = 82,  /*82*/
    //SERVICE_MODE_PROTO_ATCMD_TOFF      = 92,  /*92*/
    //SERVICE_MODE_PROTO_ATCMD_CERTIF    = 84,  /*84*/
    //SERVICE_MODE_PROTO_ATCMD_CW        = 90,  /*90*/
#endif
/* Miscellaneous Command */
    //SERVICE_MODE_PROTO_ATCMD_DELBONDS  = 76,  /*76*/
} SERVICE_MODE_PROTO_ATCMD_ID;

#define PROTO_ATCMD_FLAG_RESPONSE           0x01
#define PROTO_ATCMD_FLAG_WR_OR_EXE          0x02
#define PROTO_ATCMD_FLAG_ERROR              0x04
#define PROTO_ATCMD_FLAG_MORE_DATA          0x08

typedef struct proto_atcmd_header_{
    uint16_t length;
    uint8_t flag;
    uint8_t atcmd_id;
} __attribute__ ((packed)) proto_atcmd_header;

void service_mode_proto_echo_request_handler (SERIAL_PORT port, uint8_t *payload, uint16_t length);

void service_mode_proto_echo_response_handler (SERIAL_PORT port, uint8_t *payload, uint16_t length);

void service_mode_proto_atcmd_request_handler (SERIAL_PORT port, uint8_t *payload, uint16_t length);

void service_mode_proto_atcmd_response_handler (SERIAL_PORT port, uint8_t *payload, uint16_t length);

#ifdef __cplusplus
}
#endif

#endif /* __SERVICE_MODE_PROTO_BUILTIN_HANDLER_H__ */

