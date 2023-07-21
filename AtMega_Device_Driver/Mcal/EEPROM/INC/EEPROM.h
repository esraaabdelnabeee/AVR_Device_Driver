/*
 * EEPROM.h
 *
 * Created: 23/07/13 12:24:26 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "EEPROM_reg.h"
#include "..\..\..\Mcal\DIO_DRIVER\INC\DIO.h"
#include "..\..\..\BIT_MATH.h"
void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
unsigned char EEPROM_read(unsigned int uiAddress);






#endif /* EEPROM_H_ */