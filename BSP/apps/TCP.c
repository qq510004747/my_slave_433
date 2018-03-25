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
#include  "TCP.h"
#include "sys.h"
#include "./BSP_Internet/w5500/W5500.h"
#include "./BSP_Internet/w5500/W5500_SPI.h"
#include "./BSP_Internet/w5500/W5500_Conf.h"
#include "./BSP_Internet/w5500/W5500_Socket.h"


/* Private defines--------------------------------------*/
/* Private function prototypes--------------------------*/
uint8_t TCP_Client_Demo(u8 *BUFF,u8 SendLen)
{
    uint8_t  rt = FALSE;
//    uint16_t local_port2 =5010;
//	for(u8 i=5;i>0;i--)
//	{
//		switch(getSn_SR(SOCK_TCPC))								       /*获取socket的状态*/
//		{
//			case SOCK_CLOSED:											/*socket处于关闭状态*/
//				socket(SOCK_TCPC,Sn_MR_TCP,local_port2+i,Sn_MR_ND);
//				break;
//			case SOCK_INIT:												/*socket处于初始化状态*/
//				rt = 0x10;
//				connect(SOCK_TCPC,ConfigMsg.serip,ConfigMsg.serport);   /*socket连接服务器*/
//				break;
//			case SOCK_ESTABLISHED: 										 /*socket处于连接建立状态*/
//				if(getSn_IR(SOCK_TCPC) & Sn_IR_CON)
//				{
//					setSn_IR(SOCK_TCPC, Sn_IR_CON); 					/*清除接收中断标志位*/
//				}
//				len=getSn_RX_RSR(SOCK_TCPC); 							/*定义len为已接收数据的长度*/
//				if(len>0)
//				{
//					recv(SOCK_TCPC,Internet_Txbuff,len); 				/*接收来自Server的数据*/
//					Internet_Txbuff[len]=0x00;  						/*添加字符串结束符*/
//					send(SOCK_TCPC,BUFF,SendLen);				/*向Server发送数据*/
//				}
//				rt |= 0x01 ;
//				break;
//			case SOCK_CLOSE_WAIT: 										/*socket处于等待关闭状态*/
//				close(SOCK_TCPC);
//				break;
//		}
//		if((rt == 0x11)||(rt == 0x01)) break;									
//	}  
    return rt ;
}

uint8_t TCP_Server_Demo(uint8_t * BUFF,u8 SendLen)
{
	 uint8_t  rt = FALSE;
//	uint16_t len=0;
//	for(u8 i=5;i>0;i--)
//	{
//		switch(getSn_SR(SOCK_TCPS))									   /*获取socket的状态*/
//		{
//		case SOCK_CLOSED:											    /*socket处于关闭状态*/
//			socket(SOCK_TCPS ,Sn_MR_TCP,ConfigMsg.port,Sn_MR_ND);	     /*打开socket*/
//			break;

//		case SOCK_INIT:	
//			/*socket已初始化状态*/
//			rt = 0x10;
//			listen(SOCK_TCPS);											/*socket建立监听*/
//			break;
//		case SOCK_ESTABLISHED:											/*socket处于连接建立状态*/
//			if(getSn_IR(SOCK_TCPS) & Sn_IR_CON)
//			{
//				setSn_IR(SOCK_TCPS, Sn_IR_CON);							/*清除接收中断标志位*/
//			}
//			len=getSn_RX_RSR(SOCK_TCPS);							    /*定义len为已接收数据的长度*/
//			if(len>0)
//			{
//				recv(SOCK_TCPS,Internet_Rxbuff,len);					/*接收来自Client的数据*/
//				send(SOCK_TCPS,BUFF,8);	/*向Client发送数据*/

////				send(SOCK_TCPS,Internet_Rxbuff,len);	/*向Client发送数据*/
////			    close(SOCK_TCPS);	//短连接，每接受完成一次数据，断开连接
//			}	
//			rt |= 0x01 ;
//			break;
//		 case SOCK_CLOSE_WAIT:	/*socket处于等待关闭状态*/
//			close(SOCK_TCPS);
//			break;
//	   }															
//		if((rt == 0x11)||(rt == 0x01)) break;	
//	  }
	  return rt ;
}


//static void Beep_Init(void);
/* Private functions -----------------------------------*/
//-----------------
/**********************************************
*	函 数 名: 
*	形    参：
*	返 回 值: 
*	功能说明: 				
**********************************************/ 

/**********************************************
*	函 数 名: 
*	形    参：
*	返 回 值: 
*	功能说明: 				
**********************************************/ 


/********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
