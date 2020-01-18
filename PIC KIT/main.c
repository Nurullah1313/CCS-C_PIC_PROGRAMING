#include <16F877A.h>
#device ADC=10


#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=8000000)

#use rs232(baud=9600,parity=N,rcv=PIN_C7,bits=8,stop=1)
#use i2c(Master,sda=PIN_C3,scl=PIN_C4,slow=100000)
#include <input.c>
#include <24256.c>


#include <lcd2x16.c>
#DEFINE use_lcd_portb True
#define LCD_ENABLE_PIN PIN_B2
#define LCD_RS_PIN PIN_B0
#DEFINE LCD_DATA4 PIN_B3
#DEFINE LCD_DATA5 PIN_B4
#DEFINE LCD_DATA6 PIN_B5
#DEFINE LCD_DATA7 PIN_B6

#include <DS18B20_2.c>

#define hccloc pin_d0
#define hcdata pin_d2
#define hcload pin_d1

#define yukari PIN_A3
#define enter PIN_A4
#define assagi PIN_A5

#define sat1 pin_c0
#define sat2 pin_c1
#define sat3 pin_c2
#define sat4 pin_c3

#define sut1 pin_c7
#define sut2 pin_c6
#define sut3 pin_c5
#define sut4 pin_c4

#include <ds1307_2.c>

int i;

 BYTE sec;
  BYTE min;
  BYTE hrs;
  BYTE day;
  BYTE month;
  BYTE yr;
  BYTE dow;
void zaman_ayar()
{
     while(True){
        lcd_sil();
         printf(lcd_yaz,"gun: %d",day);
         delay_ms(50);
      if(input(assagi)==0)
      {
         while(input(assagi)==0);
         day++;
         lcd_sil();
         printf(lcd_yaz,"gun: %d",day);
         delay_ms(50);
         if(day>31)
            day=0;
      }
      if(input(yukari)==0)
      {
         while(input(yukari)==0);
        day--;
        lcd_sil();
        printf(lcd_yaz,"gun: %d",day);
        delay_ms(50);
        if(day<=0)
         day=31;
      }
      if(input(enter)==0)
      {
      while(input(enter)==0);
         break;
      }
      }
            
     while(True){
         lcd_sil();
         printf(lcd_yaz,"ay: %d",month);
         delay_ms(50);
      if(input(assagi)==0)
      {
         while(input(assagi)==0);
         month++;
         lcd_sil();
         printf(lcd_yaz,"ay: %d",month);
         delay_ms(50);
         if(month>12)
            month=0;
      }
      if(input(yukari)==0)
      {
         while(input(yukari)==0);
        month--;
        lcd_sil();
        printf(lcd_yaz,"ay: %d",month);
        delay_ms(50);
        if(month<0)
         month=12;
      }
      if(input(enter)==0)
      {
      while(input(enter)==0);
         break;
      }
      }
      while(True){
         lcd_sil();
         printf(lcd_yaz,"yil: %d",yr);
         delay_ms(50);
      if(input(assagi)==0)
      {  
         while(input(assagi)==0);
         yr++;
         lcd_sil();
         printf(lcd_yaz,"yil: %d",yr);
         delay_ms(50);
         if(yr>50)
            yr=0;//kolaylýk için sýnýr 50
      }
      if(input(yukari)==0)
      {
         while(input(yukari)==0);
        yr--;
        lcd_sil();
        printf(lcd_yaz,"yil: %d",yr);
        delay_ms(50);
        if(yr<0)
         yr=50;
      }
      if(input(enter)==0)
      {
      while(input(enter)==0);
         break;
      }
      }
      while(True){
         lcd_sil();
         printf(lcd_yaz,"saat: %d",hrs);
         delay_ms(50);
      if(input(assagi)==0)
      {
         while(input(assagi)==0);
         hrs++;
         lcd_sil();
         printf(lcd_yaz,"saat: %d",hrs);
         delay_ms(50);
         if(hrs>24)
            hrs=0;
      }
      if(input(yukari)==0)
      {
         while(input(yukari)==0);
        hrs--;
        lcd_sil();
        printf(lcd_yaz,"saat: %d",hrs);
        delay_ms(50);
        if(hrs<0)
         hrs=24;
      }
      if(input(enter)==0)
      {
      while(input(enter)==0);
         break;
      }
      }
      
      
      while(True){
         lcd_sil();
         printf(lcd_yaz,"dakika: %d",sec);
         delay_ms(50);
      if(input(assagi)==0)
      {
         while(input(assagi)==0);
         sec++;
         lcd_sil();
         printf(lcd_yaz,"dakika: %d",sec);
         delay_ms(50);
         if(sec>60)
            min=0;
      }
      if(input(yukari)==0)
      {
         while(input(yukari)==0);
        sec--;
        lcd_sil();
        printf(lcd_yaz,"dakika: %d",sec);
        delay_ms(50);
        if(sec<0)
         min=60;
      }
      if(input(enter)==0)
      {
      while(input(enter)==0);
         break;
      }
  ds1307_init();
  ds1307_set_date_time(day,month,yr,1,hrs,sec,min);

}
}

