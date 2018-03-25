///**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
// * 文件名   ：USART.c
// * 环境	 	  : MDK4.73-固件库V3.5-uCOS III V3.03版本
// * 实验平台 ：TOP9110-STM32F103RBT6-8MHz->72MHz
// * 版本     ：V1.0.0
// * 作者     ：
// * 修改时间 ：2013-12-20
// * 硬件连接 : STM32F10x-STM32开发板
//              串口1:TX-A9 RX-A10   
// * 描述     : 1.发送接收测试通过，
//              2.接受数组采用正点原子旗舰版串口方式，未测试
//              							
//*******************************************************************************/
///* Includes---------------------------------------------*/
//#include "main.h"
//#include "BSP_USART1.h"
//#include "BSP_FIFO.h"

///* Private defines--------------------------------------*/
//#if USART1_PinRemap   // 定义驱动CAN1的GPIO端口
//		#define USART1_PIN_Rx        GPIO_Pin_7
//		#define USART1_PIN_Tx        GPIO_Pin_6
//		#define USART1_GPIO          GPIOB
//		#define USART1_GPIO_CLK      RCC_APB2Periph_GPIOB
//#else
//		#define USART1_PIN_Rx        GPIO_Pin_10
//		#define USART1_PIN_Tx        GPIO_Pin_9
//		#define USART1_GPIO          GPIOA
//		#define USART1_GPIO_CLK      RCC_APB2Periph_GPIOA
//#endif
///* Private function prototypes--------------------------*/
///* Private typedef -------------------------------------*/
///* Private macro ---------------------------------------*/
///* Private variables -----------------------------------*/
//u8 USART_RX_BUF[USART1_REC_LEN];     //接收缓冲,最大USART1_REC_LEN个字节.
////接收状态
////bit15，	  接收完成标志
////bit14，	  接收到0x0d
////bit13~0，	接收到的有效字节数目
//u16 USART1_RX_STA=0; //接收状态标记
///* Private function prototypes -------------------------*/
//static void USART1_Init(u32 BAUD);
///* Private functions -----------------------------------*/
///**********************************************
//*	函 数 名: BSP_USART_Init(void)
//*	形    参：
//*	返 回 值: 
//*	功能说明: 初始化串口			
//**********************************************/
//void BSP_USART1_Init(u32 BAUD)
//{
//	USART1_Init(BAUD);
//}
///**********************************************
//*	函 数 名: USART1_Init_Config(void)
//*	形    参：
//*	返 回 值: 
//*	功能说明: 初始化串口1				
//**********************************************/ 
////static void USART1_Init(u32 BAUD)
////{
////		GPIO_InitTypeDef GPIO_InitStructure;
////		USART_InitTypeDef USART_InitStructure;
////		USART_DeInit(USART1);  //复位串口1
////		 
////		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//使能GPIOA时钟
////		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
////		RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	//使能USART1
////		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
////		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|USART1_GPIO_CLK, ENABLE);	//使能USART1,USART1_GPIO时钟
////#if USART1_Rx_INT_ENABLE
////		NVIC_InitTypeDef NVIC_InitStructure;
////#endif	 
////		
////#if USART1_PinRemap
////		GPIO_PinRemapConfig(GPIO_Remap_USART1,ENABLE); //开启串口1重映射时钟
////#endif
////	
////#if USART1_Rx_INT_ENABLE	//如果使能了接收配置Usart1 NVIC  
////		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); 
////		NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
////		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=USART1_PreemptionPriority ;//抢占优先级0
////		NVIC_InitStructure.NVIC_IRQChannelSubPriority = USART1_ChannelSubPriority;		//子优先级3
////		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
////		NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
////		 
////		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启中断
////		USART_ITConfig(USART1, USART_IT_IDLE , ENABLE);//一定要单独设置，;USART_IT_IDLE空闲中断
////#endif

//////USART1_TX   PA.9 PB.6
////		GPIO_InitStructure.GPIO_Pin = USART1_PIN_Tx; //PA.9
////		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
////		GPIO_Init(USART1_GPIO, &GPIO_InitStructure); //初始化PA9
//////USART1_RX	  PA.10 PB.7
////		GPIO_InitStructure.GPIO_Pin = USART1_PIN_Rx;
////		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
////		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////		GPIO_Init(USART1_GPIO, &GPIO_InitStructure);  //初始化
////		//RS48C_CTRL
//////		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//////		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//////		GPIO_Init(GPIOB, &GPIO_InitStructure);  //初始化PB8
////	
//////USART 初始化设置
////		USART_InitStructure.USART_BaudRate = BAUD;//一般设置为9600;
////		USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
////		USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
////		USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
////		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
////		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
////		USART_Init(USART1, &USART_InitStructure); //初始化串口
////	

