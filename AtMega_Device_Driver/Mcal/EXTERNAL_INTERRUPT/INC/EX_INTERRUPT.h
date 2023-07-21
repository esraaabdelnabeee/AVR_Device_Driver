/*
 * EX_INTERRUPT.h
 *
 * Created: 23/07/13 12:33:31 PM
 *  Author: ESRAA_ABDELANBE
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

#include "../../EXTERNAL_INTERRUPT/INC/EX_CFG.h"
#include "../../EXTERNAL_INTERRUPT/INC/EX_REG.h"
#include "../../EXTERNAL_INTERRUPT/INC/EX_TYPES.h"

void Enable_EX_Inter(INT_TYPES Int_TYPE ,TRIGGER_MODE mode,void (*ptr)(void) );
void Disable_EX_Inter(INT_TYPES Int_TYPE );



#endif /* EX_INTERRUPT_H_ */