void ds1307()
{
   ds1307_init();
   while(TRUE)
   {
    delay_ms(1000);
    lcd_sil();
    ds1307_get_date(day,month,yr,dow);
    ds1307_get_time(hrs,min,sec);
    if(day>31)
      day=0;
    if(day>12)
      month=0;
    if(yr>50)
      yr=0;//kolaylýk için sýnýr 50 yapýlmýþtýr
    if(hrs>24)
      hrs=0;
    if(min>60)
      min=0;
    printf(lcd_yaz,"TARIH:%02d/%02d/%02d",day,month,yr);
    adres(1,2);
    printf(lcd_yaz,"SAAT:%02d:%02d:%02d", hrs,min,sec);
    if(input(assagi)==0)
    {
      while(input(assagi)==0);
      zaman_ayar();
      }
    if(input(enter)==0)
    {
    while(input(enter)==0);
    break;
     }
   }
}

void adc()
{  
setup_adc(adc_clock_div_32);  //adc frekansý 32
setup_adc_ports(AN0);
float value=0,voltaj=0;
while(TRUE){
      set_adc_channel(0);//okunacak adc portu AN0 
      lcd_sil();
      printf(lcd_yaz,"  AN0 KANALI:");//ekraný temizle ve ekrana girilen yazýyý yaz
      delay_ms(1000);//1 sn bekle
      value=read_adc();//adc portundan deðeri oku ve "okunan" deðiþkenine aktar
      delay_us(20);//20 mikro sn bekle
      voltaj=value*0.0048875855327468;//okunan deðiþkenin deðerini (5/1023) ile çarp  Bunun yapýlmasýnýn amacý ham deðer baþýna düþen voltajý bulmak
      lcd_sil();
      printf(lcd_yaz,"DIJITAL=>%lf",value);//ekraný temizle ve ekrana girilen yazýyý yaz yanýna okunan deðiþkenini yaz
      adres(1,2);
      printf(lcd_yaz,"VOLTAJ=>%fV",voltaj);//ekraný temizle ve ekrana girilen yazýyý yaz yanýna voltaj deðiþkenini yaz
      delay_ms(2500);//2500 ms bekle   
      
      set_adc_channel(1);//okunacak adc portu AN0 
      lcd_sil();
      printf(lcd_yaz,"  AN1 KANALI:");//ekraný temizle ve ekrana girilen yazýyý yaz
      delay_ms(1000);//1 sn bekle
      value=read_adc();//adc portundan deðeri oku ve "okunan" deðiþkenine aktar
      delay_us(20);//20 mikro sn bekle
      voltaj=value*0.0048875855327468;//okunan deðiþkenin deðerini (5/1023) ile çarp  Bunun yapýlmasýnýn amacý ham deðer baþýna düþen voltajý bulmak
      lcd_sil();
      printf(lcd_yaz,"DIJITAL=>%lf",value);//ekraný temizle ve ekrana girilen yazýyý yaz yanýna okunan deðiþkenini yaz
      adres(1,2);
      printf(lcd_yaz,"VOLTAJ=>%fV",voltaj);//ekraný temizle ve ekrana girilen yazýyý yaz yanýna voltaj deðiþkenini yaz
      delay_ms(2500);//2500 ms bekle   
      
      set_adc_channel(2);//okunacak adc portu AN0 
      lcd_sil();
      printf(lcd_yaz,"  AN2 KANALI:");//ekraný temizle ve ekrana girilen yazýyý yaz
      delay_ms(1000);//1 sn bekle
      value=read_adc();//adc portundan deðeri oku ve "okunan" deðiþkenine aktar
      delay_us(20);//20 mikro sn bekle
      voltaj=value*0.0048875855327468;//okunan deðiþkenin deðerini (5/1023) ile çarp  Bunun yapýlmasýnýn amacý ham deðer baþýna düþen voltajý bulmak
      lcd_sil();
      printf(lcd_yaz,"DIJITAL=>%lf",value);//ekraný temizle ve ekrana girilen yazýyý yaz yanýna okunan deðiþkenini yaz
      adres(1,2);
      printf(lcd_yaz,"VOLTAJ=>%fV",voltaj);//ekraný temizle ve ekrana girilen yazýyý yaz yanýna voltaj deðiþkenini yaz
      delay_ms(2500);//2500 ms bekle   
      
   if(input(enter)==0){
   while(input(enter)==0);
      break;
   }
  }
}