////		USART_Cmd(USART1, ENABLE);//使能串口
////}
//void USART1_Init(u32 bound)
//{
//	//GPIO端口设置
//	GPIO_InitTypeDef GPIO_InitStructure;
//	USART_InitTypeDef USART_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	 
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟
//  
//	//USART1_TX   GPIOA.9
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
//	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.9
//   
//	//USART1_RX	  GPIOA.10初始化
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
//	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.10  

////	//Usart1 NVIC 配置
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//抢占优先级3
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		//子优先级3
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
//	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器

//	USART_InitStructure.USART_BaudRate = bound;//串口波特率
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
//	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

//	USART_Init(USART1, &USART_InitStructure); //初始化串口1
//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启串口接受中断
//	USART_Cmd(USART1, ENABLE);                    //使能串口1 
//}
//#if USART1_Rx_INT_ENABLE
///**********************************************
//*	函 数 名: USART1_IRQHandler(void)
//*	形    参：
//*	返 回 值: 
//*	功能说明: USART1中断函数		
//**********************************************/ 
//void USART1_USART_IRQHandler()
//{
//	unsigned char data;
//	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
//		Some_Data_On_Sky = 1; 
//		data = USART_ReceiveData(USART1);
//		fifoPushBuf(&data, 1);
//	}
//	USART_ClearITPendingBit(USART1, USART_IT_RXNE );
// 
////    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  
////    {     
////        USART_ClearFlag(USART1, USART_FLAG_RXNE);  
////        USART_ClearITPendingBit(USART1, USART_IT_RXNE);  
////        data = USART_ReceiveData(USART1);  
////        fifoPushBuf(&data, 1);
////    }
//}
//#endif 
///***************************************************************************************************************************************************/

///**
//  * @brief  发送字符
//  * @param  len   字符长度， *c   指向待发送字符串的指针
//  * @retval 无
//  */
//void UART1_Send_char(u8* c, u8 len)
//{
//    while(len--)
//    {
//		while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); 
//		USART_SendData(USART1,*c);
//		c++;
//    }        
//}

//void RS4851_Send_char(u8* c, u8 len)
//{
//	 UART1_Send_char( c, len);
//}

//void Usart1Send(u16 ch)
//{
//	USART1->DR = (ch&(u16)0x01FF);   
//	while((USART1->SR&0X40) == 0);//循环发送,直到发送完毕    
//}

//void PrintChar(char *s)
//{
//	char *p;
//	p=s;
//	while(*p != '\0')
//	{
//		Usart1Send(*p);
//		p++;
//	}
//}


//void USART_putchar(USART_TypeDef* USART_x, unsigned char ch)
//{
//		

///* Write a character to the USART */
//    USART_SendData(USART_x, (unsigned char) ch);
//    while( USART_GetFlagStatus(USART_x, USART_FLAG_TXE) == RESET );
//    while( USART_GetFlagStatus(USART_x, USART_FLAG_TC) == RESET );
//	
//}




///*********************************************END OF FILE**********************/



