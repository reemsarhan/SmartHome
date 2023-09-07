/*
 * KPD_prog.c

 *
 *  Created on: Aug 18, 2023
 *      Author: hp
 */


#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "KPD_int.h"
#include "util/delay.h"



u8 G_u8Grid[4][4]={
{'7','8','9','/'},
{'4','5','6','*'},
{'1','2','3','-'},
{'c','0','=','+'}
};
void HKPD_voidInit()
{

	MDIO_voidSetPortDirection(KPD_PORT, 0x0f);
	MDIO_voidSetPortValue(KPD_PORT,0xff);

}

u8 HKPD_u8GetPressedKey() {
    u8 Pressed_Key = 0xFF;

    for (u8 col = 0; col < 4; col++) {
        // Activate current column
        MDIO_voidSetPinValue(KPD_PORT, col, LOW);
        for (u8 row = 0; row < 4; row++) {
            if (MDIO_U8GetPinValue(KPD_PORT, row + 4) == 0) {
                Pressed_Key = G_u8Grid[row][col];
            }
         //   while (MDIO_U8GetPinValue(KPD_PORT, row + 4) == 0) {}
            _delay_ms(10);
        }
        MDIO_voidSetPinValue(KPD_PORT, col, HIGH);
    }
    return Pressed_Key;
}

