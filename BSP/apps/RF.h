///**************(C) COPYRIGHT  DIYǶ��ʽ����������******************************
// * �ļ���   ��BSP_OutPut.h
// * ����	 	  : MDK4.73-�̼���V3.5-uCOS III V3.03�汾
// * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
// * �汾     ��V1.0.0
// * ����     ��
// * �޸�ʱ�� ��2013-12-20
// * Ӳ������ : STM32F10x-STM32������
// * ����     : ϵͳ������������ļ�
//*******************************************************************************/
//#ifndef __RF_H
//#define __RF_H
///* Includes---------------------------------------------*/
//#include "sys.h"
///* Private defines--------------------------------------*/
///*************************************************************LORAƽ̨������ʼ��*****************************************************************/
////#define SX1278_RX
//#define SX1278_TX
//#define BUFFER_SIZE     30                          // Define the payload size here

//#define MSG_RESERVE 						0XFF //
//#define MSG_MASTER_ADDR 					0X01 //
//#define MSG_SLAVE_ADDR1 					0X00 //
//#define MSG_SLAVE_ADDR2 					0X01 //
//#define MSG_LOCATION1						0X00 //
//#define MSG_LOCATION2 						0X01 //

////#define Operation 				0x00
//#define Operate_Spikelamp 			(1<<0)     /*	�صƹ��ܱ�־*/
//#define Operate_Voice_Colum  		(1<<1)     /*	�������ܱ�־*/
//#define Operate_Led_Guide_Screen  	(1<<2)     /*	LED���ܱ�־	*/
//#define Operate_Road_Lamp  			(1<<3)     /*	·�ƹ��ܱ�־*/
//#define Location_East1 				0x00   /*		��	*/
//#define Location_South2 			0x01     /*	��	*/
//#define Location_West3				0x02     /*	��	*/
//#define Location_North4  			0x03     /*	��	*/

//#define Master_Addr 				0x01	   /*	������ַ*/
//#define Slave_Addr 					0x01	   /*  	������ַ*/

//#define  STX    0xFE
//#define  END   	0xEF
//#define  MSG_LEN_MAX			40
//#define  MSG_PAYLOAD_OFFSET 	7     //! message len = payload len + 12(STX LEN SEQ MSGID CRC16 END)

//#define BUFFER_SIZE     30           // Define the payload size here

////#define NODE_ID_NUM_MAX		20 	//! supporst up to 20 nodes
//#define NODE_ID_NUM_MAX		10 	//! supporst up to 20 nodes
//#define NODE_BAD_CNT_MAX	5	//! if ask for data without ack more than this times, then suppose this node down 
//#define CURRENT_BAD_CNT_RESTAR	20
//#define CURRENT_BAD_CNT_MAX	20	//! if ask for data without ack more than this times, then suppose this node down 
//#define TRAVERSE_PERIOD   	30 //! ask for data per 300ms
//#define MESH_TIME_MAX		5	//! if can't receive ask for id msg more than 5 seconds, then suppose mesh finished!

//#define ASK_FOR_ID_RETRY_MAX	20	//! if ask for id more than ASK_FOR_ID_RETRY_MAX times, then modify send period; 
//#define ASK_FOR_ID_RETRY_REBOOT	20	//! if ask for id more than ASK_FOR_ID_RETRY_REBOOT times, then reboot
//extern bool Some_Data_On_Sky;
//#pragma pack(1)
//typedef __packed struct __node_t
//{
//	uint8_t  id;
//	uint8_t  state;
//	uint8_t  bad_cnt;
////	uint8_t  dev_type;
////	uint32_t run_time;
//	
//	uint8_t  master_addr;
//	uint8_t  slave_addr1;
//	uint8_t  slave_addr2;
//	uint8_t  location1;
//	uint8_t  location2;
//	uint8_t  reserve1;
//	uint8_t  reserve2;

//	uint8_t  trigger_num;
//	uint8_t  trigger_vehicle1;
//	uint8_t  trigger_video2;
//	uint8_t  trigger_microwave3;
//	uint8_t  trigger_reserve1;

//	uint8_t  spikelamp_switch1;
//	uint8_t  voice_switch2;
//	uint8_t  led_switch3;
//	uint8_t	 reserve1_switch;
//	uint8_t	 reserve2_switch;
//	uint8_t  reserve3_switch;
//	uint8_t  cfdt;
//	uint32_t mac[3];
//}node_t;
//#pragma pack()
//extern bool Rece_Frame_Data_flag;
//extern uint8_t Device_Location ;
//extern uint32_t LoRa_Frequency_Change;

//static uint16_t BufferSize = BUFFER_SIZE;			// RF buffer size
//static uint8_t  Buffer[BUFFER_SIZE];				// RF buffer

