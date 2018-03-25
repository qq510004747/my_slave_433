/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：串行FLASH  SST25VF016B驱动模块
 * 环境	 	  : MDK5.10-固件库V3.5版本
 * 实验平台 ：STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 :            
 * 描述     : 实现SST25VF016B的读写操作。写操作采用AAI指令提高写入效率。
 *			      使用STM32的硬件SPI接口，非IO模拟时序          
 * 修改记录 :
 * 版本号    日期        作者     说明 
*******************************************************************************/
#ifndef _BSP_SST25VF016B_H
#define _BSP_SST25VF016B_H
/* Includes---------------------------------------------*/
#include "sys.h"
#include <inttypes.h>
/* Private defines--------------------------------------*/
#define SST25VF016B_ID		0xBF2541
#define Flash_TOTAL_SIZE		  (2*1024*1024)	/* 总容量，2M字节 */
#define Flash_PAGE_SIZE    	(4*1024)		  /* 页面大小，4K字节 */
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
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
#endif
