/*
 * EX_REG.h
 *
 * Created: 23/07/13 12:34:28 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef EX_REG_H_
#define EX_REG_H_

#include "..\..\..\BIT_MATH.h"
#include "..\..\..\STD_TYPES.h"


#define GICR    (*((volatile u8*)0x5B))
#define GIFR    (*((volatile u8*)0x5A))
#define MCUCR   (*((volatile u8*)0x55))
#define MCUCSR  (*((volatile u8*)0x54))





#endif /* EX_REG_H_ */