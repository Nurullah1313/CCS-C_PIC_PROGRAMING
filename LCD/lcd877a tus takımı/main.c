#include <main.h>
#define LCD_ENABLE_PIN PIN_B2
#define LCD_RS_PIN PIN_B0
#define LCD_RW_PIN PIN_B1
#define LCD_DATA4 PIN_B3
#define LCD_DATA5 PIN_B4
#define LCD_DATA6 PIN_B5
#define LCD_DATA7 PIN_B6

#include <lcd.c>
#define  LCD_DATA_PORT  getenv("SFR:PORTB")

//keypad sat�r ve s�tunlar� pinlerle e�le�triliyor
#define sut1 pin_c0
#define sut2 pin_c1
#define sut3 pin_c2
#define sut4 pin_c3

#define sat1 pin_c4
#define sat2 pin_c5
#define sat3 pin_c6
#define sat4 pin_c7

char tus=0; //ekrana yazaca�am�z de�i�ken

char oku()//keypad'i okumak i�in yapt���m�z bir fonkksiyon
{  
   output_d(0x00);//keypad'in pinlerini s�f�rl�yoruz
   
   //sat�r tarama i�lemleri yap�yoruyz
   output_high(sat1);//1. sat�r� lojik 1 yap�yoruz
      if(input(sut1)){delay_ms(20);tus=1;}//1. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut2)){delay_ms(20);tus=2;}//2. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut3)){delay_ms(20);tus=3;}//3. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut4)){delay_ms(20);tus=0xA;}//4. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
   output_low (sat1);//1. sat�r� lojik 0 yap�yoruz

   output_high(sat2);//2. sat�r� lojik 1 yap�yoruz
      if(input(sut1)){delay_ms(20);tus=4;}//1. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut2)){delay_ms(20);tus=5;}//2. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut3)){delay_ms(20);tus=6;}//3. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut4)){delay_ms(20);tus=0XB;}//4. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
   output_low (sat2);//2. sat�r� lojik 0 yap�yoruz
   
   output_high(sat3);//3. sat�r� lojik 1 yap�yoruz
      if(input(sut1)){delay_ms(20);tus=7;}//1. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut2)){delay_ms(20);tus=8;}//2. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut3)){delay_ms(20);tus=9;}//3. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut4)){delay_ms(20);tus=0XC;}//4. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
   output_low (sat3);//3. sat�r� lojik 0 yap�yoruz
   
   output_high(sat4);//4. sat�r� lojik 1 yap�yoruz
      if(input(sut1)){delay_ms(20);tus=0XE;}//1. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut2)){delay_ms(20);tus=0;}//2. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut3)){delay_ms(20);tus=0XF;}//3. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
      if(input(sut4)){delay_ms(20);tus=0XD;}//4. s�tun'u ok�uyoruz gereken de�er'i tus de�i�kenine at�yoruz
   output_low (sat4);//4. sat�r� lojik 0 yap�yoruz
   
   return tus;//tus de�i�kenini ana fonksiyona g�nderiyoruz
}

void main()//ana fonksiyon
{
   setup_psp(psp_disabled);
   setup_timer_1(t1_disabled);
   setup_timer_2(t2_disabled,0,1);
   setup_adc_ports(no_analogs);
   setup_adc(adc_off);
   setup_ccp1(ccp_off);
   setup_ccp2(ccp_off);
   setup_comparator(nc_nc_nc_nc);
   setup_vref(false);
   
   
   set_tris_b(0x00);//b portunu ��k�� portu olarak ayarl�yoruz
   set_tris_c(0xFF);//c portunu giri� portu olarak ayarl�yoruz
   output_b(0x00);//b portunu s�f�rl�yoruz
   output_c(0x00);//c portunu s�f�rl�yoruz
   
   lcd_init();//lcd'yi a��yoruz
   printf(lcd_putc,"\fBasilan tus=");//lcd ekran�n� tamizleyip "Bas�lan tus="yaz�yoruz D�ng�ye koymad�k ��nk� program� yormas�n� istemiyoruz
   while(TRUE)//d�ng�
   {
    lcd_gotoxy(13,1);//kursor'u 13.sat�r 1. sutuna sabitleyip ardan ba�lamas�n� sa�l�yoruz
    if(oku()>9)//tus de�i�keni 9 dan b�y�kse ekrana a��a��daki �ekilde yaz
     printf(lcd_putc,"%d",oku());
    else//tus de�i�keni 9 dan b�y�k de�ilse ekrana a��a��daki �ekilde yaz
     printf(lcd_putc,"%d ",oku());  
   }

}

//dikkat edilirse else k�sm�nda "%d " yaz�lan komut �ekkildeki gibi t�rnak i�ine fazladan bir bo�luk eklenmi�tir 9 dan b�y�kse bo�luk at�lmaz ��nk�
//9 dan b�y�k olunca 2 basamakl� olucakt�r e�er o bo�lu�u koymasayd�k �rne�in ekrana 15 yazd�ktan sonra 2'ye bas�l�nca ekrana 25 yazard�
