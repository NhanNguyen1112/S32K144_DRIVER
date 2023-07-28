
#include "Gpio.h"

static void SetInput(volatile unsigned int *Register, const unsigned char Pull)
{
  CLEARBIT(*Register,7u,8u); /* Clear ALL MUX */
  CLEARBIT(*Register,3u,0u); /* Clear PULL */

  SETBIT(*Register,1u,8u); /* SET MUX GPIO */

  if(Pull==PullUp)
  {
    SETBIT(*Register,3u,0u); /* Set PullUp */
  }
  else if(Pull==PullDown)
  {
    SETBIT(*Register,2u,0u); /* Set PullUp */
  } else {}
}

void SetPinInput(const unsigned char Port, const unsigned char Pin, const unsigned char Pull)
{
  if(Port==PortA)
  {
    SetInput(&PORTA->PCR[Pin],Pull);
    CLEARBIT(GPIOA->PDDR,1u,Pin);
  }
  else if(Port==PortB)
  {
    SetInput(&PORTB->PCR[Pin],Pull);
    CLEARBIT(GPIOB->PDDR,1u,Pin);
  }
  else if(Port==PortC)
  {
    SetInput(&PORTC->PCR[Pin],Pull);
    CLEARBIT(GPIOC->PDDR,1u,Pin);
  }
  else if(Port==PortD)
  {
    SetInput(&PORTD->PCR[Pin],Pull);
    CLEARBIT(GPIOD->PDDR,1u,Pin);
  }
  else
  {
    SetInput(&PORTE->PCR[Pin],Pull);
    CLEARBIT(GPIOE->PDDR,1u,Pin);
  }
}
