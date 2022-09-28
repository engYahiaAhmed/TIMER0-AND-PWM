/************************************************/
/* Title       : Timer interface file           */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#ifndef _TIMER0_INT_H
#define _TIMER0_INT_H


void TIMER0_vidInit(void);

void TIMER0_vidSetTimerReg(u8 Copy_u8Val);

void TIMER0_vidSetCompareVal(u8 Copy_u8Val);

void TIMER0_vidEnableOVInterrupt(void);

void TIMER0_vidDisableOVInterrupt(void);

void TIMER0_vidEnableCTCInterrupt(void);

void TIMER0_vidDisableCTCInterrupt(void);

void TIMER0_vidSetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER0_vidSetCTCCallBack(void (*Copy_ptr) (void) ) ;


#endif