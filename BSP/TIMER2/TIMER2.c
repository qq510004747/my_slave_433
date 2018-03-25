#include "TIMER2.h"
#include "RF.h"
static uint64_t timer2SysRunTime = 0;
static uint32_t timer2Delay1000ms = 0;





/**
  * @brief  init timer2  1ms
  * @note   
  */
void timer2Init(uint16_t ms)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(TIMER2_RCC_APB1Periph, ENABLE);
    TIM_DeInit(TIMER2_TIMER);
	TIM_TimeBaseStructure.TIM_Period = 9;		 							

	TIM_TimeBaseStructure.TIM_Prescaler = (7200-1);	//! 10KHz			           
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 		
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIMER2_TIMER, &TIM_TimeBaseStructure);
	TIM_ClearFlag(TIMER2_TIMER, TIM_FLAG_Update);							    		
	TIM_ITConfig(TIMER2_TIMER, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIMER2_TIMER, ENABLE);																		
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);	
	NVIC_InitStructure.NVIC_IRQChannel = TIMER2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	
	NVIC_Init(&NVIC_InitStructure);
}




/**
  * @brief  timer2 IRQ handler
  * @note   
  */
void TIMER2_TIMER_IRQHandler()
{
	
	if (TIM_GetITStatus(TIMER2_TIMER, TIM_IT_Update) != RESET) {   
		TIM_ClearITPendingBit(TIMER2_TIMER, TIM_IT_Update);
		
		timer2SysRunTime++;
		if(timer2SysRunTime > 1000)
		{
			timer2SysRunTime = 0;
//			KM_7 =~ KM_7;
		}
		else
		{
			timer2SysRunTime++;
		}
//		if (gRadioNoDataCnt++ == (getAnalogValue(0)&0X07)*20/*((myNode.mac[0] + myNode.mac[1] + myNode.mac[2])&0x00000007*15)*/) {	//! means have not received data more than 50ms 
//			gCanAskForIdDurNormMode = true;
//		}
		
//		if (timer2Delay1000ms++ > 1000) {
//			timer2Delay1000ms = 0;
//			if ((gNoneAskForCnt++ > MESH_TIME_MAX) && (!gMeshFinished)) {
//				gMeshFinished = true;
//			}
//		}
	}

}






/**
  * @brief  system run time (ms)
  * @note   
  */
uint64_t getSystemTime(void) 
{
	return timer2SysRunTime;
}



