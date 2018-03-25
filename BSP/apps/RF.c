///**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
// * 文件名   ：LED.C
// * 环境	 	  : MDK4.73-固件库V3.5版本
// * 实验平台 ：STM32F103RBT6-8MHz->72MHz
// * 版本     ：V1.0.0
// * 作者     ：
// * 修改时间 ：2013-12-20
// * 硬件连接 : STM32F10x-STM32开发板
// * 描述     : 系统基本输出配置文件
// * 修改记录     :
// * 版本号       :  日期          作者       说明 
//   V1.0.1       :  2014-09-13          
//*******************************************************************************/
///* Includes---------------------------------------------*/
//#include  "RF.h"
//#include "main.h"
//#include "BSP_FIFO.h"
//#define  RF_Send_Buff_Len     128*1          //射频接收发送数组长度
//uint8_t Device_Location = 0;
//uint32_t LoRa_Frequency_Change =  435000000;
//bool Some_Data_On_Sky = 0;
//bool Rece_Frame_Data_flag = 0;
//uint8_t gNoneAskForCnt = 0;
//uint8_t gNodesOnLine = 0;
//uint16_t RandvVlue = 0;

//location_control_t  east1_control_t; //东
//location_control_t  south2_control_t;//南
//location_control_t  west3_control_t; //西
//location_control_t  north4_control_t;//北

//uint16_t Block_Code = ((0x7E<<8)&0X0D);			/*	功能隔断标志~回车	*/
//uint8_t Pay_Load[] = {0x00};
//uint8_t RF_size = 0; 
//uint8_t RF_TX_Buff[] = {0};
////uint8_t RF_Send_Buff[RF_Send_Buff_Len];/*定义一个1KB的缓存*/
////uint8_t RF_Rece_Buff[RF_Send_Buff_Len];/*定义一个1KB的缓存*/

//const uint8_t MY_TEST_Msg[] = "3";
//const uint8_t Function_TEST_Msg[27]   = {0xFE,0x00,0x0c,0x01,0x01,0xff,0x0ff,0x00,0x01,0x04,0x00,0xfc,0x01,0x01,0x01,0x01,0x01,0xff,0x01,0xff,0xff,0xff,0xff,0xff,0xaa,0xff,0xef};
//const uint8_t Function_TEST_Msg1[27]  = {0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};	
//tRadioDriver *Radio = NULL;

//bool gNetworkRunning = false;			//! the system is in running mode, if i want to ask for id, should send msg in free time  
//bool gCanAskForIdTriger = false;		//! if ask for id, should under own radio period
//bool gCanAskForIdDurNormMode = false;	//
//void parseRadioData(void)
//{
//	
//	uint8_t data;
//	static message_t msg;
//	
//	Rece_Frame_Data_flag = false;
//	
//	while (fifoGetBufDataCount()) {
//           fifoPopBuf(&data, 1);
//		
//		if (msg_parse_char(&msg, data)) {
//			Rece_Frame_Data_flag = true;
//			PCout(13) =~ PCout(13);
//			handleMessage(&msg);
//		}
//	}
//}

////void Lora_Handle( void )
////{
//////	static uint8_t canCheckCnt = 0;
////	static uint8_t node_cycle = 1;
////	uint8_t i;
//////	uint8_t result = 0;
////	
////	unsigned char data;
////	static message_t msg;

////	bool flag = false;
////	static volatile TickType_t currentTime;	

//////	if (xTaskGetTickCount() - currentTime >= TRAVERSE_PERIOD) {
//////	currentTime = xTaskGetTickCount();
//////	flag = true;
//////	}
//////	flag = true;

//////	printf("RF_TX_DONE: \n");
////////			 Indicates on a LED that we have sent a PONG
////////			Radio->SetTxPacket( MY_TEST_Msg, 1);

//////	if (flag == true) 
//////	{			
//////		if (node_cycle > 7 ) {/*(gNodesOnLine+1)NODE_ID_NUM_MAX*/
//////			node_cycle = 1;
//////		}
////////		msg_start_mesh_send();
//////		msg_ask_for_data_send(node_cycle); 
//////		node_cycle++;
//////	}
//////	else 
//////	{

//////	}

////	switch ( Radio->Process( ) )
////	{
////		case RF_RX_DONE:	
////		{
////			//printf("RF_RX_DONE!\r\n");
////			Radio->GetRxPacket( Buffer, ( uint16_t* )&BufferSize );
////			PCout(14) = ~PCout(14);
////			for(i=0;i < BufferSize;i++)
////			{
////				data = Buffer[i];
////				fifoPushBuf(&data, 1);
//////				printf(" %x",data);
////				if (msg_parse_char(&msg, data)){
////					handleMessage(&msg);
////				}
////			}
////			for(i=0;i<BUFFER_SIZE;i++)
////			Buffer[i] = 0;
////		}break;

////		case RF_TX_DONE:
////		{
////			Soft_delay_ms(2);
////			Radio->StartRx( );
////			Soft_delay_ms(2);
////		}break;
////		
////		case  RF_TX_TIMEOUT:
////		{
////		}break;
////		
////		case RF_RX_TIMEOUT:
////		{
////			
////		}break;
////	
////		default:
////		{}break;
////	}
////}


/////****************************************************************/
//////! msg_ask_for_data_send (master -> slaver)
////#define MSG_ID_CTRL_NODE_KM				0X00
////#define MSG_CTRL_NODE_KM_PAYLOAD_LEN	         	12
////#define MSG_RESERVE 					0XFF
//////主机群发指令
////void msg_ctrl_node_km_send(uint8_t node_id)
////{   
////	reserve;
////}

///****************************************************************/
////! msg_ask_for_data_send (master -> slaver)
//#define MSG_ID_ASK_FOR_DATA				0X51
//#define MSG_ASK_FOR_DATA_PAYLOAD_LEN 	13

////主机轮询从机指令
//void msg_ask_for_data_send(uint8_t node_id)
//{
//	static uint8_t msg[MSG_ASK_FOR_DATA_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];//13 + 7 = 20
//	static msg_head_t          msg_head;					//! msg head
//	static msg_ask_for_data_t  payload;						//! msg payload

//	msg_head.stx     = STX;//1
//	msg_head.len     = MSG_ASK_FOR_DATA_PAYLOAD_LEN;
//	msg_head.seq     = MSG_RESERVE;
//	msg_head.msg_id  = MSG_ID_ASK_FOR_DATA;//4
//	
//	payload.master_addr  = MSG_MASTER_ADDR;//5
//	payload.slave_addr1  = MSG_RESERVE;
//	payload.slave_addr2  = node[node_id].slave_addr2;
//	payload.location1 	 = MSG_RESERVE;
//	payload.location2 	 = node[node_id].location2;//9

////	location_control_t  east1_control_t;//东
////	location_control_t  south2_control_t;//南
////	location_control_t  west3_control_t;//西
////	location_control_t  north4_control_t;//北
//	memcpy(&gITASMsg.payload.node[node_id-1], &node[node_id], sizeof(node_t));
////	switch(gITASMsg.payload.node[node_id-1].location2)
//	switch(node[node_id].location2)
//	{ 
//		case Location_East1:	 /*		东	*/
//			{
//			payload.spikelamp_switch1  = east1_control_t.spikelamp_switch1;//10
//			payload.voice_switch2 	   = east1_control_t.voice_switch2;
//			payload.led_switch3		   = east1_control_t.led_switch3;
//			payload.reserve1_switch    = east1_control_t.reserve1_switch;
//			payload.reserve2_switch    = east1_control_t.reserve2_switch;
//			payload.reserve3_switch    = east1_control_t.reserve3_switch;//15
//			}
//			break;
//		
//		case Location_South2: 			    /*	南	*/
//			{
//			payload.spikelamp_switch1  = south2_control_t.spikelamp_switch1;
//			payload.voice_switch2 	   = south2_control_t.voice_switch2;
//			payload.led_switch3		   = south2_control_t.led_switch3;
//			payload.reserve1_switch    = south2_control_t.reserve1_switch;
//			payload.reserve2_switch    = south2_control_t.reserve2_switch;
//			payload.reserve3_switch    = south2_control_t.reserve3_switch;
//			}
//			break;
//		case Location_West3:			   /*	西	*/
//			{
//			payload.spikelamp_switch1  = west3_control_t.spikelamp_switch1;
//			payload.voice_switch2 	   = west3_control_t.voice_switch2;
//			payload.led_switch3		   = west3_control_t.led_switch3;
//			payload.reserve1_switch    = west3_control_t.reserve1_switch;
//			payload.reserve2_switch    = west3_control_t.reserve2_switch;
//			payload.reserve3_switch    = west3_control_t.reserve3_switch;
//			}
//			break;
//		case Location_North4: 			    /*	北	*/
//			{
//			payload.spikelamp_switch1  = north4_control_t.spikelamp_switch1;
//			payload.voice_switch2 	   = north4_control_t.voice_switch2;
//			payload.led_switch3		   = north4_control_t.led_switch3;
//			payload.reserve1_switch    = north4_control_t.reserve1_switch;
//			payload.reserve2_switch    = north4_control_t.reserve2_switch;
//			payload.reserve3_switch    = north4_control_t.reserve3_switch;
//			}
//			break;
//		default:
//			break;
//	}

