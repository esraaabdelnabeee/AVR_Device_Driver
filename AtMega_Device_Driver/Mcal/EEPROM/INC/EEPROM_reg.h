/*
 * EEPROM_reg.h
 *
 * Created: 23/07/13 12:23:16 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef EEPROM_REG_H_
#define EEPROM_REG_H_


#define EEAR (*(volatile u16 *)0x3E)
#define  EEDR   (*(volatile u8 *)0x3D)
#define EECR (*(volatile u8 *)0x3C)
#define   EERE        0
#define   EEWE        1
#define   EEMWE       2
#define   EERIE       3


#endif /* EEPROM_REG_H_ */