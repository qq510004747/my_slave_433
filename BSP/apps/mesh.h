#ifndef _MESH_H
#define _MESH_H

#include <stm32f10x.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys.h>
#include <RF.h>

//#define  MSG_LEN_MAX		32
//#define  MSG_PAYLOAD_OFFSET 7     //! message len = payload len + 7(STX LEN SEQ MSGID CRC16 END)
//#define  STX				0xFE
//#define  END				0xEF



//typedef __packed struct __message_t 
//{
//	uint16_t checksum; 	
//	uint8_t  stx;
//	uint8_t	 len;  
//	uint8_t  seq;
//	uint8_t  msg_id;
//	uint8_t  payload[MSG_LEN_MAX];		
//} message_t;




//typedef __packed struct __msg_head_t
//{
//	uint8_t   stx;
//	uint8_t	  len;  //! payload len
//	uint8_t   seq;
//	uint8_t   msg_id;
//} msg_head_t;



//typedef __packed struct __msg_start_mesh_t
//{ 
//	uint16_t reserved; 
//} msg_start_mesh_t;



//typedef __packed struct __msg_ask_for_data_t
//{ 
//	uint8_t  node_id; 
//	uint16_t reserved; 
//} msg_ask_for_data_t;



//typedef __packed struct __msg_ack_for_data_t
//{ 
//	uint8_t  node_id; 
//	uint8_t  reserved_1;
//	uint8_t	 dev_type;
//	uint8_t  fault_type;
//	uint8_t  fault_scale;
//	uint32_t reserved_4;
//} msg_ack_for_data_t;



//typedef __packed struct __msg_ask_for_id_t
//{ 
//	uint8_t  node_id; 
//	uint32_t mac[3];
//	uint16_t reserved;
//} msg_ask_for_id_t;



//typedef __packed struct __msg_ack_for_id_t
//{ 
//	uint8_t  node_id; 
//	uint32_t mac[3];
//	uint16_t reserved;
//} msg_ack_for_id_t;




//typedef __packed struct __msg_assign_id_t
//{ 
//	uint8_t  node_id; 
//	uint32_t mac[3];
//	uint8_t  cfdt; //! communication fault determination time: (s)
//	uint8_t  reserved;
//} msg_assign_id_t;




//static bool mesh_msg_parse_char(message_t *rxmsg, uint8_t c);
//static void mesh_msg_start_mesh_send(void);
//static void mesh_msg_ask_for_data_send(uint8_t node_id);
//static void mesh_msg_ack_for_data_send(uint8_t node_id, uint8_t dev_type, uint8_t fault_type, uint8_t fault_scale); 
//static void mesh_msg_ask_for_id_send(uint32_t mac_0, uint32_t mac_1, uint32_t mac_2);
//static void mesh_msg_assign_id_send(uint8_t node_id, uint32_t mac_0, uint32_t mac_1, uint32_t mac_2, uint8_t cfdt);
//static void mesh_msg_ack_for_id_send(uint8_t node_id, uint32_t mac_0, uint32_t mac_1, uint32_t mac_2);
//static void mesh_handleMessage(message_t *msg);

//static void mesh_handle_msg_start_mesh(const message_t *msg);
//static void mesh_handle_msg_ack_for_data(const message_t *msg);
//static void mesh_handle_msg_ask_for_data(const message_t *msg);
//static void mesh_handle_msg_ask_for_id(const message_t *msg);
//static void mesh_handle_msg_ack_for_id(const message_t *msg);
//static void mesh_handle_msg_assign_id(const message_t *msg);

//typedef enum msg_parse_state_t
//{
//    MSG_PARSE_STATE_UNINIT = 0,
//    MSG_PARSE_STATE_IDLE,
//    MSG_PARSE_STATE_GOT_STX,
//    MSG_PARSE_STATE_GOT_LENGTH,
//	MSG_PARSE_STATE_GOT_SEQ,
//	MSG_PARSE_STATE_GOT_MSGID,
//    MSG_PARSE_STATE_GOT_PAYLOAD,
//    MSG_PARSE_STATE_GOT_CRC1,
//	MSG_PARSE_STATE_GOT_CRC2,
//	MSG_PARSE_STATE_GOT_END,
//	MSG_PARSE_STATE_GOT_OK
//} msg_parse_state_t; //! The state machine for the comm parser

#endif 



