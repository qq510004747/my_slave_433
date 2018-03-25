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
/* Includes---------------------------------------------*/
#include "./BSP_Internet/w5500/W5500.h"
#include "./BSP_Internet/w5500/W5500_SPI.h"
#include "./BSP_Internet/w5500/W5500_Conf.h"
#include "./BSP_Internet/w5500/W5500_Socket.h"
//#include "./BSP_W25Qxx/BSP_W25Qxx.h"
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
CONFIG_MSG  ConfigMsg;	/*���ýṹ��*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/*����MAC��ַ,������W5500�����������ͬһ�ֳ���������ʹ�ò�ͬ��MAC��ַ*/
uint8_t  MAC[6]= {0x4A,0x4B,0x14,0xC0,0x00,0x03};
/* Private function prototypes -------------------------*/
/* Private functions -----------------------------------*/
/**
*@brief		��EEPROM�л�ȡ�������״̬
*@param		��
*@return	��
*/
void Get_NetMsg(void)
{	
	   /*����Ĭ��IP��Ϣ*/
	uint8_t  local_ip[4]   = {192,168,198,101};		/*����W5500Ĭ��IP��ַ*/
    uint8_t  subnet[4]     = {255,255,255,0};		/*����W5500Ĭ����������*/
    uint8_t  gateway[4]    = {192,168,198,1};		    /*����W5500Ĭ������*/
    uint8_t  dns_server[4] = {114,114,115,115};		/*����W5500Ĭ��DNS*/
    uint16_t local_port    = 5000;	                /*���屾�ض˿�*/
    /*����Զ��IP��Ϣ*/
    uint8_t  remote_ip[4] = {192,168,198,203};	     /*Զ��IP��ַ*/
    uint16_t remote_port  = 8000;					/*Զ�˶˿ں�*/

    /*���ƶ����������Ϣ�����ýṹ��*/
    memcpy(ConfigMsg.lip,local_ip,4);
    memcpy(ConfigMsg.sub,subnet,4);
    memcpy(ConfigMsg.gw,gateway,4);
    memcpy(ConfigMsg.dns,dns_server,4);
    memcpy(ConfigMsg.serip,remote_ip,4);
    ConfigMsg.port =local_port;
    ConfigMsg.serport=remote_port;

}
/**
*@brief		����W5500��IP��ַ
*@param		��
*@return	��
*/
void W5500_Set_IP(void)
{
    /*��IP������Ϣд��W5500��Ӧ�Ĵ���*/
    setSUBR(ConfigMsg.sub);
    setGAR(ConfigMsg.gw);
    setSIPR(ConfigMsg.lip);

    getSIPR (ConfigMsg.lip);
    getSUBR(ConfigMsg.sub);
    getGAR(ConfigMsg.gw);

}
void W5500_GetMac(void)
{
    Get_ChipInfo();
	MAC[3] = (((DataStr[9]-'0')<<4)&0xF0)+(DataStr[10]-'0');
	MAC[4] = ChipUniqueID[1]&0xFF;
	MAC[5] = ChipUniqueID[0]&0xFF;
}
/**
*@brief		����W5500��MAC��ַ
*@param		��
*@return	��
*/
//void W5500_Set_MAC(void)
//{
//	Get_ChipInfo();
//	MAC[2] = (((DataStr[9]-'0')<<4)&0xF0)+(DataStr[10]-'0');
//	MAC[3] = (ChipUniqueID[0]>>16)&0xFF;
//	MAC[4] = (ChipUniqueID[0])&0xFF;
//	MAC[5] = (ChipUniqueID[1])&0xFF;
//	memcpy(ConfigMsg.mac, MAC, 6);
//    setSHAR(ConfigMsg.mac);	/**/
//}

/**
*@brief		д��һ��8λ���ݵ�W5500
*@param		addrbsb: д�����ݵĵ�ַ
*@param     data��д���8λ����
*@return	��
*/
void IINCHIP_WRITE( uint32_t addrbsb,  uint8_t data)
{
    GPIO_ResetBits(WIZ_SCS_PORT, WIZ_SCS);
    W5500_SPI_SendByte( (addrbsb & 0x00FF0000)>>16);
    W5500_SPI_SendByte( (addrbsb & 0x0000FF00)>> 8);
    W5500_SPI_SendByte( (addrbsb & 0x000000F8) + 4);
    W5500_SPI_SendByte(data);
    GPIO_SetBits(WIZ_SCS_PORT, WIZ_SCS);
}

/**
*@brief		��W5500����һ��8λ����
*@param		addrbsb: д�����ݵĵ�ַ
*@param     data����д��ĵ�ַ����ȡ����8λ����
*@return	��
*/
uint8_t IINCHIP_READ(uint32_t addrbsb)
{
    uint8_t data = 0;
    GPIO_ResetBits(WIZ_SCS_PORT, WIZ_SCS);
    W5500_SPI_SendByte( (addrbsb & 0x00FF0000)>>16);
    W5500_SPI_SendByte( (addrbsb & 0x0000FF00)>> 8);
    W5500_SPI_SendByte( (addrbsb & 0x000000F8))    ;
    data = W5500_SPI_SendByte(0x00);
    GPIO_SetBits(WIZ_SCS_PORT, WIZ_SCS);
    return data;
}

/**
*@brief		��W5500д��len�ֽ�����
*@param		addrbsb: д�����ݵĵ�ַ
*@param     buf��д���ַ���
*@param     len���ַ�������
*@return	len�������ַ�������
*/
uint16_t wiz_write_buf(uint32_t addrbsb,uint8_t* buf,uint16_t len)
{
    uint16_t idx = 0;
//   if(len == 0) ;//printf("Unexpected2 length 0\r\n");
    GPIO_ResetBits(WIZ_SCS_PORT, WIZ_SCS);
    W5500_SPI_SendByte( (addrbsb & 0x00FF0000)>>16);
    W5500_SPI_SendByte( (addrbsb & 0x0000FF00)>> 8);
    W5500_SPI_SendByte( (addrbsb & 0x000000F8) + 4);
    for(idx = 0; idx < len; idx++)
    {
        W5500_SPI_SendByte(buf[idx]);
    }
    GPIO_SetBits(WIZ_SCS_PORT, WIZ_SCS);
    return len;
}

/**
*@brief		��W5500����len�ֽ�����
*@param		addrbsb: ��ȡ���ݵĵ�ַ
*@param 	buf����Ŷ�ȡ����
*@param		len���ַ�������
*@return	len�������ַ�������
*/
uint16_t wiz_read_buf(uint32_t addrbsb, uint8_t* buf,uint16_t len)
{
    uint16_t idx = 0;
//  if(len == 0)
//  {
////    printf("Unexpected2 length 0\r\n");
//  }
    GPIO_ResetBits(WIZ_SCS_PORT, WIZ_SCS);
    W5500_SPI_SendByte( (addrbsb & 0x00FF0000)>>16);
    W5500_SPI_SendByte( (addrbsb & 0x0000FF00)>> 8);
    W5500_SPI_SendByte( (addrbsb & 0x000000F8));
    for(idx = 0; idx < len; idx++)
    {
        buf[idx] = W5500_SPI_SendByte(0x00);
    }
    GPIO_SetBits(WIZ_SCS_PORT, WIZ_SCS);
    return len;
}


/********** (C) COPYRIGHT DIYǶ��ʽ���������� ��END OF FILE ��************************/








