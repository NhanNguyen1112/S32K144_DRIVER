#include "S32K144.h"

int main(void)
{
	LED_INIT();
	BUTTON_INIT();
	INIT_Interrupt();
	
	while(1)
	{
		TURN_ON_LED(RED);
		SysTickDelay(5000);
		TURN_OFF_LED(RED);
		SysTickDelay(5000);
		
		//Test_Led_button();
		
		//if(StateLED==1) TURN_ON_LED(RED);
		//else TURN_OFF_LED(RED);
		
		//BUTTON_BLINK();
		//Blink_LED();
	}
}

