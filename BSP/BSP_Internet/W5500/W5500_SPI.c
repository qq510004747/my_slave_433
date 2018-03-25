/******************** (C) COPYRIGHT DIYǶ��ʽ����������*******************************
 *
 *                              ARM Cortex-M4 Port
 *
 * �ļ�����     : W5500_SPI.h (  )
 * ��    ��     :    
 * ��    ��	 	: MDK5.10a-->�̼���V1.5.0�汾
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
/* Private defines--------------------------------------*/
/* Private typedef -------------------------------------*/
/* Private macro ---------------------------------------*/
/* Private variables -----------------------------------*/
/* Private function prototypes -------------------------*/
/* Private functions -----------------------------------*/
void  Internet_Init(void)
{
    W5500_SPI_Configuration();	         /*��ʼ��MCU�������*/
	vTaskDelay(2000);
//    /*Ӳ��λW5500*/
    GPIO_ResetBits(WIZ_RESET_PORT, WIZ_RESET);
    vTaskDelay(50);
    GPIO_SetBits(WIZ_RESET_PORT, WIZ_RESET);

//	printf("w5500re_initok \n");
    vTaskDelay(2000);
//    W5500_Set_MAC();			         /*����MAC��ַ*/
    W5500_Set_IP();                      /*����IP��ַ*/
    socket_buf_init(txsize, rxsize);     /*��ʼ��8��Socket�ķ��ͽ��ջ����С*/	
}
/**
  * @brief  �����ⲿSPI�豸����SPI��ز���
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
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //PB13/14/15����������� 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB

 	GPIO_SetBits(GPIOB,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);  //PB13/14/15����
	
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//����SPI����ģʽ:����Ϊ��SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		//����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;	//����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ256
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRCֵ����Ķ���ʽ
	SPI_Init(SPI2, &SPI_InitStructure);  //����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
 
	SPI_I2S_ITConfig(SPI1,SPI_I2S_IT_RXNE,ENABLE);
	SPI_Cmd(SPI2, ENABLE); //ʹ��SPI����
	
	W5500_SPI_SendByte(0xff);//��������		
	
	
    //��ʼ��Ƭ��Դ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Pin = WIZ_Pwr;
    GPIO_Init(WIZ_Pwr_PORT, &GPIO_InitStructure);
    GPIO_SetBits(WIZ_Pwr_PORT,WIZ_Pwr);
	
	//��ʼ��Ƭѡ�������
    GPIO_InitStructure.GPIO_Pin = WIZ_SCS;
//    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
//    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(WIZ_SCS_PORT, &GPIO_InitStructure);
    GPIO_SetBits(WIZ_SCS_PORT,WIZ_SCS);
	
    //��ʼ����λ�������
    GPIO_InitStructure.GPIO_Pin = WIZ_RESET;
//    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
//    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(WIZ_RESET_PORT, &GPIO_InitStructure);
    GPIO_SetBits(WIZ_RESET_PORT,WIZ_RESET);

}

/**
*@brief		W5500����SPI��д����
*@param		��
*@return	��
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


  

/********** (C) COPYRIGHT DIYǶ��ʽ���������� ��END OF FILE ��************************/
