/*
 * SPI_TYPES.h
 *
 * Created: 23/07/20 6:24:32 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_


typedef enum{

	SLAVE,
	MASTER
}SPI_mode;

typedef enum{
	MSB,
	LSB
}SPI_dataOrder;

typedef enum{
	RISINGD_EDGE,
	FALLING_EDGE
}SPI_clockPolarity;
typedef enum{
	SAMPLE,
	SETUP
}SPI_clockPhase;



#endif /* SPI_TYPES_H_ */