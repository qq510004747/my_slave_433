///**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
// * �ļ���   ��USART.c
// * ����	 	  : MDK4.73-�̼���V3.5-uCOS III V3.03�汾
// * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
// * �汾     ��V1.0.0
// * ����     ��
// * �޸�ʱ�� ��2013-12-20
// * Ӳ������ : STM32F10x-STM32������
//              ����1:TX-A9 RX-A10   
// * ����     : 1.���ͽ��ղ���ͨ����
//              2.���������������ԭ���콢�洮�ڷ�ʽ��δ����
//              							
//*******************************************************************************/
///* Includes---------------------------------------------*/
//#include "main.h"
//#include "BSP_USART1.h"
//#include "BSP_FIFO.h"

///* Private defines--------------------------------------*/
//#if USART1_PinRemap   // ��������CAN1��GPIO�˿�
//		#define USART1_PIN_Rx        GPIO_Pin_7
//		#define USART1_PIN_Tx        GPIO_Pin_6
//		#define USART1_GPIO          GPIOB
//		#define USART1_GPIO_CLK      RCC_APB2Periph_GPIOB
//#else
//		#define USART1_PIN_Rx        GPIO_Pin_10
//		#define USART1_PIN_Tx        GPIO_Pin_9
//		#define USART1_GPIO          GPIOA
//		#define USART1_GPIO_CLK      RCC_APB2Periph_GPIOA
//#endif
///* Private function prototypes--------------------------*/
///* Private typedef -------------------------------------*/
///* Private macro ---------------------------------------*/
///* Private variables -----------------------------------*/
//u8 USART_RX_BUF[USART1_REC_LEN];     //���ջ���,���USART1_REC_LEN���ֽ�.
////����״̬
////bit15��	  ������ɱ�־
////bit14��	  ���յ�0x0d
////bit13~0��	���յ�����Ч�ֽ���Ŀ
//u16 USART1_RX_STA=0; //����״̬���
///* Private function prototypes -------------------------*/
//static void USART1_Init(u32 BAUD);
///* Private functions -----------------------------------*/
///**********************************************
//*	�� �� ��: BSP_USART_Init(void)
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: ��ʼ������			
//**********************************************/
//void BSP_USART1_Init(u32 BAUD)
//{
//	USART1_Init(BAUD);
//}
///**********************************************
//*	�� �� ��: USART1_Init_Config(void)
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: ��ʼ������1				
//**********************************************/ 
////static void USART1_Init(u32 BAUD)
////{
////		GPIO_InitTypeDef GPIO_InitStructure;
////		USART_InitTypeDef USART_InitStructure;
////		USART_DeInit(USART1);  //��λ����1
////		 
////		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��GPIOAʱ��
////		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
////		RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	//ʹ��USART1
////		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
////		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|USART1_GPIO_CLK, ENABLE);	//ʹ��USART1,USART1_GPIOʱ��
////#if USART1_Rx_INT_ENABLE
////		NVIC_InitTypeDef NVIC_InitStructure;
////#endif	 
////		
////#if USART1_PinRemap
////		GPIO_PinRemapConfig(GPIO_Remap_USART1,ENABLE); //��������1��ӳ��ʱ��
////#endif
////	
////#if USART1_Rx_INT_ENABLE	//���ʹ���˽�������Usart1 NVIC  
////		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); 
////		NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
////		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=USART1_PreemptionPriority ;//��ռ���ȼ�0
////		NVIC_InitStructure.NVIC_IRQChannelSubPriority = USART1_ChannelSubPriority;		//�����ȼ�3
////		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
////		NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
////		 
////		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//�����ж�
////		USART_ITConfig(USART1, USART_IT_IDLE , ENABLE);//һ��Ҫ�������ã�;USART_IT_IDLE�����ж�
////#endif

//////USART1_TX   PA.9 PB.6
////		GPIO_InitStructure.GPIO_Pin = USART1_PIN_Tx; //PA.9
////		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
////		GPIO_Init(USART1_GPIO, &GPIO_InitStructure); //��ʼ��PA9
//////USART1_RX	  PA.10 PB.7
////		GPIO_InitStructure.GPIO_Pin = USART1_PIN_Rx;
////		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
////		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////		GPIO_Init(USART1_GPIO, &GPIO_InitStructure);  //��ʼ��
////		//RS48C_CTRL
//////		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//////		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//////		GPIO_Init(GPIOB, &GPIO_InitStructure);  //��ʼ��PB8
////	
//////USART ��ʼ������
////		USART_InitStructure.USART_BaudRate = BAUD;//һ������Ϊ9600;
////		USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
////		USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
////		USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
////		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
////		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
////		USART_Init(USART1, &USART_InitStructure); //��ʼ������
////	

////		USART_Cmd(USART1, ENABLE);//ʹ�ܴ���
////}
//void USART1_Init(u32 bound)
//{
//	//GPIO�˿�����
//	GPIO_InitTypeDef GPIO_InitStructure;
//	USART_InitTypeDef USART_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	 
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��USART1��GPIOAʱ��
//  
//	//USART1_TX   GPIOA.9
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
//	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.9
//   
//	//USART1_RX	  GPIOA.10��ʼ��
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
//	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.10  

////	//Usart1 NVIC ����
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//��ռ���ȼ�3
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		//�����ȼ�3
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
//	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���

//	USART_InitStructure.USART_BaudRate = bound;//���ڲ�����
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
//	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ

//	USART_Init(USART1, &USART_InitStructure); //��ʼ������1
//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
//	USART_Cmd(USART1, ENABLE);                    //ʹ�ܴ���1 
//}
//#if USART1_Rx_INT_ENABLE
///**********************************************
//*	�� �� ��: USART1_IRQHandler(void)
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: USART1�жϺ���		
//**********************************************/ 
//void USART1_USART_IRQHandler()
//{
//	unsigned char data;
//	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
//		Some_Data_On_Sky = 1; 
//		data = USART_ReceiveData(USART1);
//		fifoPushBuf(&data, 1);
//	}
//	USART_ClearITPendingBit(USART1, USART_IT_RXNE );
// 
////    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  
////    {     
////        USART_ClearFlag(USART1, USART_FLAG_RXNE);  
////        USART_ClearITPendingBit(USART1, USART_IT_RXNE);  
////        data = USART_ReceiveData(USART1);  
////        fifoPushBuf(&data, 1);
////    }
//}
//#endif 
///***************************************************************************************************************************************************/

///**
//  * @brief  �����ַ�
//  * @param  len   �ַ����ȣ� *c   ָ��������ַ�����ָ��
//  * @retval ��
//  */
//void UART1_Send_char(u8* c, u8 len)
//{
//    while(len--)
//    {
//		while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); 
//		USART_SendData(USART1,*c);
//		c++;
//    }        
//}

//void RS4851_Send_char(u8* c, u8 len)
//{
//	 UART1_Send_char( c, len);
//}

//void Usart1Send(u16 ch)
//{
//	USART1->DR = (ch&(u16)0x01FF);   
//	while((USART1->SR&0X40) == 0);//ѭ������,ֱ���������    
//}

//void PrintChar(char *s)
//{
//	char *p;
//	p=s;
//	while(*p != '\0')
//	{
//		Usart1Send(*p);
//		p++;
//	}
//}


//void USART_putchar(USART_TypeDef* USART_x, unsigned char ch)
//{
//		

///* Write a character to the USART */
//    USART_SendData(USART_x, (unsigned char) ch);
//    while( USART_GetFlagStatus(USART_x, USART_FLAG_TXE) == RESET );
//    while( USART_GetFlagStatus(USART_x, USART_FLAG_TC) == RESET );
//	
//}




///*********************************************END OF FILE**********************/



/////*  printf�����Ķ�����ʹ��-------------------*/
////int fputc(int ch, FILE *f)//��������
////   {
////      USART_SendData(USART1, (unsigned char) ch);// USART1 ���Ի��� USART1 ��
////      while (!(USART1->SR & USART_FLAG_TXE));
////      return (ch);
////   }
//// 
//// int fgetc(FILE *f) // ��������
////  { 
////      while (!(USART1->SR & USART_FLAG_RXNE));
////      return ((int)(USART1->DR & 0x1FF));
////   } 
////���Ҫʹ��printf��������#include<stdio.h>���ض�������������������⻹Ӧ��Target->Code Generation�й�ѡUse MicroLIB 
////char ch='E',str[10]={"FGHIJKLM"};
////int intd=12345;
////printf("The is a example!\n");
////printf("%c\n%s\n%d\n%c\n%s\n%d\n%d\n",'A',"BCD",0x23,ch,str,ch,intd);
////The is a example!
////A
////BCD
////35
////E
////FGHIJKLM
////69
////12345
///*******************************************************************************
//* Function Name  : USART_Scanf_Name
//* Description    : Gets Char values from the hyperterminal.
//* Input          : None
//* Output         : None
//* Return         : Length
//*******************************************************************************/
////int USART_Scanf_Name(char * str)
////{	
////    u16 index = 0;
////	  USART_ClearFlag(USART1,USART_FLAG_RXNE);//��һ�½��ձ�־λ
////    while(1) 
////    {
////        /* Loop until RXNE = 1 */
////        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET){}//�ȴ�ֱ�������ݵĵ���
////        
////		  str[index++] = (USART_ReceiveData(USART1));
////	    printf("%c",str[index - 1]);//�������������
////	    if(str[index - 1] == 0x0d)//�س���\r
////	    {  
////	        index--;//ȥ���س�������\0��β
////			    str[index] ='\0';//��������
////	        return index;
////        }
////    }													
////}

///**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
// * �ļ���   ��USART.c
// * ����	 	  : MDK4.73-�̼���V3.5-uCOS III V3.03�汾
// * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
// * �汾     ��V1.0.0
// * ����     ��
// * �޸�ʱ�� ��2013-12-20
// * Ӳ������ : STM32F10x-STM32������
//              ����1:TX-A9 RX-A10   
// * ����     : 1.���ͽ��ղ���ͨ����
//              2.���������������ԭ���콢�洮�ڷ�ʽ��δ����
//              							
//*******************************************************************************/
/////* Includes---------------------------------------------*/
////#include "main.h"
////#include "BSP_USART1.h"
////#include "BSP_FIFO.h"
/////*
////* @brief  USART1 init/gprs
////* @param	baud
////* @retval None
////*/
////void USART1Init(uint32_t baud) 
////{
////	GPIO_InitTypeDef   GPIO_InitStructure;
////	USART_InitTypeDef  USART_InitStructure;	
////	NVIC_InitTypeDef 	NVIC_InitStructure;
////	
////	USART_DeInit(USART1_USART);
////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
////	RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
////	
////	GPIO_InitStructure.GPIO_Pin = USART1_GPIO_PIN_TX;
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
////	GPIO_Init(USART1_GPIO, &GPIO_InitStructure);

////	GPIO_InitStructure.GPIO_Pin = USART1_GPIO_PIN_RX;
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////	GPIO_Init(USART1_GPIO, &GPIO_InitStructure);
////	
////	USART_InitStructure.USART_BaudRate = baud;
////	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
////	USART_InitStructure.USART_StopBits = USART_StopBits_1;
////	USART_InitStructure.USART_Parity = USART_Parity_No;
////	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
////	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
////	USART_Init(USART1, &USART_InitStructure);
////    USART_GetFlagStatus(USART1, USART_FLAG_TC); 
////	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
////	USART_Cmd(USART1, ENABLE);
////	USART_ClearFlag(USART1, USART_FLAG_TC);
////	
////	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
////	NVIC_InitStructure.NVIC_IRQChannel = USART1_USART_IRQn;
////	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
////	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
////	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
////	NVIC_Init(&NVIC_InitStructure);
////}

////void USART1Stop(void) 
////{
////	USART_DeInit(USART1);	
////}

////void USART1SendChar(unsigned char data) 
////{  
////    USART_SendData(USART1, data);  
////    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET){}  
////} 

////void USART1SendBuffer(unsigned char *buffer, uint16_t count) 
////{
////	while (count--) {    
////		USART1SendChar(*buffer);    
////		buffer++;    
////	}
////}

////void USART1_USART_IRQHandler()
////{
////	unsigned char data; 
////	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
////		Some_Data_On_Sky = 1;
////		data = USART_ReceiveData(USART1);
////		fifoPushBuf(&data, 1);
////	}
//////	USART_ClearITPendingBit(USART1, USART_IT_RXNE );
////}

///////********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
 * �ļ���   ��USART.c
 * ����	 	  : MDK4.73-�̼���V3.5-uCOS III V3.03�汾
 * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
 * �汾     ��V1.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ : STM32F10x-STM32������
              ����1:TX-A9 RX-A10   
 * ����     : 1.���ͽ��ղ���ͨ����
              2.���������������ԭ���콢�洮�ڷ�ʽ��δ����
              							
*******************************************************************************/
/* Includes---------------------------------------------*/
#include "BSP_USART1.h"
#include "BSP_FIFO.h"



#include "stm32f10x.h"
#include "misc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h" 

