/**
  ******************************************************************************
  * @file    spi.h
  * $Author: wdluo $
  * $Revision: 17 $
  * $Date:: 2012-07-06 11:16:48 +0800 #$
  * @brief   SPIÇý¶¯º¯ÊýÉùÃ÷.
  ******************************************************************************
  * @attention
  *
  *<h3><center>&copy; Copyright 2009-2012, ViewTool</center>
  *<center><a href="http:\\www.viewtool.com">http://www.viewtool.com</a></center>
  *<center>All Rights Reserved</center></h3>
  * 
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RADIO_DRIVER_H
#define __RADIO_DRIVER_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_conf.h"
#include "main.h"
/* Exported Functions --------------------------------------------------------*/
/****************************************************************/
//! radio

#define RADIO_GPIO_REG_M0		GPIOA
#define RADIO_GPIO_PIN_M0		GPIO_Pin_12		//! PC.04

#define RADIO_GPIO_REG_M1		GPIOA
#define RADIO_GPIO_PIN_M1		GPIO_Pin_11		//! PC.05

#define RADIO_GPIO_REG_AUX		GPIOC
#define RADIO_GPIO_PIN_AUX		GPIO_Pin_15		//! PA.08

#define RADIO_GPIO_REG_CTRL		GPIOC			//! PB.00
#define RADIO_GPIO_PIN_CTRL		GPIO_Pin_15

#define RADIO_RCC_APB2Periph   (RCC_APB2Periph_GPIOB )
#define RADIO_GPIOC_PINS		RADIO_GPIO_PIN_M0 | RADIO_GPIO_PIN_M1
#define RADIO_GPIOB_PINS		RADIO_GPIO_PIN_CTRL
#define RADIO_GPIOA_PINS		RADIO_GPIO_PIN_AUX

void radioInit(void);
void radioReset(void);
void radioSetMode(uint8_t mode);
void radioGetParameter(void);
void radioGetVersion(void);
void radioSetParameter(uint16_t addr, uint32_t baud, uint32_t sped, uint8_t chan);
static void radioSetM0M1(bool m0, bool m1);

/****************************************************************/
//! some defineds

enum RADIO_MODE {
	 RADIO_MODE_NORMAL,
	 RADIO_MODE_WAKEUP,
	 RADIO_MODE_POWER_DOWN,
	 RADIO_MODE_SLEEP
};

#endif /* __RADIO_DRIVER_H */

/*********************************END OF FILE**********************************/

