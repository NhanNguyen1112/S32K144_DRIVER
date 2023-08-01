
#include "Clock.h"

void Fast_IRC_Clock(void)
{
	//unsigned int TempRegister=0u;
}

void Slow_IRC_Clock(void)
{
	unsigned int SIRCCSR=0u;
	unsigned int SIRCCFG=0u;

	SIRCCSR &= ~(1u<<0); /* Disable SLOW IRC */

	SIRCCFG |= (1u<<0); /* Set SIRC 8Mhz */
	SCG->SIRCCFG = SIRCCFG;

	SIRCCSR |= (1u<<0); /* Enable SLOW IRC */
	SCG->SIRCCSR = SIRCCSR;
	
	while( !(SCG->SIRCCSR & (1u<<24)) ); /* Wait Enable SIRC clock */
}

void Run_Mode_Clock(void)
{
	unsigned int RCCR=0u;

	RCCR |= (2u<<24); /* SCS Set Slow IRC */

	SCG->RCCR = RCCR;

	while( (SCG->CSR & (1<<24)) != 1u  );
}

void CheckClock(void)
{
	//unsigned int TempRegister=0u;
	
	//SCG->CLKOUTCNFG = TempRegister; /* Clear All Register - Set SCG SLOW CLOCK*/
	
	//TempRegister |= (1u<<24);  /* Set SOSC_CLK */
	//TempRegister |= (2u<<24);  /* Set SIRC_CLK */
	//TempRegister |= (3u<<24);  /* Set FIRC_CLK */
	//TempRegister |= (6u<<24);  /* Set SPLL_CLK */
	//SCG->CLKOUTCNFG = TempRegister;
  
  SIM->CHIPCTL &= ~(1u<<11);     /* Disable CLKOUT */
	
	SIM->CHIPCTL &= ~(0xFu<<4);  /* CLKOUTSEL SET SCG CLKOUT */
	//SIM->CHIPCTL |= (2u<<4);   /* CLKOUTSEL SET SOSC DIV2 */
	//SIM->CHIPCTL |= (4u<<4);   /* CLKOUTSEL SET SIRC DIV2 */
	//SIM->CHIPCTL |= (6u<<4);   /* CLKOUTSEL SET FIRC DIV2 */
	SIM->CHIPCTL |= (7u<<4);   /* CLKOUTSEL SET HCLK */
	//SIM->CHIPCTL |= (9u<<4);   /* CLKOUTSEL SET BUS CLK */
  
	SIM->CHIPCTL &= ~(0x7u<<8); 	/* CLKOUTDIV Set /1 */
	//SIM->CHIPCTL |= (1u<<8);   	/* CLKOUTDIV /2 */
	
	SIM->CHIPCTL |= (1u<<11);     /* Enable CLKOUT */
	
	/* Set PIN5 PORTB Output CLK */
	CLEARBIT(PORTB->PCR[PIN5],7u,8u); /* Clear ALL MUX */
  CLEARBIT(PORTB->PCR[PIN5],3u,0u); /* Clear PULL */

  SETBIT(PORTB->PCR[PIN5],5u,8u); /* SET MUX ALT2 */
	SETBIT(GPIOB->PDDR,1u,PIN5);
}

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

