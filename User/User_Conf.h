/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
				ARM Cortex-M3 Port
* 文件名    : User_Conf.h
* 描  述    : 系统资源定义区
* 环  境	: MDK4.73-固件库V3.5版本
* 实验平台  : STM32F103RBT6-8MHz->72MHz
* 版  本    : V1.0.0
* 作  者    :
* 修改时间  : 2013-12-20
* 硬件连接  : STM32F10x-STM32开发板
*******************************************************************************/
#ifndef __User_Conf_H
#define __User_Conf_H
/* Includes---------------------------------------------*/
#include "Utility.h"
/* Private defines--------------------------------------*/
//#define DEBUG_MODE              TRUE //!TRUE关闭打印调试，TRUE开启打印调试
//参数区版本控制（可用于程序升级时，决定是否对参数区进行升级）
//#define SysParam_Ver            ((u32)(0x00000000))	
/*--------- Uart1 用户参数设置  -----------------------*/ 
//#define USART1_Remap            TRUE 
//#define USART1_RxSize           50      //接受缓冲池的大小
//#define Usart1_BaudRate         115200
//#define USART1_INT_ENABLE       TRUE    //FALSE不使用中断接受，TRUE使用中断接收
//#define USART1_RxHeader         0xFFAA  //串口通信的起始帧


//#if USART1_INT_ENABLE// 定义中断优先级，BSP.C函数NVIC_Configuration使用详情
//		#define USART1_PreemptionPriority  0
//		#define USART1_ChannelSubPriority  0 
//#endif 

// 用户LED指示灯参数设置
//#define LED_Pin         GPIO_Pin_13
//#define LED_GPIO_Port   GPIOC
//#define LED_Port_RCC    RCC_APB2Periph_GPIOC
/* Private typedef -------------------------------------*/
#if DEBUG_MODE
#define printf_debug(...)   printf(__VA_ARGS__);
#endif 

/* Private macro ---------------------------------------*/
/* Private function prototypes--------------------------*/
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
#endif
