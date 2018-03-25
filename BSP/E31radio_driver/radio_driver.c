#include "main.h"
#include "radio_driver.h"
#include "BSP_USART1.h"
#define radioDelayMs(a)		vTaskDelay(a)

#define RADIO_RX_BUF_MAX	30

#define  READPARAMETER 	    {0xC1,0xC1,0xC1}
#define  TTLSELFCHECK		{0xC4,0xC4,0xC4}
u8       e31_set[6]       = {0xC0 ,0xFF ,0xFF ,0x36 ,0x64 ,0x44 };
struct TTLConfig
{
	u8	HEAD;								//�̶� 0xC0 �� 0xC2����ʾ��֡����Ϊ��������   0xC0�����õĲ�������籣��
	u8	ADDH;								//ģ���ַ���ֽ�   00H-FFH
	u8	ADDL;								//ģ���ַ���ֽ�   00H-FFH
	u8	SPED:2;							//����У��λ       00��8N1��Ĭ�ϣ�
	u8	TTLBPS:3;						//TTL ��������     110�����ڲ�����Ϊ 57600
	u8	SKYBPS:3;						//���߿�������			110����������Ϊ 50k
	u8	CHAN;								//ͨ��Ƶ��       ��425M + CHAN * 0.1M�� 435M
	u8 SPREADMODE:1;				//���㷢��ʹ��λ   0�� ͸������ģʽ��Ĭ�ϣ�
	u8 DRIVEMODE:1;					//IO ������ʽ			1��TXD�� AUX ���������RXD ��������
	u8 WAKEUPTIME:3;				//���߻���ʱ��			000��250ms��Ĭ�ϣ�
	u8 FEC:1;								//FEC ����				1���� FEC��Ĭ�ϣ�
	u8 WIRELESSPOWER:2; 		//���͹���					00�� 17dBm��Ĭ�ϣ�
};

#define SET_TTL { 0xC0,0xFF, 0xFF, 0x00, 0x06 , 0x06, 0x64, 0x00, 0x01, 0x00, 0x01, 0x00 }

uint8_t radioRxBuf[RADIO_RX_BUF_MAX];
uint8_t radioRxBufIndex = 0;
uint8_t gRadioConfigEnable = false;

struct TTLConfig ttlSend = SET_TTL;
u8 SendCom[3] = TTLSELFCHECK;
/**
  * @brief  radio init
  * @note   
  * @retval None
  */
void radioInit(void) 
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//Ҫ�ȿ�ʱ�ӣ�����ӳ�䣻�ر�jtag������swd��  
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA
//						|RCC_APB2Periph_GPIOB
//						|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD 
						, ENABLE);
	
	RCC_APB2PeriphClockCmd(RADIO_RCC_APB2Periph, ENABLE);

//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	
//	GPIO_InitStructure.GPIO_Pin	= RADIO_GPIOC_PINS;
//	GPIO_Init(GPIOC, &GPIO_InitStructure);
//	GPIO_ResetBits(GPIOC, RADIO_GPIOC_PINS);
//	
//	GPIO_InitStructure.GPIO_Pin	= RADIO_GPIOB_PINS;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	GPIO_SetBits(GPIOC, RADIO_GPIOB_PINS);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_InitStructure.GPIO_Pin	= RADIO_GPIOA_PINS;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	//****************************************************************************

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_InitStructure.GPIO_Pin = RADIO_GPIO_PIN_M0 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(RADIO_GPIO_REG_M0, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = RADIO_GPIO_PIN_M1 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(RADIO_GPIO_REG_M1, &GPIO_InitStructure);
	
//	GPIO_SetBits(RADIO_GPIO_REG_M0,RADIO_GPIO_PIN_M0);
//	GPIO_SetBits(RADIO_GPIO_REG_M1,RADIO_GPIO_PIN_M1);
	//****************************************************************************
//	radioSetMode(RADIO_MODE_SLEEP);
GPIO_SetBits(RADIO_GPIO_REG_M0, RADIO_GPIO_PIN_M0);
GPIO_SetBits(RADIO_GPIO_REG_M1, RADIO_GPIO_PIN_M1);
 
	BSP_USART1_Init(9600);		 			//��ʼ������
	
	vTaskDelay(500); 
	UART1_Send_char(e31_set,sizeof(e31_set));	//��������
	vTaskDelay(500); 
	UART1_Send_char(SendCom,sizeof(SendCom));	//��������
	vTaskDelay(500); 

	GPIO_ResetBits(RADIO_GPIO_REG_M0, RADIO_GPIO_PIN_M0);
	GPIO_ResetBits(RADIO_GPIO_REG_M1, RADIO_GPIO_PIN_M1);

	vTaskDelay(100);
	BSP_USART1_Init(57600);					//��ʼ������ 

	vTaskDelay(100);
//	radioSetMode(RADIO_MODE_NORMAL);
//	debugLogInfo("ITSC: radio initialization OK ! \n");
}
	


