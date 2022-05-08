#ifndef __RAK_SYSTEM_H__
#define __RAK_STSTEM_H__

#include "WString.h"

#include "sleep.h"
#include "atcmd.h"
#include "udrv_errno.h"
#include "udrv_system.h"
#include "udrv_serial.h"
#include "udrv_delay.h"
#include "service_mode_cli.h"
#include "service_battery.h"
#include "service_nvm.h"
#ifdef SUPPORT_FS
#include "service_fs.h"
#endif

using namespace std;

/**@addtogroup	RUI_System_Data_Type
 * @{
 */

/**@par	Description
 * 	The ID of timer
 */
typedef enum {
    RAK_TIMER_0 = TIMER_0,	///< timer ID #0
    RAK_TIMER_1 = TIMER_1,	///< timer ID #1
    RAK_TIMER_2 = TIMER_2,	///< timer ID #2
    RAK_TIMER_3 = TIMER_3,	///< timer ID #3
    RAK_TIMER_4 = TIMER_4,	///< timer ID #4
    RAK_TIMER_ID_MAX = TIMER_ID_MAX,	///< this is the number of all available timers
} RAK_TIMER_ID;

/**@par	Description
 * 	The handler function of timer
 */
typedef void (*RAK_TIMER_HANDLER) (void *data);

typedef enum {
    RAK_TIMER_ONESHOT = HTMR_ONESHOT,	///< This timer is only triggered one time
    RAK_TIMER_PERIODIC = HTMR_PERIODIC,	///< This timer is triggered periodically
} RAK_TIMER_MODE;

/**@par	Description
 * 	The permission setting of AT command
 */
/* ATCMD PERMISSION */
typedef enum {
    RAK_ATCMD_PERM_READ          = ATCMD_PERM_READ,             ///< Read permission allows for reading a variable data only and disables any write functionality.
    RAK_ATCMD_PERM_WRITE         = ATCMD_PERM_WRITE,            ///< Write permission allows for writting a variable data only and disables any read functionality.
    RAK_ATCMD_PERM_WRITEONCEREAD = ATCMD_PERM_WRITEONCEREAD,    ///< Special functionality that allows for setting variable once and only allows for reading after.
    RAK_ATCMD_PERM_DISABLE       = ATCMD_PERM_DISABLE,          ///< Disables the AT command from being used.
} RAK_AT_PERMISSION;

/**@}*/

/** @def CHANGE_ATCMD_PERM(ATCMD,ATCMD_PERMISSIONS);
     * @ingroup System_Misc
     * @brief change AT command permission

        PERMISSION LEVEL:\n
            RAK_ATCMD_PERM_READ,\n
            RAK_ATCMD_PERM_WRITE,\n
            RAK_ATCMD_PERM_WRITEONCEREAD,\n
            RAK_ATCMD_PERM_DISABLE\n
        AT commands' default permission are RAK_ATCMD_PERM_READ | RAK_ATCMD_PERM_WRITE
     * @par		Example
     * @verbatim
       CHANGE_ATCMD_PERM("AT+APPKEY", RAK_ATCMD_PERM_READ);
       CHANGE_ATCMD_PERM("AT+APPSKEY", RAK_ATCMD_PERM_WRITE);
       CHANGE_ATCMD_PERM("AT+DEVADDR", RAK_ATCMD_PERM_WRITEONCEREAD);
       CHANGE_ATCMD_PERM("AT+APPEUI", RAK_ATCMD_PERM_DISABLE);
       CHANGE_ATCMD_PERM("AT+NETID", RAK_ATCMD_PERM_READ | RAK_ATCMD_PERM_WRITE);
       CHANGE_ATCMD_PERM("AT+ALIAS", RAK_ATCMD_PERM_READ | RAK_ATCMD_PERM_WRITE);
       CHANGE_ATCMD_PERM("AT+HWID", RAK_ATCMD_PERM_READ | RAK_ATCMD_PERM_WRITE);

       void setup()
       {
       }

       void loop()
       {
       }
       @endverbatim
    */

#define CHANGE_ATCMD_PERM(_atcmd_name,_atcmd_perm)                 \
    ATCMD_ITEM(atcmd_queue, atcmd_permission_item UNIQUE_NAME(permissions)) =   \
    {                                       \
    .atcmd_id = _atcmd_name,                \
    .permission = _atcmd_perm,              \
    }

#ifdef SUPPORT_FS
/**@addtogroup	RUI_System_Data_Type
 * @{
 */

