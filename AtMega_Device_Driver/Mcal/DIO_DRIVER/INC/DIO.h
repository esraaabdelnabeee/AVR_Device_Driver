/*
 * DIO.h
 *
 * Created: 23/06/23 8:47:26 PM
 * Author: ESRAA_ABDELNABE
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "DIO_REG.h"
#include "DIO_TYPES.h"
#include "..\..\..\BIT_MATH.h"

void DIO_setPinDirection(PORT_ID,PIN_ID,PIN_DIR);
void DIO_setPinChannel(PORT_ID,PIN_ID,PIN_LEVEL);
void DIO_FLIP_Channel(PORT_ID,PIN_ID);
PIN_LEVEL READ_PIN_CHANNEL(PORT_ID,PIN_ID);

#endif /* DIO_H_ */