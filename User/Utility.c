/******************** (C) COPYRIGHT DIYǶ��ʽ����������*******************************
 *                                
 *                              ARM Cortex-M4 Port
 *
 * �ļ�����     : Utility.c (  For Cortex-M4 )
 * ��    ��     :    	 
 * ��    ��	 	: MDK5.10a-->�̼���V1.5.0�汾
 * ����ƽ̨     : STM32F407ZGT6-25MHz->168MHz 
 * �޸�ʱ��     : 2014-10-20 
 * ��    ��     : V1.0.0
 * Ӳ������     : STM32F40xx-STM32������
 * ˵    ��     : 
 * 			  
 *				   
**************************************************************************************/
/* Includes---------------------------------------------*/
#include "Utility.h"
#include "crc.h"
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
static u8  fac_us = 0;//us��ʱ������			   
static u16 fac_ms = 0;//ms��ʱ������,
//static void Delay_xms(u16 nms);

#define  DWT_CYCCNT  *(volatile unsigned int *)0xE0001004
#define  DWT_CR      *(volatile unsigned int *)0xE0001000
#define  DEM_CR      *(volatile unsigned int *)0xE000EDFC
#define  DBGMCU_CR   *(volatile unsigned int *)0xE0042004

#define  DEM_CR_TRCENA               (1 << 24)
#define  DWT_CR_CYCCNTENA            (1 <<  0)
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
//unsigned char  WSD_MSGBuff[];
const unsigned char  DataStr[]=__DATE__; //�����������
const unsigned char  TimeStr[]=__TIME__; //�������ʱ��
uint32_t ChipUniqueID[3];  //оƬ96λΨһID
uint16_t STM32_FLASH_SIZE; //оƬFlash��Ϣ
static const uint8_t table_crc_hi[] = {
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
        0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
        0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
        0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
};
/* Table of CRC values for low-order byte */
static const uint8_t table_crc_lo[] = {
        0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
        0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
        0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
        0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
        0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
        0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
        0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
        0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
        0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
        0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
        0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
        0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
        0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
        0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
        0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
        0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
        0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
        0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
        0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
        0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
        0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
        0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
        0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
        0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
        0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
        0x43, 0x83, 0x41, 0x81, 0x80, 0x40
};

/* Private function prototypes--------------------------*/
/* Private functions -----------------------------------*/
/**********************************
*	�� �� ��: bsp_InitDWT
*	����˵��: ��ʼ��DWT. �ú����� bsp_Init() ���á�
*	��    ��: ��
*	�� �� ֵ: ��
***********************************/
void BSP_InitDWT(void)
{
	DEM_CR         |= (unsigned int)DEM_CR_TRCENA;   /* Enable Cortex-M4's DWT CYCCNT reg.  */
	DWT_CYCCNT      = (unsigned int)0u;
	DWT_CR         |= (unsigned int)DWT_CR_CYCCNTENA;
}

/* Private function prototypes -------------------------*/
//��ʼ���ӳٺ���
//��ʹ��ucos��ʱ��,�˺������ʼ��ucos��ʱ�ӽ���
//SYSTICK��ʱ�ӹ̶�ΪHCLKʱ�ӵ�1/8
//SYSCLK:ϵͳʱ��

void Delay_Init(u8 SYSCLK)
{
	fac_ms = fac_ms;
 	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us=SYSCLK/8;		//�����Ƿ�ʹ��ucos,fac_us����Ҫʹ��
	fac_ms=(u16)fac_us*1000;//��ucos��,����ÿ��ms��Ҫ��systickʱ����   
}

//void Delay_Init(void)
//{
//// 	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
////	fac_us=SYSCLK/8;		//�����Ƿ�ʹ��ucos,fac_us����Ҫʹ��
////	fac_ms=(u16)fac_us*1000;//��ucos��,����ÿ��ms��Ҫ��systickʱ����   
//	u32 reload;
//	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);//ѡ���ⲿʱ��  HCLK
//	fac_us=SystemCoreClock/1000000;				//�����Ƿ�ʹ��OS,fac_us����Ҫʹ��
//	reload=SystemCoreClock/1000000;				//ÿ���ӵļ������� ��λΪM  
//	reload*=1000000/configTICK_RATE_HZ;			//����configTICK_RATE_HZ�趨���ʱ��
//												//reloadΪ24λ�Ĵ���,���ֵ:16777216,��72M��,Լ��0.233s����	
//	fac_ms=1000/configTICK_RATE_HZ;				//����OS������ʱ�����ٵ�λ	   