#define RAK_FS_OK                          SERVICE_FS_OK                       ///< (0) Succeeded
#define RAK_FS_ERR_NOT_MOUNTED             SERVICE_FS_ERR_NOT_MOUNTED          ///< FS_ERR NOT MOUNTED
#define RAK_FS_ERR_FULL                    SERVICE_FS_ERR_FULL                 ///< FS_ERR FULL
#define RAK_FS_ERR_NOT_FOUND               SERVICE_FS_ERR_NOT_FOUND            ///< FS_ERR NOT FOUND
#define RAK_FS_ERR_END_OF_OBJECT           SERVICE_FS_ERR_END_OF_OBJECT        ///< FS_ERR_END OF_OBJECT
#define RAK_FS_ERR_DELETED                 SERVICE_FS_ERR_DELETED              ///< FS_ERR DELETED
#define RAK_FS_ERR_NOT_FINALIZED           SERVICE_FS_ERR_NOT_FINALIZED        ///< FS_ERR NOT FINALIZED
#define RAK_FS_ERR_NOT_INDEX               SERVICE_FS_ERR_NOT_INDEX            ///< FS_ERR NOT INDEX
#define RAK_FS_ERR_OUT_OF_FILE_DESCS       SERVICE_FS_ERR_OUT_OF_FILE_DESCS    ///< FS_ERR OUT OF FILE DESCS
#define RAK_FS_ERR_FILE_CLOSED             SERVICE_FS_ERR_FILE_CLOSED          ///< FS_ERR FILE CLOSED
#define RAK_FS_ERR_FILE_DELETED            SERVICE_FS_ERR_FILE_DELETED         ///< FS_ERR FILE DELETED
#define RAK_FS_ERR_BAD_DESCRIPTOR          SERVICE_FS_ERR_BAD_DESCRIPTOR       ///< FS_ERR BAD DESCRIPTOR
#define RAK_FS_ERR_IS_INDEX                SERVICE_FS_ERR_IS_INDEX             ///< FS_ERR IS INDEX
#define RAK_FS_ERR_IS_FREE                 SERVICE_FS_ERR_IS_FREE              ///< FS_ERR IS FREE
#define RAK_FS_ERR_INDEX_SPAN_MISMATCH     SERVICE_FS_ERR_INDEX_SPAN_MISMATCH  ///< FS_ERR INDEX SPAN MISMATCH
#define RAK_FS_ERR_DATA_SPAN_MISMATCH      SERVICE_FS_ERR_DATA_SPAN_MISMATCH   ///< FS_ERR DATA SPAN MISMATCH
#define RAK_FS_ERR_INDEX_REF_FREE          SERVICE_FS_ERR_INDEX_REF_FREE       ///< FS_ERR INDEX REF FREE
#define RAK_FS_ERR_INDEX_REF_LU            SERVICE_FS_ERR_INDEX_REF_LU         ///< FS_ERR INDEX REF LU
#define RAK_FS_ERR_INDEX_REF_INVALID       SERVICE_FS_ERR_INDEX_REF_INVALID    ///< FS_ERR INDEX REF INVALID
#define RAK_FS_ERR_INDEX_FREE              SERVICE_FS_ERR_INDEX_FREE           ///< FS_ERR INDEX FREE
#define RAK_FS_ERR_INDEX_LU                SERVICE_FS_ERR_INDEX_LU             ///< FS_ERR INDEX LU
#define RAK_FS_ERR_INDEX_INVALID           SERVICE_FS_ERR_INDEX_INVALID        ///< FS_ERR INDEX INVALID
#define RAK_FS_ERR_NOT_WRITABLE            SERVICE_FS_ERR_NOT_WRITABLE         ///< FS_ERR NOT WRITABLE
#define RAK_FS_ERR_NOT_READABLE            SERVICE_FS_ERR_NOT_READABLE         ///< FS_ERR NOT READABLE
#define RAK_FS_ERR_CONFLICTING_NAME        SERVICE_FS_ERR_CONFLICTING_NAME     ///< FS_ERR CONFLICTING NAME
#define RAK_FS_ERR_NOT_CONFIGURED          SERVICE_FS_ERR_NOT_CONFIGURED       ///< FS_ERR NOT CONFIGURED
#define RAK_FS_ERR_NOT_A_FS                SERVICE_FS_ERR_NOT_A_FS             ///< FS_ERR_NOT A FS
#define RAK_FS_ERR_MOUNTED                 SERVICE_FS_ERR_MOUNTED              ///< FS_ERR MOUNTED
#define RAK_FS_ERR_ERASE_FAIL              SERVICE_FS_ERR_ERASE_FAIL           ///< FS_ERR ERASE FAIL
#define RAK_FS_ERR_MAGIC_NOT_POSSIBLE      SERVICE_FS_ERR_MAGIC_NOT_POSSIBLE   ///< FS_ERR MAGIC NOT POSSIBLE
#define RAK_FS_ERR_NO_DELETED_BLOCKS       SERVICE_FS_ERR_NO_DELETED_BLOCKS    ///< FS_ERR NO DELETED BLOCKS
#define RAK_FS_ERR_FILE_EXISTS             SERVICE_FS_ERR_FILE_EXISTS          ///< FS_ERR FILE EXISTS
#define RAK_FS_ERR_NOT_A_FILE              SERVICE_FS_ERR_NOT_A_FILE           ///< FS_ERR NOT A FILE
#define RAK_FS_ERR_RO_NOT_IMPL             SERVICE_FS_ERR_RO_NOT_IMPL          ///< FS_ERR RO NOT IMPL
#define RAK_FS_ERR_RO_ABORTED_OPERATION    SERVICE_FS_ERR_RO_ABORTED_OPERATION ///< FS_ERR RO ABORTED OPERATION
#define RAK_FS_ERR_PROBE_TOO_FEW_BLOCKS    SERVICE_FS_ERR_PROBE_TOO_FEW_BLOCKS ///< FS_ERR PROBE TOO FEW BLOCKS
#define RAK_FS_ERR_PROBE_NOT_A_FS          SERVICE_FS_ERR_PROBE_NOT_A_FS       ///< FS_ERR PROBE NOT A FS
#define RAK_FS_ERR_NAME_TOO_LONG           SERVICE_FS_ERR_NAME_TOO_LONG        ///< FS_ERR NAME TOO LONG
#define RAK_FS_ERR_IX_MAP_UNMAPPED         SERVICE_FS_ERR_IX_MAP_UNMAPPED      ///< FS_ERR IX MAP UNMAPPED
#define RAK_FS_ERR_IX_MAP_MAPPED           SERVICE_FS_ERR_IX_MAP_MAPPED        ///< FS_ERR IX MAP MAPPED
#define RAK_FS_ERR_IX_MAP_BAD_RANGE        SERVICE_FS_ERR_IX_MAP_BAD_RANGE     ///< FS_ERR IX MAP BAD RANGE
#define RAK_FS_ERR_SEEK_BOUNDS             SERVICE_FS_ERR_SEEK_BOUNDS          ///< FS_ERR SEEK BOUNDS
#define RAK_FS_ERR_INTERNAL                SERVICE_FS_ERR_INTERNAL             ///< FS_ERR INTERNAL
#define RAK_FS_ERR_TEST                    SERVICE_FS_ERR_TEST                 ///< FS_ERR TEST
#define RAK_FS_ERR_CONTINUE                SERVICE_FS_ERR_CONTINUE             ///< FS_ERR CONTINUE