/////*  printf函数的定义与使用-------------------*/
////int fputc(int ch, FILE *f)//发送数据
////   {
////      USART_SendData(USART1, (unsigned char) ch);// USART1 可以换成 USART1 等
////      while (!(USART1->SR & USART_FLAG_TXE));
////      return (ch);
////   }
//// 
//// int fgetc(FILE *f) // 接收数据
////  { 
////      while (!(USART1->SR & USART_FLAG_RXNE));
////      return ((int)(USART1->DR & 0x1FF));
////   } 
////如果要使用printf函数除了#include<stdio.h>和重定义两个输入输出函数外还应该Target->Code Generation中勾选Use MicroLIB 
////char ch='E',str[10]={"FGHIJKLM"};
////int intd=12345;
////printf("The is a example!\n");
////printf("%c\n%s\n%d\n%c\n%s\n%d\n%d\n",'A',"BCD",0x23,ch,str,ch,intd);
////The is a example!
////A
////BCD
////35
////E
////FGHIJKLM
////69
////12345
///*******************************************************************************
//* Function Name  : USART_Scanf_Name
//* Description    : Gets Char values from the hyperterminal.
//* Input          : None
//* Output         : None
//* Return         : Length
//*******************************************************************************/
////int USART_Scanf_Name(char * str)
////{	
////    u16 index = 0;
////	  USART_ClearFlag(USART1,USART_FLAG_RXNE);//清一下接收标志位
////    while(1) 
////    {
////        /* Loop until RXNE = 1 */
////        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET){}//等待直到有数据的到来
////        
////		  str[index++] = (USART_ReceiveData(USART1));
////	    printf("%c",str[index - 1]);//返回输入的内容
////	    if(str[index - 1] == 0x0d)//回车键\r
////	    {  
////	        index--;//去掉回车符并以\0结尾
////			    str[index] ='\0';//结束符号
////	        return index;
////        }
////    }													
////}

///**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
// * 文件名   ：USART.c
// * 环境	 	  : MDK4.73-固件库V3.5-uCOS III V3.03版本
// * 实验平台 ：TOP9110-STM32F103RBT6-8MHz->72MHz
// * 版本     ：V1.0.0
// * 作者     ：
// * 修改时间 ：2013-12-20
// * 硬件连接 : STM32F10x-STM32开发板
//              串口1:TX-A9 RX-A10   
// * 描述     : 1.发送接收测试通过，
//              2.接受数组采用正点原子旗舰版串口方式，未测试
//              							
//*******************************************************************************/
/////* Includes---------------------------------------------*/
////#include "main.h"
////#include "BSP_USART1.h"
////#include "BSP_FIFO.h"
/////*
////* @brief  USART1 init/gprs
////* @param	baud
////* @retval None
////*/
////void USART1Init(uint32_t baud) 
////{
////	GPIO_InitTypeDef   GPIO_InitStructure;
////	USART_InitTypeDef  USART_InitStructure;	
////	NVIC_InitTypeDef 	NVIC_InitStructure;
////	
////	USART_DeInit(USART1_USART);
////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
////	RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
////	
////	GPIO_InitStructure.GPIO_Pin = USART1_GPIO_PIN_TX;
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
////	GPIO_Init(USART1_GPIO, &GPIO_InitStructure);

////	GPIO_InitStructure.GPIO_Pin = USART1_GPIO_PIN_RX;
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////	GPIO_Init(USART1_GPIO, &GPIO_InitStructure);
////	
////	USART_InitStructure.USART_BaudRate = baud;
////	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
////	USART_InitStructure.USART_StopBits = USART_StopBits_1;
////	USART_InitStructure.USART_Parity = USART_Parity_No;
////	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
////	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
////	USART_Init(USART1, &USART_InitStructure);
////    USART_GetFlagStatus(USART1, USART_FLAG_TC); 
////	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
////	USART_Cmd(USART1, ENABLE);
////	USART_ClearFlag(USART1, USART_FLAG_TC);
////	
////	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
////	NVIC_InitStructure.NVIC_IRQChannel = USART1_USART_IRQn;
////	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
////	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
////	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
////	NVIC_Init(&NVIC_InitStructure);
////}

////void USART1Stop(void) 
////{
////	USART_DeInit(USART1);	
////}

////void USART1SendChar(unsigned char data) 
////{  
////    USART_SendData(USART1, data);  
////    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET){}  
////} 

////void USART1SendBuffer(unsigned char *buffer, uint16_t count) 
////{
////	while (count--) {    
////		USART1SendChar(*buffer);    
////		buffer++;    
////	}
////}

////void USART1_USART_IRQHandler()
////{
////	unsigned char data; 
////	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
////		Some_Data_On_Sky = 1;
////		data = USART_ReceiveData(USART1);
////		fifoPushBuf(&data, 1);
////	}
//////	USART_ClearITPendingBit(USART1, USART_IT_RXNE );
////}

///////********** (C) COPYRIGHT DIY嵌入式开发工作室 *****END OF FILE****************/
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
#include "BSP_USART1.h"
#include "BSP_FIFO.h"



#include "stm32f10x.h"
#include "misc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h" 

