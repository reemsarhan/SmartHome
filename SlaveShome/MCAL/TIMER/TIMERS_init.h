/*
 * TIMERS_init.h
 
 */

#ifndef MCAL_TIMERS_TIMERS_INIT_H_
#define MCAL_TIMERS_TIMERS_INIT_H_
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BITMATH.h"

void MTIMERS_voidinit(u8 TIMER);
void MTIMERS_voidSet_intervals_OVF(u8 A_u8TIMER_ID,u16 A_u16Interval_counts, void (*A_funptr)(void));
void MTIMERS_voidset_compare_value(u8 A_u8TIMER_ID,u16 A_u16compare_value);
void MTIMERS_voidSet_intervals_CTC(u8 A_u8TIMER_ID,u16 A_u16Interval_counts, u16 A_u16compare_value,void (*A_funptr)(void));
void MTIMERS_voidPreload_value(u8 A_u8TIMER_ID, u16 A_u16Preload);
void MTIMERS_voidStart(u8 A_u8TIMER_ID);
void MTIMERS_voidStop (u8 A_u8TIMER_ID);

#endif /* MCAL_TIMERS_TIMERS_INIT_H_ */
