/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：BSP.h
 * 描述     :
 * 环境	 	  : MDK4.73-固件库V3.5版本
 * 实验平台 ：TOP9110-STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 : STM32F10x-STM32开发板
*******************************************************************************/
/* Includes---------------------------------------------*/
#include  "main.h"
static u32 Current_Mac1 = 0;
static u32 Current_Mac2 = 0;
static u32 Current_Mac3 = 0;
typedef void (*pFunction)(void);
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
/* 全局运行时间，单位10ms，用于uIP */
//volatile int32_t Sys_RunTime = 0;
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
//static void SysTick_Init(void);
static void NVIC_Configuration(void);
static void SysTick_Init(void);
static u8  fac_us=0;																										/*us延时倍乘数*/
static u16 fac_ms=0;	
u8 myMac[6] = {0};
static void NVIC_Configuration(void)
{
	//响应优先级
	//USART1: NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	//CAN1  : NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	//
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );//优先级设置  抢占优先级为0,0-15响应优先级
}
/***********************************************
*	函 数 名: static void BSP_SysTick(void)
*	功能说明: 配置systic中断周期为1ms，并启动systick中断。
*	形    参：无
*	返 回 值: 无
************************************************/
static void SysTick_Init(void)
{
	/* 
		配置systic中断周期为1ms，并启动systick中断。    	
    Systick中断向量在(\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x\startup\arm\
    		startup_stm32f10x_hd.s 文件中定义为 SysTick_Handler。
    SysTick_Handler函数的实现在stm32f10x_it.c 文件。
    SysTick_Handler函数调用了SysTick_ISR()函数，在本文件末尾。
   */	
//	SysTick_Config(SystemCoreClock / 1000);
	 if( SysTick_Config( SystemCoreClock / 1000 ) )    //1ms
    { 
        /* Capture error */ 
        while (1);
    }
}

																									/*ms延时倍乘数*/

/**
*@brief		初始化延迟函数
*@param		SYSCLK:系统时钟
*@return	无
*/
//void systick_init (u8 sysclk)
//{
//	SysTick->CTRL&=0xfffffffb;																						/*bit2清空,选择外部时钟  HCLK/8*/
//	fac_us=sysclk/8;		    
//	fac_ms=(u16)fac_us*1000;
//}								    




void delayInit(void)
{        

	u32 reload;
	SysTick->CTRL &= 0xFFFFFFFB;	 //! bit2清空,选择外部时钟  HCLK/8
	fac_ms = fac_ms;
	fac_us = (72000000/1000000)/8;	 //! 1us需计算的脉冲个数,其中(SystemFrequency/1000000)代表1US的脉冲个数,8是需要8分频		 
	fac_ms = (uint16_t)fac_us*1000;  //! 1ms需计算的脉冲个数
	
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);//选择外部时钟  HCLK
	fac_us=SystemCoreClock/1000000;				//不论是否使用OS,fac_us都需要使用
	reload=SystemCoreClock/1000000;				//每秒钟的计数次数 单位为M  
	reload*=1000000/configTICK_RATE_HZ;			//根据configTICK_RATE_HZ设定溢出时间
												//reload为24位寄存器,最大值:16777216,在72M下,约合0.233s左右	
	fac_ms=1000/configTICK_RATE_HZ;				//代表OS可以延时的最少单位	   

	SysTick->CTRL|=SysTick_CTRL_TICKINT_Msk;   	//开启SYSTICK中断
	SysTick->LOAD=reload; 						//每1/configTICK_RATE_HZ秒中断一次	
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;   	//开启SYSTICK    
	
}

/* Private functions -----------------------------------*/
/*******************************************************************************
* Function Name :void BSP_init(void)
* Description   :系统底层驱动初始化
* Input         :
* Output        :
* Other         :
* Date          :2013.12.14  
*******************************************************************************/
void BSP_Init(void)
{
	u8 Switch_Flag = 0;
	SysTick_Init();
	delayInit();
	NVIC_Configuration();
	EXTI_Initialization();
	TIM3_Int_Init(9,7199);//1ms
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);    //开启AFIO时钟
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);      /*使能SWD 禁用JTAG*/

	BSP_OutPut_Init();
	BSP_InPut_Init();
	BSP_Switch_Init();
	BSP_USART1_Init(57600);
	USART2_Init(57600);  
	BoardInit( );
	Switch_Flag = Get_Switch_Status(); 
	Get_Switch_Message(Switch_Flag);
	Adc_Init();
	radioInit();
	RS4851_TX;
	PAout(15) = 1;
//	RS4851_RX;

	while (!getCpuId(&Current_Mac1, &Current_Mac2, &Current_Mac3)) { //! if get mac failed, then continue to get till succeed!

	}
	current_node.mac[0] = Current_Mac1;
	current_node.mac[1] = Current_Mac2;
	current_node.mac[2] = Current_Mac3;
	Get_NetMsg();
	getDevMac(&myMac[0], &myMac[1], &myMac[2], &myMac[3], &myMac[4], &myMac[5]);
	printf("init  ok \r\n");
} 
//普通延时

//72M条件下us精确延时函数，Nus<=500           



/**
*@brief		STM32系统软复位函数
*@param		无
*@return	无
*/
void systemReboot(void)
{
	printf("systemReboot\r\n");
	__set_FAULTMASK(1);  //关总中断
	NVIC_SystemReset();//执行复位
}



/*******************************
*	函 数 名: Delay_ms
*	功能说明: ms级延迟，延迟精度为正负1ms
*	形    参：n : 延迟长度，单位1 ms。 n 应大于2
*	返 回 值: 无
********************************/

/**************************************************
*	函 数 名: bsp_GetRunTime
*	功能说明: 获取CPU运行时间，单位1ms
*	形    参：无
*	返 回 值: CPU运行时间，单位1ms
***************************************************/
//int32_t bsp_GetRunTime(void)
//{
//	int runtime; 
//	__set_PRIMASK(1);  		/* 关中断 */
//	runtime = Sys_RunTime;	/* 由于在Systick中断被改写，因此关中断进行保护 */	
//	__set_PRIMASK(0);  		/* 开中断 */
//	return runtime;
//}
/**************************************
* Function Name :void InterruptOrder(void)
* Description   :中断向量，优先级
* Input         :
* Output        :
* Other         :
* Date          :2011.10.27  11:50:05
***************************************/

/***********************************************
*	函 数 名: void SysTick_Handler(void)
*	功能说明: SysTick中断服务程序，每隔1ms进入1次
*	形    参：无
*	返 回 值: 无
************************************************/
//void SysTick_Handler(void)
//{
//	static uint8_t s_count = 0;
//	TickCounter++;	/* 全局运行时间每1ms增1 */	
//	if (TickCounter == 0x7FFFFFFF)
//	{
//		TickCounter = 0;
//	}	
//	if (++s_count >= 10)
//	{
//		s_count = 0;
//		/* 
//			下面的代码实现所有按键的检测。按键检测每隔10ms一次就行了，一般做40ms的滤波处理就可以
//			有效过滤掉机械动作造成的按键抖动。
//		*/
//	}
//}
/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
