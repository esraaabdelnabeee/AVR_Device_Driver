/*
 * ICU.h
 *
 * Created: 23/07/20 6:35:02 PM
 *  Author: ESRAA_ABDELANBE
 */ 


#ifndef ICU_H_
#define ICU_H_

#include "ICU_reg.h"
#include "ICU_Types.h"
#include "..\..\..\BIT_MATH.h"
#include <avr/interrupt.h>
void TIMER1_Start(timer1_Prescaler_t);
void TIMER1_Stop();

void Timer1_Init(TIMER1_mode_t);
void  ICU_CATCH (catch_mode_t,timer1_Prescaler_t);




#endif /* ICU_H_ */