//	payload.reserve1 = 0;//16
//	payload.reserve2 = 0;//17

//	memcpy(&msg, &msg_head, sizeof(msg_head));
//	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload)); //! payload

//	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
//	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
//	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20
//	
//	node[node_id].bad_cnt++; //! bigger means the slaver(node) bad and bad and bad....... !
//	gITASMsg.payload.node[node_id-1].bad_cnt++;
//    MSG_SEND_USART_BYTES(msg, sizeof(msg));
//}

////void Fill_Location_Control(uint8_t node_id)//给方位参数控制结构体赋值，包含主机node
////{
////	
////}
////从机回复主机轮询指令
//#define MSG_ID_ACK_FOR_DATA				0X52
//#define MSG_ACK_FOR_DATA_PAYLOAD_LEN 	12
////从机 回复主机 轮询指令
//void msg_ack_for_data_send(
//							uint8_t  master_addr,
//							uint8_t  slave_addr1,
//							uint8_t  slave_addr2,
//							uint8_t  location1,
//							uint8_t  location2,
//							uint8_t  trigger_num,
//							uint8_t	 trigger_vehicle1,//车检器触发
//							uint8_t  trigger_video2,//视频触发
//							uint8_t  trigger_microwave3,//微波触发
//							uint8_t  trigger_reserve1,//预留触发
//							uint8_t  reserve1,
//							uint8_t  reserve2/*预留四个字节*/
//							)
//{	
//	static uint8_t			   msg[MSG_ACK_FOR_DATA_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];
//	static msg_head_t	       msg_head;
//	static msg_ack_for_data_t  payload;

//	msg_head.stx          = STX;
//	msg_head.len          = MSG_ACK_FOR_DATA_PAYLOAD_LEN;
//	msg_head.seq	      = MSG_RESERVE;
//	msg_head.msg_id       = MSG_ID_ACK_FOR_DATA;

//	payload.master_addr  = master_addr;
//	payload.slave_addr1  = slave_addr1;
//	payload.slave_addr2  = slave_addr2;
//	payload.location1    = location1;
//	payload.location2    = location2;

//	payload.trigger_num	       = trigger_num;
//	payload.trigger_vehicle1   = trigger_vehicle1;
//	payload.trigger_video2     = trigger_video2;
//	payload.trigger_microwave3 = trigger_microwave3;
//	payload.trigger_reserve1   = trigger_reserve1;
//	payload.reserve1           = reserve1;
//	payload.reserve2	       = reserve2;
//	 
//	memcpy(&msg, &msg_head, sizeof(msg_head));				   	//head 4字节
//	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload));  //msg_ack_for_data_send payload 12字节
//	
//	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
//	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
//	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20

//	current_node.bad_cnt = 0;
//	
//    MSG_SEND_USART_BYTES(msg, sizeof(msg));
////printf("slave_addr2 %d\r\n",slave_addr2);
//}
///****************************************************************/

//#define MSG_ID_ASK_FOR_ID				0X53
//#define MSG_ASK_FOR_ID_PAYLOAD_LEN 		20
// //主机处理 从机发送
//void msg_ask_for_id_send(uint32_t mac_0, uint32_t mac_1, uint32_t mac_2, uint8_t master_addr, uint8_t slave_addr2, uint8_t location2) 
//{
//	static uint8_t msg[MSG_ASK_FOR_ID_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];//7 + 15 = 22
//	static msg_head_t	     msg_head;
//	static msg_ask_for_id_send_t  payload;

//	msg_head.stx        = STX;//1
//	msg_head.len        = MSG_ASK_FOR_ID_PAYLOAD_LEN;//2
//	msg_head.seq	    = 0;//3
//	msg_head.msg_id     = MSG_ID_ASK_FOR_ID;//4
//	
//	payload.node_id     = slave_addr2;	//5
//	payload.mac[0]	    = mac_0;//9
//	payload.mac[1]      = mac_1;//13
//	payload.mac[2]      = mac_2;//17
//	
//	payload.master_addr	= master_addr;//18
//	payload.slave_addr1	= 0;//19	
//	payload.slave_addr2	= slave_addr2;//19
//	payload.location1	= 0;//20
//	payload.location2	= location2;//20 

//    payload.reserve1    = 0;//21
//	payload.reserve2    = 0;//22
//	 
//	memcpy(&msg, &msg_head.stx, sizeof(msg_head));
//	memcpy(&msg[sizeof(msg_head)], &payload.node_id, sizeof(payload));//! payload

//	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
//	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
//	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20

////	current_node.bad_cnt = 0;
//	current_node.slave_addr2 = 0;
//	
//    MSG_SEND_USART_BYTES(msg, sizeof(msg));
//}

///****************************************************************/
////! msg_assign_id_send (master -> slaver)
////主机分配ID

//#define	MSG_ID_ASSIGN_ID				0X54
//#define MSG_ASSIGN_ID_PAYLOAD_LEN 		16

//void msg_assign_id_send(uint8_t node_id, uint32_t mac_0, uint32_t mac_1, uint32_t mac_2, uint8_t cfdt)
//{
//	static uint8_t msg[MSG_ASSIGN_ID_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];
//	static msg_head_t	    msg_head;
//	static msg_assign_id_t  payload;
//	
//	msg_head.stx       = STX;
//	msg_head.len       = MSG_ASSIGN_ID_PAYLOAD_LEN;
//	msg_head.seq	   = 0;
//	msg_head.msg_id    = MSG_ID_ASSIGN_ID;
//	
//	payload.node_id    = node_id;
//	payload.mac[0]     = mac_0;
//	payload.mac[1]     = mac_1;
//	payload.mac[2]     = mac_2;
//	payload.cfdt	   = cfdt;
//    payload.reserve1   = 0;
//	payload.reserve2   = 0;
//	
//	memcpy(&msg, &msg_head, sizeof(msg_head));
//	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload)); //! payload
// 
//	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
//	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
//	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20
//  
//    MSG_SEND_USART_BYTES(msg, sizeof(msg));
//}

///****************************************************************/
////! msg_ack_for_id_send
////! ，由从机发送给主机的ID确认命令，主机若收到该命令则认为ID分配成功，否则会连续发送三次分配ID命令，
////			若均没收到该消息则不再给该节点分配ID
//#define	MSG_ID_ACK_FOR_ID				0X55
//#define MSG_ACK_FOR_ID_PAYLOAD_LEN 		15

//void msg_ack_for_id_send(uint8_t node_id, uint32_t mac_0, uint32_t mac_1, uint32_t mac_2) 
//{
//	static uint8_t msg[MSG_ACK_FOR_ID_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];
//	static msg_head_t	     msg_head;
//	static msg_ack_for_id_t  payload;
//	
//	msg_head.stx       = STX;//
//	msg_head.len       = MSG_ACK_FOR_ID_PAYLOAD_LEN;//
//	msg_head.seq	   = 0;//
//	msg_head.msg_id    = MSG_ID_ACK_FOR_ID;//
//	
//	payload.node_id    = node_id;//
//	payload.mac[0]     = mac_0;//
//	payload.mac[1]     = mac_1;//
//	payload.mac[2]     = mac_2;//
//    payload.reserve1   = 0;//
//	payload.reserve2   = 0;//
//	
//	memcpy(&msg, &msg_head, sizeof(msg_head));
//	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload)); //! payload

//	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
//	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
//	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20
//	
//    MSG_SEND_USART_BYTES(msg, sizeof(msg));
//}

///****************************************************************/
////! msg_start_mesh_send (master -> slaver)
////主机上电伊始，向从机群发组网命令
//#define MSG_ID_START_MESH				0X56
//#define MSG_START_MESH_PAYLOAD_LEN 		2

//void msg_start_mesh_send(void)
//{
//	static uint8_t msg[MSG_START_MESH_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];
//	static msg_head_t	msg_head;
//	static msg_start_mesh_t payload;
//	
//	msg_head.stx	= STX;//1
//	msg_head.len	= MSG_START_MESH_PAYLOAD_LEN;//2
//	msg_head.seq	= 0x00;//3	uint8_t  seq;
//	msg_head.msg_id	= MSG_ID_START_MESH;//4
//	
//    payload.reserve1   = 0;//5
//	payload.reserve2   = 0;//6
//	
//	memcpy(&msg, &msg_head, sizeof(msg_head));//
//	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload)); //! payload

//	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
//	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
//	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20
//	
//	
//	MSG_SEND_USART_BYTES(msg, sizeof(msg));
////	debugLogInfo("start mesh \n");
////	ledFlashSet(LED_MESH, 3, 2, 5);
//}
//void checkNodesStatePeriod(void) //检查从机状态阶段
//{
//	uint8_t i;
//	bool flag = false;
//	static volatile TickType_t currentTime;	
//	
//	if (xTaskGetTickCount() - currentTime >= TRAVERSE_PERIOD) {
//		currentTime = xTaskGetTickCount();
//		flag = true;
//	}

//	if (flag == true) {
//		gNodesOnLine = 0;
//		for (i = 1; i < NODE_ID_NUM_MAX; i++) { //! check all the nodes 
//			if (node[i].bad_cnt >= NODE_BAD_CNT_MAX) {
//				memset(&node[i], 0, sizeof(node_t));	//! node[i].state = NODE_STATE_OFFLINE;	
//				memset(&gITASMsg.payload.node[i-1], 0, sizeof(node_t));
//				
//			} else if (node[i].id != 0) {
//				gNodesOnLine++;// 
//			}
//		}
//	}
//}

