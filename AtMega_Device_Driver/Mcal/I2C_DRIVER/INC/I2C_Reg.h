/*
 * I2C_Reg.h
 *
 * Created: 23/07/20 6:17:40 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef I2C_REG_H_
#define I2C_REG_H_

#include "../../../BIT_MATH.h"
#include "../../../STD_TYPES.h"
#define TWBR_REG					(*(volatile u8*)0x20)
#define TWSR_REG					(*(volatile u8*)0x21)
#define TWAR_REG					(*(volatile u8*)0x22)
#define TWDR_REG					(*(volatile u8*)0x23)
#define TWCR_REG					(*(volatile u8*)0x56)
#define START_FLAG           0x08
#define REP_START_FLAG       0x10
#define SLAVE_ACK_REC_FLAG   0x18
#define SLAVE_ACK_NREC_FLAG  0x20
#define DATA_ACK_FLAG			0x28
#define DATA_NACK_FLAG			0x30
#define ARBITRATION_LOST_FLAG	0x38


/* I2C --> TWBR Register Bits*/

#define   TWBR0                  (0)
#define   TWBR1                  (1)
#define   TWBR2                  (2)
#define   TWBR3                  (3)
#define   TWBR4                  (4)
#define   TWBR5                  (5)
#define   TWBR6                  (6)
#define   TWBR7                  (7)



/* I2C --> TWCR Register Bits*/

#define   TWIE                   (0)
#define   TWEN                   (2)
#define   TWWC                   (3)
#define   TWSTO                  (4)
#define   TWSTA                  (5)
#define   TWEA                   (6)
#define   TWINT                  (7)



/* I2C --> TWSR Register Bits*/

#define   TWPS0                  (0)
#define   TWPS1                  (1)
#define   TWS3                   (3)
#define   TWS4                   (4)
#define   TWS5                   (5)
#define   TWS6                   (6)
#define   TWS7                   (7)

/* I2C --> TWAR Register Bits*/

#define   TWGCE                  (0)
#define   TWA0                   (1)
#define   TWA1                   (2)
#define   TWA2                   (3)
#define   TWA3                   (4)
#define   TWA4                   (5)
#define   TWA5                   (6)
#define   TWA6                   (7)


/* READ -- WRITE BIT*/
#define   TWD0                   (0)



#endif /* I2C_REG_H_ */