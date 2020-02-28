#include <grafic.h>
#include <hdm64gs12.c>//grafik lcd i�in hdm64gs12.c k�t�phanesi eklenmi�tir
#include <graphics.c>//grafik lcd de �izgi ve �ekiller �izebilmek i�in graphics.c dostyas� eklenmi�tir

char yazi1[]="NURULLAH";//char t�r�nden yazi1 ad�nda bir boyutu belirsiz bir dizi tan�mlanm��t�r ve i�ine NURULLAH stringi koyulmu�tur
char yazi2[]="SAHIN";//char t�r�nden yazi2 ad�nda bir boyutu belirsiz bir dizi tan�mlanm��t�r ve i�ine SAHIN stringi koyulmu�tur
int i,x1,y1,x2,y2;//int cinsinden 5 tane de�i�ken tan�mlanm��

void main()//ana fonksiyon
{
  
   
   glcd_init(ON);//grafik lcd yi haz�rlama ve ekran� tamzleme 
   
   while(TRUE)//sonsuz d�ng�
   {
      glcd_init(ON);//ekran� temizlenme
      glcd_text57(25,5,yazi1,2,ON);//25'e 5 kordinatlar�ndan ba�layarak size=2 boyutunda yazi1 stringini ekrana pixelleri a�arak(ON) yazd�rd�k
      glcd_text57(25,30,yazi2,2,ON);//25'e 30 kordinatlar�ndan ba�layarak size=2 boyutunda yazi2 stringini ekrana pixelleri a�arak(ON) yazd�rd�k
      delay_ms(2000);//2 sn bekle
      
      glcd_init(ON);//ekran� tamizle
      x1=5;
      y1=5;
      x2=100;
      y2=5;

      for(i=0;i<6;i++){//i 6ya e�it olana kadar d�ng�deki i�lemleri ger�ekle�tir
      glcd_line(x1,y1,x2,y2,ON);//grafik lcdye �izgi(line) �iz x1'e y1 kordinat�ndan ba�layarak x2,y2 kordinatlar�na kadar pixelleri a�arak (ON)
      y2=y1+=10;//y2=y1=y1+10
      x2-=10;//x2=x2-10
      delay_ms(100);//100 ms bekle
      }
      glcd_init(ON);//ekran� temizle
      x1=y1=10;

      for(i=0;i<120;i++){
      glcd_pixel(x1,y1,ON);//ekrandaverilen (x1,y1) kordinatlar�ndaki pixelleri a�(ON)
      y1=x1++;//y1=x1+1;
      delay_ms(50);//50ms bekle
      }
      
      glcd_init(ON);//ekran� temizle
      y2=60;
      x1=5;

      for(i=0;i<8;i++){
         glcd_bar(x1,0,x1,y2,10,ON);//ekrana �ubuklar �iz (x1,0) aras� ilk nokta (x1,y2) ikinci nokta 10 �ubu�un geni�li�i pixeller a��lacak(ON)
         delay_ms(500);
         x1+=15;
         y2-=5;
      }
      
      glcd_init(ON);//ekran� temizle

      for(i=0;i<=30;i=i+=5){
         glcd_circle(60,30,i, NO,ON);//belirlenen merkezde belirlenen �apta daire �izer (60,30) kordinatlar� daire merkezi 'i' yar� �ap 'NO'(dairenin i�i boyans�nm� yes te alabilir) 'ON'(daire �izgisi siyah NO beyaz)
         delay_ms(500);
      }
      glcd_init(ON);//ekran� temizle
      x1=5;
      y1=5;
      x2=120;
      y2=63;

     for(i=0;i<12;i++){
     glcd_rect(x1,y1,x1,y2,NO,ON);//belirlenen konularda belirlenen b�y�kl�kte d�rtgen �izer (x1,y1)d�rtgenin ilk k��e konumu (x2,y2)d�rtgenin ikinci k��e konumu 'NO'(i�i boyans�nm�(YES) te ala bilir) 'ON'(kenar �izgiler siyah(NO) beyaz)
     y1=x1+=5;
     x2-=5;
     y2-=5;
     delay_ms(500);
     }
  
   }

}  
