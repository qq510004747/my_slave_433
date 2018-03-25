/******************** (C) COPYRIGHT DIYǶ��ʽ����������*******************************
 *                                
 *                              ARM Cortex-M4 Port
 *
 * �ļ�����     : BSP.h (  )
 * ��    ��     : MJQ	 
 * ��    ��	 	: MDK5.10a-->�̼���V1.5.0�汾
 * ����ƽ̨     : STM32F407ZGT6-25MHz->168MHz 
 * �޸�ʱ��     : 2014-10-20 
 * ��    ��     : V1.0.0
 * Ӳ������     : STM32F40xx-STM32������
 * ˵    ��     : TCP ��ʾ����
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
//uint8_t Internet_Txbuff[InternetBuffLen];	/*����һ��1KB�Ļ���*/
//uint8_t Internet_Rxbuff[InternetBuffLen];	/*����һ��1KB�Ļ���*/
/* Private function prototypes -------------------------*/


///**
//*@brief		TCP Server�ػ���ʾ������
//*@param		��
//*@return	��
//*/
//void Internet_Init(void)
//{
//	W5500_SPI_Configuration();	         /*��ʼ��MCU�������*/
//	W5500_RST();                         /*Ӳ��λW5500*/
//    W5500_Set_MAC();			         /*����MAC��ַ*/
//    W5500_Set_IP();                      /*����IP��ַ*/
//	socket_buf_init(txsize, rxsize);     /*��ʼ��8��Socket�ķ��ͽ��ջ����С*/
//}
///**
//*@brief		TCP Server�ػ���ʾ������
//*@param		��
//*@return	��
//*/

//unsigned char TCP_Server_Demo(void)
//{
//    uint16_t len=0;
//	uint8_t  rflag = FALSE;
//	STDATETIME net_time;
//    switch(getSn_SR(SOCK_TCPS))										/*��ȡsocket��״̬*/
//    {
//    case SOCK_CLOSED:											    /*socket���ڹر�״̬*/
//        socket(SOCK_TCPS ,Sn_MR_TCP,ConfigMsg.port,Sn_MR_ND);	     /*��socket*/
//        break;

//    case SOCK_INIT:													/*socket�ѳ�ʼ��״̬*/
//        listen(SOCK_TCPS);											/*socket��������*/
//        break;

//    case SOCK_ESTABLISHED:											/*socket�������ӽ���״̬*/

//        if(getSn_IR(SOCK_TCPS) & Sn_IR_CON)
//        {
//            setSn_IR(SOCK_TCPS, Sn_IR_CON);							/*��������жϱ�־λ*/
//        }
//        len=getSn_RX_RSR(SOCK_TCPS);							    /*����lenΪ�ѽ������ݵĳ���*/
//        if(len>0)
//        {
//            recv(SOCK_TCPS,Internet_Rxbuff,len);					/*��������Client������*/
//            Internet_Rxbuff[len]=0x00; 							    /*����ַ���������*/
//			
//            if(Internet_Rxbuff[(Internet_Rxbuff[NetLenH]<<8)+Internet_Rxbuff[NetLenL]+4] == 
//			   XORValid(Internet_Rxbuff,(Internet_Rxbuff[NetLenH]<<8)+Internet_Rxbuff[NetLenL]+4))
//			{
//				switch ((Internet_Rxbuff[NetCMDH]<<8)+Internet_Rxbuff[NetCMDL])
//				{
//					case NetSerSendRTCCmd:  //Уʱ
//						 net_time.year =   Internet_Rxbuff[NetDataStarFlag];
//					     net_time.month =  Internet_Rxbuff[NetDataStarFlag+1]; 
//					     net_time.date =   Internet_Rxbuff[NetDataStarFlag+2];
//					     net_time.hour =   Internet_Rxbuff[NetDataStarFlag+3];
//					     net_time.minute = Internet_Rxbuff[NetDataStarFlag+4];
//					     net_time.second = Internet_Rxbuff[NetDataStarFlag+5];
////					     net_time.week =   Internet_Rxbuff[NetDataStarFlag+6];;
//					     RtcSetLocalTime(net_time);
//						 break;
//	            	case NetSerSendRstCmd://�豸����
//						 RS485SendCmdFlag |= 1<<(NetSerSendRstCmd&0xFF);  
//						 ReBoot_Flag = 0xFF;//�豸������־
//	            		 break;			
//					case NetSerQueryCmd://�����������豸״̬����
//						 NetSendCmdFlag |= 1<<(NetSerQueryCmd&0xFF);
//					     xSemaphoreGive(xSem_Net);
//	            		 break;
//					case NetSerSendAlarmCmd://�����������豸������������
//						 NetSendCmdFlag |= 1<<(NetSerSendAlarmCmd&0xFF);
//					     xSemaphoreGive(xSem_Net);
//	            		 break;
//					case NetSerSendGPSCmd://����������GPS����
//						 NetSendCmdFlag |= 1<<(NetSerSendGPSCmd&0xFF);
//	            		 break;
//					case NetSerSendDerIPCmd://�����������޸��豸IP����
//						 SaveSysParameter(Internet_Rxbuff+NetDataStarFlag-2,SysParameterPage+DerParameterPage,NetSerSendDerIPLen+2);
////     					 ReadSysParameter(Internet_Rxbuff,SysParameterPage+DerParameterPage,NetSerSendDerIPLen+2);
//	            		 break;
//					case NetSerSendSerIPCmd://�����������޸ķ�����IP����
//						 SaveSysParameter(Internet_Rxbuff+NetDataStarFlag-2,SysParameterPage+SerParameterPage,NetSerSendSerIPLen+2); 
////     					 ReadSysParameter(Internet_Rxbuff,SysParameterPage+SerParameterPage,NetSerSendDerIPLen+2);
//   					     break;
//					case NetSerSendGPRSIPCmd://�����������޸�GPRS������IP����
//						 SaveSysParameter(Internet_Rxbuff+NetDataStarFlag-2,SysParameterPage+GPRSParameterPage,NetSerSendGPRSIPLen+2);
////					     ReadSysParameter(Internet_Rxbuff,SysParameterPage+GPRSParameterPage,NetSerSendGPRSIPLen+2);
//	            		 break;
//					case NetSerSendWSDCmd://������������ʪ�ȷ�ֵ��������
//						 memcpy(Device.WSDAlarmValue,Internet_Rxbuff+NetDataStarFlag,NetSerSendWSDLen);//��ʪ��ģ���趨�������ݿ���
//						 RS485SendCmdFlag |= 1<<(NetSerSendWSDCmd&0xFF); 
//	            		 break;
//					case NetSerSendKGLCmd://���������Ϳ�������ֵ����
//						 memcpy(Device.KGLAlarmValue,Internet_Rxbuff+NetDataStarFlag,NetSerSendKGLLen);//������ģ���趨�������ݿ���
//						 RS485SendCmdFlag |= 1<<(NetSerSendKGLCmd&0xFF); 
//	            		 break;
//					case NetSerSendPerCmd://���������͵�Դ��ֵ����
//						 memcpy(Device.PerAlarmValue,Internet_Rxbuff+NetDataStarFlag,NetSerSendPerLen);//��Դģ���趨�������ݿ���
//						 RS485SendCmdFlag |= 1<<(NetSerSendPerCmd&0xFF); 
//	            		 break;
//					case NetSerSendCHZCmd://�����������غ�բ����
//						 memcpy(Device.CHZAlarmValue,Internet_Rxbuff+NetDataStarFlag,NetSerSendCHZLen);//�غ�բģ���趨�������ݿ���
//						 RS485SendCmdFlag |= 1<<(NetSerSendCHZCmd&0xFF); 
//	            		 break;				
//					default:
//						 break;
//				}
//				rflag = TRUE;
//			}		
//            send(SOCK_TCPS,Internet_Rxbuff,len);				    /*��Client��������*/
//        }
//        break;

