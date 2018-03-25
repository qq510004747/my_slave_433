///**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
// * �ļ���   ��APPtask.c
// * ����     : ϵͳ������
// * ����	 	  : MDK4.54-�̼���V3.5-FreeRTOS V8.0.0 �汾
// * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
// * �汾     ��V0.0.0
// * ����     ��
// * �޸�ʱ�� ��2013-12-20
// * Ӳ������ : FreeRTOS-STM32������
//********************************************************************************/
///* Includes---------------------------------------------*/
//#include "main.h"
//#include "sys.h"
//#include "stdlib.h"
//// #include<stdlib.h>

///* Private defines--------------------------------------*/
////xTaskHandle     Task_Handle;
////xTaskHandle     Demo_Handle;
////���ȼ�
//#define Switch_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )
//#define Trigger_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )
//#define MESH_Task_PRIO		( ( unsigned portBASE_TYPE ) 3U )
//#define LORA_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )	
//#define TCP_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )	

////�ں�Ϊ��������ջ�ռ��С	
//#define Switch_Task_STACK			( ( unsigned short )  512 )
//#define Trigger_Task_STACK     	( ( unsigned short )  512)
//#define MESH_Task_STACK 	( ( unsigned short )  512 )
//#define LORA_Task_STACK 		( ( unsigned short )  512 )
//#define TCP_Task_STACK 		( ( unsigned short )  512 )
//	


///* Private function prototypes--------------------------*/
//static void vSwitch_Task( void *pvParameters );
//static void vTrigger_Task( void *pvParameters );
//static void vMESH_Task( void *pvParameters );
//static void vLORA_Task(  void *pvParameters );
//static void vTCP_Task(  void *pvParameters );

//u8 Send[6] = {0xff,0xff,0xff,0xff,0xff,0xff};
//u8 num[6] = {0x30,0x31,0x32,0x33,0x34,0x35};
//char letter[6] = {'a','b','c','d','e','f'};

//#define  NetControlCommadptMsgLen     NetSerSendPerLen    //���ڷ����������Ŀ������������Ϣ���ȶ���
//#define  NetSerSendPerLen     84   //���������͵�Դ��ֵ�������ݳ���
//#define	 RepairBase 10    //���޸��������û������Կ���rs485�ײ��豸����ͨ�ŵ�ʱ��
//#define  ptMsgNum                     10                  //��Ϣ���еĴ�С
//const TickType_t xMaxBlockTime = pdMS_TO_TICKS(20*RepairBase); /* �������ȴ�ʱ��Ϊ10*RepairBase ms =100ms */



//typedef struct _Net_ptMsg    //V2.0����TCP Server��ͨ���ж���Ϣ������Ϣ
//{
//	uint8_t  SerCMD;    //����������������
//	uint8_t  StatusCMD; //Ҫ����RS485�豸״̬����
//	uint8_t   usData[NetControlCommadptMsgLen];
//}_ptMsg;

//_ptMsg  *ptMsg;
//_ptMsg  *ptClientMsg;
//BaseType_t xResult;

//TaskHandle_t   xHandleRS485Task = NULL;
//QueueHandle_t  xQueue_RS485  = NULL;   //RS485��Ϣ�ж�
//SemaphoreHandle_t xSem_swch1  = NULL;  

// _ptMsg            NetRS485Msg; //V2.0

//u8 t = 0;


