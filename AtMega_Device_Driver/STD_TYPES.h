/*
* STD_TYPES.h
*
* Created: 23/06/22 9:31:55 AM
*  Author: ESRAA_ABDELANBE
*/


#ifndef STD_TYPES_H_
#define STD_TYPES_H_
typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned long  u32;
typedef unsigned long  s32;

typedef unsigned long long u64;
typedef unsigned long long s64;

typedef float f32;
typedef enum
{
	OC,
	NOC
}ErrorStatus;
typedef enum
{
	TRUE,
	FALSE
}BOOLEAN;

#endif /* STD_TYPES_H_ */