//	SysTick->CTRL|=SysTick_CTRL_TICKINT_Msk;   	//����SYSTICK�ж�
//	SysTick->LOAD=reload; 						//ÿ1/configTICK_RATE_HZ���ж�һ��	
//	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;   	//����SYSTICK    
//}	
//��ʱnus
//nusΪҪ��ʱ��us��.	
//ע��:nus��ֵ,��Ҫ����798915us
void Delay_us(u32 nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us; //ʱ�����	  		 
	SysTick->VAL=0x00;        //��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //��ʼ���� 
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����	 
}
//��ʱnms
//ע��nms�ķ�Χ
//SysTick->LOADΪ24λ�Ĵ���,����,�����ʱΪ:
//nms<=0xffffff*8*1000/SYSCLK
//SYSCLK��λΪHz,nms��λΪms
//��168M������,nms<=798ms 
//static void Delay_xms(u16 nms)
//{	 		  	  
//	u32 temp;		   
//	SysTick->LOAD=(u32)nms*fac_ms;//ʱ�����(SysTick->LOADΪ24bit)
//	SysTick->VAL =0x00;           //��ռ�����
//	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //��ʼ����  
//	do
//	{
//		temp=SysTick->CTRL;
//	}
//	while((temp&0x01)&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
//	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //�رռ�����
//	SysTick->VAL =0X00;       //��ռ�����	  	    
//}
//��ʱnms 
//nms:0~65535
void Delay_ms(u16 nms)
{	 	 
	vTaskDelay(nms);
} 

/*********************�����ʱ*******************/
//�����ʱ������us����
void Soft_delay_us(u16 time)
{    
   u32 i;  
   while(time--)
   {
      i=8;  //�Լ�����  ����ʱ�䣺20141116
      while(i--){};
        __nop();
        __nop();
        __nop();
        __nop();
   }
}

//�����ʱ������ms����
void Soft_delay_ms(u16 time)
{    
	vTaskDelay(time);
}


/*
* ��������Get_ChipID
 * ����  ����ȡоƬID
 * ����  ����
 * ���  ����
 * ˵��  ��96λ��ID��stm32Ψһ��ݱ�ʶ��������8bit��16bit��32bit��ȡ
           �ṩ�˴�˺�С�����ֱ�ʾ����
*/
void Get_ChipID(void)
{
#if 1    
     //��ַ��С����,�ȷŵ��ֽڣ��ٷŸ��ֽڣ�С��ģʽ
     //��ַ��С����,�ȷŸ��ֽڣ��ٷŵ��ֽڣ����ģʽ
 ChipUniqueID[2] = *(__IO u32*)(0X1FFFF7E8);  // ���ֽ�
 ChipUniqueID[1] = *(__IO u32 *)(0X1FFFF7EC); // 
 ChipUniqueID[0] = *(__IO u32 *)(0X1FFFF7F0); // ���ֽ�
// printf("######## оƬ��ΨһIDΪ: X-X-X  rn",ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);
          //����������32λ
#else   //�����˴�С��ģʽ����ISP���������һ��
    u8 temp[12];   
    u32 temp0,temp1,temp2;
    temp0=*(__IO u32*)(0x1FFFF7E8);    //��ƷΨһ��ݱ�ʶ�Ĵ�����96λ��
    temp1=*(__IO u32*)(0x1FFFF7EC);
    temp2=*(__IO u32*)(0x1FFFF7F0);
    temp[0] = (u8)(temp0 & 0x000000FF);
    temp[1] = (u8)((temp0 & 0x0000FF00)>>8);
    temp[2] = (u8)((temp0 & 0x00FF0000)>>16);
    temp[3] = (u8)((temp0 & 0xFF000000)>>24);
    temp[4] = (u8)(temp1 & 0x000000FF);
    temp[5] = (u8)((temp1 & 0x0000FF00)>>8);
    temp[6] = (u8)((temp1 & 0x00FF0000)>>16);
    temp[7] = (u8)((temp1 & 0xFF000000)>>24);
    temp[8] = (u8)(temp2 & 0x000000FF);
    temp[9] = (u8)((temp2 & 0x0000FF00)>>8);
    temp[10] = (u8)((temp2 & 0x00FF0000)>>16);
    temp[11] = (u8)((temp2 & 0xFF000000)>>24);
//    printf("######## STM32оƬIDΪ: %.2X%.2X%.2X%.2X-%.2X%.2X%.2X%.2X-%.2X%.2X%.2X%.2X rn",
//  temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp [11]); //���ڴ�ӡ��оƬID
#endif
}
/*
 * ��������Get_ChipInfo(void)
 * ����  ����ȡоƬFlash ��С
 * ����  ����
 * ���  ����
 * ˵��  ��
*/
void Get_ChipInfo(void)
{
   ChipUniqueID[0] = *(__IO u32 *)(0X1FFF7A10); // ���ֽ�
   ChipUniqueID[1] = *(__IO u32 *)(0X1FFF7A14); //
   ChipUniqueID[2] = *(__IO u32 *)(0X1FFF7A18); // ���ֽ�
   STM32_FLASH_SIZE= *(u16*)(0x1FFFF7E0);    //���������Ĵ���  
//   printf("rn########### оƬ��ΨһIDΪ: %X-%X-%X n",
//           ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);  
//   printf("rn########### оƬflash������Ϊ: %dK n", STM32_FLASH_SIZE);
//   printf("rn########### ��¼����: "__DATE__" - "__TIME__"n");
      //���ʹ�ù̼���汾�� 
}

