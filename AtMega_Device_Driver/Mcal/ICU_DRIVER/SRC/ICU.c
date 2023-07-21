/*
 * ICU.c
 *
 * Created: 23/07/20 6:36:27 PM
 *  Author: ESRAA_ABDELANBE
 */ 
#include "..\INC\ICU.h"

static volatile u16 first_catch=0; 
static volatile u16 second_catch=0;

void Timer1_Init(TIMER1_mode_t MODE)
{
	switch(MODE)
	{
		case Normal_mode:
		CLEAR_BIT(ICU_TCCR1A_REG , WGM10);
		CLEAR_BIT(ICU_TCCR1A_REG , WGM11);
		CLEAR_BIT(ICU_TCCR1B_REG , WGM12);
		CLEAR_BIT(ICU_TCCR1B_REG , WGM13);	
	}
}

void TIMER1_Start(timer1_Prescaler_t prescaler)
{
	
	switch(prescaler){
		case No_Clock_src:
		CLEAR_BIT(ICU_TCCR1B_REG,CS10);
		CLEAR_BIT(ICU_TCCR1B_REG,CS11);
		CLEAR_BIT(ICU_TCCR1B_REG,CS12);
		break;
		
		case prescaler_none:
		SET_BIT(ICU_TCCR1B_REG,CS10);
		CLEAR_BIT(ICU_TCCR1B_REG,CS11);
		CLEAR_BIT(ICU_TCCR1B_REG,CS12);
		break;
		
		case prescaler_8:
		CLEAR_BIT(ICU_TCCR1B_REG,CS10);
		SET_BIT(ICU_TCCR1B_REG,CS11);
		CLEAR_BIT(ICU_TCCR1B_REG,CS12);
		break;
		
		case prescaler_64:
		SET_BIT(ICU_TCCR1B_REG,CS10);
		SET_BIT(ICU_TCCR1B_REG,CS11);
		CLEAR_BIT(ICU_TCCR1B_REG,CS12);
		break;
		
		case prescaler_256:
		CLEAR_BIT(ICU_TCCR1B_REG,CS10);
		CLEAR_BIT(ICU_TCCR1B_REG,CS11);
		SET_BIT(ICU_TCCR1B_REG,CS12);
		break;
		
		case prescaler_1024:
		SET_BIT(ICU_TCCR1B_REG,CS10);
		CLEAR_BIT(ICU_TCCR1B_REG,CS11);
		SET_BIT(ICU_TCCR1B_REG,CS12);
		break;
	}
}
void TIMER1_Stop()
{
		CLEAR_BIT(ICU_TCCR1B_REG,CS10);
		CLEAR_BIT(ICU_TCCR1B_REG,CS11);
		CLEAR_BIT(ICU_TCCR1B_REG,CS12);
}
void ICU_CATCH (catch_mode_t MODE,timer1_Prescaler_t prescaler)
{
	switch(MODE)
	{
		case Rising_Edge:
		SET_BIT(ICU_TCCR1B_REG,ICES1);
		break;
		/*TIMER1_Start(prescaler);
		while(!(CHECK_BIT(ICU_TIFR_REG,ICF1)));
		first_catch = ICU_ICR1_REG;
		SET_BIT(ICU_TIFR_REG,ICF1);
		//ICR1
		while(!(CHECK_BIT(ICU_TIFR_REG,ICF1)));
		second_catch = ICU_ICR1_REG;
		SET_BIT(ICU_TIFR_REG,ICF1);
		
		if(second_catch> first_catch)
		{
			result = (second_catch - first_catch);
		}else
		{
			result = ((65535 - first_catch)+second_catch);
		}
		
		
		case Rising_Edge:
		SET_BIT(ICU_TCCR1B_REG,ICES1);
		TIMER1_Start(prescaler);
		while(!(CHECK_BIT(ICU_TIFR_REG,ICF1)));
		first_catch = ICU_ICR1_REG;
		SET_BIT(ICU_TIFR_REG,ICF1);
		
		while(!(CHECK_BIT(ICU_TIFR_REG,ICF1)));
		second_catch = ICU_ICR1_REG;
		SET_BIT(ICU_TIFR_REG,ICF1);
		
		if(second_catch> first_catch)
		{
			result =  (second_catch - first_catch);
		}else
		{
			result =  ((65535 - first_catch)+second_catch);
		}
		break;
		*/
	}
	SET_BIT(ICU_TIMSK_REG,TICIE1);
	TIMER1_Start(prescaler);
}


//void __vector_6 (void)        __attribute__((signal));

//void __vector_6 (void)    
ISR(TIMER1_CAPT_vect)    
{
	//TOGGLE_BIT(ICU_TIMSK_REG,TOIE1);
	//SET_BIT(ICU_TIMSK_REG,TOIE1);
	//TOGGLE_BIT(ICU_TIMSK_REG,TOIE0);
	static u8 flag = 0;
	static u16 old_value=0;
	if(flag==0)
	{
		first_catch = ICU_ICR1_REG - old_value;
		flag =1;
		CLEAR_BIT(ICU_TCCR1B_REG,ICES1);
		
	}
	else
	{
		second_catch = ICU_ICR1_REG - old_value;
		flag =0;
		SET_BIT(ICU_TCCR1B_REG,ICES1);
		TIMER1_Stop();
		
	}
	old_value = ICU_ICR1_REG;
};


u32 ICU_get_pwm(void)
{
	return first_catch + second_catch;
}
