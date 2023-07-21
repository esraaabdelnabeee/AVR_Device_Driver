/*
 * DIO_TYPES.h
 *
 * Created: 23/06/23 8:49:01 PM
 *  Author: Esraa_AbdElnabe
 */ 


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_
//  port id
typedef enum {
	PORTA,
	PORTB,
	PORTC,
	PORTD
}PORT_ID;
//pin _id
typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
	
}PIN_ID;
// pin_Direction
typedef enum
{
	INPUT,
	OUTPUT
}PIN_DIR;
//pin_level
typedef enum
{
	HIGH,
	LOW
}PIN_LEVEL;



#endif /* DIO_TYPES_H_ */