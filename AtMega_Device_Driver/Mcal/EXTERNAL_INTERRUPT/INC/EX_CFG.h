/*
 * EX_CFG.h
 *
 * Created: 23/07/13 12:33:07 PM
 *  Author: ESRAA_ABDELANBE
 */ 


#ifndef EX_CFG_H_
#define EX_CFG_H_
// GICR pins  **********
#define IVCE_GICR 0
#define IVSEL_GICR 1
#define INT2_GICR 5
#define INT0_GICR 6
#define INT1_GICR 7


// GIFR pins **********
#define INTF1_GIFR 7
#define INTF0_GIFR 6
#define INTF2_GIFR 5
//MCUCR pins **********
#define ISC00_MCUCR 0
#define ISC01_MCUCR 1
#define ISC10_MCUCR 2
#define ISC11_MCUCR 3
#define  SM0_MCUCR  4
#define  SM1_MCUCR  5
#define  SM2_MCUCR  6
#define  SE_MCUCR  7

// MCUCSR pins *********

#define  PORF_MCUCSR   0
#define  EXTRF_MCUCSR  1
#define  BORF_MCUCSR   2
#define  WDRF_MCUCSR  3
#define  JTRF_MCUCSR  4
#define  ISC2_MCUCSR   6
#define  JTD_MCUCSR  7




#endif /* EX_CFG_H_ */