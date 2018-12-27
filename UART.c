#include <stdint.h>
#include "UART_cfg.h"
#include "UART.h"
#include "GPIO.h"
#include "M4MemMap.h"

typedef volatile uint32_t* const UART_RegAddType ;

#define UART0_BASE_ADDRESS 0x4000C000
#define UARTDR_OFFSET 0x000
#define UARTRSR_OFFSET 0x004
#define UARTFR_OFFSET 0x018
#define UARTILPR_OFFSET 0x020
#define UARTIBRD_OFFSET 0x024
#define UARTFBRD_OFFSET 0x028
#define UARTLCRH_OFFSET 0x02c
#define UARTCTL_OFFSET 0x030
#define UARTIFLS_OFFSET 0x034
#define UARTIM_OFFSET 0x038
#define UARTRIS_OFFSET 0x03c
#define UARTMIS_OFFSET 0x40
#define UARTICR_OFFSET 0x044
#define UARTDMACTL_OFFSET 0x048
#define UARTLINEPITADDR_OFFSET 0x0A4
#define UART9BITAMASK_OFFSET 0x0A8
#define UARTPP_OFFSET 0xfc0
#define UARTCC_OFFSET 0xfc8
#define UARTPERIPHLD4_OFFSET 0xfd0
#define UARTPERIPHLD5_OFFSET 0xfd4
#define UARTPERIPHLD6_OFFSET 0xfd8
#define UARTPERIPHLD7_OFFSET 0xfdc
#define UARTPERIPHLD0_OFFSET 0xfe0
#define UARTPERIPHLD1_OFFSET 0xfe4
#define UARTPERIPHLD2_OFFSET 0xfe8
#define UARTPERIPHLD3_OFFSET 0xfec
#define UARTCELLLD0_OFFSET 0xFF0
#define UARTCELLLD1_OFFSET 0xFF4
#define UARTCELLLD2_OFFSET 0xFF8
#define UARTCELLLD3_OFFSET 0xFFc
#define CH_ID 0
#define UART_MAX_CH_NUM 8u

#if UART_CHANNELS_NUM>UART_MAX_CH_NUM
#warning "Invalid Channel Number"
#endif // UART_CHANNELS_NUM

#define UARTDR(Ch_ID)           *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTDR_OFFSET))
#define UARTRSR(Ch_ID)          *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTRSR_OFFSET))
#define UARTFR(Ch_ID)           *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTFR_OFFSET))
#define UARTILPR(Ch_ID)         *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTILPR_OFFSET))
#define UARTFBRD(Ch_ID)         *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTFBRD_OFFSET))
#define UARTIBRD(Ch_ID)         *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTIBRD_OFFSET))
#define UARTLCRH(Ch_ID)         *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTLCRH_OFFSET))
#define UARTCTL(Ch_ID)          *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTCTL_OFFSET))
#define UARTIFLS(Ch_ID)         *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTIFLS_OFFSET))
#define UARTIM(Ch_ID)           *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTIM_OFFSET))
#define UARTRIS(Ch_ID)          *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTRIS_OFFSET))
#define UARTMIS(Ch_ID)          *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTMIS_OFFSET))
#define UARTICR(Ch_ID)          *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTICR_OFFSET))
#define UARTDMACTL(Ch_ID)       *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTDMACTL_OFFSET))
#define UARTLINEPITADDR(Ch_ID)  *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTLINEPITADDR_OFFSET))
#define UART9BITAMASK(Ch_ID)    *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UART9BITAMASK_OFFSET))
#define UARTPP(Ch_ID)           *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTPP_OFFSET))
#define UARTCC(Ch_ID)           *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTCC_OFFSET))
#define UARTPERIPHLD4(Ch_ID)    *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) +  UARTPERIPHLD4_OFFSET))
#define UARTPERIPHLD5(Ch_ID)    *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTPERIPHLD5_OFFSET))
#define UARTPERIPHLD6(Ch_ID)    *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTPERIPHLD6_OFFSET))
#define UARTPERIPHLD7(Ch_ID)    *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTPERIPHLD7_OFFSET))
#define UARTPERIPHLD0(Ch_ID)    *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTPERIPHLD0_OFFSET))
#define UARTPERIPHLD1(Ch_ID)    *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTPERIPHLD1_OFFSET))
#define UARTPERIPHLD2(Ch_ID)    *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTPERIPHLD2_OFFSET))
#define UARTPERIPHLD3(Ch_ID)    *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTPERIPHLD3_OFFSET))
#define UARTCELLLD0(Ch_ID)      *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTCELLLD0_OFFSET))
#define UARTCELLLD1(Ch_ID)      *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTCELLLD1_OFFSET))
#define UARTCELLLD2(Ch_ID)      *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTCELLLD2_OFFSET))
#define UARTCELLLD3 (Ch_ID)     *((UART_RegAddType) (UART0_BASE_ADDRESS + (0x1000*CH_ID) + UARTCELLLD3_OFFSET))

