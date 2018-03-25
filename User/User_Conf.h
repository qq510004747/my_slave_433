/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
				ARM Cortex-M3 Port
* �ļ���    : User_Conf.h
* ��  ��    : ϵͳ��Դ������
* ��  ��	: MDK4.73-�̼���V3.5�汾
* ʵ��ƽ̨  : STM32F103RBT6-8MHz->72MHz
* ��  ��    : V1.0.0
* ��  ��    :
* �޸�ʱ��  : 2013-12-20
* Ӳ������  : STM32F10x-STM32������
*******************************************************************************/
#ifndef __User_Conf_H
#define __User_Conf_H
/* Includes---------------------------------------------*/
#include "Utility.h"
/* Private defines--------------------------------------*/
//#define DEBUG_MODE              TRUE //!TRUE�رմ�ӡ���ԣ�TRUE������ӡ����
//�������汾���ƣ������ڳ�������ʱ�������Ƿ�Բ���������������
//#define SysParam_Ver            ((u32)(0x00000000))	
/*--------- Uart1 �û���������  -----------------------*/ 
//#define USART1_Remap            TRUE 
//#define USART1_RxSize           50      //���ܻ���صĴ�С
//#define Usart1_BaudRate         115200
//#define USART1_INT_ENABLE       TRUE    //FALSE��ʹ���жϽ��ܣ�TRUEʹ���жϽ���
//#define USART1_RxHeader         0xFFAA  //����ͨ�ŵ���ʼ֡


//#if USART1_INT_ENABLE// �����ж����ȼ���BSP.C����NVIC_Configurationʹ������
//		#define USART1_PreemptionPriority  0
//		#define USART1_ChannelSubPriority  0 
//#endif 

// �û�LEDָʾ�Ʋ�������
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
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
#endif
