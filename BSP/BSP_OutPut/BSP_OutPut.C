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
#include  "BSP_OutPut.h"

#define LED_CHANNEL	2

#define LED_1_Pin 		GPIO_Pin_13
#define LED_1_GPIO 		GPIOC

#define LED_2_Pin 		GPIO_Pin_14
#define LED_2_GPIO 		GPIOC

#define LED_3_Pin 		GPIO_Pin_2
#define LED_3_GPIO 		GPIOC

#define LED_4_Pin 		GPIO_Pin_1
#define LED_4_GPIO 		GPIOC

#define LED_5_Pin 		GPIO_Pin_0
#define LED_5_GPIO 		GPIOC


#define KM_1_Pin 		GPIO_Pin_5
#define KM_1_GPIO 		GPIOB

#define KM_2_Pin 		GPIO_Pin_4
#define KM_2_GPIO 		GPIOB

#define KM_3_Pin 		GPIO_Pin_3
#define KM_3_GPIO 		GPIOB

#define KM_4_Pin 		GPIO_Pin_2
#define KM_4_GPIO 		GPIOD

#define KM_5_Pin 		GPIO_Pin_12
#define KM_5_GPIO 		GPIOC

#define KM_6_Pin 		GPIO_Pin_11
#define KM_6_GPIO 		GPIOC

#define KM_7_Pin 		GPIO_Pin_10
#define KM_7_GPIO 		GPIOC

#define KM_8_Pin 		GPIO_Pin_15
#define KM_8_GPIO 		GPIOA



uint8_t ch1_flag = 0;
uint8_t ch2_flag = 0;
uint8_t ch3_flag = 0;
uint8_t ch4_flag = 0;
uint8_t ch5_flag = 0;
uint8_t ch6_flag = 0;
uint8_t ch7_flag = 0;
uint8_t ch8_flag = 0;

uint16_t ch1_time = 0;
uint16_t ch2_time = 0;
uint16_t ch3_time = 0;
uint16_t ch4_time = 0;
uint16_t ch5_time = 0;
uint16_t ch6_time = 0;
uint16_t ch7_time = 0;
uint16_t ch8_time = 0;

uint16_t km1_time = 0;
uint16_t km2_time = 0;
uint16_t km3_time = 0;
uint16_t km4_time = 0;
uint16_t km5_time = 0;
uint16_t km6_time = 0;
uint16_t km7_time = 0;
uint16_t km8_time = 0;

uint16_t east1_control_t_trigger_time = 0;
uint16_t south2_control_t_trigger_time = 0;
uint16_t west3_control_t_trigger_time = 0;
uint16_t north4_control_t_trigger_time = 0;
/* Private defines--------------------------------------*/
/* Private function prototypes--------------------------*/
static void Out_Put_Init(void);
//static void Beep_Init(void);
/* Private functions -----------------------------------*/
//-----------------
/**********************************************
*	函 数 名: BSP_Output_Init(void)
*	形    参：
*	返 回 值: 
*	功能说明: 系统基本输出配置				
**********************************************/ 
void BSP_OutPut_Init(void)
{
     Out_Put_Init();
//	   Beep_Init();
}