//static uint8_t EnableMaster = true; 				// Master/Slave selection

//extern uint16_t Block_Code;			/*	���ܸ��ϱ�־~�ӻس�	*/
//extern uint8_t Pay_Load[];

//extern uint16_t BufferSize;			// RF buffer size
//extern uint8_t  Buffer[BUFFER_SIZE];				// RF buffer
//extern uint8_t EnableMaster; 				//selection Master or Slave 
//extern tRadioDriver *Radio;

//extern uint16_t gRadioNoDataCnt;
//extern bool gNetworkRunning ;			//! the system is in running mode, if i want to ask for id, should send msg in free time  
//extern bool gCanAskForIdTriger;		//! if ask for id, should under own radio period
//extern bool parse_flag;  
//extern bool gCanAskForIdDurNormMode;	
//typedef __packed struct __location_control_t
//{
//	uint8_t  trigger_num;
//	uint8_t  trigger_vehicle1;
//	uint8_t  trigger_video2;
//	uint8_t  trigger_microwave3;
//	uint8_t  trigger_reserve1;

//	uint8_t  spikelamp_switch1;
//	uint8_t  voice_switch2;
//	uint8_t  led_switch3;
//	uint8_t	 reserve1_switch;
//	uint8_t	 reserve2_switch;
//	uint8_t  reserve3_switch;
//}location_control_t;

////typedef __packed struct __east1_t//��
////{
////	uint8_t  trigger_num;
////	uint8_t  trigger_vehicle1;
////	uint8_t  trigger_video2;
////	uint8_t  trigger_microwave3;

////	uint8_t  spikelamp_switch1;
////	uint8_t  voice_switch2;
////	uint8_t  led_switch3;
////}east1_t;
////typedef __packed struct __south2_t//��
////{
////	uint8_t  trigger_num;
////	uint8_t  trigger_vehicle1;
////	uint8_t  trigger_video2;
////	uint8_t  trigger_microwave3;

////	uint8_t  spikelamp_switch1;
////	uint8_t  voice_switch2;
////	uint8_t  led_switch3;
////}south2_t;
////typedef __packed struct __west3_t//��
////{
////	uint8_t  trigger_num;
////	uint8_t  trigger_vehicle1;
////	uint8_t  trigger_video2;
////	uint8_t  trigger_microwave3;

////	uint8_t  spikelamp_switch1;
////	uint8_t  voice_switch2;
////	uint8_t  led_switch3;
////}west3_t;
////typedef __packed struct __north4_t//��
////{
////	uint8_t  trigger_num;
////	uint8_t  trigger_vehicle1;
////	uint8_t  trigger_video2;
////	uint8_t  trigger_microwave3;

////	uint8_t  spikelamp_switch1;
////	uint8_t  voice_switch2;
////	uint8_t  led_switch3;
////	
////}north4_t;

////�����洢���дӻ����ݵĽṹ��
//#pragma pack(1)
//typedef __packed struct __itas_msg_payload_t
//{
//	//! itsc info
//	uint8_t		dev_code;		//! device code: 0x01: ITSC 
//	uint8_t		swv;			//! software version
//	uint8_t		power_state;
//	uint8_t	    nodeOnlineNum;//���ߴӻ���
//	node_t		node[NODE_ID_NUM_MAX];//���NODE_ID_NUM_MAX���ӻ�
//} itas_msg_payload_t;
//#pragma pack()
//typedef __packed struct __itas_msg_head_t//�����������ݵİ�ͷ����
//{
//	uint8_t  stx;
//	uint8_t	 len;  
//	uint8_t  seq;
//	uint8_t  msg_id;
//	uint8_t  master_addr;
//	uint8_t  slave_addr1;
//	uint8_t  slave_addr2;
//	uint8_t  location1;
//	uint8_t  location2;
//	uint16_t checksum; 	
//} itas_msg_head_t;

//typedef enum //����״̬��״̬��־
//{
//	MESH_MODE_UNINIT = 0,//��ʼ��
//	MESH_MODE_IDLE,//����
//	MESH_MODE_START_MESH,//��ʼ����
//	MESH_MODE_MESH,//����ingģʽ
//	MESH_MODE_NORMAL,//������������
//	MESH_MODE_SELF_CHECK,//�����Լ�ģʽ
//	MESH_MODE_NONE	//������״̬
//} itas_mode_t; //! the itas_mode_t slave work mode��������״̬��־

//extern  itas_mode_t meshMode;