//void AppObjCreate (void)
//{
//    xQueue_RS485 = xQueueCreate(8, 50);//sizeof(uint8_t)
//    if( xQueue_RS485 == NULL ){ /* û�д����ɹ����û�������������봴��ʧ�ܵĴ������ */}
//	
//	    /* �����ź��� */  
//   xSem_swch1 = xSemaphoreCreateBinary();  
//   
//   if( xSem_swch1 == NULL )  
//   {  
//       /* ���ջ���㣬�ź�������ʧ�ܣ��������ʧ�ܴ���*/  
//   } 
//}
///* Private functions -----------------------------------*/
///**********************************************
//*	�� �� ��: void vStart_Task( void *pvParameters )
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: ϵͳ��ʼ��������һ��ɾ����			
//**********************************************/ 
//void vStart_Task( void *pvParameters )
//{
//	BSP_Init();	
//	AppObjCreate ();
////	vTaskDelay(50);
//	while(1)
//	{		
//		xTaskCreate( vSwitch_Task, 	//��������
//	               "vSwitch_Task",  //���������Ե�������
//								 Switch_Task_STACK, //�ں�Ϊ��������ջ�ռ��С usStackDepth ��
//								 NULL, 
//								 Switch_Task_PRIO, 	//����ִ�е����ȼ�
//								 NULL);	  //����һ����LED1��˸������	 
//							 
//		xTaskCreate( vTrigger_Task, 	//��������
//	               "vTrigger_Task",  //���������Ե�������
//								 Trigger_Task_STACK, //�ں�Ϊ��������ջ�ռ��С usStackDepth ��
//								 NULL, 
//								 Trigger_Task_PRIO, 	//����ִ�е����ȼ�
//								 NULL);		//����һ����LED1��˸������
//		
//		xTaskCreate( vMESH_Task, 	//��������
//	               "vMESH_Task",  //���������Ե�������
//								 MESH_Task_STACK, //�ں�Ϊ��������ջ�ռ��С usStackDepth ��
//								 NULL, 
//								 MESH_Task_PRIO, 	//����ִ�е����ȼ�
//								 NULL);		//����һ����LED1��˸������
//		
////		xTaskCreate( vLORA_Task, 	//��������
////	               "vLORA_Task",  //���������Ե�������
////								 LORA_Task_STACK, //�ں�Ϊ��������ջ�ռ��С usStackDepth ��
////								 NULL, 
////								 LORA_Task_PRIO, 	//����ִ�е����ȼ�
////								 NULL);		//����һ����LED1��˸������
//								 
////		xTaskCreate( vTCP_Task, 	//��������
////	               "vTCP_Task",  //���������Ե�������
////								 TCP_Task_STACK, //�ں�Ϊ��������ջ�ռ��С usStackDepth ��
////								 NULL, 
////								 TCP_Task_PRIO, 	//����ִ�е����ȼ�
////								 NULL);		//����һ����LED1��˸������
//		
//		vTaskDelete( NULL );//ֻ����һ�Σ�ɾ���Լ�
//	}
//}
///**********************************************
//*	�� �� ��: static void vLED1_Task( void *pvParameters )
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: LED1����				
//**********************************************/ 
//static void vSwitch_Task( void *pvParameters )
//{
//	u8 Switch_Flag = 0;
////	u16 m=200,n=1000,x=1,y=20,RandvVlue=0;
////	u16  adc = 0;
////	u16  adc0 = 0;
////	u16  adc1 = 0;
//	while(1)
//	{
//		PCout(14) =~ PCout(14);
//		Switch_Flag = Get_Switch_Status();
//		Get_Switch_Message(Switch_Flag);
////		printf("current_node.location %d \r\n",current_node.location2);
////		PCout(14) =~ PCout(14);
////		adc0 = Get_Adc(ADC_Channel_10); 
////		adc1 = Get_Adc(ADC_Channel_11); 
////		adc = adc0 + adc1;
//////		printf("Get_Adc(ADC_Channel_10) %d \r\n",adc0);
//////		printf("Get_Adc(ADC_Channel_11) %d \r\n",adc1);
////		srand(adc%100);
////		RandvVlue = rand()%(n-m+1)+m;
////		printf("Get_Adc(ADC_Channel_10) %d : \r\n",RandvVlue);
////		printf("Get_Adc(ADC_Channel_10) %d \r\n",Get_Adc(ADC_Channel_10));
////		printf("current_node.slave_addr2 %d:  \r\n",current_node.slave_addr2);
////		printf("bad_cnt %d: slave_addr2 %d   \r\n",current_node.bad_cnt,current_node.slave_addr2);
////		printf("normal mode: ask for id times: %d \n", askForIdCnt);
//		vTaskDelay(500);		
//	}
//}
///**********************************************
//*	�� �� ��: static void vLED2_Task( void *pvParameters )
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: ����������				
//**********************************************/ 
//static void vTrigger_Task( void *pvParameters )
//{   
//	while(1)
//	{
////������
////		if((SWD_1 == 1)||(SW_IN_1 == 0))
////		{
////			current_node.trigger_vehicle1 = 1;
////		}
////		if((SWD_2 == 1)||(SW_IN_2 == 0))
////		{
////			current_node.trigger_video2 = 1;
////		}
//		
////		if((SWD_3 == 1)||(SW_IN_3 == 0))
////		{
////			current_node.trigger_microwave3 = 1;
////		}
////		if((SWD_4 == 1)||(SW_IN_4 == 0))
////		{
////			current_node.trigger_reserve1 = 1;
////		}
////		if(gMeshFinished)
////			PCout(14) = 0;
////		else
////			PCout(14) = 1;
//		
////		current_node.slave_addr2 = 0X01;
//		current_node.master_addr = 0x01;
////		current_node.location2   = 0X03;
////�������
////#define KM_1 PBout(3)
////#define KM_2 PDout(2)
////#define KM_3 PCout(12)
////#define KM_4 PCout(11)
////#define KM_5 PCout(10)
////#define KM_6 PAout(15)
//		if(current_node.spikelamp_switch1 == 1)
//		{
//			KM_1 = 0;
//		}