#define UART_WLEN 5u
#define UART_FEN  4u
#define UART_STP2 3u
#define UART_EPS  2u

#define UART_PEN  1u
#define UART_TXEN 8u
#define UART_RXEN 9u

#define UART_TXRIS 5u
#define UART_RXRIS 4u
#define UART_STATE_UNINIT        0x00
#define UART_STATE_INIT          0x01
#define UART_STATE_TX_INPROGRESS 0x02
#define UART_STATE_RX_INPROGRESS 0x04
#define UART_STATE_TX_DONE       0x08
#define UART_STATE_RX_DONE       0x10

typedef struct
{
	uint8_t TxChannelVal;
	uint8_t RxChannelVal;
}GpioAlternFunc;
static const GpioAlternFunc UartChannelsAlternFun[UART_MAX_CH_NUM]
= {{0x01,0x01},
   {0x02,0x02},
   {0x01,0x01},
   {0x01,0x01},
   {0x01,0x01},
   {0x01,0x01},
   {0x01,0x01},
   {0x01,0x01}};

static void TxManage(uint8_t ChannelId);
static void RxManage(uint8_t ChannelId);

static uint8_t UartDriverState[UART_CHANNELS_NUM] = {0};
static uint32_t UartTxLength[UART_MAX_CH_NUM];
static uint32_t UartTxCount[UART_MAX_CH_NUM];
static const uint8_t* UartTxBuffPtr[UART_MAX_CH_NUM];
static uint32_t UartRxLength[UART_MAX_CH_NUM];
static uint32_t UartRxCount[UART_MAX_CH_NUM];
static uint8_t* UartRxBuffPtr[UART_MAX_CH_NUM];
//Initialization
UART_ChkType UART_Init(void)
{
	UART_ChkType RetVar;
	const UART_ConfigType* CfgPtr;
	uint8_t ErrorFlag = 0;
	uint8_t LoopIndex;
	uint32_t TempVar;
	double BaudRateDev;
	for(LoopIndex =0; (LoopIndex < UART_CHANNELS_NUM) && (ErrorFlag == 0); LoopIndex ++)
	{
		CfgPtr = &UART_ConfigParam[LoopIndex];
		/*Checking for a valid configuration*/
		if((CfgPtr->UARTID < UART_MAX_CH_NUM) &&
		(CfgPtr->DataSize <= DATA_9) &&
		(CfgPtr->Parity <= PARITY_ODD) &&
		(CfgPtr->StopBits <=STOP_TWO) &&
		(CfgPtr->RxFifoSize <= NO_FIFO) &&
		(CfgPtr->TxFifoSize <= NO_FIFO))
		{
			/*Enable the GPIO Group*/
			GPIO_SetAlternFuntion(CfgPtr->TxPinChannelID,UartChannelsAlternFun[CfgPtr->UARTID].TxChannelVal);
			GPIO_SetAlternFuntion(CfgPtr->RxPinChannelID,UartChannelsAlternFun[CfgPtr->UARTID].RxChannelVal);
			/*Enable the Uart Clk gate*/
			RCGCUART_REG |= 1 << CfgPtr->UARTID;
			UARTCTL(CfgPtr->UARTID) = 0x00;
			BaudRateDev = 16000000.0/CfgPtr->BaudRate/16.0;
			UARTIBRD(CfgPtr->UARTID) = (uint32_t) BaudRateDev;
			BaudRateDev -=(uint32_t) BaudRateDev;
			UARTFBRD(CfgPtr->UARTID) = (uint32_t)((BaudRateDev * 64) + 0.5);
			/*init the UART Setting*/
			TempVar = 0x00;
			TempVar |= (CfgPtr->DataSize << UART_WLEN);
			TempVar |= (CfgPtr->StopBits << UART_STP2);
			TempVar |= (CfgPtr->Parity << UART_PEN);
			if((CfgPtr->TxFifoSize != NO_FIFO) ||
			(CfgPtr->RxFifoSize !=  NO_FIFO))
			{
				TempVar |= 1 << UART_FEN;
			}
			UARTLCRH(CfgPtr->UARTID) = TempVar;
			/*init the UARTIFLS*/
/*			TempVar = 0x00;
			TempVar |= (0x04 - (CfgPtr->TxFifoSize));
			TempVar |= (CfgPtr->RxFifoSize << 3);
			UARTIFLS(CfgPtr->UARTID) = TempVar;
*/			/*Enable interrupt masks*/
			#if(UART_USE_INT_TO_HANDLE == 1)
			UARTIM(CfgPtr->UARTID) = 0x30;
			#endif
			/*Enable UART*/
			UARTCTL(CfgPtr->UARTID) = 0x01;
			/*Change the UART State*/
			UartDriverState[LoopIndex] = UART_STATE_INIT;
			RetVar = UART_OK;
		}
		else
		{
			RetVar = UART_NOK;
			ErrorFlag = 1;
		}

	}
	return RetVar;
}

