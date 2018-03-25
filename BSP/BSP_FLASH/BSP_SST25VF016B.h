/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
 * �ļ���   ������FLASH  SST25VF016B����ģ��
 * ����	 	  : MDK5.10-�̼���V3.5�汾
 * ʵ��ƽ̨ ��STM32F103RBT6-8MHz->72MHz
 * �汾     ��V1.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ :            
 * ����     : ʵ��SST25VF016B�Ķ�д������д��������AAIָ�����д��Ч�ʡ�
 *			      ʹ��STM32��Ӳ��SPI�ӿڣ���IOģ��ʱ��          
 * �޸ļ�¼ :
 * �汾��    ����        ����     ˵�� 
*******************************************************************************/
#ifndef _BSP_SST25VF016B_H
#define _BSP_SST25VF016B_H
/* Includes---------------------------------------------*/
#include "sys.h"
#include <inttypes.h>
/* Private defines--------------------------------------*/
#define SST25VF016B_ID		0xBF2541
#define Flash_TOTAL_SIZE		  (2*1024*1024)	/* ��������2M�ֽ� */
#define Flash_PAGE_SIZE    	(4*1024)		  /* ҳ���С��4K�ֽ� */
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
void Flash_InitHard(void);
uint32_t Flash_ReadID(void);
void Flash_EraseChip(void);
void Flash_EraseSector(uint32_t _uiSectorAddr);
void Flash_PageWrite(uint8_t * _pBuf, uint32_t _uiWriteAddr, uint16_t _usSize);
uint8_t Flash_WriteBuffer(uint8_t* _pBuf, uint32_t _uiWriteAddr, uint16_t _usWriteSize);
void Flash_ReadBuffer(uint8_t * _pBuf, uint32_t _uiReadAddr, uint32_t _uiSize);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
#endif
