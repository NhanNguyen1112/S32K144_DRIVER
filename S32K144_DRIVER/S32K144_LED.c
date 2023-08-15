
#include "S32K144_LED.h"

	/* Pin LED definitions
	* ===================================================
	* Pin number        | Function
	* ----------------- |------------------
	* PTD0              | GPIO [BLUE LED]
	* PTD15             | GPIO [RED LED]
	* PTD16             | GPIO [GREEN LED]
	*/

static void delay(void)
{
	for(int i=0;i<=600000;i++);
}

/* Init Led 0, 15, 16 of PORT D */
void LED_INIT(void)
{
	/* Enable Clock*/
	EnableClockPortD(Enable);
	
	/* Set MUX */
	PORTD->PCR[LEDBLUE] 	|= (0x01u<<8); /*BLUE*/
	PORTD->PCR[LEDRED] 		|= (0x01u<<8); /*RED*/
	PORTD->PCR[LEDGREEN] 	|= (0x01u<<8); /*GREEN*/
	
	/* Clear PULL */
	PORTD->PCR[LEDBLUE]  &= ~(1u<<1); /*BLUE*/
	PORTD->PCR[LEDRED] 	 &= ~(1u<<1); /*RED*/
	PORTD->PCR[LEDGREEN] &= ~(1u<<1); /*GREEN*/
	
	/* SET GPIO OUTPUT */
	SETBIT(GPIOD->PDDR,1,LEDRED);
	SETBIT(GPIOD->PDDR,1,LEDGREEN);
	SETBIT(GPIOD->PDDR,1,LEDBLUE);
	LED_ALL_OFF();
}	

/* Turn off all led */
void LED_ALL_OFF(void)
{
	SETBIT(GPIOD->PDOR,1u,LEDRED);
	SETBIT(GPIOD->PDOR,1u,LEDGREEN);
	SETBIT(GPIOD->PDOR,1u,LEDBLUE);
}

/* Turn on all led */
void LED_ALL_ON(void)
{
	CLEARBIT(GPIOD->PDOR,1u,LEDRED);
	CLEARBIT(GPIOD->PDOR,1u,LEDGREEN);
	CLEARBIT(GPIOD->PDOR,1u,LEDBLUE);
}

/* 
Turn on 1 led 
Input: RED / GREEN / BLUE
*/
void TURN_ON_LED(LED_RGB SelectLED)
{
	if(SelectLED==RED) CLEARBIT(GPIOD->PDOR,1u,LEDRED);
	else if(SelectLED==GREEN) CLEARBIT(GPIOD->PDOR,1u,LEDGREEN);
	else CLEARBIT(GPIOD->PDOR,1u,LEDBLUE);
}

/* 
Turn off 1 led 
Input: RED / GREEN / BLUE
*/
void TURN_OFF_LED(LED_RGB SelectLED)
{
	if(SelectLED==RED) SETBIT(GPIOD->PDOR,1u,LEDRED);
	else if(SelectLED==GREEN) SETBIT(GPIOD->PDOR,1u,LEDGREEN);
	else SETBIT(GPIOD->PDOR,1u,LEDBLUE);
}

/* Blink 3 led red, green, blue */
void Blink_LED(void)
{
	TURN_ON_LED(GREEN);
	delay();
	TURN_OFF_LED(GREEN);
	
	TURN_ON_LED(RED);
	delay();
	TURN_OFF_LED(RED);
	
	TURN_ON_LED(BLUE);
	delay();
	TURN_OFF_LED(BLUE);
}

