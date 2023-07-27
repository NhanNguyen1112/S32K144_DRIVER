
#ifndef __LED_inc__
#define __LED_inc__

#include "S32K144.h"

	/* Pin LED definitions
	* ===================================================
	* Pin number        | Function
	* ----------------- |------------------
	* PTD0              | GPIO [BLUE LED]
	* PTD15             | GPIO [RED LED]
	* PTD16             | GPIO [GREEN LED]
	*/

#define LEDBLUE 0u
#define LEDRED 15u
#define LEDGREEN 16u

typedef enum 
{
	RED,
	GREEN,
	BLUE
}LED_RGB;

void CLOCK_PORTD_INIT(void);
void LED_INIT(void);
void LED_ALL_OFF(void);
void LED_ALL_ON(void);
void TURN_ON_LED(LED_RGB SelectLED);
void TURN_OFF_LED(LED_RGB SelectLED);
void Blink_LED(void);

#endif