//		if(current_node.voice_switch2 == 1)
//		{
//			KM_2 = 0;
//		}

//		if(current_node.led_switch3 == 1)
//		{
//			KM_3 = 0;
//		}

//		if(current_node.reserve1_switch == 1)
//		{
//			KM_4 = 0;
//		}

//		if(current_node.reserve2_switch == 1)
//		{
//			KM_5 = 0;
//		}

//		if(current_node.reserve3_switch == 1)
//		{
//			KM_6 = 0;
//		}
//		 
////		if (current_node.bad_cnt > CURRENT_BAD_CNT_MAX) //! communication is bad ! run selfcheck !
////		current_node.slave_addr2 = 0;
//		
//		current_node.id = current_node.slave_addr2;
//		if(current_node.slave_addr2 == 0)
//		{
////			current_node.spikelamp_switch1 = 0;
////			current_node.voice_switch2     = 0;
////			current_node.led_switch3       = 0;
////			current_node.reserve1_switch   = 0;
////			current_node.reserve2_switch   = 0;
////			current_node.reserve3_switch   = 0;
//			KM_1 = 1;
//			KM_2 = 1;
//			KM_3 = 1;
//			KM_4 = 1;
//			KM_5 = 1;
//			KM_6 = 1;
//		}
//		if(current_node.bad_cnt > CURRENT_BAD_CNT_RESTAR) //��ʱ����++
//		{
//			systemReboot();
//		}
//		

////		printf("KM_1 %d:  \r\n",(uint8_t)KM_1);
////		printf("current_node.spikelamp_switch1 %d:  \r\n",(uint8_t)current_node.spikelamp_switch1);
////		printf("km1_time %d:  \r\n",(uint8_t)km1_time);	
//		vTaskDelay(2);	
//	}
//} 
///**********************************************
//*	�� �� ��: static void vMESH_Task( void *pvParameters )
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: MESH��ʾ����				
//**********************************************/ 
//static void vMESH_Task( void *pvParameters )
//{   
//	static uint8_t powerState = 1;
//	uint8_t RandvVlue = 1;
//	u16 m=60,n=400;
//	while(1)
//	{
//		
//		
////		if (powerState != gITASMsg.payload.power_state){	//! power_state: 0 -> 1 will cause system reboot
////			powerState  = gITASMsg.payload.power_state;
////			
////			if (powerState == 1) {
////				systemReboot();
////			}
////		}

//		parseRadioData();

//		switch(meshMode)
//		{

//		case MESH_MODE_UNINIT:
//			
//			meshMode = MESH_MODE_IDLE;
//			break;
//		
//		case MESH_MODE_IDLE://����
////				printf("MESH_MODE_IDLE  \r\n");
//			meshMode = MESH_MODE_START_MESH;
//			break;
//	
//		case MESH_MODE_START_MESH://��ʼ����
////				printf("MESH_MODE_START_MESH  \r\n");
////			srand(Get_Adc(ADC_Channel_10));
////			RandvVlue = rand()%(n-m+1)+m;
////			vTaskDelay(RandvVlue);
////			meshMode = MESH_MODE_MESH;//����
//			break;
//		
//		case MESH_MODE_MESH:
////				printf("  MESH_MODE_MESH \r\n");	
//			meshMode = taskMesh();
//			if (gGetStartNewMeshAck == false) {//! if not received ask for id msg?
//				meshMode = MESH_MODE_START_MESH;//��ʼ����
//				
//			} else if (gMeshFinished == true) {
//				meshMode = MESH_MODE_NORMAL;//��������
//			}	
//			break;
//		 
//		case MESH_MODE_NORMAL://��������
////			printf(" MESH_MODE_NORMAL \r\n");
//			meshMode = taskNormalMission();
//			break;

//		case MESH_MODE_SELF_CHECK://�����Լ�
////				printf(" MESH_MODE_SELF_CHECK \r\n");
//			break;
//		
//		case MESH_MODE_NONE:	//������״̬
////				printf(" MESH_MODE_NONE \r\n");
//			if (current_node.slave_addr2 == 0) 
//			{		//! it can come out of the NONE mode and start apply for id again
//				meshMode = MESH_MODE_START_MESH;
//			}
//			break;
//			
//		default :
//				break;
//		}
//	
//		vTaskDelay(2);
////		xEventGroupSetBits(xCreatedEventGroup, TASK_BIT_MESH);
//	}
////! can not be running into here
////	systemReboot();
//}

