/**@file	RAKNfc.h
 *
 * @brief
 * @author	RAKwireless
 * @version	0.1.0
 * @data	2021.11
 */
#ifndef	__RAKNFC_H__
#define	__RAKNFC_H__

#ifdef SUPPORT_NFC

#include "udrv_nfc.h"
#include <stdint.h> 

typedef enum _RAK_NFC_RECORD_TYPE
{
  TXT = 0,  ///< TXT
  URI = 1,  ///< URI
  APP = 2,  ///< Launch app
} RAK_NFC_RECORD_TYPE;

typedef enum
{
    RAK_NFC_URI_NONE          = 0x00,  /**< No prepending is done. */
    RAK_NFC_URI_HTTP_WWW      = 0x01,  /**< "http://www." */
    RAK_NFC_URI_HTTPS_WWW     = 0x02,  /**< "https://www." */
    RAK_NFC_URI_HTTP          = 0x03,  /**< "http:" */
    RAK_NFC_URI_HTTPS         = 0x04,  /**< "https:" */
    RAK_NFC_URI_TEL           = 0x05,  /**< "tel:" */
    RAK_NFC_URI_MAILTO        = 0x06,  /**< "mailto:" */
    RAK_NFC_URI_FTP_ANONYMOUS = 0x07,  /**< "ftp://anonymous:anonymous@" */
    RAK_NFC_URI_FTP_FTP       = 0x08,  /**< "ftp://ftp." */
    RAK_NFC_URI_FTPS          = 0x09,  /**< "ftps://" */
    RAK_NFC_URI_SFTP          = 0x0A,  /**< "sftp://" */
    RAK_NFC_URI_SMB           = 0x0B,  /**< "smb://" */
    RAK_NFC_URI_NFS           = 0x0C,  /**< "nfs://" */
    RAK_NFC_URI_FTP           = 0x0D,  /**< "ftp://" */
    RAK_NFC_URI_DAV           = 0x0E,  /**< "dav://" */
    RAK_NFC_URI_NEWS          = 0x0F,  /**< "news:" */
    RAK_NFC_URI_TELNET        = 0x10,  /**< "telnet://" */
    RAK_NFC_URI_IMAP          = 0x11,  /**< "imap:" */
    RAK_NFC_URI_RTSP          = 0x12,  /**< "rtsp://" */
    RAK_NFC_URI_URN           = 0x13,  /**< "urn:" */
    RAK_NFC_URI_POP           = 0x14,  /**< "pop:" */
    RAK_NFC_URI_SIP           = 0x15,  /**< "sip:" */
    RAK_NFC_URI_SIPS          = 0x16,  /**< "sips:" */
    RAK_NFC_URI_TFTP          = 0x17,  /**< "tftp:" */
    RAK_NFC_URI_BTSPP         = 0x18,  /**< "btspp://" */
    RAK_NFC_URI_BTL2CAP       = 0x19,  /**< "btl2cap://" */
    RAK_NFC_URI_BTGOEP        = 0x1A,  /**< "btgoep://" */
    RAK_NFC_URI_TCPOBEX       = 0x1B,  /**< "tcpobex://" */
    RAK_NFC_URI_IRDAOBEX      = 0x1C,  /**< "irdaobex://" */
    RAK_NFC_URI_FILE          = 0x1D,  /**< "file://" */
    RAK_NFC_URI_URN_EPC_ID    = 0x1E,  /**< "urn:epc:id:" */
    RAK_NFC_URI_URN_EPC_TAG   = 0x1F,  /**< "urn:epc:tag:" */
    RAK_NFC_URI_URN_EPC_PAT   = 0x20,  /**< "urn:epc:pat:" */
    RAK_NFC_URI_URN_EPC_RAW   = 0x21,  /**< "urn:epc:raw:" */
    RAK_NFC_URI_URN_EPC       = 0x22,  /**< "urn:epc:" */
    RAK_NFC_URI_URN_NFC       = 0x23,  /**< "urn:nfc:" */
    RAK_NFC_URI_RFU           = 0xFF   /**< No prepending is done. Reserved for future use. */
} RAK_NFC_URI_ID;

typedef enum
{
   RAK_NFC_T4T_EVENT_NONE,
   RAK_NFC_T4T_EVENT_FIELD_ON,
   RAK_NFC_T4T_EVENT_FIELD_OFF,
   RAK_NFC_T4T_EVENT_NDEF_READ,
   RAK_NFC_T4T_EVENT_NDEF_UPDATED,
   RAK_NFC_T4T_EVENT_DATA_TRANSMITTED,
   RAK_NFC_T4T_EVENT_DATA_IND,
} RAK_NFC_T4T_EVENT;

