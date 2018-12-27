#include "UART.h"
#include "UART_cfg.h"

UART_CallBackPtrType f;
void test(void);

const UART_ConfigType UART_ConfigParam[UART_CHANNELS_NUM] =
	{
			{
					0x00,
					0x04,0x03,
					9600,PARITY_DISABLED,STOP_ONE,DATA_8,
					test,test,test,test,test,
					NO_FIFO,NO_FIFO
			}
	};