///**********************************************
//*	�� �� ��: static void vLORA_Task( void *pvParameters )
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: vLORA_Task��ʾ����				
//**********************************************/ 
//extern const uint8_t Function_TEST_Msg1[27];
//static void vLORA_Task( void *pvParameters )
//{   
//#if defined (SX1278_RX)
//    Radio->StartRx( );   //RFLR_STATE_RX_INIT
//#elif defined (SX1278_TX)
//	vTaskDelay(50);
//	Radio->SetTxPacket( Function_TEST_Msg1, 27 );
//#endif
//	{
//		static uint8_t powerState = 1;
//		
//		while(1)
//		{	
//			if (powerState != gITASMsg.payload.power_state) {	//! power_state: 0 -> 1 will cause system reboot
//				powerState  = gITASMsg.payload.power_state; //��ʼ��ʱΪ0
//				
//				if (powerState == 1) {
//					systemReboot();
//				}
//			}
//			parseRadioData();
////			switch(meshMode)
////			{
////			case MESH_MODE_UNINIT:
////			case MESH_MODE_IDLE:
////				meshMode = MESH_MODE_START_MESH;
////				break;
////			
////			case MESH_MODE_START_MESH:
////				startNewMesh();
//////				msg_ask_for_data_send(2);
////				meshMode = MESH_MODE_MESH;
////				break;

////			case MESH_MODE_MESH:                                                                  //???
////				if (gGetStartNewMeshAck == false) {	//! if not received ask for id msg?
////					meshMode = MESH_MODE_START_MESH;
////					
////				} else if (gMeshFinished == true) {
////					meshMode = MESH_MODE_NORMAL;		
////				}	
////				break;
////			
////			case MESH_MODE_NORMAL:
////				checkNodesStatePeriod();
////				askForDataPeriod();						
////				break;
////				
////			case MESH_MODE_SELF_CHECK:
////				break;
////			
////			case MESH_MODE_NONE:	
////				break;
////			}
//	//		xEventGroupSetBits(xCreatedEventGroup, TASK_BIT_MESH);//�¼���־�����״̬
//			
//			PBout(3) = ~PBout(3);
//			vTaskDelay(500);

//		}
//	}
//}

///**********************************************
//*	�� �� ��: static void vTCP_Task( void *pvParameters )
//*	��    �Σ�
//*	�� �� ֵ: 
//*	����˵��: TCP����
//**********************************************/ 
//static void vTCP_Task( void *pvParameters )
//{
////	u8 clitest,len;
////	Get_NetMsg();
////	Internet_Init();
////	printf("w5500initok \n");
//	while(W5500_Check_Link())  //û�в�������
//	{
//		Internet_Init();
//	}

//	while(1)
//	{
//		PBout(3) = ~PBout(3);
//		vTaskDelay(50);

//		PBout(3) = ~PBout(3);
//		vTaskDelay(50);
//	}
////	while (1)
////	{
////		PBout(3) = ~PBout(3);
////		vTaskDelay(50);

////		PBout(3) = ~PBout(3);
////		vTaskDelay(50);
//////		tcp server demo
////		switch(getSn_SR(SOCK_TCPS))									   /*��ȡsocket��״̬*/
////        {
////		case SOCK_CLOSED:											    /*socket���ڹر�״̬*/
////			socket(SOCK_TCPS ,Sn_MR_TCP,ConfigMsg.port,Sn_MR_ND);	     /*��socket*/
////			break;

////		case SOCK_INIT:													/*socket�ѳ�ʼ��״̬*/
////			listen(SOCK_TCPS);											/*socket��������*/
////			break;

////		case SOCK_ESTABLISHED:											/*socket�������ӽ���״̬*/
////			if(getSn_IR(SOCK_TCPS) & Sn_IR_CON)
////			{
////				setSn_IR(SOCK_TCPS, Sn_IR_CON);							/*��������жϱ�־λ*/
////			}
////			len=getSn_RX_RSR(SOCK_TCPS);							    /*����lenΪ�ѽ������ݵĳ���*/
////			if(len>0)
////			{
////				recv(SOCK_TCPS,Internet_Rxbuff,len);					/*��������Client������*/
////				send(SOCK_TCPS,ALL_FF,8);	/*��Client��������*/

//////				send(SOCK_TCPS,Internet_Rxbuff,len);	/*��Client��������*/
//////			    close(SOCK_TCPS);	//�����ӣ�ÿ�������һ�����ݣ��Ͽ�����
////			}	
////			break;
////		 case SOCK_CLOSE_WAIT:	/*socket���ڵȴ��ر�״̬*/
////			close(SOCK_TCPS);
////			break;
////       }
//////		clitest = TCP_Client_Demo(8);
////	}
//}
///********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/

