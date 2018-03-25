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
#ifndef __BSP_InPut_H
#define __BSP_InPut_H
/* Includes---------------------------------------------*/
#include "sys.h"
/* Private defines--------------------------------------*/
#define  Echo   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6 )

#define Get_SWD1_GPIO_In		PAin(7)
#define Get_SWD2_GPIO_In		PAin(6)
#define Get_SWD3_GPIO_In		PAin(5)
#define Get_SWD4_GPIO_In		PAin(4)
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
/* Private functions -----------------------------------*/
void BSP_InPut_Init(void);
void EXTI_Initialization(void);
void In_Put_Handle_fun(void);
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
#endif

