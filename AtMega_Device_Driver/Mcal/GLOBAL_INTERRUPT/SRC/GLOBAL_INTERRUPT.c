/*
 * GLOBAL_INTERRUPT.c
 *
 * Created: 23/07/13 12:29:28 PM
 *  Author: ESRAA_ABDELNABE
 */ 
#include "../../Global_interrupt/INC/GLOBAL_REG.h"
void Enable_Global_Inter()
{
	SET_BIT(SREG_REG,SREG_I);
	
}
void Disable_Global_Inter()
{
	CLEAR_BIT(SREG_REG,SREG_I);
}
