/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
 * �ļ���   ��BSP_OutPut.h
 * ����	 	  : MDK4.73-�̼���V3.5-uCOS III V3.03�汾
 * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
 * �汾     ��V1.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ : STM32F10x-STM32������
 * ����     : ϵͳ������������ļ�
*******************************************************************************/
#ifndef __TCP_H
#define __TCP_H
/* Includes---------------------------------------------*/
#include "sys.h"
/* Private defines--------------------------------------*/

/*************************************************************LORAƽ̨������ʼ��*****************************************************************/
#define Server_Mode
//#define Client_Mode

extern uint8_t Internet_Rxbuff[256];	/*����һ��1KB�Ļ���*/
//extern uint8_t Play_Music[8];	/*��ѯ�ɶ��ļ�����*/
//extern uint8_t Play_Music[8],

extern uint8_t Play_Music[8];/*�����������001*/
//extern uint8_t Play_Music[8];	/*�������FLASH1*/
//extern uint8_t Play_Music[8];	/*ѭ����������001*/
//extern uint8_t Play_Music[8];	/*ѭ����������*/
extern uint8_t Internet_Txbuff[8];	/*�����������001*/
extern uint8_t ALL_AA_FF[8];	/*�����������001*/
extern uint8_t ALL_AA[8];	/*�����������001*/
extern uint8_t ALL_FF[8];	/*�����������001*/

/* Private function prototypes--------------------------*/
uint8_t TCP_Client_Demo(uint8_t *BUFF,uint8_t SendLen);
uint8_t TCP_Server_Demo(uint8_t *BUFF,uint8_t SendLen);
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
#endif

