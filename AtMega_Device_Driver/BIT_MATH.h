/*
 * BIT_MATH.h
 *
 * Created: 23/06/22 9:31:34 AM
 *  Author: ESRAA_ABDELANBE
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM) (REG  = REG | (1<<BIT_NUM))
#define CLEAR_BIT(REG,BIT_NUM) (REG  = REG & ~(1<<BIT_NUM))
#define TOGGLE_BIT(REG,BIT_NUM) (REG  = REG ^ (1<<BIT_NUM))
#define CHECK_BIT(REG,BIT_NUM) ((REG >> BIT_NUM) &1 )





#endif /* BIT_MATH_H_ */