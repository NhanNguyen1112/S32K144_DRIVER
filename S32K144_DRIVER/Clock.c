
#include "Clock.h"

void EnableClockPortA(const unsigned char Status)
{
  if(Status==Enable) SETBIT(PCC->PCC_PORTA,0x1u,30);
  else CLEARBIT(PCC->PCC_PORTA,0x1u,30);
}

void EnableClockPortB(const unsigned char Status)
{
  if(Status==Enable) SETBIT(PCC->PCC_PORTB,0x1u,30);
  else CLEARBIT(PCC->PCC_PORTB,0x1u,30);
}

void EnableClockPortC(const unsigned char Status)
{
  if(Status==Enable) SETBIT(PCC->PCC_PORTC,0x1u,30);
  else CLEARBIT(PCC->PCC_PORTC,0x1u,30);
}

void EnableClockPortD(const unsigned char Status)
{
  if(Status==Enable) SETBIT(PCC->PCC_PORTD,0x1u,30);
  else CLEARBIT(PCC->PCC_PORTD,0x1u,30);
}

void EnableClockPortE(const unsigned char Status)
{
  if(Status==Enable) SETBIT(PCC->PCC_PORTE,0x1u,30);
  else CLEARBIT(PCC->PCC_PORTE,0x1u,30);
}