/* Fast CRC */
//���ص�CRCУ����,�ߵ�λδ����
uint16_t getCRC16(uint8_t *buffer, uint16_t buffer_length)
{
    uint8_t crc_hi = 0xFF; /* high CRC byte initialized */
    uint8_t crc_lo = 0xFF; /* low CRC byte initialized */
    unsigned int i; /* will index into CRC lookup */

    /* pass through message buffer */
    while (buffer_length--)
    {
        i = crc_hi ^ *buffer++; /* calculate the CRC  */
        crc_hi = crc_lo ^ table_crc_hi[i];
        crc_lo = table_crc_lo[i];
    }
    return (crc_hi << 8 | crc_lo);
}


/******************************************************************************
* Function Name  :
* Description    :   
* Input          : msg:���ݻ�����
				   msg_length:���ݳ���
				   overturn=0��ʾCRCУ����ֽ��ȷ��ͣ����ֽں���
				   overturn=1��ʾCRCУ����ֽ��ȷ��ͣ����ֽں���
* Return         : ����1��ʾУ����ȷ������0��ʾУ�鲻��ȷ
* Note           : 
*******************************************************************************/
uint8_t checkCRC16(uint8_t *msg, const uint16_t msg_length, uint8_t overturn)
{
    uint16_t  crc_calc;
    uint16_t crc_received;

    if(msg_length < 3)
    {
        return 1;
    }

    crc_calc = getCRC16(msg, msg_length - 2);
    if(overturn)
    {
        crc_received = (msg[msg_length - 1] << 8) | msg[msg_length - 2]; //��������ʱ,���յ����ֽ�,���Ǹ��ֽ�.
    }else
    {
        crc_received = (msg[msg_length - 2] << 8) | msg[msg_length - 1];
    }

    /* Check CRC of msg */
    if (crc_calc == crc_received)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/******************************************************************************
* Function Name  :
* Description    :   
* Input          : abyte:8λ����
* Return         : 
* Note           : 
*******************************************************************************/
static uint8_t Caculate_CRC8_Byte(uint8_t abyte)
{
   uint8_t i,crc_1byte;

	crc_1byte=0;                //�趨crc_1byte��ֵΪ0
	for(i = 0; i < 8; i++)
	{
		if(((crc_1byte^abyte)&0x01))
		{
			crc_1byte^=0x18;
			crc_1byte>>=1;
			crc_1byte|=0x80;
		}
		else
		{
			crc_1byte>>=1;
		}
		abyte>>=1;
	}
	return crc_1byte;
}

/******************************************************************************
* Function Name  :
* Description    :   
* Input          : pbuf:���ݻ�����
				   len :��ҪУ�����ݵĳ���
* Return         : 
* Note           : 
*******************************************************************************/
uint8_t getCRC8(uint8_t *pbuf,uint8_t len)
{
	uint8_t crccheck=0;

    while(len--) 
    {
        crccheck = Caculate_CRC8_Byte(crccheck^*pbuf++);
    }	
	return crccheck;
}

/******************************************************************************
* Function Name  :
* Description    :   
* Input          : pbuf:���ݻ�����
				   len :��ҪУ�����ݵĳ���(����CRC8У��ֵ)
* Return         : ����1��ʾУ����ȷ������0��ʾУ�鲻��ȷ
* Note           : 
*******************************************************************************/
uint8_t checkCRC8(uint8_t *pbuf,uint8_t len)
{
    uint8_t crc=0,i;

    for(i=0;i<len;i++)
    {
        crc = Caculate_CRC8_Byte(crc^*pbuf++);
    }
    if(crc == 0)
    {
        return 1;
    }else 
    {   
        return 0;
    }
}

/*** һ�º�����Http Server��ʹ��**************/
/**
*@brief	 	���ַ���ת��Ϊʮ������
*@param		c:Ҫת��ʮ��������
*@return	����һ���ַ�������
*/
char C2D(unsigned char c	)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return 10 + c -'a';
	if (c >= 'A' && c <= 'F')
		return 10 + c -'A';

	return (char)c;
}
///**
//*@brief	 	��ʮ������ת��Ϊ�ַ���
//*@param		c:Ҫת��ʮ��������
//*@return	����һ���ַ�������
//*/
//char D2C(unsigned char c)
//{
//	if (c >= 0 && c <= 9)
//		return c + '0';
////	if (c >= 'a' && c <= 'f')
////		return 10 + c -'a';
//	if (c >= 10 && c <= 15)
//		return c +'A'-10;

