/*
 * TIMERS_config.h

 *

 */

#ifndef MCAL_TIMERS_TIMERS_CONFIG_H_
#define MCAL_TIMERS_TIMERS_CONFIG_H_
#include "TIMERS_priv.h"
//timer0 config
#define TIMER0_enable DISABLE

/*
 * options:
 * TIMER_OVF
 * TIMER_CTC
 * TIMER_FASTPWM
 * TIMER_PHASECORRECT
 *
 */
#define TIMER0_MODE TIMER_FASTPWM
#define TIMER0_prescaler TIMER_PS_8

//timer1 config
#define TIMER1_enable DISABLE

/*
 * options:
 * TIMER_NORMAL
 * TIMER_CTC
 * TIMER_FASTPWM
 * TIMER_PHASECORRECT
 *
 */
#define TIMER1_MODE TIMER_FASTPWM
#define TIMER1_prescaler TIMER_PS_8

//timer2 config
#define TIMER2_enable DISABLE

/*
 * options:
 * TIMER_NORMAL
 * TIMER_CTC
 * TIMER_FASTPWM
 * TIMER_PHASECORRECT
 *
 */
#define TIMER2_MODE TIMER_FASTPWM
#define TIMER2_prescaler TIMER_PS_8

#endif /* MCAL_TIMERS_TIMERS_CONFIG_H_ */
