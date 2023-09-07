/*
 * LCD_int.h

 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define LCD_ROW_1 127
#define LCD_ROW_2 191

#define LCD_LINE_1 1
#define LCD_LINE_2 2

#define Control_Port PORTB
#define Data_Port PORTA

//these are for 8 bit initialization
#define LCD_FunctionSet  0b00111100
#define LCD_DisplayOnOff 0b00001100
#define LCD_DisplayClear 0b00000001
#define LCD_EntryMode    0b00000110

#define CGRAM_Init 0b01000000
#define CGRAM_AvailableChars (u8)8



#endif /* HAL_LCD_LCD_H_ */

void HLCD_voidSendCommand(u8 A_u8cmd);
void HLCD_voidSendData(u8 A_u8data);
void HLCD_void8bitInit();
void HLCD_voidClear();
void HLCD_voidSetCursor(u8 A_u8RowNum,u8 A_u8ColNum);
void HLCD_voidSendString(u8 *A_u8PtrString);
void HLCD_voidDisplayChar(u8 A_u8Char);
void HLCD_voidDisplayNum(s32 A_s32Number);
void HLCD_voidSaveCustomChar (u8 A_u8CGRAM_Index,u8 *A_u8CustomArray);
void HLCD_voidDisplayCustomChar (u8 A_u8CGRAM_Index);


