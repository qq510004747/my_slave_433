/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：USART.h
 * 描述     :
 * 环境	 	  : MDK4.73-固件库V3.5-uCOS III V3.03版本
 * 实验平台 ：TOP9110-STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 : STM32F10x-STM32开发板
*******************************************************************************/
#ifndef __BSP_USART_H
#define __BSP_USART_H
/* Includes---------------------------------------------*/
#include "main.h"
/* Private defines--------------------------------------*/
/****************************************************************/
//! usart3
#define MSG_SEND_USART_BYTES(buf, bytes)  usart3SendBuffer(buf, bytes) 

#define USART3_RCC_APB2Periph			RCC_APB2Periph_GPIOB
#define	USART3_RCC_APB1Periph_USART3	RCC_APB1Periph_USART3
#define	USART3_GPIO						GPIOB
#define	USART3_GPIO_PIN_TX				GPIO_Pin_10	//! PB.10
#define	USART3_GPIO_PIN_RX				GPIO_Pin_11 //! PB.11
#define USART3_USART					USART3
#define USART3_USART_IRQHandler			USART3_IRQHandler
#define	USART3_USART_IRQn				USART3_IRQn

/****************************************************************/
//! usart3
void usart3Init(uint32_t baud);
void usart3Stop(void);
void usart3SendChar(unsigned char data);
void usart3SendBuffer(unsigned char *buffer, uint16_t count);
void usart3SendString(unsigned char *s);


/* Private typedef -------------------------------------*/
/* Private define --------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/

/* Private function prototypes -------------------------*/


//int fputc(int ch, FILE *f);//发送数据
//int fgetc(FILE *f); // 接收数据
//int USART_Scanf_Name(char * str);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
#endif

