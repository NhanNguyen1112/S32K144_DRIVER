
#include "SYSTICK.h"

void Systick_MAIN_Delay_Test(void)
{
  EnableClockPortD(Enable);
  SetPinOutput(PortD, PIN0, No);

  while(1)
  {
		TogglePin(PortD,PIN0);
		SysTickDelay_us(5);
  }
}

void SysTickDelay_ms(const unsigned int Milisecond)
{
	unsigned int i=0;
	
  SYSTICK->SYST_RVR = (uint32_t)(SYST_RVR_ms); /* Set reload value */

  SYSTICK->SYST_CVR = (uint32_t)(0u); /* Clear current value */

  SYSTICK->SYST_CSR |= (1<<0) | (1<<2); /* Enable counter & Set processor clock */

  for(i=Milisecond; i>0; i--)
  {
    while (!(SYSTICK->SYST_CSR & (1<<16)));    
  }

  SYSTICK->SYST_CSR = 0u; /* Disable Systick counter */
}

void SysTickDelay_us(const unsigned int MicroSecond)
{
  unsigned int i=0;
	
  SYSTICK->SYST_RVR = (uint32_t)(SYST_RVR_us); /* Set reload value */

  SYSTICK->SYST_CVR = (uint32_t)(0u); /* Clear current value */

  SYSTICK->SYST_CSR |= (1<<0) | (1<<2); /* Enable counter & Set processor clock */

  for(i=MicroSecond; i>0; i--)
  {
    while (!(SYSTICK->SYST_CSR & (1<<16)));    
  }

  SYSTICK->SYST_CSR = 0u; /* Disable Systick counter */
}

