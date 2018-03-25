/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
 * �ļ���   ������FLASH  SST25VF016B������ʾģ��
 * ����	 	  : MDK5.10-�̼���V3.5�汾
 * ʵ��ƽ̨ ��STM32F103RBT6-8MHz->72MHz
 * �汾     ��V1.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ :            
 * ����     : ʵ��SST25VF016B�Ķ�д������         
 * �޸ļ�¼ :
 * �汾��       ����         ����       ˵�� 
   V1.0.1   :  2014-09-13    ���ǿ     1.ʹ��Jlink RTT���ߵ���printf����
*******************************************************************************/
/* Includes---------------------------------------------*/
#include "BSP_SST25VF016B_Demo.h"
/* Private defines--------------------------------------*/
#define TEST_ADDR		0			/* ��д���Ե�ַ */
#define TEST_SIZE		4096		/* ��д�������ݴ�С */
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
/* �������ļ��ڵ��õĺ������� */
static void Flash_ReadTest(void);
static void Flash_WriteTest(void);
static void Flash_Erase(void);
static void Flash_ViewData(uint32_t _uiAddr);
static void Flash_WriteAll(uint8_t _ch);
/* Private functions -----------------------------------*/
/****************************
*	�� �� ��: Flash_Demo
*	����˵��: ����EEPROM��д����
*	��    �Σ���
*	�� �� ֵ: ��
*****************************/
void Flash_Demo(void)
{	
	uint32_t id;
	uint32_t uiReadPageNo = 0;
	Flash_InitHard();	/* ��ʼ��SPIӲ�� */
	id = Flash_ReadID();
	if (id != SST25VF016B_ID)
	{
		/* û�м�⵽оƬ */
//    SEGGER_RTT_WriteString(0, "û�м�⵽����Flash!\r\n");				
		while (1);	/* ͣ�� */
	}
	/* ��⴮��Flash OK */
//	SEGGER_RTT_printf(0,"��⵽����Flash,ID = %08X\r\n",id);
	Flash_ReadTest();		  /* ������Flash���ݣ�����ӡ������������ */	
	Flash_WriteTest();		/* д����Flash���ݣ�����ӡд���ٶ� */		
	Flash_Erase();			  /* ��������Flash���ݣ�ʵ���Ͼ���д��ȫ0xFF */		
	Flash_WriteAll(0x55);	/* ��������Flash���ݣ�ʵ���Ͼ���д��ȫ0xFF */	
	Flash_WriteAll(0xAA);	/* ��������Flash���ݣ�ʵ���Ͼ���д��ȫ0xFF */
/* ��ȡǰ1K */
	if (uiReadPageNo > 0)
	{
		  uiReadPageNo--;
	}
	Flash_ViewData(uiReadPageNo * 1024);
/* ��ȡ��1K */
	if (uiReadPageNo < 2048 - 1)
	{
		 uiReadPageNo++;
	}
	Flash_ViewData(uiReadPageNo * 1024);
}

/*******************************
*	�� �� ��: Flash_ReadTest
*	����˵��: ������Flash����
*	��    �Σ���
*	�� �� ֵ: ��
********************************/
static void Flash_ReadTest(void)
{
	uint16_t i;
	uint8_t buf[TEST_SIZE];
	Flash_ReadBuffer(buf, TEST_ADDR, TEST_SIZE);
	/* ��ӡ���� */
	for (i = 0; i < TEST_SIZE; i++)
	{
//		SEGGER_RTT_printf(0,"%02X",buf[i]);
		if ((i & 15) == 15)
		{
//         SEGGER_RTT_WriteString(0, "\r\n");	/* ÿ����ʾ8�ֽ����� */
		}		
	}
}

/*****************************************
*	�� �� ��: Flash_WriteTest
*	����˵��: д����Flash����
*	��    �Σ���
*	�� �� ֵ: ��
*******************************************/
static void Flash_WriteTest(void)
{
	uint16_t i;
	uint8_t buf[TEST_SIZE];
	/* �����Ի����� */
	for (i = 0; i < TEST_SIZE; i++)
	{		
		buf[i] = i;
	}
	if (Flash_WriteBuffer(buf, TEST_ADDR, TEST_SIZE) == 0)
	{
//		printf("д����Flash����\r\n");
		return;
	}
	else
	{
//		printf("д����Flash�ɹ���\r\n");
	}
}
/********************************************
*	�� �� ��: Flash_WriteAll
*	����˵��: д����EEPROMȫ������
*	��    �Σ�_ch : д�������
*	�� �� ֵ: ��
*********************************************/
static void Flash_WriteAll(uint8_t _ch)
{
	uint16_t i;
	uint8_t buf[Flash_PAGE_SIZE];
	/* �����Ի����� */
	for (i = 0; i < TEST_SIZE; i++)
	{		
		buf[i] = _ch;
	}	
	/* дEEPROM, ��ʼ��ַ = 0�����ݳ���Ϊ 256 */
	for (i = 0; i < Flash_TOTAL_SIZE / Flash_PAGE_SIZE; i++)
	{
		if (Flash_WriteBuffer(buf, i * Flash_PAGE_SIZE, Flash_PAGE_SIZE) == 0)
		{
//			printf("д����Flash����\r\n");
			return;
		}
	}
}

/*********************
*	�� �� ��: Flash_ReadTest
*	����˵��: ������EEPROMȫ�����ݣ�����ӡ����
*	��    �Σ���
*	�� �� ֵ: ��
***********************/
static void Flash_Erase(void)
{
	Flash_EraseChip();
}
/*******************************
*	�� �� ��: Flash_ViewData
*	����˵��: ������Flash����ʾ��ÿ����ʾ1K������
*	��    �Σ���
*	�� �� ֵ: ��
********************************/
static void Flash_ViewData(uint32_t _uiAddr)
{
	uint16_t i;
	uint8_t buf[1024];

	Flash_ReadBuffer(buf, _uiAddr,  1024);		/* ������ */	
	/* ��ӡ���� */
	for (i = 0; i < 1024; i++)
	{
//		printf(" %02X", buf[i]);	
		if ((i & 15) == 15)
		{
//			printf("\r\n");	/* ÿ����ʾ8�ֽ����� */
		}		
	}
}
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
