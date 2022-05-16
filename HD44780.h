/* 
 *  HD44780.h - Header file of HD44780 library
 *  Written by Ercan Ersoy.
 */

#ifndef HD44780_H
#define HD44780_H

#define COLUMNS 0
#define ROWS 0

#ifndef COLUMNS
#error COLUMNS must be defined.
#endif

#ifndef ROWS
#error ROWS must be defined.
#endif

#define _XTAL_FREQ 0

#ifndef _XTAL_FREQ
#error _XTAL_FREQ must be defined.
#endif

#define RS 0                //example: PORTDbits.RD1
#define RW 0                //example: PORTDbits.RD2
#define ENABLE 0            //example: PORTDbits.RD3
#define LCD_PORT_D4         //example: PORTDbits.RD4
#define LCD_PORT_D5         //example: PORTDbits.RD5  
#define LCD_PORT_D6         //example: PORTDbits.RD6  
#define LCD_PORT_D7         //example: PORTDbits.RD7
// Connect to the ground the LCD's D0, D1, D2, D3 pinouts.
//RW pin is not used (always 0). It maybe connected to the ground and get one extra pin on MCU.

#ifndef RS
#error RS must be defined.
#endif

#ifndef RW
#error RW must be defined.
#endif

#ifndef ENABLE
#error ENABLE must be defined.
#endif

#ifndef LCD_PORT_D4 
#error LCD_PORT_D4 must be defined!
#endif
#ifndef LCD_PORT_D5 
#error LCD_PORT_D5 must be defined!
#endif
#ifndef LCD_PORT_D6 
#error LCD_PORT_D6 must be defined!
#endif
#ifndef LCD_PORT_D7 
#error LCD_PORT_D7 must be defined!
#endif

#define ClearLCD 1
#define BackToBegin 2
#define WriteLeft 4
#define WriteRight 6
#define HideCursor 12
#define SkipCursor 14
#define BlinkCursor 16
#define ShiftRight 24
#define ShiftLeft 28
#define OnOffScreen 8
#define FirstLine 128
#define SecondLine 192
#define ThirdLine 148
#define FourthLine 212
#define GenerateCharacterAddress 64
#define DoubleLine 40
#define SingleLine 32

void lcd_wait(void);
void lcd_send_command(unsigned char command);
void lcd_send_data(unsigned char data);
void lcd_on_off_screen(void);
void lcd_clear(void);
void lcd_print(const char *s);
void lcd_goto_xy(unsigned char x, unsigned char y);
void lcd_prepare(void);

#endif

