/*
 * main_config.h



 *
 *  Created on: Sep 5, 2023
 *      Author: Reem
 */

#ifndef APP_MAIN_CONFIG_H_
#define APP_MAIN_CONFIG_H_

#include "../LIB/STD_TYPES.h"

/****************************   Show menu codes  *****************************************/



#define NOT_STORED   0xFF
#define NOT_SELECTED 0xFF

#define FALSE   (u8)0
#define TRUE    (u8)1

#define SELECT_ROOM1            (u8)'1'
#define SELECT_ROOM2            (u8)'2'
#define SELECT_TV               (u8)'3'
#define USER_MORE_OPTION        (u8)'4'
//#define SELECT_ROOM3            (u8)'3'
//#define SELECT_ROOM4            (u8)'4'


//#define SELECT_ROOM4_USER     (u8)'1'
//#define SELECT_TV               (u8)'2'
#define SELECT_AIR_CONDITIONING (u8)'1'
#define SELECT_FAN              (u8)'2'
#define RET_OPTION              (u8)'3'

#define SELECT_SET_TEMPERATURE  (u8)'1'
#define SELECT_AIR_COND_CTRL    (u8)'2'
#define SELECT_AIR_COND_RET     (u8)'0'


#define MAIN_MENU            1
#define MORE_MENU            2
#define ROOM1_MENU           3
#define ROOM2_MENU           4
//#define ROOM3_MENU           5
//#define ROOM4_MENU           6
#define TV_MENU              7
#define AIRCONDITIONING_MENU 8
#define AIRCOND_CTRL_MENU    9
#define TEMPERATURE_MENU     10
#define FAN_MENU             11

#define BLOCK_MODE_TIME		   (u32)20000
#define CHARACTER_PREVIEW_TIME (u16)300
#define DEGREES_SYMBOL		   (u8)0xDF



/*****************************************************************************************/



#endif /* APP_MAIN_CONFIG_H_ */
