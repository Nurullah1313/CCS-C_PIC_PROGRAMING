#include <628A.h>
#include "lcd.c"

#define LCD_ENABLE_PIN  PIN_B2
#define LCD_RS_PIN      PIN_B0
#define LCD_RW_PIN      PIN_B1
#define LCD_DATA4       PIN_B4
#define LCD_DATA5       PIN_B5
#define LCD_DATA6       PIN_B6
#define LCD_DATA7       PIN_B7


void main()
{
lcd_init();
printf(lcd_putc,"nurullah");
delay_ms(500);
printf(lcd_putc,"\n\t\t\tsahin");
delay_ms(500);
printf(lcd_putc,"\f");
lcd_gotoxy(5,1);
printf(lcd_putc,"HOS GELDINIZ");
delay_ms(100);
int a=lcd_getc(16,1);
printf(lcd_putc,"\f");
lcd_putc(a);



}
