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

#ifndef __BSP_USART1_H__
#define __BSP_USART1_H__
/* Includes---------------------------------------------*/
#include "main.h"
#include "stdint.h"
#include "stm32f10x.h"
#include "stdio.h"
#define MSG_SEND_USART_BYTES(buf, bytes)  UART1_Send_char(buf, bytes) 
/* Private defines--------------------------------------*/
#define USART1_REC_LEN  			    200  	 //�����������ֽ���
#define USART1_Baud_Rate               57600 //����������
#define USART1_PinRemap         0      //0û����ӳ�䣬1��ӳ��
#define USART1_Rx_INT_ENABLE    1      //0��ʹ���жϽ��ܣ�1ʹ���жϽ���



#if USART1_Rx_INT_ENABLE// �����ж����ȼ���BSP.C����NVIC_Configurationʹ������
	#define USART1_PreemptionPriority  0
	#define USART1_ChannelSubPriority  0 
#endif 

/* Private typedef -------------------------------------*/
/* Private define --------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
extern uint8_t  USART_RX_BUF[USART1_REC_LEN]; //���ջ���,���USART1_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern uint16_t USART1_RX_STA;         		//����״̬���	
/* Private function prototypes -------------------------*/
void BSP_USART1_Init(u32 BAUD);
/*********************************************************************************************************************/
//void USART1_Config(void);
//void USART2_Config(void);

void Usart1Send(uint16_t ch);
void UART1_Send_char(uint8_t* c, uint8_t len);
void RS4851_Send_char(uint8_t* c, uint8_t len);
void USART_putchar(USART_TypeDef* USART_x, unsigned char ch);


//int fputc(int ch, FILE *f);//��������
//int fgetc(FILE *f); // ��������
//int USART_Scanf_Name(char * str);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/

#endif

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


////int fputc(int ch, FILE *f);//��������
////int fgetc(FILE *f); // ��������
////int USART_Scanf_Name(char * str);
///* Private functions -----------------------------------*/
///********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
//#endif

