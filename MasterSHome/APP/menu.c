/*
 * menu.c

 *
 *  Created on: Sep 5, 2023
 *      Author: Reem
 */


#include "../LIB/BITMATH.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KeyPad/KPD_int.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/SPI/SPI_Init.h"
#include "../APP/main_config.h"
#include "../APP/STD_MESSAGES.h"

void vMenuOption(const u8 u8SelectedRoom)
{
	u8 u8StatusCode  = 0;//demand status code
	u8 u8TurnOnCode  = 0;//turn on the room or the device code
	u8 u8TurnOffCode = 0;//turn off the device or room
	u8 response      = DEFAULT_ACK;//the response of the slave that is sent back based on the command of the master
	u8 key_pressed   = NOT_PRESSED;//the key that is entered by the user

	do
	{
		HLCD_voidClear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row

		/*********** ****************Set the commands to be sent to the slave based on  the sent room or device ******************************/
		switch(u8SelectedRoom)
		{
			case ROOM1_MENU:
			u8StatusCode = ROOM1_STATUS;
			u8TurnOnCode = ROOM1_TURN_ON;
			u8TurnOffCode = ROOM1_TURN_OFF;
			HLCD_voidSendString((u8 *)"Room1:");

			break;

			case ROOM2_MENU:
			u8StatusCode = ROOM2_STATUS;
			u8TurnOnCode = ROOM2_TURN_ON;
			u8TurnOffCode = ROOM2_TURN_OFF;
			HLCD_voidSendString((u8 *)"Room2:");
			break;

			case TV_MENU:
			u8StatusCode = TV_STATUS;
			u8TurnOnCode = TV_TURN_ON;
			u8TurnOffCode = TV_TURN_OFF;
			HLCD_voidSendString((u8 *)"TV:");
			break;
			case AIRCOND_CTRL_MENU:
			u8StatusCode = AIR_COND_STATUS;
			u8TurnOnCode = AIR_COND_TURN_ON;
			u8TurnOffCode = AIR_COND_TURN_OFF;
			HLCD_voidSendString((u8 *)"Air Cond:");
			break;

			case FAN_MENU:
					u8StatusCode = FAN_MENU;
					u8TurnOnCode = FAN_TURN_ON;
					u8TurnOffCode = FAN_TURN_OFF;
					HLCD_voidSendString((u8 *)"FAN:");
					break;

		}
		/****************************************************************************************************/
//		MSPI_voidMasterTranceive(u8StatusCode);//demand the status from the slave
//		_delay_ms(100);//Halt the system for the given time in (ms)
//		response = MSPI_voidMasterTranceive(DEMAND_RESPONSE);//the master micro controller asks for the status
//		if(response == ON_STATUS)//if the response from the slave was on status
//		{
//			HLCD_voidSendString((u8 *)"ON");//print the status on
//		}
//		else//if the response from the slave was off status
//		{
//			HLCD_voidSendString((u8 *)"OFF");//print the status off
//		}
		HLCD_voidSetCursor(2,1);//move the cursor to the start of the second line
		HLCD_voidSendString((u8 *)"1-On 2-Off 0-RET");//print the sub menu



		key_pressed =HKPD_u8GetPressedKey();//wait for the user till key is pressed or the time is out
		_delay_ms(100);//to avoid the duplication of the pressed key

		if (key_pressed == '1')
		{
			MSPI_voidMasterTranceive(u8TurnOnCode);//Send turn on signal from master to slave
		}
		else if (key_pressed == '2')
		{
			MSPI_voidMasterTranceive(u8TurnOffCode);//Send turn off signal from master to slave
		}
		else if( (key_pressed != NOT_PRESSED) && (key_pressed != '0') )//show wrong input message if the user entered non numeric value
		{
			HLCD_voidClear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
			HLCD_voidSendString((u8 *)"Wrong input");//print error message
			_delay_ms(500);//Halt the system for the given time in (ms)
		}



//		HLCD_voidSetCursor(2,1);//move the cursor to the start of the second line
//		HLCD_voidSendString((u8 *)"1-On 2-Off 0-RET");//print the sub menu

//		/*******************************************************************************/
//
//		key_pressed =HKPD_u8GetPressedKey();//wait for the user till key is pressed or the time is out
//		_delay_ms(100);//to avoid the duplication of the pressed key
//
//		/*there is no need to take any action in case of the user pressed 0(RET) key
//		breaking the loop will be enough since it will be handled in the main*/
//
//		if (key_pressed == '1')
//		{
//			MSPI_voidMasterTranceive(u8TurnOnCode);//Send turn on signal from master to slave
//		}
//		else if (key_pressed == '2')
//		{
//			MSPI_voidMasterTranceive(u8TurnOffCode);//Send turn off signal from master to slave
//		}
//		else if( (key_pressed != NOT_PRESSED) && (key_pressed != '0') )//show wrong input message if the user entered non numeric value
//		{
//			HLCD_voidClear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
//			HLCD_voidSendString((u8 *)"Wrong input");//print error message
//			_delay_ms(500);//Halt the system for the given time in (ms)
//		}
	} while ( ( (key_pressed < '0') || (key_pressed > '2') ) );//break the loop in case of valid key or time is out
}



