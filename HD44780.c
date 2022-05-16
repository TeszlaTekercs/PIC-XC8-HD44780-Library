/* 
 *  HD44780.c - Source file of HD44780 library
 *  Written by Ercan Ersoy.
 */

#include <xc.h>
#include "HD44780.h"

void lcd_wait(void)
{
    __delay_ms(10); //working with 8 MHz
}

void lcd_send_command(unsigned char command)
{
    RW = 0;
    RS = 0;
    ENABLE = 1;
    LCD_PORT_D4 = (command & 0X10)?1:0;           //mask command's MSB bits and put it to the port
    LCD_PORT_D5 = (command & 0X20)?1:0;           // conditional assignment: (expression) ? (TRUE):(FALSE))
    LCD_PORT_D6 = (command & 0X40)?1:0;           //  
    LCD_PORT_D7 = (command & 0X80)?1:0;           //
    ENABLE = 0;
    lcd_wait();
    ENABLE = 1;
    LCD_PORT_D4 = ((command & 0X01) << 4)?1:0;    //mask command's LSB bits and put it to the port
    LCD_PORT_D5 = ((command & 0X02) << 4)?1:0;    // conditional assignment: (expression) ? (TRUE):(FALSE))
    LCD_PORT_D6 = ((command & 0X04) << 4)?1:0;    //
    LCD_PORT_D7 = ((command & 0X08) << 4)?1:0;    //
    ENABLE = 0;
    lcd_wait();
}

void lcd_send_data(unsigned char data)
{
    RW = 0;
    RS = 1;
    ENABLE = 1;
    LCD_PORT_D4 = (data & 0X10)?1:0;            //mask data's MSB bits and put it to the port
    LCD_PORT_D5 = (data & 0X20)?1:0;            // conditional assignment: (expression) ? (TRUE):(FALSE))
    LCD_PORT_D6 = (data & 0X40)?1:0;            //  
    LCD_PORT_D7 = (data & 0X80)?1:0;            //
    ENABLE = 0;
    lcd_wait();
    ENABLE = 1;
    LCD_PORT_D4 = ((data & 0X01) << 4)?1:0;     //mask data's LSB bits and put it to the port
    LCD_PORT_D5 = ((data & 0X02) << 4)?1:0;     // conditional assignment: (expression) ? (TRUE):(FALSE))
    LCD_PORT_D6 = ((data & 0X04) << 4)?1:0;     //
    LCD_PORT_D7 = ((data & 0X08) << 4)?1:0;     //
    ENABLE = 0;
    lcd_wait();
}

void lcd_on_off_screen(void)
{
    lcd_send_command(OnOffScreen);
}

void lcd_clear(void)
{
    lcd_send_command(ClearLCD);
}

void lcd_print(const char *s)
{
    lcd_wait();
    while(*s)
    {
        lcd_send_data(*s++);
    }
}

void lcd_goto_xy(unsigned char x, unsigned char y)
{
#if ROWS == 2

    if (x == 0)
    {
        lcd_send_command(FirstLine + (y % COLUMNS));
    }
    else if(x == 1)
    {
        lcd_send_command(SecondLine + (y % COLUMNS));
    }

#elif ROWS == 4

    if (x == 0)
    {
        lcd_send_command(FirstLine + (y % COLUMNS));
    }
    else if(x == 1)
    {
        lcd_send_command(SecondLine + (y % COLUMNS));
    }
    else if(x == 2)
    {
        lcd_send_command(ThirdLine + (y % COLUMNS));
    }
    else if(x == 3)
    {
        lcd_send_command(FourthLine + (y % COLUMNS));
    }

#endif
}

void lcd_prepare()
{
    RS = 0;
    RW = 0;
    ENABLE = 0;
    __delay_ms(15);
    ENABLE = 1;
    lcd_send_command(0X02);
    __delay_ms(2);
    lcd_send_command(DoubleLine);
    lcd_send_command(WriteLeft);
    lcd_send_command(HideCursor);
    lcd_clear();
    lcd_send_command(FirstLine);
}