//void askForDataPeriod(void)
//{
//	static uint8_t canCheckCnt = 0;
//	static uint8_t node_cycle = 1;
//	uint8_t i;
//	uint8_t result = 0;
//	bool flag = false;
//	static volatile TickType_t currentTime;	
//	
//	if (xTaskGetTickCount() - currentTime >= TRAVERSE_PERIOD) {//定时轮询
//		currentTime = xTaskGetTickCount();
//		flag = true;
//	}	
//	
//	if (node_cycle >= /*gNodesOnLine*/NODE_ID_NUM_MAX) {//超过节点数  
//		if (canCheckCnt++ > 1) {//初始时为0  ???
//			for (i = 1; i < /*gNodesOnLine*/NODE_ID_NUM_MAX; i++) {
//				result = result + node[i].state;//node[i].state为每个节点的状态 
//			}

//			if (result == 0) { //! no node online, start a new mesh
//				node_cycle = 1;
//				meshMode = MESH_MODE_START_MESH;//开始组网
//			}
//			canCheckCnt = 0;
//		}
//	}	
//		
//	if (flag == true) {			
//		if (node_cycle >= /*(gNodesOnLine+1)*/NODE_ID_NUM_MAX) {//超过最大节点数
//			node_cycle = 1;
//		}
//		
//		msg_ask_for_data_send(node_cycle); //对节点轮询
//		node_cycle++;
//		
//	} else {

//	}		
//}
////从机网络运行任务
//itas_mode_t taskMesh(void)
//{
//	static uint8_t askForIdCnt = 0;
//	itas_mode_t mode = MESH_MODE_MESH;
//	u16 m=60,n=400,x=1,y=20;
//	u16 p=50,q=160;
//	if (current_node.slave_addr2 == 0) {
//		
//		gMeshFinished = 0;
//		
//		if (gNetworkRunning) {//! the network is running normally  系统内某些主从网络关系已存在
////		if (gCanAskForIdDurNormMode) {	//! check if it is the free time that can send ask for id msg
////			if(Rece_Frame_Data_flag){ //已接收完整帧数据
//				if(parse_flag){ //已接收完整帧数据				parse_flag
//							srand(Get_Adc(ADC_Channel_10));
//							RandvVlue = rand()%(q-p+1)+p;
//							vTaskDelay(RandvVlue);
////				if((Rece_Frame_Data_flag)&&(!Some_Data_On_Sky))//帧数据完整，且空中没有字节数据，
//				if(parse_flag)
//				{	printf("  gNetworkRunning \r\n");	
//					gCanAskForIdDurNormMode = false; 
//					askForIdCnt++;
//					msg_ask_for_id_send(current_node.mac[0], current_node.mac[1], current_node.mac[2], current_node.master_addr, 
//										current_node.slave_addr2, current_node.location2);
//					printf("normal mode: ask for id times: %d \n", askForIdCnt);
//				}
//			} else {
//				
//				//! to do 
//			}
//		} else {//! the network is running mesh系统伊始，组网状态
////			if (gCanAskForIdTriger) {
//			if(parse_flag){
//				
//							srand(Get_Adc(ADC_Channel_10));
//							RandvVlue = rand()%(n-m+1)+m;
//							vTaskDelay(RandvVlue);
//				if((parse_flag))//帧数据完整，且空中没有字节数据，
//				{
//					
//					msg_ask_for_id_send(current_node.mac[0], current_node.mac[1], current_node.mac[2], current_node.master_addr, 
//										current_node.slave_addr2, current_node.location2);						
//					askForIdCnt++; 
//					printf("mesh mode: ask for id times: %d \n", askForIdCnt);
//				}
//			} else {
//				//! to do
//			}
//		}			
//			
//		if (askForIdCnt == ASK_FOR_ID_RETRY_MAX) {//! ask for id more than n times, delay a random time then restart timer
////			vTaskDelay((current_node.mac[0] + current_node.mac[1] + current_node.mac[2])&0x00000007*20);
////			timer2Init(200);
//			srand(Get_Adc(ADC_Channel_10));
//			RandvVlue = rand()%(q-p+1)+p;
//			vTaskDelay(RandvVlue);
//		}
//		
//		if (askForIdCnt >= ASK_FOR_ID_RETRY_REBOOT) {//发送一次申请id ++
//			systemReboot(); 
//		}
//		
//	} else if (current_node.slave_addr2 == 255) {//! rejected my mesh request!!!
//		askForIdCnt = 0;
////		timer2Init(getAskForIdPeriod());	//! just case of had modified the period
//		mode = MESH_MODE_NONE;
//		printf("i am ok but rejected ! \n");
//		
//	} else { //! get the id succeed !
//		askForIdCnt = 0;
////		current_node.bad_cnt = 0;???
////		timer2Init(getAskForIdPeriod()); //! just case of had modified the period
//		mode = MESH_MODE_NORMAL;
//		
////		printf("i get my id = %d \n", current_node.slave_addr2);			
//	}
//	return mode;
//}
////正常网络运行任务 
//itas_mode_t taskNormalMission(void)
//{
//	itas_mode_t mode = MESH_MODE_NORMAL;
//	
//	//! to do normal mission
//	if (current_node.slave_addr2 == 0){	//! master start a new mesh, should apply for a new id 
//		mode = MESH_MODE_MESH; 

//	}
//	else if (current_node.bad_cnt > CURRENT_BAD_CNT_MAX){ //! communication is bad ! run selfcheck !
//		current_node.slave_addr2 = 0;
//		//mode = ITS_MODE_SELF_CHECK;
////		printf("i am running selfcheck! \n");
//	}
//	return mode;
//}
///********************************************************************************************************************************************************/
////handle_function  从机处理
////! master -> slaver  0x51
////bool gNetworkRunning = false;
//uint16_t gRadioNoDataCnt = 0;
//static void handle_msg_ask_for_data(const message_t *msg)
//{		
//	msg_ask_for_data_t message;
//	memcpy(&message, &msg->payload[0], sizeof(message));
//	
//	gRadioNoDataCnt = 0;	//! when received a msg, this value will be reset to 0.
//	gNetworkRunning = true;	//! means the net is in running mode
//	
//	if (message.slave_addr2 == 0) {
//		return;	//! there must be something wrong with master, just give no ack
//	}
// 
//	if ((message.slave_addr2 == current_node.slave_addr2)||(message.slave_addr2 == current_node.id)){

//		gMeshFinished = 1;
//		
////		printf("slave_addr2 %d:  \n",current_node.slave_addr2);
//		current_node.bad_cnt = 0;     //! can receive this msg means communication is OK!
//		
//		current_node.spikelamp_switch1 = message.spikelamp_switch1;
//		current_node.voice_switch2     = message.voice_switch2;
//		current_node.led_switch3       = message.led_switch3;
//		current_node.reserve1_switch   = message.reserve1_switch;
//		current_node.reserve2_switch   = message.reserve2_switch;
//		current_node.reserve3_switch   = message.reserve3_switch;
//		
////		KM_spikelamp_switch1 = message.spikelamp_switch1;
////		KM_voice_switch2     = message.voice_switch2;
////		KM_led_switch3       = message.led_switch3;
////		KM_reserve1_switch   = message.reserve1_switch;
////		KM_reserve2_switch   = message.reserve2_switch;
////		KM_reserve3_switch   = message.reserve3_switch;
//	
//		msg_ack_for_data_send(  current_node.master_addr,
//								current_node.slave_addr1,
//								current_node.slave_addr2,
//								current_node.location1,
//								current_node.location2,
//								current_node.trigger_num,
//								current_node.trigger_vehicle1,
//								current_node.trigger_video2,
//								current_node.trigger_microwave3,
//								current_node.trigger_reserve1,
//								current_node.reserve1,
//								current_node.reserve2
//							 );
////		printf("ack for data my id : %d \n", current_node.slave_addr2);
////		ledFlashSet(1, 200, 5);
//	}
//	else
//	{};	
//}
////! slaver -> master
//static void handle_msg_ack_for_data(const message_t *msg)
//{
//	uint8_t i;
//	msg_ack_for_data_t message;
//	memcpy(&message, &msg->payload[0], sizeof(message));
//	for (i = 1; i < NODE_ID_NUM_MAX; i++) {	//! traverse the entire array which saves all the nodes 
//		if (node[i].id == message.slave_addr2) {
//			

//			
//			node[i].state 	  		= NODE_STATE_ONLINE;
//			node[i].bad_cnt	  		= 0;//! if the data ack ok, then the bad_cnt will be reset to 0, which means this slaver(node) is ok.
////			node[i].dev_type  		= message.dev_type; 	
//			
//			node[i].location2 		= message.location2; 
//			
//			node[i].trigger_num		= message.trigger_num;
//			node[i].trigger_vehicle1	= message.trigger_vehicle1;
//			node[i].trigger_video2	= message.trigger_video2;
//			node[i].trigger_microwave3	= message.trigger_microwave3;
////			trigger_reserve1;
////			uint16_t reserved_2;

