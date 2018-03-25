/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
                   ARM Cortex-M3 Port
* �ļ���    : User_BSP.h
* ��  ��    :
* ��  ��	: MDK4.73-�̼���V3.5�汾
* ʵ��ƽ̨  : STM32F103RBT6-8MHz->72MHz
* ��  ��    : V1.0.0
* ��  ��    :
* �޸�ʱ��  : 2013-12-20
* Ӳ������  : STM32F10x-STM32������
*******************************************************************************/
#ifndef __User_BSP_H
#define __User_BSP_H
/* Includes---------------------------------------------*/
#include "main.h"
#include "BSP_InPut.h"
#include "BSP_InPut.h"
#include "User_BSP.h"
#include "TIMER3.h"


extern TaskHandle_t   xHandleRS485Task;
extern QueueHandle_t  xQueue_RS485;   //RS485��Ϣ�ж�
extern SemaphoreHandle_t xSem_swch1;  

extern uint16_t ADC_SHOW_Flag;
extern uint8_t SWD_1;
extern uint8_t SWD_2;
extern uint8_t SWD_3;
extern uint8_t SWD_4;
extern u16 adcx ;
extern u16 ADC_Voltage;

//extern uint8_t SWD_5;
//extern uint8_t SWD_6;

extern uint8_t ch1_flag;
extern uint8_t ch2_flag;
extern uint8_t ch3_flag;
extern uint8_t ch4_flag;
extern uint8_t ch5_flag;
extern uint8_t ch6_flag;
extern uint8_t ch7_flag;
extern uint8_t ch8_flag;

extern uint16_t ch1_time;
extern uint16_t ch2_time;
extern uint16_t ch3_time;
extern uint16_t ch4_time;
extern uint16_t ch5_time;
extern uint16_t ch6_time;
extern uint16_t ch7_time;
extern uint16_t ch8_time;

extern uint16_t km1_time ;
extern uint16_t km2_time ;
extern uint16_t km3_time ;
extern uint16_t km4_time ;
extern uint16_t km5_time ;
extern uint16_t km6_time ;
extern uint16_t km7_time ;
extern uint16_t km8_time ;

extern uint8_t KM_spikelamp_switch1;
extern uint8_t KM_voice_switch2;
extern uint8_t KM_led_switch3;
extern uint8_t KM_reserve1_switch;
extern uint8_t KM_reserve2_switch;
extern uint8_t KM_reserve3_switch;

#define KM_1 PBout(5)
#define KM_2 PBout(4)
#define KM_3 PBout(3)
#define KM_4 PDout(2)
#define KM_5 PCout(12)
#define KM_6 PCout(11)
#define KM_7 PCout(10)
#define KM_8 PAout(15)

#define SW_IN_1 PAin(3)
#define SW_IN_2 PAin(2)
#define SW_IN_3 PAin(1)
#define SW_IN_4 PAin(0)

//#define KM_1 PBout(5)
//#define KM_2 PBout(4)
//#define KM_3 PBout(3)
//#define KM_4 PDout(2)
//#define KM_5 PCout(12)
//#define KM_6 PCout(11)
//#define KM_7 PCout(10)
//#define KM_8 PAout(15)

/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
void User_BSP_Init(void);
extern void EXTI_Initialization(void);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
#endif

