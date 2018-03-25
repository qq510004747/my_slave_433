#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//ADC ����	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/7
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define NUMBER_ANALOG_ADC1			6
#define ADC1_DR_Address				((uint32_t)0x40012400+0x4c)
//! adc

#define		ADC_CH_I_1		((uint8_t)0x0D)
#define		ADC_CH_I_2		((uint8_t)0x00)
#define		ADC_CH_I_3		((uint8_t)0x01)

#define	ADC_RCC_APB2Periph			(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC)
#define	ADC_RCC_APB2Periph_ADC1		 RCC_APB2Periph_ADC1
#define	ADC_GPIO_PIN_V_R			 GPIO_Pin_6		//! PA.06
#define	ADC_GPIO_PIN_C_R			 GPIO_Pin_7		//! PA.07
#define	ADC_GPIO_PIN_V_Y			 GPIO_Pin_4		//! PA.04
#define	ADC_GPIO_PIN_C_Y			 GPIO_Pin_5		//! PA.05
#define	ADC_GPIO_PIN_V_G			 GPIO_Pin_0		//! PC.00
#define	ADC_GPIO_PIN_C_G			 GPIO_Pin_1		//! PC.01
#define	ADC_CHANNEL_V_R				 ADC_Channel_6	//! ADC1_IN6
#define ADC_CHANNEL_C_R				 ADC_Channel_7	//! ADC1_IN7
#define	ADC_CHANNEL_V_Y				 ADC_Channel_4	//! ADC1_IN4
#define ADC_CHANNEL_C_Y				 ADC_Channel_5	//! ADC1_IN5
#define	ADC_CHANNEL_V_G				 ADC_Channel_10	//! ADC1_IN10
#define ADC_CHANNEL_C_G				 ADC_Channel_11	//! ADC1_IN11
#define ADC_GPIOA_PINS				(ADC_GPIO_PIN_V_R | ADC_GPIO_PIN_C_R | ADC_GPIO_PIN_V_Y | ADC_GPIO_PIN_C_Y)
#define ADC_GPIOC_PINS				(ADC_GPIO_PIN_V_G | ADC_GPIO_PIN_C_G)



void Adc_Init(void);
u16  Get_Adc(u8 ch); 
u16 Get_Adc(u8 ADC_Channel)  ; 
u16 Get_Adc_Average(u8 ch,u8 times); 


#endif 
