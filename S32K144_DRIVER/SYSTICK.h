
#ifndef __SYSTICK__
#define __SYSTICK__

#include "S32K144.h"
#include "SYSTICK_Register.h"

#define Systick_CLK     (60000000UL)

#define SYST_RVR_ms     (Systick_CLK/1000UL)
#define SYST_RVR_us     (Systick_CLK/1000000UL)

void SysTickDelay_ms(const unsigned int Milisecond);
void SysTickDelay_us(const unsigned int MicroSecond);
void Systick_MAIN_Delay_Test(void);

#endif
