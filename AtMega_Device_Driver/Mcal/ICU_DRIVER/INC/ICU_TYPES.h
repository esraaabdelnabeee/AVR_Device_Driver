/*
 * ICU_TYPES.h
 *
 * Created: 23/07/20 6:35:32 PM
 *  Author: ESRAA_ABDELANBE
 */ 


#ifndef ICU_TYPES_H_
#define ICU_TYPES_H_
typedef enum
{
	No_Clock_src,
	prescaler_none,
	prescaler_8,
	prescaler_64,
	prescaler_256,
	prescaler_1024
}timer1_Prescaler_t;

typedef enum
{
	Normal_mode
}TIMER1_mode_t;

typedef enum
{
	Falling_Edge,
	Rising_Edge
}catch_mode_t;



#endif /* ICU_TYPES_H_ */