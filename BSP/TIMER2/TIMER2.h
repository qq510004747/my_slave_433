#ifndef __TIM2_Dirver_H
#define __TIM2_Dirver_H
#include "main.h"



/****************************************************************/
//! timer2/1KHz timer
#define TIMER2_RCC_APB1Periph			RCC_APB1Periph_TIM2
#define TIMER2_TIMER					TIM2
#define TIMER2_IRQn              		TIM2_IRQn
#define TIMER2_TIMER_IRQHandler       	TIM2_IRQHandler

/****************************************************************/
//! timer2
void timer2Init(uint16_t ms);


#endif
