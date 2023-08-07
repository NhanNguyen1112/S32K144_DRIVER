
#include "S32K144_INTERRUPT.h"

volatile char StateLED;

void INIT_Interrupt(void)
{
	/* Enable NVIC */
	/* 61-32=29 */
	NVIC->ISER[1] |= (1u<<29u);
	
	/* Config interrupt for button 1, 2 */
	PORTC->PCR[BUTTON_1] |= (0x9u<<16);
	PORTC->PCR[BUTTON_2] |= (0x9u<<16);
}

void PORTC_IRQHandler(void)
{
	if(READBIT(PORTC->PCR[BUTTON_1],24))
	{
		SETBIT(PORTC->PCR[BUTTON_1],1,24);
		StateLED = 1;
	}
	
	if(READBIT(PORTC->PCR[BUTTON_2],24))
	{
		SETBIT(PORTC->PCR[BUTTON_2],1,24);
		StateLED = 0;
	}
}

void Test_Led_button(void)
{
	if(StateLED==1) TURN_ON_LED(RED);
	else TURN_OFF_LED(RED);
}

