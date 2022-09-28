/************************************************/
/* Title       : Timer Private file             */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/


#ifndef _TIMER0_PRIV_H_
#define _TIMER0_PRIV_H_
/* Timer 0 Registers */
#define TCNT0	 (*(volatile u8 * )0x52)
#define TCCR0	 (*(volatile u8 * )0x53)
#define TIFR 	 (*(volatile u8 * )0x58)
#define TIMSK	 (*(volatile u8 * )0x59)
#define OCR0 	 (*(volatile u8 * )0x5C)






#define TIMER0_u8_NORMAL 			1
#define TIMER0_u8_CTC 				2
#define TIMER0_u8_FAST_PWM 			3
#define TIMER0_u8_PHASE_PWM 		4

#define TIMER0_u8_DIV_BY_1			1
#define TIMER0_u8_DIV_BY_8			5
#define TIMER0_u8_DIV_BY_64			8
#define TIMER0_u8_DIV_BY_256		10
#define TIMER0_u8_DIV_BY_1024		15


#define TIMER0_u8_NO_ACTION			100
#define TIMER0_u8_TOGGLE			12
#define TIMER0_u8_SET				20
#define TIMER0_u8_CLEAR				25


#endif
