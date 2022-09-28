/************************************************/
/* Title       : Timer program file             */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "Timer_int.h"
#include "Timer_priv.h"
#include "Timer_config.h"

void (*TIMER0_OV_CallBack) (void) ;
void (*TIMER0_CTC_CallBack) (void) ;

void TIMER0_vidInit(void)
{
	#if( TIMER0_u8_MODE   == TIMER0_u8_NORMAL)
		CLEAR_BIT(TCCR0 , 6);
		CLEAR_BIT(TCCR0 , 3);
	
	#elif(TIMER0_u8_MODE  == TIMER0_u8_CTC)
		CLEAR_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		
	#elif(TIMER0_u8_MODE  == TIMER0_u8_FAST_PWM )
		SET_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		
	#elif(TIMER0_u8_MODE  == TIMER0_u8_PHASE_PWM )
		SET_BIT(TCCR0 , 6);
		CLEAR_BIT(TCCR0 , 3);
		
	#endif
	
	#if(TIMER0_u8_PRESCALER == TIMER0_u8_DIV_BY_1)
		SET_BIT(TCCR0 	, 0);
		CLEAR_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	
	#elif(TIMER0_u8_PRESCALER == TIMER0_u8_DIV_BY_8)
		CLEAR_BIT(TCCR0 , 0);
		SET_BIT(TCCR0   , 1);
		CLEAR_BIT(TCCR0 , 2);
	#elif(TIMER0_u8_PRESCALER == TIMER0_u8_DIV_BY_64 )
		SET_BIT(TCCR0   , 0);
		SET_BIT(TCCR0   , 1);
		CLEAR_BIT(TCCR0 , 2);
	#elif(TIMER0_u8_PRESCALER == TIMER0_u8_DIV_BY_256 )
		CLEAR_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0   , 2);
	#elif(TIMER0_u8_PRESCALER == TIMER0_u8_DIV_BY_1024 )
		SET_BIT(TCCR0   , 0);
		CLEAR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0   , 2);
		
	#endif
	
	#if(TIMER0_u8_COM_EVENT == TIMER0_u8_NO_ACTION)
		CLEAR_BIT(TCCR0 , 4);
		CLEAR_BIT(TCCR0 , 5);
		
	
	#elif(TIMER0_u8_COM_EVENT == TIMER0_u8_TOGGLE)
		SET_BIT(TCCR0 , 4)
		CLEAR_BIT(TCCR0 , 5);
	#elif(TIMER0_u8_COM_EVENT == TIMER0_u8_CLEAR )
		CLEAR_BIT(TCCR0 , 4);
		SET_BIT(TCCR0 , 5);
	#elif(TIMER0_u8_COM_EVENT == TIMER0_u8_SET )
		SET_BIT(TCCR0 , 4);
		SET_BIT(TCCR0 , 5);

		
	#endif
	/*Disable Interrupts*/
	CLEAR_BIT(TIMSK , 0);	
	CLEAR_BIT(TIMSK , 1);
	/*CLEAR Flags*/
	SET_BIT(TIFR , 0);	
	SET_BIT(TIFR , 1);
	/*Clear egister*/
	TCNT0 = 0 ;
	OCR0  = 0 ;
}

void TIMER0_vidSetTimerReg(u8 Copy_u8Val)
{
	TCNT0 = Copy_u8Val ;
}

void TIMER0_vidSetCompareVal(u8 Copy_u8Val)
{
	OCR0 = Copy_u8Val ;
}
void TIMER0_vidEnableOVInterrupt(void)
{
	SET_BIT(TIMSK , 0);
}
void TIMER0_vidDisableOVInterrupt(void)
{
	CLEAR_BIT(TIMSK , 0);
}
void TIMER0_vidEnableCTCInterrupt(void)
{
	SET_BIT(TIMSK , 1);
}
void TIMER0_vidDisableCTCInterrupt(void)
{
	CLEAR_BIT(TIMSK , 1);
}

void TIMER0_vidSetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_OV_CallBack = Copy_ptr ;
}
void TIMER0_vidSetCTCCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_CTC_CallBack = Copy_ptr ;
	
}

void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	
	TIMER0_OV_CallBack();
}

void __vector_10(void) __attribute__((signal , used));

void __vector_10(void)
{
	TIMER0_CTC_CallBack();
}
