/*
 * TIMER0_TYPES.h
 *
 * Created: 23/07/13 12:40:20 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef TIMER0_TYPES_H_
#define TIMER0_TYPES_H_

typedef enum{
	normal_mode,
	pwm_mode,
	ctc_mode,
	fast_pwm_mode
}timer_mode;
typedef enum
{
	Compare_Intrrupt,
	OverFlow_Interrupr
}INT;
typedef enum{
	prescaler_none,
	prescaler_8,
	prescaler_64,
	prescaler_256,
	prescaler_1024
}prescaler;






#endif /* TIMER0_TYPES_H_ */