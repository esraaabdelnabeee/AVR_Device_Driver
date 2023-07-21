/*
 * SPI_REG.h
 *
 * Created: 23/07/20 6:24:44 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_



#define SPDR_REG (*(volatile u8 *)(0x2F))


#define SPSR_REG (*(volatile u8 *)(0x2E))
#define SPI2X_BIT		(0)
#define WCOL_BIT		(6)
#define SPIF_BIT		(7)


#define SPCR_REG (*(volatile u8 *)(0x2D))
#define SPR0_BIT		(0)
#define SPR1_BIT		(1)
#define CPHA_BIT		(2)
#define CPOL_BIT		(3)
#define MSTR_BIT		(4)
#define DORD_BIT		(5)
#define SPE_BIT			(6)
#define SPIE_BIT		(7)



#endif /* SPI_REG_H_ */