//			gITASMsg.payload.nodeOnlineNum		= gNodesOnLine;
//			memcpy(&gITASMsg.payload.node[i-1], &node[i], sizeof(node_t));
//			break;
//			
//		} else if (i >= NODE_ID_NUM_MAX - 1) {
////			msg_start_mesh_send();
//		}			
//	}
////	ledFlashSet(LED_MESH, 1, 5, 1);
//}

////! slaver -> master
//static void handle_msg_ask_for_id(const message_t *msg)
//{
////	uint8_t i;
////	bool need_trav_ids = false;
////	msg_ask_for_id_t message;
////	memcpy(&message, &msg->payload[0], sizeof(message));
////	gGetStartNewMeshAck = true;
////	gMeshFinished = false; //! there still some nodes want to join into the net, mesh not finished 
////	gNoneAskForCnt = 0;
////	//! traverse the entire array which saves all the nodes. i prefer to traverse mac first, if this mac has been existed, then assign the corresponding id to the node 
////	//! if can not find this mac, then traverse the id from 1 to max, assign the seq as id till the corresponding id is zero.
////	for (i = 1; i < NODE_ID_NUM_MAX; i++) {
////		if ((node[i].mac[0] == message.mac[0]) && (node[i].mac[1] == message.mac[1]) && (node[i].mac[2] == message.mac[2])) {
////			node[i].bad_cnt = 0; //! another place always check this value, if this node down less than n times, and here assign the same id again, we should reset the bad_cnt in case be reseted again 
////			node[i].c_base_red		= message.c_base_red;
////			node[i].c_base_yellow	= message.c_base_yellow;
////			node[i].c_base_green	= message.c_base_green;
////			need_trav_ids = false;
////			msg_assign_id_send(i, message.mac[0], message.mac[1], message.mac[2], NODE_BAD_CNT_MAX*NODE_ID_NUM_MAX*TRAVERSE_PERIOD/1000);
////			break;
////		
////		} else if (i >= NODE_ID_NUM_MAX-1) {
////			need_trav_ids = true;
////		}
////	}

////	//! if need, traverse the ids
////	if (need_trav_ids == true) {
////		need_trav_ids = false;
////		
////		for (i = 1; i < NODE_ID_NUM_MAX; i++) { 
////			if (node[i].id == 0) {				 
////				node[i].id     = i;
////				node[i].mac[0] = message.mac[0];
////				node[i].mac[1] = message.mac[1];
////				node[i].mac[2] = message.mac[2];
////				node[i].c_base_red		= message.c_base_red;
////				node[i].c_base_yellow	= message.c_base_yellow;
////				node[i].c_base_green	= message.c_base_green;
////				
////				msg_assign_id_send(i, message.mac[0], message.mac[1], message.mac[2], NODE_BAD_CNT_MAX * NODE_ID_NUM_MAX * TRAVERSE_PERIOD /1000);
////				break; //! must quit out otherwise will assign all the idle nodes
////		
////			} else if (i >= NODE_ID_NUM_MAX-1) { //! it means the active nodes up to MAX, then reject this node mesh
////				msg_assign_id_send(255, message.mac[0], message.mac[1], message.mac[2],  NODE_BAD_CNT_MAX * NODE_ID_NUM_MAX * TRAVERSE_PERIOD /1000);
////				
////			} else {
////				//! normal
////			}				
////		}
////		
////	}
//}


////! slaver 传给-> master 
////主机处理 查询从机ID的指令 
//static void handle_msg_ack_for_id(const message_t *msg)
//{
////	msg_ack_for_id_t message;
////	memcpy(&message, &msg->payload[0], sizeof(message));
//	return;	
//}

////! master 传给-> slaver
////从机处理主机的分配ID指令
//static void handle_msg_assign_id(const message_t *msg)//0X54
//{
//	msg_assign_id_t message;
//	memcpy(&message, &msg->payload[0], sizeof(message));	
//	
//	if ((message.mac[0] != current_node.mac[0])||(message.mac[1] != current_node.mac[1])||(message.mac[2] != current_node.mac[2])) {
////		printf("this is not my mac! \n");
//		if ((message.node_id == current_node.slave_addr2)||(message.node_id == current_node.id)) { //! my id is reassigned to other nodes, i have to apply for a new id 
//			current_node.slave_addr2 = 0;
////			printf("i have to re apply for my id \n");
//		}
//		
//	} else {
//		current_node.slave_addr2 = message.node_id;
//		current_node.id          = message.node_id;
//		current_node.cfdt		 = message.cfdt;
//	}
//}

////重新组网指令
//static void handle_msg_start_mesh(const message_t *msg)
//{
//	current_node.slave_addr2 = 0;			//! start to mesh again
//	gNetworkRunning = false;	//! means the net is in meshing mode
////	printf("start a new mesh \n");
//}

///******************************************************************************************************************************************************************************************************************************
//function： state machine
//brief：Master Analysis the polling Packet which received from slave  （Radio->GetRxPacket( Buffer, ( uint16_t* )&BufferSize );）
//return：

////#pragma pack(1)
////typedef __packed struct s_rece_oprerate{
////	uint8_t frame_head;	//0xFE
////	uint8_t frame_length[2];
////	uint8_t msg_id;//指令	
////	uint8_t master_addr;	
////	uint8_t slave_addr[2];
////	uint8_t location[2];//方位
////	uint8_t function_num;//功能个数
////	uint8_t function_operate[2];//功能动作操作
////	uint8_t data_buff[12];	//数据
////	uint8_t crc[2];		
////	uint8_t frame_tail;//0xEF
////}rece_operate_t,*rece_operate_t_p;
////#pragma pack()
////rece_operate_t_p SPI_MSG_Opreate;


//******************************************************************************************************************/
//	bool parse_flag = false;
//bool msg_parse_char(message_t *rxmsg, uint8_t c)
//{

//	parse_flag = false;

//	static message_t rxmsg_t;	
//	static uint16_t bufferIndex;
//	static msg_parse_state_t status;
//	
//	switch (status)
//	{
//	case MSG_PARSE_STATE_UNINIT:
//		
//	case MSG_PARSE_STATE_IDLE:
//		if (c == STX) {
//			rxmsg_t.stx = c;
//			status = MSG_PARSE_STATE_GOT_STX; 
//		} 
//		break;

//	case MSG_PARSE_STATE_GOT_STX:
//		rxmsg_t.len = c;
//		status = MSG_PARSE_STATE_GOT_LENGTH; 
//		break;

//	case MSG_PARSE_STATE_GOT_LENGTH:
//		rxmsg_t.seq = c;
//		status = MSG_PARSE_STATE_GOT_SEQ;
//		break;
//	
//	case MSG_PARSE_STATE_GOT_SEQ:
//		rxmsg_t.msg_id = c;
//		status = MSG_PARSE_STATE_GOT_MSGID;
//		break;

//	case MSG_PARSE_STATE_GOT_MSGID:

//		rxmsg_t.payload[bufferIndex++] = c;
//		if (bufferIndex == rxmsg_t.len) {
//			status = MSG_PARSE_STATE_GOT_PAYLOAD;
//		}
//		break;

//	case MSG_PARSE_STATE_GOT_PAYLOAD:
//			rxmsg_t.checksum =  (uint16_t)(c << 8);//高位	          
//			status = MSG_PARSE_STATE_GOT_CRC1;
//		break;

//	case MSG_PARSE_STATE_GOT_CRC1:
//			rxmsg_t.checksum |= (uint16_t)c;       //低位
//			status = MSG_PARSE_STATE_GOT_CRC2;		
//		break;
//	
//	case MSG_PARSE_STATE_GOT_CRC2:
////				printf("rxmsg_t.checksum %x\n",rxmsg_t.checksum);
////				printf("crc16(&rxmsg_t.payload[0], bufferIndex) : %x\n",crc16(&rxmsg_t.payload[0], bufferIndex));
//			if ((crc16(&rxmsg_t.payload[0], bufferIndex) == rxmsg_t.checksum) && (c == END)) {
////				printf("rxmsg_t.checksum %x\n",rxmsg_t.checksum);
//				memcpy(rxmsg, &rxmsg_t, sizeof(rxmsg_t));
//				Some_Data_On_Sky = 0;
//				Rece_Frame_Data_flag = true;
//				parse_flag = true;
//			}
//			bufferIndex = 0;                                   
//			status = MSG_PARSE_STATE_UNINIT;
//        break;
//			
//	default:
//		bufferIndex = 0;
//		status = MSG_PARSE_STATE_UNINIT;
//	}
////	printf("parse_flag %d\n",parse_flag);

//	return parse_flag;
//			
//}
///*该节点作为从机  SLAVE*/
//void handleMessage(message_t *msg)
//{
//	switch(msg->msg_id)
//	{
//		case MSG_ID_ASK_FOR_DATA://由主机发送给从机 从机处理主机发送的轮询指令
//			handle_msg_ask_for_data(msg);	
//			break;
//	
//////		case MSG_ID_ACK_FOR_DATA://由从机向主机回复的数据  主机可用
//////			handle_msg_ack_for_data(msg);
//////			break;	

//////		case MSG_ID_ASK_FOR_ID://由从机向主机回复的数据  主机处理
//////			handle_msg_ask_for_id(msg);
//////			break;	

