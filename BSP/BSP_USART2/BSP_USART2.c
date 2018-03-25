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
#include "BSP_USART2.h"
#include "BSP_FIFO.h"
#define USED_COM_NUMBER     USART2
/*
* @brief  USART2 init/gprs
* @param	baud
* @retval None
*/
void USART2_Init(uint32_t baud) 
{
//	GPIO_InitTypeDef   GPIO_InitStructure;
//	USART_InitTypeDef  USART_InitStructure;	
//	NVIC_InitTypeDef 	NVIC_InitStructure;
//	
//	USART_DeInit(USART2_USART);
//	RCC_APB2PeriphClockCmd(USART2_RCC_APB2Periph, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD , ENABLE);
//	RCC_APB1PeriphClockCmd(USART2_RCC_APB1Periph_USART2, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
//	
//	
//	GPIO_InitStructure.GPIO_Pin = USART2_GPIO_PIN_TX;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
//	GPIO_Init(USART2_GPIO, &GPIO_InitStructure);

//	GPIO_InitStructure.GPIO_Pin = USART2_GPIO_PIN_RX;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(USART2_GPIO, &GPIO_InitStructure);
//	
//	GPIO_InitStructure.GPIO_Pin = USART2_GPIO_PIN_CTR;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_Init(USART2_GPIO_CTR, &GPIO_InitStructure);  //初始化PB8
//	
//	GPIO_SetBits(USART2_GPIO_CTR  , USART2_GPIO_PIN_CTR);
//	
//	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//开启中断
//	USART_ITConfig(USART2, USART_IT_IDLE , ENABLE);//一定要单独设置，;USART_IT_IDLE空闲中断
//	USART_InitStructure.USART_BaudRate = baud;
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;
//	USART_InitStructure.USART_Parity = USART_Parity_No;
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//	USART_Init(USART2_USART, &USART_InitStructure);
//    USART_GetFlagStatus(USART2_USART, USART_FLAG_TC); 
//	USART_ITConfig(USART2_USART, USART_IT_RXNE, ENABLE);
//			 
//	
//	USART_Cmd(USART2_USART, ENABLE);
//	USART_ClearFlag(USART2_USART, USART_FLAG_TC);
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//	NVIC_InitStructure.NVIC_IRQChannel = USART2_USART_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//	
//	GPIO_InitStructure.GPIO_Pin = USART2_GPIO_PIN_CTR;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(USART2_GPIO_CTR, &GPIO_InitStructure);  
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;        

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE );
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE );

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //USART2 TX；
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //复用推挽输出；
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); //端口A；
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; //USART2 RX；
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //浮空输入；
	GPIO_Init(GPIOA, &GPIO_InitStructure); //端口A；

	USART_InitStructure.USART_BaudRate = baud; //波特率；
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位8位；
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //停止位1位；
	USART_InitStructure.USART_Parity = USART_Parity_No ; //无校验位；
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	//无硬件流控；
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	//收发模式；
	USART_Init(USART2, &USART_InitStructure);//配置串口参数

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断组，4位抢占优先级，4位响应优先级

	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; //中断号
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART2, ENABLE); //使能串口；
	
	GPIO_InitStructure.GPIO_Pin = USART2_GPIO_PIN_CTR;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(USART2_GPIO_CTR, &GPIO_InitStructure);  //初始化PB8

	GPIO_SetBits(USART2_GPIO_CTR  , USART2_GPIO_PIN_CTR);
}

void USART2Stop(void) 
{
	USART_DeInit(USART2_USART);	
}

void USART2SendChar(unsigned char data) 
{  
    USART_SendData(USART2_USART, data);  
    while (USART_GetFlagStatus(USART2_USART, USART_FLAG_TC) == RESET){}  
} 

void USART2SendBuffer(unsigned char *buffer, uint16_t count) 
{
	while (count--) {    
		USART2SendChar(*buffer);    
		buffer++;    
	}
}

void USART2_USART_IRQHandler()
{
	unsigned char data;
	if (USART_GetITStatus(USART2_USART, USART_IT_RXNE) != RESET) {
 
		data = USART_ReceiveData(USART2_USART);

	}
	USART_ClearITPendingBit(USART1, USART_IT_RXNE );
}
/// 重定向c库函数printf到USARTx
int fputc(int ch, FILE *f)
{

RS4851_TX;
		/* 发送一个字节数据到USARTx */
		USART_SendData(USED_COM_NUMBER, (uint8_t) ch);
		
		/* 等待发送完毕 */
		while (USART_GetFlagStatus(USED_COM_NUMBER, USART_FLAG_TC) == RESET);		
//RS4851_RX;
		return (ch);
}

/// 重定向c库函数scanf到USARTx
int fgetc(FILE *f)
{
	RS4851_TX;
		/* 等待串口x输入数据 */
		while (USART_GetFlagStatus(USED_COM_NUMBER, USART_FLAG_RXNE) == RESET);
//	RS4851_RX;
		return (int)USART_ReceiveData(USED_COM_NUMBER);
}
///********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/

