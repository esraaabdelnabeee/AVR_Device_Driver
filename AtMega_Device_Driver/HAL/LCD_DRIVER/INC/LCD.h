/*
 * LCD.h
 *
 * Created: 23/07/13 12:14:41 PM
 *  Author: ESRAA_ABDELANBE
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "..\..\..\BIT_MATH.h"
#include "..\..\..\STD_TYPES.h"
#include "..\..\..\Mcal\DIO_DRIVER\INC\DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include "LCD_Types.h"
#include "LCD_cfg.h"

void lcd_init(void);
void LCD_writeCMD(u8);
void LCD_writeData(u8);
void LCD_writeString(u8*);




#endif /* LCD_H_ */