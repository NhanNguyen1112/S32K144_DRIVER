
#include "S32K144_BUTTON.h"

	/* Pin BUTTON definitions
	* ===================================================
	* Pin number        | Function
	* ----------------- |------------------
	* PTC12             | GPIO [BUTTON1]
	* PTC13             | GPIO [BUTTON2]
	*/

/* Enable clock for PORT C*/
void CLOCK_PORTC_INIT(void)
{
	SETBIT(PCC->PCC_PORTC,0x1u,30);
}

/* INIT button 12, 13 */
void BUTTON_INIT(void)
{
	/* Enable Clock*/
	CLOCK_PORTC_INIT();
	
	/* Set MUX */
	PORTC->PCR[BUTTON_1] |= (0x01u<<8);
	PORTC->PCR[BUTTON_2] |= (0x01u<<8);
	
	/* Disable PULL */
	PORTC->PCR[BUTTON_1] &= ~(1u<<1);
	PORTC->PCR[BUTTON_2] &= ~(1u<<1);
	
	/*Set INPUT*/
	CLEARBIT(GPIOC->PDDR,1u,BUTTON_1);
	CLEARBIT(GPIOC->PDDR,1u,BUTTON_2);
}

/* Read button 1 (Pin 12, GPIO C) */
int Read_Button_1(void)
{
	return (GPIOC->PDIR & (1<<BUTTON_1));
}

/* Read button 2 (Pin 13, GPIO C) */
int Read_Button_2(void)
{
	return (GPIOC->PDIR & (1<<BUTTON_2));
}

/* Blink led + button */
void BUTTON_BLINK(void)
{
	volatile static int Button_State_1=0;
	volatile static int Button_State_2=0;
	
	Button_State_1 = Read_Button_1();
	Button_State_2 = Read_Button_2();
	
	if( Button_State_1 )
	{
		TURN_ON_LED(GREEN);
	}
	else 
	{
		TURN_OFF_LED(GREEN);
	}
	
	if( Button_State_2 )
	{
		TURN_ON_LED(RED);
	}
	else 
	{
		TURN_OFF_LED(RED);
	}
}

