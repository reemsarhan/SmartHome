/*
 * main.c


 *
 *  Created on: Sep 6, 2023
 *      Author: Reem
 */

#include "../LIB/BITMATH.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LED/LED.h"
#include "../HAL/KeyPad/KPD_int.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/SPI/SPI_Init.h"
#include "../MCAL/SPI/SPI_Cfg.h"
#include "../MCAL/SPI/SPI_Prv.h"
#include "../MCAL/ADC/ADC_driver.h"
#include "../MCAL/TIMER/TIMERS_init.h"
#include "../MCAL/TIMER/TIMERS_config.h"
#include "../MCAL/TIMER/TIMERS_priv.h"
#include "APP_slave_Macros.h"
#include "STD_MESSAGES.h"

void MOTORTURNON(u8 motor_port, u8 motor_pin)
{
    MDIO_voidSetPinDirection(MOTOR_PORT, MOTOR_PIN, OUTPUT); // Set the motor pin as output
    MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN, HIGH);      // Set the motor pin to HIGH to turn it on
}

// Function to turn the motor off
void MOTORTURNOFF(u8 motor_port, u8 motor_pin)
{
	MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN, LOW); // Set the motor pin to LOW to turn it off
}



volatile u16 required_temperature=24; // the required temperature which sent from Master with initial value 24
volatile u16 temp_sensor_reading=0; // the temperature of the room
volatile u8 counter=0; // the counter which determine the periodic time of implementing ISR
volatile u8 last_air_conditioning_value=AIR_CONDTIONING_OFF; // last air conditioning value which will help in hysteresis

int main(void)
{
	ADC_vinit();//initialize the ADC of the micro controller
	MTIMERS_voidinit(0);//Initialize the timer zero of the micro controller
	MSPI_voidSlave_init();//initialize the SPI as a slave

	/* initialization of output pins of connected leds or devices */
	LED_vInit(AIR_COND_PORT,AIR_COND_PIN);
	LED_vInit(TV_PORT,TV_PIN);
	LED_vInit(ROOM1_PORT,ROOM1_PIN);
	LED_vInit(ROOM2_PORT,ROOM2_PIN);

	volatile u8 request = DEFAULT_ACK;//the value that is received from the master
	volatile u8 response = DEFAULT_ACK;//the values that is sent back to the master

	while(1)
	{
		request = SPI_SlaveReceive();//wait for the master to start the transmitting
		//ALL Messages are defined in STD_messages.h
		switch (request)
		{

			/*********************************   TURN ON COMMANDS ********************************/
			HLCD_voidClear();
			HLCD_voidSendString((u8*)request -'0');
			case ROOM1_TURN_ON:
			LED_vTurnOn(ROOM1_PORT,ROOM1_PIN);//turn on the led of room 1
			break;//break the switch case
			case ROOM2_TURN_ON:
			LED_vTurnOn(ROOM1_PORT,ROOM2_PIN);//turn on the led of room 2
			break;//break the switch case
			case AIR_COND_TURN_ON:
			MTIMERS_voidinit(0);
			LED_vTurnOn(AIR_COND_PORT,AIR_COND_PIN);//turn on the led of air conditioning
			break;//break the switch case
			case TV_TURN_ON:
			LED_vTurnOn(TV_PORT,TV_PIN);//turn on the led of the TV
			break;//break the switch case
			case MOTOR_TURN_ON:
				MOTORTURNON(MOTOR_PORT,MOTOR_PIN);
						break;
			/*********************************   TURN OFF COMMANDS ********************************/
			case ROOM1_TURN_OFF:
			LED_vTurnOff(ROOM1_PORT,ROOM1_PIN);//turn off the led of room 1
			break;//break the switch case
			case ROOM2_TURN_OFF:
			LED_vTurnOff(ROOM2_PORT,ROOM2_PIN);//turn off the led of room 2
			break;//break the switch case
			case AIR_COND_TURN_OFF:
			MTIMERS_voidStop(0);
			LED_vTurnOff(AIR_COND_PORT,AIR_COND_PIN);//turn off the led of air conditioning
			break;//break the switch case
			case TV_TURN_OFF:
			LED_vTurnOff(TV_PORT,TV_PIN);//turn off the led of the TV
			break;//break the switch case

			case MOTOR_TURN_OFF:
						MOTORTURNOFF(MOTOR_PORT,MOTOR_PIN);//turn off the led of the TV
						break;//break the switch case
			/*********************************   Set temperature   ********************************/
			case SET_TEMPERATURE:
			required_temperature = SPI_SlaveReceive();//get the temperature from the master and store the temperature in required temperature
			break;//break the switch case
		}
	}
}
//
//ISR(TIMER0_COMP_vect)
//{
//	counter++;//count the ticks of the timer zero
//	if(counter>=10)//do that code every 10 ticks
//	{
//		counter=0;//clear the counter of ticks
//		temp_sensor_reading=(0.25*ADC_u16Read());//read the temperature from the temperature sensor connected to the ADC of the micro controller
//		if (temp_sensor_reading>=(required_temperature+1))//do that code if the read temperature if greater than required temperature by one or more
//		{
//			LED_vTurnOn(AIR_COND_PORT,AIR_COND_PIN);//turn on the led of the air conditioning
//			last_air_conditioning_value=AIR_CONDTIONING_ON;//save the value of the state of the air conditioning
//		}
//		else if (temp_sensor_reading<=(required_temperature-1))//do that code if the read temperature if lesser than required temperature by one or more
//		{
//			LED_vTurnOff(AIR_COND_PORT,AIR_COND_PIN);//turn off the led of the air conditioning
//			last_air_conditioning_value=AIR_CONDTIONING_OFF;//save the value of the state of the air conditioning
//		}
//		else if (required_temperature==temp_sensor_reading)//do that code if the read temperature is equal to the required temperature
//		{
//			if (last_air_conditioning_value==AIR_CONDTIONING_ON)//in the case of the last saved status of the air conditioning was on
//			{
//				LED_vTurnOn(AIR_COND_PORT,AIR_COND_PIN);//turn on the led of the air conditioning
//			}
//			else if (last_air_conditioning_value==AIR_CONDTIONING_OFF)//in the case of the last saved status of the air conditioning was off
//			{
//				LED_vTurnOff(AIR_COND_PORT,AIR_COND_PIN);//turn off the led of the air conditioning
//			}
//		}
//	}
//}
//
//
