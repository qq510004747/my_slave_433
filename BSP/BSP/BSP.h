/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
 * �ļ���   ��BSP.h
 * ����     :
 * ����	 	  : MDK4.73-�̼���V3.5�汾
 * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
 * �汾     ��V1.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ : STM32F10x-STM32������
*******************************************************************************/
#ifndef __BSP_H
#define __BSP_H
/* Includes---------------------------------------------*/
#include "sys.h"
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
//extern volatile int32_t Sys_RunTime;
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
void BSP_Init(void);
void systemReboot(void);					/*STM32��λ*/
//NEWS ������North       ������East     ������West          �ϡ���South 
#define East  0     //��
#define South 1     //��
#define West  2		//��
#define North 3		//��

//void Delay(u32 nCount);         
//void Delay_us(u32 Nus);
//void Delay_ms(uint32_t Nms);
//int32_t bsp_GetRunTime(void);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
#endif