////init end
/*A function to Request a silent transmission*/
UART_ChkType UART_StartSilentTransmission (const uint8_t* TxBuffPtr,uint32_t TxLength, uint8_t ChannelId)
{
	UART_ChkType RetVar;
	/*Check the validity of channel ID*/
	if(ChannelId < UART_CHANNELS_NUM)
	{
		/*Check if the channel Ready to start transmission*/
		if(UartDriverState[ChannelId] == UART_STATE_INIT)
		{
			UARTCTL(UART_ConfigParam[ChannelId].UARTID) |= 1 << UART_TXEN;
			/*Init the global parameters*/
			UartTxLength[ChannelId] = TxLength;
			UartTxBuffPtr[ChannelId] = TxBuffPtr;
			UartTxCount[ChannelId] = 0;
			UartDriverState[ChannelId] |= UART_STATE_TX_INPROGRESS;
			/*Start the transmission*/
			UARTDR(UART_ConfigParam[ChannelId].UARTID) = *(UartTxBuffPtr[ChannelId] + UartTxCount[ChannelId]);
			RetVar = UART_OK;
		}

	}
	else
	{
		RetVar = UART_NOK;
	}
	return RetVar;
}

UART_ChkType UART_StopCrntTransmission(uint8_t ChannelId)
{
	UART_ChkType RetVar;
	/*Check the validity of channel ID*/
	if(ChannelId < UART_MAX_CH_NUM)
	{
		/*Check if the transmission is already in progress*/
		if((UartDriverState[ChannelId] & UART_STATE_TX_INPROGRESS) == UART_STATE_TX_INPROGRESS)
		{
			UARTCTL(ChannelId) &= ~(1 << UART_TXEN);
			UartDriverState[ChannelId] &= ~(UART_STATE_TX_INPROGRESS);
			RetVar = UART_OK;
		}
		else
		{
			RetVar = UART_NOK;
		}


	}
	else
	{
		RetVar = UART_NOK;
	}
	return RetVar;
}

/*A function to get number of transmitted bytes in an ongoing transmission*/
UART_ChkType UART_GetNumberOfTxBytes(uint8_t ChannelID,uint32_t* NumPtr)
{
	UART_ChkType RetVar;
	/*Check the validity of channel ID*/
	if(ChannelID < UART_MAX_CH_NUM)
	{
		/*Check if the channel is in progress*/
		if(((UartDriverState[ChannelID] & UART_STATE_TX_INPROGRESS) == UART_STATE_TX_INPROGRESS) ||
		((UartDriverState[ChannelID] & UART_STATE_TX_DONE) == UART_STATE_TX_DONE))
		{
			*NumPtr = UartTxCount[0];
			RetVar = UART_OK;

		}
		else
		{
			RetVar = UART_NOK;
		}
	}
	else
	{
		RetVar = UART_NOK;
	}
	return RetVar;
}
/*A function to Request a silent Reception*/
UART_ChkType UART_StartSilentReception(uint8_t* RxBuffPtr,uint32_t RxLength,uint8_t ChannelId)
{
	UART_ChkType RetVar;
	/*Check the validity of channel ID*/
	if(ChannelId < UART_MAX_CH_NUM)
	{
		/*Check if the channel Ready to start transmission*/
		if(UartDriverState[ChannelId] == UART_STATE_INIT)
		{
			UARTCTL(ChannelId) |= 1 << UART_RXEN;
			/*Init the global parameters*/
			UartRxLength[ChannelId] = RxLength;
			UartRxBuffPtr[ChannelId] = RxBuffPtr;
			UartRxCount[ChannelId] = 0;
			UartDriverState[ChannelId] |= UART_STATE_RX_INPROGRESS;
			RetVar = UART_OK;
		}

	}
	else
	{
		RetVar = UART_NOK;
	}
	return RetVar;
}

