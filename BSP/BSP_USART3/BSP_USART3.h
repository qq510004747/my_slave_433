/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
 * �ļ���   ��USART.h
 * ����     :
 * ����	 	  : MDK4.73-�̼���V3.5-uCOS III V3.03�汾
 * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
 * �汾     ��V1.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ : STM32F10x-STM32������
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


//int fputc(int ch, FILE *f);//��������
//int fgetc(FILE *f); // ��������
//int USART_Scanf_Name(char * str);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
#endif

