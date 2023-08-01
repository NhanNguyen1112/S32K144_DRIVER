
#ifndef __Clock__
#define __Clock__

#include "S32K144.h"

void Fast_IRC_Clock(void);
void Slow_IRC_Clock(void);
void Run_Mode_Clock(void);
void CheckClock(void);
void EnableClockPortA(const unsigned char Status);
void EnableClockPortB(const unsigned char Status);
void EnableClockPortC(const unsigned char Status);
void EnableClockPortD(const unsigned char Status);
void EnableClockPortE(const unsigned char Status);

#endif
