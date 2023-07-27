
#ifndef __S32K144_REGISTER__
#define __S32K144_REGISTER__

#include "S32K144_LED.h"
#include "S32K144_BUTTON.h"
#include "S32K144_INTERRUPT.h"
#include "SYSTICK.h"

typedef unsigned char 	uint8_t;
typedef unsigned short 	uint16_t;
typedef unsigned long 	uint32_t;

#define SETBIT(PORT,VALUE,BIT) 		( (PORT) |= ( (VALUE)<<(BIT) ) )
#define CLEARBIT(PORT,VALUE,BIT) 	( (PORT) &= ~( (VALUE)<<(BIT) ) )
#define SETALL(PORT) 				( (PORT)|=(0xFFFFFFFF) )
#define CLEARALL(PORT) 				( (PORT)&=(0x00000000) )
#define READBIT(PORT,BIT) 			( (PORT) & (1<<(BIT)) )


/*===============================================================================*/
/*			Define PCC (Clock)			*/ 
/*===============================================================================*/

typedef struct
{
	uint8_t dummy1[0x124];
	volatile uint32_t PCC_PORTA;
	volatile uint32_t PCC_PORTB;
	volatile uint32_t PCC_PORTC;
	volatile uint32_t PCC_PORTD;
	volatile uint32_t PCC_PORTE;
}PCC_typedef;

#define PCC_base_address (0x40065000u)
#define PCC ((volatile PCC_typedef *)PCC_base_address)
/*===============================================================================*/


/*===============================================================================*/
/*			Define PORT			*/ 
/*===============================================================================*/
typedef struct 
{
  volatile uint32_t PCR[32u];       
	volatile uint32_t GPCLR;
	volatile uint32_t GPCHR;
	volatile uint32_t GICLR;
	volatile uint32_t GICHR;
	volatile uint32_t ISFR;
	volatile uint32_t DFER;
	volatile uint32_t DFCR;
	volatile uint32_t DFWR;
}PORT_typedef;

#define PORTA_address (0x40049000)
#define PORTB_address (0x4004A000)
#define PORTC_address (0x4004B000)
#define PORTD_address (0x4004C000)
#define PORTE_address (0x4004D000)

#define PORTA	((PORT_typedef *)PORTA_address)
#define PORTB	((PORT_typedef *)PORTB_address)
#define PORTC	((PORT_typedef *)PORTC_address)
#define PORTD	((PORT_typedef *)PORTD_address)
#define PORTE	((PORT_typedef *)PORTE_address)

/*LED RED, GREEN, BLUE*/
#define PORTD_PCR0    	*( (volatile uint32_t *)(PORTD_address) )
#define PORTD_PCR15    	*( (volatile uint32_t *)((PORTD_address)+(0x3Cu)) )
#define PORTD_PCR16    	*( (volatile uint32_t *)((PORTD_address)+(0x40u)) )

/*BUTTON 1, 2*/
#define PORTC_PCR12  *( (volatile uint32_t *)((PORTC_address)+(0x30u)) )
#define PORTC_PCR13  *( (volatile uint32_t *)((PORTC_address)+(0x34u)) )
/*===============================================================================*/


/*===============================================================================*/
/*			Define GPIO			*/ 
/*===============================================================================*/
typedef struct 
{
	volatile uint32_t PDOR;
	volatile uint32_t PSOR;
	volatile uint32_t PCOR;
	volatile uint32_t PTOR;
	volatile uint32_t PDIR;
	volatile uint32_t PDDR;
	volatile uint32_t PIDR;
}gpio_typedef;

#define GPIOA_base_address (0x400FF000u)
#define GPIOB_base_address (0x400FF040u)
#define GPIOC_base_address (0x400FF080u)
#define GPIOD_base_address (0x400FF0C0u)
#define GPIOE_base_address (0x400FF100u)

#define GPIOA	((gpio_typedef *)GPIOA_base_address)
#define GPIOB	((gpio_typedef *)GPIOB_base_address)
#define GPIOC	((gpio_typedef *)GPIOC_base_address)
#define GPIOD	((gpio_typedef *)GPIOD_base_address)
#define GPIOE	((gpio_typedef *)GPIOE_base_address)
/*===============================================================================*/

/*===============================================================================*/
/*			Define NVIC			*/ 
/*===============================================================================*/

/** S32_NVIC - Register Layout Typedef */
typedef struct {
  volatile unsigned int ISER[8u];        
	unsigned int RESERVED_0[24];
  volatile unsigned int ICER[8u];         
    unsigned int RESERVED_1[24];
  volatile unsigned int ISPR[8u];         
    unsigned int RESERVED_2[24];
  volatile unsigned int ICPR[8u];         
    unsigned int RESERVED_3[24];
  volatile unsigned int IABR[8u];         
    unsigned char RESERVED_4[224];
  volatile unsigned char IP[240u];              
    unsigned char RESERVED_5[2576];
  volatile  unsigned int STIR;                              
} NVIC_Type;

#define NVIC_BASE	(0xE000E100u)
#define NVIC		((NVIC_Type *)NVIC_BASE)

/*===============================================================================*/


/*===============================================================================*/
/*			Define SYSTICK			*/ 
/*===============================================================================*/
typedef struct
{
	uint32_t SYST_CSR;
	uint32_t SYST_RVR;
	uint32_t SYST_CVR;
	uint32_t SYST_CALIB;
}Systick_typedef;
#define SYSTICK_BASE_ADDRESS  ((uint32_t)0xE000E010u)
#define SYSTICK 							((Systick_typedef*)SYSTICK_BASE_ADDRESS)
/*===============================================================================*/

/*===============================================================================*/
/*			Define LPIT			*/ 
/*===============================================================================*/

typedef struct
{
	uint32_t VERID;
	uint32_t PARAM;
	uint32_t MCR;
	uint32_t MSR;
	uint32_t MIER;
	uint32_t SETTEN;
	uint32_t CLRTEN;
	uint32_t TVAL0;
	uint32_t CVAL0;
	uint32_t TCTRL0;
	uint32_t TVAL1;
	uint32_t CVAL1;
	uint32_t TCTRL1;
	uint32_t TVAL2;
	uint32_t CVAL2;
	uint32_t TCTRL2;
	uint32_t TVAL3;
	uint32_t CVAL3;
	uint32_t TCTRL3;
}LPIT_typdef;
#define LPIT_BASE_ADDRESS 	((uint32_t)0x40037000u)
#define LPIT				((LPIT_typdef*)SYSTICK_BASE_ADDRESS)

/*===============================================================================*/

#endif