static void USART1_Init(u32 usart1_baud_rate);
/* Private functions -----------------------------------*/
/**********************************************
*	�� �� ��: BSP_USART_Init(void)
*	��    �Σ�
*	�� �� ֵ: 
*	����˵��: ��ʼ������			
**********************************************/
void BSP_USART1_Init(u32 usart1_baud_rate)
{
	USART1_Init(usart1_baud_rate);
}
void USART1_Init(u32 usart1_baud_rate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;        

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE );
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE );

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //USART1 TX��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); //�˿�A��
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //USART1 RX��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //�������룻
	GPIO_Init(GPIOA, &GPIO_InitStructure); //�˿�A��

	USART_InitStructure.USART_BaudRate = usart1_baud_rate; //�����ʣ�
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //����λ8λ��
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //ֹͣλ1λ��
	USART_InitStructure.USART_Parity = USART_Parity_No ; //��У��λ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	//��Ӳ�����أ�
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	//�շ�ģʽ��
	USART_Init(USART1, &USART_InitStructure);//���ô��ڲ�����

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); //�����ж��飬4λ��ռ���ȼ���4λ��Ӧ���ȼ���

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; //�жϺţ�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART1, ENABLE); //ʹ�ܴ��ڣ�
//	GPIO_InitTypeDef GPIO_InitStructure;
//	USART_InitTypeDef USART_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure; 
//	
//	USART_DeInit(USART1);       

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //USART1 TX��
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�������������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure); //�˿�A��
//		
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //USART1 RX��
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //�������룻
//	GPIO_Init(GPIOA, &GPIO_InitStructure); //�˿�A��

//	USART_InitStructure.USART_BaudRate = usart1_baud_rate; //�����ʣ�
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //����λ8λ��
//	USART_InitStructure.USART_StopBits = USART_StopBits_1; //ֹͣλ1λ��
//	USART_InitStructure.USART_Parity = USART_Parity_No ; //��У��λ��
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//	//��Ӳ�����أ�
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//	//�շ�ģʽ��
//	USART_Init(USART1, &USART_InitStructure);//���ô��ڲ�����

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); //�����ж��飬4λ��ռ���ȼ���4λ��Ӧ���ȼ���

//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; //�жϺţ�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ���
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //��Ӧ���ȼ���
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);

//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//	USART_ITConfig(USART1, USART_IT_IDLE , ENABLE);//һ��Ҫ�������ã�;USART_IT_IDLE�����ж�
//	USART_Cmd(USART1, ENABLE); //ʹ�ܴ��ڣ�

//	GPIO_InitTypeDef   GPIO_InitStructure;
//	USART_InitTypeDef  USART_InitStructure;	
//	NVIC_InitTypeDef 	NVIC_InitStructure;
//	
//	USART_DeInit(USART1);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
//	GPIO_Init(GPIOA, &GPIO_InitStructure);

//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	USART_InitStructure.USART_BaudRate = usart1_baud_rate;
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;
//	USART_InitStructure.USART_Parity = USART_Parity_No;
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//	USART_Init(USART1, &USART_InitStructure);
//    USART_GetFlagStatus(USART1, USART_FLAG_TC); 
//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//	USART_Cmd(USART1, ENABLE);
//	USART_ClearFlag(USART1, USART_FLAG_TC);
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);

//	GPIO_InitTypeDef   GPIO_InitStructure;
//	USART_InitTypeDef  USART_InitStructure;	
//	NVIC_InitTypeDef 	NVIC_InitStructure;
//	

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
// 
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	USART_InitStructure.USART_BaudRate = usart1_baud_rate;
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;
//	USART_InitStructure.USART_Parity = USART_Parity_No;
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//	USART_Init(USART1, &USART_InitStructure);
//    USART_GetFlagStatus(USART1, USART_FLAG_TC); 
//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//	USART_Cmd(USART1, ENABLE);
//	USART_ClearFlag(USART1, USART_FLAG_TC);
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
}

void USART1_Send_Byte(u8 Data) //����һ���ֽڣ�
{
	USART_SendData(USART1,Data);
	while( USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET );
}

void USART1_Send_String(u8 *Data) //�����ַ�����
{
	while(*Data)
	USART1_Send_Byte(*Data++);
}

