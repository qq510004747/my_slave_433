/**************(C) COPYRIGHT  DIYǶ��ʽ����������*****************************
 * �ļ���   ��USART.c
 * ����	 	  : MDK4.73-�̼���V3.5-uCOS III V3.03�汾
 * ʵ��ƽ̨ ��TOP9110-STM32F103RBT6-8MHz->72MHz
 * �汾     ��V1.0.0
 * ����     ��
 * �޸�ʱ�� ��2013-12-20
 * Ӳ������ : STM32F10x-STM32������
              ����1:TX-A9 RX-A10   
 * ����     : 1.���ͽ��ղ���ͨ����
              2.���������������ԭ���콢�洮�ڷ�ʽ��δ����
              							
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
//	GPIO_Init(USART2_GPIO_CTR, &GPIO_InitStructure);  //��ʼ��PB8
//	
//	GPIO_SetBits(USART2_GPIO_CTR  , USART2_GPIO_PIN_CTR);
//	
//	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//�����ж�
//	USART_ITConfig(USART2, USART_IT_IDLE , ENABLE);//һ��Ҫ�������ã�;USART_IT_IDLE�����ж�
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

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //USART2 TX��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); //�˿�A��
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; //USART2 RX��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //�������룻
	GPIO_Init(GPIOA, &GPIO_InitStructure); //�˿�A��

	USART_InitStructure.USART_BaudRate = baud; //�����ʣ�
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //����λ8λ��
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //ֹͣλ1λ��
	USART_InitStructure.USART_Parity = USART_Parity_No ; //��У��λ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	//��Ӳ�����أ�
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	//�շ�ģʽ��
	USART_Init(USART2, &USART_InitStructure);//���ô��ڲ���

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����ж��飬4λ��ռ���ȼ���4λ��Ӧ���ȼ�

	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; //�жϺ�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //��Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART2, ENABLE); //ʹ�ܴ��ڣ�
	
	GPIO_InitStructure.GPIO_Pin = USART2_GPIO_PIN_CTR;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(USART2_GPIO_CTR, &GPIO_InitStructure);  //��ʼ��PB8

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
/// �ض���c�⺯��printf��USARTx
int fputc(int ch, FILE *f)
{

RS4851_TX;
		/* ����һ���ֽ����ݵ�USARTx */
		USART_SendData(USED_COM_NUMBER, (uint8_t) ch);
		
		/* �ȴ�������� */
		while (USART_GetFlagStatus(USED_COM_NUMBER, USART_FLAG_TC) == RESET);		
//RS4851_RX;
		return (ch);
}

/// �ض���c�⺯��scanf��USARTx
int fgetc(FILE *f)
{
	RS4851_TX;
		/* �ȴ�����x�������� */
		while (USART_GetFlagStatus(USED_COM_NUMBER, USART_FLAG_RXNE) == RESET);
//	RS4851_RX;
		return (int)USART_ReceiveData(USED_COM_NUMBER);
}
///********** (C) COPYRIGHT DIYǶ��ʽ���������� *****END OF FILE****************/

