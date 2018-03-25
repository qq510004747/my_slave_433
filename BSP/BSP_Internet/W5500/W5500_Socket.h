/******************** (C) COPYRIGHT DIYǶ��ʽ����������*******************************
 *
 *                              ARM Cortex-M4 Port
 *
 * �ļ�����     : BSP.h (  )
 * ��    ��     :    
 * ��    ��	 	: MDK5.10a-->�̼���V1.3.0�汾
 * ����ƽ̨     : STM32F407ZGT6-25MHz->168MHz
 * �޸�ʱ��     : 2014-10-20
 * ��    ��     : V1.0.0
 * Ӳ������     : STM32F40xx-STM32������
 * ˵    ��     :
 *
 *
**************************************************************************************/
#ifndef	_W5500_SOCKET_H_
#define	_W5500_SOCKET_H_
/* Includes---------------------------------------------*/
#include "User_config.h"
#include "W5500_SPI.h"
#include "W5500_Conf.h"
/* Private defines--------------------------------------*/
/*Socket �˿�ѡ�񣬿ɰ��Լ���ϰ�߶���*/
#define SOCK_TCPS             0
#define SOCK_HUMTEM			  0
#define SOCK_PING			  0
#define SOCK_TCPC             1
#define SOCK_UDPS             2
#define SOCK_WEIBO      	  2
#define SOCK_DHCP             3
#define SOCK_HTTPS            4
#define SOCK_DNS              5
#define SOCK_SMTP             6
#define SOCK_NTP              7
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
extern uint8_t socket(SOCKET s, uint8_t protocol, uint16_t port, uint8_t flag); // Opens a socket(TCP or UDP or IP_RAW mode)
extern void close(SOCKET s); // Close socket
extern uint8_t connect(SOCKET s, uint8_t * addr, uint16_t port); // Establish TCP connection (Active connection)
extern void disconnect(SOCKET s); // disconnect the connection
extern uint8_t listen(SOCKET s);	// Establish TCP connection (Passive connection)
extern uint16_t send(SOCKET s, const uint8_t * buf, uint16_t len); // Send data (TCP)
extern uint16_t recv(SOCKET s, uint8_t * buf, uint16_t len);	// Receive data (TCP)
extern uint16_t sendto(SOCKET s, const uint8_t * buf, uint16_t len, uint8_t * addr, uint16_t port); // Send data (UDP/IP RAW)
extern uint16_t recvfrom(SOCKET s, uint8_t * buf, uint16_t len, uint8_t * addr, uint16_t  *port); // Receive data (UDP/IP RAW)
/* Private functions -----------------------------------*/
/********** (C) COPYRIGHT DIYǶ��ʽ���������� ��END OF FILE ��************************/
#endif

