/******************** (C) COPYRIGHT DIY嵌入式开发工作室*******************************
 *
 *                              ARM Cortex-M4 Port
 *
 * 文件名称     : W5500_SPI.h ( FreeTROS For STM32F4 )
 * 作    者     :    
 * 环    境	 	: MDK5.10a-->固件库V1.3.0版本-->FreeRTOS V8.1.2 版本
 * 开发平台     : STM32F407ZGT6-25MHz->168MHz
 * 修改时间     : 2014-10-20
 * 版    本     : V1.0.0
 * 硬件连接     : STM32F40xx-STM32开发板
 * 说    明     :
 *
 *
**************************************************************************************/
#ifndef __W5500_SPI_H
#define __W5500_SPI_H
/* Includes---------------------------------------------*/
#include "User_config.h"
/* Private defines--------------------------------------*/
/*定义W5500的电源控制管脚*/
#define WIZ_Pwr			   GPIO_Pin_9
#define WIZ_Pwr_PORT	   GPIOA
#define WIZ_Pwr_RCC	       RCC_APB2Periph_GPIOA
/*定义W5500的片选管脚*/
#define WIZ_SCS			   GPIO_Pin_12
#define WIZ_SCS_PORT	   GPIOA
#define WIZ_SCS_RCC	       RCC_APB2Periph_GPIOA    
/*定义W5500的RESET管脚*/
#define WIZ_RESET		   GPIO_Pin_10
#define WIZ_RESET_PORT	   GPIOA
#define WIZ_RESET_RCC	   RCC_APB2Periph_GPIOA
/*定义W5500的INT管脚*/
#define WIZ_INT			   GPIO_Pin_11
#define WIZ_INT_PORT	   GPIOA
#define WIZ_INT_RCC	       RCC_APB2Periph_GPIOA
///*定义SPI作为W5500的硬件接口*/
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
void  W5500_RST(void);
void  Internet_Init(void);
void  W5500_SPI_Configuration(void);
uint8_t W5500_SPI_SendByte(uint8_t byte);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
#endif











