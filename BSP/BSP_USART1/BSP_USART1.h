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

#ifndef __BSP_USART1_H__
#define __BSP_USART1_H__
/* Includes---------------------------------------------*/
#include "main.h"
#include "stdint.h"
#include "stm32f10x.h"
#include "stdio.h"
#define MSG_SEND_USART_BYTES(buf, bytes)  UART1_Send_char(buf, bytes) 
/* Private defines--------------------------------------*/
#define USART1_REC_LEN  			    200  	 //定义最大接收字节数
#define USART1_Baud_Rate               57600 //波特率设置
#define USART1_PinRemap         0      //0没有重映射，1重映射
#define USART1_Rx_INT_ENABLE    1      //0不使用中断接受，1使用中断接收



#if USART1_Rx_INT_ENABLE// 定义中断优先级，BSP.C函数NVIC_Configuration使用详情
	#define USART1_PreemptionPriority  0
	#define USART1_ChannelSubPriority  0 
#endif 

/* Private typedef -------------------------------------*/
/* Private define --------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
extern uint8_t  USART_RX_BUF[USART1_REC_LEN]; //接收缓冲,最大USART1_REC_LEN个字节.末字节为换行符 
extern uint16_t USART1_RX_STA;         		//接收状态标记	
/* Private function prototypes -------------------------*/
void BSP_USART1_Init(u32 BAUD);
/*********************************************************************************************************************/
//void USART1_Config(void);
//void USART2_Config(void);

void Usart1Send(uint16_t ch);
void UART1_Send_char(uint8_t* c, uint8_t len);
void RS4851_Send_char(uint8_t* c, uint8_t len);
void USART_putchar(USART_TypeDef* USART_x, unsigned char ch);


//int fputc(int ch, FILE *f);//发送数据
//int fgetc(FILE *f); // 接收数据
//int USART_Scanf_Name(char * str);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/

#endif

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
//#ifndef __BSP_USART1_H
//#define __BSP_USART1_H
///* Includes---------------------------------------------*/
//#include "main.h"
///* Private defines--------------------------------------*/
///****************************************************************/
////! USART1
//#define MSG_SEND_USART_BYTES(buf, bytes)  USART1SendBuffer(buf, bytes) 

//#define USART1_RCC_APB2Periph			RCC_APB2Periph_GPIOA
//#define	USART1_RCC_APB1Periph_USART1	RCC_APB2Periph_USART1
//#define	USART1_GPIO						GPIOA
//#define	USART1_GPIO_PIN_TX				GPIO_Pin_9	//! PB.10
//#define	USART1_GPIO_PIN_RX				GPIO_Pin_10 //! PB.11
//#define USART1_USART					USART1
//#define USART1_USART_IRQHandler			USART1_IRQHandler
//#define	USART1_USART_IRQn				USART1_IRQn

///****************************************************************/
////! USART1
//void USART1Init(uint32_t baud);
//void USART1Stop(void);
//void USART1SendChar(unsigned char data);
//void USART1SendBuffer(unsigned char *buffer, uint16_t count);
//void USART1SendString(unsigned char *s);


///* Private typedef -------------------------------------*/
///* Private define --------------------------------------*/
///* Private macro ---------------------------------------*/
///* Private variables -----------------------------------*/

///* Private function prototypes -------------------------*/


////int fputc(int ch, FILE *f);//发送数据
////int fgetc(FILE *f); // 接收数据
////int USART_Scanf_Name(char * str);
///* Private functions -----------------------------------*/
///********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
//#endif