static void USART1_Init(u32 usart1_baud_rate);
/* Private functions -----------------------------------*/
/**********************************************
*	函 数 名: BSP_USART_Init(void)
*	形    参：
*	返 回 值: 
*	功能说明: 初始化串口			
**********************************************/
void BSP_USART1_Init(u32 usart1_baud_rate)
{
	USART1_Init(usart1_baud_rate);
}
void USART1_Init(u32 usart1_baud_rate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;        

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE );
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE );

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //USART1 TX；
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //复用推挽输出；
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); //端口A；
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //USART1 RX；
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //浮空输入；
	GPIO_Init(GPIOA, &GPIO_InitStructure); //端口A；

	USART_InitStructure.USART_BaudRate = usart1_baud_rate; //波特率；
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位8位；
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //停止位1位；
	USART_InitStructure.USART_Parity = USART_Parity_No ; //无校验位；
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	//无硬件流控；
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	//收发模式；
	USART_Init(USART1, &USART_InitStructure);//配置串口参数；

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); //设置中断组，4位抢占优先级，4位响应优先级；

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; //中断号；
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //抢占优先级；
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //响应优先级；
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART1, ENABLE); //使能串口；
//	GPIO_InitTypeDef GPIO_InitStructure;
//	USART_InitTypeDef USART_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure; 
//	
//	USART_DeInit(USART1);       

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //USART1 TX；
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //复用推挽输出；
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure); //端口A；
//		
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //USART1 RX；
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //浮空输入；
//	GPIO_Init(GPIOA, &GPIO_InitStructure); //端口A；

//	USART_InitStructure.USART_BaudRate = usart1_baud_rate; //波特率；
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位8位；
//	USART_InitStructure.USART_StopBits = USART_StopBits_1; //停止位1位；
//	USART_InitStructure.USART_Parity = USART_Parity_No ; //无校验位；
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//	//无硬件流控；
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//	//收发模式；
//	USART_Init(USART1, &USART_InitStructure);//配置串口参数；

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); //设置中断组，4位抢占优先级，4位响应优先级；

//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; //中断号；
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //抢占优先级；
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //响应优先级；
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);

//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//	USART_ITConfig(USART1, USART_IT_IDLE , ENABLE);//一定要单独设置，;USART_IT_IDLE空闲中断
//	USART_Cmd(USART1, ENABLE); //使能串口；

//	GPIO_InitTypeDef   GPIO_InitStructure;
//	USART_InitTypeDef  USART_InitStructure;	
//	NVIC_InitTypeDef 	NVIC_InitStructure;
//	
//	USART_DeInit(USART1);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
//	GPIO_Init(GPIOA, &GPIO_InitStructure);

//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	USART_InitStructure.USART_BaudRate = usart1_baud_rate;
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;
//	USART_InitStructure.USART_Parity = USART_Parity_No;
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//	USART_Init(USART1, &USART_InitStructure);
//    USART_GetFlagStatus(USART1, USART_FLAG_TC); 
//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//	USART_Cmd(USART1, ENABLE);
//	USART_ClearFlag(USART1, USART_FLAG_TC);
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);

//	GPIO_InitTypeDef   GPIO_InitStructure;
//	USART_InitTypeDef  USART_InitStructure;	
//	NVIC_InitTypeDef 	NVIC_InitStructure;
//	

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
// 
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	USART_InitStructure.USART_BaudRate = usart1_baud_rate;
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;
//	USART_InitStructure.USART_Parity = USART_Parity_No;
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//	USART_Init(USART1, &USART_InitStructure);
//    USART_GetFlagStatus(USART1, USART_FLAG_TC); 
//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//	USART_Cmd(USART1, ENABLE);
//	USART_ClearFlag(USART1, USART_FLAG_TC);
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
}

void USART1_Send_Byte(u8 Data) //发送一个字节；
{
	USART_SendData(USART1,Data);
	while( USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET );
}

void USART1_Send_String(u8 *Data) //发送字符串；
{
	while(*Data)
	USART1_Send_Byte(*Data++);
}

void UART1_Send_char(u8* c, u8 len)
{
    while(len--)
    {
        USART_SendData(USART1,*c);
        while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); 
		c++;
    }        
}
void USART1_IRQHandler(void) //中断处理函数；
{
	unsigned char data; 
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
		Some_Data_On_Sky = 1;
		data = USART_ReceiveData(USART1);
		fifoPushBuf(&data, 1);
	}
	USART_ClearITPendingBit(USART1, USART_IT_RXNE );
}  
 
