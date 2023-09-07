/*
 * TIMERS_prog.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Rowan Madeeh
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BITMATH.h"

#include "TIMERS_init.h"
#include "TIMERS_priv.h"
#include "TIMERS_config.h"

static void (*G_Time_ovf)(void);
static void (*G_Time_ctc)(void);
static u32 G_u32Inteval_counter;

void MTIMERS_voidinit(u8 TIMER)
{
	switch(TIMER)
	{
		case TIMER0:

			#if TIMER0_MODE == TIMER_OVF
			CLR_BIT(TCCR0,WGM01);
			CLR_BIT(TCCR0,WGM00);
			#elif TIMER0_MODE == TIMER_CTC
			SET_BIT(TCCR0,WGM01);
			CLR_BIT(TCCR0,WGM00);
			#elif TIMER0_MODE == TIMER_FASTPWM
			SET_BIT(TCCR0,WGM01);
			SET_BIT(TCCR0,WGM00);
			#elif TIMER0_MODE == TIMER_PHASECORRECT
				CLR_BIT(TCCR0,WGM01);
				SET_BIT(TCCR0,WGM00);
			#else
			#error "please select a valid timer mode"
			#endif
			break;

		case TIMER1:

			#if TIMER1_MODE == TIMER_NORMAL
			CLR_BIT(TCCR1A, WGM10);
			CLR_BIT(TCCR1A, WGM11);
			CLR_BIT(TCCR1B, WGM12);
			CLR_BIT(TCCR1B, WGM13);
            #elif TIMER1_MODE == TIMER_CTC
			CLR_BIT(TCCR1A, WGM10);
			CLR_BIT(TCCR1A, WGM11);
			CLR_BIT(TCCR1B, WGM12);
			SET_BIT(TCCR1B, WGM13);
            #elif TIMER1_MODE == TIMER_FASTPWM
                CLR_BIT(TCCR1B, WGM13);
                CLR_BIT(TCCR1A, WGM11);
                SET_BIT(TCCR1B, WGM12);
                SET_BIT(TCCR1A, WGM10);
            #elif TIMER1_MODE == TIMER_PHASECORRECT
                CLR_BIT(TCCR1A, WGM10);
                SET_BIT(TCCR1A, WGM11);
                CLR_BIT(TCCR1B, WGM12);
                CLR_BIT(TCCR1B, WGM13);
            #else
               #error "Please select a valid timer mode"
            #endif
			break;

		case TIMER2:

            #if TIMER2_MODE == TIMER_NORMAL
			CLR_BIT(TCCR2, WGM20);
			CLR_BIT(TCCR2, WGM21);
            #elif TIMER2_MODE == TIMER_CTC
			CLR_BIT(TCCR2, WGM20);
			SET_BIT(TCCR2, WGM21);
            #elif TIMER2_MODE == TIMER_FASTPWM
			SET_BIT(TCCR2, WGM20);
			SET_BIT(TCCR2, WGM21);
            #elif TIMER2_MODE == TIMER_PHASECORRECT
			SET_BIT(TCCR2, WGM20);
            CLR_BIT(TCCR2, WGM21);
            #else
                #error "Please select a valid timer mode"
            #endif
			break;

		default:
			break;
	}

//	TCCR0 = 0b01101000;
}

void MTIMERS_voidSet_intervals_OVF(u8 A_u8TIMER_ID,u16 A_u16Interval_counts, void (*A_funptr)(void))
{
	G_u32Inteval_counter= A_u16Interval_counts;
	G_Time_ovf=A_funptr;

	//start timer
	MTIMERS_voidStart(A_u8TIMER_ID);
}

void MTIMERS_voidset_compare_value(u8 A_u8TIMER_ID,u16 A_u16compare_value)
{
	switch(A_u8TIMER_ID)
	{
		case TIMER0:OCR0=A_u16compare_value;break;
		case TIMER1:
			OCR1A = A_u16compare_value;   // Compare value for channel A
            OCR1B = A_u16compare_value;   // Compare value for channel B break;
            break;
		case TIMER2:OCR2 = A_u16compare_value; break;
	}
}

void MTIMERS_voidSet_intervals_CTC(u8 A_u8TIMER_ID,u16 A_u16Interval_counts,u16 A_u16compare_value, void (*A_funptr)(void))
{
	G_u32Inteval_counter= A_u16Interval_counts;
	G_Time_ctc=A_funptr;
	MTIMERS_voidset_compare_value(A_u8TIMER_ID,A_u16compare_value);
	//start timer
	MTIMERS_voidStart(A_u8TIMER_ID);
}

void MTIMERS_voidPreload_value(u8 A_u8TIMER_ID,u16 A_u16Preload)
{
	switch(A_u8TIMER_ID)
	{
		case TIMER0:TCNT0 = A_u16Preload;break;
		case TIMER1:TCNT1 = A_u16Preload;break;
		case TIMER2:TCNT2 = A_u16Preload;break;
	}

}

void MTIMERS_voidStart(u8 A_u8TIMER_ID)
{
	switch(A_u8TIMER_ID)
	{
		case TIMER0:
			TCNT0 =0;
			TCCR0|= (1<<COM01)|(0<<CS02)|(1<<CS01)|(1<<CS00);
			break;
		case TIMER1:
			TCCR1B |= (1 << CS10)| (1<<CS11)| (0<<CS12);
			TCCR1A |= (1<<COM1A1);
			ICR1L=4999;
			break;
		case TIMER2:
			TCNT2 =0;
			TCCR2|=(1<<COM21)|(0<<CS20)|(0<<CS21)|(1<<CS22);
			break;
	}
}

void MTIMERS_voidStop (u8 A_u8TIMER_ID)
{
	switch(A_u8TIMER_ID)
	{
		case TIMER0:TCCR0= (TCCR0 &0b11111000) | (0b000);break;
		case TIMER1:TCCR1B &= ~(1 << CS10);break;
		case TIMER2:TCCR2 &= 0b11111000;break;
	}
}

void __vector_10 (void)	__attribute__((signal));
void __vector_10 (void)
{
	static u32 Ls_u32Counter=0;

	Ls_u32Counter++;

	if(Ls_u32Counter== G_u32Inteval_counter){
		G_Time_ctc();
		Ls_u32Counter=0;
	}

}

void __vector_11 (void)	__attribute__((signal));
void __vector_11 (void)
{
	static u32 Ls_u32Counter=0;

	Ls_u32Counter++;

	if(Ls_u32Counter== G_u32Inteval_counter){
		G_Time_ovf();
		Ls_u32Counter=0;
	}

}