/**@}*/
#endif

class RAKSystem {
  public:
    RAKSystem();
    class sleep sleep;

    class firmwareVersion {
      private:
        String ver;

      public:
        firmwareVersion();

	/**@par		Description
	 * 		This api allow user to get the firmware version
	 * @ingroup	Firmware_Version
	 * @par		Syntax
	 * 		api.system.firmwareVersion.get()
	 * @return	firmware version(Type: String)
	 * @par		Example
	 * @verbatim	
	   void setup()
	   {
	     Serial.begin(115200);
	   }

	   void loop()
	   {
             Serial.printf("Firmware Version: %s\r\n", api.system.firmwareVersion.get().c_str());
	     delay(1000);
	   }
	   @endverbatim
	 */
        const String get();
    };

    class cliVersion {
      private:
        String ver;

      public:
        cliVersion();

	/**@par		Description
	 *		This api allow user to get the cli version
	 * @ingroup	Cli_Version
	 * @par		Syntax
	 *		api.system.cliVersion.get()
	 * @return	cli version(Type: String)
	 * @par         Example
         * @verbatim
           void setup()
           {
             Serial.begin(115200);
           }

           void loop()
           {
             Serial.printf("AT Command Version: %s\r\n", api.system.cliVersion.get().c_str());
             delay(1000);
           }
           @endverbatim

	 */
        const String get();
    };

    class apiVersion {
      private:
        String ver;

      public:
        apiVersion();

