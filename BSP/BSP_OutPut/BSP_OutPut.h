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
#ifndef __BSP_OutPut_H
#define __BSP_OutPut_H
/* Includes---------------------------------------------*/
#include "sys.h"
/* Private defines--------------------------------------*/
#define LED1   PCout(13)// 
#define LED2   PCout(14)// 

//#define LED1_GPIO_REG 			GPIOC
//#define LED1_GPIO_PIN			GPIO_Pin_13		//! PC.13	

//#define LED2_GPIO_REG 			GPIOC
//#define LED2_GPIO_PIN			GPIO_Pin_14		//! PC.13
//#define LED4 PBout(8) // 
//#define Speaker_ON   GPIO_SetBits(GPIOB,GPIO_Pin_9  )
//#define Speaker_OFF   GPIO_ResetBits(GPIOB,GPIO_Pin_9  )
/* Private function prototypes--------------------------*/
void BSP_OutPut_Init(void);
/****************************************************************/
//! leds
void ledInit(void);
void ledOn(uint8_t chan);
void ledOff(uint8_t chan);

void ledFlashInit(void);
void ledFlashSet(uint8_t chan, uint8_t chFlashCnt, uint16_t hwOnTime, uint16_t hwOffTime);
void ledFlashLoop(uint8_t chan);
void ledFlashLoopAll(void);

typedef enum 
{
	LED_RUN,
	LED_MESH,	
} led_channel_t; 

/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
#endif