//typedef __packed struct __itas_msg_t
//{
//	itas_msg_head_t		head;
//	itas_msg_payload_t	payload;
//	uint16_t			checksum;
//	uint8_t				end;
//} itas_msg_t;
///*�����������ݴ�������ṹ��*/
//typedef __packed struct __message_t 
//{
//	uint8_t  stx;
//	uint8_t	 len;  
//	uint8_t  seq;
//	uint8_t  msg_id;
////	uint8_t  master_addr;
////	uint8_t  slave_addr1;
////	uint8_t  slave_addr2;
////	uint8_t  location1;
////	uint8_t  location2;	
//	uint8_t  payload[MSG_LEN_MAX];	
//	uint16_t checksum; 	
//} message_t;


//typedef enum msg_parse_state_t
//{
//    MSG_PARSE_STATE_UNINIT = 0,
//    MSG_PARSE_STATE_IDLE,
//    MSG_PARSE_STATE_GOT_STX,
//    MSG_PARSE_STATE_GOT_LENGTH,
//	MSG_PARSE_STATE_GOT_SEQ,
//	MSG_PARSE_STATE_GOT_MSGID,
//	
//	MSG_PARSE_STATE_GOT_MASTERADDR,
//	MSG_PARSE_STATE_GOT_SLAVERADDR1,
//	MSG_PARSE_STATE_GOT_SLAVERADDR2,
//	MSG_PARSE_STATE_GOT_LOCATION1,
//	MSG_PARSE_STATE_GOT_LOCATION2,

//    MSG_PARSE_STATE_GOT_PAYLOAD,
//    MSG_PARSE_STATE_GOT_CRC1,
//	MSG_PARSE_STATE_GOT_CRC2,
//	MSG_PARSE_STATE_GOT_END,
//	MSG_PARSE_STATE_GOT_OK
//} msg_parse_state_t; //! The state machine for the comm parser

////���� �洢 �����ӻ���Ϣ�Ľṹ��

//typedef enum //�ӻ�����״̬��־
//{
//    NODE_STATE_OFFLINE = 0,
//    NODE_STATE_ONLINE
//} node_state_t;

//#pragma pack(1)
//// ! �ӻ��洢��¼�Լ���Ϣ�Ľṹ��
//typedef __packed struct __machine_state_t
//{
//	uint8_t  id; 	
//	uint8_t  state;
//	uint8_t  bad_cnt;
//	uint8_t  dev_type;
//	uint32_t run_time;	
//	uint8_t  slave_addr1; 
//	uint8_t  slave_addr2;
//	uint8_t  location1;
//	uint8_t  location2;
//	uint8_t  vehicle_detective;
//	uint8_t  video_detective;
//	uint8_t  microwave_detective;
//	uint8_t  reserve1_detective;
//	uint8_t  spikelamp_switch1;
//	uint8_t  voice_switch2;
//	uint8_t  led_switch3;
//	uint8_t	 reserve1_switch;
//	uint8_t	 reserve2_switch;
//	uint8_t  reserve3_switch;
//	uint32_t mac[3];
//} machine_state_t;
//#pragma pack()

//typedef __packed struct __msg_head_t
//{
//	uint8_t  stx;
//	uint8_t	 len;  
//	uint8_t  seq;
//	uint8_t  msg_id;
//} msg_head_t;

//typedef __packed struct __msg_start_mesh_t
//{ 
//	uint8_t reserve1; //����ָ��û��payloadʵ��ֵ
//	uint8_t reserve2; //����ָ��û��payloadʵ��ֵ
//} msg_start_mesh_t;

//typedef __packed struct __msg_ctrl_node_km_t 
//{ 
//	//	uint8_t  dev_type;
//	uint8_t  master_addr;
//	uint8_t  slave_addr1; 	
//	uint8_t  slave_addr2;
//	uint8_t  location1;
//	uint8_t  location2;
//	uint8_t  trigger_num;
//	uint8_t  trigger_vehicle1;
//	uint8_t  trigger_video2;
//	uint8_t  trigger_microwave3;
//	uint8_t  trigger_reserve1;
//	uint8_t  reserve1;
//	uint8_t  reserve2;

//	uint8_t  spikelamp_switch1;
//	uint8_t  voice_switch2;
//	uint8_t  led_switch3;
//	uint8_t	 reserve1_switch;
//	uint8_t	 reserve2_switch;
//	uint8_t  reserve3_switch;
//} msg_ctrl_node_km_t;

