/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
				ARM Cortex-M4 Port
* 文件名    : User_Config.h
* 描  述    : 用户系统资源自定义文件
* 环  境	: MDK5.20_StdPeriph_Driver V1.5 For Cortex-M4
* 实验平台  : 
* 版  本    : V1.0.0
* 作  者    :
* 修改时间  : 2013-12-20
* 硬件连接  : STM32F40x-STM32开发板
* 修改记录  :
* 版本号  日期        作者     说明
* V1.0    2013-03-01 
*******************************************************************************/
#ifndef __User_Config_H
#define __User_Config_H
/* Includes---------------------------------------------*/
#include "Utility.h"
//#include "./CmdMsg/NetCmd.h"
//#include "./BSP_Config/BSP_PwrConfig.h"
//#include "./BSP_Config/BSP_CHZConfig.h"
//#include "./BSP_AT24Cxx/IAP_EEPROMPAGE.h"
/* Private defines--------------------------------------*/
//#if USE_FreeRTOS == TRUE     //* 开关全局中断的宏 *
//	#define DISABLE_INT()    taskENTER_CRITICAL()
//	#define ENABLE_INT()     taskEXIT_CRITICAL()
//#else	
//	#define ENABLE_INT()	 __set_PRIMASK(0)	//* 使能全局中断 *
//	#define DISABLE_INT()	 __set_PRIMASK(1)	//* 禁止全局中断 *
//#endif
/*--------- 系统常量定义  ------------------------------*/ 
//#define  USE_FreeRTOS           TRUE    //* 定义 使用RTOS   *
//#define  STM32_BSP_VERSION		"V2.0"  //* 定义 BSP 版本号 *
////#define  DEBUG_MODE             TRUE    //* !TRUE关闭打印调试，TRUE开启打印调试

// -----初始值------------------------------

/*--------- 系统参数常用常量定义（20.16.12.08V2.0） --------*/ 
#define High       1     //输入高电平
#define Low        0     //输入低电平
#define Open       1    
#define Close      0
#define Err        1     //有故障
#define NoErr      0     //没有故障
#define Noused     0xFF  //没有使用：预留
#define RepairBase 10    //自修复基数，该基数可以控制rs485底层设备重新通信的时间

/* Private typedef -------------------------------------*/

/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/

extern uint8_t  HardWareVERSION[]; // 定义 BSP  版本号 
extern uint8_t  AppVERSION[];      // 定义 App  版本号 
extern uint8_t  ProductSN[];       // 定义产品SN
/* Private function prototypes -------------------------*/

/* Private functions -----------------------------------*/
#endif