//////		case MSG_ID_ACK_FOR_ID:/，由从机发送给主机的ID确认命令，主机若收到该命令则认为ID分配成功，
//////									//	否则会连续发送三次分配ID命令，若均没收到该消息则不再给该节点分配ID
//////			handle_msg_ack_for_id(msg);
//////			break;

//		case MSG_ID_ASSIGN_ID://从机接收到主机的分配ID指令之后，写入自己的current_node
//			handle_msg_assign_id(msg);
//			break;

//		case MSG_ID_START_MESH: //从机处理主机发送的重新请求id指令
//			handle_msg_start_mesh(msg);
//			break;
//		
//		default: 
//			break;
//	}
//}


//void startNewMesh(void)
//{
//	msg_start_mesh_send();	//! what should do if the slavers miss this msg?
////	PCout(13) = 0;
////	PCout(14) = 1;
//	vTaskDelay(1000);		//! i forget why delay this N ms  wait until mesh  finished
//}
/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：LED.C
 * 环境	 	  : MDK4.73-固件库V3.5版本
 * 实验平台 ：STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 : STM32F10x-STM32开发板
 * 描述     : 系统基本输出配置文件
 * 修改记录     :
 * 版本号       :  日期          作者       说明 
   V1.0.1       :  2014-09-13          
*******************************************************************************/
/* Includes---------------------------------------------*/
#include  "RF.h"
#include "main.h"
#include "BSP_FIFO.h"
#define  RF_Send_Buff_Len     128*1          //射频接收发送数组长度
uint8_t Device_Location = 0;
uint32_t LoRa_Frequency_Change =  435000000;
bool Some_Data_On_Sky = 0;
bool Rece_Frame_Data_flag = 0;
uint8_t gNoneAskForCnt = 0;
uint8_t gNodesOnLine = 0;
uint16_t RandvVlue = 0;

location_control_t  east1_control_t; //东
location_control_t  south2_control_t;//南
location_control_t  west3_control_t; //西
location_control_t  north4_control_t;//北

uint16_t Block_Code = ((0x7E<<8)&0X0D);			/*	功能隔断标志~回车	*/
uint8_t Pay_Load[] = {0x00};
uint8_t RF_size = 0; 
uint8_t RF_TX_Buff[] = {0};
//uint8_t RF_Send_Buff[RF_Send_Buff_Len];/*定义一个1KB的缓存*/
//uint8_t RF_Rece_Buff[RF_Send_Buff_Len];/*定义一个1KB的缓存*/

const uint8_t MY_TEST_Msg[] = "3";
const uint8_t Function_TEST_Msg[27]   = {0xFE,0x00,0x0c,0x01,0x01,0xff,0x0ff,0x00,0x01,0x04,0x00,0xfc,0x01,0x01,0x01,0x01,0x01,0xff,0x01,0xff,0xff,0xff,0xff,0xff,0xaa,0xff,0xef};
const uint8_t Function_TEST_Msg1[27]  = {0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};	
tRadioDriver *Radio = NULL;

bool gNetworkRunning = false;			//! the system is in running mode, if i want to ask for id, should send msg in free time  
bool gCanAskForIdTriger = false;		//! if ask for id, should under own radio period
bool gCanAskForIdDurNormMode = false;	//
void parseRadioData(void)
{
	
	uint8_t data;
	static message_t msg;
	
	Rece_Frame_Data_flag = false;
	
	while (fifoGetBufDataCount()) {
           fifoPopBuf(&data, 1);
		
		if (msg_parse_char(&msg, data)) {
			Rece_Frame_Data_flag = true;
			PCout(13) =~ PCout(13);
			handleMessage(&msg);
		}
	}
}

//void Lora_Handle( void )
//{
////	static uint8_t canCheckCnt = 0;
//	static uint8_t node_cycle = 1;
//	uint8_t i;
////	uint8_t result = 0;
//	
//	unsigned char data;
//	static message_t msg;

//	bool flag = false;
//	static volatile TickType_t currentTime;	

////	if (xTaskGetTickCount() - currentTime >= TRAVERSE_PERIOD) {
////	currentTime = xTaskGetTickCount();
////	flag = true;
////	}
////	flag = true;

////	printf("RF_TX_DONE: \n");
//////			 Indicates on a LED that we have sent a PONG
//////			Radio->SetTxPacket( MY_TEST_Msg, 1);

////	if (flag == true) 
////	{			
////		if (node_cycle > 7 ) {/*(gNodesOnLine+1)NODE_ID_NUM_MAX*/
////			node_cycle = 1;
////		}
//////		msg_start_mesh_send();
////		msg_ask_for_data_send(node_cycle); 
////		node_cycle++;
////	}
////	else 
////	{

////	}

//	switch ( Radio->Process( ) )
//	{
//		case RF_RX_DONE:	
//		{
//			//printf("RF_RX_DONE!\r\n");
//			Radio->GetRxPacket( Buffer, ( uint16_t* )&BufferSize );
//			PCout(14) = ~PCout(14);
//			for(i=0;i < BufferSize;i++)
//			{
//				data = Buffer[i];
//				fifoPushBuf(&data, 1);
////				printf(" %x",data);
//				if (msg_parse_char(&msg, data)){
//					handleMessage(&msg);
//				}
//			}
//			for(i=0;i<BUFFER_SIZE;i++)
//			Buffer[i] = 0;
//		}break;

//		case RF_TX_DONE:
//		{
//			Soft_delay_ms(2);
//			Radio->StartRx( );
//			Soft_delay_ms(2);
//		}break;
//		
//		case  RF_TX_TIMEOUT:
//		{
//		}break;
//		
//		case RF_RX_TIMEOUT:
//		{
//			
//		}break;
//	
//		default:
//		{}break;
//	}
//}


///****************************************************************/
////! msg_ask_for_data_send (master -> slaver)
//#define MSG_ID_CTRL_NODE_KM				0X00
//#define MSG_CTRL_NODE_KM_PAYLOAD_LEN	         	12
//#define MSG_RESERVE 					0XFF
////主机群发指令
//void msg_ctrl_node_km_send(uint8_t node_id)
//{   
//	reserve;
//}

/****************************************************************/
//! msg_ask_for_data_send (master -> slaver)
#define MSG_ID_ASK_FOR_DATA				0X51
#define MSG_ASK_FOR_DATA_PAYLOAD_LEN 	13

//主机轮询从机指令
void msg_ask_for_data_send(uint8_t node_id)
{
	static uint8_t msg[MSG_ASK_FOR_DATA_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];//13 + 7 = 20
	static msg_head_t          msg_head;					//! msg head
	static msg_ask_for_data_t  payload;						//! msg payload

	msg_head.stx     = STX;//1
	msg_head.len     = MSG_ASK_FOR_DATA_PAYLOAD_LEN;
	msg_head.seq     = MSG_RESERVE;
	msg_head.msg_id  = MSG_ID_ASK_FOR_DATA;//4
	
	payload.master_addr  = MSG_MASTER_ADDR;//5
	payload.slave_addr1  = MSG_RESERVE;
	payload.slave_addr2  = node[node_id].slave_addr2;
	payload.location1 	 = MSG_RESERVE;
	payload.location2 	 = node[node_id].location2;//9

//	location_control_t  east1_control_t;//东
//	location_control_t  south2_control_t;//南
//	location_control_t  west3_control_t;//西
//	location_control_t  north4_control_t;//北
	memcpy(&gITASMsg.payload.node[node_id-1], &node[node_id], sizeof(node_t));
//	switch(gITASMsg.payload.node[node_id-1].location2)
	switch(node[node_id].location2)
	{ 
		case Location_East1:	 /*		东	*/
			{
			payload.spikelamp_switch1  = east1_control_t.spikelamp_switch1;//10
			payload.voice_switch2 	   = east1_control_t.voice_switch2;
			payload.led_switch3		   = east1_control_t.led_switch3;
			payload.reserve1_switch    = east1_control_t.reserve1_switch;
			payload.reserve2_switch    = east1_control_t.reserve2_switch;
			payload.reserve3_switch    = east1_control_t.reserve3_switch;//15
			}
			break;
		
		case Location_South2: 			    /*	南	*/
			{
			payload.spikelamp_switch1  = south2_control_t.spikelamp_switch1;
			payload.voice_switch2 	   = south2_control_t.voice_switch2;
			payload.led_switch3		   = south2_control_t.led_switch3;
			payload.reserve1_switch    = south2_control_t.reserve1_switch;
			payload.reserve2_switch    = south2_control_t.reserve2_switch;
			payload.reserve3_switch    = south2_control_t.reserve3_switch;
			}
			break;
		case Location_West3:			   /*	西	*/
			{
			payload.spikelamp_switch1  = west3_control_t.spikelamp_switch1;
			payload.voice_switch2 	   = west3_control_t.voice_switch2;
			payload.led_switch3		   = west3_control_t.led_switch3;
			payload.reserve1_switch    = west3_control_t.reserve1_switch;
			payload.reserve2_switch    = west3_control_t.reserve2_switch;
			payload.reserve3_switch    = west3_control_t.reserve3_switch;
			}
			break;
		case Location_North4: 			    /*	北	*/
			{
			payload.spikelamp_switch1  = north4_control_t.spikelamp_switch1;
			payload.voice_switch2 	   = north4_control_t.voice_switch2;
			payload.led_switch3		   = north4_control_t.led_switch3;
			payload.reserve1_switch    = north4_control_t.reserve1_switch;
			payload.reserve2_switch    = north4_control_t.reserve2_switch;
			payload.reserve3_switch    = north4_control_t.reserve3_switch;
			}
			break;
		default:
			break;
	}

	payload.reserve1 = 0;//16
	payload.reserve2 = 0;//17

	memcpy(&msg, &msg_head, sizeof(msg_head));
	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload)); //! payload

	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20
	
	node[node_id].bad_cnt++; //! bigger means the slaver(node) bad and bad and bad....... !
	gITASMsg.payload.node[node_id-1].bad_cnt++;
    MSG_SEND_USART_BYTES(msg, sizeof(msg));
}

