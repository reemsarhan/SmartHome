/*
 * TIMERS_priv.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Rowan Madeeh
 */

#ifndef MCAL_TIMERS_TIMERS_PRIV_H_
#define MCAL_TIMERS_TIMERS_PRIV_H_

#define TCCR0		*((volatile u8*)(0x53))
#define TCNT0		*((volatile u8*)(0x52))
#define TCNT2		*((volatile u8*)(0x44))
#define TCNT1		*((volatile u16*)(0x4C))
#define OCR0		*((volatile u8*)(0x5C))
#define TIMSK		*((volatile u8*)(0x59))
#define TIFR		*((volatile u8*)(0x58))
#define TCCR2		*((volatile u8*)(0x45))
#define TCCR1B 		*((volatile u8*)(0x4E))
#define OCR2		*((volatile u8*)(0x43))
#define OCR1A		*((volatile u8*)(0x4A))
#define OCR1B		*((volatile u8*)(0x48))
#define ICR1L		*((volatile u8*)(0x46))
#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
#define CS10 0
#define TIMER_FASTPWM 0xC4
#define DISABLE 0
#define WGM01 3
#define WGM00 6
#define WGM10 0
#define WGM11 1
#define WGM12 3
#define WGM13 4
#define TCCR1A *((volatile u8*)(0x4F))
#define COM1A1 7
#define COM01 5
#define COM00 4
#define CS02 2
#define CS01 1
#define CS00 0
#define COM21 5
#define CS20 0
#define CS21 1
#define CS22 2
#define CS11 1
#define CS12 2
#define WGM20 6
#define WGM21 3
#endif /* MCAL_TIMERS_TIMERS_PRIV_H_ */
