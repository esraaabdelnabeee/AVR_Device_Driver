/*
 * I2C_TYPES.h
 *
 * Created: 23/07/20 6:17:11 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef I2C_TYPES_H_
#define I2C_TYPES_H_

#include "../../../BIT_MATH.h"
#include "../../../STD_TYPES.h"
#define    READ                             (1)
#define    WRITE                            (0)
#define    REPEATED_START_TRUE              (1)
#define    REPEATED_START_FALSE             (0)
#define	   ACK_TRUE							(1)
#define    ACK_FALSE						(0)


typedef u8     READ_or_Write;
typedef u8     Repeated_Start;
typedef u8     Address_;

typedef enum
{
	ACKControl_OFF,
	ACKControl_ON,

}ACKControl_Mode;




typedef enum
{
	Prescaler_OFF,
	Prescaler_ON,

}Prescaler_Mode;


typedef enum
{
	Prescaler_4,
	Prescaler_16,
	Prescaler_64,

}Prescaler_Value;



typedef enum
{
	MASTER_MODE,
	SLAVE_MODE,

}I2C_MODE;


typedef struct
{
	I2C_MODE            I2Cmode;
	ACKControl_Mode     AckControlMode;
	Prescaler_Mode      PrescalerMode;
	Prescaler_Value     PrescalerValue;

}I2C_ConfigType;







#endif /* I2C_TYPES_H_ */