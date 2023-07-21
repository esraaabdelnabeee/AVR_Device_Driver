/*
 * TIMER0_CFG.h
 *
 * Created: 23/07/13 12:41:02 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

//************TCCR0*************//
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7
//*******************************//

//************TIMSK*************//
#define TOIE0 0
#define OCIE0 1
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2  6
#define OCIE2  7
//*******************************//
//**************TIFR************//
#define TOV0 0
#define OCF0 1
//********************************//



#endif /* TIMER0_CFG_H_ */