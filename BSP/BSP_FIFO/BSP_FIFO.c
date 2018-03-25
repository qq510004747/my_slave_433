
#include "BSP_FIFO.h"
#include "main.h"

uint8_t buf_flags;
static uint8_t buffer[FIFO_BUF_SIZE];
static uint16_t  in_index, out_index;



/**
  * @brief  Write n data to buffer
  * @retval None
  */
uint16_t fifoPushBuf(uint8_t *data, uint16_t n)
{
	uint16_t i = 0;
	uint16_t data_count = 0;

	while (n--) {
		/* If buffer overflowed, drop new data */
		if (buf_flags & OVREFLOW_FLAG) {
			//return OVFERR;
			return 0;
		} else {
			buffer[in_index++] = data[i++];
			in_index &= FIFO_BUF_MASK;
			/* Clear overflow flag */
			buf_flags &= ~EMPTY_FLAG;
			data_count++;
			/* Set overflow flag */
			if (in_index == out_index) {
				buf_flags |= OVREFLOW_FLAG;
			}
		}
	}
	return data_count;
}



/**
  * @brief  Flush buffer
  * @retval None
  */
void fifoFlushBuf(void)
{
	out_index = in_index;
	/* Set empty flag */
	buf_flags |= EMPTY_FLAG;
}



/**
  * @brief  Read n data from buffer
  * @retval None
  */
uint16_t fifoPopBuf(uint8_t *out_buf, uint16_t n)
{
	uint16_t i = 0;
	uint16_t data_count = 0;

	while (n--) {
		/* Buffer is overflowed or empty */
		if (out_index == in_index) {
			if (!(buf_flags & OVREFLOW_FLAG)) {
				/* Buffer is empty */
				buf_flags |= EMPTY_FLAG;
				//return EMPTERR;
				return 0;
			}
		}
		out_buf[i++] = buffer[out_index++];
		out_index &= FIFO_BUF_MASK;
		data_count++;
		/* Clear overflow flag */
		buf_flags &= ~OVREFLOW_FLAG;
	}
	return data_count;
}



/**
  * @brief  Get unread data count in buffer
  * @retval None
  */
uint16_t fifoGetBufDataCount(void)
{
	/* Check if buffer is overflowed or empty */
	if (out_index == in_index) {
		if (!(buf_flags & OVREFLOW_FLAG)) {
			/* Buffer is empty */
			buf_flags |= EMPTY_FLAG;
			return 0;
			
		} else {
			return FIFO_BUF_SIZE;
		}
	}
	if (in_index > out_index) {
		return in_index - out_index;
		
	} else {
		return FIFO_BUF_SIZE - out_index + in_index;
	}
}



/**
  * @brief  Look data in buffer, but not read out
  * @retval None
  */
void fifoLookBuf(uint8_t *out_buf)
{
	uint8_t i = 0;

	while (i < FIFO_BUF_SIZE) {
		out_buf[i] = buffer[i];
		i++;
	}
}

