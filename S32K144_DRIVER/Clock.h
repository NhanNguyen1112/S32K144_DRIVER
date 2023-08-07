
#ifndef __Clock__
#define __Clock__

#include "S32K144.h"

void SOSC_Init_8Mhz(void);
void SPLL_Init(void);
void Run_Mode_Clock(void);
void CheckClock(void);
void EnableClockPortA(const unsigned char Status);
void EnableClockPortB(const unsigned char Status);
void EnableClockPortC(const unsigned char Status);
void EnableClockPortD(const unsigned char Status);
void EnableClockPortE(const unsigned char Status);

#endif