const int digit[13]={0x5F,0x06,0x3B,0x2F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x58,0x63,0x00};
int birler,onlar;
float sicaklik;

void hc595_yolla(unsigned char veri)
{
char i=0;
output_low(hcload);
for(i=0;i<8;i++){
output_low(hccloc);
if((veri<<i)&0x80){
output_high(hcdata);
}
else{
output_low(hcdata);
}
output_high(hccloc);
}
output_high(hcload);
}

byte veri;
byte addres;
char islem;
int data;
int ack;
long int fahr,celc;
void eprom_oku()
{
   printf("\n\n\r********************************************************************");
   printf("\n\r24LC02 HARÝCÝ EEPROM TC74(sicaklik entegresi) OKUMA VE VERÝ OKUMA YAZMA");
   printf("\n\n\r**********************************************************************");              
   printf("\n\rBir islem seciniz==>>");
   while(TRUE)
   {
      do{
      printf("\n\r24lc256 Okuma(O) \n\r24lc256 Yazma(Y)\n\r TC74 okuma(S)");
      lcd_sil();
      lcd_yaz("seri haberlesme");
      adres(1,2);
      lcd_yaz("etkin");
      
      islem=getc();                        
      islem=toupper(islem);
      printf("\n\rsectiginiz islem=>");
      putc(islem);                                
      }While((islem!='O') && (islem!='Y') && (islem!='S')  && (islem!='Q'));
      
      if(islem == 'S'){
      printf("\n\rOlcum Yapiliyor\r\n");
        i2c_start();
        ack = i2c_write(0x9A);
        ack = i2c_write(0x00);

        //send start again 
        i2c_start();
        ack = i2c_write(0x9b);
        data = i2c_read(0);
        i2c_stop();

        // Convert the A/D value to fahrenheit
        celc = ((long)data);
        fahr = celc*9/5+32;
       
        printf ("\n\rTemperature  Celciosu   : %ld\r\n",celc);  
        printf ("Temperature  Fahrenheit : %ld\r\n",fahr);  
        onlar  = (celc/10)%10;
        birler = celc%10;
        hc595_yolla(digit[10]);
        hc595_yolla(digit[11]);
        hc595_yolla(digit[birler]);
        hc595_yolla(digit[onlar]);
        delay_ms(50);        
        
        delay_ms(200);
      }                                                                                
      if(islem == 'O'){
      printf("\n\rOkumak istediginiz addresi girin :");
      addres = gethex();
      printf("\n\r Deger=>%X",read_ext_eeprom(addres));
      printf("\n\rislem basariyla gerceklestirildi");
      }
      
      if(islem == 'Y'){
      printf("\n\r Yazmak istediginiz adresi girin:");
      addres = gethex();
      printf("\n\r Yazmak istediginiz veriyi girin:");
      veri = gethex();
      write_ext_eeprom(addres, veri);
      printf("\n\rBasariyla kaydedildi"); 
      }
      if(islem == 'Q'){ delay_ms(70);break; } 
   }
}

void keypad_oku()
{
output_c(0x00);
   output_high(sat1);
   if(input(sut1)){i=1;while(input(sut1));}
   else if(input(sut2)){i=2;while(input(sut2));}
   else if(input(sut3)){i=3;while(input(sut3));}
   else if(input(sut4)){i=10;while(input(sut4));}
   output_c(0x00);
   delay_ms(100);
   output_low(sat1);
   output_high(sat2);
   if(input(sut1)){i=4;while(input(sut1));}
   else if(input(sut2)){i=5;while(input(sut2));}
   else if(input(sut3)){i=6;while(input(sut3));}
   else if(input(sut4)){i=11;while(input(sut4));}
   output_c(0x00);
   delay_ms(100);
   output_low(sat2);
   output_high(sat3);
   if(input(sut1)){i=7;while(input(sut1));}
   else if(input(sut2)){i=8;while(input(sut2));}
   else if(input(sut3)){i=9;while(input(sut3));}
   else if(input(sut4)){i=12;while(input(sut4));}
   output_c(0x00);
   delay_ms(100);
   output_low(sat3);
   output_high(sat4);
   if(input(sut1)){i=14;while(input(sut1));}
   else if(input(sut2)){i=0;while(input(sut2));}
   else if(input(sut3)){i=15;while(input(sut3));}
   else if(input(sut4)){i=13;while(input(sut4));}
   output_c(0x00);
   delay_ms(100);
   output_low(sat4);
   
}
void keypad()
{
i=0;
   set_tris_c(0x0F);
   output_c(0x00);
   lcd_sil();
   printf(lcd_yaz"LCD ILE KEYPAD");
   DELAY_MS(2000);
while(TRUE){
   keypad_oku();
   lcd_sil();
   adres(1,1);
   lcd_sil();
   printf(lcd_yaz"Keypad => %d",i);
   output_c(0x00);
   delay_ms(250);

   if(input(enter)==0){
     WHILE(INPUT(ENTER)==0);
     break;
     }
}
output_c(0x00);
}


