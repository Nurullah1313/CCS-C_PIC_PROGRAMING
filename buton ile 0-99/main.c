#include <main.h>
#define buton pin_a0
#define seg_1 pin_c0
#define seg_2 pin_d0

void main()
{
set_tris_b(0x00);
set_tris_c(0x00);
setup_psp(psp_disabled);
setup_ccp1(ccp_off);
setup_ccp2(ccp_off);
setup_timer_1(t1_disabled);
setup_timer_2(t2_disabled,0,1);
setup_adc_ports(no_analogs);
setup_adc(adc_off);
const int dizi[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x07,0x7f,0x6f};
output_b(0x00);
output_c(0x00);
int birler=0,onlar=0,sayi=0;
   while(TRUE)
   {
      if(input(buton)==0)
     {  
      delay_ms(10);
         sayi++;
         birler=sayi%10;
         onlar=(sayi-birler)/10;
       while(input(buton)==0);
       while(input(buton)==1)
       {
       
         output_high(seg_1);
         output_low(seg_2);
         output_b(dizi[birler]);
         delay_ms(15);
         output_low(seg_1);
         output_high(seg_2);
         output_b(dizi[onlar]);
         delay_ms(15);
         
         if(sayi==100)
            sayi=0;
       }
       
      }

   }

}