/* Private defines--------------------------------------*/
//#if USART1_PinRemap   // 定义驱动CAN1的GPIO端口
//		#define USART1_PIN_Rx        GPIO_Pin_7
//		#define USART1_PIN_Tx        GPIO_Pin_6
//		#define USART1_GPIO          GPIOB
//		#define USART1_GPIO_CLK      RCC_APB2Periph_GPIOB
//#else
//		#define USART1_PIN_Rx        GPIO_Pin_10
//		#define USART1_PIN_Tx        GPIO_Pin_9
//		#define USART1_GPIO          GPIOA
//		#define USART1_GPIO_CLK      RCC_APB2Periph_GPIOA
//#endif
///* Private function prototypes--------------------------*/
///* Private typedef -------------------------------------*/
///* Private macro ---------------------------------------*/
///* Private variables -----------------------------------*/
//u8 USART_RX_BUF[USART1_REC_LEN];     //接收缓冲,最大USART1_REC_LEN个字节.
////接收状态
////bit15，	  接收完成标志
////bit14，	  接收到0x0d
////bit13~0，	接收到的有效字节数目
//u16 USART1_RX_STA=0; //接收状态标记
///* Private function prototypes -------------------------*/
//static void USART1_Init(u32 usart1_baud_rate);
///* Private functions -----------------------------------*/
///**********************************************
//*	函 数 名: BSP_USART_Init(void)
//*	形    参：
//*	返 回 值: 
//*	功能说明: 初始化串口			
//**********************************************/
//void BSP_USART1_Init(u32 usart1_baud_rate)
//{
//	USART1_Init(usart1_baud_rate);
//}
///**********************************************
//*	函 数 名: USART1_Init_Config(void)
//*	形    参：
//*	返 回 值: 
//*	功能说明: 初始化串口1				
//**********************************************/ 
//static void USART1_Init(u32 usart1_baud_rate)
//{

//		GPIO_InitTypeDef GPIO_InitStructure;
//		USART_InitTypeDef USART_InitStructure;
//		 
////		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//使能GPIOA时钟
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
//		RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	//使能USART1
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
//	
//#if USART1_Rx_INT_ENABLE
//		NVIC_InitTypeDef NVIC_InitStructure;
//#endif	 
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|USART1_GPIO_CLK, ENABLE);	//使能USART1,USART1_GPIO时钟

//#if USART1_PinRemap
//		GPIO_PinRemapConfig(GPIO_Remap_USART1,ENABLE); //开启串口1重映射时钟
//#endif
//		USART_DeInit(USART1);  //复位串口1
////USART1_TX   PA.9 PB.6
//		GPIO_InitStructure.GPIO_Pin = USART1_PIN_Tx; //PA.9
//		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
//		GPIO_Init(USART1_GPIO, &GPIO_InitStructure); //初始化PA9
////USART1_RX	  PA.10 PB.7
//		GPIO_InitStructure.GPIO_Pin = USART1_PIN_Rx;
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
//		GPIO_Init(USART1_GPIO, &GPIO_InitStructure);  //初始化
//		//RS48C_CTRL
//		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//		GPIO_Init(GPIOB, &GPIO_InitStructure);  //初始化PB8
//	
////USART 初始化设置
//		USART_InitStructure.USART_BaudRate = usart1_baud_rate;//一般设置为9600;
//		USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
//		USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
//		USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
//		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
//		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
//		USART_Init(USART1, &USART_InitStructure); //初始化串口
//	
//#if USART1_Rx_INT_ENABLE	//如果使能了接收配置Usart1 NVIC   
//		NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=USART1_PreemptionPriority ;//抢占优先级0
//		NVIC_InitStructure.NVIC_IRQChannelSubPriority = USART1_ChannelSubPriority;		//子优先级3
//		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
//		NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
//		 
//		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启中断
//		USART_ITConfig(USART1, USART_IT_IDLE , ENABLE);//一定要单独设置，;USART_IT_IDLE空闲中断
//#endif
//		USART_Cmd(USART1, ENABLE);                    //使能串口 
//}

