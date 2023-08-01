
#include "Gpio.h"

static void SetPortGpio(volatile unsigned int *Register, const unsigned char Pull)
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
    SetPortGpio(&PORTA->PCR[Pin],Pull);
    CLEARBIT(GPIOA->PDDR,1u,Pin);
  }
  else if(Port==PortB)
  {
    SetPortGpio(&PORTB->PCR[Pin],Pull);
    CLEARBIT(GPIOB->PDDR,1u,Pin);
  }
  else if(Port==PortC)
  {
    SetPortGpio(&PORTC->PCR[Pin],Pull);
    CLEARBIT(GPIOC->PDDR,1u,Pin);
  }
  else if(Port==PortD)
  {
    SetPortGpio(&PORTD->PCR[Pin],Pull);
    CLEARBIT(GPIOD->PDDR,1u,Pin);
  }
  else
  {
    SetPortGpio(&PORTE->PCR[Pin],Pull);
    CLEARBIT(GPIOE->PDDR,1u,Pin);
  }
}

void SetPinOutput(const unsigned char Port, const unsigned char Pin, const unsigned char Pull)
{
  if(Port==PortA)
  {
    SetPortGpio(&PORTA->PCR[Pin],Pull);
    SETBIT(GPIOA->PDDR,1u,Pin);
  }
  else if(Port==PortB)
  {
    SetPortGpio(&PORTB->PCR[Pin],Pull);
    SETBIT(GPIOB->PDDR,1u,Pin);
  }
  else if(Port==PortC)
  {
    SetPortGpio(&PORTC->PCR[Pin],Pull);
    SETBIT(GPIOC->PDDR,1u,Pin);
  }
  else if(Port==PortD)
  {
    SetPortGpio(&PORTD->PCR[Pin],Pull);
    SETBIT(GPIOD->PDDR,1u,Pin);
  }
  else
  {
    SetPortGpio(&PORTE->PCR[Pin],Pull);
    SETBIT(GPIOE->PDDR,1u,Pin);
  }
}

void WritePin(const unsigned char Port, const unsigned char Pin, const unsigned char Status)
{
  if(Status==HIGH)
  {
    if(Port==PortA) SETBIT(GPIOA->PDOR,1u,Pin);
    else if(Port==PortB)  SETBIT(GPIOB->PDOR,1u,Pin);
    else if(Port==PortC)  SETBIT(GPIOC->PDOR,1u,Pin);
    else if(Port==PortD)  SETBIT(GPIOD->PDOR,1u,Pin);
    else SETBIT(GPIOE->PDOR,1u,Pin);
  }
  else 
  {
    if(Port==PortA) CLEARBIT(GPIOA->PDOR,1u,Pin);
    else if(Port==PortB)  CLEARBIT(GPIOB->PDOR,1u,Pin);
    else if(Port==PortC)  CLEARBIT(GPIOC->PDOR,1u,Pin);
    else if(Port==PortD)  CLEARBIT(GPIOD->PDOR,1u,Pin);
    else CLEARBIT(GPIOE->PDOR,1u,Pin);
  }
}

unsigned int GetPin(const unsigned char Port, const unsigned char Pin)
{
  unsigned int DataRead=0;
  if(Port==PortA) DataRead=READBIT(GPIOA->PDIR,Pin);
  else if(Port==PortB)  DataRead=READBIT(GPIOB->PDIR,Pin);
  else if(Port==PortC)  DataRead=READBIT(GPIOC->PDIR,Pin);
  else if(Port==PortD)  DataRead=READBIT(GPIOD->PDIR,Pin);
  else DataRead=READBIT(GPIOE->PDIR,Pin);
  return DataRead;
}

void TogglePin(const unsigned char Port, const unsigned char Pin)
{
  if(Port==PortA) GPIOA->PDOR ^= (1u<<Pin);
  else if(Port==PortB)  GPIOB->PDOR ^= (1u<<Pin);
  else if(Port==PortC)  GPIOC->PDOR ^= (1u<<Pin);
  else if(Port==PortD)  GPIOD->PDOR ^= (1u<<Pin);
  else GPIOA->PDOR ^= (1u<<Pin);
}