//typedef __packed struct __msg_ask_for_data_t//���������ӻ�
//{ 
//	//	uint8_t  dev_type;
//	uint8_t  master_addr;
//	uint8_t  slave_addr1; 	
//	uint8_t  slave_addr2;
//	uint8_t  location1;
//	uint8_t  location2;
////	uint8_t  trigger_num;
////	uint8_t  trigger_vehicle1;
////	uint8_t  trigger_video2;
////	uint8_t  trigger_microwave3;
////	uint8_t  trigger_reserve1;
//	
////	uint8_t  switch_num;	
//	uint8_t  spikelamp_switch1;
//	uint8_t  voice_switch2;
//	uint8_t  led_switch3;
//	uint8_t	 reserve1_switch;
//	uint8_t	 reserve2_switch;
//	uint8_t  reserve3_switch;
//	
//	uint8_t reserve1;
//	uint8_t reserve2;
//} msg_ask_for_data_t;

//typedef __packed struct __msg_ack_for_data_t//�ӻ���Ӧ����������������������
//{ 
////	uint8_t  dev_type;
//	uint8_t  master_addr;
//	uint8_t  slave_addr1; 	
//	uint8_t  slave_addr2;
//	uint8_t  location1;
//	uint8_t  location2;
//	uint8_t  trigger_num;
//	uint8_t  trigger_vehicle1;
//	uint8_t  trigger_video2;
//	uint8_t  trigger_microwave3;
//	uint8_t  trigger_reserve1;
//	uint8_t reserve1;
//	uint8_t reserve2;
//} msg_ack_for_data_t;

//#pragma pack(1)
//typedef __packed struct __msg_ask_for_id_t
//{ 
//	uint8_t  node_id; 
//	uint32_t mac[3];
//	uint8_t  master_addr;
//	uint8_t  slave_addr1; 	
//	uint8_t  slave_addr2;
//	uint8_t  location1;
//	uint8_t  location2;
//	uint8_t  trigger_num;
//	uint8_t  trigger_vehicle1;
//	uint8_t  trigger_video2;
//	uint8_t  trigger_microwave3;
//	uint8_t  trigger_reserve1;
//	uint8_t reserve1;
//	uint8_t reserve2;
//} msg_ask_for_id_t;
//#pragma pack()


//#pragma pack(1)
//typedef __packed struct __msg_ask_for_id_send_t
//{ 
//	uint8_t  node_id; 
//	uint32_t mac[3];
//	uint8_t  master_addr;
//	uint8_t  slave_addr1; 	
//	uint8_t  slave_addr2;
//	uint8_t  location1;
//	uint8_t  location2;

//	uint8_t reserve1;
//	uint8_t reserve2;
//} msg_ask_for_id_send_t;
//#pragma pack()


//#pragma pack(1)
//typedef __packed struct __msg_ack_for_id_t
//{ 
//	uint8_t  node_id; 
//	uint32_t mac[3];
//	uint8_t reserve1;
//	uint8_t reserve2;
//} msg_ack_for_id_t;
//#pragma pack()

//#pragma pack(1)
//typedef __packed struct __msg_assign_id_t//����id
//{ 
//	uint8_t  node_id; 
//	uint32_t mac[3];
//	uint8_t  cfdt; //! communication fault determination time: ͨ�Ŵ��� ����ʱ��(s)
//	uint8_t reserve1;
//	uint8_t reserve2;
//} msg_assign_id_t;
//#pragma pack()

//bool msg_parse_char(message_t *rxmsg, uint8_t c);
//void msg_start_mesh_send(void);
//void msg_ask_for_data_send(uint8_t node_id);
//void msg_ack_for_data_send(
//							uint8_t  master_addr,
//							uint8_t  slave_addr1,
//							uint8_t  slave_addr2,
//							uint8_t  location1,
//							uint8_t  location2,
//							uint8_t  trigger_num,
//							uint8_t	 trigger_vehicle1,//����������
//							uint8_t  trigger_video2,//��Ƶ����
//							uint8_t  trigger_microwave3,//΢������
//							uint8_t  trigger_reserve1,//Ԥ������
//							uint8_t  reserve1,
//							uint8_t  reserve2/*Ԥ���ĸ��ֽ�*/
//							);
//void msg_ask_for_id_send(uint32_t mac_0, uint32_t mac_1, uint32_t mac_2, uint8_t master_addr, uint8_t slave_addr2, uint8_t location2) ;
//void msg_assign_id_send(uint8_t node_id, uint32_t mac_0, uint32_t mac_1, uint32_t mac_2, uint8_t cfdt);
//void msg_ack_for_id_send(uint8_t node_id, uint32_t mac_0, uint32_t mac_1, uint32_t mac_2);
//void handleMessage(message_t *msg);

