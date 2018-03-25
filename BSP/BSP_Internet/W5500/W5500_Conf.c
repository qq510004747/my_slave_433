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
/* Includes---------------------------------------------*/
#include "./BSP_Internet/w5500/W5500.h"
#include "./BSP_Internet/w5500/W5500_SPI.h"
#include "./BSP_Internet/w5500/W5500_Conf.h"
#include "./BSP_Internet/w5500/W5500_Socket.h"
//#include "./BSP_W25Qxx/BSP_W25Qxx.h"
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
CONFIG_MSG  ConfigMsg;	/*配置结构体*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/*定义MAC地址,如果多块W5500网络适配板在同一现场工作，请使用不同的MAC地址*/
uint8_t  MAC[6]= {0x4A,0x4B,0x14,0xC0,0x00,0x03};
/* Private function prototypes -------------------------*/
/* Private functions -----------------------------------*/
/**
*@brief		从EEPROM中获取网络参数状态
*@param		无
*@return	无
*/
void Get_NetMsg(void)
{	
	   /*定义默认IP信息*/
	uint8_t  local_ip[4]   = {192,168,198,101};		/*定义W5500默认IP地址*/
    uint8_t  subnet[4]     = {255,255,255,0};		/*定义W5500默认子网掩码*/
    uint8_t  gateway[4]    = {192,168,198,1};		    /*定义W5500默认网关*/
    uint8_t  dns_server[4] = {114,114,115,115};		/*定义W5500默认DNS*/
    uint16_t local_port    = 5000;	                /*定义本地端口*/
    /*定义远端IP信息*/
    uint8_t  remote_ip[4] = {192,168,198,203};	     /*远端IP地址*/
    uint16_t remote_port  = 8000;					/*远端端口号*/

    /*复制定义的配置信息到配置结构体*/
    memcpy(ConfigMsg.lip,local_ip,4);
    memcpy(ConfigMsg.sub,subnet,4);
    memcpy(ConfigMsg.gw,gateway,4);
    memcpy(ConfigMsg.dns,dns_server,4);
    memcpy(ConfigMsg.serip,remote_ip,4);
    ConfigMsg.port =local_port;
    ConfigMsg.serport=remote_port;

}
/**
*@brief		配置W5500的IP地址
*@param		无
*@return	无
*/
void W5500_Set_IP(void)
{
    /*将IP配置信息写入W5500相应寄存器*/
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
*@brief		配置W5500的MAC地址
*@param		无
*@return	无
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
*@brief		写入一个8位数据到W5500
*@param		addrbsb: 写入数据的地址
*@param     data：写入的8位数据
*@return	无
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
*@brief		从W5500读出一个8位数据
*@param		addrbsb: 写入数据的地址
*@param     data：从写入的地址处读取到的8位数据
*@return	无
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
*@brief		向W5500写入len字节数据
*@param		addrbsb: 写入数据的地址
*@param     buf：写入字符串
*@param     len：字符串长度
*@return	len：返回字符串长度
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
*@brief		从W5500读出len字节数据
*@param		addrbsb: 读取数据的地址
*@param 	buf：存放读取数据
*@param		len：字符串长度
*@return	len：返回字符串长度
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


/********** (C) COPYRIGHT DIY嵌入式开发工作室 （END OF FILE ）************************/








