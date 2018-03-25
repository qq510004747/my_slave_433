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
#ifndef __BSP_InPut_H
#define __BSP_InPut_H
/* Includes---------------------------------------------*/
#include "sys.h"
/* Private defines--------------------------------------*/
#define  Echo   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6 )

#define Get_SWD1_GPIO_In		PAin(7)
#define Get_SWD2_GPIO_In		PAin(6)
#define Get_SWD3_GPIO_In		PAin(5)
#define Get_SWD4_GPIO_In		PAin(4)
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
/* Private functions -----------------------------------*/
void BSP_InPut_Init(void);
void EXTI_Initialization(void);
void In_Put_Handle_fun(void);
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
#endif

