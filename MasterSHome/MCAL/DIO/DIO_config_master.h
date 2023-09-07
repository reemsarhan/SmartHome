/*
 * DIO_config_master.h


 *
 *  Created on: Sep 5, 2023
 *      Author: Reem
 */

#ifndef MCAL_DIO_DIO_CONFIG_MASTER_H_
#define MCAL_DIO_DIO_CONFIG_MASTER_H_



/*****************************  Ports and pins of input and output pins ******************/
#define USER_LED_PORT (u8)'C'
//#define GUEST_LED_PORT (uint8)'C'
//#define BLOCK_LED_PORT (uint8)'C'

#define USER_LED_PIN  (u8)0
//#define GUEST_LED_PIN  (uint8)1
//#define BLOCK_LED_PIN  (uint8)2
/*****************************************************************************************/

/* keypad Macros */
#define KEYPAD_PORT			(u8)'D'
#define KEYPAD_FIRST_PIN	(u8)0
#define KEYPAD_SECOND_PIN	(u8)1
#define KEYPAD_THIRD_PIN	(u8)2
#define KEYPAD_FOURTH_PIN	(u8)3
#define KEYPAD_FIFTH_PIN	(u8)4
#define KEYPAD_SIXTH_PIN	(u8)5
#define KEYPAD_SEVENTH_PIN	(u8)6
#define KEYPAD_EIGHTH_PIN	(u8)7

/* LCD Macros */
#define LCD_PORT			(u8)'A'
#define LCD_FIRST_PIN		(u8)0
#define LCD_SECOND_PIN		(u8)1
#define LCD_THIRD_PIN		(u8)2
#define LCD_FOURTH_PIN		(u8)3
#define LCD_FIFTH_PIN		(u8)4
#define LCD_SIXTH_PIN		(u8)5
#define LCD_SEVENTH_PIN		(u8)6
#define LCD_EIGHTH_PIN		(u8)7
#define LCD_CONTROL_PORT	(u8)'B'
#define LCD_EN_PIN			(u8)0
#define LCD_RS_PIN			(u8)1
#define LCD_RW_PIN			(u8)2


#endif /* MCAL_DIO_DIO_CONFIG_MASTER_H_ */
