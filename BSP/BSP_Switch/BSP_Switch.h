/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
 * �ļ���   ��BSP_InPut.h
 * ����	 	  : MDK4.73-�̼���V3.5�汾
 * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
 * �汾     ��V1.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ : STM32F10x-STM32������
 * ����     : ϵͳ�������������ļ�
*******************************************************************************/
#ifndef __BSP_SWITCH_H
#define __BSP_SWITCH_H
/* Includes---------------------------------------------*/
#include "sys.h"
/* Private defines--------------------------------------*/
//#define  Echo   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6 )
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
/* Private functions -----------------------------------*/
void BSP_Switch_Init(void);
u8 Get_Switch_Status(void);
void Get_Switch_Message(u8 switch_flag);
extern u8 Switch_Status;
extern u8 Location_Flag;

/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
#endif

