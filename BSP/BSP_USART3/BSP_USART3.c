/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：USART.c
 * 环境	 	  : MDK4.73-固件库V3.5-uCOS III V3.03版本
 * 实验平台 ：TOP9110-STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 : STM32F10x-STM32开发板
              串口1:TX-A9 RX-A10   
 * 描述     : 1.发送接收测试通过，
              2.接受数组采用正点原子旗舰版串口方式，未测试
              							
*******************************************************************************/
/* Includes---------------------------------------------*/
#include "main.h"
#include "BSP_USART3.h"
#include "BSP_FIFO.h"
/*
* @brief  usart3 init/gprs
* @param	baud
* @retval None
*/
void usart3Init(uint32_t baud) 
{
	GPIO_InitTypeDef   GPIO_InitStructure;
	USART_InitTypeDef  USART_InitStructure;	
	NVIC_InitTypeDef 	NVIC_InitStructure;
	
	USART_DeInit(USART3_USART);
	RCC_APB2PeriphClockCmd(USART3_RCC_APB2Periph, ENABLE);
	RCC_APB1PeriphClockCmd(USART3_RCC_APB1Periph_USART3, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = USART3_GPIO_PIN_TX;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_Init(USART3_GPIO, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = USART3_GPIO_PIN_RX;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART3_GPIO, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = baud;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART3_USART, &USART_InitStructure);
    USART_GetFlagStatus(USART3_USART, USART_FLAG_TC); 
	USART_ITConfig(USART3_USART, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART3_USART, ENABLE);
	USART_ClearFlag(USART3_USART, USART_FLAG_TC);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_InitStructure.NVIC_IRQChannel = USART3_USART_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void usart3Stop(void) 
{
	USART_DeInit(USART3_USART);	
}

void usart3SendChar(unsigned char data) 
{  
    USART_SendData(USART3_USART, data);  
    while (USART_GetFlagStatus(USART3_USART, USART_FLAG_TC) == RESET){}  
} 

void usart3SendBuffer(unsigned char *buffer, uint16_t count) 
{
	while (count--) {    
		usart3SendChar(*buffer);    
		buffer++;    
	}
}

void USART3_USART_IRQHandler()
{
	unsigned char data; 
	if (USART_GetITStatus(USART3_USART, USART_IT_RXNE) != RESET) {
		Some_Data_On_Sky = 1;
		data = USART_ReceiveData(USART3_USART);
		fifoPushBuf(&data, 1);
	}
//	USART_ClearITPendingBit(USART3, USART_IT_RXNE );
}

///********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/

