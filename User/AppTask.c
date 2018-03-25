///**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
// * 文件名   ：APPtask.c
// * 描述     : 系统任务处理
// * 环境	 	  : MDK4.54-固件库V3.5-FreeRTOS V8.0.0 版本
// * 实验平台 ：TOP9110-STM32F103RBT6-8MHz->72MHz
// * 版本     ：V0.0.0
// * 作者     ：
// * 修改时间 ：2013-12-20
// * 硬件连接 : FreeRTOS-STM32开发板
//********************************************************************************/
///* Includes---------------------------------------------*/
//#include "main.h"
//#include "sys.h"
//#include "stdlib.h"
//// #include<stdlib.h>

///* Private defines--------------------------------------*/
////xTaskHandle     Task_Handle;
////xTaskHandle     Demo_Handle;
////优先级
//#define Switch_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )
//#define Trigger_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )
//#define MESH_Task_PRIO		( ( unsigned portBASE_TYPE ) 3U )
//#define LORA_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )	
//#define TCP_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )	

////内核为任务分配堆栈空间大小	
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

//#define  NetControlCommadptMsgLen     NetSerSendPerLen    //用于服务器发来的控制命令队列信息长度定义
//#define  NetSerSendPerLen     84   //服务器发送电源阀值命令数据长度
//#define	 RepairBase 10    //自修复基数，该基数可以控制rs485底层设备重新通信的时间
//#define  ptMsgNum                     10                  //消息队列的大小
//const TickType_t xMaxBlockTime = pdMS_TO_TICKS(20*RepairBase); /* 设置最大等待时间为10*RepairBase ms =100ms */



//typedef struct _Net_ptMsg    //V2.0用于TCP Server中通过列队信息发送消息
//{
//	uint8_t  SerCMD;    //服务器发来的命令
//	uint8_t  StatusCMD; //要控制RS485设备状态命令
//	uint8_t   usData[NetControlCommadptMsgLen];
//}_ptMsg;

//_ptMsg  *ptMsg;
//_ptMsg  *ptClientMsg;
//BaseType_t xResult;

//TaskHandle_t   xHandleRS485Task = NULL;
//QueueHandle_t  xQueue_RS485  = NULL;   //RS485消息列队
//SemaphoreHandle_t xSem_swch1  = NULL;  

// _ptMsg            NetRS485Msg; //V2.0

//u8 t = 0;