//static void handle_msg_start_mesh(const message_t *msg);
//static void handle_msg_ack_for_data(const message_t *msg);
//static void handle_msg_ask_for_data(const message_t *msg);
//static void handle_msg_ask_for_id(const message_t *msg);
//static void handle_msg_ack_for_id(const message_t *msg);
//static void handle_msg_assign_id(const message_t *msg);
////static void handle_msg_start_mesh(const message_t *msg);
///* Private function prototypes--------------------------*/
//void OnMaster( void );
//void OnSlave( void );
//void RF_Sx1278(void);
//void Lora_Handle( void );
//void parseRadioData(void);
//void checkNodesStatePeriod(void);
//void askForDataPeriod(void);

//itas_mode_t taskMesh(void);
//itas_mode_t taskNormalMission(void);

///* Private functions -----------------------------------*/
///********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
//#endif
/**************(C) COPYRIGHT  DIYǶ��ʽ����������******************************
 * �ļ���   ��BSP_OutPut.h
 * ����	 	  : MDK4.73-�̼���V3.5-uCOS III V3.03�汾
 * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
 * �汾     ��V1.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ : STM32F10x-STM32������
 * ����     : ϵͳ������������ļ�
*******************************************************************************/
#ifndef __RF_H
#define __RF_H
/* Includes---------------------------------------------*/
#include "sys.h"
/* Private defines--------------------------------------*/
/*************************************************************LORAƽ̨������ʼ��*****************************************************************/
//#define SX1278_RX
#define SX1278_TX
#define BUFFER_SIZE     30                          // Define the payload size here

#define MSG_RESERVE 						0XFF //
#define MSG_MASTER_ADDR 					0X01 //
#define MSG_SLAVE_ADDR1 					0X00 //
#define MSG_SLAVE_ADDR2 					0X01 //
#define MSG_LOCATION1						0X00 //
#define MSG_LOCATION2 						0X01 //

//#define Operation 				0x00
#define Operate_Spikelamp 			(1<<0)     /*	�صƹ��ܱ�־*/
#define Operate_Voice_Colum  		(1<<1)     /*	�������ܱ�־*/
#define Operate_Led_Guide_Screen  	(1<<2)     /*	LED���ܱ�־	*/
#define Operate_Road_Lamp  			(1<<3)     /*	·�ƹ��ܱ�־*/
#define Location_East1 				0x00   /*		��	*/
#define Location_South2 			0x01     /*	��	*/
#define Location_West3				0x02     /*	��	*/
#define Location_North4  			0x03     /*	��	*/

#define Master_Addr 				0x01	   /*	������ַ*/
#define Slave_Addr 					0x01	   /*  	������ַ*/

#define  STX    0xFE
#define  END   	0xEF
#define  MSG_LEN_MAX			40
#define  MSG_PAYLOAD_OFFSET 	7     //! message len = payload len + 12(STX LEN SEQ MSGID CRC16 END)

#define BUFFER_SIZE     30           // Define the payload size here

//#define NODE_ID_NUM_MAX		20 	//! supporst up to 20 nodes
#define NODE_ID_NUM_MAX		10 	//! supporst up to 20 nodes
#define NODE_BAD_CNT_MAX	5	//! if ask for data without ack more than this times, then suppose this node down 
#define CURRENT_BAD_CNT_RESTAR	60
#define CURRENT_BAD_CNT_MAX	20	//! if ask for data without ack more than this times, then suppose this node down 
#define TRAVERSE_PERIOD   	30 //! ask for data per 300ms
#define MESH_TIME_MAX		5	//! if can't receive ask for id msg more than 5 seconds, then suppose mesh finished!

#define ASK_FOR_ID_RETRY_MAX	20	//! if ask for id more than ASK_FOR_ID_RETRY_MAX times, then modify send period; 
#define ASK_FOR_ID_RETRY_REBOOT	50	//! if ask for id more than ASK_FOR_ID_RETRY_REBOOT times, then reboot
extern bool Some_Data_On_Sky;
extern bool parse_flag;
#pragma pack(1)
typedef __packed struct __node_t
{
	uint8_t  id;
	uint8_t  state;
	uint8_t  bad_cnt;
//	uint8_t  dev_type;
//	uint32_t run_time;
	
	uint8_t  master_addr;
	uint8_t  slave_addr1;
	uint8_t  slave_addr2;
	uint8_t  location1;
	uint8_t  location2;
	uint8_t  reserve1;
	uint8_t  reserve2;

	uint8_t  trigger_num;
	uint8_t  trigger_vehicle1;
	uint8_t  trigger_video2;
	uint8_t  trigger_microwave3;
	uint8_t  trigger_reserve1;

	uint8_t  spikelamp_switch1;
	uint8_t  voice_switch2;
	uint8_t  led_switch3;
	uint8_t	 reserve1_switch;
	uint8_t	 reserve2_switch;
	uint8_t  reserve3_switch;
	uint8_t  cfdt;
	uint32_t mac[3];
}node_t;
#pragma pack()
extern bool Rece_Frame_Data_flag;
extern uint8_t Device_Location ;
extern uint32_t LoRa_Frequency_Change;

