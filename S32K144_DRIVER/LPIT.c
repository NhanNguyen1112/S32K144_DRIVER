
#include "LPIT.h"

static volatile unsigned int Count=0;

static unsigned int test=0;
static int total=0;
static unsigned int Starttimer=0;
static unsigned int Stoptimer=0;

void MainLPIT_Test(void)
{
  SOSC_Init_8Mhz();
	SPLL_Init();
	Run_Mode_Clock();
  //CheckClock();

  LPIT_Init_CH0();

  EnableClockPortD(Enable);
  SetPinOutput(PortD, PIN0, No);

  while(1)
  {
    TogglePin(PortD,PIN0);
    LPIT_CH0_Delay_ms(10);
		
		// Starttimer=LPIT->CVAL0;
		// for(unsigned int i=0; i<=3000000; i++)
		// {
		// 	test++;
		// }
		// Stoptimer=LPIT->CVAL0;
		
		// total = (int)( (Starttimer - Stoptimer)/8000000 );
		
		// test=0;
  }
}

void LPIT_Init_CH0(void)
{
	unsigned int PccLPIT=0;
	unsigned int TCTRL=0;
	
	//PccLPIT |= (1u<<24); 	/* Set SOSCDIV2_CLK */
  PccLPIT |= (6u<<24); 		/* Set SPLLDIV2_CLK */
  
  PccLPIT |= (1u<<30); /* Enable */
  PCC_LPIT = PccLPIT; 
	
  LPIT->MCR = 0x1u;     /* Enable peripheral clock to timers */

  LPIT->MIER = 0x00000001u;    /* Timer 0 Enable interrupt */

  LPIT->TVAL0 = 60000UL;      /* Timer 0: 60mhz-> 60.000 = 1ms */ 

	NVIC_SetPriority(LPIT0_Ch0_IRQn,0);
	NVIC_ClearPendingFlag(LPIT0_Ch0_IRQn);
	NVIC_EnableInterrupt(LPIT0_Ch0_IRQn); /* Enable LPIT timer 0 */
	
  TCTRL |= (1u<<0);
  LPIT->TCTRL0 = TCTRL;  /* Timer 0 Enable */

}

void LPIT0_Ch0_IRQHandler(void)
{
	LPIT->MSR |= (1u<<0); /* Timer 0 Clear flag */
	Count++;
}

void LPIT_CH0_Delay_ms(const unsigned int MiliSecond)
{
  while(Count<MiliSecond);
  Count=0;
}

