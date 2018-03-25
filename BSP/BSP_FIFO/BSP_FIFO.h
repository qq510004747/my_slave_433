
#ifndef _BSP_FIFO_H
#define _BSP_FIFO_H

#include <stm32f10x.h>
#include <stdint.h> 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>



//! fifo buffer size, should be n^2 value 
#define FIFO_BUF_SIZE	128
#define FIFO_BUF_MASK	FIFO_BUF_SIZE - 1

//! Buffer state flags 
#define OVREFLOW_FLAG	0x01
#define EMPTY_FLAG		0x02

//! Buffer state register 
extern uint8_t buf_flags;



uint16_t fifoPushBuf(uint8_t *data, uint16_t n); //! write n data to buffer 
uint16_t fifoPopBuf(uint8_t *out_buf, uint16_t n); //! read n data from buffer 
void fifoFlushBuf(void); //! flush buffer 
uint16_t fifoGetBufDataCount(void); //! get unread data count in buffer 
void fifoLookBuf(uint8_t *out_buf); //! look data in buffer, but not read out 


#endif

