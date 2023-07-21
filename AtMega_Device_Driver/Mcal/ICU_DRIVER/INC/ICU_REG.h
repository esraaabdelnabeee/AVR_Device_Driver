/*
 * ICU_REG.h
 *
 * Created: 23/07/20 6:35:14 PM
 *  Author: ESRAA_ABDELANBE
 */ 


#ifndef ICU_REG_H_
#define ICU_REG_H_

#include "..\..\..\STD_TYPES.h"


#define ICU_TIMSK_REG   (*(volatile u8*)(0x59))
#define TOIE0   0
#define OCIE0   1
#define TOIE2   6
#define OCIE2   7
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5


#define ICU_ICR1_REG  (*(volatile u16*)(0x46))


#define ICU_TCCR1A_REG (*(volatile u8*)(0x4F))
#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7


#define ICU_TCCR1B_REG  (*(volatile u8*)(0x4E))
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define ICU_TIFR_REG  (*(volatile u8*)(0x58))
#define TOV0    0
#define OCF0    1
#define TOV2    6
#define OCF2    7
#define TOV1    2
#define OCF1B   3
#define OCF1A   4
#define ICF1    5






#endif /* ICU_REG_H_ */