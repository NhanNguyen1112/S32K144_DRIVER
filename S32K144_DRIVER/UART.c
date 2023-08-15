
#include "UART.h"

static unsigned char ReadData=0;

void LPUART0_RxTx_IRQHandler(void)
{
	ReadData=(unsigned char)(UART0->DATA);

	UART0_WriteData(&ReadData);

	NVIC_ClearPendingFlag(LPUART0_RxTx_IRQn);
}

void UART0_MAIN_TEST(void)
{
  SOSC_Init_8Mhz();
	SPLL_Init();
  Run_Mode_Clock();
  //CheckClock();

	LPIT_Init_CH0();

	// UART0_Init_Polling();
	UART0_Init_INT();

	unsigned char DataSend[5]= {'A','B','C','D','\n'};
	unsigned char DataRead[20]={0};

	while(1)
	{
		//UART0_ReadData(DataRead);
		// LPIT_CH0_Delay_ms(100);
		// UART0_WriteMultiData(DataRead,sizeof(DataRead));


		UART0_WriteMultiData(DataSend,sizeof(DataSend));
		LPIT_CH0_Delay_ms(1000);
	}
}

static void UART0_GPIO_Config(void)
{
	EnableClockPortB(Enable);
	PORTB->PCR[0] &= ~(7u<<8);
	PORTB->PCR[0] |= (2u<<8); /* ALT 2 */

	PORTB->PCR[1] &= ~(7u<<8);
	PORTB->PCR[1] |= (2u<<8); /* ALT 2 */
}

/* PTB1-TX ; PTB0 - RX */
void UART0_Init_Polling(void)
{
  unsigned int BAUD=0;
	unsigned int CTRL=0;

	UART0_GPIO_Config();
	UART0_CLK_ENABLE(Enable,SOSCDIV2_CLK);

	BAUD &= ~(1u<<29); /* 7-9bit data */
	BAUD |= (15u<<24); /* OSR= 15 */
	BAUD |= (0x34u<<0); /* 8mhz/9600/15+1 ~= 52 */
	BAUD &= ~(1u<<13); /* 1 Stop bit */
	UART0->BAUD = BAUD;

	//CTRL |= (1u<<0); 		/* Odd Parity */
	//CTRL &= ~(1u<<0); 	/* Even Parity */
	//CTRL |= (1u<<1); 	/* Parity enable */
	CTRL |= (1u<<18) | (1u<<19); /* TX & RX enable */
	UART0->CTRL = CTRL;

}

/* PTB1-TX ; PTB0 - RX */
void UART0_Init_INT(void)
{
  unsigned int BAUD=0;
	unsigned int CTRL=0;

	UART0_GPIO_Config();
	UART0_CLK_ENABLE(Enable,SOSCDIV2_CLK);

	BAUD &= ~(1u<<29); /* 7-9bit data */
	BAUD |= (15u<<24); /* OSR= 15 */
	BAUD |= (0x34u<<0); /* 8mhz/9600/15+1 ~= 52 */
	BAUD &= ~(1u<<13); /* 1 Stop bit */
	UART0->BAUD = BAUD;

	//CTRL |= (1u<<0); 		/* Odd Parity */
	//CTRL &= ~(1u<<0); 	/* Even Parity */
	//CTRL |= (1u<<1); 	/* Parity enable */

	CTRL &= ~(1u<<11); /* 8bit-10bit Data */
	//CTRL |= (1u<<11); /* 7bit Data */

	CTRL &= ~(1u<<4); /* 8bit Data */
	//CTRL |= (1u<<4); /* 9bit Data */

	//CTRL |= (1u<<23); /* TX Enable Interrupt */
	CTRL |= (1u<<21); /* RX Enable Interrupt */

	CTRL |= (1u<<18) | (1u<<19); /* TX & RX enable */
	UART0->CTRL = CTRL;

	NVIC_SetPriority(LPUART0_RxTx_IRQn,1);
	NVIC_EnableInterrupt(LPUART0_RxTx_IRQn);
	NVIC_ClearPendingFlag(LPUART0_RxTx_IRQn);

}

void UART0_WriteData(unsigned char *Data)
{
	while( !(UART0->STAT & (1u<<23)) ); /* Wait Transmit data buffer empty */
	UART0->DATA = (unsigned int)*Data;
	while( !(UART0->STAT & (1u<<22)) ); /* transmission activity complete */
}

void UART0_WriteMultiData(unsigned char *Data, const unsigned char size)
{
	unsigned int i=0;
	for(i=0;i<size;i++)
	{
		UART0_WriteData(Data);
		Data++;
	}
}

void UART0_ReadData(unsigned char *Data)
{
	while( !(UART0->STAT & (1u<<21)) ); /* Wait Receive data buffer FULL */
	*Data = (unsigned char)(UART0->DATA);

	//UART0_WriteData(Data);
}

void UART0_ReadMultiData(unsigned char *Data, const unsigned char size)
{
	unsigned int i=0;

	while( !(UART0->STAT & (1u<<21)) ); /* Wait Receive data buffer FULL */
	for(i=0;i<size;i++)
	{
		UART0_ReadData(Data);
		Data++;
	}
	
	//UART0_WriteData(Data);
}




