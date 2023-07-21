/*
 * LED.c
 *
 * Created: 23/06/23 9:37:34 PM
 *  Author: Esraa_Abdelanbe
 */ 
#include "..\INC\LED.h"
void LEDs_init()
{
	DIO_setPinDirection(PORTB,PIN7,OUTPUT);  // RED LED
	DIO_setPinDirection(PORTA,PIN4,OUTPUT);  // GRN LED
	DIO_setPinDirection(PORTA,PIN5,OUTPUT);  // BLU LED
	DIO_setPinDirection(PORTA,PIN6,OUTPUT);  // YEL LED
}
void LEDs_off(LED_COLOR c)
{
		switch(c)
		{
			case RED:
			DIO_setPinChannel(PORTB,PIN7,LOW);
			break;
			case GREEN:
			DIO_setPinChannel(PORTA,PIN4,LOW);
			break;
			case BLUE:
			DIO_setPinChannel(PORTA,PIN5,LOW);
			break;
			case YELLOW:
			DIO_setPinChannel(PORTA,PIN6,LOW);
			break;
		}
}
void LEDs_on(LED_COLOR c)
{
		switch(c)
		{
			case RED:
			DIO_setPinChannel(PORTB,PIN7,HIGH);
			break;
			case GREEN:
			DIO_setPinChannel(PORTA,PIN4,HIGH);
			break;
			case BLUE:
			DIO_setPinChannel(PORTA,PIN5,HIGH);
			break;
			case YELLOW:
			DIO_setPinChannel(PORTA,PIN6,HIGH);
			break;
		}
}
void LEDs_toggle(LED_COLOR c)
{
	switch(c)
		{
		case RED:
		DIO_FLIP_Channel(PORTB,PIN7);
		break;
		case GREEN:
		DIO_FLIP_Channel(PORTA,PIN4);
		break;
		case BLUE:
		DIO_FLIP_Channel(PORTA,PIN5);
		break;
		case YELLOW:
		DIO_FLIP_Channel(PORTA,PIN6);
		break;
		}
	
}
