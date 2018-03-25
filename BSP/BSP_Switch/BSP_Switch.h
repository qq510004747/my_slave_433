/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：BSP_InPut.h
 * 环境	 	  : MDK4.73-固件库V3.5版本
 * 实验平台 ：TOP9110-STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 : STM32F10x-STM32开发板
 * 描述     : 系统基本输入配置文件
*******************************************************************************/
#ifndef __BSP_SWITCH_H
#define __BSP_SWITCH_H
/* Includes---------------------------------------------*/
#include "sys.h"
/* Private defines--------------------------------------*/
//#define  Echo   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6 )
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
/* Private functions -----------------------------------*/
void BSP_Switch_Init(void);
u8 Get_Switch_Status(void);
void Get_Switch_Message(u8 switch_flag);
extern u8 Switch_Status;
extern u8 Location_Flag;

/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
#endif

