/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：BSP_OutPut.h
 * 环境	 	  : MDK4.73-固件库V3.5-uCOS III V3.03版本
 * 实验平台 ：TOP9110-STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 : STM32F10x-STM32开发板
 * 描述     : 系统基本输出配置文件
*******************************************************************************/
#ifndef __TCP_H
#define __TCP_H
/* Includes---------------------------------------------*/
#include "sys.h"
/* Private defines--------------------------------------*/

/*************************************************************LORA平台参数初始化*****************************************************************/
#define Server_Mode
//#define Client_Mode

extern uint8_t Internet_Rxbuff[256];	/*定义一个1KB的缓存*/
//extern uint8_t Play_Music[8];	/*查询可读文件个数*/
//extern uint8_t Play_Music[8],

extern uint8_t Play_Music[8];/*随机播放音乐001*/
//extern uint8_t Play_Music[8];	/*随机播放FLASH1*/
//extern uint8_t Play_Music[8];	/*循环播放音乐001*/
//extern uint8_t Play_Music[8];	/*循环音量设置*/
extern uint8_t Internet_Txbuff[8];	/*随机播放音乐001*/
extern uint8_t ALL_AA_FF[8];	/*随机播放音乐001*/
extern uint8_t ALL_AA[8];	/*随机播放音乐001*/
extern uint8_t ALL_FF[8];	/*随机播放音乐001*/

/* Private function prototypes--------------------------*/
uint8_t TCP_Client_Demo(uint8_t *BUFF,uint8_t SendLen);
uint8_t TCP_Server_Demo(uint8_t *BUFF,uint8_t SendLen);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
#endif