static uint16_t BufferSize = BUFFER_SIZE;			// RF buffer size
static uint8_t  Buffer[BUFFER_SIZE];				// RF buffer

static uint8_t EnableMaster = true; 				// Master/Slave selection

extern uint16_t Block_Code;			/*	���ܸ��ϱ�־~�ӻس�	*/
extern uint8_t Pay_Load[];

extern uint16_t BufferSize;			// RF buffer size
extern uint8_t  Buffer[BUFFER_SIZE];				// RF buffer
extern uint8_t EnableMaster; 				//selection Master or Slave 
extern tRadioDriver *Radio;

extern uint16_t gRadioNoDataCnt;
extern bool gNetworkRunning ;			//! the system is in running mode, if i want to ask for id, should send msg in free time  
extern bool gCanAskForIdTriger;		//! if ask for id, should under own radio period
extern bool gCanAskForIdDurNormMode;	
typedef __packed struct __location_control_t
{
	uint8_t  trigger_num;
	uint8_t  trigger_vehicle1;
	uint8_t  trigger_video2;
	uint8_t  trigger_microwave3;
	uint8_t  trigger_reserve1;

	uint8_t  spikelamp_switch1;
	uint8_t  voice_switch2;
	uint8_t  led_switch3;
	uint8_t	 reserve1_switch;
	uint8_t	 reserve2_switch;
	uint8_t  reserve3_switch;
}location_control_t;

//typedef __packed struct __east1_t//��
//{
//	uint8_t  trigger_num;
//	uint8_t  trigger_vehicle1;
//	uint8_t  trigger_video2;
//	uint8_t  trigger_microwave3;

//	uint8_t  spikelamp_switch1;
//	uint8_t  voice_switch2;
//	uint8_t  led_switch3;
//}east1_t;
//typedef __packed struct __south2_t//��
//{
//	uint8_t  trigger_num;
//	uint8_t  trigger_vehicle1;
//	uint8_t  trigger_video2;
//	uint8_t  trigger_microwave3;

//	uint8_t  spikelamp_switch1;
//	uint8_t  voice_switch2;
//	uint8_t  led_switch3;
//}south2_t;
//typedef __packed struct __west3_t//��
//{
//	uint8_t  trigger_num;
//	uint8_t  trigger_vehicle1;
//	uint8_t  trigger_video2;
//	uint8_t  trigger_microwave3;

//	uint8_t  spikelamp_switch1;
//	uint8_t  voice_switch2;
//	uint8_t  led_switch3;
//}west3_t;
//typedef __packed struct __north4_t//��
//{
//	uint8_t  trigger_num;
//	uint8_t  trigger_vehicle1;
//	uint8_t  trigger_video2;
//	uint8_t  trigger_microwave3;

//	uint8_t  spikelamp_switch1;
//	uint8_t  voice_switch2;
//	uint8_t  led_switch3;
//	
//}north4_t;

//�����洢���дӻ����ݵĽṹ��
#pragma pack(1)
typedef __packed struct __itas_msg_payload_t
{
	//! itsc info
	uint8_t		dev_code;		//! device code: 0x01: ITSC 
	uint8_t		swv;			//! software version
	uint8_t		power_state;
	uint8_t	    nodeOnlineNum;//���ߴӻ���
	node_t		node[NODE_ID_NUM_MAX];//���NODE_ID_NUM_MAX���ӻ�
} itas_msg_payload_t;
#pragma pack()
typedef __packed struct __itas_msg_head_t//�����������ݵİ�ͷ����
{
	uint8_t  stx;
	uint8_t	 len;  
	uint8_t  seq;
	uint8_t  msg_id;
	uint8_t  master_addr;
	uint8_t  slave_addr1;
	uint8_t  slave_addr2;
	uint8_t  location1;
	uint8_t  location2;
	uint16_t checksum; 	
} itas_msg_head_t;

typedef enum //����״̬��״̬��־
{
	MESH_MODE_UNINIT = 0,//��ʼ��
	MESH_MODE_IDLE,//����
	MESH_MODE_START_MESH,//��ʼ����
	MESH_MODE_MESH,//����ingģʽ
	MESH_MODE_NORMAL,//������������
	MESH_MODE_SELF_CHECK,//�����Լ�ģʽ
	MESH_MODE_NONE	//������״̬
} itas_mode_t; //! the itas_mode_t slave work mode��������״̬��־

extern  itas_mode_t meshMode;

