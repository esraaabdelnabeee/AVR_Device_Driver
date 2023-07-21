/*
* DIO.c
*
* Created: 23/06/23 8:49:18 PM
*  Author: Esraa_AbdElnabe
*/
#include "../INC/DIO.h"

void DIO_setPinDirection(PORT_ID portid,PIN_ID pinid,PIN_DIR pindir)
{
	switch(portid)
	{
		case PORTA:
		(pindir == OUTPUT)?SET_BIT(PORTA_REG,pinid):CLEAR_BIT(PORTA_REG,pinid);
		break;
		case PORTB:
		(pindir == OUTPUT)?SET_BIT(PORTB_REG,pinid):CLEAR_BIT(PORTB_REG,pinid);
		break;
		case PORTC:
		(pindir == OUTPUT)?SET_BIT(PORTC_REG,pinid):CLEAR_BIT(PORTC_REG,pinid);
		break;
		case PORTD:
		(pindir == OUTPUT)?SET_BIT(PORTD_REG,pinid):CLEAR_BIT(PORTD_REG,pinid);
		break;
	}
}
void DIO_setPinChannel(PORT_ID portid,PIN_ID pinid,PIN_LEVEL pinlevel)
{
		switch(portid)
		{
			case PORTA:
			(pinlevel == HIGH)? SET_BIT(PORTA_REG,pinid):CLEAR_BIT(PORTA_REG,pinid);
			break;
			case PORTB:
			(pinlevel == HIGH)? SET_BIT(PORTB_REG,pinid):CLEAR_BIT(PORTB_REG,pinid);
			break;
			case PORTC:
			(pinlevel == HIGH)?SET_BIT(PORTC_REG,pinid):CLEAR_BIT(PORTC_REG,pinid);
			break;
			case PORTD:
			(pinlevel == HIGH)?SET_BIT(PORTD_REG,pinid):CLEAR_BIT(PORTD_REG,pinid);
			break;
		}
}
void DIO_FLIP_Channel(PORT_ID portid,PIN_ID pinid)
{
	switch(portid)
	{
		case PORTA:
		TOGGLE_BIT(PORTA_REG,pinid);
		break;				 
		case PORTB:			 
		TOGGLE_BIT(PORTB_REG,pinid);
		break;				 
		case PORTC:			 
		TOGGLE_BIT(PORTC_REG,pinid);
		break;				 
		case PORTD:			 
		TOGGLE_BIT(PORTD_REG,pinid);
		break;
	}
}
PIN_LEVEL READ_PIN_CHANNEL(PORT_ID portid,PIN_ID pinid)
{
	PIN_LEVEL pin_level=LOW;
		switch(portid)
		{
			case PORTA:
			pin_level=CHECK_BIT(PORTA_REG,pinid);
			break;
			case PORTB:
			pin_level=CHECK_BIT(PORTB_REG,pinid);
			break;
			case PORTC:
			pin_level=CHECK_BIT(PORTC_REG,pinid);
			break;
			case PORTD:
			pin_level=CHECK_BIT(PORTD_REG,pinid);
			break;
		}
		return pin_level;
}