//void Fill_Location_Control(uint8_t node_id)//给方位参数控制结构体赋值，包含主机node
//{
//	
//}
//从机回复主机轮询指令
#define MSG_ID_ACK_FOR_DATA				0X52
#define MSG_ACK_FOR_DATA_PAYLOAD_LEN 	12
//从机 回复主机 轮询指令
void msg_ack_for_data_send(
							uint8_t  master_addr,
							uint8_t  slave_addr1,
							uint8_t  slave_addr2,
							uint8_t  location1,
							uint8_t  location2,
							uint8_t  trigger_num,
							uint8_t	 trigger_vehicle1,//车检器触发
							uint8_t  trigger_video2,//视频触发
							uint8_t  trigger_microwave3,//微波触发
							uint8_t  trigger_reserve1,//预留触发
							uint8_t  reserve1,
							uint8_t  reserve2/*预留四个字节*/
							)
{	
	static uint8_t			   msg[MSG_ACK_FOR_DATA_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];
	static msg_head_t	       msg_head;
	static msg_ack_for_data_t  payload;

	msg_head.stx          = STX;
	msg_head.len          = MSG_ACK_FOR_DATA_PAYLOAD_LEN;
	msg_head.seq	      = MSG_RESERVE;
	msg_head.msg_id       = MSG_ID_ACK_FOR_DATA;

	payload.master_addr  = master_addr;
	payload.slave_addr1  = slave_addr1;
	payload.slave_addr2  = slave_addr2;
	payload.location1    = location1;
	payload.location2    = location2;

	payload.trigger_num	       = trigger_num;
	payload.trigger_vehicle1   = trigger_vehicle1;
	payload.trigger_video2     = trigger_video2;
	payload.trigger_microwave3 = trigger_microwave3;
	payload.trigger_reserve1   = trigger_reserve1;
	payload.reserve1           = reserve1;
	payload.reserve2	       = reserve2;
	 
	memcpy(&msg, &msg_head, sizeof(msg_head));				   	//head 4字节
	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload));  //msg_ack_for_data_send payload 12字节
	
	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20

	current_node.bad_cnt = 0;
	
    MSG_SEND_USART_BYTES(msg, sizeof(msg));
//printf("slave_addr2 %d\r\n",slave_addr2);
}
/****************************************************************/

#define MSG_ID_ASK_FOR_ID				0X53
#define MSG_ASK_FOR_ID_PAYLOAD_LEN 		20
 //主机处理 从机发送
void msg_ask_for_id_send(uint32_t mac_0, uint32_t mac_1, uint32_t mac_2, uint8_t master_addr, uint8_t slave_addr2, uint8_t location2) 
{
	static uint8_t msg[MSG_ASK_FOR_ID_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];//7 + 15 = 22
	static msg_head_t	     msg_head;
	static msg_ask_for_id_send_t  payload;

	msg_head.stx        = STX;//1
	msg_head.len        = MSG_ASK_FOR_ID_PAYLOAD_LEN;//2
	msg_head.seq	    = 0;//3
	msg_head.msg_id     = MSG_ID_ASK_FOR_ID;//4
	
	payload.node_id     = slave_addr2;	//5
	payload.mac[0]	    = mac_0;//9
	payload.mac[1]      = mac_1;//13
	payload.mac[2]      = mac_2;//17
	
	payload.master_addr	= master_addr;//18
	payload.slave_addr1	= 0;//19	
	payload.slave_addr2	= slave_addr2;//19
	payload.location1	= 0;//20
	payload.location2	= location2;//20 

    payload.reserve1    = 0;//21
	payload.reserve2    = 0;//22
	 
	memcpy(&msg, &msg_head.stx, sizeof(msg_head));
	memcpy(&msg[sizeof(msg_head)], &payload.node_id, sizeof(payload));//! payload

	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20

	current_node.bad_cnt = 0;
	current_node.slave_addr2 = 0;
	
    MSG_SEND_USART_BYTES(msg, sizeof(msg));
}

/****************************************************************/
//! msg_assign_id_send (master -> slaver)
//主机分配ID

#define	MSG_ID_ASSIGN_ID				0X54
#define MSG_ASSIGN_ID_PAYLOAD_LEN 		16

void msg_assign_id_send(uint8_t node_id, uint32_t mac_0, uint32_t mac_1, uint32_t mac_2, uint8_t cfdt)
{
	static uint8_t msg[MSG_ASSIGN_ID_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];
	static msg_head_t	    msg_head;
	static msg_assign_id_t  payload;
	
	msg_head.stx       = STX;
	msg_head.len       = MSG_ASSIGN_ID_PAYLOAD_LEN;
	msg_head.seq	   = 0;
	msg_head.msg_id    = MSG_ID_ASSIGN_ID;
	
	payload.node_id    = node_id;
	payload.mac[0]     = mac_0;
	payload.mac[1]     = mac_1;
	payload.mac[2]     = mac_2;
	payload.cfdt	   = cfdt;
    payload.reserve1   = 0;
	payload.reserve2   = 0;
	
	memcpy(&msg, &msg_head, sizeof(msg_head));
	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload)); //! payload
 
	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20
  
    MSG_SEND_USART_BYTES(msg, sizeof(msg));
}

/****************************************************************/
//! msg_ack_for_id_send
//! ，由从机发送给主机的ID确认命令，主机若收到该命令则认为ID分配成功，否则会连续发送三次分配ID命令，
//			若均没收到该消息则不再给该节点分配ID
#define	MSG_ID_ACK_FOR_ID				0X55
#define MSG_ACK_FOR_ID_PAYLOAD_LEN 		15

void msg_ack_for_id_send(uint8_t node_id, uint32_t mac_0, uint32_t mac_1, uint32_t mac_2) 
{
	static uint8_t msg[MSG_ACK_FOR_ID_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];
	static msg_head_t	     msg_head;
	static msg_ack_for_id_t  payload;
	
	msg_head.stx       = STX;//
	msg_head.len       = MSG_ACK_FOR_ID_PAYLOAD_LEN;//
	msg_head.seq	   = 0;//
	msg_head.msg_id    = MSG_ID_ACK_FOR_ID;//
	
	payload.node_id    = node_id;//
	payload.mac[0]     = mac_0;//
	payload.mac[1]     = mac_1;//
	payload.mac[2]     = mac_2;//
    payload.reserve1   = 0;//
	payload.reserve2   = 0;//
	
	memcpy(&msg, &msg_head, sizeof(msg_head));
	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload)); //! payload

	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20
	
    MSG_SEND_USART_BYTES(msg, sizeof(msg));
}

/****************************************************************/
//! msg_start_mesh_send (master -> slaver)
//主机上电伊始，向从机群发组网命令
#define MSG_ID_START_MESH				0X56
#define MSG_START_MESH_PAYLOAD_LEN 		2

void msg_start_mesh_send(void)
{
	static uint8_t msg[MSG_START_MESH_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];
	static msg_head_t	msg_head;
	static msg_start_mesh_t payload;
	
	msg_head.stx	= STX;//1
	msg_head.len	= MSG_START_MESH_PAYLOAD_LEN;//2
	msg_head.seq	= 0x00;//3	uint8_t  seq;
	msg_head.msg_id	= MSG_ID_START_MESH;//4
	
    payload.reserve1   = 0;//5
	payload.reserve2   = 0;//6
	
	memcpy(&msg, &msg_head, sizeof(msg_head));//
	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload)); //! payload

	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB  19
	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB  18++
	msg[sizeof(msg_head)+sizeof(payload)+2] = END;  //20
	
	
	MSG_SEND_USART_BYTES(msg, sizeof(msg));
//	debugLogInfo("start mesh \n");
//	ledFlashSet(LED_MESH, 3, 2, 5);
}
void checkNodesStatePeriod(void) //检查从机状态阶段
{
	uint8_t i;
	bool flag = false;
	static volatile TickType_t currentTime;	
	
	if (xTaskGetTickCount() - currentTime >= TRAVERSE_PERIOD) {
		currentTime = xTaskGetTickCount();
		flag = true;
	}

	if (flag == true) {
		gNodesOnLine = 0;
		for (i = 1; i < NODE_ID_NUM_MAX; i++) { //! check all the nodes 
			if (node[i].bad_cnt >= NODE_BAD_CNT_MAX) {
				memset(&node[i], 0, sizeof(node_t));	//! node[i].state = NODE_STATE_OFFLINE;	
				memset(&gITASMsg.payload.node[i-1], 0, sizeof(node_t));
				
			} else if (node[i].id != 0) {
				gNodesOnLine++;// 
			}
		}
	}
}

