/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：串行FLASH  SST25VF016B功能演示模块
 * 环境	 	  : MDK5.10-固件库V3.5版本
 * 实验平台 ：STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 :            
 * 描述     : 实现SST25VF016B的读写操作。         
 * 修改记录 :
 * 版本号       日期         作者       说明 
   V1.0.1   :  2014-09-13    马加强     1.使用Jlink RTT在线调试printf功能
*******************************************************************************/
/* Includes---------------------------------------------*/
#include "BSP_SST25VF016B_Demo.h"
/* Private defines--------------------------------------*/
#define TEST_ADDR		0			/* 读写测试地址 */
#define TEST_SIZE		4096		/* 读写测试数据大小 */
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
/* 仅允许本文件内调用的函数声明 */
static void Flash_ReadTest(void);
static void Flash_WriteTest(void);
static void Flash_Erase(void);
static void Flash_ViewData(uint32_t _uiAddr);
static void Flash_WriteAll(uint8_t _ch);
/* Private functions -----------------------------------*/
/****************************
*	函 数 名: Flash_Demo
*	功能说明: 串行EEPROM读写例程
*	形    参：无
*	返 回 值: 无
*****************************/
void Flash_Demo(void)
{	
	uint32_t id;
	uint32_t uiReadPageNo = 0;
	Flash_InitHard();	/* 初始化SPI硬件 */
	id = Flash_ReadID();
	if (id != SST25VF016B_ID)
	{
		/* 没有检测到芯片 */
//    SEGGER_RTT_WriteString(0, "没有检测到串行Flash!\r\n");				
		while (1);	/* 停机 */
	}
	/* 检测串行Flash OK */
//	SEGGER_RTT_printf(0,"检测到串行Flash,ID = %08X\r\n",id);
	Flash_ReadTest();		  /* 读串行Flash数据，并打印出来数据内容 */	
	Flash_WriteTest();		/* 写串行Flash数据，并打印写入速度 */		
	Flash_Erase();			  /* 擦除串行Flash数据，实际上就是写入全0xFF */		
	Flash_WriteAll(0x55);	/* 擦除串行Flash数据，实际上就是写入全0xFF */	
	Flash_WriteAll(0xAA);	/* 擦除串行Flash数据，实际上就是写入全0xFF */
/* 读取前1K */
	if (uiReadPageNo > 0)
	{
		  uiReadPageNo--;
	}
	Flash_ViewData(uiReadPageNo * 1024);
/* 读取后1K */
	if (uiReadPageNo < 2048 - 1)
	{
		 uiReadPageNo++;
	}
	Flash_ViewData(uiReadPageNo * 1024);
}

/*******************************
*	函 数 名: Flash_ReadTest
*	功能说明: 读串行Flash测试
*	形    参：无
*	返 回 值: 无
********************************/
static void Flash_ReadTest(void)
{
	uint16_t i;
	uint8_t buf[TEST_SIZE];
	Flash_ReadBuffer(buf, TEST_ADDR, TEST_SIZE);
	/* 打印数据 */
	for (i = 0; i < TEST_SIZE; i++)
	{
//		SEGGER_RTT_printf(0,"%02X",buf[i]);
		if ((i & 15) == 15)
		{
//         SEGGER_RTT_WriteString(0, "\r\n");	/* 每行显示8字节数据 */
		}		
	}
}

/*****************************************
*	函 数 名: Flash_WriteTest
*	功能说明: 写串行Flash测试
*	形    参：无
*	返 回 值: 无
*******************************************/
static void Flash_WriteTest(void)
{
	uint16_t i;
	uint8_t buf[TEST_SIZE];
	/* 填充测试缓冲区 */
	for (i = 0; i < TEST_SIZE; i++)
	{		
		buf[i] = i;
	}
	if (Flash_WriteBuffer(buf, TEST_ADDR, TEST_SIZE) == 0)
	{
//		printf("写串行Flash出错！\r\n");
		return;
	}
	else
	{
//		printf("写串行Flash成功！\r\n");
	}
}
/********************************************
*	函 数 名: Flash_WriteAll
*	功能说明: 写串行EEPROM全部数据
*	形    参：_ch : 写入的数据
*	返 回 值: 无
*********************************************/
static void Flash_WriteAll(uint8_t _ch)
{
	uint16_t i;
	uint8_t buf[Flash_PAGE_SIZE];
	/* 填充测试缓冲区 */
	for (i = 0; i < TEST_SIZE; i++)
	{		
		buf[i] = _ch;
	}	
	/* 写EEPROM, 起始地址 = 0，数据长度为 256 */
	for (i = 0; i < Flash_TOTAL_SIZE / Flash_PAGE_SIZE; i++)
	{
		if (Flash_WriteBuffer(buf, i * Flash_PAGE_SIZE, Flash_PAGE_SIZE) == 0)
		{
//			printf("写串行Flash出错！\r\n");
			return;
		}
	}
}

/*********************
*	函 数 名: Flash_ReadTest
*	功能说明: 读串行EEPROM全部数据，并打印出来
*	形    参：无
*	返 回 值: 无
***********************/
static void Flash_Erase(void)
{
	Flash_EraseChip();
}
/*******************************
*	函 数 名: Flash_ViewData
*	功能说明: 读串行Flash并显示，每次显示1K的内容
*	形    参：无
*	返 回 值: 无
********************************/
static void Flash_ViewData(uint32_t _uiAddr)
{
	uint16_t i;
	uint8_t buf[1024];

	Flash_ReadBuffer(buf, _uiAddr,  1024);		/* 读数据 */	
	/* 打印数据 */
	for (i = 0; i < 1024; i++)
	{
//		printf(" %02X", buf[i]);	
		if ((i & 15) == 15)
		{
//			printf("\r\n");	/* 每行显示8字节数据 */
		}		
	}
}
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