typedef void (*rak_nfc_t4t_callback)(void              * p_context,
                                     RAK_NFC_T4T_EVENT  event,
                                     const uint8_t     * p_data,
                                     size_t              data_size,
                                     uint32_t            flags);


class RAKNfc
{
  public:
    RAKNfc(void);

    void send(RAK_NFC_RECORD_TYPE record_type, RAK_NFC_URI_ID uri_type, const uint8_t* payload, uint32_t size);

    /**@addtogroup	NFC
     * @{
     */

    /**@par	Description
     *		The initialization of NFC
     * @par	Syntax
      		api.nfc.init(wakeup, atMode, callback)
     * @param	wakeup	The bool is whether to use an interrupt to wake from sleep and passing a callback function with different states
     * @param   atMode  whether to use AT-Commnad over NFC(the tag will be changed to result of the command)
     * @param	callback	the callback funcation for nfc 
     * @return	void
     * @par Example
     * @verbatim
     static void nfc_t4t_callback(void * p_context, RAK_NFC_T4T_EVENT event, const uint8_t * p_data, size_t data_length, uint32_t flags)
     {
         (void)p_context;
     }

     void setup()
     {
         static const uint8_t language[] = {'e', 'n'};
         static const uint8_t paylaod[] = {'H', 'e', 'l', 'l', 'o', ' ', 'N', 'F','C'}

         api.nfc.init(true, false, nfc_t4t_callback);
         api.nfc_send(TXT, language, sizeof(language), paylaod, sizeof(payload));
     }

     void loop()
     {
         api.system.sleep.all(30000);
     }
     @endverbatim
     */
    void init(bool wakeup, bool atMode,rak_nfc_t4t_callback callback);

    /**@par	Description
     *		This api allows to send TXT,URI or APP message as a NFC tag
     * @note There are three types of NFC message TXT, URI and APP. 
     *       Ecah paramters of the types has diffenent meaning. \n
     *       Please follow the Syntax to use this API.       
     *
     * @par	Syntax
     * 		api.nfc.send(TXT, language, language_size, txt_payload, txt_size) \n
     * 		api.nfc.send(APP, ,android_package_name android_size, windows_application_id, windows_size) \n
     * 		api.nfc.send(URL, RAK_NFC_URI_ID, url_payload, url_size)
     * @param	type		                the message is a TXT, URI or APP message
     * @param   language                    language of TXT message (must be 2 bytes)
     * @param   language_size               size of language (must be 2)
     * @param   payload                     paylaod of TXT message (1~244 bytes)
     * @param   paylaod_size                size of TXT message (1~244) \n
     * @param   android_package_name        android package name 
     * @param   android_size                size of android of android package name
     * @param   windows_application_id      windows applicaiton id 
     * @param   windows_size                size of windows application id \n
     * @param   RAK_NFC_URI_ID              Enum of URI ID 
     * @param   url_payload                 url of a URI message (1~246bytes)
     * @param   url_size                    size of the url (1~246)
     * @return	void
     * @par Example
     * @verbatim
     static void nfc_t4t_callback(void * p_context, RAK_NFC_T4T_EVENT event, const uint8_t * p_data, size_t data_length, uint32_t flags)
     {
         (void)p_context;
     }

     void setup()
     {
         static const uint8_t language[] = {'e', 'n'};
         static const uint8_t paylaod[] = {'H', 'e', 'l', 'l', 'o', ' ', 'N', 'F','C'}

         api.nfc.init(true, false, nfc_t4t_callback);
         api.nfc_send(TXT, language, sizeof(language), paylaod, sizeof(payload));
     }

     void loop()
     {
         api.system.sleep.all(30000);
     }
     @endverbatim
     */
    void send(RAK_NFC_RECORD_TYPE record_type, const uint8_t* payload1, uint32_t size1, const uint8_t* payload2, uint32_t size2);

    /**@par	Description
     *		This api will disable nfc and any interrupts created for it
     * @par	Syntax
     * 		api.nfc.close()
     *
     * @return	void
     * @par Example
     * @verbatim
     static void nfc_t4t_callback(void * p_context, RAK_NFC_T4T_EVENT event, const uint8_t * p_data, size_t data_length, uint32_t flags)
     {
         (void)p_context;
     }

     void setup()
     {
         static const uint8_t language[] = {'e', 'n'};
         static const uint8_t paylaod[] = {'H', 'e', 'l', 'l', 'o', ' ', 'N', 'F','C'}

         api.nfc.init(true, false, nfc_t4t_callback);
         api.nfc_send(TXT, language, sizeof(language), paylaod, sizeof(payload));
     }

     void loop()
     {
         if(millis() > 60000) 
             api.nfc.close();
         api.system.sleep.all(30000);
     }
     @endverbatim
     */
    void close();

    /**@}*/
};

#endif

#endif	//end RAKNfc.h
