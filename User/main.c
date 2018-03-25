/******************** (C) COPYRIGHT DIY嵌入式开发工作室*******************************
 *                                
 *                              ARM Cortex-M3 Port
 *
 * 文件名称     : STM32F10x工程模板V6.0.0
 * 作    者     :  
 * 环    境	 	  : MDK4.73-->固件库V3.5版本
 * 开发平台     : TOP9110-STM32F103RBT6-8MHz->72MHz 
 * 修改时间     : 2013-12-20 
 * 硬件连接     : STM32F10x-STM32开发板
 * 说    明     : 				  
 * 修改记录     :
 * 版本号       :  日期          作者       说明 
   V6.0.0       :  2014-09-13       1.改进V5.0.0使用JLinkRTT printf，进入硬件故障中断	
	                                          2.JLinkRTT printf消耗资源: Program Size: Code=1600 
																						  RO-data=2 RW-data=120 ZI-data=2080  	 
**************************************************************************************/
/* Includes---------------------------------------------*/
#include "main.h"
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
#define Start_Task_PRIO			( ( unsigned portBASE_TYPE ) 2U )
bool gCanAskForDataPeriod 	= false;
bool gMeshFinished 			= false;
bool gGetStartNewMeshAck 	= false;
itas_msg_t	gITASMsg;
node_t node[NODE_ID_NUM_MAX]; //! note: the node[0] store the master's own info.
node_t current_node;
itas_mode_t meshMode = MESH_MODE_UNINIT;


/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
/* Private functions -----------------------------------*/
/*********************************************************
*	函 数 名: main
*	功能说明: c程序入口
*	形    参：无
*	返 回 值: 错误代码(无需处理)
**********************************************************/
int main(void)
{
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4
	xTaskCreate( vStart_Task, //任务函数名
	             "StartTask", //具有描述性的任务名
	             configMINIMAL_STACK_SIZE, //内核为任务分配堆栈空间大小 usStackDepth 字
	             NULL, 
	             Start_Task_PRIO,          //任务执行的优先级
	             NULL 
	           );//创建一个让LED1闪烁的任务	
	vTaskStartScheduler();	//开始任务调度
}
/************************END OF MAIN**********************/
#ifdef USE_FULL_ASSERT
/*****************************************
*	函 数 名: assert_failed
*	形    参：file : 源代码文件名称。关键字__FILE__表示源代码文件名。
*			  line ：代码行号。关键字 __LINE__ 表示源代码行号
*	返 回 值: 无
*******************************************/
void assert_failed(uint8_t* file, uint32_t line)
{ 
	/* 
		用户可以添加自己的代码报告源代码文件名和代码行号，比如将错误文件和行号打印到串口
		printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* 这是一个死循环，断言失败时程序会在此处死机，以便于用户查错 */
	while (1)
	{
	}
}

//! twice of askForDataPeriod() in running frequency(rate)




#endif
/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
