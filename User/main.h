/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：mian.h
 * 描述     :
 * 环境	 	  : MDK4.73-固件库V3.5版本
 * 实验平台 ：TOP9110-STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 : STM32F10x-STM32开发板
*******************************************************************************/
#ifndef __main_H
#define __main_H
/* Includes---------------------------------------------*/


#include "sys.h"
#include "AppTask.h"

#include "crc.h"
//--------STM32---------------
#include "BSP.h"
#include "adc.h"
#include "FreeRTOS.h"  
#include "task.h"  
#include "queue.h"  
#include "semphr.h"  
#include "Utility.h"
#include "BSP_OutPut.h"
#include "BSP_InPut.h"
#include "BSP_Switch.h"
#include "Inout_Handle.h"

#include "BSP_USART1.h"
#include "BSP_USART2.h"


#include "./BSP_Internet/w5500/W5500.h"
#include "./BSP_Internet/w5500/W5500_SPI.h"
#include "./BSP_Internet/w5500/W5500_Conf.h"
#include "./BSP_Internet/w5500/W5500_Socket.h"

#include "stdlib.h"
#include "projdefs.h"
#include "TIMER2.h"
#include "TIMER3.h"
#include "User_BSP.h"
#include "radio_driver.h"

#include "RF.h"
#include "TCP.h"

#include "platform.h"

//#include "ioe.h"
#include "spi.h"
#include "../../radio/sx1276-Hal.h"
#include "sx1276.h"
#include "sx1276-Hal.h"
#include "sx1276-Fsk.h"
#include "sx1276-LoRa.h"
extern location_control_t  east1_control_t;//东
extern location_control_t  south2_control_t;//南
extern location_control_t  west3_control_t;//西
extern location_control_t  north4_control_t;//北
extern node_t current_node;
extern itas_msg_t	gITASMsg;
extern node_t node[NODE_ID_NUM_MAX]; //! note: the node[0] store the master's own info.

extern bool gCanAskForDataPeriod;
extern bool gMeshFinished;
extern bool gGetStartNewMeshAck;
extern  itas_mode_t meshMode;
extern u16 LED_Lingt_Flash_Timer;
//bool getDevMac(uint8_t *mac0, uint8_t *mac1, uint8_t *mac2, uint8_t *mac3, uint8_t *mac4, uint8_t *mac5);
//bool getCpuId(uint32_t *mac_0, uint32_t *mac_1, uint32_t *mac_2);
//uint8_t getAskForIdPeriod(void);


//void lockFlash(void);
//void unlockFlash(void);
//void writeFlashOneWord(uint32_t writeAddr, uint32_t data);
//uint32_t readFlashBtyes(uint32_t readAddr, uint8_t *readBuf, uint32_t n);

//bool isEnableDHCP(void);

//void checkNodesStatePeriod(void);
//void askForDataPeriod(void);
void startNewMesh(void);
bool getDevMac(uint8_t *mac0, uint8_t *mac1, uint8_t *mac2, uint8_t *mac3, uint8_t *mac4, uint8_t *mac5);
bool getCpuId(uint32_t *mac_0, uint32_t *mac_1, uint32_t *mac_2);
//void parseRadioData(void);
//void parseGPSData(void);

//void itscMsgUpdate(void);

/* Private defines--------------------------------------*/
/* Private function prototypes--------------------------*/
/* Private functions -----------------------------------*/

/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
#endif
