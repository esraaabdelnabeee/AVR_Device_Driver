/*
 * SPI.h
 *
 * Created: 23/07/20 6:24:17 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "SPI_TYPES.h"
#include "SPI_REG.h"
#include "../../../BIT_MATH.h"
#include "../../../STD_TYPES.h"
#include "../../DIO_DRIVER/INC/DIO.h"
#define  SPI_PORT PORTB
#define  SPI_MOZI PIN5
#define  SPI_MIZO PIN6
#define  SPI_CS   PIN4
#define  SPI_CLK  PIN7
void SPI_init(SPI_mode spimode);
//void SPI_voidInit(SPI_mode);
ErrorStatus  SPI_u8SendByteSynch(u8 Data);
u8  SPI_u8ReceiveByteSynch(u8 Data);
ErrorStatus  SPI_u8_Send_Receive_ByteSynch(u8 Data_S,u8 *Data_R);
ErrorStatus  SPI_u8SendReceiveBufferASynch(u8 *Data_S,u8 *Data_R,u8 BufferSize,void(*NotificationFuction)(void));



#endif /* SPI_H_ */