//    case SOCK_CLOSE_WAIT:									        /*socket���ڵȴ��ر�״̬*/
//        close(SOCK_TCPS);
//        break;
//    }
//	
//	return rflag;
//}

///**
//*@brief		TCP Client�ػ���ʾ������
//*@param		��
//*@return	FALSE:����ʧ�ܣ�TRUE�����ͳɹ�
//*/

//unsigned int W5500_Send_Delay_Counter=0;                       //W5500������ʱ��������(ms)
//unsigned char TCP_Client_Demo(u16 SendLen)
//{
//    uint16_t len=0;
//    unsigned char rt = FALSE;
//	uint16_t local_port2 =5010;
//    switch(getSn_SR(SOCK_TCPC))								    /*��ȡsocket��״̬*/
//    {
//    case SOCK_CLOSED:											/*socket���ڹر�״̬*/
//        socket(SOCK_TCPC,Sn_MR_TCP,local_port2++,Sn_MR_ND);
//        break;

//    case SOCK_INIT:												/*socket���ڳ�ʼ��״̬*/
//        connect(SOCK_TCPC,ConfigMsg.serip,ConfigMsg.serport);           /*socket���ӷ�����*/
//        break;

//    case SOCK_ESTABLISHED: 										 /*socket�������ӽ���״̬*/
//        if(getSn_IR(SOCK_TCPC) & Sn_IR_CON)
//        {
//            setSn_IR(SOCK_TCPC, Sn_IR_CON); 					/*��������жϱ�־λ*/
//        }
//        len=getSn_RX_RSR(SOCK_TCPC); 							/*����lenΪ�ѽ������ݵĳ���*/
//        if(len>0)
//        {
//            recv(SOCK_TCPC,Internet_Txbuff,len); 				/*��������Server������*/
//            Internet_Txbuff[len]=0x00;  						/*����ַ���������*/
//            send(SOCK_TCPC,Internet_Txbuff,len);				/*��Server��������*/
//			
//        }else send(SOCK_TCPC,Internet_Txbuff,SendLen);           /*��Server��������*/
//        
//		rt = TRUE ;
//        break;

//    case SOCK_CLOSE_WAIT: 										/*socket���ڵȴ��ر�״̬*/
//        close(SOCK_TCPC);
//        break;
//    }
//	
//	return rt ;
//}
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIYǶ��ʽ���������� ��END OF FILE ��************************/





			                              	         