/**
  * @brief  enable or disable the 433 moduler
  * @note   
  * @retval None
  */
void radioEnable(bool state)
{
	if (state) {
		GPIO_SetBits(RADIO_GPIO_REG_CTRL, RADIO_GPIO_PIN_CTRL);		
		
	} else {
		GPIO_ResetBits(RADIO_GPIO_REG_CTRL, RADIO_GPIO_PIN_CTRL);				
	}
	
}



/**
  * @brief  set or reset M0 and M1
  * @note   
  * @retval None
  */
static void radioSetM0M1(bool m0, bool m1)
{
	if (m0) {
		GPIO_SetBits(RADIO_GPIO_REG_M0, RADIO_GPIO_PIN_M0);
		
	} else {
		GPIO_ResetBits(RADIO_GPIO_REG_M0, RADIO_GPIO_PIN_M0);
	}
	
	if (m1) {
		GPIO_SetBits(RADIO_GPIO_REG_M1, RADIO_GPIO_PIN_M1);
		
	} else {
		GPIO_ResetBits(RADIO_GPIO_REG_M1, RADIO_GPIO_PIN_M1);
	}
}



/**
  * @brief  reset the E31-TTL-50 moduler
  * @note   should under sleep mode
  * @retval None
  */
//void radioReset(void)
//{
//	uint8_t i;
//	
//	radioSetMode(RADIO_MODE_SLEEP);	
//	radioDelayMs(5);
//	for (i = 0; i < 3; i++) {
//		UART1_Send_char(0xC4);
//	}
//}



///**
//  * @brief  get the version of the E31-TTL-50 moduler
//  * @note   should under sleep mode
//  * @retval None
//  */
//void radioGetVersion(void)
//{
//	uint8_t i;
//	
//	radioSetMode(RADIO_MODE_SLEEP);
//	radioDelayMs(5);
//	for (i = 0; i < 3; i++) {
//		UART1_Send_char(0xC3);
//	}	
//}



///**
//  * @brief  get the parameter of the E31-TTL-50 moduler
//  * @note   should under sleep mode
//  * @retval None
//  */
//void radioGetParameter(void)
//{
//	uint8_t i;
//	
//	radioSetMode(RADIO_MODE_SLEEP);
//	radioDelayMs(5);
//	for (i = 0; i < 3; i++) {
//		UART1_Send_char(0xC1);
//	}	
//}



/**
  * @brief  set the parameter of the E31-TTL-50 moduler
  * @note   should under sleep mode 
  * @param  addr:
  * @param  baud:
  * @param  sped:
  * @param	chan: 0 - 255 (425MHz - 450.5MHz)
  * @retval None
  */
void radioSetParameter(uint16_t addr, uint32_t baud, uint32_t sped, uint8_t chan)
{
	uint8_t cmd[6] = {0xC0, 0xFF, 0xFF, 0x1F, 0x50, 0xC4};
	uint8_t baud_t;
	uint8_t sped_t;	

	radioSetMode(RADIO_MODE_SLEEP);
	radioDelayMs(5);

	switch (baud) 
	{
		case 1200:   baud_t = 0; break;
		case 2400:   baud_t = 1; break;
		case 4800:   baud_t = 2; break;
		case 9600:   baud_t = 3; break; //! default
		case 19200:  baud_t = 4; break;
		case 38400:  baud_t = 5; break;		
		case 57600:  baud_t = 6; break;
		case 115200: baud_t = 7; break;
		default:	 baud_t = 3; break;				
	}

	switch (sped) 
	{
		case 1200:   sped_t = 0; break; //! default
		case 2400:   sped_t = 1; break;
		case 4800:   sped_t = 2; break;
		case 9600:   sped_t = 3; break; 
		case 19200:  sped_t = 4; break;
		case 38400:  sped_t = 5; break;		
		case 50000:  sped_t = 6; break;
		case 70000:  sped_t = 7; break;
		default:	 sped_t = 0; break;				
	}	
	
	cmd[0] = 0xC0; //! always save the parameters
	cmd[1] = addr >> 8;
	cmd[2] = addr & 0x00FF;
	cmd[3] = (baud_t << 3) | (sped_t & 0x07);
	cmd[4] = chan;
	cmd[5] = 0xC4;

	UART1_Send_char(cmd, 6); 	
}



/**
  * @brief  set the mode of the E31-TTL-50 moduler
  * @param	mode: 
  * @retval None
  */
void radioSetMode(uint8_t mode)
{
	switch (mode)
	{
		case RADIO_MODE_NORMAL:
			 radioSetM0M1(false, false);
			 break;
		case RADIO_MODE_WAKEUP:
			 radioSetM0M1(true, false);
			 break;
		case RADIO_MODE_POWER_DOWN:
			 radioSetM0M1(false, true);
			 break;
		case RADIO_MODE_SLEEP:
			 radioSetM0M1(true, true);
			 break;
		default:
			 radioSetM0M1(false, false);
			 break;
	}
}

