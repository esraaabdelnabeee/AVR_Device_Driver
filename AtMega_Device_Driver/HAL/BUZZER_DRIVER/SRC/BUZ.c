/*
* BUZ.c
*
* Created: 23/06/23 10:08:58 PM
*  Author: ESRAA_ABDELNABE
*/
#include "../INC/BUZ.h"
void BUZ_INIT(void)
{
	DIO_setPinChannel(PORTC,PIN6,OUTPUT);

}
void BUZ_TurnON(void)
{
	DIO_setPinChannel(PORTC,PIN6,HIGH);

}
void BUZ_TurnOFF(void)
{
	DIO_setPinChannel(PORTC,PIN6,LOW);
}
void BUZ_TOGGLE(void)
{
	DIO_FLIP_Channel(PORTC,PIN6);
}