/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：BSP_InPut.h
 * 环境	 	  : MDK4.73-固件库V3.5版本
 * 实验平台 ：STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：   
 * 修改时间 ：2013-12-20
 * 硬件连接 : STM32F10x-STM32开发板
 * 描述     : 系统基本输入配置文件
 * 修改记录     :
 * 版本号       :  日期          作者       说明 
   V1.0.1       :  2014-09-13    马加强     
*******************************************************************************/
/* Includes---------------------------------------------*/
#include "main.h"

//#include "semphr.h"  
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/                  
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/		
static void Switch_Init(void);
/* Private functions -----------------------------------*/
/**********************************************
*	函 数 名: static void In_Put_Init(void)
*	形    参：
*	返 回 值: 
*	功能说明: LED端口初始化				
**********************************************/ 
u8 Switch_Status = 0x00;
u8 Location_Flag = 0;
//#define ADDR_7_Pin 		GPIO_Pin_0
//#define ADDR_7_GPIO 	GPIOA
//#define ADDR_6_Pin 		GPIO_Pin_4
//#define ADDR_6_GPIO 	GPIOC
//#define ADDR_5_Pin 		GPIO_Pin_5
//#define ADDR_5_GPIO 	GPIOC
//#define ADDR_4_Pin 		GPIO_Pin_0
//#define ADDR_4_GPIO 	GPIOB
//#define ADDR_3_Pin 		GPIO_Pin_1
//#define ADDR_3_GPIO 	GPIOB
//#define ADDR_2_Pin 		GPIO_Pin_10
//#define ADDR_2_GPIO 	GPIOB
//#define ADDR_1_Pin 		GPIO_Pin_11
//#define ADDR_1_GPIO 	GPIOB
//#define ADDR_0_Pin 		GPIO_Pin_12
//#define ADDR_0_GPIO 	GPIOB 

#define ADDR_7_Pin 		GPIO_Pin_0
#define ADDR_7_GPIO 	GPIOA

#define ADDR_6_Pin 		GPIO_Pin_4
#define ADDR_6_GPIO 	GPIOC

#define ADDR_5_Pin 		GPIO_Pin_5
#define ADDR_5_GPIO 	GPIOC

#define ADDR_4_Pin 		GPIO_Pin_0
#define ADDR_4_GPIO 	GPIOB

#define ADDR_3_Pin 		GPIO_Pin_1
#define ADDR_3_GPIO 	GPIOB

#define ADDR_2_Pin 		GPIO_Pin_10
#define ADDR_2_GPIO 	GPIOB

#define ADDR_1_Pin 		GPIO_Pin_11
#define ADDR_1_GPIO 	GPIOB

#define ADDR_0_Pin 		GPIO_Pin_12
#define ADDR_0_GPIO 	GPIOB 

#define ADDR_1_1_Pin 	GPIO_Pin_6
#define ADDR_1_1_GPIO 	GPIOB 
#define ADDR_1_2_Pin 	GPIO_Pin_7
#define ADDR_1_2_GPIO 	GPIOB 
#define ADDR_1_3_Pin 	GPIO_Pin_8
#define ADDR_1_3_GPIO 	GPIOB
#define ADDR_1_4_Pin 	GPIO_Pin_9
#define ADDR_1_4_GPIO 	GPIOB 

#define Switch0 		PBin(12)
#define Switch1 		PBin(11)
#define Switch2 		PBin(10)
#define Switch3 		PBin(1)
#define Switch4 		PBin(0)
#define Switch5 		PCin(5)
#define Switch6 		PCin(4)
#define Switch7 		PAin(0)

