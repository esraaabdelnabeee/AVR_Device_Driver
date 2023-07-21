/*
 * EX_INTERRUPT.c
 *
 * Created: 23/07/13 12:32:14 PM
 *  Author: ESRAA_ABDELANBE
 */ 
#include "../../EXTERNAL_INTERRUPT/INC/EX_INTERRUPT.h"
#include <stddef.h>
#include <avr/interrupt.h>
void (*INT0_ptr)(void)=NULL;
void (*INT1_ptr)(void)=NULL;
void (*INT2_ptr)(void)=NULL;

void Enable_EX_Inter(INT_TYPES Int_TYPE  ,TRIGGER_MODE mode,void (*ptr)(void) )
{
	switch (Int_TYPE)
	{
		case INT_0:
		INT0_ptr=ptr;
		SET_BIT(GICR,INT0_GICR);
		INT0_ptr=ptr;
		if (mode==Low_level)
		{
			CLEAR_BIT(MCUCR,ISC00_MCUCR);
			CLEAR_BIT(MCUCR,ISC01_MCUCR);
		}
		else if (mode==Rising_falling_Edge)
		{
			SET_BIT(MCUCR,ISC00_MCUCR);
			CLEAR_BIT(MCUCR,ISC01_MCUCR);
		}
		else if (mode==Falling_Edge)
		{
			CLEAR_BIT(MCUCR,ISC00_MCUCR);
			SET_BIT(MCUCR,ISC01_MCUCR);
		}
		else if (mode==Rising_Edge)
		{
			SET_BIT(MCUCR,ISC00_MCUCR);
			SET_BIT(MCUCR,ISC01_MCUCR);
			
		}
		break;
		case INT_1:
		INT1_ptr=ptr;
		
		SET_BIT(GICR,INT1_GICR);
		if (mode==Low_level)
		{
			CLEAR_BIT(MCUCR,ISC10_MCUCR);
			CLEAR_BIT(MCUCR,ISC11_MCUCR);
		}
		else if (mode==Rising_falling_Edge)
		{
			SET_BIT(MCUCR,ISC10_MCUCR);
			CLEAR_BIT(MCUCR,ISC11_MCUCR);
		}
		else if (mode==Falling_Edge)
		{
			CLEAR_BIT(MCUCR,ISC10_MCUCR);
			SET_BIT(MCUCR,ISC11_MCUCR);
		}
		else if (mode==Rising_Edge)
		{
			SET_BIT(MCUCR,ISC10_MCUCR);
			SET_BIT(MCUCR,ISC11_MCUCR);
			
		}
		break;
		
		case INT_2:
		INT2_ptr=ptr;
		
		SET_BIT(GICR,INT2_GICR);
		if(mode==Falling_Edge)
		{
			CLEAR_BIT(MCUCSR,ISC2_MCUCSR);
		}
		else if(mode==Rising_Edge)
		{
			SET_BIT(MCUCSR,ISC2_MCUCSR);

		}
		break;
	}
}
void Disable_EX_Inter(INT_TYPES Int_TYPE )
{
	switch(Int_TYPE)
	{
		case INT_0:
		CLEAR_BIT(GICR,INT0_GICR);

		break;
		case INT_1:
		CLEAR_BIT(GICR,INT1_GICR);

		break;
		case INT_2:
		CLEAR_BIT(GICR,INT2_GICR);

		break;
		
	}
}
ISR(INT0_vect)
{
	if(INT0_ptr != NULL)
	{
		INT0_ptr();
	}
}
ISR(INT1_vect)
{
	if(INT1_ptr != NULL)
	{
		INT1_ptr();
	}
}
ISR(INT2_vect)
{
	if(INT2_ptr != NULL)
	{
		INT2_ptr();
	}
}