//#if USART1_Rx_INT_ENABLE
///**********************************************
//*	函 数 名: USART1_IRQHandler(void)
//*	形    参：
//*	返 回 值: 
//*	功能说明: USART1中断函数		
//**********************************************/ 
//void USART1_IRQHandler(void)
//{
//	u8 Res;
//	unsigned char data;
//	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
//		Some_Data_On_Sky = 1; 
//		data = USART_ReceiveData(USART1);
//		fifoPushBuf(&data, 1);
//	}
//	USART_ClearITPendingBit(USART1, USART_IT_RXNE );
//}
//#endif 
///***************************************************************************************************************************************************/



///**
//  * @brief  发送字符
//  * @param  len   字符长度， *c   指向待发送字符串的指针
//  * @retval 无
//  */
//void UART1_Send_char(u8* c, u8 len)
//{
//    while(len--)
//    {
//        USART_SendData(USART1,*c);
//        while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); 
//		c++;
//    }        
//}

//void Usart1Send(u16 ch)
//{
//	USART1->DR = (ch&(u16)0x01FF);   
//	while((USART1->SR&0X40) == 0);//循环发送,直到发送完毕    
//}

//void PrintChar(char *s)
//{
//	char *p;
//	p=s;
//	while(*p != '\0')
//	{
//		Usart1Send(*p);
//		p++;
//	}
//}


//void USART_putchar(USART_TypeDef* USART_x, unsigned char ch)
//{
//	/* Write a character to the USART */
//    USART_SendData(USART_x, (unsigned char) ch);
//    while( USART_GetFlagStatus(USART_x, USART_FLAG_TXE) == RESET );
//    while( USART_GetFlagStatus(USART_x, USART_FLAG_TC) == RESET );	
//}



///// 重定向c库函数printf到USARTx
//int fputc(int ch, FILE *f)
//{
//	RS4851_TX;

//		/* 发送一个字节数据到USARTx */
//		USART_SendData(USED_COM_NUMBER, (uint8_t) ch);
//		
//		/* 等待发送完毕 */
//		while (USART_GetFlagStatus(USED_COM_NUMBER, USART_FLAG_TC) == RESET);		

//		return (ch);
//}

///// 重定向c库函数scanf到USARTx
//int fgetc(FILE *f)
//{
//	RS4851_TX;

//	
//		/* 等待串口x输入数据 */
//		while (USART_GetFlagStatus(USED_COM_NUMBER, USART_FLAG_RXNE) == RESET);

//		return (int)USART_ReceiveData(USED_COM_NUMBER);
//}
/*********************************************END OF FILE**********************/



///*  printf函数的定义与使用-------------------*/
//int fputc(int ch, FILE *f)//发送数据
//   {
//      USART_SendData(USART1, (unsigned char) ch);// USART1 可以换成 USART1 等
//      while (!(USART1->SR & USART_FLAG_TXE));
//      return (ch);
//   }
// 
// int fgetc(FILE *f) // 接收数据
//  { 
//      while (!(USART1->SR & USART_FLAG_RXNE));
//      return ((int)(USART1->DR & 0x1FF));
//   } 
//如果要使用printf函数除了#include<stdio.h>和重定义两个输入输出函数外还应该Target->Code Generation中勾选Use MicroLIB 
//char ch='E',str[10]={"FGHIJKLM"};
//int intd=12345;
//printf("The is a example!\n");
//printf("%c\n%s\n%d\n%c\n%s\n%d\n%d\n",'A',"BCD",0x23,ch,str,ch,intd);
//The is a example!
//A
//BCD
//35
//E
//FGHIJKLM
//69
//12345
/*******************************************************************************
* Function Name  : USART_Scanf_Name
* Description    : Gets Char values from the hyperterminal.
* Input          : None
* Output         : None
* Return         : Length
*******************************************************************************/
//int USART_Scanf_Name(char * str)
//{	
//    u16 index = 0;
//	  USART_ClearFlag(USART1,USART_FLAG_RXNE);//清一下接收标志位
//    while(1) 
//    {
//        /* Loop until RXNE = 1 */
//        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET){}//等待直到有数据的到来
//        
//		  str[index++] = (USART_ReceiveData(USART1));
//	    printf("%c",str[index - 1]);//返回输入的内容
//	    if(str[index - 1] == 0x0d)//回车键\r
//	    {  
//	        index--;//去掉回车符并以\0结尾
//			    str[index] ='\0';//结束符号
//	        return index;
//        }
//    }													
//}