void askForDataPeriod(void)
{
	static uint8_t canCheckCnt = 0;
	static uint8_t node_cycle = 1;
	uint8_t i;
	uint8_t result = 0;
	bool flag = false;
	static volatile TickType_t currentTime;	
	
	if (xTaskGetTickCount() - currentTime >= TRAVERSE_PERIOD) {//定时轮询
		currentTime = xTaskGetTickCount();
		flag = true;
	}	
	
	if (node_cycle >= /*gNodesOnLine*/NODE_ID_NUM_MAX) {//超过节点数  
		if (canCheckCnt++ > 1) {//初始时为0  ???
			for (i = 1; i < /*gNodesOnLine*/NODE_ID_NUM_MAX; i++) {
				result = result + node[i].state;//node[i].state为每个节点的状态 
			}

			if (result == 0) { //! no node online, start a new mesh
				node_cycle = 1;
				meshMode = MESH_MODE_START_MESH;//开始组网
			}
			canCheckCnt = 0;
		}
	}	
		
	if (flag == true) {			
		if (node_cycle >= /*(gNodesOnLine+1)*/NODE_ID_NUM_MAX) {//超过最大节点数
			node_cycle = 1;
		}
		
		msg_ask_for_data_send(node_cycle); //对节点轮询
		node_cycle++;
		
	} else {

	}		
}
//从机网络运行任务
itas_mode_t taskMesh(void)
{
	static uint8_t askForIdCnt = 0;
	itas_mode_t mode = MESH_MODE_MESH;
	u16 m=60,n=400,x=1,y=20;
	u16 p=50,q=160;
	if (current_node.slave_addr2 == 0) {
		
		gMeshFinished = 0;
		 
		if (gNetworkRunning) {//! the network is running normally  系统内某些主从网络关系已存在
//		if (gCanAskForIdDurNormMode) {	//! check if it is the free time that can send ask for id msg
			if(parse_flag){ //已接收完整帧数据 
							srand(Get_Adc(ADC_Channel_10));
							RandvVlue = rand()%(q-p+1)+p;
							vTaskDelay(RandvVlue);
//				if((Rece_Frame_Data_flag)&&(!Some_Data_On_Sky))//帧数据完整，且空中没有字节数据，
				if(parse_flag)
				{
					gCanAskForIdDurNormMode = false; 
					askForIdCnt++;
					msg_ask_for_id_send(current_node.mac[0], current_node.mac[1], current_node.mac[2], current_node.master_addr, 
										current_node.slave_addr2, current_node.location2);
					printf("normal mode: ask for id times: %d \n", askForIdCnt);
				}
			} else {
				
				//! to do 
			}
		} else {//! the network is running mesh系统伊始，组网状态
//			if (gCanAskForIdTriger) {
			if(!Some_Data_On_Sky){//空中没有字节数据，
							srand(Get_Adc(ADC_Channel_10));
							RandvVlue = rand()%(n-m+1)+m;
							vTaskDelay(RandvVlue);
				if(!Some_Data_On_Sky)//空中没有字节数据，
				{
					msg_ask_for_id_send(current_node.mac[0], current_node.mac[1], current_node.mac[2], current_node.master_addr, current_node.slave_addr2, current_node.location2);						
					askForIdCnt++; 
					printf("mesh mode: ask for id times: %d \n", askForIdCnt);
				}
			} else {
				//! to do
			}
		}			
			
		if (askForIdCnt == ASK_FOR_ID_RETRY_MAX) {//! ask for id more than n times, delay a random time then restart timer
//			vTaskDelay((current_node.mac[0] + current_node.mac[1] + current_node.mac[2])&0x00000007*20);
//			timer2Init(200);
			srand(Get_Adc(ADC_Channel_10));
			RandvVlue = rand()%(q-p+1)+p;
			vTaskDelay(RandvVlue);
		}
		
		if (askForIdCnt >= ASK_FOR_ID_RETRY_REBOOT) {//发送一次申请id ++
			systemReboot(); 
		}
		
	} else if (current_node.slave_addr2 == 255) {//! rejected my mesh request!!!
		askForIdCnt = 0;
//		timer2Init(getAskForIdPeriod());	//! just case of had modified the period
		mode = MESH_MODE_NONE;
		printf("i am ok but rejected ! \n");
		
	} else { //! get the id succeed !
		askForIdCnt = 0;
//		current_node.bad_cnt = 0;???
//		timer2Init(getAskForIdPeriod()); //! just case of had modified the period
		mode = MESH_MODE_NORMAL;
		
//		printf("i get my id = %d \n", current_node.slave_addr2);			
	}
	return mode;
}
//正常网络运行任务 
itas_mode_t taskNormalMission(void)
{
	itas_mode_t mode = MESH_MODE_NORMAL;
	
	//! to do normal mission
	if (current_node.slave_addr2 == 0){	//! master start a new mesh, should apply for a new id 
		mode = MESH_MODE_MESH; 

	}
	else if (current_node.bad_cnt > CURRENT_BAD_CNT_MAX){ //! communication is bad ! run selfcheck !
		current_node.slave_addr2 = 0;
		//mode = ITS_MODE_SELF_CHECK;
//		printf("i am running selfcheck! \n");
	}
	return mode;
}
/********************************************************************************************************************************************************/
//handle_function  从机处理
//! master -> slaver  0x51
//bool gNetworkRunning = false;
uint16_t gRadioNoDataCnt = 0;
static void handle_msg_ask_for_data(const message_t *msg)
{		
	msg_ask_for_data_t message;
	memcpy(&message, &msg->payload[0], sizeof(message));
	
	gRadioNoDataCnt = 0;	//! when received a msg, this value will be reset to 0.
	gNetworkRunning = true;	//! means the net is in running mode
	
	if (message.slave_addr2 == 0) {
		return;	//! there must be something wrong with master, just give no ack
	}
 
	if ((message.slave_addr2 == current_node.slave_addr2)||(message.slave_addr2 == current_node.id)){

		gMeshFinished = 1;
		
//		printf("slave_addr2 %d:  \n",current_node.slave_addr2);
		current_node.bad_cnt = 0;     //! can receive this msg means communication is OK!
		
		current_node.spikelamp_switch1 = message.spikelamp_switch1;
		current_node.voice_switch2     = message.voice_switch2;
		current_node.led_switch3       = message.led_switch3;
		current_node.reserve1_switch   = message.reserve1_switch;
		current_node.reserve2_switch   = message.reserve2_switch;
		current_node.reserve3_switch   = message.reserve3_switch;
		
//		KM_spikelamp_switch1 = message.spikelamp_switch1;
//		KM_voice_switch2     = message.voice_switch2;
//		KM_led_switch3       = message.led_switch3;
//		KM_reserve1_switch   = message.reserve1_switch;
//		KM_reserve2_switch   = message.reserve2_switch;
//		KM_reserve3_switch   = message.reserve3_switch;
	
		msg_ack_for_data_send(  current_node.master_addr,
								current_node.slave_addr1,
								current_node.slave_addr2,
								current_node.location1,
								current_node.location2,
								current_node.trigger_num,
								current_node.trigger_vehicle1,
								current_node.trigger_video2,
								current_node.trigger_microwave3,
								current_node.trigger_reserve1,
								current_node.reserve1,
								current_node.reserve2
							 );
//		printf("ack for data my id : %d \n", current_node.slave_addr2);
//		ledFlashSet(1, 200, 5);
	}
	else
	{};	
}
//! slaver -> master
static void handle_msg_ack_for_data(const message_t *msg)
{
	uint8_t i;
	msg_ack_for_data_t message;
	memcpy(&message, &msg->payload[0], sizeof(message));
	for (i = 1; i < NODE_ID_NUM_MAX; i++) {	//! traverse the entire array which saves all the nodes 
		if (node[i].id == message.slave_addr2) {
			

			
			node[i].state 	  		= NODE_STATE_ONLINE;
			node[i].bad_cnt	  		= 0;//! if the data ack ok, then the bad_cnt will be reset to 0, which means this slaver(node) is ok.
//			node[i].dev_type  		= message.dev_type; 	
			
			node[i].location2 		= message.location2; 
			
			node[i].trigger_num		= message.trigger_num;
			node[i].trigger_vehicle1	= message.trigger_vehicle1;
			node[i].trigger_video2	= message.trigger_video2;
			node[i].trigger_microwave3	= message.trigger_microwave3;
//			trigger_reserve1;
//			uint16_t reserved_2;

			gITASMsg.payload.nodeOnlineNum		= gNodesOnLine;
			memcpy(&gITASMsg.payload.node[i-1], &node[i], sizeof(node_t));
			break;
			
		} else if (i >= NODE_ID_NUM_MAX - 1) {
//			msg_start_mesh_send();
		}			
	}
//	ledFlashSet(LED_MESH, 1, 5, 1);
}