/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
 * �ļ���   ��APPtask.c
 * ����     : ϵͳ������
 * ����	 	  : MDK4.54-�̼���V3.5-FreeRTOS V8.0.0 �汾
 * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
 * �汾     ��V0.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ : FreeRTOS-STM32������
********************************************************************************/
/* Includes---------------------------------------------*/
#include "main.h"
#include "sys.h"
#include "stdlib.h"
// #include<stdlib.h>

/* Private defines--------------------------------------*/
//xTaskHandle     Task_Handle;
//xTaskHandle     Demo_Handle;
//���ȼ�
#define Switch_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )
#define Trigger_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )
#define MESH_Task_PRIO		( ( unsigned portBASE_TYPE ) 3U )
#define LORA_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )	
#define TCP_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )	

//�ں�Ϊ��������ջ�ռ��С	
#define Switch_Task_STACK			( ( unsigned short )  512 )
#define Trigger_Task_STACK     	( ( unsigned short )  512)
#define MESH_Task_STACK 	( ( unsigned short )  512 )
#define LORA_Task_STACK 		( ( unsigned short )  512 )
#define TCP_Task_STACK 		( ( unsigned short )  512 )
	


/* Private function prototypes--------------------------*/
static void vSwitch_Task( void *pvParameters );
static void vTrigger_Task( void *pvParameters );
static void vMESH_Task( void *pvParameters );
static void vLORA_Task(  void *pvParameters );
static void vTCP_Task(  void *pvParameters );
u8 LED_Lingt_Flash_Faster = 0;
u16 LED_Lingt_Flash_Timer = 0;
u8 Send[6] = {0xff,0xff,0xff,0xff,0xff,0xff};
u8 num[6] = {0x30,0x31,0x32,0x33,0x34,0x35};
char letter[6] = {'a','b','c','d','e','f'};

#define  NetControlCommadptMsgLen     NetSerSendPerLen    //���ڷ����������Ŀ������������Ϣ���ȶ���
#define  NetSerSendPerLen     84   //���������͵�Դ��ֵ�������ݳ���
#define	 RepairBase 10    //���޸��������û������Կ���rs485�ײ��豸����ͨ�ŵ�ʱ��
#define  ptMsgNum                     10                  //��Ϣ���еĴ�С
const TickType_t xMaxBlockTime = pdMS_TO_TICKS(20*RepairBase); /* �������ȴ�ʱ��Ϊ10*RepairBase ms =100ms */



typedef struct _Net_ptMsg    //V2.0����TCP Server��ͨ���ж���Ϣ������Ϣ
{
	uint8_t  SerCMD;    //����������������
	uint8_t  StatusCMD; //Ҫ����RS485�豸״̬����
	uint8_t   usData[NetControlCommadptMsgLen];
}_ptMsg;

_ptMsg  *ptMsg;
_ptMsg  *ptClientMsg;
BaseType_t xResult;

TaskHandle_t   xHandleRS485Task = NULL;
QueueHandle_t  xQueue_RS485  = NULL;   //RS485��Ϣ�ж�
SemaphoreHandle_t xSem_swch1  = NULL;  

 _ptMsg            NetRS485Msg; //V2.0

u8 t = 0;