u8 Get_Switch_Status(void)
{
	
	Switch_Status = 0;
	Switch_Status |= (Switch0<<0);
	Switch_Status |= (Switch1<<1);
	Switch_Status |= (Switch2<<2);
	Switch_Status |= (Switch3<<3);
	Switch_Status |= (Switch4<<4);
	Switch_Status |= (Switch5<<5);
	Switch_Status |= (Switch6<<6);
	Switch_Status |= (Switch7<<7);
	return  Switch_Status;
}
void Get_Switch_Message(u8 switch_flag)
{
	u8 LoRa_Frequency_Flag = 0;
	switch((switch_flag & (1<<0))) 
	{
		case 1:
		{
			#define MASTER_MODE
		}
		case 0:
		{
			#define  SLAVE_MODE
		}
	}
	if(Switch4 == 0)
	{
		current_node.location2  = East;
	}
	else if(Switch5 == 0)
	{
		current_node.location2  = South;
	}
	else if(Switch6 == 0)
	{
		current_node.location2  = West;
	}
	else if(Switch7 == 0)
	{
		current_node.location2  = North;
	}
	else
	{
		current_node.location2  = East;
	}
//	LoRa_Frequency_Flag = ((switch_flag>>4)&(~(1<<4)));
//	switch(LoRa_Frequency_Flag) 
//	{
//		case 0:
//		{
//			LoRa_Frequency_Change =  426000000;
//			break;
//		}
//		case 1:
//		{
//			LoRa_Frequency_Change =  428000000;
//			break;
//		}
//		case 2:
//		{
//			LoRa_Frequency_Change =  430000000;
//			break;
//		}
//		case 3:
//		{
//			LoRa_Frequency_Change =  432000000;
//			break;
//		}
//		case 4:
//		{
//			LoRa_Frequency_Change =  434000000;
//			break;
//		}
//		case 5:
//		{
//			LoRa_Frequency_Change =  436000000;
//			break;
//		}
//		case 6:
//		{
//			LoRa_Frequency_Change =  438000000;
//			break;
//		}
//		case 7:
//		{
//			LoRa_Frequency_Change =  440000000;
//			break;
//		}
//		default:
//			break;
//	}
//	Location_Flag = ((switch_flag>>2)&((~(1<<0))&(~(1<<1))));
//	switch(Location_Flag)
//	{
//		case 0:
//		{
//			current_node.location2  = East;
//			break;
//		}
//		case 1:
//		{
//			current_node.location2  = South;
//			break;
//		}
//		case 2:
//		{
//			current_node.location2  = West;
//			break;
//		}
//		case 3:
//		{
//			current_node.location2  = North;
//			break;
//		}
//		default:
//			break;
//	}
}
void BSP_Switch_Init(void)
{
	Switch_Init();		 
}
/**********************************************
*	函 数 名: static void Key_Init(void)
*	形    参：
*	返 回 值: 
*	功能说明: 按键端口初始化				
**********************************************/ 
static void Switch_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE); //JATG

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_InitStructure.GPIO_Pin =  ADDR_7_Pin ;
	GPIO_Init(ADDR_7_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  ADDR_6_Pin ;
	GPIO_Init(ADDR_6_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  ADDR_5_Pin ;
	GPIO_Init(ADDR_5_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  ADDR_4_Pin ;
	GPIO_Init(ADDR_4_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  ADDR_3_Pin ;
	GPIO_Init(ADDR_3_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  ADDR_2_Pin ;
	GPIO_Init(ADDR_2_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  ADDR_1_Pin ;
	GPIO_Init(ADDR_1_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  ADDR_0_Pin ;
	GPIO_Init(ADDR_0_GPIO, &GPIO_InitStructure);
//******************************************************************
	GPIO_InitStructure.GPIO_Pin =  ADDR_1_1_Pin ;
	GPIO_Init(ADDR_1_1_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  ADDR_1_2_Pin ;
	GPIO_Init(ADDR_1_2_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  ADDR_1_3_Pin ;
	GPIO_Init(ADDR_1_3_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  ADDR_1_4_Pin ;
	GPIO_Init(ADDR_1_4_GPIO, &GPIO_InitStructure);
//******************************************************************
	GPIO_SetBits(ADDR_1_1_GPIO, ADDR_1_1_Pin);
	GPIO_SetBits(ADDR_1_2_GPIO, ADDR_1_2_Pin);
	GPIO_SetBits(ADDR_1_3_GPIO, ADDR_1_3_Pin);
	GPIO_SetBits(ADDR_1_4_GPIO, ADDR_1_4_Pin);
	
	GPIO_SetBits(ADDR_0_GPIO, ADDR_0_Pin);
	GPIO_SetBits(ADDR_1_GPIO, ADDR_1_Pin);
	GPIO_SetBits(ADDR_2_GPIO, ADDR_2_Pin);
	GPIO_SetBits(ADDR_3_GPIO, ADDR_3_Pin);
	GPIO_SetBits(ADDR_4_GPIO, ADDR_4_Pin);
	GPIO_SetBits(ADDR_5_GPIO, ADDR_5_Pin);
	GPIO_SetBits(ADDR_6_GPIO, ADDR_6_Pin);
	GPIO_SetBits(ADDR_7_GPIO, ADDR_7_Pin);
}

//#define SX1278_RX
////#define SX1278_TX
//#define BUFFER_SIZE     30                          // Define the payload size here

//#define MSG_RESERVE 						0XFF //
//#define MSG_MASTER_ADDR 					0XFF //
//#define MSG_SLAVE_ADDR1 					0XFF //
//#define MSG_SLAVE_ADDR2 					0XFF //
//#define MSG_LOCATION1						0XFF //
//#define MSG_LOCATION2 					0XFF //

/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/


