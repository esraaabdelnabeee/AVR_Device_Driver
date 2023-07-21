/*
 * I2C.h
 *
 * Created: 23/07/20 4:46:52 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "I2C_TYPES.h"
#include "I2C_Reg.h"
#include "../../DIO_DRIVER/INC/DIO.h"
extern const I2C_ConfigType I2C_Config;
typedef enum
{
	I2C_Ok,
	I2C_SC_Error,
	I2C_RSC_Error,
	I2C_SLA_W_Error,
	I2C_SLA_R_Error,
	I2C_DATA_Error,
	I2C_MR_DATA_Error,
	I2C_ARBITIRATION_ERROR
}I2C_Error_States;


void I2C_voidMasterInit(void);
void I2C_voidSlaveInit(u8 Copy_u8SlaveAdd);
I2C_Error_States I2C_enuSendStartCondition(void);
I2C_Error_States I2C_enuSendReStartCondition(void);
I2C_Error_States I2C_enuSendSlaveAddWithWrite(u8 Copy_u8SlaveAdd);
I2C_Error_States I2C_enuSendSlaveAddWithRead(u8 Copy_u8SlaveAdd);
I2C_Error_States I2C_enuMasterSendDataByte(u8 Copy_u8Data);
I2C_Error_States I2C_enuMasterReadDataByte(u8 * Copy_pu8Data);
I2C_Error_States I2C_Slave_voidListen(void);
I2C_Error_States I2C_Slave_enuReadu8Data(u8* I2C_DATA);
I2C_Error_States I2C_Slave_enuReadu8Data(u8* DATA);
void I2C_voidSendStopCondition(void);






#endif /* I2C_H_ */