/******************** (C) COPYRIGHT DIY嵌入式开发工作室*******************************
 *                                
 *                              ARM Cortex-M4 Port
 *
 * 文件名称     : BSP.h (  )
 * 作    者     : MJQ	 
 * 环    境	 	: MDK5.10a-->固件库V1.5.0版本
 * 开发平台     : STM32F407ZGT6-25MHz->168MHz 
 * 修改时间     : 2014-10-20 
 * 版    本     : V1.0.0
 * 硬件连接     : STM32F40xx-STM32开发板
 * 说    明     : TCP 演示函数
 * 			  
 *				   
**************************************************************************************/
/* Includes---------------------------------------------*/
#include "W5500.h"
#include "W5500_conf.h"
#include "W5500_Socket.h"
#include "TCP_Client_Demo.h"
#include "./BSP_RX8025/RX8025_Demo.h"
#include "./BSP_W25Qxx/BSP_W25Qxx.h"
#include "User_RTOSConfig.h"
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
//uint8_t Internet_Txbuff[InternetBuffLen];	/*定义一个1KB的缓存*/
//uint8_t Internet_Rxbuff[InternetBuffLen];	/*定义一个1KB的缓存*/
/* Private function prototypes -------------------------*/


///**
//*@brief		TCP Server回环演示函数。
//*@param		无
//*@return	无
//*/
//void Internet_Init(void)
//{
//	W5500_SPI_Configuration();	         /*初始化MCU相关引脚*/
//	W5500_RST();                         /*硬复位W5500*/
//    W5500_Set_MAC();			         /*配置MAC地址*/
//    W5500_Set_IP();                      /*配置IP地址*/
//	socket_buf_init(txsize, rxsize);     /*初始化8个Socket的发送接收缓存大小*/
//}
///**
//*@brief		TCP Server回环演示函数。
//*@param		无
//*@return	无
//*/

//unsigned char TCP_Server_Demo(void)
//{
//    uint16_t len=0;
//	uint8_t  rflag = FALSE;
//	STDATETIME net_time;
//    switch(getSn_SR(SOCK_TCPS))										/*获取socket的状态*/
//    {
//    case SOCK_CLOSED:											    /*socket处于关闭状态*/
//        socket(SOCK_TCPS ,Sn_MR_TCP,ConfigMsg.port,Sn_MR_ND);	     /*打开socket*/
//        break;

//    case SOCK_INIT:													/*socket已初始化状态*/
//        listen(SOCK_TCPS);											/*socket建立监听*/
//        break;

//    case SOCK_ESTABLISHED:											/*socket处于连接建立状态*/