	/**@par		Description
	 *		This api allow user to get the api version
	 * @ingroup	Api_Version
	 * @par		Syntax
	 * 		api.system.apiVersion.get()
	 * @return	api version(Type: String)
	 * @par         Example
         * @verbatim
           void setup()
           {
             Serial.begin(115200);
           }

           void loop()
           {
             Serial.printf("RUI API Version: %s\r\n", api.system.apiVersion.get().c_str());
             delay(1000);
           }
           @endverbatim

	 */
        const String get();
    };

    class modelId {
      private:
        String id;

      public:
        modelId();

	/**@par		Description
	 *		This api allow user to get the mode ID
	 * @ingroup	Model_ID
	 * @par		Syntax
	 * 		api.system.modelId.get()
	 * @return	model ID(Type: String)
	 * @par         Example
         * @verbatim
           void setup()
           {
             Serial.begin(115200);
           }

           void loop()
           {
             Serial.printf("Model ID: %s\r\n", api.system.modelId.get().c_str());
             delay(1000);
           }
           @endverbatim

	 */
        const String get();
    };

    class chipId {
      private:
        String id;

      public:
        chipId();

	/**@par		Description
	 *		This api allow user to get the chip ID
	 * @ingroup	Chip_ID
	 * @par		Syntax
	 *		api.system.chipId.get()
	 * @return	chip ID(Type: String)
	 * @par         Example
         * @verbatim
           void setup()
           {
             Serial.begin(115200);
           }

           void loop()
           {
             Serial.printf("Hardware ID: %s\r\n", api.system.chipId.get().c_str());
             delay(1000);
           }
           @endverbatim

	 */
        const String get();
    };
    
    firmwareVersion firmwareVersion;
    cliVersion cliVersion;
    apiVersion apiVersion;
    modelId modelId;
    chipId chipId;

    /**@par	Description
     *
     * @ingroup	System_Misc
     * @par	Syntax
     * 		api.system.reboot()
     * @return	void
     * @par	Example
     * @verbatim
       int loopCount == 0;

       void setup()
       {
       }

       void loop()
       {
         loopCount++;

         if(loopCount == 60)
           api.system.reboot();  // Reboot after 60 seconds 

         delay(1000);
       }
       @endverbatim 
     */
    void reboot();

    /**@par	Description
     *
     * @ingroup	System_Misc
     * @par	Syntax
     * 		api.system.restoreDefault()
     * @return	void
     * @par	Example
     * @verbatim
       void setup()
       {
         api.system.restoreDefault();
       }

       void loop()
       {
       }
       @endverbatim 
     */
    void restoreDefault();

    class pword {
      public:
	/**@par		Description
	 *		This api allow user to set a 1~8 digits password to lock the default serial
	 * @ingroup	System_Pword
	 * @par		Syntax
	 * 		api.system.pword.set(passwd_Str)\n
	 * 		api.system.pword.set(passwd_Char, len)
	 * @param	passwd_Str	the password to lock the Default Serial(Type: String)
	 * @param	passwd_Char	the password to lock the Default Serial(Type: cahr *)
	 * @param	len		the length of passwod
	 * @return	bool
	 * @retval	TRUE for successfully set a password
	 * @retval	FALSE for set a password failure
	 * @par		Example
	 * @verbatim
	   int loopCount = 0;

	   void setup()
	   {
	     String password = "12345678";
	     api.system.pword.set(password); // set the password to 12345678
	     api.system.pword.lock();        // lock the default port 
	   }

	   void loop()
	   {
	     loopCount++; 

             if (loopCount == 60)
               api.system.pword.unlock();   // unlock the default port after 60 seconds

	     delay(1000);
	   }
	   @endverbatim
	 */
        bool set(char *passwd, uint32_t len);
        bool set(String passwd);

	/**@par		Description
	 *		This api allow user to lock the default serial with the pass set in api.system.pword.set()	
	 * @note	If you never set a password successfully, the default password will be 00000000
	 * @ingroup	System_Pword
	 * @par		Syntax
	 * 		api.system.pword.lock()
	 * @return	void
	 * @par         Example
         * @verbatim
           int loopCount = 0;

           void setup()
           {
             String password = "12345678";
             api.system.pword.set(password); // set the password to 12345678
             api.system.pword.lock();        // lock the default port
           }

           void loop()
           {
             loopCount++;

             if (loopCount == 60)
               api.system.pword.unlock();   // unlock the default port after 60 seconds

             delay(1000);
           }
           @endverbatim

	 */
        void lock(void);