void UART1_Send_char(u8* c, u8 len)
{
    while(len--)
    {
        USART_SendData(USART1,*c);
        while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); 
		c++;
    }        
}
void USART1_IRQHandler(void) //�жϴ�������
{
	unsigned char data; 
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
		Some_Data_On_Sky = 1;
		data = USART_ReceiveData(USART1);
		fifoPushBuf(&data, 1);
	}
	USART_ClearITPendingBit(USART1, USART_IT_RXNE );
}  
 
/* Private defines--------------------------------------*/
//#if USART1_PinRemap   // ��������CAN1��GPIO�˿�
//		#define USART1_PIN_Rx        GPIO_Pin_7
//		#define USART1_PIN_Tx        GPIO_Pin_6
//		#define USART1_GPIO          GPIOB
//		#define USART1_GPIO_CLK      RCC_APB2Periph_GPIOB
//#else
//		#define USART1_PIN_Rx        GPIO_Pin_10
//		#define USART1_PIN_Tx        GPIO_Pin_9
//		#define USART1_GPIO          GPIOA
//		#define USART1_GPIO_CLK      RCC_APB2Periph_GPIOA
//#endif
///* Private function prototypes--------------------------*/
///* Private typedef -------------------------------------*/
///* Private macro ---------------------------------------*/
///* Private variables -----------------------------------*/
//u8 USART_RX_BUF[USART1_REC_LEN];     //���ջ���,���USART1_REC_LEN���ֽ�.
////����״̬
////bit15��	  ������ɱ�־
////bit14��	  ���յ�0x0d
////bit13~0��	���յ�����Ч�ֽ���Ŀ
//u16 USART1_RX_STA=0; //����״̬���
///* Private function prototypes -------------------------*/
//static void USART1_Init(u32 usart1_baud_rate);
///* Private functions -----------------------------------*/
///**********************************************
//*	�� �� ��: BSP_USART_Init(void)
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: ��ʼ������			
//**********************************************/
//void BSP_USART1_Init(u32 usart1_baud_rate)
//{
//	USART1_Init(usart1_baud_rate);
//}
///**********************************************
//*	�� �� ��: USART1_Init_Config(void)
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: ��ʼ������1				
//**********************************************/ 
//static void USART1_Init(u32 usart1_baud_rate)
//{

//		GPIO_InitTypeDef GPIO_InitStructure;
//		USART_InitTypeDef USART_InitStructure;
//		 
////		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��GPIOAʱ��
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
//		RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	//ʹ��USART1
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
//	
//#if USART1_Rx_INT_ENABLE
//		NVIC_InitTypeDef NVIC_InitStructure;
//#endif	 
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|USART1_GPIO_CLK, ENABLE);	//ʹ��USART1,USART1_GPIOʱ��

//#if USART1_PinRemap
//		GPIO_PinRemapConfig(GPIO_Remap_USART1,ENABLE); //��������1��ӳ��ʱ��
//#endif
//		USART_DeInit(USART1);  //��λ����1
////USART1_TX   PA.9 PB.6
//		GPIO_InitStructure.GPIO_Pin = USART1_PIN_Tx; //PA.9
//		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
//		GPIO_Init(USART1_GPIO, &GPIO_InitStructure); //��ʼ��PA9
////USART1_RX	  PA.10 PB.7
//		GPIO_InitStructure.GPIO_Pin = USART1_PIN_Rx;
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
//		GPIO_Init(USART1_GPIO, &GPIO_InitStructure);  //��ʼ��
//		//RS48C_CTRL
//		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//		GPIO_Init(GPIOB, &GPIO_InitStructure);  //��ʼ��PB8
//	
////USART ��ʼ������
//		USART_InitStructure.USART_BaudRate = usart1_baud_rate;//һ������Ϊ9600;
//		USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
//		USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
//		USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
//		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
//		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
//		USART_Init(USART1, &USART_InitStructure); //��ʼ������
//	
//#if USART1_Rx_INT_ENABLE	//���ʹ���˽�������Usart1 NVIC   
//		NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=USART1_PreemptionPriority ;//��ռ���ȼ�0
//		NVIC_InitStructure.NVIC_IRQChannelSubPriority = USART1_ChannelSubPriority;		//�����ȼ�3
//		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
//		NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
//		 
//		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//�����ж�
//		USART_ITConfig(USART1, USART_IT_IDLE , ENABLE);//һ��Ҫ�������ã�;USART_IT_IDLE�����ж�
//#endif
//		USART_Cmd(USART1, ENABLE);                    //ʹ�ܴ��� 
//}

