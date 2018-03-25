/******************** (C) COPYRIGHT DIYǶ��ʽ����������*******************************
 *
 *                              ARM Cortex-M4 Port
 *
 * �ļ�����     : W5500_SPI.h ( FreeTROS For STM32F4 )
 * ��    ��     :    
 * ��    ��	 	: MDK5.10a-->�̼���V1.3.0�汾-->FreeRTOS V8.1.2 �汾
 * ����ƽ̨     : STM32F407ZGT6-25MHz->168MHz
 * �޸�ʱ��     : 2014-10-20
 * ��    ��     : V1.0.0
 * Ӳ������     : STM32F40xx-STM32������
 * ˵    ��     :
 *
 *
**************************************************************************************/
#ifndef __W5500_SPI_H
#define __W5500_SPI_H
/* Includes---------------------------------------------*/
#include "User_config.h"
/* Private defines--------------------------------------*/
/*����W5500�ĵ�Դ���ƹܽ�*/
#define WIZ_Pwr			   GPIO_Pin_9
#define WIZ_Pwr_PORT	   GPIOA
#define WIZ_Pwr_RCC	       RCC_APB2Periph_GPIOA
/*����W5500��Ƭѡ�ܽ�*/
#define WIZ_SCS			   GPIO_Pin_12
#define WIZ_SCS_PORT	   GPIOA
#define WIZ_SCS_RCC	       RCC_APB2Periph_GPIOA    
/*����W5500��RESET�ܽ�*/
#define WIZ_RESET		   GPIO_Pin_10
#define WIZ_RESET_PORT	   GPIOA
#define WIZ_RESET_RCC	   RCC_APB2Periph_GPIOA
/*����W5500��INT�ܽ�*/
#define WIZ_INT			   GPIO_Pin_11
#define WIZ_INT_PORT	   GPIOA
#define WIZ_INT_RCC	       RCC_APB2Periph_GPIOA
///*����SPI��ΪW5500��Ӳ���ӿ�*/
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
void  W5500_RST(void);
void  Internet_Init(void);
void  W5500_SPI_Configuration(void);
uint8_t W5500_SPI_SendByte(uint8_t byte);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
#endif











