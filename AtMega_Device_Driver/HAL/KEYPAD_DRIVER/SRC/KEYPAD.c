/*
 * KEYPAD.c
 *
 * Created: 23/06/23 10:00:20 PM
 *  Author: ESRAA_ABDELNABE
 */ 

#include "..\INC\KEYPAD.h"
void KEYPAD_init()
{
	DIO_setPinChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_PIN,OUTPUT);
	DIO_setPinChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_PIN,OUTPUT);
	DIO_setPinChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_PIN,OUTPUT);
	DIO_setPinChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_PIN,OUTPUT);
	
	DIO_setPinChannel(KEYPAD_COL1_PORT,KEYPAD_COL1_PIN,INPUT);
	DIO_setPinChannel(KEYPAD_COL2_PORT,KEYPAD_COL2_PIN,INPUT);
	DIO_setPinChannel(KEYPAD_COL3_PORT,KEYPAD_COL3_PIN,INPUT);
	DIO_setPinChannel(KEYPAD_COL4_PORT,KEYPAD_COL4_PIN,INPUT);
}

u8 KEYPAD_checkKey()
{
	u8 row;
	u8 matrix[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	
	DIO_setPinChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_PIN,HIGH);
	DIO_setPinChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_PIN,HIGH);
	DIO_setPinChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_PIN,HIGH);
	DIO_setPinChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_PIN,HIGH);
	for(row=0;row<4;row++)
	{
		if(row == 0) DIO_setPinChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_PIN,LOW);
		if(row == 1) DIO_setPinChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_PIN,LOW);
		if(row == 2) DIO_setPinChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_PIN,LOW);
		if(row == 3) DIO_setPinChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_PIN,LOW);

		if(READ_PIN_CHANNEL(KEYPAD_COL1_PORT,KEYPAD_COL1_PIN)==0 ) return matrix[row][0];
		if(READ_PIN_CHANNEL(KEYPAD_COL2_PORT,KEYPAD_COL2_PIN)==0 ) return matrix[row][1];
		if(READ_PIN_CHANNEL(KEYPAD_COL3_PORT,KEYPAD_COL3_PIN)==0 ) return matrix[row][2];
		if(READ_PIN_CHANNEL(KEYPAD_COL4_PORT,KEYPAD_COL4_PIN)==0 ) return matrix[row][3];
		
		if(row == 0) DIO_setPinChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_PIN,HIGH);
		if(row == 1) DIO_setPinChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_PIN,HIGH);
		if(row == 2) DIO_setPinChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_PIN,HIGH);
		if(row == 3) DIO_setPinChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_PIN,HIGH);
	}
	return 0;
}