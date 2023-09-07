/*
 * SPI_Init.h


 *
 *  Created on: Aug 24, 2023
 *      Author: hp
 */

#ifndef MCAL_SPI_SPI_INIT_H_
#define MCAL_SPI_SPI_INIT_H_


void MSPI_voidMasterIntial();
void MSPI_voidMasterTranceive(u8 A_u8Data);

void MSPI_voidSlave_init();
u8 SPI_SlaveReceive();
#endif /* MCAL_SPI_SPI_INIT_H_ */
