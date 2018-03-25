/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
 * �ļ���   ��LED.C
 * ����	 	  : MDK4.73-�̼���V3.5�汾
 * ʵ��ƽ̨ ��STM32F103RBT6-8MHz->72MHz
 * �汾     ��V1.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ : STM32F10x-STM32������
 * ����     : ϵͳ������������ļ�
 * �޸ļ�¼     :
 * �汾��       :  ����          ����       ˵�� 
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
//		switch(getSn_SR(SOCK_TCPC))								       /*��ȡsocket��״̬*/
//		{
//			case SOCK_CLOSED:											/*socket���ڹر�״̬*/
//				socket(SOCK_TCPC,Sn_MR_TCP,local_port2+i,Sn_MR_ND);
//				break;
//			case SOCK_INIT:												/*socket���ڳ�ʼ��״̬*/
//				rt = 0x10;
//				connect(SOCK_TCPC,ConfigMsg.serip,ConfigMsg.serport);   /*socket���ӷ�����*/
//				break;
//			case SOCK_ESTABLISHED: 										 /*socket�������ӽ���״̬*/
//				if(getSn_IR(SOCK_TCPC) & Sn_IR_CON)
//				{
//					setSn_IR(SOCK_TCPC, Sn_IR_CON); 					/*��������жϱ�־λ*/
//				}
//				len=getSn_RX_RSR(SOCK_TCPC); 							/*����lenΪ�ѽ������ݵĳ���*/
//				if(len>0)
//				{
//					recv(SOCK_TCPC,Internet_Txbuff,len); 				/*��������Server������*/
//					Internet_Txbuff[len]=0x00;  						/*����ַ���������*/
//					send(SOCK_TCPC,BUFF,SendLen);				/*��Server��������*/
//				}
//				rt |= 0x01 ;
//				break;
//			case SOCK_CLOSE_WAIT: 										/*socket���ڵȴ��ر�״̬*/
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
//		switch(getSn_SR(SOCK_TCPS))									   /*��ȡsocket��״̬*/
//		{
//		case SOCK_CLOSED:											    /*socket���ڹر�״̬*/
//			socket(SOCK_TCPS ,Sn_MR_TCP,ConfigMsg.port,Sn_MR_ND);	     /*��socket*/
//			break;

//		case SOCK_INIT:	
//			/*socket�ѳ�ʼ��״̬*/
//			rt = 0x10;
//			listen(SOCK_TCPS);											/*socket��������*/
//			break;
//		case SOCK_ESTABLISHED:											/*socket�������ӽ���״̬*/
//			if(getSn_IR(SOCK_TCPS) & Sn_IR_CON)
//			{
//				setSn_IR(SOCK_TCPS, Sn_IR_CON);							/*��������жϱ�־λ*/
//			}
//			len=getSn_RX_RSR(SOCK_TCPS);							    /*����lenΪ�ѽ������ݵĳ���*/
//			if(len>0)
//			{
//				recv(SOCK_TCPS,Internet_Rxbuff,len);					/*��������Client������*/
//				send(SOCK_TCPS,BUFF,8);	/*��Client��������*/

////				send(SOCK_TCPS,Internet_Rxbuff,len);	/*��Client��������*/
////			    close(SOCK_TCPS);	//�����ӣ�ÿ�������һ�����ݣ��Ͽ�����
//			}	
//			rt |= 0x01 ;
//			break;
//		 case SOCK_CLOSE_WAIT:	/*socket���ڵȴ��ر�״̬*/
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
*	�� �� ��: 
*	��    �Σ�
*	�� �� ֵ: 
*	����˵��: 				
**********************************************/ 

/**********************************************
*	�� �� ��: 
*	��    �Σ�
*	�� �� ֵ: 
*	����˵��: 				
**********************************************/ 


/********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/