//#if USART1_Rx_INT_ENABLE
///**********************************************
//*	�� �� ��: USART1_IRQHandler(void)
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: USART1�жϺ���		
//**********************************************/ 
//void USART1_IRQHandler(void)
//{
//	u8 Res;
//	unsigned char data;
//	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
//		Some_Data_On_Sky = 1; 
//		data = USART_ReceiveData(USART1);
//		fifoPushBuf(&data, 1);
//	}
//	USART_ClearITPendingBit(USART1, USART_IT_RXNE );
//}
//#endif 
///***************************************************************************************************************************************************/



///**
//  * @brief  �����ַ�
//  * @param  len   �ַ����ȣ� *c   ָ��������ַ�����ָ��
//  * @retval ��
//  */
//void UART1_Send_char(u8* c, u8 len)
//{
//    while(len--)
//    {
//        USART_SendData(USART1,*c);
//        while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); 
//		c++;
//    }        
//}

//void Usart1Send(u16 ch)
//{
//	USART1->DR = (ch&(u16)0x01FF);   
//	while((USART1->SR&0X40) == 0);//ѭ������,ֱ���������    
//}

//void PrintChar(char *s)
//{
//	char *p;
//	p=s;
//	while(*p != '\0')
//	{
//		Usart1Send(*p);
//		p++;
//	}
//}


//void USART_putchar(USART_TypeDef* USART_x, unsigned char ch)
//{
//	/* Write a character to the USART */
//    USART_SendData(USART_x, (unsigned char) ch);
//    while( USART_GetFlagStatus(USART_x, USART_FLAG_TXE) == RESET );
//    while( USART_GetFlagStatus(USART_x, USART_FLAG_TC) == RESET );	
//}



///// �ض���c�⺯��printf��USARTx
//int fputc(int ch, FILE *f)
//{
//	RS4851_TX;

//		/* ����һ���ֽ����ݵ�USARTx */
//		USART_SendData(USED_COM_NUMBER, (uint8_t) ch);
//		
//		/* �ȴ�������� */
//		while (USART_GetFlagStatus(USED_COM_NUMBER, USART_FLAG_TC) == RESET);		

//		return (ch);
//}

///// �ض���c�⺯��scanf��USARTx
//int fgetc(FILE *f)
//{
//	RS4851_TX;

//	
//		/* �ȴ�����x�������� */
//		while (USART_GetFlagStatus(USED_COM_NUMBER, USART_FLAG_RXNE) == RESET);

//		return (int)USART_ReceiveData(USED_COM_NUMBER);
//}
/*********************************************END OF FILE**********************/



///*  printf�����Ķ�����ʹ��-------------------*/
//int fputc(int ch, FILE *f)//��������
//   {
//      USART_SendData(USART1, (unsigned char) ch);// USART1 ���Ի��� USART1 ��
//      while (!(USART1->SR & USART_FLAG_TXE));
//      return (ch);
//   }
// 
// int fgetc(FILE *f) // ��������
//  { 
//      while (!(USART1->SR & USART_FLAG_RXNE));
//      return ((int)(USART1->DR & 0x1FF));
//   } 
//���Ҫʹ��printf��������#include<stdio.h>���ض�������������������⻹Ӧ��Target->Code Generation�й�ѡUse MicroLIB 
//char ch='E',str[10]={"FGHIJKLM"};
//int intd=12345;
//printf("The is a example!\n");
//printf("%c\n%s\n%d\n%c\n%s\n%d\n%d\n",'A',"BCD",0x23,ch,str,ch,intd);
//The is a example!
//A
//BCD
//35
//E
//FGHIJKLM
//69
//12345
/*******************************************************************************
* Function Name  : USART_Scanf_Name
* Description    : Gets Char values from the hyperterminal.
* Input          : None
* Output         : None
* Return         : Length
*******************************************************************************/
//int USART_Scanf_Name(char * str)
//{	
//    u16 index = 0;
//	  USART_ClearFlag(USART1,USART_FLAG_RXNE);//��һ�½��ձ�־λ
//    while(1) 
//    {
//        /* Loop until RXNE = 1 */
//        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET){}//�ȴ�ֱ�������ݵĵ���
//        
//		  str[index++] = (USART_ReceiveData(USART1));
//	    printf("%c",str[index - 1]);//�������������
//	    if(str[index - 1] == 0x0d)//�س���\r
//	    {  
//	        index--;//ȥ���س�������\0��β
//			    str[index] ='\0';//��������
//	        return index;
//        }
//    }													
//}

