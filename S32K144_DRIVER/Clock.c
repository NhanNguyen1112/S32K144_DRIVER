
#include "Clock.h"

void SOSC_Init_8Mhz(void)
{
	unsigned int TempDIV=0;
	unsigned int TempCFG=0;
	unsigned int TempCSR=0;
	
	TempDIV |= (1u<<0); /* DIV1 /1 */
	TempDIV |= (1u<<8); /* DIV2 /1 */
	SCG->SOSCDIV=TempDIV;

	TempCFG |= (2u<<4); 	/* RANGE set Medium */
	TempCFG &= ~(1u<<3); 	/* HGO set low power */
	TempCFG |= (1u<<2); 	/* EREFS set XTAL */
	SCG->SOSCCFG=TempCFG;

	TempCSR |= (1u<<0); 							/* Enable OSC */
	SCG->SOSCCSR=TempCSR;

	while( !(SCG->SOSCCSR & (1u<<24)) ); /* Wait for sys OSC clk valid */

}

/* SPLL_CLK=100Mhz , SPLLDIV1 /2, SPLLDIV2 /2 */
void SPLL_Init(void)
{
	unsigned int TempDIV=0;
	unsigned int TempCFG=0;
	unsigned int TempCSR=0;

	SCG->SPLLCSR = TempCSR; 		/* Disable SPLL & unlocked register */
	while(SCG->SPLLCSR & (1u<<23)); /* SPLLCSR unlocked */

	TempDIV |= (2u<<0); /* DIV1 /2 */
	TempDIV |= (2u<<8); /* DIV2 /2 */
	SCG->SPLLDIV = TempDIV;

	/* SPLLL CLK = CLK_SOURCE/(PREDIV + 1) * (MULT) */
	TempCFG &= ~(1u<<0); 		/* Clock source OSC */
	TempCFG &= ~(0xFu<<8); 	/* FREDIV=0 */
	TempCFG |= (9u<<16); 		/* MULT=25 */
	SCG->SPLLCFG = TempCFG;

	while(SCG->SPLLCSR & (1u<<23)); /* SPLLCSR unlocked */
	TempCSR |= (1u<<0); /* enable SPLL */
	SCG->SPLLCSR = TempCSR;

	while(!(SCG->SPLLCSR & (1u<<24))); /* Wait for SPLL valid */
}

/* Set SPLL, DIVCORE /2, DIVBUS /2, DIVSLOW /2 */
void Run_Mode_Clock(void)
{
	unsigned int TempRCCR=0;

	TempRCCR |= (6u<<24); 	/* SCS Set SPLL */
	TempRCCR |= (1u<<16); 	/* DIVCORE /2 */
	TempRCCR |= (1u<<4); 		/* DIVBUS /2 */
	TempRCCR |= (1u<<0); 		/* DIVSLOW /2 */

	SCG->RCCR = TempRCCR;

	while( (SCG->CSR>>24) != 6u  ); /* Wait SCS set clock */
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
	
	SIM->CHIPCTL &= ~(0xFu<<4);  	/* CLKOUTSEL SET SCG CLKOUT */
	SIM->CHIPCTL |= (2u<<4);   		/* CLKOUTSEL SET SOSC DIV2 */
	//SIM->CHIPCTL |= (4u<<4);   	/* CLKOUTSEL SET SIRC DIV2 */
	//SIM->CHIPCTL |= (6u<<4);   	/* CLKOUTSEL SET FIRC DIV2 */
	//SIM->CHIPCTL |= (7u<<4);   	/* CLKOUTSEL SET HCLK */
	//SIM->CHIPCTL |= (9u<<4);   	/* CLKOUTSEL SET BUS CLK */
	//SIM->CHIPCTL |= (8u<<4);   	/* CLKOUTSEL SET SPLLDIV/2 */
  
	SIM->CHIPCTL &= ~(0x7u<<8); 	/* CLKOUTDIV Set /1 */
	//SIM->CHIPCTL |= (1u<<8);   	/* CLKOUTDIV /2 */
	
	SIM->CHIPCTL |= (1u<<11);     /* Enable CLKOUT */
	
	/* Set PIN5 PORTB Output CLK */
	SETBIT(PCC->PCC_PORTB,0x1u,30); /* Enable clock port B */
	
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