//void AppObjCreate (void)
//{
//    xQueue_RS485 = xQueueCreate(8, 50);//sizeof(uint8_t)
//    if( xQueue_RS485 == NULL ){ /* 没有创建成功，用户可以在这里加入创建失败的处理机制 */}
//	
//	    /* 创建信号量 */  
//   xSem_swch1 = xSemaphoreCreateBinary();  
//   
//   if( xSem_swch1 == NULL )  
//   {  
//       /* 因堆栈不足，信号量创建失败，这里进行失败处理*/  
//   } 
//}
///* Private functions -----------------------------------*/
///**********************************************
//*	函 数 名: void vStart_Task( void *pvParameters )
//*	形    参：
//*	返 回 值: 
//*	功能说明: 系统开始任务，运行一次删除。			
//**********************************************/ 
//void vStart_Task( void *pvParameters )
//{
//	BSP_Init();	
//	AppObjCreate ();
////	vTaskDelay(50);
//	while(1)
//	{		
//		xTaskCreate( vSwitch_Task, 	//任务函数名
//	               "vSwitch_Task",  //具有描述性的任务名
//								 Switch_Task_STACK, //内核为任务分配堆栈空间大小 usStackDepth 字
//								 NULL, 
//								 Switch_Task_PRIO, 	//任务执行的优先级
//								 NULL);	  //创建一个让LED1闪烁的任务	 
//							 
//		xTaskCreate( vTrigger_Task, 	//任务函数名
//	               "vTrigger_Task",  //具有描述性的任务名
//								 Trigger_Task_STACK, //内核为任务分配堆栈空间大小 usStackDepth 字
//								 NULL, 
//								 Trigger_Task_PRIO, 	//任务执行的优先级
//								 NULL);		//创建一个让LED1闪烁的任务
//		
//		xTaskCreate( vMESH_Task, 	//任务函数名
//	               "vMESH_Task",  //具有描述性的任务名
//								 MESH_Task_STACK, //内核为任务分配堆栈空间大小 usStackDepth 字
//								 NULL, 
//								 MESH_Task_PRIO, 	//任务执行的优先级
//								 NULL);		//创建一个让LED1闪烁的任务
//		
////		xTaskCreate( vLORA_Task, 	//任务函数名
////	               "vLORA_Task",  //具有描述性的任务名
////								 LORA_Task_STACK, //内核为任务分配堆栈空间大小 usStackDepth 字
////								 NULL, 
////								 LORA_Task_PRIO, 	//任务执行的优先级
////								 NULL);		//创建一个让LED1闪烁的任务
//								 
////		xTaskCreate( vTCP_Task, 	//任务函数名
////	               "vTCP_Task",  //具有描述性的任务名
////								 TCP_Task_STACK, //内核为任务分配堆栈空间大小 usStackDepth 字
////								 NULL, 
////								 TCP_Task_PRIO, 	//任务执行的优先级
////								 NULL);		//创建一个让LED1闪烁的任务
//		
//		vTaskDelete( NULL );//只运行一次，删除自己
//	}
//}
///**********************************************
//*	函 数 名: static void vLED1_Task( void *pvParameters )
//*	形    参：
//*	返 回 值: 
//*	功能说明: LED1任务				
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
//*	函 数 名: static void vLED2_Task( void *pvParameters )
//*	形    参：
//*	返 回 值: 
//*	功能说明: 输入检测任务				
//**********************************************/ 
//static void vTrigger_Task( void *pvParameters )
//{   
//	while(1)
//	{
////输入检测
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
////输出控制
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
//		if(current_node.bad_cnt > CURRENT_BAD_CNT_RESTAR) //定时器中++
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
//*	函 数 名: static void vMESH_Task( void *pvParameters )
//*	形    参：
//*	返 回 值: 
//*	功能说明: MESH显示任务，				
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
//		case MESH_MODE_IDLE://空闲
////				printf("MESH_MODE_IDLE  \r\n");
//			meshMode = MESH_MODE_START_MESH;
//			break;
//	
//		case MESH_MODE_START_MESH://开始组网
////				printf("MESH_MODE_START_MESH  \r\n");
////			srand(Get_Adc(ADC_Channel_10));
////			RandvVlue = rand()%(n-m+1)+m;
////			vTaskDelay(RandvVlue);
////			meshMode = MESH_MODE_MESH;//组网
//			break;
//		
//		case MESH_MODE_MESH:
////				printf("  MESH_MODE_MESH \r\n");	
//			meshMode = taskMesh();
//			if (gGetStartNewMeshAck == false) {//! if not received ask for id msg?
//				meshMode = MESH_MODE_START_MESH;//开始组网
//				
//			} else if (gMeshFinished == true) {
//				meshMode = MESH_MODE_NORMAL;//组网正常
//			}	
//			break;
//		 
//		case MESH_MODE_NORMAL://组网正常
////			printf(" MESH_MODE_NORMAL \r\n");
//			meshMode = taskNormalMission();
//			break;

//		case MESH_MODE_SELF_CHECK://组网自检
////				printf(" MESH_MODE_SELF_CHECK \r\n");
//			break;
//		
//		case MESH_MODE_NONE:	//非组网状态
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
//*	函 数 名: static void vLORA_Task( void *pvParameters )
//*	形    参：
//*	返 回 值: 
//*	功能说明: vLORA_Task显示任务，				
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
//				powerState  = gITASMsg.payload.power_state; //初始化时为0
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
//	//		xEventGroupSetBits(xCreatedEventGroup, TASK_BIT_MESH);//事件标志组代表状态
//			
//			PBout(3) = ~PBout(3);
//			vTaskDelay(500);

//		}
//	}
//}

///**********************************************
//*	函 数 名: static void vTCP_Task( void *pvParameters )
//*	形    参：
//*	返 回 值: 
//*	功能说明: TCP任务
//**********************************************/ 
//static void vTCP_Task( void *pvParameters )
//{
////	u8 clitest,len;
////	Get_NetMsg();
////	Internet_Init();
////	printf("w5500initok \n");
//	while(W5500_Check_Link())  //没有插入网线
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
////		switch(getSn_SR(SOCK_TCPS))									   /*获取socket的状态*/
////        {
////		case SOCK_CLOSED:											    /*socket处于关闭状态*/
////			socket(SOCK_TCPS ,Sn_MR_TCP,ConfigMsg.port,Sn_MR_ND);	     /*打开socket*/
////			break;

////		case SOCK_INIT:													/*socket已初始化状态*/
////			listen(SOCK_TCPS);											/*socket建立监听*/
////			break;

////		case SOCK_ESTABLISHED:											/*socket处于连接建立状态*/
////			if(getSn_IR(SOCK_TCPS) & Sn_IR_CON)
////			{
////				setSn_IR(SOCK_TCPS, Sn_IR_CON);							/*清除接收中断标志位*/
////			}
////			len=getSn_RX_RSR(SOCK_TCPS);							    /*定义len为已接收数据的长度*/
////			if(len>0)
////			{
////				recv(SOCK_TCPS,Internet_Rxbuff,len);					/*接收来自Client的数据*/
////				send(SOCK_TCPS,ALL_FF,8);	/*向Client发送数据*/

