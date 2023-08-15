
#ifndef __UART__
#define __UART__ 

#include "S32K144.h"
#include "UART_Register.h"

void UART0_MAIN_TEST(void);

void UART0_Init_Polling(void);
void UART0_Init_INT(void);
void UART0_WriteData(unsigned char *Data);
void UART0_WriteMultiData(unsigned char *Data, const unsigned char size);
void UART0_ReadData(unsigned char *Data);
void UART0_ReadMultiData(unsigned char *Data, const unsigned char size);
void LPUART0_RxTx_IRQHandler(void);

#endif /* __UART__ */

