/******************** (C) COPYRIGHT DIYǶ��ʽ����������*******************************
 *                                
 *                              ARM Cortex-M4 Port
 *
 * �ļ�����     : Utility.c (  For Cortex-M4 )
 * ��    ��     :    	 
 * ��    ��	 	: MDK5.10a-->�̼���V1.3.0�汾
 * ����ƽ̨     : STM32F407ZGT6-25MHz->168MHz 
 * �޸�ʱ��     : 2014-10-20 
 * ��    ��     : V1.0.0
 * Ӳ������     : STM32F40xx-STM32������
 * ˵    ��     : 
 * 			  
 *				   
**************************************************************************************/
#ifndef _Utility_H_
#define _Utility_H_
/* Includes---------------------------------------------*/
#include "SYS.h"
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
extern const unsigned char  DataStr[]; //�����������
extern const unsigned char  TimeStr[]; //�������ʱ��
extern uint32_t ChipUniqueID[];  //оƬ96λΨһID
extern uint16_t STM32_FLASH_SIZE; //оƬFlash��Ϣ
/* Private function prototypes -------------------------*/
/* �ṩ������C�ļ����õĺ��� */
void BSP_InitDWT(void);
void Get_ChipID(void);
void Get_ChipInfo(void);

void Delay_Init(u8 SYSCLK);
//void Delay_Init(void);
void Delay_us(u32 nus);
void Delay_ms(u16 nms);

void Soft_delay_us(u16 time);
void Soft_delay_ms(u16 time);

uint8_t XORValid(uint8_t *buffer,uint16_t Len);
uint8_t StrCmp(uint8_t *str1,uint8_t *str2,uint16_t len);
/*** һ�º�����Http Server��ʹ��**************/
char C2D(unsigned char c);
uint8_t getCRC8(uint8_t *pbuf,uint8_t len);
uint8_t checkCRC8(uint8_t *pbuf,uint8_t len);
static uint8_t Caculate_CRC8_Byte(uint8_t abyte);
uint16_t getCRC16(uint8_t *buffer, uint16_t buffer_length);
uint8_t checkCRC16(uint8_t *msg, const uint16_t msg_length, uint8_t overturn);

char CharToBCD(unsigned char c	);
char BCDToChar(unsigned char c	);
uint16_t atoi16(char* str,uint16_t base	);
void mid(char* src, char* s1, char* s2, char* sub);
void inet_addr_(unsigned char* addr,unsigned char *ip);
void replacetochar(char * str, char oldchar,char newchar);

uint16_t swaps(uint16_t i);
uint16_t htons( uint16_t hostshort);
unsigned long ntohs(unsigned short netshort);

uint8_t getAskForIdPeriod(void);
/* Private functions -----------------------------------*/
#endif
/********** (C) COPYRIGHT DIYǶ��ʽ���������� ��END OF FILE ��************************/


