#include <grafic.h>
#include <hdm64gs12.c>//grafik lcd için hdm64gs12.c kütüphanesi eklenmiþtir
#include <graphics.c>//grafik lcd de çizgi ve þekiller çizebilmek için graphics.c dostyasý eklenmiþtir

char yazi1[]="NURULLAH";//char türünden yazi1 adýnda bir boyutu belirsiz bir dizi tanýmlanmýþtýr ve içine NURULLAH stringi koyulmuþtur
char yazi2[]="SAHIN";//char türünden yazi2 adýnda bir boyutu belirsiz bir dizi tanýmlanmýþtýr ve içine SAHIN stringi koyulmuþtur
int i,x1,y1,x2,y2;//int cinsinden 5 tane deðiþken tanýmlanmýþ

void main()//ana fonksiyon
{
  
   
   glcd_init(ON);//grafik lcd yi hazýrlama ve ekraný tamzleme 
   
   while(TRUE)//sonsuz döngü
   {
      glcd_init(ON);//ekraný temizlenme
      glcd_text57(25,5,yazi1,2,ON);//25'e 5 kordinatlarýndan baþlayarak size=2 boyutunda yazi1 stringini ekrana pixelleri açarak(ON) yazdýrdýk
      glcd_text57(25,30,yazi2,2,ON);//25'e 30 kordinatlarýndan baþlayarak size=2 boyutunda yazi2 stringini ekrana pixelleri açarak(ON) yazdýrdýk
      delay_ms(2000);//2 sn bekle
      
      glcd_init(ON);//ekraný tamizle
      x1=5;
      y1=5;
      x2=100;
      y2=5;

      for(i=0;i<6;i++){//i 6ya eþit olana kadar döngüdeki iþlemleri gerçekleþtir
      glcd_line(x1,y1,x2,y2,ON);//grafik lcdye çizgi(line) çiz x1'e y1 kordinatýndan baþlayarak x2,y2 kordinatlarýna kadar pixelleri açarak (ON)
      y2=y1+=10;//y2=y1=y1+10
      x2-=10;//x2=x2-10
      delay_ms(100);//100 ms bekle
      }
      glcd_init(ON);//ekraný temizle
      x1=y1=10;

      for(i=0;i<120;i++){
      glcd_pixel(x1,y1,ON);//ekrandaverilen (x1,y1) kordinatlarýndaki pixelleri aç(ON)
      y1=x1++;//y1=x1+1;
      delay_ms(50);//50ms bekle
      }
      
      glcd_init(ON);//ekraný temizle
      y2=60;
      x1=5;

      for(i=0;i<8;i++){
         glcd_bar(x1,0,x1,y2,10,ON);//ekrana çubuklar çiz (x1,0) arasý ilk nokta (x1,y2) ikinci nokta 10 çubuðun geniþliði pixeller açýlacak(ON)
         delay_ms(500);
         x1+=15;
         y2-=5;
      }
      
      glcd_init(ON);//ekraný temizle

      for(i=0;i<=30;i=i+=5){
         glcd_circle(60,30,i, NO,ON);//belirlenen merkezde belirlenen çapta daire çizer (60,30) kordinatlarý daire merkezi 'i' yarý çap 'NO'(dairenin içi boyansýnmý yes te alabilir) 'ON'(daire çizgisi siyah NO beyaz)
         delay_ms(500);
      }
      glcd_init(ON);//ekraný temizle
      x1=5;
      y1=5;
      x2=120;
      y2=63;

     for(i=0;i<12;i++){
     glcd_rect(x1,y1,x1,y2,NO,ON);//belirlenen konularda belirlenen büyüklükte dörtgen çizer (x1,y1)dörtgenin ilk köþe konumu (x2,y2)dörtgenin ikinci köþe konumu 'NO'(içi boyansýnmý(YES) te ala bilir) 'ON'(kenar çizgiler siyah(NO) beyaz)
     y1=x1+=5;
     x2-=5;
     y2-=5;
     delay_ms(500);
     }
  
   }

}  
