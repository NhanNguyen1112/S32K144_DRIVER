
#ifndef _SYSTICK_Register_
#define _SYSTICK_Register_

#include "SYSTICK.h"

/*===============================================================================*/
/*			Define SYSTICK			*/ 
/*===============================================================================*/
typedef struct
{
	volatile unsigned int SYST_CSR;
	volatile unsigned int SYST_RVR;
	volatile unsigned int SYST_CVR;
	volatile unsigned int SYST_CALIB;
}Systick_typedef;

#define SYSTICK_BASE_ADDRESS    (0xE000E010UL)
#define SYSTICK 			    ((Systick_typedef*)SYSTICK_BASE_ADDRESS)
/*===============================================================================*/

#endif /* _SYSTICK_Register_ */


