/************************************************/
/* Title       : Timer configuration file       */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#ifndef _TIMER0_CONFIG_H
#define _TIMER0_CONFIG_H
/***********Timer0 MODES**********/
/*Range
#define TIMER0_u8_NORMAL 		
#define TIMER0_u8_CTC 			
#define TIMER0_u8_FAST_PWM 	
#define TIMER0_u8_PHASE_PWM 	
*/

#define TIMER0_u8_MODE TIMER0_u8_NORMAL
/********Timer0 Prescaler***********/
/*Range
#define TIMER0_u8_DIV_BY_1			
#define TIMER0_u8_DIV_BY_8			
#define TIMER0_u8_DIV_BY_64		
#define TIMER0_u8_DIV_BY_256		
#define TIMER0_u8_DIV_BY_1024		
*/
#define TIMER0_u8_PRESCALER  TIMER0_u8_DIV_BY_1

/*Range
#define TIMER0_u8_NO_ACTION	
#define TIMER0_u8_TOGGLE		
#define TIMER0_u8_SET			
#define TIMER0_u8_CLEAR		
*/

#define TIMER0_u8_COM_EVENT   TIMER0_u8_SET


#endif