	/**@par		Description
	 *		This api allow user to unlock the default serial without password when it'locked
	 * @ingroup System_Pword
	 * @par		Syntax
	 * 		api.system.pword.unlock()
	 * @return	void
	 * @par         Example
         * @verbatim
           int loopCount = 0;

           void setup()
           {
             String password = "12345678";
             api.system.pword.set(password); // set the password to 12345678
             api.system.pword.lock();        // lock the default port
           }

           void loop()
           {
             loopCount++;

             if (loopCount == 60)
               api.system.pword.unlock();   // unlock the default port after 60 seconds

             delay(1000);
           }
           @endverbatim

	 */
        void unlock(void);
    };

    class bat {
      public:
	/**@par		Description
	 *		Get the current battery level
	 * @ingroup	System_Battery
	 * @par		Syntax
	 * 		api.system.bat.get()
	 * @return	float
	 * @par         Example
         * @verbatim
           void setup()
           {
             Serial.begin(115200);
           }

           void loop()
           {
             Serial.printf("Battery Level: %f\r\n", api.system.bat.get());
             delay(1000);
           }
           @endverbatim

	 */
        float get(void);
    };

    /**@ingroup		System_Misc
     */
    class atMode {
      public:
	/**@par		Description
	 *		Provide developers to create AT CMD.
	 * @par		Syntax
	 * 		api.system.atMode.add(cmd, usage, title, handle, perm)
	 * @param	cmd  	the cmd to define cmd name
	 * @param	usage	the cmd usage
	 * @param	title	the cmd title
	 * @param	handle	the handler that this command will execute
     * @param   perm    the cmd execution permission
	 *
	 * @return
	 * @par		Example
	 * @verbatim
      uint32_t led_status;
      
      int led_handle(SERIAL_PORT port, char *cmd, stParam *param) {
          if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
              Serial.print(cmd);
              Serial.print("=");
              Serial.println(led_status?"HIGH":"LOW");
          } else if (param->argc == 1) {
              for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
                  if (!isdigit(*(param->argv[0]+i))) {
                      return AT_PARAM_ERROR;
                  }
              }
      
              led_status = strtoul(param->argv[0], NULL, 10);
              if (led_status != 0 && led_status != 1) {
                  return AT_PARAM_ERROR;
              }
      
              pinMode(GREEN_LED, OUTPUT);
              pinMode(BLUE_LED, OUTPUT);
              digitalWrite(GREEN_LED, (led_status == 1)?HIGH:LOW);
              digitalWrite(BLUE_LED, (led_status == 1)?HIGH:LOW);
          } else {
              return AT_PARAM_ERROR;
          }
      
          return AT_OK;
      }
      
      void setup()
      {
          api.system.atMode.add("LED", "This controls both green and blue LEDs.", "LED", led_handle, RAK_ATCMD_PERM_WRITE | RAK_ATCMD_PERM_READ);
      }
      
      void loop()
      {
      }
	   @endverbatim
	 */
        bool add(char *cmd, char *usage, char *title, PF_handle handle,unsigned int perm = RAK_ATCMD_PERM_WRITE | RAK_ATCMD_PERM_READ);
    };

#ifdef SUPPORT_FS
    class fs {
      public:

	/**@par         Description
	 *              Get the error code of a file operation
	 *
	 * @ingroup     File_System
	 *
	 * @par		Syntax
	 *              api.system.fs.ferrno(file)
	 *
	 * @param       file     the file handle
	 *
	 * @return      int32_t
	 *
	 */
        int32_t         ferrno(SERVICE_FS_FILE file);

	/**@par		Description
	 *              Get the error code of a directory operation
	 *
	 * @ingroup	File_System
	 *
	 * @par		Syntax
	 *              api.system.fs.derrno(dir)
	 *
	 * @param       dir      the directory handle
	 *
	 * @return      int32_t
	 *
	 */
        int32_t         derrno(SERVICE_FS_DIR dir);

	/**@par		Description
	 *              Initialize the file system
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.init()
	 *
	 * @return      SERVICE_FS
	 */
        SERVICE_FS             init(void);

	/**@par		Description
	 *              Reset the file system
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.reset()
	 *
	 * @return      SERVICE_FS
	 */
        SERVICE_FS             reset(void);

