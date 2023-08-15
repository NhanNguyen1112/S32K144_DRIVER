
#ifndef _LPIT_
#define _LPIT_

#include "S32K144.h"
#include "LPIT_Register.h"

void MainLPIT_Test(void);
void LPIT_Init_CH0(void);
void LPIT0_Ch0_IRQHandler(void);
void LPIT_CH0_Delay_ms(const unsigned int MiliSecond);
void LPIT_CH0_Delay_us(const unsigned int MicroSecond);

#endif

