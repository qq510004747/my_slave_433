#include "TIMER3.h"
#include "RF.h"

//////////////////////////////////////////////////////////////////////////////////   	 

//bit0：温湿度
//bit1:浸水+拨码开关

//通用定时器3中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!
//arr = 9,psc = 7999 设定时间 = 1ms
//arr = 9999,psc = 7999 设定时间 = 1s
static uint16_t Run_Tim3_Flag,Run_LED_Flag = 0;
static uint16_t Bad_Cnt_Tim3_Flag = 0;
static uint64_t timer3SysRunTime = 0;
static uint32_t timer3Delay1000ms = 0;
static uint16_t ADC_SHOW_Flag = 0;
#define KM_OPEN_DURATION_TIME 5000
void TIM3_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能

	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //使能指定的TIM3中断,允许更新中断
	
	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;  //从优先级4级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器

	TIM_Cmd(TIM3, ENABLE);  //使能TIMx					 
	}
//定时器3中断服务程序
void TIM3_IRQHandler(void)   //TIM3中断
{
	ADC_SHOW_Flag = ADC_SHOW_Flag;
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //清除TIMx更新中断标志 
//************************************************************************************************
		if(Run_Tim3_Flag>300)
		{
//			PCout(0) = ~ PCout(0);
//			PCout(1) = ~ PCout(1);
			Run_Tim3_Flag =0;
		}
		else
		{
			Run_Tim3_Flag ++;
		}
		
//********************************************************************************************
		if(Run_LED_Flag>500)
		{ 
			ADC_SHOW_Flag = 1;
			Run_LED_Flag =0;
		}
		else
		{
			Run_LED_Flag ++;
		}
	//本机触发判断 
//************************************************************************************
//		if((ch1_time >= 1000))
//		{
//			ch1_time =0;
//			SWD_1 = 0;
//			current_node.trigger_vehicle1 = 0;
//		}
//		else if((SWD_1 == 1)||(SW_IN_1 == 0))
//		{
//			ch1_time = 0;
//			current_node.trigger_vehicle1 = 1;
//		}
//		else if(((ch1_time < 1000)&&(SW_IN_1 == 1)))
//		{
//			ch1_time ++;
//		}
//************************************************************************************
		if((ch1_time >= 5000))
		{
			ch1_time =0;
			current_node.trigger_vehicle1 = 0;
		}
		else if(current_node.trigger_vehicle1 == 1)
		{
			ch1_time ++;
		}
		
		if(SWD_1 == 1) 
		{
			ch1_time =0;
			SWD_1 = 0;
		}
//************************************************************************************
		if((ch2_time >= 5000))
		{
			ch2_time =0;
			current_node.trigger_video2 = 0;
		}
		else if(current_node.trigger_video2 == 1)
		{
			ch2_time ++;
		}
		if(SWD_2 == 1) 
		{
			ch2_time =0;
			SWD_2 = 0;
		}
//************************************************************************************
		if((ch3_time >= 5000))
		{
			ch3_time =0;
			current_node.trigger_microwave3 = 0;
		}
		else if(current_node.trigger_microwave3 == 1)
		{
			ch3_time ++;
		}
		if(SWD_3 == 1) 
		{
			ch3_time =0;
			SWD_3 = 0;
		}
//************************************************************************************
		if((ch4_time >= 5000))
		{
			ch4_time =0;
			current_node.trigger_reserve1 = 0;
		}
		else if(current_node.trigger_reserve1 == 1)
		{
			ch4_time ++;
		}
		if(SWD_4 == 1) 
		{
			ch4_time =0;
			SWD_4 = 0;
		}

//************************************************************************************
//		if((ch2_time >= 30000))
//		{
//			ch2_time =0;
//			SWD_2 = 0;
//			current_node.trigger_video2 = 0;
//		}
//		else if((ch2_time < 30000)&&(current_node.trigger_video2 == 1))
//		{
//			current_node.trigger_video2 = 1;
//			SWD_2 = 0;
//			ch2_time = 0;
//			ch2_time ++;
//		}
//		else if((ch2_time < 30000)&&(current_node.trigger_video2 == 1))
//		{
//			ch2_time ++;
//		}
////************************************************************************************
//		if((ch3_time >= 30000))
//		{
//			ch3_time =0;
//			SWD_3 = 0;
//			current_node.trigger_microwave3 = 0;
//		}
//		else if((ch3_time < 30000)&&(current_node.trigger_microwave3 == 1))
//		{
//			current_node.trigger_microwave3 = 1;
//			SWD_3 = 0;
//			ch3_time = 0;
//			ch3_time ++;
//		}
//		else if((ch3_time < 30000)&&(current_node.trigger_microwave3 == 1))
//		{
//			ch3_time ++;
//		}
////*************************************************************************************
//		if((ch4_time >= 30000))
//		{
//			ch4_time =0;
//			SWD_4 = 0;
//			current_node.trigger_reserve1 = 0;
//		}
//		else if((ch4_time < 30000)&&(current_node.trigger_reserve1 == 1))
//		{
//			current_node.trigger_reserve1 = 1;
//			SWD_4 = 0;
//			ch4_time = 0;
//			ch4_time ++;
//		}
//		else if((ch4_time < 30000)&&(current_node.trigger_reserve1 == 1))
//		{
//			ch4_time ++;
//		}
		//输出
//uint16_t km1_time = 0;
//uint16_t km2_time = 0;
//uint16_t km3_time = 0;
//uint16_t km4_time = 0;
//uint16_t km5_time = 0;
//uint16_t km6_time = 0;
//uint16_t km7_time = 0;
//uint16_t km8_time = 0;
//*************************************************************************************
//		if(km1_time >= 30000)//(&&(current_node.spikelamp_switch1 == 1))
//		{
//			km1_time =0;
//			KM_1 = 0;
//			current_node.spikelamp_switch1 = 0;
//		}
//		else if((km1_time < 30000)&&(current_node.spikelamp_switch1 == 1))
//		{
//			KM_1 = 1;
//			current_node.spikelamp_switch1 = 0;
//			km1_time = 0;
//			km1_time ++;
//		}
//		else if((km1_time < 30000)&&(current_node.spikelamp_switch1 == 0))
//		{
//			KM_1 = 1;
//			ch4_time ++;
//		}
////*************************************************************************************
//		if(km2_time >= 30000)//(&&(current_node.spikelamp_switch1 == 1))
//		{
//			km2_time =0;
//			KM_2 = 0;
//			current_node.voice_switch2 = 0;
//		}
//		else if((km2_time < 30000)&&(current_node.voice_switch2 == 1))
//		{
//			KM_2 = 1;
//			current_node.voice_switch2 = 0;
//			km2_time = 0;
//			km2_time ++;
//		}
//		else if((km2_time < 30000)&&(current_node.voice_switch2 == 0))
//		{
//			KM_2 = 1;
//			km2_time ++;
//		}
////*************************************************************************************	
//		if(km3_time >= 30000)//(&&(current_node.led_switch3 == 1))
//		{
//			km3_time =0;
//			KM_3 = 0;
//			current_node.led_switch3 = 0;
//		}
//		else if((km3_time < 30000)&&(current_node.led_switch3 == 1))
//		{
//			KM_3 = 1;
//			current_node.led_switch3 = 0;
//			km3_time = 0;
//			km3_time ++;
//		}
//		else if((km3_time < 30000)&&(current_node.led_switch3 == 0))
//		{
//			KM_3 = 1;
//			km3_time ++;
//		}
////*************************************************************************************	
//		if(km4_time >= 30000)//(&&(current_node.reserve1_switch == 1))
//		{
//			km4_time =0;
//			KM_4 = 0;
//			current_node.reserve1_switch = 0;
//		}
//		else if((km4_time < 30000)&&(current_node.reserve1_switch == 1))
//		{
//			KM_4 = 1;
//			current_node.reserve1_switch = 0;
//			km4_time = 0;
//			km4_time ++;
//		}
//		else if((km4_time < 30000)&&(current_node.reserve1_switch == 0))
//		{
//			KM_4 = 1;
//			km4_time ++;
//		}
////*************************************************************************************	
//		if(km5_time >= 30000)//(&&(current_node.reserve1_switch == 1))
//		{
//			km5_time =0;
//			KM_5 = 0;
//			current_node.reserve1_switch = 0;
//		}
//		else if((km5_time < 30000)&&(current_node.reserve2_switch == 1))
//		{
//			KM_5 = 1;
//			current_node.reserve2_switch = 0;
//			km5_time = 0;
//			km5_time ++;
//		}
//		else if((km5_time < 30000)&&(current_node.reserve2_switch == 0))
//		{
//			KM_5 = 1;
//			km5_time ++;
//		}
////*************************************************************************************	
//		if(km6_time >= 30000)//(&&(current_node.reserve1_switch == 1))
//		{
//			km6_time =0;
//			KM_6 = 0;
//			current_node.reserve3_switch = 0;
//		}
//		else if((km6_time < 30000)&&(current_node.reserve3_switch == 1))
//		{
//			KM_6 = 1;
//			current_node.reserve1_switch = 0;
//			km6_time = 0;
//			km6_time ++;
//		}
//		else if((km6_time < 30000)&&(current_node.reserve3_switch == 0))
//		{
//			KM_6 = 1;
//			km6_time ++;
//		}
////*************************************************************************************	
//		if(KM_spikelamp_switch1 == 1) 
//		{
//			KM_1 = 0;
//			km1_time =0;
//			KM_spikelamp_switch1 = 0;
//		}
		if((km1_time >= KM_OPEN_DURATION_TIME))
		{
			KM_1 = 1;
			km1_time =0;
		}
		else if(KM_1 == 0)
		{
			km1_time ++;
		}
		if(current_node.spikelamp_switch1 == 1)
		{
			km1_time = 0;
		}
//		printf("KM_1 %d:  \n",(uint8_t)KM_1);
//		printf("current_node.spikelamp_switch1 %d:  \n",(uint8_t)current_node.spikelamp_switch1);
//		printf("km1_time %d:  \n",(uint8_t)km1_time);		
//*************************************************************************************		
//		if(KM_voice_switch2 == 1) 
//		{
//			KM_2 = 0;
//			km2_time =0;
//			KM_voice_switch2 = 0;
//		}
		if((km2_time >= KM_OPEN_DURATION_TIME))
		{
			KM_2 = 1;
			km2_time =0;
		}
		else if((uint8_t)KM_2 == 0)
		{
			km2_time ++;
		}
		if(current_node.voice_switch2 == 1)
		{
			km2_time = 0;
		}
//*************************************************************************************	
		if((km3_time >= KM_OPEN_DURATION_TIME))
		{
			KM_3 = 1;
			km3_time =0;
		}
		else if((uint8_t)KM_3 == 0)
		{
			km3_time ++;
		}
		if(current_node.led_switch3 == 1)
		{
			km3_time = 0;
		}
//*************************************************************************************	
		if((km4_time >= KM_OPEN_DURATION_TIME))
		{
			KM_4 = 1;
			km4_time =0;
		}
		else if((uint8_t)KM_4 == 0)
		{
			km4_time ++;
		}
		if(current_node.reserve1_switch == 1)
		{
			km4_time = 0;
		}
//*************************************************************************************	
		if((km5_time >= KM_OPEN_DURATION_TIME))
		{
			KM_5 = 1;
			km5_time =0;
		}
		else if((uint8_t)KM_5 == 0)
		{
			km5_time ++;
		}
		if(current_node.reserve2_switch == 1)
		{
			km5_time = 0;
		}
//*************************************************************************************	
		if((km6_time >= KM_OPEN_DURATION_TIME))
		{
			KM_6 = 1;
			km6_time =0;
		}
		else if((uint8_t)KM_6 == 0)
		{
			km6_time ++;
		}
		if(current_node.reserve3_switch == 1)
		{
			km6_time = 0;
		}
		

//*************************************************************************************			
		if(Bad_Cnt_Tim3_Flag>1000)
		{
			if(current_node.bad_cnt>254)
			{
				current_node.bad_cnt = 254;
			}
				
			else
			{
				current_node.bad_cnt++;
				Bad_Cnt_Tim3_Flag =0;
			}
			
		}
		else
		{
			Bad_Cnt_Tim3_Flag ++;
		}
//**************************************************************************************
		
		
		if((timer3SysRunTime > LED_Lingt_Flash_Timer)&&(LED_Lingt_Flash_Faster))
		{
			timer3SysRunTime = 0;
			KM_7 =~ KM_7;
		}
		else
		{
			timer3SysRunTime++;
		} 
//**************************************************************************************
	}
}