typedef __packed struct __itas_msg_t
{
	itas_msg_head_t		head;
	itas_msg_payload_t	payload;
	uint16_t			checksum;
	uint8_t				end;
} itas_msg_t;
/*�����������ݴ�������ṹ��*/
typedef __packed struct __message_t 
{
	uint8_t  stx;
	uint8_t	 len;  
	uint8_t  seq;
	uint8_t  msg_id;
//	uint8_t  master_addr;
//	uint8_t  slave_addr1;
//	uint8_t  slave_addr2;
//	uint8_t  location1;
//	uint8_t  location2;	
	uint8_t  payload[MSG_LEN_MAX];	
	uint16_t checksum; 	
} message_t;


typedef enum msg_parse_state_t
{
    MSG_PARSE_STATE_UNINIT = 0,
    MSG_PARSE_STATE_IDLE,
    MSG_PARSE_STATE_GOT_STX,
    MSG_PARSE_STATE_GOT_LENGTH,
	MSG_PARSE_STATE_GOT_SEQ,
	MSG_PARSE_STATE_GOT_MSGID,
	
	MSG_PARSE_STATE_GOT_MASTERADDR,
	MSG_PARSE_STATE_GOT_SLAVERADDR1,
	MSG_PARSE_STATE_GOT_SLAVERADDR2,
	MSG_PARSE_STATE_GOT_LOCATION1,
	MSG_PARSE_STATE_GOT_LOCATION2,

    MSG_PARSE_STATE_GOT_PAYLOAD,
    MSG_PARSE_STATE_GOT_CRC1,
	MSG_PARSE_STATE_GOT_CRC2,
	MSG_PARSE_STATE_GOT_END,
	MSG_PARSE_STATE_GOT_OK
} msg_parse_state_t; //! The state machine for the comm parser

//���� �洢 �����ӻ���Ϣ�Ľṹ��

typedef enum //�ӻ�����״̬��־
{
    NODE_STATE_OFFLINE = 0,
    NODE_STATE_ONLINE
} node_state_t;

#pragma pack(1)
// ! �ӻ��洢��¼�Լ���Ϣ�Ľṹ��
typedef __packed struct __machine_state_t
{
	uint8_t  id; 	
	uint8_t  state;
	uint8_t  bad_cnt;
	uint8_t  dev_type;
	uint32_t run_time;	
	uint8_t  slave_addr1; 
	uint8_t  slave_addr2;
	uint8_t  location1;
	uint8_t  location2;
	uint8_t  vehicle_detective;
	uint8_t  video_detective;
	uint8_t  microwave_detective;
	uint8_t  reserve1_detective;
	uint8_t  spikelamp_switch1;
	uint8_t  voice_switch2;
	uint8_t  led_switch3;
	uint8_t	 reserve1_switch;
	uint8_t	 reserve2_switch;
	uint8_t  reserve3_switch;
	uint32_t mac[3];
} machine_state_t;
#pragma pack()

typedef __packed struct __msg_head_t
{
	uint8_t  stx;
	uint8_t	 len;  
	uint8_t  seq;
	uint8_t  msg_id;
} msg_head_t;

typedef __packed struct __msg_start_mesh_t
{ 
	uint8_t reserve1; //����ָ��û��payloadʵ��ֵ
	uint8_t reserve2; //����ָ��û��payloadʵ��ֵ
} msg_start_mesh_t;

typedef __packed struct __msg_ctrl_node_km_t 
{ 
	//	uint8_t  dev_type;
	uint8_t  master_addr;
	uint8_t  slave_addr1; 	
	uint8_t  slave_addr2;
	uint8_t  location1;
	uint8_t  location2;
	uint8_t  trigger_num;
	uint8_t  trigger_vehicle1;
	uint8_t  trigger_video2;
	uint8_t  trigger_microwave3;
	uint8_t  trigger_reserve1;
	uint8_t  reserve1;
	uint8_t  reserve2;

	uint8_t  spikelamp_switch1;
	uint8_t  voice_switch2;
	uint8_t  led_switch3;
	uint8_t	 reserve1_switch;
	uint8_t	 reserve2_switch;
	uint8_t  reserve3_switch;
} msg_ctrl_node_km_t;

typedef __packed struct __msg_ask_for_data_t//���������ӻ�
{ 
	//	uint8_t  dev_type;
	uint8_t  master_addr;
	uint8_t  slave_addr1; 	
	uint8_t  slave_addr2;
	uint8_t  location1;
	uint8_t  location2;
//	uint8_t  trigger_num;
//	uint8_t  trigger_vehicle1;
//	uint8_t  trigger_video2;
//	uint8_t  trigger_microwave3;
//	uint8_t  trigger_reserve1;
	
//	uint8_t  switch_num;	
	uint8_t  spikelamp_switch1;
	uint8_t  voice_switch2;
	uint8_t  led_switch3;
	uint8_t	 reserve1_switch;
	uint8_t	 reserve2_switch;
	uint8_t  reserve3_switch;
	
	uint8_t reserve1;
	uint8_t reserve2;
} msg_ask_for_data_t;