//////				send(SOCK_TCPS,Internet_Rxbuff,len);	/*向Client发送数据*/
//////			    close(SOCK_TCPS);	//短连接，每接受完成一次数据，断开连接
////			}	
////			break;
////		 case SOCK_CLOSE_WAIT:	/*socket处于等待关闭状态*/
////			close(SOCK_TCPS);
////			break;
////       }
//////		clitest = TCP_Client_Demo(8);
////	}
//}
///********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/

/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：APPtask.c
 * 描述     : 系统任务处理
 * 环境	 	  : MDK4.54-固件库V3.5-FreeRTOS V8.0.0 版本
 * 实验平台 ：TOP9110-STM32F103RBT6-8MHz->72MHz
 * 版本     ：V0.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 : FreeRTOS-STM32开发板
********************************************************************************/
/* Includes---------------------------------------------*/
#include "main.h"
#include "sys.h"
#include "stdlib.h"
// #include<stdlib.h>

/* Private defines--------------------------------------*/
//xTaskHandle     Task_Handle;
//xTaskHandle     Demo_Handle;
//优先级
#define Switch_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )
#define Trigger_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )
#define MESH_Task_PRIO		( ( unsigned portBASE_TYPE ) 3U )
#define LORA_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )	
#define TCP_Task_PRIO			( ( unsigned portBASE_TYPE ) 3U )	

//内核为任务分配堆栈空间大小	
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

#define  NetControlCommadptMsgLen     NetSerSendPerLen    //用于服务器发来的控制命令队列信息长度定义
#define  NetSerSendPerLen     84   //服务器发送电源阀值命令数据长度
#define	 RepairBase 10    //自修复基数，该基数可以控制rs485底层设备重新通信的时间
#define  ptMsgNum                     10                  //消息队列的大小
const TickType_t xMaxBlockTime = pdMS_TO_TICKS(20*RepairBase); /* 设置最大等待时间为10*RepairBase ms =100ms */



typedef struct _Net_ptMsg    //V2.0用于TCP Server中通过列队信息发送消息
{
	uint8_t  SerCMD;    //服务器发来的命令
	uint8_t  StatusCMD; //要控制RS485设备状态命令
	uint8_t   usData[NetControlCommadptMsgLen];
}_ptMsg;

_ptMsg  *ptMsg;
_ptMsg  *ptClientMsg;
BaseType_t xResult;

TaskHandle_t   xHandleRS485Task = NULL;
QueueHandle_t  xQueue_RS485  = NULL;   //RS485消息列队
SemaphoreHandle_t xSem_swch1  = NULL;  

 _ptMsg            NetRS485Msg; //V2.0

u8 t = 0;


