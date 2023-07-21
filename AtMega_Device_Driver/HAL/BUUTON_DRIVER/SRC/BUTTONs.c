/*
 * BUTTONs.c
 *
 * Created: 6/10/2023 2:53:24 PM
 *  Author: ESRAA_ABDELNABE
 */ 

#include "..\INC\BUTTONs.h"

/*
void BUTTONs_init(void)
{
	DIO_setPinDiretion(LED_BUTTON1_PORT,LED_BUTTON1_PIN,INPUT);
	DIO_setPinDiretion(LED_BUTTON2_PORT,LED_BUTTON2_PIN,INPUT);
	DIO_setPinDiretion(LED_BUTTON3_PORT,LED_BUTTON3_PIN,INPUT);
	DIO_setPinDiretion(LED_BUTTON4_PORT,LED_BUTTON4_PIN,INPUT);
}
button_state BUTTONs_getstatus(buttonId buttonID)
{
	button_state state = unPressed;
	switch(buttonID)
	{
		case Button1:
		state = DIO_readPinChannel(LED_BUTTON1_PORT ,LED_BUTTON1_PIN);
		break;
		case Button2:
		state = DIO_readPinChannel(LED_BUTTON2_PORT,LED_BUTTON2_PIN);
		break;
		case Button3:
		state = DIO_readPinChannel(LED_BUTTON3_PORT,LED_BUTTON3_PIN);
		break;
		case Button4:
		state = DIO_readPinChannel(LED_BUTTON4_PORT,LED_BUTTON4_PIN);
		break;
	}
	return state;
}
*/