/*
 * STD_MESSAGES.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Reem
 */

#ifndef APP_STD_MESSAGES_H_
#define APP_STD_MESSAGES_H_


#define ROOM1_STATUS    0x11
#define ROOM2_STATUS    0x12

#define TV_STATUS 		0x15
#define AIR_COND_STATUS 0x16

#define MOTOR_STATUS      0x17

//#define ROOM1_TURN_ON    0x21
//#define ROOM2_TURN_ON    0x22
#define ROOM1_TURN_ON    1
#define ROOM2_TURN_ON    2
#define TV_TURN_ON 		 3
#define AIR_COND_TURN_ON 4
#define MOTOR_TURN_ON    10

//#define TV_TURN_ON 		 0x25
//#define AIR_COND_TURN_ON 0x26

//#define ROOM1_TURN_OFF    0x31
//#define ROOM2_TURN_OFF    0x32
//
//#define TV_TURN_OFF 	  0x35
//#define AIR_COND_TURN_OFF 0x36
#define ROOM1_TURN_OFF    5
#define ROOM2_TURN_OFF   6

#define TV_TURN_OFF 	  7
#define AIR_COND_TURN_OFF 8

#define SET_TEMPERATURE 9
#define MOTOR_TURN_OFF    11

#define DEFAULT_ACK    0xFF
#define DEMAND_RESPONSE 0xFF

#define ON_STATUS   0x01
#define OFF_STATUS  0x00



#endif /* APP_STD_MESSAGES_H_ */
