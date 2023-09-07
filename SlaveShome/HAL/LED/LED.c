/*
 * LED.c


 *
 *  Created on: Sep 5, 2023
 *      Author: Reem
 */


#include "LED.h"
void LED_vInit(u8 portname,u8 pinnumber)
{
	//DIO_vsetPINDir(portname,pinnumber,1);//Set the given pin in the given port as an output
	MDIO_voidSetPinDirection(portname,pinnumber,1);
}
void LED_vTurnOn(u8 portname,u8 pinnumber)
{
	//DIO_write(portname,pinnumber,1);//Set the given pin in the given port to one(on)
	MDIO_voidSetPinValue(portname,pinnumber,1);
}
void LED_vTurnOff(u8 portname,u8 pinnumber)
{
//	DIO_write(portname,pinnumber,0);//Set the given pin in the given port to zero(off)
	MDIO_voidSetPinValue(portname,pinnumber,0);
}
void LED_vToggle(u8 portname,u8 pinnumber)
{
	MDIO_toggle(portname,pinnumber);//Set the given pin in the given port to zero if it is one or set it to one if it is zero

}
u8 LED_u8ReadStatus(u8 portname,u8 pinnumber)
{
	return MDIO_U8GetPinValue(portname,pinnumber);//return the current status of the given pin
}
