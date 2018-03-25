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
#ifndef __BSP_USART2_H
#define __BSP_USART2_H
/* Includes---------------------------------------------*/
#include "main.h"
/* Private defines--------------------------------------*/
/****************************************************************/
//! USART2
//#define MSG_SEND_USART_BYTES(buf, bytes)  usart1SendBuffer(buf, bytes) 
 
#define USART2_RCC_APB2Periph			RCC_APB2Periph_GPIOA
#define	USART2_RCC_APB1Periph_USART2	RCC_APB1Periph_USART2

#define	USART2_GPIO						GPIOA
#define	USART2_GPIO_PIN_TX				GPIO_Pin_2	//! PB.10
#define	USART2_GPIO_PIN_RX				GPIO_Pin_3 //! PB.11

#define	USART2_GPIO_CTR					GPIOA
#define	USART2_GPIO_PIN_CTR				GPIO_Pin_1	//! PB.10

#define USART2_USART					USART2
#define USART2_USART_IRQHandler			USART2_IRQHandler
#define	USART2_USART_IRQn				USART2_IRQn

#define RS4851_TX PAout(1) = 1;
#define RS4851_RX PAout(1) = 0;
/****************************************************************/
//! USART2
void USART2_Init(uint32_t baud);
void USART2Stop(void);
void USART2SendChar(unsigned char data);
void USART2SendBuffer(unsigned char *buffer, uint16_t count);
void USART2SendString(unsigned char *s);

int fputc(int ch, FILE *f);
int fgetc(FILE *f);
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

