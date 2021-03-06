/******************** (C) COPYRIGHT DIY嵌入式开发工作室*******************************
 *
 *                              ARM Cortex-M4 Port
 *
 * 文件名称     : BSP.h (  )
 * 作    者     :    
 * 环    境	 	: MDK5.10a-->固件库V1.3.0版本
 * 开发平台     : STM32F407ZGT6-25MHz->168MHz
 * 修改时间     : 2014-10-20
 * 版    本     : V1.0.0
 * 硬件连接     : STM32F40xx-STM32开发板
 * 说    明     :
 *
 *
**************************************************************************************/
#ifndef _W5500_CONF_H_
#define _W5500_CONF_H_
/* Includes---------------------------------------------*/
#include "User_config.h"
#define __GNUC__
/* Private defines--------------------------------------*/
#define MAX_BUF_SIZE		 	1460		/*定义每个数据包的大小*/
#define KEEP_ALIVE_TIME	     	30	// 30sec
#define TX_RX_MAX_BUF_SIZE      2048
/* Private typedef -------------------------------------*/
typedef unsigned char 	SOCKET;

#pragma pack(1)
/*此结构体定义了W5500可供配置的主要参数*/
typedef struct _CONFIG_MSG
{
    uint8_t  sw_ver[2];	/*软件版本号*/
    uint8_t  mac[6];		/*MAC地址*/
    uint8_t  lip[4];		/*local IP本地IP地址*/
    uint8_t  sub[4];		/*子网掩码*/
    uint8_t  gw[4];		    /*网关*/
    uint8_t  dns[4];		/*DNS服务器地址*/
    uint8_t  serip[4];		/*remote IP远程IP地址*/
    uint16_t port;	        /*本地端口号*/
    uint16_t serport;	    /*远程端口号*/
    uint8_t  gprsip[4];		/*GPRS IP远程IP地址*/
    uint16_t gprsport;	    /*远程端口号*/
    uint8_t  gprsiplen;	    /*GPRS IP远程IP地址转换成字符长度*/
	uint8_t  gprsportlen;	/*远程端口号转换成字符长度*/
} CONFIG_MSG;
#pragma pack()

extern CONFIG_MSG  	ConfigMsg;
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
extern uint8_t      MAC[];
extern uint8_t  	remote_ip[4];		/*远端IP地址*/
extern uint16_t 	remote_port;		/*远端端口号*/
extern uint16_t	    local_port;			/*定义本地端口*/
/* Private function prototypes -------------------------*/
/* 提供给其他C文件调用的函数 */

void Get_NetMsg(void);
void W5500_Set_IP(void);				/*配置W5500的IP地址*/
void W5500_Set_MAC(void);				/*配置W5500的MAC地址*/
/*MCU配置相关函数*/
void W5500_GPIO_Configuration(void);	/*SPI接口reset 及中断引脚*/

/*W5500SPI相关函数*/
void IINCHIP_WRITE( uint32_t addrbsb,  uint8_t data);	/*写入一个8位数据到W5500*/
uint8_t IINCHIP_READ(uint32_t addrbsb);					/*从W5500读出一个8位数据*/
uint16_t wiz_write_buf(uint32_t addrbsb,uint8_t* buf,uint16_t len);	/*向W5500写入len字节数据*/
uint16_t wiz_read_buf(uint32_t addrbsb, uint8_t* buf,uint16_t len);	/*从W5500读出len字节数据*/
/* Private functions -----------------------------------*/

/********** (C) COPYRIGHT DIY嵌入式开发工作室 （END OF FILE ）************************/
#endif