void AppObjCreate (void)
{
    xQueue_RS485 = xQueueCreate(8, 50);//sizeof(uint8_t)
    if( xQueue_RS485 == NULL ){ /* û�д����ɹ����û�������������봴��ʧ�ܵĴ������ */}
	
	    /* �����ź��� */  
   xSem_swch1 = xSemaphoreCreateBinary();  
   
   if( xSem_swch1 == NULL )  
   {  
       /* ���ջ���㣬�ź�������ʧ�ܣ��������ʧ�ܴ���*/  
   } 
}
/* Private functions -----------------------------------*/
/**********************************************
*	�� �� ��: void vStart_Task( void *pvParameters )
*	��    �Σ�
*	�� �� ֵ: 
*	����˵��: ϵͳ��ʼ��������һ��ɾ����			
**********************************************/ 
void vStart_Task( void *pvParameters )
{
	BSP_Init();	
	AppObjCreate ();
//	vTaskDelay(50);
	while(1)
	{		
		xTaskCreate( vSwitch_Task, 	//��������
	               "vSwitch_Task",  //���������Ե�������
								 Switch_Task_STACK, //�ں�Ϊ��������ջ�ռ��С usStackDepth ��
								 NULL, 
								 Switch_Task_PRIO, 	//����ִ�е����ȼ�
								 NULL);	  //����һ����LED1��˸������	 
							 
		xTaskCreate( vTrigger_Task, 	//��������
	               "vTrigger_Task",  //���������Ե�������
								 Trigger_Task_STACK, //�ں�Ϊ��������ջ�ռ��С usStackDepth ��
								 NULL, 
								 Trigger_Task_PRIO, 	//����ִ�е����ȼ�
								 NULL);		//����һ����LED1��˸������
		
		xTaskCreate( vMESH_Task, 	//��������
	               "vMESH_Task",  //���������Ե�������
								 MESH_Task_STACK, //�ں�Ϊ��������ջ�ռ��С usStackDepth ��
								 NULL, 
								 MESH_Task_PRIO, 	//����ִ�е����ȼ�
								 NULL);		//����һ����LED1��˸������
		
//		xTaskCreate( vLORA_Task, 	//��������
//	               "vLORA_Task",  //���������Ե�������
//								 LORA_Task_STACK, //�ں�Ϊ��������ջ�ռ��С usStackDepth ��
//								 NULL, 
//								 LORA_Task_PRIO, 	//����ִ�е����ȼ�
//								 NULL);		//����һ����LED1��˸������
								 
//		xTaskCreate( vTCP_Task, 	//��������
//	               "vTCP_Task",  //���������Ե�������
//								 TCP_Task_STACK, //�ں�Ϊ��������ջ�ռ��С usStackDepth ��
//								 NULL, 
//								 TCP_Task_PRIO, 	//����ִ�е����ȼ�
//								 NULL);		//����һ����LED1��˸������
		
		vTaskDelete( NULL );//ֻ����һ�Σ�ɾ���Լ�
	}
}
/**********************************************
*	�� �� ��: static void vLED1_Task( void *pvParameters )
*	��    �Σ�
*	�� �� ֵ: 
*	����˵��: LED1����				
**********************************************/ 
static void vSwitch_Task( void *pvParameters )
{
//	u16 m=200,n=1000,x=1,y=20,RandvVlue=0;
//	u16  adc = 0;
//	u16  adc0 = 0;
//	u16  adc1 = 0;
	while(1)
	{
		u8 Switch_Flag ;
//		wdgFeed();
		
		PCout(14) =~ PCout(14);
//		KM_8 =~ KM_8;
//		KM_7 =~ KM_7;

//		PCout(14) =~ PCout(14);
//		PCout(0) =~ PCout(0);
//		PCout(1) =~ PCout(1);


		Switch_Flag = Get_Switch_Status();
		Get_Switch_Message(Switch_Flag);
//		PCout(14) =~ PCout(14);
//		adc0 = Get_Adc(ADC_Channel_10); 
//		adc1 = Get_Adc(ADC_Channel_11); 
//		adc = adc0 + adc1;
////		printf("Get_Adc(ADC_Channel_10) %d \r\n",adc0);
////		printf("Get_Adc(ADC_Channel_11) %d \r\n",adc1);
//		srand(adc%100);
//		RandvVlue = rand()%(n-m+1)+m;
//		printf("Get_Adc(ADC_Channel_10) %d : \r\n",RandvVlue);
//		printf("Get_Adc(ADC_Channel_10) %d \r\n",Get_Adc(ADC_Channel_10));
//		printf("current_node.slave_addr2 %d:  \r\n",current_node.slave_addr2);
//		printf("bad_cnt %d: slave_addr2 %d   \r\n",current_node.bad_cnt,current_node.slave_addr2);
		vTaskDelay(500);		
	}
}
/**********************************************
*	�� �� ��: static void vLED2_Task( void *pvParameters )
*	��    �Σ�
*	�� �� ֵ: 
*	����˵��: ����������				
**********************************************/ 
static void vTrigger_Task( void *pvParameters )
{   
	while(1)
	{ 
		In_Put_Handle_fun(); 
		
		if((current_node.trigger_microwave3 == 1)||(Get_SWD2_GPIO_In == 0))
		{
//			timer2Init(1000); 
			LED_Lingt_Flash_Faster = 1;
			LED_Lingt_Flash_Timer = 200;
		}
		else
		{
//			timer2Init(2000);
			LED_Lingt_Flash_Faster = 0;
			KM_7 = 1;
		}
//������
//		if((SWD_1 == 1)||(SW_IN_1 == 0))
//		{
//			current_node.trigger_vehicle1 = 1;
//		}
//		if((SWD_2 == 1)||(SW_IN_2 == 0))
//		{
//			current_node.trigger_video2 = 1;
//		}
		
//		if((SWD_3 == 1)||(SW_IN_3 == 0))
//		{
//			current_node.trigger_microwave3 = 1;
//		}
//		if((SWD_4 == 1)||(SW_IN_4 == 0))
//		{
//			current_node.trigger_reserve1 = 1;
//		}
//		if(gMeshFinished)
//			PCout(14) = 0;
//		else
//			PCout(14) = 1;
		
//		current_node.slave_addr2 = 0X01;
		current_node.master_addr = 0x01;
//		current_node.location2   = 0X03;
//�������
//#define KM_1 PBout(3)
//#define KM_2 PDout(2)
//#define KM_3 PCout(12)
//#define KM_4 PCout(11)
//#define KM_5 PCout(10)
//#define KM_6 PAout(15)
		if(current_node.spikelamp_switch1 == 1)
		{
			KM_1 = 0;
		}

		if(current_node.voice_switch2 == 1)
		{
			KM_2 = 0;
		}

		if(current_node.led_switch3 == 1)
		{
			KM_3 = 0;
		}

		if(current_node.reserve1_switch == 1)
		{
			KM_4 = 0;
		}

		if(current_node.reserve2_switch == 1)
		{
			KM_5 = 0;
		}

		if(current_node.reserve3_switch == 1)
		{
			KM_6 = 0;
		}
		 
//		if (current_node.bad_cnt > CURRENT_BAD_CNT_MAX) //! communication is bad ! run selfcheck !
//		current_node.slave_addr2 = 0;
		
		current_node.id = current_node.slave_addr2;
		if(current_node.slave_addr2 == 0)
		{
//			current_node.spikelamp_switch1 = 0;
//			current_node.voice_switch2     = 0;
//			current_node.led_switch3       = 0;
//			current_node.reserve1_switch   = 0;
//			current_node.reserve2_switch   = 0;
//			current_node.reserve3_switch   = 0;
			KM_1 = 1;
			KM_2 = 1;
			KM_3 = 1;
			KM_4 = 1;
			KM_5 = 1;
			KM_6 = 1;
			KM_7 = 1;
			KM_8 = 1;
		}
		if(current_node.bad_cnt > CURRENT_BAD_CNT_RESTAR) //��ʱ����++
		{
			systemReboot();
		}
		

//		printf("KM_1 %d:  \r\n",(uint8_t)KM_1);
//		printf("current_node.spikelamp_switch1 %d:  \r\n",(uint8_t)current_node.spikelamp_switch1);
//		printf("km1_time %d:  \r\n",(uint8_t)km1_time);	
		vTaskDelay(2);	
	}
} 
/**********************************************
*	�� �� ��: static void vMESH_Task( void *pvParameters )
*	��    �Σ�
*	�� �� ֵ: 
*	����˵��: MESH��ʾ����				
**********************************************/ 
static void vMESH_Task( void *pvParameters )
{   
	static uint8_t powerState = 1;
	uint8_t RandvVlue = 1;
	u16 m=60,n=400;
	while(1)
	{
		
		
//		if (powerState != gITASMsg.payload.power_state){	//! power_state: 0 -> 1 will cause system reboot
//			powerState  = gITASMsg.payload.power_state;
//			
//			if (powerState == 1) {
//				systemReboot();
//			}
//		}
//		Lora_Handle();
		parseRadioData();

		switch(meshMode)
		{
		case MESH_MODE_UNINIT:
			meshMode = MESH_MODE_IDLE;
			break;
		
		case MESH_MODE_IDLE://����
			meshMode = MESH_MODE_START_MESH;
			break;
	
		case MESH_MODE_START_MESH://��ʼ����
			srand(Get_Adc(ADC_Channel_10));
			RandvVlue = rand()%(n-m+1)+m;
			vTaskDelay(RandvVlue);
			meshMode = MESH_MODE_MESH;//����
			break;
		
		case MESH_MODE_MESH:
			meshMode = taskMesh();
//			if (gGetStartNewMeshAck == false) {//! if not received ask for id msg?
//				meshMode = MESH_MODE_START_MESH;//��ʼ����
//				
//			} else if (gMeshFinished == true) {
//				meshMode = MESH_MODE_NORMAL;//��������
//			}	
			break;
		 
		case MESH_MODE_NORMAL://��������
			meshMode = taskNormalMission();
			break;

		case MESH_MODE_SELF_CHECK://�����Լ�
			break;
		
		case MESH_MODE_NONE:	//������״̬
				if (current_node.slave_addr2 == 0) {		//! it can come out of the NONE mode and start apply for id again
				meshMode = MESH_MODE_START_MESH;
			}
			break;
			
		default :
				break;
		}
	
		vTaskDelay(2);
//		xEventGroupSetBits(xCreatedEventGroup, TASK_BIT_MESH);
	}
//! can not be running into here
//	systemReboot();
}