//	return (char)c;
//}
/**
*@brief	 	��16������ת��ΪBCD
*@param		c:Ҫת��16��������
*@return	����һ��BCD������
*/
char CharToBCD(unsigned char c	)
{
	return (char)((c/10<<4)+(c%10));
}
/**
*@brief	 	��BCD����ת��Ϊ16��������
*@param		c:Ҫת��BCD����
*@return	����һ��16��������
*/
char BCDToChar(unsigned char c	)
{
	return (char)((c>>4)&0X0F)*10+(c&0x0F);
}
/**
*@brief	 	�ַ�������
*@param		srcĿ���ַ��� s1 s2�����ַ���
*@return	��
*/
void mid(char* src, char* s1, char* s2, char* sub)
{
	char* sub1;
	char* sub2;
	unsigned short n;

  sub1=strstr(src,s1);
  sub1+=strlen(s1);
  sub2=strstr(sub1,s2);
  n=sub2-sub1;
  strncpy(sub,sub1,n);
  sub[n]=0;
}

/**
*@brief	 	�ַ�תת��Ϊ8λ���ͺ���
*@param		str:Ҫת���ַ����� base:
*@return	num:����ת�����������
*/
uint16_t atoi16(char* str,uint16_t base	)
{
  unsigned int num = 0;
  while (*str !=0)
          num = num * base + C2D(*str++);
  return num;
}

/**
*@brief	 	ip�����ַת��
*@param		adr����ַ ip��ip
*@return	��
*/
void inet_addr_(unsigned char* addr,unsigned char *ip)
{
	int i;
	char taddr[30];
	char * nexttok;
	char num;
	strcpy(taddr,(char *)addr);
	
	nexttok = taddr;
	for(i = 0; i < 4 ; i++)
	{
		nexttok = strtok(nexttok,".");
		if(nexttok[0] == '0' && nexttok[1] == 'x') num = atoi16(nexttok+2,0x10);
		else num = atoi16(nexttok,10);
		
		ip[i] = num;
		nexttok = NULL;
	}
}	
/**
*@brief	 	���µ��ַ�ȥ�滻�ַ�����������ַ�
*@param		str:�滻���ַ�����oldchar:������ַ���newchar���µ��ַ�	
*@return	��
*/
void replacetochar(char * str,	char oldchar,char newchar	)
{
  int x;
  for (x = 0; str[x]; x++) 
    if (str[x] == oldchar) str[x] = newchar;	
}


