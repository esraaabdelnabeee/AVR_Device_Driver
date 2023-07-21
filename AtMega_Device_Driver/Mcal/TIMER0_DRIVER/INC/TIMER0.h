/*
 * TIMER.h
 *
 * Created: 23/07/13 12:41:20 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include "../../TIMER0_DRIVER/INC/TIMER0_REG.h"
#include "../../TIMER0_DRIVER/INC/TIMER0_CFG.h"
#include "../../TIMER0_DRIVER/INC/TIMER0_TYPES.h"
#include <avr/io.h>

void TIMER0_Init(timer_mode MODE);
void TIMER0_Start(u8 prescaler);
void TIMER0_Stop(void);
void TIMER0_SetPreLoad(u8 value);
u8   TIMER0_GetLoadValue(void);
void TIMER0_EnableInterrupt(INT,void (*ptr)(void));
void TIMER0_DisableInterrupt(INT,void (*ptr)(void));
void TIMER0_RESET_COUNTER(void);
void TIMER0_SET_DUTY(u8 duty);
void TIMER0_INC_DUTY(u8 INC_DUT);




#endif /* TIMER0_H_ */