/**@defgroup	ruiapi	Arduino Api 
 */

        /**@defgroup	RUI_Arduino_Data_Type	RUI Arduino Data Type
	 * @ingroup	ruiapi
         */

	/**@defgroup	Serial		Serial
	 * @ingroup	ruiapi
	 */
	
	/**@defgroup	Wire		Wire
	 * @ingroup	ruiapi
	 */

	/**@defgroup	SPI	SPI
	 * @ingroup	ruiapi
	 */

	/**@defgroup	Time		Time
	 * @ingroup	ruiapi
	 */

	/**@defgroup	AdvancedIO	AdvancedIO
	 * @ingroup	ruiapi
	 */	

	/**@defgroup	Characters 	Characters
	 * @ingroup	ruiapi
	 */

	/**@defgroup	Bit_and_Byte	Bit and Byte
	 * @ingroup	ruiapi
	 */

	/**@defgroup	DigitalIO	DigitalIO
	 * @ingroup	ruiapi
	 */
	
	/**@defgroup	AnalogIO	AnalogIO
	 * @ingroup	ruiapi
	 */

	/**@defgroup	Interrupts	Interrupts
	 * @ingroup	ruiapi
	 */
	
	/**@defgroup	Random		RandomNumber
	 * @ingroup	ruiapi
	 */

/**@defgroup	System	System
 */

        /**@defgroup	RUI_System_Data_Type	RUI System Data Type
	 * @ingroup	System
         */

	/**@defgroup	Device_Information	Device Information
	 * @ingroup	System
	 */
	
		/**@defgroup	Firmware_Version	Firmware Version
		 * @ingroup	Device_Information
		 */
	
		/**@defgroup	Cli_Version	Cli Version
		 * @ingroup	Device_Information
		 */
	
		/**@defgroup	Api_Version	Api Version
		 * @ingroup	Device_Information
		 */
	
		/**@defgroup	Model_ID	Model ID
		 * @ingroup	Device_Information
		 */
	
		/**@defgroup	Chip_ID		Chip ID
		 * @ingroup	Device_Information
		 */
	
		/**@defgroup	System_Battery	Battery
		 * @ingroup	Device_Information
		 */

#ifdef SUPPORT_FS
	/**@defgroup	File_System	File System	
	 * @ingroup	System
	 */
#else
	/**@defgroup	Flash	Flash
	 * @ingroup	System
	 */
#endif

	/**@defgroup	Powersave	Powersave
	 * @ingroup	System
	 */

        /**@defgroup    System_Pword  pword
         * @ingroup System_Misc
         */

	/**@defgroup	System_Misc	Misc
	 * @ingroup	System
	 */
    
        /**@defgroup    System_Alias  alias
         * @ingroup System_Misc
         */

/**@defgroup    lorawan  Lorawan
 */

        /**@defgroup	RUI_Lorawan_Data_Type	RUI Lorawan Data Type
	 * @ingroup	lorawan
         */

	/**@defgroup	Keys_IDs_and_EUI_Management	Keys, IDs, and EUIs Management
	 * @ingroup	lorawan
	 */

	/**@defgroup	Joining_and_Sending	Joining and Sending Data on LoRa® Network
	 * @ingroup	lorawan
	 */

	/**@defgroup	Network	LoRa® Network Management
	 * @ingroup	lorawan
	 */

	/**@defgroup	Class_B	Class B mode
	 * @ingroup	lorawan
	 */

	/**@defgroup	Information	Information
	 * @ingroup	lorawan
	 */

	/**@defgroup	Supplement	Supplement
	 * @ingroup	lorawan
	 */

	/**@defgroup	P2P	P2P Instructions
	 * @ingroup	lorawan
	 */

	/**@defgroup	Multicast	Multicast Group Command
	 * @ingroup	lorawan
	 */
	
/**@defgroup	ble	Ble
 */

        /**@defgroup	RUI_Ble_Data_Type	RUI Ble Data Type
	 * @ingroup	ble
         */

	/**@defgroup	BLE_Uart BLE UART
	 * @ingroup	ble
	 */

	/**@defgroup	BLE_Setting	BLE Setting
	 * @ingroup	ble
	 */
	
		/**@defgroup	BLE_MAC		mac
		 * @ingroup	BLE_Setting
		 */

	/**@defgroup	Beacon_Mode	Beacon Mode
	 * @ingroup	ble
	 */

		/**@defgroup	I_Beacon	iBeacon
		 * @ingroup	Beacon_Mode
		 */

			/**@defgroup	Beacon_UUID	uuid	
			 * @ingroup	I_Beacon
			 */

			/**@defgroup	Beacon_Major	major
			 * @ingroup	I_Beacon
			 */

			/**@defgroup	Beacon_Minor	minor
			 * @ingroup	I_Beacon
			 */

			/**@defgroup	Beacon_Power	power
			 * @ingroup	I_Beacon
			 */

	/**@defgroup	BLE_Scanner	BLE Scanner
	 * @ingroup	ble
	 */

	/**@defgroup	Customize_Service	Customize Service
	 * @ingroup	ble
	 */

#ifdef SUPPORT_NFC
/**@defgroup	NFC	Nfc
 */
#endif

/**@defgroup    One_Wire_Serial  One Wire Serial
 */

/**@defgroup	Api_Mode	API Mode
 */