/**********************************************
*	函 数 名: static void Out_Put_Init(void)
*	形    参：
*	返 回 值: 
*	功能说明: LED端口初始化				
**********************************************/ 
static void Out_Put_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//要先开时钟，再重映射；关闭jtag，保留swd。  
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD , ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOD,GPIO_Pin_2);
	
	
	GPIO_InitStructure.GPIO_Pin = LED_1_Pin ;
	GPIO_Init(LED_1_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = LED_2_Pin ;
	GPIO_Init(LED_2_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = LED_3_Pin ;
	GPIO_Init(LED_3_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = LED_4_Pin ;
	GPIO_Init(LED_4_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = LED_5_Pin ;
	GPIO_Init(LED_5_GPIO, &GPIO_InitStructure);
//*******************************************************************

	GPIO_InitStructure.GPIO_Pin = KM_1_Pin ;
	GPIO_Init(KM_1_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = KM_2_Pin ;
	GPIO_Init(KM_2_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = KM_3_Pin ;
	GPIO_Init(KM_3_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = KM_4_Pin ;
	GPIO_Init(KM_4_GPIO, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = KM_5_Pin ;
	GPIO_Init(KM_5_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = KM_6_Pin ;
	GPIO_Init(KM_6_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = KM_7_Pin ;
	GPIO_Init(KM_7_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = KM_8_Pin ;
	GPIO_Init(KM_8_GPIO, &GPIO_InitStructure);

	GPIO_SetBits(LED_1_GPIO, LED_1_Pin);
	GPIO_SetBits(LED_2_GPIO, LED_2_Pin); 
	GPIO_SetBits(LED_3_GPIO, LED_3_Pin);	
	GPIO_SetBits(LED_4_GPIO, LED_4_Pin);
	GPIO_SetBits(LED_5_GPIO, LED_5_Pin);
 
	GPIO_SetBits(KM_1_GPIO, KM_1_Pin);	
	GPIO_SetBits(KM_2_GPIO, KM_2_Pin);
	GPIO_SetBits(KM_3_GPIO, KM_3_Pin);
	GPIO_SetBits(KM_4_GPIO, KM_4_Pin);
	GPIO_SetBits(KM_5_GPIO, KM_5_Pin); 
	GPIO_SetBits(KM_6_GPIO, KM_6_Pin);	
	GPIO_SetBits(KM_7_GPIO, KM_7_Pin);
	GPIO_SetBits(KM_8_GPIO, KM_8_Pin);
}

//void ledOn(uint8_t chan) 
//{
//	switch(chan)
//	{
//	case LED_RUN:
//		GPIO_SetBits(LED1_GPIO_REG, LED1_GPIO_PIN);		
//		break;
//	
//	case LED_MESH:
//		GPIO_SetBits(LED2_GPIO_REG, LED2_GPIO_PIN);
//		break;	
//}

//}

//void ledOff(uint8_t chan) 
//{

//	switch(chan)
//	{
//	case LED_RUN:
//		GPIO_ResetBits(LED1_GPIO_REG, LED1_GPIO_PIN);		
//		break;
//	
//	case LED_MESH:
//		GPIO_ResetBits(LED2_GPIO_REG, LED2_GPIO_PIN);
//		break;	
//	

//	}
//}



//static uint8_t  sChFlashFsmSta[LED_CHANNEL]   = {2};             
//static uint8_t  sChFlashCnt[LED_CHANNEL]      = {0};
//static uint16_t sHwFlashOnTime[LED_CHANNEL]   = {0};
//static uint16_t sHwFlashOffTime[LED_CHANNEL]  = {0};




//void ledFlashInit(void)
//{

//	ledFlashSet(LED_RUN,   1, 100, 100);

//	ledFlashSet(LED_MESH,  1, 100, 100);

//}



//void ledFlashSet(uint8_t chan, uint8_t chFlashCnt, uint16_t hwOnTime, uint16_t hwOffTime)
//{
//	switch (chan)
//	{
//	case LED_RUN:
//		sChFlashCnt[LED_RUN]     = chFlashCnt;
//		sHwFlashOnTime[LED_RUN]  = hwOnTime;
//		sHwFlashOffTime[LED_RUN] = hwOffTime;
//		sChFlashFsmSta[LED_RUN]  = 0;		
//		break;

//	case LED_MESH:
//		sChFlashCnt[LED_MESH]     = chFlashCnt;
//		sHwFlashOnTime[LED_MESH]  = hwOnTime;
//		sHwFlashOffTime[LED_MESH] = hwOffTime;
//		sChFlashFsmSta[LED_MESH]  = 0;		
//		break;
//			
//	}
//}



//void ledFlashLoop(uint8_t chan)
//{
//    static uint16_t sHwTime[LED_CHANNEL]     = {0};    
//    static uint8_t sChLedSta[LED_CHANNEL]    = {0};              
//    static uint8_t sChFlashMode[LED_CHANNEL] = {0};             

//    switch (sChFlashFsmSta[chan])
//    {
//	case 0:
//		if (0 == sChFlashCnt[chan]) {
//			sChFlashMode[chan] = 1;
//			
//		} else {
//			sChFlashMode[chan] = 0;
//		}

//		ledOff(chan);                         
//		sChLedSta[chan] = 1;                             
//		sChFlashFsmSta[chan] = 1;                       

//		break;

//	case 1:
//		if (sChLedSta[chan]) {
//			if (0 == sHwTime[chan]) {
//				if ((0 == sChFlashCnt[chan]) && (0 == sChFlashMode[chan])) {
//					sChFlashFsmSta[chan] = 2;
//					break;
//				}

//				if (sHwFlashOnTime[chan]) {
//					ledOn(chan);
//					sHwTime[chan] = sHwFlashOnTime[chan];     
//					sChLedSta[chan] = 0;                 
//				}
//				
//			} else {
//				sHwTime[chan]--;                         
//			}
//			
//		} else {
//			if (0 == sHwTime[chan]) {
//				if (sHwFlashOffTime[chan]) {
//					ledOff(chan);
//					sHwTime[chan] = sHwFlashOffTime[chan];
//					sChLedSta[chan] = 1;

//					if (!sChFlashMode[chan]) {
//						if (sChFlashCnt[chan]) {
//							sChFlashCnt[chan]--;
//						
//						} else {
//							//! do nothing 
//						}
//					}
//				}
//				
//			} else {
//				sHwTime[chan]--;
//			}
//		}

//		break;

//	case 2:
//		//! do nothing 
//		break;

//	default:
//		break;
//    }
//}



//void ledFlashLoopAll(void)
//{
//	ledFlashLoop(LED_RUN);

//	ledFlashLoop(LED_MESH);
//}
/**********************************************
*	函 数 名: static void Out_Put_Init(void)
*	形    参：
*	返 回 值: 
*	功能说明: LED端口初始化				
**********************************************/ 
//static void Beep_Init(void)
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 ;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
////	GPIO_SetBits(GPIOC,GPIO_Pin_13  );
//}
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