void AppObjCreate (void)
{
    xQueue_RS485 = xQueueCreate(8, 50);//sizeof(uint8_t)
    if( xQueue_RS485 == NULL ){ /* 没有创建成功，用户可以在这里加入创建失败的处理机制 */}
	
	    /* 创建信号量 */  
   xSem_swch1 = xSemaphoreCreateBinary();  
   
   if( xSem_swch1 == NULL )  
   {  
       /* 因堆栈不足，信号量创建失败，这里进行失败处理*/  
   } 
}
/* Private functions -----------------------------------*/
/**********************************************
*	函 数 名: void vStart_Task( void *pvParameters )
*	形    参：
*	返 回 值: 
*	功能说明: 系统开始任务，运行一次删除。			
**********************************************/ 
void vStart_Task( void *pvParameters )
{
	BSP_Init();	
	AppObjCreate ();
//	vTaskDelay(50);
	while(1)
	{		
		xTaskCreate( vSwitch_Task, 	//任务函数名
	               "vSwitch_Task",  //具有描述性的任务名
								 Switch_Task_STACK, //内核为任务分配堆栈空间大小 usStackDepth 字
								 NULL, 
								 Switch_Task_PRIO, 	//任务执行的优先级
								 NULL);	  //创建一个让LED1闪烁的任务	 
							 
		xTaskCreate( vTrigger_Task, 	//任务函数名
	               "vTrigger_Task",  //具有描述性的任务名
								 Trigger_Task_STACK, //内核为任务分配堆栈空间大小 usStackDepth 字
								 NULL, 
								 Trigger_Task_PRIO, 	//任务执行的优先级
								 NULL);		//创建一个让LED1闪烁的任务
		
		xTaskCreate( vMESH_Task, 	//任务函数名
	               "vMESH_Task",  //具有描述性的任务名
								 MESH_Task_STACK, //内核为任务分配堆栈空间大小 usStackDepth 字
								 NULL, 
								 MESH_Task_PRIO, 	//任务执行的优先级
								 NULL);		//创建一个让LED1闪烁的任务
		
//		xTaskCreate( vLORA_Task, 	//任务函数名
//	               "vLORA_Task",  //具有描述性的任务名
//								 LORA_Task_STACK, //内核为任务分配堆栈空间大小 usStackDepth 字
//								 NULL, 
//								 LORA_Task_PRIO, 	//任务执行的优先级
//								 NULL);		//创建一个让LED1闪烁的任务
								 
//		xTaskCreate( vTCP_Task, 	//任务函数名
//	               "vTCP_Task",  //具有描述性的任务名
//								 TCP_Task_STACK, //内核为任务分配堆栈空间大小 usStackDepth 字
//								 NULL, 
//								 TCP_Task_PRIO, 	//任务执行的优先级
//								 NULL);		//创建一个让LED1闪烁的任务
		
		vTaskDelete( NULL );//只运行一次，删除自己
	}
}
/**********************************************
*	函 数 名: static void vLED1_Task( void *pvParameters )
*	形    参：
*	返 回 值: 
*	功能说明: LED1任务				
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
*	函 数 名: static void vLED2_Task( void *pvParameters )
*	形    参：
*	返 回 值: 
*	功能说明: 输入检测任务				
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
//输入检测
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
//输出控制
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
		if(current_node.bad_cnt > CURRENT_BAD_CNT_RESTAR) //定时器中++
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
*	函 数 名: static void vMESH_Task( void *pvParameters )
*	形    参：
*	返 回 值: 
*	功能说明: MESH显示任务，				
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
		
		case MESH_MODE_IDLE://空闲
			meshMode = MESH_MODE_START_MESH;
			break;
	
		case MESH_MODE_START_MESH://开始组网
			srand(Get_Adc(ADC_Channel_10));
			RandvVlue = rand()%(n-m+1)+m;
			vTaskDelay(RandvVlue);
			meshMode = MESH_MODE_MESH;//组网
			break;
		
		case MESH_MODE_MESH:
			meshMode = taskMesh();
//			if (gGetStartNewMeshAck == false) {//! if not received ask for id msg?
//				meshMode = MESH_MODE_START_MESH;//开始组网
//				
//			} else if (gMeshFinished == true) {
//				meshMode = MESH_MODE_NORMAL;//组网正常
//			}	
			break;
		 
		case MESH_MODE_NORMAL://组网正常
			meshMode = taskNormalMission();
			break;

		case MESH_MODE_SELF_CHECK://组网自检
			break;
		
		case MESH_MODE_NONE:	//非组网状态
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
*	函 数 名: static void vLORA_Task( void *pvParameters )
*	形    参：
*	返 回 值: 
*	功能说明: vLORA_Task显示任务，				
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
				powerState  = gITASMsg.payload.power_state; //初始化时为0
				
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
	//		xEventGroupSetBits(xCreatedEventGroup, TASK_BIT_MESH);//事件标志组代表状态
			
			PBout(3) = ~PBout(3);
			vTaskDelay(500);

		}
	}
}

/**********************************************
*	函 数 名: static void vTCP_Task( void *pvParameters )
*	形    参：
*	返 回 值: 
*	功能说明: TCP任务
**********************************************/ 
static void vTCP_Task( void *pvParameters )
{
//	u8 clitest,len;
//	Get_NetMsg();
//	Internet_Init();
//	printf("w5500initok \n");
	while(W5500_Check_Link())  //没有插入网线
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
//		switch(getSn_SR(SOCK_TCPS))									   /*获取socket的状态*/
//        {
//		case SOCK_CLOSED:											    /*socket处于关闭状态*/
//			socket(SOCK_TCPS ,Sn_MR_TCP,ConfigMsg.port,Sn_MR_ND);	     /*打开socket*/
//			break;

//		case SOCK_INIT:													/*socket已初始化状态*/
//			listen(SOCK_TCPS);											/*socket建立监听*/
//			break;

//		case SOCK_ESTABLISHED:											/*socket处于连接建立状态*/
//			if(getSn_IR(SOCK_TCPS) & Sn_IR_CON)
//			{
//				setSn_IR(SOCK_TCPS, Sn_IR_CON);							/*清除接收中断标志位*/
//			}
//			len=getSn_RX_RSR(SOCK_TCPS);							    /*定义len为已接收数据的长度*/
//			if(len>0)
//			{
//				recv(SOCK_TCPS,Internet_Rxbuff,len);					/*接收来自Client的数据*/
//				send(SOCK_TCPS,ALL_FF,8);	/*向Client发送数据*/

////				send(SOCK_TCPS,Internet_Rxbuff,len);	/*向Client发送数据*/
////			    close(SOCK_TCPS);	//短连接，每接受完成一次数据，断开连接
//			}	
//			break;
//		 case SOCK_CLOSE_WAIT:	/*socket处于等待关闭状态*/
//			close(SOCK_TCPS);
//			break;
//       }
////		clitest = TCP_Client_Demo(8);
//	}
}
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/

