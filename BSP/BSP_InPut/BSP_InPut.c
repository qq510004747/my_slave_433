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
   V1.0.1       :  2014-09-13        
*******************************************************************************/
/* Includes---------------------------------------------*/
#include  "BSP_InPut.h"
#include  "main.h"
//#include "semphr.h"  
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/                  
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/		
static void In_Put_Init(void);
/* Private functions -----------------------------------*/
/**********************************************
*	函 数 名: static void In_Put_Init(void)
*	形    参：
*	返 回 值: 
*	功能说明: LED端口初始化				
**********************************************/ 
#define SWD_GPIO 			GPIOA

#define Swd1_Pin 			GPIO_Pin_7
#define Swd2_Pin 			GPIO_Pin_6
#define Swd3_Pin 			GPIO_Pin_5
#define Swd4_Pin 			GPIO_Pin_4

#define SWD1_EXTI_IRQn		EXTI9_5_IRQn  
#define SWD2_EXTI_IRQn		EXTI9_5_IRQn  
#define SWD3_EXTI_IRQn		EXTI9_5_IRQn  
#define SWD4_EXTI_IRQn		EXTI4_IRQn  

#define SWD1_EXTI_Line		EXTI_Line7
#define SWD2_EXTI_Line		EXTI_Line6
#define SWD3_EXTI_Line		EXTI_Line5
#define SWD4_EXTI_Line		EXTI_Line4

#define SWD1_GPIO_PinSource		GPIO_PinSource7
#define SWD2_GPIO_PinSource		GPIO_PinSource6
#define SWD3_GPIO_PinSource		GPIO_PinSource5
#define SWD4_GPIO_PinSource		GPIO_PinSource4

//#define Get_SWD1_GPIO_In		PAin(7)
//#define Get_SWD2_GPIO_In		PAin(6)
//#define Get_SWD3_GPIO_In		PAin(5)
//#define Get_SWD4_GPIO_In		PAin(4)

uint8_t SWD_1 = 0;
uint8_t SWD_2 = 0;
uint8_t SWD_3 = 0;
uint8_t SWD_4 = 0;

void BSP_InPut_Init(void)
{
	In_Put_Init();		 
}
/**********************************************
*	函 数 名: static void Key_Init(void)
*	形    参：
*	返 回 值: 
*	功能说明: 按键端口初始化				
**********************************************/ 
static void In_Put_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE); 

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE); //JATG

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin =  Swd1_Pin | Swd2_Pin | Swd3_Pin | Swd4_Pin ;
	GPIO_Init(SWD_GPIO, &GPIO_InitStructure); 
 
	GPIO_SetBits(SWD_GPIO,Swd1_Pin | Swd2_Pin | Swd3_Pin | Swd4_Pin);
}
static void NVIC_LED(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 	 
	/*******************3????D??,?D??D栩a??a??***************************/
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	NVIC_InitStructure.NVIC_IRQChannel = SWD1_EXTI_IRQn ; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = SWD2_EXTI_IRQn ; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = SWD3_EXTI_IRQn ; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = SWD4_EXTI_IRQn ; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
 
static void EXTI_Configuration_LED(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, SWD1_GPIO_PinSource);
	EXTI_InitStructure.EXTI_Line=SWD1_EXTI_Line;                     
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;           
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;        
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;                      
	EXTI_Init(&EXTI_InitStructure);
	EXTI_ClearITPendingBit(SWD1_EXTI_Line);	

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, SWD2_GPIO_PinSource);
	EXTI_InitStructure.EXTI_Line=SWD2_EXTI_Line;                     
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;           
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;        
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;                      
	EXTI_Init(&EXTI_InitStructure);
	EXTI_ClearITPendingBit(SWD2_EXTI_Line);	


	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, SWD3_GPIO_PinSource);
	EXTI_InitStructure.EXTI_Line=SWD3_EXTI_Line;                     
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;           
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;        
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;                      
	EXTI_Init(&EXTI_InitStructure);
	EXTI_ClearITPendingBit(SWD3_EXTI_Line);	

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, SWD4_GPIO_PinSource);
	EXTI_InitStructure.EXTI_Line=SWD4_EXTI_Line;                     
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;           
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;        
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;                      
	EXTI_Init(&EXTI_InitStructure);
	EXTI_ClearITPendingBit(SWD4_EXTI_Line);	
}
void EXTI_Initialization(void)
{
	NVIC_LED();
	EXTI_Configuration_LED();
 }
