/******************** (C) COPYRIGHT DIY嵌入式开发工作室*******************************
 *
 *                              ARM Cortex-M4 Port
 *
 * 文件名称     : W5500_SPI.h (  )
 * 作    者     :    
 * 环    境	 	: MDK5.10a-->固件库V1.5.0版本
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
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
/* Private functions -----------------------------------*/
void  Internet_Init(void)
{
    W5500_SPI_Configuration();	         /*初始化MCU相关引脚*/
	vTaskDelay(2000);
//    /*硬复位W5500*/
    GPIO_ResetBits(WIZ_RESET_PORT, WIZ_RESET);
    vTaskDelay(50);
    GPIO_SetBits(WIZ_RESET_PORT, WIZ_RESET);

//	printf("w5500re_initok \n");
    vTaskDelay(2000);
//    W5500_Set_MAC();			         /*配置MAC地址*/
    W5500_Set_IP();                      /*配置IP地址*/
    socket_buf_init(txsize, rxsize);     /*初始化8个Socket的发送接收缓存大小*/	
}
/**
  * @brief  根据外部SPI设备配置SPI相关参数
  * @retval None
  */
void W5500_SPI_Configuration(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;
	SPI_InitTypeDef  SPI_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,ENABLE);
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | WIZ_RESET_RCC | WIZ_SCS_RCC | WIZ_Pwr_RCC, ENABLE);
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //PB13/14/15复用推挽输出 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB

 	GPIO_SetBits(GPIOB,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);  //PB13/14/15上拉
	
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //设置SPI单向或者双向的数据模式:SPI设置为双线双向全双工
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//设置SPI工作模式:设置为主SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		//设置SPI的数据大小:SPI发送接收8位帧结构
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		//串行同步时钟的空闲状态为高电平
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;	//串行同步时钟的第二个跳变沿（上升或下降）数据被采样
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS信号由硬件（NSS管脚）还是软件（使用SSI位）管理:内部NSS信号有SSI位控制
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		//定义波特率预分频的值:波特率预分频值为256
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//指定数据传输从MSB位还是LSB位开始:数据传输从MSB位开始
	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRC值计算的多项式
	SPI_Init(SPI2, &SPI_InitStructure);  //根据SPI_InitStruct中指定的参数初始化外设SPIx寄存器
 
	SPI_I2S_ITConfig(SPI1,SPI_I2S_IT_RXNE,ENABLE);
	SPI_Cmd(SPI2, ENABLE); //使能SPI外设
	
	W5500_SPI_SendByte(0xff);//启动传输		
	
	
    //初始化片电源控制引脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Pin = WIZ_Pwr;
    GPIO_Init(WIZ_Pwr_PORT, &GPIO_InitStructure);
    GPIO_SetBits(WIZ_Pwr_PORT,WIZ_Pwr);
	
	//初始化片选输出引脚
    GPIO_InitStructure.GPIO_Pin = WIZ_SCS;
//    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
//    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(WIZ_SCS_PORT, &GPIO_InitStructure);
    GPIO_SetBits(WIZ_SCS_PORT,WIZ_SCS);
	
    //初始化复位输出引脚
    GPIO_InitStructure.GPIO_Pin = WIZ_RESET;
//    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
//    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(WIZ_RESET_PORT, &GPIO_InitStructure);
    GPIO_SetBits(WIZ_RESET_PORT,WIZ_RESET);

}

/**
*@brief		W5500基本SPI读写函数
*@param		无
*@return	无
*/
uint8_t W5500_SPI_SendByte(uint8_t byte)
{
	/* Loop while DR register in not emplty */
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
    /* Send byte through the SPI1 peripheral */
    SPI_I2S_SendData(SPI2, byte);

    /* Wait to receive a byte */
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
    /* Return the byte read from the SPI bus */
    return SPI_I2S_ReceiveData(SPI2);
}


  

/********** (C) COPYRIGHT DIY嵌入式开发工作室 （END OF FILE ）************************/
