/*
 * SPI_Prog.c
 *
 *  Created on: Aug 24, 2023
 *      Author: hp
 */

#include "../../LIB/BITMATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "SPI_Cfg.h"
#include "SPI_Init.h"
#include "SPI_Prv.h"

void MSPI_voidMasterIntial()
{
	MDIO_voidSetPinDirection(PORTB,PIN5,OUTPUT);//mosi
	MDIO_voidSetPinDirection(PORTB,PIN7,OUTPUT);//sck
	MDIO_voidSetPinDirection(PORTB,PIN6,OUTPUT);//miso
	MDIO_voidSetPinDirection(PORTB,PIN4,OUTPUT);

	const u8 SPCR_Setting=0b01010001;
	SPCR =SPCR_Setting;
	MDIO_voidSetPinValue(PORTB,PIN4,HIGH);
}



void MSPI_voidMasterTranceive(u8 A_u8Data)
{
//	 static  u8 flag;
	MDIO_voidSetPinValue(PORTB,PIN4,LOW);

	SPDR=A_u8Data;

	while (((SPSR&(1<<SPIF))>>SPIF)==0)	//wait till the transmitting is done
		;

}




void MSPI_voidSlave_init()
{
	/* Set MISO output, all others input */
	MDIO_voidSetPinDirection(PORTB,PIN6,OUTPUT);
	/* Enable SPI */
	SPCR = (1<<SPE);
}



u8 SPI_SlaveReceive(){
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)));
	/* Return data register */
	return SPDR;
}


