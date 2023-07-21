/*
 * SPO.c
 *
 * Created: 23/07/20 6:23:52 PM
 *  Author: ESRAA_ABDELNABE
 */ 
#include "../INC/SPI.h"
#include <stddef.h>
void (* SPI_interrupt)(void)= NULL;

void SPI_init(SPI_mode spimode)
{
	SET_BIT(SPCR_REG,SPE_BIT);
	SET_BIT(SPCR_REG,CPOL_BIT);
	SET_BIT(SPCR_REG,CPHA_BIT);
	CLEAR_BIT(SPCR_REG,SPR0_BIT);
	CLEAR_BIT(SPCR_REG,SPR1_BIT);
	switch(spimode)
	{
		case MASTER:
		SET_BIT(SPCR_REG,MSTR_BIT);
		//SET_BIT(SPI_PORT,SPI_CS);
		DIO_setPinDiretion(SPI_PORT,SPI_CS,OUTPUT);
		DIO_setPinDiretion(SPI_PORT,SPI_MOZI,OUTPUT);
		DIO_setPinDiretion(SPI_PORT,SPI_CLK,OUTPUT);

		break;
		case SLAVE:
		CLEAR_BIT(SPCR_REG, MSTR_BIT);
		//CLEAR_BIT(SPI_PORT, SPI_CS);
		DIO_setPinDiretion(SPI_PORT,SPI_CS,INPUT);
		DIO_setPinDiretion(SPI_PORT,SPI_MIZO,OUTPUT);
		DIO_setPinDiretion(SPI_PORT,SPI_CLK,INPUT);
		break;
		

		default:
		break;
	}
}

 u8  SPI_u8ReceiveByteSynch(u8 data)
 {
	SPDR_REG = data;
	while(!(SPSR_REG & (1<<SPIF_BIT)));
	return SPDR_REG;
 }
 void SPI_EnableInterrupt(void (*ptr)(void)){
	 SPI_interrupt = ptr;
 }