/**********************************************
*	�� �� ��: static void vLORA_Task( void *pvParameters )
*	��    �Σ�
*	�� �� ֵ: 
*	����˵��: vLORA_Task��ʾ����				
**********************************************/ 
extern const uint8_t Function_TEST_Msg1[27];
static void vLORA_Task( void *pvParameters )
{   
#if defined (SX1278_RX)
    Radio->StartRx( );   //RFLR_STATE_RX_INIT
#elif defined (SX1278_TX)
	vTaskDelay(50);
	Radio->SetTxPacket( Function_TEST_Msg1, 27 );
#endif
	{
		static uint8_t powerState = 1;
		
		while(1)
		{	
			if (powerState != gITASMsg.payload.power_state) {	//! power_state: 0 -> 1 will cause system reboot
				powerState  = gITASMsg.payload.power_state; //��ʼ��ʱΪ0
				
				if (powerState == 1) {
					systemReboot();
				}
			}
			parseRadioData();
//			switch(meshMode)
//			{
//			case MESH_MODE_UNINIT:
//			case MESH_MODE_IDLE:
//				meshMode = MESH_MODE_START_MESH;
//				break;
//			
//			case MESH_MODE_START_MESH:
//				startNewMesh();
////				msg_ask_for_data_send(2);
//				meshMode = MESH_MODE_MESH;
//				break;

//			case MESH_MODE_MESH:                                                                  //???
//				if (gGetStartNewMeshAck == false) {	//! if not received ask for id msg?
//					meshMode = MESH_MODE_START_MESH;
//					
//				} else if (gMeshFinished == true) {
//					meshMode = MESH_MODE_NORMAL;		
//				}	
//				break;
//			
//			case MESH_MODE_NORMAL:
//				checkNodesStatePeriod();
//				askForDataPeriod();						
//				break;
//				
//			case MESH_MODE_SELF_CHECK:
//				break;
//			
//			case MESH_MODE_NONE:	
//				break;
//			}
	//		xEventGroupSetBits(xCreatedEventGroup, TASK_BIT_MESH);//�¼���־�����״̬
			
			PBout(3) = ~PBout(3);
			vTaskDelay(500);

		}
	}
}

