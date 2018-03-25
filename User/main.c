/******************** (C) COPYRIGHT DIYǶ��ʽ����������*******************************
 *                                
 *                              ARM Cortex-M3 Port
 *
 * �ļ�����     : STM32F10x����ģ��V6.0.0
 * ��    ��     :  
 * ��    ��	 	  : MDK4.73-->�̼���V3.5�汾
 * ����ƽ̨     : TOP9110-STM32F103RBT6-8MHz->72MHz 
 * �޸�ʱ��     : 2013-12-20 
 * Ӳ������     : STM32F10x-STM32������
 * ˵    ��     : 				  
 * �޸ļ�¼     :
 * �汾��       :  ����          ����       ˵�� 
   V6.0.0       :  2014-09-13       1.�Ľ�V5.0.0ʹ��JLinkRTT printf������Ӳ�������ж�	
	                                          2.JLinkRTT printf������Դ: Program Size: Code=1600 
																						  RO-data=2 RW-data=120 ZI-data=2080  	 
**************************************************************************************/
/* Includes---------------------------------------------*/
#include "main.h"
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
#define Start_Task_PRIO			( ( unsigned portBASE_TYPE ) 2U )
bool gCanAskForDataPeriod 	= false;
bool gMeshFinished 			= false;
bool gGetStartNewMeshAck 	= false;
itas_msg_t	gITASMsg;
node_t node[NODE_ID_NUM_MAX]; //! note: the node[0] store the master's own info.
node_t current_node;
itas_mode_t meshMode = MESH_MODE_UNINIT;


/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
/* Private functions -----------------------------------*/
/*********************************************************
*	�� �� ��: main
*	����˵��: c�������
*	��    �Σ���
*	�� �� ֵ: �������(���账��)
**********************************************************/
int main(void)
{
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4
	xTaskCreate( vStart_Task, //��������
	             "StartTask", //���������Ե�������
	             configMINIMAL_STACK_SIZE, //�ں�Ϊ��������ջ�ռ��С usStackDepth ��
	             NULL, 
	             Start_Task_PRIO,          //����ִ�е����ȼ�
	             NULL 
	           );//����һ����LED1��˸������	
	vTaskStartScheduler();	//��ʼ�������
}
/************************END OF MAIN**********************/
#ifdef USE_FULL_ASSERT
/*****************************************
*	�� �� ��: assert_failed
*	��    �Σ�file : Դ�����ļ����ơ��ؼ���__FILE__��ʾԴ�����ļ�����
*			  line �������кš��ؼ��� __LINE__ ��ʾԴ�����к�
*	�� �� ֵ: ��
*******************************************/
void assert_failed(uint8_t* file, uint32_t line)
{ 
	/* 
		�û���������Լ��Ĵ��뱨��Դ�����ļ����ʹ����кţ����罫�����ļ����кŴ�ӡ������
		printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* ����һ����ѭ��������ʧ��ʱ������ڴ˴��������Ա����û���� */
	while (1)
	{
	}
}

//! twice of askForDataPeriod() in running frequency(rate)




#endif
/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