//! slaver -> master
static void handle_msg_ask_for_id(const message_t *msg)
{
//	uint8_t i;
//	bool need_trav_ids = false;
//	msg_ask_for_id_t message;
//	memcpy(&message, &msg->payload[0], sizeof(message));
//	gGetStartNewMeshAck = true;
//	gMeshFinished = false; //! there still some nodes want to join into the net, mesh not finished 
//	gNoneAskForCnt = 0;
//	//! traverse the entire array which saves all the nodes. i prefer to traverse mac first, if this mac has been existed, then assign the corresponding id to the node 
//	//! if can not find this mac, then traverse the id from 1 to max, assign the seq as id till the corresponding id is zero.
//	for (i = 1; i < NODE_ID_NUM_MAX; i++) {
//		if ((node[i].mac[0] == message.mac[0]) && (node[i].mac[1] == message.mac[1]) && (node[i].mac[2] == message.mac[2])) {
//			node[i].bad_cnt = 0; //! another place always check this value, if this node down less than n times, and here assign the same id again, we should reset the bad_cnt in case be reseted again 
//			node[i].c_base_red		= message.c_base_red;
//			node[i].c_base_yellow	= message.c_base_yellow;
//			node[i].c_base_green	= message.c_base_green;
//			need_trav_ids = false;
//			msg_assign_id_send(i, message.mac[0], message.mac[1], message.mac[2], NODE_BAD_CNT_MAX*NODE_ID_NUM_MAX*TRAVERSE_PERIOD/1000);
//			break;
//		
//		} else if (i >= NODE_ID_NUM_MAX-1) {
//			need_trav_ids = true;
//		}
//	}

//	//! if need, traverse the ids
//	if (need_trav_ids == true) {
//		need_trav_ids = false;
//		
//		for (i = 1; i < NODE_ID_NUM_MAX; i++) { 
//			if (node[i].id == 0) {				 
//				node[i].id     = i;
//				node[i].mac[0] = message.mac[0];
//				node[i].mac[1] = message.mac[1];
//				node[i].mac[2] = message.mac[2];
//				node[i].c_base_red		= message.c_base_red;
//				node[i].c_base_yellow	= message.c_base_yellow;
//				node[i].c_base_green	= message.c_base_green;
//				
//				msg_assign_id_send(i, message.mac[0], message.mac[1], message.mac[2], NODE_BAD_CNT_MAX * NODE_ID_NUM_MAX * TRAVERSE_PERIOD /1000);
//				break; //! must quit out otherwise will assign all the idle nodes
//		
//			} else if (i >= NODE_ID_NUM_MAX-1) { //! it means the active nodes up to MAX, then reject this node mesh
//				msg_assign_id_send(255, message.mac[0], message.mac[1], message.mac[2],  NODE_BAD_CNT_MAX * NODE_ID_NUM_MAX * TRAVERSE_PERIOD /1000);
//				
//			} else {
//				//! normal
//			}				
//		}
//		
//	}
}


//! slaver 传给-> master 
//主机处理 查询从机ID的指令 
static void handle_msg_ack_for_id(const message_t *msg)
{
//	msg_ack_for_id_t message;
//	memcpy(&message, &msg->payload[0], sizeof(message));
	return;	
}

//! master 传给-> slaver
//从机处理主机的分配ID指令
static void handle_msg_assign_id(const message_t *msg)//0X54
{
	msg_assign_id_t message;
	memcpy(&message, &msg->payload[0], sizeof(message));	
	
	if ((message.mac[0] != current_node.mac[0])||(message.mac[1] != current_node.mac[1])||(message.mac[2] != current_node.mac[2])) {
//		printf("this is not my mac! \n");
		if ((message.node_id == current_node.slave_addr2)||(message.node_id == current_node.slave_addr2)) { //! my id is reassigned to other nodes, i have to apply for a new id 
			current_node.slave_addr2 = 0;
//			printf("i have to re apply for my id \n");
		}
		
	} else {
		current_node.slave_addr2 = message.node_id;
		current_node.id          = message.node_id;
		current_node.cfdt		 = message.cfdt;
	}
}

//重新组网指令
static void handle_msg_start_mesh(const message_t *msg)
{
	current_node.slave_addr2 = 0;			//! start to mesh again
	gNetworkRunning = false;	//! means the net is in meshing mode
//	printf("start a new mesh \n");
}

/******************************************************************************************************************************************************************************************************************************
function： state machine
brief：Master Analysis the polling Packet which received from slave  （Radio->GetRxPacket( Buffer, ( uint16_t* )&BufferSize );）
return：

//#pragma pack(1)
//typedef __packed struct s_rece_oprerate{
//	uint8_t frame_head;	//0xFE
//	uint8_t frame_length[2];
//	uint8_t msg_id;//指令	
//	uint8_t master_addr;	
//	uint8_t slave_addr[2];
//	uint8_t location[2];//方位
//	uint8_t function_num;//功能个数
//	uint8_t function_operate[2];//功能动作操作
//	uint8_t data_buff[12];	//数据
//	uint8_t crc[2];		
//	uint8_t frame_tail;//0xEF
//}rece_operate_t,*rece_operate_t_p;
//#pragma pack()
//rece_operate_t_p SPI_MSG_Opreate;


******************************************************************************************************************/
	bool parse_flag = false;
bool msg_parse_char(message_t *rxmsg, uint8_t c)
{

	parse_flag = false;

	static message_t rxmsg_t;	
	static uint16_t bufferIndex;
	static msg_parse_state_t status;
	
	switch (status)
	{
	case MSG_PARSE_STATE_UNINIT:
		
	case MSG_PARSE_STATE_IDLE:
		if (c == STX) {
			rxmsg_t.stx = c;
			status = MSG_PARSE_STATE_GOT_STX; 
		} 
		break;

	case MSG_PARSE_STATE_GOT_STX:
		rxmsg_t.len = c;
		status = MSG_PARSE_STATE_GOT_LENGTH; 
		break;

	case MSG_PARSE_STATE_GOT_LENGTH:
		rxmsg_t.seq = c;
		status = MSG_PARSE_STATE_GOT_SEQ;
		break;
	
	case MSG_PARSE_STATE_GOT_SEQ:
		rxmsg_t.msg_id = c;
		status = MSG_PARSE_STATE_GOT_MSGID;
		break;

	case MSG_PARSE_STATE_GOT_MSGID:

		rxmsg_t.payload[bufferIndex++] = c;
		if (bufferIndex == rxmsg_t.len) {
			status = MSG_PARSE_STATE_GOT_PAYLOAD;
		}
		break;

	case MSG_PARSE_STATE_GOT_PAYLOAD:
			rxmsg_t.checksum =  (uint16_t)(c << 8);//高位	          
			status = MSG_PARSE_STATE_GOT_CRC1;
		break;

	case MSG_PARSE_STATE_GOT_CRC1:
			rxmsg_t.checksum |= (uint16_t)c;       //低位
			status = MSG_PARSE_STATE_GOT_CRC2;		
		break;
	
	case MSG_PARSE_STATE_GOT_CRC2:
//				printf("rxmsg_t.checksum %x\n",rxmsg_t.checksum);
//				printf("crc16(&rxmsg_t.payload[0], bufferIndex) : %x\n",crc16(&rxmsg_t.payload[0], bufferIndex));
			if ((crc16(&rxmsg_t.payload[0], bufferIndex) == rxmsg_t.checksum) && (c == END)) {
//				printf("rxmsg_t.checksum %x\n",rxmsg_t.checksum);
				memcpy(rxmsg, &rxmsg_t, sizeof(rxmsg_t));
				Some_Data_On_Sky = 0;
				parse_flag = true;
			}
			bufferIndex = 0;                                   
			status = MSG_PARSE_STATE_UNINIT;
        break;
			
	default:
		bufferIndex = 0;
		status = MSG_PARSE_STATE_UNINIT;
	}
//	printf("parse_flag %d\n",parse_flag);

	return parse_flag;
			
}
/*该节点作为从机  SLAVE*/
void handleMessage(message_t *msg)
{
	switch(msg->msg_id)
	{
		case MSG_ID_ASK_FOR_DATA://由主机发送给从机 从机处理主机发送的轮询指令
			handle_msg_ask_for_data(msg);	
			break;
	
////		case MSG_ID_ACK_FOR_DATA://由从机向主机回复的数据  主机可用
////			handle_msg_ack_for_data(msg);
////			break;	

////		case MSG_ID_ASK_FOR_ID://由从机向主机回复的数据  主机处理
////			handle_msg_ask_for_id(msg);
////			break;	

////		case MSG_ID_ACK_FOR_ID:/，由从机发送给主机的ID确认命令，主机若收到该命令则认为ID分配成功，
////									//	否则会连续发送三次分配ID命令，若均没收到该消息则不再给该节点分配ID
////			handle_msg_ack_for_id(msg);
////			break;

		case MSG_ID_ASSIGN_ID://从机接收到主机的分配ID指令之后，写入自己的current_node
			handle_msg_assign_id(msg);
			break;

		case MSG_ID_START_MESH: //从机处理主机发送的重新请求id指令
			handle_msg_start_mesh(msg);
			break;
		
		default: 
			break;
	}
}


void startNewMesh(void)
{
	msg_start_mesh_send();	//! what should do if the slavers miss this msg?
//	PCout(13) = 0;
//	PCout(14) = 1;
	vTaskDelay(1000);		//! i forget why delay this N ms  wait until mesh  finished
}


