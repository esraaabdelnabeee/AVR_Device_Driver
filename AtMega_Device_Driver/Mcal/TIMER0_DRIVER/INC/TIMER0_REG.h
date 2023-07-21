/*
 * TIMER0_REG.h
 *
 * Created: 23/07/13 12:40:38 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_


#include "..\..\..\BIT_MATH.h"
#include "..\..\..\STD_TYPES.h"

#define TIMER_TCCR0 (*(volatile u8*)(0x53))
#define TIMER_TCNT0  (*(volatile u8*)(0x52))
#define TIMER_TIFR  (*(volatile u8*)(0x58))
#define TIMER_OCR0  (*(volatile u8*)(0x5c))
#define TIMER_TIMSK  (*(volatile u8*)(0x59))




#endif /* TIMER0_REG_H_ */