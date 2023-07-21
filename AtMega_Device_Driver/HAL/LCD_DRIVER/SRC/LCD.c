/*
 * LCD.c
 *
 * Created: 23/07/13 12:16:22 PM
 *  Author: ESRAA_ABDELANBE
 */ 
#include "..\INC\LCD.h"




void lcd_init(void)
{
	DIO_setPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
	DIO_setPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	
	DIO_setPinDirection(LCD_D4_PORT,LCD_D4_PIN,OUTPUT);
	DIO_setPinDirection(LCD_D5_PORT,LCD_D5_PIN,OUTPUT);
	DIO_setPinDirection(LCD_D6_PORT,LCD_D6_PIN,OUTPUT);
	DIO_setPinDirection(LCD_D7_PORT,LCD_D7_PIN,OUTPUT);
	//_delay_ms(20);
	

	
	LCD_writeCMD(_LCD_4BIT_MODE_4lines);   // 2-LINE 4-BIT MODE INIT
	
	_delay_ms(10);
	LCD_writeCMD(_LCD_CURSOR_OFF);
	_delay_ms(10);
	LCD_writeCMD(_LCD_CLEAR);
	_delay_ms(10);
	LCD_writeCMD(_LCD_RETURN_CURSOR);
	_delay_ms(10);
	//lcd_vidGotoRowColumn(0, 0);
}



void LCD_writeCMD(u8 CMD)
{
	DIO_setPinChannel(LCD_RS_PORT,LCD_RS_PIN,LOW);
	_delay_ms(1);
	DIO_setPinChannel(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(1);
	
	DIO_setPinChannel(LCD_D4_PORT,LCD_D4_PIN,CHECK_BIT(CMD,4));
	DIO_setPinChannel(LCD_D5_PORT,LCD_D5_PIN,CHECK_BIT(CMD,5));
	DIO_setPinChannel(LCD_D6_PORT,LCD_D6_PIN,CHECK_BIT(CMD,6));
	DIO_setPinChannel(LCD_D7_PORT,LCD_D7_PIN,CHECK_BIT(CMD,7));
	
	_delay_ms(1);
	DIO_setPinChannel(LCD_EN_PORT, LCD_EN_PIN, LOW);
	_delay_ms(1);
	DIO_setPinChannel(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(1);
	
	DIO_setPinChannel(LCD_D4_PORT,LCD_D4_PIN,CHECK_BIT(CMD,0));
	DIO_setPinChannel(LCD_D5_PORT,LCD_D5_PIN,CHECK_BIT(CMD,1));
	DIO_setPinChannel(LCD_D6_PORT,LCD_D6_PIN,CHECK_BIT(CMD,2));
	DIO_setPinChannel(LCD_D7_PORT,LCD_D7_PIN,CHECK_BIT(CMD,3));
	_delay_ms(1);
	
	DIO_setPinChannel(LCD_EN_PORT, LCD_EN_PIN, LOW);
	_delay_ms(1);
	
}
void LCD_writeData(u8 data)
{
	DIO_setPinChannel(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	_delay_ms(1);
	DIO_setPinChannel(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(1);
	
	DIO_setPinChannel(LCD_D4_PORT,LCD_D4_PIN,CHECK_BIT(data,4));
	DIO_setPinChannel(LCD_D5_PORT,LCD_D5_PIN,CHECK_BIT(data,5));
	DIO_setPinChannel(LCD_D6_PORT,LCD_D6_PIN,CHECK_BIT(data,6));
	DIO_setPinChannel(LCD_D7_PORT,LCD_D7_PIN,CHECK_BIT(data,7));
	
	_delay_ms(1);
	DIO_setPinChannel(LCD_EN_PORT, LCD_EN_PIN, LOW);
	_delay_ms(1);
	DIO_setPinChannel(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(1);
	
	DIO_setPinChannel(LCD_D4_PORT,LCD_D4_PIN,CHECK_BIT(data,0));
	DIO_setPinChannel(LCD_D5_PORT,LCD_D5_PIN,CHECK_BIT(data,1));
	DIO_setPinChannel(LCD_D6_PORT,LCD_D6_PIN,CHECK_BIT(data,2));
	DIO_setPinChannel(LCD_D7_PORT,LCD_D7_PIN,CHECK_BIT(data,3));
	_delay_ms(1);
	
	DIO_setPinChannel(LCD_EN_PORT, LCD_EN_PIN, LOW);
	_delay_ms(2);
	
}

void LCD_writeString(u8* str)
{
	while (*str != '\0')
	{
		LCD_writeData(*str);
		str++;
	}
}

void lcd_vidGotoRowColumn(u8 row, u8 column);