typedef __packed struct __msg_ack_for_data_t//�ӻ���Ӧ����������������������
{ 
//	uint8_t  dev_type;
	uint8_t  master_addr;
	uint8_t  slave_addr1; 	
	uint8_t  slave_addr2;
	uint8_t  location1;
	uint8_t  location2;
	uint8_t  trigger_num;
	uint8_t  trigger_vehicle1;
	uint8_t  trigger_video2;
	uint8_t  trigger_microwave3;
	uint8_t  trigger_reserve1;
	uint8_t reserve1;
	uint8_t reserve2;
} msg_ack_for_data_t;

#pragma pack(1)
typedef __packed struct __msg_ask_for_id_t
{ 
	uint8_t  node_id; 
	uint32_t mac[3];
	uint8_t  master_addr;
	uint8_t  slave_addr1; 	
	uint8_t  slave_addr2;
	uint8_t  location1;
	uint8_t  location2;
	uint8_t  trigger_num;
	uint8_t  trigger_vehicle1;
	uint8_t  trigger_video2;
	uint8_t  trigger_microwave3;
	uint8_t  trigger_reserve1;
	uint8_t reserve1;
	uint8_t reserve2;
} msg_ask_for_id_t;
#pragma pack()


#pragma pack(1)
typedef __packed struct __msg_ask_for_id_send_t
{ 
	uint8_t  node_id; 
	uint32_t mac[3];
	uint8_t  master_addr;
	uint8_t  slave_addr1; 	
	uint8_t  slave_addr2;
	uint8_t  location1;
	uint8_t  location2;

	uint8_t reserve1;
	uint8_t reserve2;
} msg_ask_for_id_send_t;
#pragma pack()


#pragma pack(1)
typedef __packed struct __msg_ack_for_id_t
{ 
	uint8_t  node_id; 
	uint32_t mac[3];
	uint8_t reserve1;
	uint8_t reserve2;
} msg_ack_for_id_t;
#pragma pack()

#pragma pack(1)
typedef __packed struct __msg_assign_id_t//����id
{ 
	uint8_t  node_id; 
	uint32_t mac[3];
	uint8_t  cfdt; //! communication fault determination time: ͨ�Ŵ��� ����ʱ��(s)
	uint8_t reserve1;
	uint8_t reserve2;
} msg_assign_id_t;
#pragma pack()

bool msg_parse_char(message_t *rxmsg, uint8_t c);
void msg_start_mesh_send(void);
void msg_ask_for_data_send(uint8_t node_id);
void msg_ack_for_data_send(
							uint8_t  master_addr,
							uint8_t  slave_addr1,
							uint8_t  slave_addr2,
							uint8_t  location1,
							uint8_t  location2,
							uint8_t  trigger_num,
							uint8_t	 trigger_vehicle1,//����������
							uint8_t  trigger_video2,//��Ƶ����
							uint8_t  trigger_microwave3,//΢������
							uint8_t  trigger_reserve1,//Ԥ������
							uint8_t  reserve1,
							uint8_t  reserve2/*Ԥ���ĸ��ֽ�*/
							);
void msg_ask_for_id_send(uint32_t mac_0, uint32_t mac_1, uint32_t mac_2, uint8_t master_addr, uint8_t slave_addr2, uint8_t location2) ;
void msg_assign_id_send(uint8_t node_id, uint32_t mac_0, uint32_t mac_1, uint32_t mac_2, uint8_t cfdt);
void msg_ack_for_id_send(uint8_t node_id, uint32_t mac_0, uint32_t mac_1, uint32_t mac_2);
void handleMessage(message_t *msg);

static void handle_msg_start_mesh(const message_t *msg);
static void handle_msg_ack_for_data(const message_t *msg);
static void handle_msg_ask_for_data(const message_t *msg);
static void handle_msg_ask_for_id(const message_t *msg);
static void handle_msg_ack_for_id(const message_t *msg);
static void handle_msg_assign_id(const message_t *msg);
//static void handle_msg_start_mesh(const message_t *msg);
/* Private function prototypes--------------------------*/
void OnMaster( void );
void OnSlave( void ); 
void RF_Sx1278(void);
void Lora_Handle( void );
void parseRadioData(void);
void checkNodesStatePeriod(void);
void askForDataPeriod(void);

itas_mode_t taskMesh(void);
itas_mode_t taskNormalMission(void);

/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
#endif


