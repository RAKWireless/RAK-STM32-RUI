/**@file	extflash.h
 *
 * @brief   Arduino wrapper for RUI external flash API.
 * @author  RAKwireless
 * @version 0.0.0
 * @date    2026.2
 */


#ifndef __EXTFLASH_H__
#define __EXTFLASH_H__


#include <stdint.h>
#include <stdbool.h>


/**@addtogroup	RUI_System_Data_Type
 * @{
 */

/**@par Description
 *      external flash information
 */

typedef struct
{
    uint32_t total_size;      /* bytes */
    uint32_t sector_size;     /* bytes (typically 0x1000) */
    uint32_t page_size;       /* bytes (typically 256) */
    uint8_t  jedec_id[3];     /* manufacturer / memory type / capacity */
} RAK_EXTFLASH_INFO;
/**@}*/

class extflash
{
public:
    extflash(void);

/**@par     Description
 *          Read data from external flash.
 * @ingroup ExtFlash
 * @par     Syntax
 *          api.system.extflash.get(uint32_t addr, uint8_t *buf, uint32_t len);
 * @param   addr
 *          Start address in external flash.
 * @param   buf
 *          Output buffer.
 * @param   len
 *          Number of bytes to read.
 * @return  int32_t
 * @par     Example
 * @verbatim
    uint32_t extflash_test_addr = 0x0u;

    void setup()
    {
        RAK_EXTFLASH_INFO info;
        int32_t st = api.system.extflash.info(&info); 

        if (st != 0) {
            Serial.printf("[FLASH] extflash.info failed, status=%d\r\n", st);
            return;
        }

        Serial.printf("[FLASH] JEDEC: %02X %02X %02X\r\n",
                      info.jedec_id[0], info.jedec_id[1], info.jedec_id[2]);
        Serial.printf("[FLASH] total_size=%lu, sector_size=%lu, page_size=%lu\r\n",
                      (unsigned long)info.total_size,
                      (unsigned long)info.sector_size,
                      (unsigned long)info.page_size);

        static uint8_t rxbuf[16];
        memset(rxbuf, 0, sizeof(rxbuf));

        st = api.system.extflash.get(extflash_test_addr, rxbuf, sizeof(rxbuf));
        if (st != 0) {
            Serial.printf("[FLASH] read failed %d\r\n", st);
            return;
        }

        Serial.printf("[FLASH] READBACK:");
        for (uint8_t i = 0; i < sizeof(rxbuf); ++i) {
            Serial.printf(" %02X", rxbuf[i]);
        }
        Serial.printf("\r\n");
    }

    void loop()
    {
        api.system.sleep.all(30000);
    }
 @endverbatim
 */
    int32_t get(uint32_t addr, uint8_t *buf, uint32_t len);

/**@par     Description
 *          Read data from external flash.
 * @ingroup ExtFlash
 * @par	    Syntax
 *          api.system.extflash.set(uint32_t addr, const uint8_t *data, uint32_t len)
 * @param   addr
 *          Start address in external flash.
 * @param   data
 *          Input data.
 * @param   len
 *          Number of bytes to write.
 * @return  int32_t
 * @par     Example
 * @verbatim
    uint32_t extflash_test_addr = 0x0u;
    uint32_t g_extflash_sector_size = 0;

    void setup()
    {
        RAK_EXTFLASH_INFO info;
        int32_t st = api.system.extflash.info(&info); 

        if (st != 0) {
            Serial.printf("[FLASH] extflash.info failed, status=%d\r\n", st);
            return;
        }
        g_extflash_sector_size = info.sector_size;
    }

    void loop()
    {
        api.system.sleep.all(30000);
        int32_t st;

        static uint8_t txbuf[16], rxbuf[16];
        for (uint8_t i = 0; i < sizeof(txbuf); ++i) {
            txbuf[i] = val + i;
        }

        memset(rxbuf, 0, sizeof(rxbuf));
        st = api.system.extflash.get(extflash_test_addr, rxbuf, sizeof(rxbuf));
        if (st != 0) {
            Serial.printf("[FLASH] read failed %d\r\n", st);
            return;
        }

        Serial.printf("[FLASH] READBACK:");
        for (uint8_t i = 0; i < sizeof(rxbuf); ++i) {
            Serial.printf(" %02X", rxbuf[i]);
        }
        Serial.printf("\r\n");

        st = api.system.extflash.erase(extflash_test_addr, g_extflash_sector_size);
        if (st != 0) {
            Serial.printf("[FLASH] erase_sector failed %d\r\n", st);
            return;
        }

        st = api.system.extflash.set(extflash_test_addr, txbuf, sizeof(txbuf));
        if (st != 0) {
            Serial.printf("[FLASH] write failed %d\r\n", st);
            return;
        }

        memset(rxbuf, 0, sizeof(rxbuf));
        st = api.system.extflash.get(extflash_test_addr, rxbuf, sizeof(rxbuf));
        if (st != 0) {
            Serial.printf("[FLASH] read failed %d\r\n", st);
            return;
        }

        Serial.printf("[FLASH] READBACK:");
        for (uint8_t i = 0; i < sizeof(rxbuf); ++i) {
            Serial.printf(" %02X", rxbuf[i]);
        }
        Serial.printf("\r\n");
    }
 @endverbatim
 */
    int32_t set(uint32_t addr, const uint8_t *data, uint32_t len);

/**@par	    Description
 *          Erase a range of external flash.
 * @ingroup ExtFlash
 * @par	    Syntax
 *          api.system.extflash.erase(uint32_t addr, uint32_t size)
 * @param   addr
 *          Start address.
 * @param   size
 *          Size in bytes.
 * @return  int32_t
 * @par Example
 * @verbatim
    uint32_t extflash_test_addr = 0x0u;
    uint32_t g_extflash_sector_size = 0;

    void setup()
    {
        RAK_EXTFLASH_INFO info;
        int32_t st = api.system.extflash.info(&info); 

        if (st != 0) {
            Serial.printf("[FLASH] extflash.info failed, status=%d\r\n", st);
            return;
        }
        g_extflash_sector_size = info.sector_size;
    }

    void loop()
    {
        api.system.sleep.all(30000);
        int32_t st;

        static uint8_t txbuf[16], rxbuf[16];
        for (uint8_t i = 0; i < sizeof(txbuf); ++i) {
            txbuf[i] = val + i;
        }

        memset(rxbuf, 0, sizeof(rxbuf));
        st = api.system.extflash.get(extflash_test_addr, rxbuf, sizeof(rxbuf));
        if (st != 0) {
            Serial.printf("[FLASH] read failed %d\r\n", st);
            return;
        }

        Serial.printf("[FLASH] READBACK:");
        for (uint8_t i = 0; i < sizeof(rxbuf); ++i) {
            Serial.printf(" %02X", rxbuf[i]);
        }
        Serial.printf("\r\n");

        st = api.system.extflash.erase(extflash_test_addr, g_extflash_sector_size);
        if (st != 0) {
            Serial.printf("[FLASH] erase_sector failed %d\r\n", st);
            return;
        }

        st = api.system.extflash.set(extflash_test_addr, txbuf, sizeof(txbuf));
        if (st != 0) {
            Serial.printf("[FLASH] write failed %d\r\n", st);
            return;
        }

        memset(rxbuf, 0, sizeof(rxbuf));
        st = api.system.extflash.get(extflash_test_addr, rxbuf, sizeof(rxbuf));
        if (st != 0) {
            Serial.printf("[FLASH] read failed %d\r\n", st);
            return;
        }

        Serial.printf("[FLASH] READBACK:");
        for (uint8_t i = 0; i < sizeof(rxbuf); ++i) {
            Serial.printf(" %02X", rxbuf[i]);
        }
        Serial.printf("\r\n");
    }
 @endverbatim
 */
    int32_t erase(uint32_t addr, uint32_t size);

/**@par	    Description
 *          Get external flash info.
 * @ingroup ExtFlash
 * @par	    Syntax
 *          api.system.extflash.info(RAK_EXTFLASH_INFO *info)
 * @param   info
 *          Output info structure.
 * @return  int32_t
 * @par     Example
 * @verbatim
    uint32_t extflash_test_addr = 0x0u;

    void setup()
    {
        RAK_EXTFLASH_INFO info;
        int32_t st = api.system.extflash.info(&info); 

        if (st != 0) {
            Serial.printf("[FLASH] extflash.info failed, status=%d\r\n", st);
            return;
        }

        Serial.printf("[FLASH] JEDEC: %02X %02X %02X\r\n",
                      info.jedec_id[0], info.jedec_id[1], info.jedec_id[2]);
        Serial.printf("[FLASH] total_size=%lu, sector_size=%lu, page_size=%lu\r\n",
                      (unsigned long)info.total_size,
                      (unsigned long)info.sector_size,
                      (unsigned long)info.page_size);

        static uint8_t rxbuf[16];
        memset(rxbuf, 0, sizeof(rxbuf));

        st = api.system.extflash.get(extflash_test_addr, rxbuf, sizeof(rxbuf));
        if (st != 0) {
            Serial.printf("[FLASH] read failed %d\r\n", st);
            return;
        }

        Serial.printf("[FLASH] READBACK:");
        for (uint8_t i = 0; i < sizeof(rxbuf); ++i) {
            Serial.printf(" %02X", rxbuf[i]);
        }
        Serial.printf("\r\n");
    }

    void loop()
    {
        api.system.sleep.all(30000);
    }
 @endverbatim
 */
    int32_t info(RAK_EXTFLASH_INFO *info);

private:
    bool _ensure_init(void);

private:
    bool s_inited;
};

#endif /* __EXTFLASH_H__ */