void main()
{

 
   setup_psp(psp_disabled);//psp modül kapalý
   setup_ccp1(ccp_off);//ccp modül 1 kapalý
   setup_ccp2(ccp_off);//ccp modül 2 kapalý
   setup_timer_1(t1_disabled);//timer 1 kapalý
   setup_timer_2(t2_disabled,0,1);//timer 2 kapalý

   int menu_s=1;  
   hc595_yolla(digit[12]);
   hc595_yolla(digit[12]);
   hc595_yolla(digit[12]);
   hc595_yolla(digit[12]);   
   set_tris_b(0x00);
   output_b(0x00);
   output_c(0x00);
   lcd_ayarla();
   lcd_sil();
    while(true)
    {
    if(input(yukari)==0)
      menu_s++;
    if(input(assagi)==0)
      menu_s--;  
      switch(menu_s)
   {
      case 1:
      {printf(lcd_yaz,">TRAFIK UYGULAMA"); adres(1,2); lcd_yaz("ADC UYGULAMA");if(input(enter)==0){while(input(enter)==0);
      output_e(0x01);
      delay_ms(3000);
      output_e(0x02);
      delay_ms(1500);
      output_e(0x04);
      delay_ms(1000);
      output_e(0x00);
    
      } break;}
      case 2:
      {printf(lcd_yaz,"TRAFIK UYGULAMA"); adres(1,2); lcd_yaz(">ADC UYGULAMA"); if(input(enter)==0){while(input(enter)==0);adc();} break;}
      case 3:
      {printf(lcd_yaz,">7SEG UYGULAMA"); adres(1,2); lcd_yaz("18B20 UYGULAMA"); if(input(enter)==0){while(input(enter)==0);

   output_c(0x00);
   i=0;
   char disp[] ={0x5F,0x06,0x3B,0x2F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x58,0x38,0x00};
   for (i=0;i<10;i++)
   {
    output_c(disp[i]);
    output_toggle(pin_e0);
    delay_ms(500);
   }
   output_c(0x00);
      } break;}
      case 4:
      {
      printf(lcd_yaz,"7SEG UYGULAMA"); adres(1,2); lcd_yaz(">18B20 UYGULAMA"); if(input(enter)==0){
      while(input(enter)==0);
      
      int isi=0,virg;
      
while(TRUE){
      sicaklik =ds1820_read();
      delay_ms(50);
      isi=sicaklik;
      virg = (sicaklik-isi)*10;
      onlar  = (isi/10);
      birler = isi%10;
      hc595_yolla(digit[onlar]);
      hc595_yolla(digit[birler]);
      hc595_yolla(digit[virg]);
      hc595_yolla(digit[11]);
      delay_ms(100);
      
      if(input(enter)==0)
      {
         while(input(enter)==0);
         break;
      }
   }
   hc595_yolla(digit[12]);
   hc595_yolla(digit[12]);
   hc595_yolla(digit[12]);
   hc595_yolla(digit[12]);
   
   }
   break;
}
      case 5:
      {printf(lcd_yaz,">DS1307 UYGULAMA"); adres(1,2); lcd_yaz("KEYPAD UYGULAMA"); if(input(enter)==0){while(input(enter)==0);ds1307();} break;}
      case 6:
      {printf(lcd_yaz,"DS1307 UYGULAMA"); adres(1,2); lcd_yaz(">KEYPAD UYGULAMA"); if(input(enter)==0){while(input(enter)==0);keypad();} break;}
      case 7:
      {printf(lcd_yaz,">EEPROM VE RS232"); adres(1,2); lcd_yaz("    UYGULAMA"); if(input(enter)==0){while(input(enter)==0);eprom_oku();} break;}
      case 8:
      {printf(lcd_yaz,">ROLE UYGULAMA"); if(input(enter)==0){while(input(enter)==0);

   output_c(0x01);
   delay_ms(1500);
   output_c(0x02);
   delay_ms(1500);
   output_c(0x00);
      } break;}
   }
      if(menu_s>8)
      menu_s=1;
   else if(menu_s<1)
      menu_s=8;
      
      delay_ms(200);
      lcd_sil();
      delay_ms(50);  
    }
}