/*PA0-3中断处理*/
void EXTI9_5_IRQHandler(void)	 				//???1
{
	if((EXTI_GetITStatus(SWD1_EXTI_Line)!=RESET)||(Get_SWD1_GPIO_In == 0))
	{ //swd4
//		  Delay_ms(3);
		  if(Get_SWD1_GPIO_In == 0) 
		  {
			current_node.trigger_reserve1 = 1;
			SWD_1 = 1;
		  }
		EXTI_ClearITPendingBit(SWD1_EXTI_Line);
	}
	if((EXTI_GetITStatus(SWD2_EXTI_Line)!=RESET)||(Get_SWD2_GPIO_In == 0))
	{ //swd-1
//		Delay_ms(3);
		if(Get_SWD2_GPIO_In == 0)
		{
			current_node.trigger_microwave3 = 1;
			SWD_2 = 1;
		}
		EXTI_ClearITPendingBit(SWD2_EXTI_Line);
	}
	if((EXTI_GetITStatus(SWD3_EXTI_Line)!=RESET)||(Get_SWD3_GPIO_In == 0))
	{ //swd-1	
//	  Delay_ms(3);
	  if(Get_SWD3_GPIO_In == 0)
	  {
		current_node.trigger_video2 = 1;
		SWD_3 = 1;
	  }
		EXTI_ClearITPendingBit(SWD3_EXTI_Line);
	}
}

void EXTI4_IRQHandler(void)					//???1
{	
	if((EXTI_GetITStatus(SWD4_EXTI_Line)!=RESET)||(Get_SWD4_GPIO_In == 0))
	{ //swd-1
//	  Delay_ms(3);
	  if(Get_SWD4_GPIO_In == 0)
	  {
		current_node.trigger_vehicle1 = 1;
		SWD_4 = 1;
	  }
		EXTI_ClearITPendingBit(SWD4_EXTI_Line);
	}
}

void In_Put_Handle_fun()
{

	if((EXTI_GetITStatus(SWD1_EXTI_Line)!=RESET)||(Get_SWD1_GPIO_In == 0))
	{ //swd4
//		  Delay_ms(3);
		  if(Get_SWD1_GPIO_In == 0) 
		  {
			current_node.trigger_reserve1 = 1;
			SWD_1 = 1;
		  }
		EXTI_ClearITPendingBit(SWD1_EXTI_Line);
	}
	if((EXTI_GetITStatus(SWD2_EXTI_Line)!=RESET)||(Get_SWD2_GPIO_In == 0))
	{ //swd-1
//		Delay_ms(3);
		if(Get_SWD2_GPIO_In == 0)
		{
			current_node.trigger_microwave3 = 1;
			SWD_2 = 1;
		}
		EXTI_ClearITPendingBit(SWD2_EXTI_Line);
	}
	if((EXTI_GetITStatus(SWD3_EXTI_Line)!=RESET)||(Get_SWD3_GPIO_In == 0))
	{ //swd-1	
//	  Delay_ms(3);
	  if(Get_SWD3_GPIO_In == 0)
	  {
		current_node.trigger_video2 = 1;
		SWD_3 = 1;
	  }
		EXTI_ClearITPendingBit(SWD3_EXTI_Line);
	}


	
	if((EXTI_GetITStatus(SWD4_EXTI_Line)!=RESET)||(Get_SWD4_GPIO_In == 0))
	{ //swd-1
//	  Delay_ms(3);
	  if(Get_SWD4_GPIO_In == 0)
	  {
		current_node.trigger_vehicle1 = 1;
		SWD_4 = 1;
	  }
		EXTI_ClearITPendingBit(SWD4_EXTI_Line);
	}

}
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/