/**********************************************
*	�� �� ��: static void vTCP_Task( void *pvParameters )
*	��    �Σ�
*	�� �� ֵ: 
*	����˵��: TCP����
**********************************************/ 
static void vTCP_Task( void *pvParameters )
{
//	u8 clitest,len;
//	Get_NetMsg();
//	Internet_Init();
//	printf("w5500initok \n");
	while(W5500_Check_Link())  //û�в�������
	{
		Internet_Init();
	}

	while(1)
	{
		PBout(3) = ~PBout(3);
		vTaskDelay(50);

		PBout(3) = ~PBout(3);
		vTaskDelay(50);
	}
//	while (1)
//	{
//		PBout(3) = ~PBout(3);
//		vTaskDelay(50);

//		PBout(3) = ~PBout(3);
//		vTaskDelay(50);
////		tcp server demo
//		switch(getSn_SR(SOCK_TCPS))									   /*��ȡsocket��״̬*/
//        {
//		case SOCK_CLOSED:											    /*socket���ڹر�״̬*/
//			socket(SOCK_TCPS ,Sn_MR_TCP,ConfigMsg.port,Sn_MR_ND);	     /*��socket*/
//			break;

//		case SOCK_INIT:													/*socket�ѳ�ʼ��״̬*/
//			listen(SOCK_TCPS);											/*socket��������*/
//			break;

//		case SOCK_ESTABLISHED:											/*socket�������ӽ���״̬*/
//			if(getSn_IR(SOCK_TCPS) & Sn_IR_CON)
//			{
//				setSn_IR(SOCK_TCPS, Sn_IR_CON);							/*��������жϱ�־λ*/
//			}
//			len=getSn_RX_RSR(SOCK_TCPS);							    /*����lenΪ�ѽ������ݵĳ���*/
//			if(len>0)
//			{
//				recv(SOCK_TCPS,Internet_Rxbuff,len);					/*��������Client������*/
//				send(SOCK_TCPS,ALL_FF,8);	/*��Client��������*/

////				send(SOCK_TCPS,Internet_Rxbuff,len);	/*��Client��������*/
////			    close(SOCK_TCPS);	//�����ӣ�ÿ�������һ�����ݣ��Ͽ�����
//			}	
//			break;
//		 case SOCK_CLOSE_WAIT:	/*socket���ڵȴ��ر�״̬*/
//			close(SOCK_TCPS);
//			break;
//       }
////		clitest = TCP_Client_Demo(8);
//	}
}
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/

