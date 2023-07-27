
#include "SYSTICK.h"

void SysTickDelay(const unsigned int Milisecond)
{
	unsigned int i=0;
	
  SYSTICK->SYST_RVR = (uint32_t)(48000u); /* Set reload value */

  SYSTICK->SYST_CVR = (uint32_t)(0u); /* Clear current value */

  SYSTICK->SYST_CSR |= (1<<0) | (1<<2); /* Enable counter & Set processor clock */

  for(i=Milisecond; i>0; i--)
  {
    while (!(SYSTICK->SYST_CSR & (1<<16)));    
  }

  SYSTICK->SYST_CSR = 0u; /* Disable Systick counter */
}