/*A function to stop a current Reception*/
UART_ChkType UART_StopCrntReception(uint8_t ChannelId)
{
	UART_ChkType RetVar;
	/*Check the validity of channel ID*/
	if(ChannelId < UART_MAX_CH_NUM)
	{
		/*Check if the transmission is already in progress*/
		if((UartDriverState[ChannelId] & UART_STATE_RX_INPROGRESS) == UART_STATE_RX_INPROGRESS)
		{
			UARTCTL(ChannelId) &= ~(1 << UART_RXEN);
			UartDriverState[ChannelId] &= ~(UART_STATE_RX_INPROGRESS);
			RetVar = UART_OK;
		}
		else
		{
			RetVar = UART_NOK;
		}


	}
	else
	{
		RetVar = UART_NOK;
	}
	return RetVar;
}

/*A function to Get the number of received bytes in an ongoing reception*/
UART_ChkType UART_GetNumberOfRxBytes(uint8_t ChannelID,uint32_t* NumPtr)
{
	UART_ChkType RetVar;
	/*Check the validity of channel ID*/
	if(ChannelID < UART_MAX_CH_NUM)
	{
		/*Check if the channel is in progress*/
		if(((UartDriverState[ChannelID] & UART_STATE_RX_INPROGRESS) == UART_STATE_RX_INPROGRESS) ||
		((UartDriverState[ChannelID] & UART_STATE_RX_DONE) == UART_STATE_RX_DONE))
		{
			*NumPtr = UartRxCount[0];
			RetVar = UART_OK;

		}
		else
		{
			RetVar = UART_NOK;
		}
	}
	else
	{
		RetVar = UART_NOK;
	}
	return RetVar;
}

/*A function manage transmission and recpetion handling*/
#if (UART_USE_INT_TO_HANDLE == 0)
UART_ChkType UART_ManageOngoingOperation(uint8_t ChannelId)
{
	UART_ChkType RetVar;
	/*Check the validity of channel ID*/
	if(ChannelId < UART_MAX_CH_NUM)
	{
		TxManage(ChannelId);
		RxManage(ChannelId);
		RetVar = UART_OK;
	}
	else
	{
		RetVar = UART_NOK;
	}

	return RetVar;
}
static void TxManage(uint8_t ChannelId)
{
	if((UartDriverState[ChannelId] & UART_STATE_TX_INPROGRESS) == UART_STATE_TX_INPROGRESS)
	{
		/*Check if a byte transmitted or not*/
		if((UARTRIS(ChannelId) & UART_TXRIS) == UART_TXRIS)
		{
			/*Clear interrupt flag*/
			UARTICR(ChannelId) |= UART_TXRIS;
			/*Check if tx done*/
			UartTxCount[ChannelId] ++;
			if(UartTxCount[ChannelId] < UartTxLength[ChannelId])
			{
				/*Tx in progress*/
				UARTDR(ChannelId) = *(UartTxBuffPtr[ChannelId] + UartTxCount[ChannelId]);
			}
			else
			{
				/*Tx Done*/
				UartDriverState[ChannelId] &= ~(UART_STATE_TX_INPROGRESS);
				UART_ConfigParam[ChannelId].TxDoneCallBackPtr();
				UARTCTL(ChannelId) &= ~(1 << UART_TXEN);

			}

		}
	}
}

static void RxManage(uint8_t ChannelId)
{
	if((UartDriverState[ChannelId] & UART_STATE_RX_INPROGRESS) == UART_STATE_RX_INPROGRESS)
	{
		/*Check if a byte transmitted or not*/
		if((UARTRIS(ChannelId) & UART_RXRIS) == UART_RXRIS)
		{
			/*Clear interrupt flag*/
			UARTICR(ChannelId) |= UART_RXRIS;
			*(UartRxBuffPtr[ChannelId] + UartRxCount[ChannelId]) = UARTDR(ChannelId);
			/*Check if Rx done*/
			UartRxCount[ChannelId] ++;
			if(UartRxCount[ChannelId] == UartRxLength[ChannelId])
			{
				UartDriverState[ChannelId] &= ~(UART_STATE_RX_INPROGRESS);
				UART_ConfigParam[ChannelId].RxDoneCallBackPtr();
				UARTCTL(ChannelId) &= ~(1 << UART_RXEN);

			}
		}
	}
}
#endif
