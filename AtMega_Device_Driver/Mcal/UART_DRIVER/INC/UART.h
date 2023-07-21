/*
 * UART.h
 *
 * Created: 23/07/13 12:48:47 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef UART_H_
#define UART_H_


#include "..\..\..\BIT_MATH.h"
#include "..\..\..\STD_TYPES.h"
#include "uart_reg.h"

#define UART_BAUDRATE_1200			(0x340)
#define UART_BAUDRATE_2400			(0x19F)
#define UART_BAUDRATE_4800			(0xCF)
#define UART_BAUDRATE_9600			(0x67)
#define UART_BAUDRATE_19200			(0x51)
#define UART_BAUDRATE_115200		(0x7)


#define UART_5_BIT_DATA				(0<<UCSZ0_BIT_NO)
#define UART_6_BIT_DATA				(1<<UCSZ0_BIT_NO)
#define UART_7_BIT_DATA				(2<<UCSZ0_BIT_NO)
#define UART_8_BIT_DATA				(3<<UCSZ0_BIT_NO)

#define UART_1_STOP_BIT				(0<<USBS_BIT_NO)
#define UART_2_STOP_BIT				(1<<USBS_BIT_NO)

#define UART_EVEN_PARITY			(2<<UPM0_BIT_NO)
#define UART_ODD_PARITY				(3<<UPM0_BIT_NO)

void UART_Init(u16 baudRate);
void UART_TransmitChr(u8 data);
void UART_TransmitStr(u8 *str);
u8 UART_ReceiveChr(void);
u8* UART_ReceiveStr();



#endif /* UART_H_ */