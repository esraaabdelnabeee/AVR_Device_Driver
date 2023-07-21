/*
 * IncFile1.h
 *
 * Created: 23/06/23 9:35:55 PM
 *  Author: Esraa_Abdelanbe
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include "..\..\..\BIT_MATH.h"
#include "..\..\..\STD_TYPES.h"
#include "LED_TYPES.h"
#include "..\..\..\MCAL\DIO_DRIVER\INC\DIO.h"

void LEDs_init(void);
void LEDs_off(LED_COLOR);
void LEDs_on(LED_COLOR);
void LEDs_toggle(LED_COLOR);



#endif /* INCFILE1_H_ */