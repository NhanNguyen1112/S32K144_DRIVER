#include "S32K144.h"

void Function_LedRed(void)
{
  TogglePin(PortD,LEDRED);
}

void Function_LedGreen(void)
{
  TogglePin(PortD,LEDGREEN);
}

void Function_LedBlue(void)
{
  TogglePin(PortD,LEDBLUE);
}

int main(void)
{
	SPI0_MAIN_TEST();

	// Systick_MAIN_Delay_Test();

	//UART0_MAIN_TEST();
	
	//MainLPIT_Test();
	
	// SOSC_Init_8Mhz();
	// SPLL_Init();
	// Run_Mode_Clock();
	
	// CheckClock();

	// SetPinInput(PortC,BUTTON_1,PullDown);
	// SetPinInput(PortC,BUTTON_2,PullDown);

	// SetPinOutput(PortD,LEDBLUE,No);
	// SetPinOutput(PortD,LEDGREEN,No);
	// SetPinOutput(PortD,LEDRED,No);

	// WritePin(PortD,LEDRED,HIGH);
	// WritePin(PortD,LEDGREEN,HIGH);
	// WritePin(PortD,LEDBLUE,HIGH);

	// Softtimer_Init();
	// Softtimer_StartTimer(0,100,ONESHOT,&Function_LedRed);
	// Softtimer_StartTimer(1,50,CONTINUE,&Function_LedGreen);
	// Softtimer_StartTimer(2,5,CONTINUE,&Function_LedBlue);

	// while(1)
	// {
		// Softtimer_MainFunction();

		// if(GetPin(PortC,BUTTON_1))
		// {
		// 	Softtimer_StopTimer(2);
		// }
		
		/*
		if(GetPin(PortC,BUTTON_2)) WritePin(PortD,LEDRED,LOW);
		else WritePin(PortD,LEDRED,HIGH);

		WritePin(PortD,LEDRED,HIGH);
		SysTickDelay(1000);
		WritePin(PortD,LEDRED,LOW);
		SysTickDelay(1000);
		
		TogglePin(PortD,LEDRED);
		SysTickDelay(1000);
		*/
	//}
}

