/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
 * �ļ���   ��LED.C
 * ����	 	  : MDK4.73-�̼���V3.5�汾
 * ʵ��ƽ̨ ��STM32F103RBT6-8MHz->72MHz
 * �汾     ��V1.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ : STM32F10x-STM32������
 * ����     : ϵͳ������������ļ�
 * �޸ļ�¼     :
 * �汾��       :  ����          ����       ˵�� 
   V1.0.1       :  2014-09-13          
*******************************************************************************/
/* Includes---------------------------------------------*/
#include  "RF.h"
#include "main.h"
#include "BSP_FIFO.h"
#include "mesh.h"

/****************************************************************/
////! msg_ask_for_data_send (master -> slaver)
//#define MSG_ID_ASK_FOR_DATA				0X51
//#define MSG_ASK_FOR_DATA_PAYLOAD_LEN 	3

//static void mesh_msg_ask_for_data_send(uint8_t node_id)
//{   
//	static uint8_t				msg[MSG_ASK_FOR_DATA_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];
//	static msg_head_t			msg_head;						//! msg head
//	static msg_ask_for_data_t	payload;						//! msg payload

//	msg_head.stx     = STX;
//	msg_head.len     = MSG_ASK_FOR_DATA_PAYLOAD_LEN;
//	msg_head.msg_id  = MSG_ID_ASK_FOR_DATA;
//	
//	payload.location2  = node_id;
//	payload.reserve1 = 0;
//	payload.reserve2 = 0;
//	memcpy(&msg, &msg_head, sizeof(msg_head));
//	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload)); //! payload

//	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB
//	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB
//	msg[sizeof(msg_head)+sizeof(payload)+2] = END;
//	

//    MSG_SEND_USART_BYTES(msg, sizeof(msg));
//}


///****************************************************************/
////! msg_ack_for_data_send

//#define MSG_ID_ACK_FOR_DATA				0X52
//#define MSG_ACK_FOR_DATA_PAYLOAD_LEN 	9

//static void mesh_msg_ack_for_data_send(uint8_t node_id, uint8_t dev_type, uint8_t fault_type, uint8_t fault_scale) 
//{
//	static uint8_t				msg[MSG_ACK_FOR_DATA_PAYLOAD_LEN + MSG_PAYLOAD_OFFSET];
//	static msg_head_t			msg_head;
//	static msg_ack_for_data_t	payload;
//	
//	msg_head.stx        = STX;
//	msg_head.len        = MSG_ACK_FOR_DATA_PAYLOAD_LEN;
//	msg_head.seq	    = 0;
//	msg_head.msg_id     = MSG_ID_ACK_FOR_DATA;
//	
//	payload.node_id     = node_id;
//	payload.reserved_1  = 0; 							//! reserved
//	payload.dev_type    = dev_type; 					//! define later just for test here
//	payload.fault_type  = fault_type; 					//! define later just for test here
//	payload.fault_scale = fault_scale;
//	payload.reserved_4  = 0; 							//! reserved
//	
//	memcpy(&msg, &msg_head, sizeof(msg_head));
//	memcpy(&msg[sizeof(msg_head)], &payload, sizeof(payload)); //! payload

//	msg[sizeof(msg_head)+sizeof(payload)]   = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)));		//! crc LSB
//	msg[sizeof(msg_head)+sizeof(payload)+1] = (uint8_t)(crc16(&msg[sizeof(msg_head)], sizeof(payload)) >> 8);	//! crc MSB
//	msg[sizeof(msg_head)+sizeof(payload)+2] = END;
//	
//	MSG_SEND_USART_BYTES(msg, sizeof(msg)); 
//}