/**һ�º�����DNS��ʹ��*********************************************/
/**
*@brief	 	16λ�ַ���8λ��8λת��
*@param		i:Ҫת��������
*@return	ת���������
*/
uint16_t swaps(uint16_t i)
{
  uint16_t ret=0;
  ret = (i & 0xFF) << 8;
  ret |= ((i >> 8)& 0xFF);
  return ret;	
}
/**
*@brief		��һ�� ����ģʽ��unsigned short������ת�������ģʽ��TCP/IP �����ֽڸ�ʽ������.
*@param		Ҫת��������
*@return 	���ģʽ������
*/ 
uint16_t htons( uint16_t hostshort)	/**< A 16-bit number in host byte order.  */
{
#if ( SYSTEM_ENDIAN == _ENDIAN_LITTLE_ )
	return swaps(hostshort);
#else
	return hostshort;
#endif		
}

/**
*@brief		��һ�����ģʽ��TCP/IP �����ֽڸ�ʽ������ת��������ģʽ��unsigned short������
*@param		Ҫת��������
*@return 	unsigned shortģʽ������
*/ 
unsigned long ntohs(unsigned short netshort)	/**< netshort - network odering 16bit value */	
{
#if ( SYSTEM_ENDIAN == _ENDIAN_LITTLE_ )	
	return htons(netshort);
#else
	return netshort;
#endif		
}

//���У��
uint8_t XORValid(uint8_t *buffer,uint16_t Len)
{
    uint8_t checksum = 0;
	uint8_t i;
    for (i = 0;  i<Len;  i++)
    {
        checksum = checksum ^ buffer[i]; //���������ȡֵ
	}
	return(checksum);
}

//��������Ƚ�
uint8_t StrCmp(uint8_t *str1,uint8_t *str2,uint16_t len)
{
    for(uint16_t i=0;i<len;i++)
	{
	   if(*(str1+i) == *(str2+i));
	   else return FALSE;
	}
	return TRUE;
}





/**
  * @brief  get the cpu unique ID
  * @note   
  * @retval None
  */

bool getCpuId(uint32_t *mac_0, uint32_t *mac_1, uint32_t *mac_2)
{
	*mac_0 = *(uint32_t*)(0x1FFFF7E8);
	*mac_1 = *(uint32_t*)(0x1FFFF7EC);
	*mac_2 = *(uint32_t*)(0x1FFFF7F0);
	
	if ((*mac_0 != 0) || (*mac_1 != 0) || (*mac_2 != 0)) {
		return true;
		
	} else {
		return false;
	}
}



/**
  * @brief  get the dev mac addr 
  * @note   
  * @retval None
  */
bool getDevMac(uint8_t *mac0, uint8_t *mac1, uint8_t *mac2, uint8_t *mac3, uint8_t *mac4, uint8_t *mac5)
{
	uint32_t mac_0;
	uint32_t mac_1;
	uint32_t mac_2;

	if (getCpuId(&mac_0, &mac_1, &mac_2)) {
		*mac0	= 0x4c;
		*mac1	= (uint8_t)(mac_0 >> 16);
		*mac2	= (uint8_t)(mac_2 >> 24);
		*mac3	= (uint8_t)(mac_2 >> 16);
		*mac4	= (uint8_t)(mac_2 >> 8);
		*mac5	= (uint8_t)(mac_2);
		return true;
	} else {
		return false;
	}		
}

/**
  * @brief  get the ask for id period of radio by crc the cpuid 
  * @note   if get cpu id ok, just use the last 4 bits of 
			crc result as period
  * @note   if get cpu id failed, use 1 as the default period
  * @retval None
  */
uint8_t getAskForIdPeriod(void)
{
	uint16_t value;
	uint32_t mac[3];
	
	if (getCpuId(&mac[0], &mac[1], &mac[2])) {
		value = (crc16((uint8_t *)mac, sizeof(mac)) & (0x001F));
		
		if (value == 0) {
			value = 100;
			
		} else {
			value = value*25;
		} 			
		
	} else {
		
		value = 500;
	}
	
	return value;
}


/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIYǶ��ʽ���������� ��END OF FILE ��************************/


