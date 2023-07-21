/*
 * ADC.h
 *
 * Created: 23/06/15 10:42:19 PM
 *  Author: ESRAA_ABDELNABE
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "..\..\..\MCAL\DIO__DRIVER\INC\DIO.h"
#include "..\..\..\BIT_MATH.h"
#include "ADC_REG.h"
#include "ADC_TYPES.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#define Step_Size  (4.8)
void INIT_ADC();
u8 READ_ADC_VAL(dio_pinID_t PINID);



#endif /* ADC_H_ */