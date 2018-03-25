

#include "crc.h"



 
/**
  * @brief  CRC16 implementation according to CCITT standards
  * @note   CRC-16/XMODEM       x16+x12+x5+1
  * @retval None
  */



uint16_t crc16(uint8_t * buf, uint32_t len)
{
	uint16_t crc = 0;
	uint32_t counter;
	
	for (counter = 0; counter < len; counter++) {
		crc = (crc<<8) ^ crc16Tab[ ((crc>>8) ^ *buf++ ) & 0x00FF];
	}
	return crc;
}
