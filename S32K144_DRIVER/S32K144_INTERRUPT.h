
#ifndef __S32K144_INTERRUPT__
#define __S32K144_INTERRUPT__

#include "S32K144.h"

extern volatile char StateLED;

void INIT_Interrupt(void);
void PORTC_IRQHandler(void);
void Test_Led_button(void);

#endif
