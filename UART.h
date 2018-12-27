#ifndef UART_H
#define UART_H
#include <stdint.h>
#include "UART_cfg.h"
typedef enum {UART_OK =0, UART_NOK}UART_ChkType;
typedef enum {PARITY_DISABLED =0, PARITY_ODD = 1, PARITY_EVEN = 3} UART_ParityType;
typedef enum {STOP_ONE =0, STOP_TWO}UART_StopBitsType;
typedef enum {DATA_5=0,DATA_6=1,DATA_7=2,DATA_8=3,DATA_9=4}UART_DataSizeType;
typedef void (*UART_CallBackPtrType)(void);
typedef enum {NO_FIFO=5,FIFO_2=0,FIFO_4=1,FIFO_8=2,FIFO_12=3,FIFO_14=4}UART_FLSRX;
/*A structure type to contain all the required configuration*/
typedef struct
{
	/*UART channel ID*/
	uint8_t UARTID;
	/*Tx Pin GPIO channel ID*/
	uint8_t TxPinChannelID;
	/*Rx Pin GPIO ChannelID*/
	uint8_t RxPinChannelID;
	/*Channel BaudRate*/
	uint32_t BaudRate;
	/*Channel ParityType*/
	UART_ParityType Parity;
	/*Channel Stop Bits*/
	UART_StopBitsType StopBits;
	/*Channel frame Data Size*/
	UART_DataSizeType DataSize;
	/*Channel TxDone Callback function*/
	UART_CallBackPtrType TxDoneCallBackPtr;
	/*Channel RxDone CallBack function*/
	UART_CallBackPtrType RxDoneCallBackPtr;
	/*Channel frame error Callback function*/
	UART_CallBackPtrType FrameErrorCallBackPtr;
	/*Channel ParityError Callback function*/
	UART_CallBackPtrType ParityErrorCallBackPtr;
	/*Channel Data overrun Callback function*/
	UART_CallBackPtrType DataOverRunCallBackPtr;
	/*Channel Tx FIFO Size*/
	UART_FLSRX TxFifoSize;
	/*Channel Rx FIFO Size*/
	UART_FLSRX RxFifoSize;
	}UART_ConfigType;



extern const UART_ConfigType UART_ConfigParam[UART_CHANNELS_NUM];
/*A function to initialize all the UART channels with the configuration set in UART_Cfg*/
UART_ChkType UART_Init(void);
/*A function to Request a silent transmission*/
UART_ChkType UART_StartSilentTransmission (const uint8_t* TxBuffPtr,
		                                 uint32_t TxLength,
		                                 uint8_t ChannelId);
/*A function to stop a current transmission*/
UART_ChkType UART_StopCrntTransmission(uint8_t ChannelId);
/*A function to get number of transmitted bytes in an ongoing transmission*/
UART_ChkType UART_GetNumberOfTxBytes(uint8_t ChannelID,uint32_t* NumPtr);
/*A function to Request a silent Reception*/
UART_ChkType UART_StartSilentReception(uint8_t* RxBuffPtr,
                                       uint32_t TxLength,
                                       uint8_t ChannelId);
/*A function to stop a current Reception*/
UART_ChkType UART_StopCrntReception(uint8_t ChannelId);
/*A function to Get the number of received bytes in an ongoing reception*/
UART_ChkType UART_GetNumberOfRxBytes(uint8_t ChannelID,uint32_t* NumPtr);

/*A function manage transmission and recpetion handling*/
#if (UART_USE_INT_TO_HANDLE == 0)
UART_ChkType UART_ManageOngoingOperation(uint8_t ChannelId);
#endif
#endif