//        if(getSn_IR(SOCK_TCPS) & Sn_IR_CON)
//        {
//            setSn_IR(SOCK_TCPS, Sn_IR_CON);							/*清除接收中断标志位*/
//        }
//        len=getSn_RX_RSR(SOCK_TCPS);							    /*定义len为已接收数据的长度*/
//        if(len>0)
//        {
//            recv(SOCK_TCPS,Internet_Rxbuff,len);					/*接收来自Client的数据*/
//            Internet_Rxbuff[len]=0x00; 							    /*添加字符串结束符*/
//			
//            if(Internet_Rxbuff[(Internet_Rxbuff[NetLenH]<<8)+Internet_Rxbuff[NetLenL]+4] == 
//			   XORValid(Internet_Rxbuff,(Internet_Rxbuff[NetLenH]<<8)+Internet_Rxbuff[NetLenL]+4))
//			{
//				switch ((Internet_Rxbuff[NetCMDH]<<8)+Internet_Rxbuff[NetCMDL])
//				{
//					case NetSerSendRTCCmd:  //校时
//						 net_time.year =   Internet_Rxbuff[NetDataStarFlag];
//					     net_time.month =  Internet_Rxbuff[NetDataStarFlag+1]; 
//					     net_time.date =   Internet_Rxbuff[NetDataStarFlag+2];
//					     net_time.hour =   Internet_Rxbuff[NetDataStarFlag+3];
//					     net_time.minute = Internet_Rxbuff[NetDataStarFlag+4];
//					     net_time.second = Internet_Rxbuff[NetDataStarFlag+5];
////					     net_time.week =   Internet_Rxbuff[NetDataStarFlag+6];;
//					     RtcSetLocalTime(net_time);
//						 break;
//	            	case NetSerSendRstCmd://设备重启
//						 RS485SendCmdFlag |= 1<<(NetSerSendRstCmd&0xFF);  
//						 ReBoot_Flag = 0xFF;//设备重启标志
//	            		 break;			
//					case NetSerQueryCmd://服务器请求设备状态命令
//						 NetSendCmdFlag |= 1<<(NetSerQueryCmd&0xFF);
//					     xSemaphoreGive(xSem_Net);
//	            		 break;
//					case NetSerSendAlarmCmd://服务器请求设备报警数据命令
//						 NetSendCmdFlag |= 1<<(NetSerSendAlarmCmd&0xFF);
//					     xSemaphoreGive(xSem_Net);
//	            		 break;
//					case NetSerSendGPSCmd://服务器请求GPS命令
//						 NetSendCmdFlag |= 1<<(NetSerSendGPSCmd&0xFF);
//	            		 break;
//					case NetSerSendDerIPCmd://服务器发送修改设备IP命令
//						 SaveSysParameter(Internet_Rxbuff+NetDataStarFlag-2,SysParameterPage+DerParameterPage,NetSerSendDerIPLen+2);
////     					 ReadSysParameter(Internet_Rxbuff,SysParameterPage+DerParameterPage,NetSerSendDerIPLen+2);
//	            		 break;
//					case NetSerSendSerIPCmd://服务器发送修改服务器IP命令
//						 SaveSysParameter(Internet_Rxbuff+NetDataStarFlag-2,SysParameterPage+SerParameterPage,NetSerSendSerIPLen+2); 
////     					 ReadSysParameter(Internet_Rxbuff,SysParameterPage+SerParameterPage,NetSerSendDerIPLen+2);
//   					     break;
//					case NetSerSendGPRSIPCmd://服务器发送修改GPRS服务器IP命令
//						 SaveSysParameter(Internet_Rxbuff+NetDataStarFlag-2,SysParameterPage+GPRSParameterPage,NetSerSendGPRSIPLen+2);
////					     ReadSysParameter(Internet_Rxbuff,SysParameterPage+GPRSParameterPage,NetSerSendGPRSIPLen+2);
//	            		 break;
//					case NetSerSendWSDCmd://服务器发送温湿度阀值参数命令
//						 memcpy(Device.WSDAlarmValue,Internet_Rxbuff+NetDataStarFlag,NetSerSendWSDLen);//温湿度模块设定参数数据拷贝
//						 RS485SendCmdFlag |= 1<<(NetSerSendWSDCmd&0xFF); 
//	            		 break;
//					case NetSerSendKGLCmd://服务器发送开关量阀值命令
//						 memcpy(Device.KGLAlarmValue,Internet_Rxbuff+NetDataStarFlag,NetSerSendKGLLen);//开关量模块设定参数数据拷贝
//						 RS485SendCmdFlag |= 1<<(NetSerSendKGLCmd&0xFF); 
//	            		 break;
//					case NetSerSendPerCmd://服务器发送电源阀值命令
//						 memcpy(Device.PerAlarmValue,Internet_Rxbuff+NetDataStarFlag,NetSerSendPerLen);//电源模块设定参数数据拷贝
//						 RS485SendCmdFlag |= 1<<(NetSerSendPerCmd&0xFF); 
//	            		 break;
//					case NetSerSendCHZCmd://服务器发送重合闸命令
//						 memcpy(Device.CHZAlarmValue,Internet_Rxbuff+NetDataStarFlag,NetSerSendCHZLen);//重合闸模块设定参数数据拷贝
//						 RS485SendCmdFlag |= 1<<(NetSerSendCHZCmd&0xFF); 
//	            		 break;				
//					default:
//						 break;
//				}
//				rflag = TRUE;
//			}		
//            send(SOCK_TCPS,Internet_Rxbuff,len);				    /*向Client发送数据*/
//        }
//        break;

//    case SOCK_CLOSE_WAIT:									        /*socket处于等待关闭状态*/
//        close(SOCK_TCPS);
//        break;
//    }
//	
//	return rflag;
//}

///**
//*@brief		TCP Client回环演示函数。
//*@param		无
//*@return	FALSE:发送失败；TRUE：发送成功
//*/

//unsigned int W5500_Send_Delay_Counter=0;                       //W5500发送延时计数变量(ms)
//unsigned char TCP_Client_Demo(u16 SendLen)
//{
//    uint16_t len=0;
//    unsigned char rt = FALSE;
//	uint16_t local_port2 =5010;
//    switch(getSn_SR(SOCK_TCPC))								    /*获取socket的状态*/
//    {
//    case SOCK_CLOSED:											/*socket处于关闭状态*/
//        socket(SOCK_TCPC,Sn_MR_TCP,local_port2++,Sn_MR_ND);
//        break;

//    case SOCK_INIT:												/*socket处于初始化状态*/
//        connect(SOCK_TCPC,ConfigMsg.serip,ConfigMsg.serport);           /*socket连接服务器*/
//        break;

//    case SOCK_ESTABLISHED: 										 /*socket处于连接建立状态*/
//        if(getSn_IR(SOCK_TCPC) & Sn_IR_CON)
//        {
//            setSn_IR(SOCK_TCPC, Sn_IR_CON); 					/*清除接收中断标志位*/
//        }
//        len=getSn_RX_RSR(SOCK_TCPC); 							/*定义len为已接收数据的长度*/
//        if(len>0)
//        {
//            recv(SOCK_TCPC,Internet_Txbuff,len); 				/*接收来自Server的数据*/
//            Internet_Txbuff[len]=0x00;  						/*添加字符串结束符*/
//            send(SOCK_TCPC,Internet_Txbuff,len);				/*向Server发送数据*/
//			
//        }else send(SOCK_TCPC,Internet_Txbuff,SendLen);           /*向Server发送数据*/
//        
//		rt = TRUE ;
//        break;

//    case SOCK_CLOSE_WAIT: 										/*socket处于等待关闭状态*/
//        close(SOCK_TCPC);
//        break;
//    }
//	
//	return rt ;
//}
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIY嵌入式开发工作室 （END OF FILE ）************************/





			                              	         