	/**@par		Description
	 *              List all the files
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.list(fs, d, entry)
	 *
         * @param	fs	the file system handle
         * @param	d	the directory handle opened by api.system.fs.opendir()
         * @param	entry	the iterator to store the current entry
         *
	 * @return      int32_t
         * @par	Example
         * @verbatim
         void setup() {
             Serial.begin(115200);
         }

         void loop() {
             int32_t ret;
             SERVICE_FS_DIRENT entry;
             SERVICE_FS_DIR dir;

             if ((ret = api.system.fs.opendir(fs, "/", &dir)) != SERVICE_FS_OK) {
                 Serial.printf("open dir error! %d\r\n", ret);
                 return;
             }

             while (api.system.fs.list(fs, &dir, &entry) != SERVICE_FS_OK) {
                 Serial.printf("%s size:%u\r\n", entry.dirent.name, entry.dirent.size);
             }

             if ((ret = api.system.fs.closedir(fs, &dir)) != SERVICE_FS_OK) {
                 Serial.printf("close dir error! %d\r\n", ret);
                 return;
             }

             Serial.printf("total %lu, used %lu\r\n", entry.total, entry.used);
             delay(5000);
         }
         @endverbatim
         */
        int32_t                list(SERVICE_FS fs, SERVICE_FS_DIR *d, SERVICE_FS_DIRENT *entry);

	/**@par		Description
	 *              Open a file by file path
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.open(fs, path, flags, mode)
	 *
         * @param	fs	the file system handle
         * @param	path	the file path to be opened
         * @param	flags	open file flags
         * @param	mode	open file mode
	 *
	 * @return      the file handle
	 */
        SERVICE_FS_FILE        open(SERVICE_FS fs, const char* path, uint32_t flags, uint32_t mode);

	/**@par		Description
	 *              Read the content of a file
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.read(fs, file, buf, len)
	 *              
         * @param	fs	the file system handle
         * @param	file	the file handle
         * @param	buf	the read data buffer
         * @param	len	the number of bytes to be read
         *
	 * @return      int32_t
	 *
	 */
        int32_t                read(SERVICE_FS fs, SERVICE_FS_FILE file, void* buf, uint32_t len);

	/**@par		Description
	 *              Write the content of a file
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.write(fs, file, buf, len)
	 *              
         * @param	fs	the file system handle
         * @param	file	the file handle
         * @param	buf	the write data buffer
         * @param	len	the number of bytes to be written
         *
	 * @return      int32_t
	 *
	 */
        int32_t                write(SERVICE_FS fs, SERVICE_FS_FILE file, void* buf, uint32_t len);

	/**@par		Description
	 *              Move read/write pointer, Expand size
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.lseek(fs, file, offs, whence)
	 *
         * @param	fs	the file system handle
         * @param	file	the file handle
         * @param	offs	how much/where to move the offset
         * @param	whence	if SPIFFS_SEEK_SET, the file offset shall be set to offset bytes\nif SPIFFS_SEEK_CUR, the file offset shall be set to its current location plus offset\nif SPIFFS_SEEK_END, the file offset shall be set to the size of the file plus offse, which should be negative
	 *
	 * @return      int32_t
	 */
        int32_t                lseek(SERVICE_FS fs, SERVICE_FS_FILE file, int32_t offs, uint32_t whence);

	/**@par		Description
	 *              Remove a file by file path
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.remove(fs, path)
	 *
         * @param	fs	the file system handle
         * @param	path	the file path to be removed
	 *
	 * @return      int32_t
	 */
        int32_t                remove(SERVICE_FS fs, const char* path);

	/**@par		Description
	 *              Remove a file by file handle
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.fremove(fs, file)
	 *              
         * @param	fs	the file system handle
         * @param	file	the file handle
	 *
	 * @return      int32_t
	 */
        int32_t                fremove(SERVICE_FS fs, SERVICE_FS_FILE file);

	/**@par		Description
	 *              Gets file status by path
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.stat(fs, path, stat)
	 *
         * @param	fs	the file system handle
         * @param	path	the file path to stat
         * @param	stat	the stat structure to pupulate
	 *
	 * @return      int32_t
	 */
        int32_t                stat(SERVICE_FS fs, const char* path, SERVICE_FS_FILE_STAT* stat);

	/**@par		Description
	 *              Gets file status by file handle
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.fstat(fs, file, stat)
	 *
         * @param	fs	the file system handle
         * @param	file	the file handle to stat
         * @param	stat	the stat structure to pupulate
	 *
	 * @return      int32_t
	 */
        int32_t                fstat(SERVICE_FS fs, SERVICE_FS_FILE file, SERVICE_FS_FILE_STAT* stat);

