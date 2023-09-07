/*
 * SPI_Prv.h
 *
 *  Created on: Aug 24, 2023
 *      Author: hp
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

//#define SPIF    7
//#define SPCR    *((volatile u8*)(0x2D))
//#define SPSR    *((volatile u8*)(0x2E))
//#define SPDR    *((volatile u8*)(0x2F))


#define SPI_master 1
#define SPI_slave 2

#define SPSR *((volatile u8*) 0x2E)
#define SPCR *((volatile u8*) 0x2D)
#define SPDR *((volatile u8*) 0x2F)

#define SPE 6
#define MSTR 4
#define SPIF 7


#endif /* MCAL_SPI_SPI_PRV_H_ */
