/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：BSP.h
 * 描述     :
 * 环境	 	  : MDK4.73-固件库V3.5版本
 * 实验平台 ：TOP9110-STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 : STM32F10x-STM32开发板
*******************************************************************************/
#ifndef __BSP_H
#define __BSP_H
/* Includes---------------------------------------------*/
#include "sys.h"
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
//extern volatile int32_t Sys_RunTime;
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
void BSP_Init(void);
void systemReboot(void);					/*STM32软复位*/
//NEWS 北——North       东——East     西——West          南——South 
#define East  0     //东
#define South 1     //南
#define West  2		//西
#define North 3		//北

//void Delay(u32 nCount);         
//void Delay_us(u32 Nus);
//void Delay_ms(uint32_t Nms);
//int32_t bsp_GetRunTime(void);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
#endif