	/**@par		Description
	 *              Flushes all pending write operations from cache for given file
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.flush(fs, file)
	 *
         * @param	fs	the file system handle
         * @param	file	the file handle to flush
	 *
	 * @return      int32_t
	 */
        int32_t                flush(SERVICE_FS fs, SERVICE_FS_FILE file);

	/**@par		Description
	 *              Closes a file handle
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.close(fs, file)
	 *
         * @param	fs	the file system handle
         * @param	file	the file handle to close
	 *
	 * @return      int32_t
	 */
        int32_t                close(SERVICE_FS fs, SERVICE_FS_FILE file);

	/**@par		Description
	 *              Renames a file
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.rename(fs, old_name, new_name)
	 *
         * @param	fs		the file system handle
         * @param	old_name	the path of file to rename
         * @param	new_name	the new path of file
	 *
	 * @return      int32_t
	 */
        int32_t                rename(SERVICE_FS fs, const char* old_name, const char* new_name);

	/**@par		Description
	 *              Opens a directory stream corresponding to the given name.
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.opendir(fs, name, d)
	 *
         * @param	fs		the file system handle
         * @param	name		the name of the directory
         * @param	d		pointer the directory stream to be populated
	 *
	 * @return      int32_t
	 */
        int32_t                opendir(SERVICE_FS fs, const char* name, SERVICE_FS_DIR* d);

	/**@par		Description
	 *              Closes a directory stream
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.closedir(fs, d)
	 *
         * @param	fs		the file system handle
         * @param	d		the directory stream to close
	 *
	 * @return      int32_t
	 */
        int32_t                closedir(SERVICE_FS fs, SERVICE_FS_DIR* d);

	/**@par		Description
	 *              Reads a directory into given iterator.
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.readdir(fs, d, e)
	 *
         * @param	fs		the file system handle
         * @param	d		pointer to the directory stream
         * @param	e		the iterator structure to be populated
	 *
	 * @return      null if error or end of stream, else an entry is returned
	 */
        SERVICE_FS_DIRENT*     readdir(SERVICE_FS fs, SERVICE_FS_DIR* d, SERVICE_FS_DIRENT* e);

	/**@par		Description
	 *              Check if EOF reached.
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.feof(fs, file)
	 *
         * @param	fs		the file system handle
         * @param	file		the file handle
	 *
	 * @return      int32_t
	 */
        int32_t                feof(SERVICE_FS fs, SERVICE_FS_FILE file);

