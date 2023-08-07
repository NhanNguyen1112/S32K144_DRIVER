
#ifndef __S32K144_REGISTER__
#define __S32K144_REGISTER__

#include "S32K144_LED.h"
#include "S32K144_BUTTON.h"
#include "S32K144_INTERRUPT.h"
#include "SYSTICK.h"
#include "Gpio.h"
#include "Clock.h"
#include "Softtimer.h"
#include "NVIC.h"

typedef unsigned char 	uint8_t;
typedef unsigned short 	uint16_t;
typedef unsigned int 	uint32_t;

#define SETBIT(PORT,VALUE,BIT) 		( (PORT) |= ( (VALUE)<<(BIT) ) )
#define CLEARBIT(PORT,VALUE,BIT) 	( (PORT) &= ~( (VALUE)<<(BIT) ) )
#define SETALL(PORT) 				( (PORT)|=(0xFFFFFFFF) )
#define CLEARALL(PORT) 				( (PORT)&=(0x00000000) )
#define READBIT(PORT,BIT) 			( (PORT) & (1<<(BIT)) )

/*==================================================================================================
*                                        ENUMS
==================================================================================================*/
typedef enum 
{
	LOW,
	HIGH
}DigitalState_enum;

typedef enum
{
	Disable,
	Enable
}EnDisable_enum;

typedef enum 
{
	OUTPUT,
	INPUT
}PinMode_enum;

typedef enum 
{
	No,
	PullUp,
	PullDown
}UpDown_enum;

typedef enum 
{
	PortA,
	PortB,
	PortC,
	PortD,
	PortE
}Port_enum;

typedef enum 
{
	GpioA,
	GpioB,
	GpioC,
	GpioD,
	GpioE
}Gpio_enum;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	PIN16,
	PIN17,
	PIN18,
	PIN19,
	PIN20,
	PIN21,
	PIN22,
	PIN23,
	PIN24,
	PIN25,
	PIN26,
	PIN27,
	PIN28,
	PIN29,
	PIN30,
	PIN31
}PortPin_enum;

/*================================================================================================*/

/*===============================================================================*/
/*			Define SIM			*/ 
/*===============================================================================*/

typedef struct
{
	char dummy[0x4u];
	volatile uint32_t CHIPCTL;
	char dummy1[0x8u];
	volatile uint32_t FTMOPT0;
	volatile uint32_t LPOCLKS;
	char dummy2[0x8u];
	volatile uint32_t ADCOPT;
	volatile uint32_t FTMOPT1;
	volatile uint32_t MISCTRL0;
	volatile uint32_t SDID;
	char dummy3[0x1Cu];
	volatile uint32_t PLATCGC;
	char dummy4[0xCu];
	volatile uint32_t FCFG1;
	char dummy5[0x8u];
	volatile uint32_t UIDH;
	volatile uint32_t UIDMH;
	volatile uint32_t UIDML;
	volatile uint32_t UIDL;
	char dummy6[0x8u];
	volatile uint32_t CLKDIV4;
	volatile uint32_t MISCTRL1;
}SIM_typedef;

#define SIM_BASE_ADDRESS (0x40048000u)
#define SIM ((volatile SIM_typedef *)SIM_BASE_ADDRESS)

/*===============================================================================*/


/*===============================================================================*/
/*			Define SCG (Clock)			*/ 
/*===============================================================================*/
typedef struct
{
	volatile uint32_t VERID;
	volatile uint32_t PARAM;
	char dummy0[8u];
	volatile uint32_t CSR;
	volatile uint32_t RCCR;
	volatile uint32_t VCCR;
	volatile uint32_t HCCR;
	volatile uint32_t CLKOUTCNFG;
	char dummy2[220u];

	volatile uint32_t SOSCCSR;
	volatile uint32_t SOSCDIV;
	volatile uint32_t SOSCCFG;
	char dummy3[244u];

	volatile uint32_t SIRCCSR;
	volatile uint32_t SIRCDIV;
	volatile uint32_t SIRCCFG;
	char dummy4[244u];

	volatile uint32_t FIRCCSR;
	volatile uint32_t FIRCDIV;
	volatile uint32_t FIRCCFG;
	char dummy5[756u];

	volatile uint32_t SPLLCSR;
	volatile uint32_t SPLLDIV;
	volatile uint32_t SPLLCFG;
}SCG_typedef;

#define SCG_BASE_ADDRESS (0x40064000u)
#define SCG ((volatile SCG_typedef *)SCG_BASE_ADDRESS)

/*===============================================================================*/


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
/*			Define SYSTICK			*/ 
/*===============================================================================*/
typedef struct
{
	volatile unsigned int SYST_CSR;
	volatile unsigned int SYST_RVR;
	volatile unsigned int SYST_CVR;
	volatile unsigned int SYST_CALIB;
}Systick_typedef;
#define SYSTICK_BASE_ADDRESS  ((uint32_t)0xE000E010u)
#define SYSTICK 							((Systick_typedef*)SYSTICK_BASE_ADDRESS)
/*===============================================================================*/



#endif
