/*
 * TIMER0.c
 *
 * Created: 23/07/13 12:42:24 PM
 *  Author: ESRAA_ABDELNABE
 */ 
#include <stddef.h>
#include <avr/interrupt.h>
#include "../../TIMER0_DRIVER/INC/TIMER0.h"
void (*PTR_OVERFLOW)(void)=NULL;
void (*PTR_ONCOMP)(void)=NULL;
#define Timer_count   255
void TIMER0_Init(timer_mode MODE)
{
	TIMER0_Stop();
	
	switch(MODE)
	{
		case normal_mode:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		//SET_BIT(TIMSK,TOIE0);
		break;
		case pwm_mode:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		
		case ctc_mode:
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		
		case fast_pwm_mode:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}
}
void TIMER0_SET_DUTY(u8 duty)
{
	u8 result=(duty*Timer_count)/100;
	OCR0=result;
}
void TIMER0_INC_DUTY(u8 INC_DUT)
{
	OCR0+=INC_DUT;
}
void TIMER0_DEC_DUTY(u8 DEC_DUT)
{
	OCR0-=DEC_DUT;
}
void TIMER0_RESET_COUNTER(void)
{
	TCNT0=0;
	//	overflows = 0;

}
void TIMER0_Start(u8 prescaler)
{
	switch (prescaler){
		case prescaler_none:
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		case prescaler_8:
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		case prescaler_64:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		case prescaler_256:
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		case prescaler_1024:
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	}
}
void TIMER0_Stop(void)
{
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
}
void TIMER0_SetPreLoad(u8 value)
{
	TCNT0=value;
}
u8   TIMER0_GetLoadValue(void)
{
	u8 return_value;
	return_value=TCNT0;
	return  return_value;
}
void TIMER0_EnableInterrupt(INT INT_TYPE,void (*ptr)(void))
{
	switch (INT_TYPE)
	{
		case Compare_Intrrupt:
		PTR_ONCOMP=ptr;
		SET_BIT(TIMSK,OCIE0);
		break;
		case OverFlow_Interrupr:
		PTR_OVERFLOW=ptr;
		SET_BIT(TIMSK,TOIE0);
		break;
		
	}
	
}
void TIMER0_DisableInterrupt(INT INT_TYPE,void (*ptr)(void))
{
	switch (INT_TYPE)
	{
		case Compare_Intrrupt:
		CLEAR_BIT(TIMSK,OCIE0);
		
		break;

		case OverFlow_Interrupr:
		CLEAR_BIT(TIMSK,TOIE0);
		break;
		
	}
	
}
ISR(TIMER0_OVF_vect)
{
	if(PTR_OVERFLOW!= NULL)
	{
		PTR_OVERFLOW();
	}
}
ISR(TIMER0_COMP_vect)
{
	if(PTR_ONCOMP != NULL)
	{
		PTR_ONCOMP();
	}
}
