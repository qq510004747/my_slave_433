/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
				ARM Cortex-M4 Port
* �ļ���    : User_Config.h
* ��  ��    : �û�ϵͳ��Դ�Զ����ļ�
* ��  ��	: MDK5.20_StdPeriph_Driver V1.5 For Cortex-M4
* ʵ��ƽ̨  : 
* ��  ��    : V1.0.0
* ��  ��    :
* �޸�ʱ��  : 2013-12-20
* Ӳ������  : STM32F40x-STM32������
* �޸ļ�¼  :
* �汾��  ����        ����     ˵��
* V1.0    2013-03-01 
*******************************************************************************/
#ifndef __User_Config_H
#define __User_Config_H
/* Includes---------------------------------------------*/
#include "Utility.h"
//#include "./CmdMsg/NetCmd.h"
//#include "./BSP_Config/BSP_PwrConfig.h"
//#include "./BSP_Config/BSP_CHZConfig.h"
//#include "./BSP_AT24Cxx/IAP_EEPROMPAGE.h"
/* Private defines--------------------------------------*/
//#if USE_FreeRTOS == TRUE     //* ����ȫ���жϵĺ� *
//	#define DISABLE_INT()    taskENTER_CRITICAL()
//	#define ENABLE_INT()     taskEXIT_CRITICAL()
//#else	
//	#define ENABLE_INT()	 __set_PRIMASK(0)	//* ʹ��ȫ���ж� *
//	#define DISABLE_INT()	 __set_PRIMASK(1)	//* ��ֹȫ���ж� *
//#endif
/*--------- ϵͳ��������  ------------------------------*/ 
//#define  USE_FreeRTOS           TRUE    //* ���� ʹ��RTOS   *
//#define  STM32_BSP_VERSION		"V2.0"  //* ���� BSP �汾�� *
////#define  DEBUG_MODE             TRUE    //* !TRUE�رմ�ӡ���ԣ�TRUE������ӡ����

// -----��ʼֵ------------------------------

/*--------- ϵͳ�������ó������壨20.16.12.08V2.0�� --------*/ 
#define High       1     //����ߵ�ƽ
#define Low        0     //����͵�ƽ
#define Open       1    
#define Close      0
#define Err        1     //�й���
#define NoErr      0     //û�й���
#define Noused     0xFF  //û��ʹ�ã�Ԥ��
#define RepairBase 10    //���޸��������û������Կ���rs485�ײ��豸����ͨ�ŵ�ʱ��

/* Private typedef -------------------------------------*/

/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/

extern uint8_t  HardWareVERSION[]; // ���� BSP  �汾�� 
extern uint8_t  AppVERSION[];      // ���� App  �汾�� 
extern uint8_t  ProductSN[];       // �����ƷSN
/* Private function prototypes -------------------------*/

/* Private functions -----------------------------------*/
#endif