	/**@par		Description
	 *              Get position in file.
	 *
	 * @ingroup	File_System
	 * @par		Syntax
	 *              api.system.fs.ftell(fs, file)
	 *
         * @param	fs		the file system handle
         * @param	file		the file handle
	 *
	 * @return      int32_t
	 */
        int32_t                ftell(SERVICE_FS fs, SERVICE_FS_FILE file);
    };
#else
    class flash {
      public:
        /**@par     Description
         *      Read a range of data from user flash partition.
         * @ingroup Flash
         * @par     Syntax
         *  api.system.flash.get(offset, buf, len)
         * @param   offset the offset to the start of user flash partition
         * @param   buf the buffer for reading the data
         * @param   len the length of data
         * @return  bool
         * @retval  TRUE for reading data successfully
         * @retval  FALSE for reading data failure
         */
        bool get(uint32_t offset, uint8_t *buf, uint32_t len);
        /**@par     Description
         *      Write a range of data from user flash partition.
         * @ingroup Flash
         * @par     Syntax
         *  api.system.flash.set(offset, buf, len)
         * @param   offset the offset to the start of user flash partition
         * @param   buf the buffer for writing the data
         * @param   len the length of data
         * @return  bool
         * @retval  TRUE for writing data successfully
         * @retval  FALSE for writing data failure
         */
        bool set(uint32_t offset, uint8_t *buf, uint32_t len);
    };
#endif
    class alias {
      public :
    /**@par     Description
     *      Set the alias name for device.
     * @ingroup System_Alias
     * @par     Syntax
     *  api.system.alias.set(buf, len)
     * @param   buf the buffer to set alias name
     * @param   len the length of alias name( <= 16 bytes)
     * @return  bool
     * @retval  TRUE for setting alias name successfully
     * @retval  FALSE for setting alias name failure
     * @par         Example
         * @verbatim
            void setup()
            {
                Serial.begin(115200);
                api.system.alias.set("my device",16);
                char buf[16];
                Serial.println(api.system.alias.get(buf,16));
                Serial.println(buf);
            }
            void loop()
            {
            }
           @endverbatim
     */
        bool    set(char * buf,uint32_t len);
    /**@par     Description
     *      Set the alias name for device.
     * @ingroup System_Alias
     * @par     Syntax
     *  api.system.alias.get(buf, len)
     * @param   buf the buffer to get alias name
     * @param   len the length of alias name( <= 16 bytes)
     * @return  bool
     * @retval  TRUE for getting alias name successfully
     * @retval  FALSE for getting alias name failure
     * @par         Example
         * @verbatim
            void setup()
            {
                Serial.begin(115200);
                api.system.alias.set("my device",16);
                char buf[16];
                Serial.println(api.system.alias.get(buf,16));
                Serial.println(buf);
            }
            void loop()
            {
            }
           @endverbatim
     */
        bool    get(char * buf,uint32_t len);
    };
    class timer {
      public :
    /**@par     Description
     *      Create a timer.
     * @ingroup System_Timer
     * @par     Syntax
     *  api.system.timer.create(id, handler, mode)
     * @param   id the timer ID
     * @param   handler the handler function for this timer
     * @param   mode the mode of this timer
     * @return  bool
     * @retval  TRUE for creating timer successfully
     * @retval  FALSE for creating timer failure
     * @par         Example
         * @verbatim
            void handler(void *data)
            {
              Serial.printf("[%lu]This is the handler\r\n", millis());
            }
            void setup()
            {
              Serial.begin(115200);

              if (api.system.timer.create(RAK_TIMER_0, (RAK_TIMER_HANDLER)handler, RAK_TIMER_PERIODIC) != true) {
                Serial.printf("Creating timer failed.\r\n");
              } else if (api.system.timer.start(RAK_TIMER_0, 1000, NULL) != true) {
                Serial.printf("Starting timer failed.\r\n");
              }
            }
            void loop()
            {
            }
           @endverbatim
     */
        bool    create(RAK_TIMER_ID id, RAK_TIMER_HANDLER handler, RAK_TIMER_MODE mode);
    /**@par     Description
     *      Start a timer.
     * @ingroup System_Timer
     * @par     Syntax
     *  api.system.timer.start(id, ms, data)
     * @param   id the timer ID
     * @param   ms the period of timer
     * @param   data the data passed to timer handler function
     * @return  bool
     * @retval  TRUE for starting timer successfully
     * @retval  FALSE for starting timer failure
     * @par         Example
         * @verbatim
            void handler(void *data)
            {
              Serial.printf("[%lu]This is the handler\r\n", millis());
            }
            void setup()
            {
              Serial.begin(115200);

              if (api.system.timer.create(RAK_TIMER_0, (RAK_TIMER_HANDLER)handler, RAK_TIMER_PERIODIC) != true) {
                Serial.printf("Creating timer failed.\r\n");
              } else if (api.system.timer.start(RAK_TIMER_0, 1000, NULL) != true) {
                Serial.printf("Starting timer failed.\r\n");
              }
            }
            void loop()
            {
            }
           @endverbatim
     */
        bool    start(RAK_TIMER_ID id, uint32_t ms, void *data);
    /**@par     Description
     *      Stop a timer.
     * @ingroup System_Timer
     * @par     Syntax
     *  api.system.timer.stop(id)
     * @param   id the timer ID
     * @return  bool
     * @retval  TRUE for stoping timer successfully
     * @retval  FALSE for stoping timer failure
     * @par         Example
         * @verbatim
            void handler(void *data)
            {
              Serial.printf("[%lu]This is the handler\r\n", millis());
            }
            void setup()
            {
              Serial.begin(115200);

              if (api.system.timer.create(RAK_TIMER_0, (RAK_TIMER_HANDLER)handler, RAK_TIMER_PERIODIC) != true) {
                Serial.printf("Creating timer failed.\r\n");
              } else if (api.system.timer.start(RAK_TIMER_0, 1000, NULL) != true) {
                Serial.printf("Starting timer failed.\r\n");
              }
            }
            void loop()
            {
              if (millis() > 60000) {
                if (api.system.timer.stop(RAK_TIMER_0) != true) {
                  Serial.printf("Stoping timer failed.\r\n");
                }
              }
            }
           @endverbatim
     */
        bool    stop(RAK_TIMER_ID id);
    };
    pword pword;
    bat bat;
    atMode atMode;
#ifdef SUPPORT_FS
    fs fs;
#else
    flash flash;
#endif
    alias alias;
    timer timer;
};

/**@example	System_FS/src/app.cpp
 */

#endif
