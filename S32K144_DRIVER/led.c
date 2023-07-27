
#include "led.h"

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

void CLOCK_PORTD_INIT(void)
{
	SETBIT(PCC_PORTD,0x1u,30);
}

void LED_INIT(void)
{
	/* Enable Clock*/
	CLOCK_PORTD_INIT();
	
	/* Set MUX */
	PORTD_PCR0 |= (0x01u<<8); /*BLUE*/
	PORTD_PCR15 |= (0x01u<<8); /*RED*/
	PORTD_PCR16 |= (0x01u<<8); /*GREEN*/
	
	/* Clear PULL */
	PORTD_PCR0 &= ~(1u<<1); /*BLUE*/
	PORTD_PCR15 &= ~(1u<<1); /*RED*/
	PORTD_PCR16 &= ~(1u<<1); /*GREEN*/
	
	/* SET GPIO OUTPUT */
	SETBIT(GPIOD->PDDR,1,LEDRED);
	SETBIT(GPIOD->PDDR,1,LEDGREEN);
	SETBIT(GPIOD->PDDR,1,LEDBLUE);
	LED_ALL_OFF();
}	

void LED_ALL_OFF(void)
{
	SETBIT(GPIOD->PDOR,1u,LEDRED);
	SETBIT(GPIOD->PDOR,1u,LEDGREEN);
	SETBIT(GPIOD->PDOR,1u,LEDBLUE);
}

void LED_ALL_ON(void)
{
	CLEARBIT(GPIOD->PDOR,1u,LEDRED);
	CLEARBIT(GPIOD->PDOR,1u,LEDGREEN);
	CLEARBIT(GPIOD->PDOR,1u,LEDBLUE);
}

void TURN_ON_LED(LED_RGB SelectLED)
{
	if(SelectLED==RED) CLEARBIT(GPIOD->PDOR,1u,LEDRED);
	else if(SelectLED==GREEN) CLEARBIT(GPIOD->PDOR,1u,LEDGREEN);
	else CLEARBIT(GPIOD->PDOR,1u,LEDBLUE);
}

void TURN_OFF_LED(LED_RGB SelectLED)
{
	if(SelectLED==RED) SETBIT(GPIOD->PDOR,1u,LEDRED);
	else if(SelectLED==GREEN) SETBIT(GPIOD->PDOR,1u,LEDGREEN);
	else SETBIT(GPIOD->PDOR,1u,LEDBLUE);
}

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
