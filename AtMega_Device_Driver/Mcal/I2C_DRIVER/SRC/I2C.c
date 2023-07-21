/*
 * I2C.c
 *
 * Created: 23/07/20 4:47:20 PM
 *  Author: ESRAA_ABDELNABE
 */ 
#include "../INC/I2C.h"
#define I2C_STATUS_CODE_MASK 0xf8
#define I2C_STATUS_CODE_MASK 0xf8
void I2C_voidMasterInit(void){
	TWBR_REG=0x02;					/* Set frequency 400 khz , prescalar value 0 */
	TWCR_REG=(1<<TWEA)|(1<<TWEN);
	/* Enable I2C */
}
void I2C_voidSlaveInit(u8 Slave_Add){
	
	TWAR_REG=Slave_Add;				/* Set Slave Address In TWAR */
	TWCR_REG=(1<<TWEA)|(1<<TWEN);

}
I2C_Error_States I2C_enuSendStartCondition(void)
{
	TWCR_REG=(1<<TWSTA)|(1<<TWINT)|(1<<TWEN);
	while(CHECK_BIT(TWCR_REG,TWINT));
	if(START_FLAG==(TWSR_REG&I2C_STATUS_CODE_MASK))
	{
		return I2C_Ok;
	}
	else {
		return I2C_SC_Error;
	}
}
I2C_Error_States I2C_enuSendReStartCondition(void)
{
	TWCR_REG=(1<<TWSTA)|(1<<TWINT)|(1<<TWEN);
	while(CHECK_BIT(TWCR_REG,TWINT));
	if(REP_START_FLAG==(TWSR_REG&I2C_STATUS_CODE_MASK))
	{
		return I2C_Ok;
	}
	else {
		return I2C_RSC_Error;
	}
}
I2C_Error_States I2C_enuSendSlaveAddWithWrite(u8 SlaveAdd)
{
	TWDR_REG=SlaveAdd&0xfe;
	TWCR_REG=(0<<TWSTA)|(1<<TWINT)|(1<<TWEN);
	SET_BIT(TWDR_REG,0);
	while(CHECK_BIT(TWCR_REG,TWINT));
	if(SLAVE_ACK_REC_FLAG==(TWSR_REG&I2C_STATUS_CODE_MASK))
	{
		return I2C_Ok;
	}
	else {
		return I2C_RSC_Error;
	}
}
I2C_Error_States I2C_enuSendSlaveAddWithRead(u8 SlaveAdd)
{
	TWDR_REG=SlaveAdd&0xfe;
	TWCR_REG=(0<<TWSTA)|(1<<TWINT)|(1<<TWEN);
	SET_BIT(TWDR_REG,0);
	while(CHECK_BIT(TWCR_REG,TWINT));
	if(SLAVE_ACK_NREC_FLAG==(TWSR_REG&I2C_STATUS_CODE_MASK))
	{
		return I2C_Ok;
	}
	else {
		return I2C_SLA_R_Error;
	}
}
I2C_Error_States I2C_enuMasterSendDataByte(u8 Data)
{
	TWDR_REG=Data;
	
	TWCR_REG = (1<<TWINT) | (1<<TWEN);
	while (CHECK_BIT(TWCR_REG,TWINT));
	if (DATA_ACK_FLAG==(TWSR_REG&I2C_STATUS_CODE_MASK))
	{
		return I2C_Ok;
	}
	else {
		return I2C_DATA_Error;
	}
}
I2C_Error_States I2C_enuMasterReadDataByte(u8 *Data)
{
	*Data=TWDR_REG;
	TWCR_REG = (1<<TWINT) | (1<<TWEN);
	while(CHECK_BIT(TWCR_REG,TWINT));
	if(DATA_NACK_FLAG==(TWSR_REG&I2C_STATUS_CODE_MASK))
	{
		return I2C_Ok;
	}
	else {
		return I2C_MR_DATA_Error;
	}
}
I2C_Error_States I2C_Slave_voidListen(void)
{
	TWCR_REG = (1<<TWEN);
	while(CHECK_BIT(TWCR_REG,TWINT));
	if(ARBITRATION_LOST_FLAG==(TWSR_REG&I2C_STATUS_CODE_MASK))
	{
		return I2C_Ok;
	}
	else {
		return I2C_ARBITIRATION_ERROR;
	}
}
I2C_Error_States I2C_Slave_enuReadu8Data(u8* DATA)
{
	*DATA=TWDR_REG;
	TWCR_REG=(1<<TWINT);
	while(CHECK_BIT(TWCR_REG,TWINT));
	if(DATA_NACK_FLAG==(TWSR_REG&I2C_STATUS_CODE_MASK))
	{
		return I2C_Ok;
	}
	else {
		return I2C_DATA_Error;
	}
}
void I2C_voidSendStopCondition(void)
{
	// 	SET_BIT(TWSR_REG,TWSTA);
	// 	SET_BIT(TWCR_REG,TWINT);
	TWCR_REG=(1<<TWSTA)|(1<<TWINT)|(1<<TWEN);
}