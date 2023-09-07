/*
 * main.c




 *
 *  Created on: Sep 5, 2023
 *      Author: Reem
 */


#include"../LIB/BITMATH.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LED/LED.h"
#include "../HAL/KeyPad/KPD_int.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/SPI/SPI_Init.h"
#include "../MCAL/SPI/SPI_Cfg.h"
#include "../MCAL/SPI/SPI_Prv.h"
#include "main_config.h"
#include "STD_MESSAGES.h"
#include "menu.h"



int main()
{


	u8 temperature = 0;//The average temperature of the room
	u8 temp_ones = NOT_SELECTED;//The entered right number of the temperature
	u8 temp_tens = NOT_SELECTED;//The entered left number of the temperature


	u8 key_pressed = NOT_PRESSED;


	/*****************  INITIALIZE  ***********************/
	HLCD_void8bitInit();//initializes the LCD screen
	HKPD_voidInit();//initializes the keypad
	MSPI_voidMasterIntial();//initializes the communication protocol of SPI
	/******************************************************/


	/* Printing Welcome screen */
	HLCD_voidSendString((u8 *)"Welcome to RSR smart");
	HLCD_voidSetCursor(2,1);
	HLCD_voidSendString((u8 *)"home system ^_^");
	_delay_ms(100);//Halt the system for the given time in (ms)
	HLCD_voidClear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
	HLCD_voidSendString((u8 *)"MENU: ");
	HLCD_voidSetCursor(2,1);
	_delay_ms(100);//Halt the system for the given time in (ms)


	u8 show_menu = MAIN_MENU;

	while(1)
	{

	key_pressed = NOT_PRESSED;//Set the key pressed by the user to its default value
				switch (show_menu)
				{
					case MAIN_MENU:
					do
					{
						/******************** print main Menu ******************/
						HLCD_voidClear();

						HLCD_voidSendString((u8 *)"1:Room1 2:Room2");
						HLCD_voidSetCursor(2,1);
						HLCD_voidSendString((u8 *)"3:TV    4:MORE");

						key_pressed = HKPD_u8GetPressedKey();//wait for the user till key is pressed or the time is out

						_delay_ms(100);//to avoid the duplication of the pressed key

						if (key_pressed == SELECT_ROOM1)//If key pressed is 1
						{
							show_menu = ROOM1_MENU;//Set the next menu to be shown to room1 menu
						}
						else if (key_pressed == SELECT_ROOM2)//If key pressed is 2
						{
							show_menu = ROOM2_MENU;//Set the next menu to be shown to room2 menu
						}
							else if (key_pressed == SELECT_TV )//If key pressed is 4 and the logged in user is admin
						{
							show_menu = TV_MENU;//Set the next menu to be shown to more menu
						}
						else if (key_pressed == USER_MORE_OPTION )//If key pressed is 4 and the logged in user is admin
						{
							show_menu = MORE_MENU;//Set the next menu to be shown to more menu
						}

						else if(key_pressed != NOT_PRESSED)//show wrong input message if the user pressed wrong key
						{
							HLCD_voidClear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
							HLCD_voidSendString((u8 *)"Wrong input");

							_delay_ms(500);//Halt the system for the given time in (ms)
						}
					} while ( ((key_pressed < '1') || (key_pressed > '4') ));//break the loop in case of valid key or time is out

					break;//End of main menu case


					case MORE_MENU:
					do
					{
						/******************** print more Menu ******************/

					    HLCD_voidClear();
						HLCD_voidSendString((u8 *)"1:AIRCON 2:FAN");
						HLCD_voidSetCursor(2,1);
					    HLCD_voidSendString((u8 *)"3:RET");
						/*******************************************************/
						key_pressed = HKPD_u8GetPressedKey();//wait for the user till key is pressed or the time is out
						_delay_ms(100);//to avoid the duplication of the pressed key

						if (key_pressed == SELECT_AIR_CONDITIONING)//If key pressed is 1
						{
							show_menu = AIRCONDITIONING_MENU;//Set the next menu to be shown to room4 menu
						}
						else if (key_pressed == SELECT_FAN)//If key pressed is 3
						{
							show_menu = FAN_MENU;//Set the next menu to be shown to Air conditioning menu
						}
						else if (key_pressed == RET_OPTION)//If key pressed is 4 (RET)
						{
							show_menu = MAIN_MENU;//Set the next menu to be shown to main menu
						}
						else if(key_pressed != NOT_PRESSED)//show wrong input message if the user pressed wrong key
						{
							  HLCD_voidClear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
							  HLCD_voidSendString((u8 *)"Wrong input");
							_delay_ms(500);//Halt the system for the given time in (ms)
						}
					} while (( (key_pressed < '1') || (key_pressed > '4') ));//break the loop in case of valid key or time is out

					break;//End of more menu case
//------------------------------FAN--------------------------------------------------

					case AIRCONDITIONING_MENU:
					do
					{
						/******************** print more Menu ******************/

					     HLCD_voidClear();
						 HLCD_voidSendString((u8 *)"1:Set temperature ");
						 HLCD_voidSetCursor(2,1);
						 HLCD_voidSendString((u8 *)"2:Control  0:RET");
						/*******************************************************/
						key_pressed = HKPD_u8GetPressedKey();//wait for the user till key is pressed or the time is out
						_delay_ms(100);//to avoid the duplication of the pressed key

						if (key_pressed == SELECT_SET_TEMPERATURE)//If key pressed is 1
						{
							show_menu = TEMPERATURE_MENU;//Set the next menu to be shown to set temperature menu
						}
						else if (key_pressed == SELECT_AIR_COND_CTRL)//If key pressed is 2
						{
							show_menu = AIRCOND_CTRL_MENU;//Set the next menu to be shown to air conditioning control menu
						}
						else if (key_pressed == SELECT_AIR_COND_RET)//If key pressed is 0
						{
							show_menu = MORE_MENU;//Set the next menu to be shown to more menu
						}
						else if(key_pressed != NOT_PRESSED)//show wrong input message if the user pressed wrong key
						{
							  HLCD_voidClear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
							  HLCD_voidSendString((u8 *)"Wrong input");

							_delay_ms(500);//Halt the system for the given time in (ms)
						}
					}
					while (( (key_pressed < '0') || (key_pressed > '2') ) );//break the loop in case of valid key or time is out
					break;//End of air conditioning menu case


					case ROOM1_MENU:
				    vMenuOption(ROOM1_MENU);//call the function that show the menu of room 1
					show_menu = MAIN_MENU;//Set the next menu to be shown to main menu
					break;//End of room1 menu case

					case ROOM2_MENU:
					vMenuOption(ROOM2_MENU);//call the function that show the menu of room 2
					show_menu = MAIN_MENU;//Set the next menu to be shown to main menu
					break;//End of room2 menu case

					case TV_MENU:
					vMenuOption(TV_MENU);//call the function that show the menu of tv
					show_menu = MAIN_MENU;//Set the next menu to be shown to more menu

					break;//End of TV menu case

					case FAN_MENU:
						vMenuOption(FAN_MENU);//call the function that show the menu of room 2
						show_menu = MAIN_MENU;//Set the next menu to be shown to main menu
			     	break;


					case AIRCOND_CTRL_MENU:
					vMenuOption(AIRCOND_CTRL_MENU);//call the function that show the menu of Air conditioning control
					show_menu = AIRCONDITIONING_MENU;//Set the next menu to be shown to air conditioning menu
					break;//End of air conditioning control menu case

					case TEMPERATURE_MENU:
				//	temperature = 0;//clear the value of temperature
					    HLCD_voidClear();
					while (temperature==0 )//start the loop that asks for the temperature from the user in case of the time is not out
					{

					key_pressed = NOT_PRESSED;//set the key pressed to the default value
			   	    HLCD_voidClear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
			   	    HLCD_voidSendString((u8 *)"Set temp.: ");
			   	    HLCD_voidDisplayChar(DEGREES_SYMBOL);
					HLCD_voidDisplayChar('C');
					HLCD_voidSetCursor(1,11);
				   _delay_ms(200);//Halt the system for the given time in (ms)

				   /*******************************************************************************/

						key_pressed = HKPD_u8GetPressedKey();//wait for the user till key is pressed or the time is out
						_delay_ms(100);//to avoid the duplication of the pressed key

							HLCD_voidDisplayChar(key_pressed);//print the value on the lcd

							temp_tens = key_pressed - '0';//save the entered value
							key_pressed = NOT_PRESSED;//set the key pressed to the default value

						/*******************************************************************************/
						key_pressed = HKPD_u8GetPressedKey();//wait for the user till key is pressed or the time is out
						_delay_ms(100);//to avoid the duplication of the pressed key

							HLCD_voidDisplayChar(key_pressed);//print the value on the lcd
							temp_ones = key_pressed-'0';//save the entered value
							key_pressed = NOT_PRESSED;//set the key pressed to the default value
							_delay_ms(500);
						temperature = temp_tens*10 + temp_ones;//set the value of the temperature from the given separated values
						MSPI_voidMasterTranceive(SET_TEMPERATURE);//Send the code of set temperature
						_delay_ms(500);//Halt the system to prevent write collision
						MSPI_voidMasterTranceive(temperature);//send the entered temperature

						//remove all previously printed characters on the LCD and move the cursor to the first column of the first row

						_delay_ms(500);
						HLCD_voidClear();
						HLCD_voidSendString((u8 *)"Temperature Sent");
						 _delay_ms(500);//Halt the system for the given time in (ms)
					}
					show_menu = AIRCONDITIONING_MENU;//Set the next menu to be shown to air conditioning menu
					break;//break from switch


				}
}

}

