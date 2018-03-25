#include "TIMER3.h"
#include "RF.h"

//////////////////////////////////////////////////////////////////////////////////   	 

//bit0����ʪ��
//bit1:��ˮ+���뿪��

//ͨ�ö�ʱ��3�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
//arr = 9,psc = 7999 �趨ʱ�� = 1ms
//arr = 9999,psc = 7999 �趨ʱ�� = 1s
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

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʱ��ʹ��

	//��ʱ��TIM3��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //ʹ��ָ����TIM3�ж�,��������ж�
	
	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;  //�����ȼ�4��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���

	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx					 
	}
//��ʱ��3�жϷ������
void TIM3_IRQHandler(void)   //TIM3�ж�
{
	ADC_SHOW_Flag = ADC_SHOW_Flag;
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //���TIMx�����жϱ�־ 
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
	//���������ж� 
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
		//���
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

