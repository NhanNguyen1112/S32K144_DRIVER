
#ifndef __Clock__
#define __Clock__

#include "Clock_Register.h"
#include "S32K144.h"

typedef enum ClockSelect_enum
{
	NoClock,
	SOSCDIV2_CLK,
	SIRCDIV2_CLK,
	FIRCDIV2_CLK,
	SPLLDIV2_CLK,
	LPO128_CLK
}ClockSelect_enum;

void SOSC_Init_8Mhz(void);
void SPLL_Init(void);
void Run_Mode_Clock(void);
void CheckClock(void);
void EnableClockPortA(const unsigned char Status);
void EnableClockPortB(const unsigned char Status);
void EnableClockPortC(const unsigned char Status);
void EnableClockPortD(const unsigned char Status);
void EnableClockPortE(const unsigned char Status);
void Enable_CLK_LPIT(const unsigned char Status);
void UART0_CLK_ENABLE(const unsigned char Status, ClockSelect_enum Clock_Seclect);

#endif
