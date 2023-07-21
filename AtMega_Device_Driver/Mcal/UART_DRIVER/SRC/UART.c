/*
 * UART.c
 *
 * Created: 23/07/13 12:49:16 PM
 *  Author: ESRAA_ABDELNABE
 */ 
#include "..\INC\UART.h"
#include <stddef.h>
#include <avr/interrupt.h>

u8 BB[32]={'\0'};
void (* UART_RX_INTERRUPT)(void)=NULL; 
void (* UART_TX_INTERRUPT)(void)=NULL;
ISR(USART_RXC_vect){

	if (UART_RX_INTERRUPT != NULL){
		UART_RX_INTERRUPT();
	}
}


ISR(USART_TXC_vect){

	if (UART_TX_INTERRUPT != NULL){
		UART_TX_INTERRUPT();
	}
}
void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRH_REG = (u8)(baudRate>>8);
	UART_UBRRL_REG = (u8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	
 	SET_BIT(UART_UCSRB_REG,RXC_BIT_NO);
	 
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO)|UART_8_BIT_DATA | UART_EVEN_PARITY;
}

void UART_TransmitChr(u8 data)
{
	/* Wait for empty transmit buffer */
	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
			;
	/* Put data into buffer, sends the data */
	UART_UDR_REG = data;
}

u8 UART_ReceiveChr(void)
{
	/* Wait for data to be received */
	while (!(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
			;
	/* Get and return received data from buffer */
	return UART_UDR_REG;
}
void UART_TransmitStr(u8 *str)
{
	int i=0;
	while(str[i]!='\n')
	{
		UART_TransmitChr(str[i]);
	i++;
	}
	
}

u8* UART_ReceiveStr()
{
	u8 i=0;
	char c=0;
	c=UART_UDR_REG;
	while( i<=31)
	{
	while (!(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)));
		if(c=='#'||c=='&')
		{
			BB[i]= '/0';
			break;
		}
			BB[i]=c;
			i++;
			c=UART_UDR_REG;
	}
	return BB;
}
void UART_EnableInterrupt(void (*ptr)(void)){
	UART_RX_INTERRUPT = ptr;
}

