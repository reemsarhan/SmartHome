/*
 * APP_slave_Macros.h

 *
 *  Created on: Sep 6, 2023
 *      Author: Reem
 */

#ifndef APP_APP_SLAVE_MACROS_H_
#define APP_APP_SLAVE_MACROS_H_

#include "../LIB/STD_TYPES.h"
#define AIR_CONDTIONING_ON          (u8)0x01
#define AIR_CONDTIONING_OFF			(u8)0x00


#define MOTOR_PIN    				1
#define AIR_COND_PIN				2
#define TV_PIN						3
#define ROOM1_PIN					4
#define ROOM2_PIN					5
//#define ROOM3_PIN					(u8)6
//#define ROOM4_PIN					(u8)7

#define AIR_COND_PORT 				3
#define TV_PORT       				3
#define ROOM1_PORT    				3
#define ROOM2_PORT   				3
//#define ROOM3_PORT   				(u8)'D'
//#define ROOM4_PORT    				(u8)'D'
#define MOTOR_PORT                  3
//fan set port pin


#endif /* APP_APP_SLAVE_MACROS_H_ */
