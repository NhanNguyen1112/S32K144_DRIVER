#ifndef __BUTTON_inc__
#define __BUTTON_inc__

#include "S32K144.h"

	/* Pin BUTTON definitions
	* ===================================================
	* Pin number        | Function
	* ----------------- |------------------
	* PTC12             | GPIO [BUTTON1]
	* PTC13             | GPIO [BUTTON2]
	*/

#define BUTTON_1 12u
#define BUTTON_2 13u

void CLOCK_PORTC_INIT(void);
void BUTTON_INIT(void);
int Read_Button_1(void);
int Read_Button_2(void);
void BUTTON_BLINK(void);

#endif
