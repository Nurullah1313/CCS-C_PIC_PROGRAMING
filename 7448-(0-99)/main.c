#include <main.h>
#define seg_1 pin_c0
#define seg_2 pin_d0
#define art pin_a0
#define azlt pin_a1
void main()
{
set_tris_a(0x03);
set_tris_b(0x00);
setup_psp(psp_disabled);
setup_ccp1(ccp_off);
setup_ccp2(ccp_off);
setup_timer_1(t1_disabled);
setup_timer_2(t2_disabled,0,1);
setup_adc_ports(no_analogs);
setup_adc(adc_off);
const int dizi[10]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
char sayi=0,birler=0,onlar=0;

while(TRUE)
{
   output_high(seg_1);
   output_low(seg_2);
   output_b(dizi[birler]);
   delay_ms(7);
   output_low(seg_1);
   output_high(seg_2);
   output_b(dizi[onlar]);
   delay_ms(7);
   
   if(input(art)==0)
   {
   sayi++;
   birler=sayi%10;
   onlar=sayi/10;
   while(input(art)==0);
   {
   output_high(seg_1);
   output_low(seg_2);
   output_b(dizi[birler]);
   delay_ms(7);
   output_low(seg_1);
   output_high(seg_2);
   output_b(dizi[onlar]);
   delay_ms(7);
   }}



      if((input(azlt)==0)& sayi!=0)
      {
      sayi--;
      birler=sayi%10;
      onlar=sayi/10;
      while(input(azlt)==0)
      {
      output_high(seg_1);
   output_low(seg_2);
   output_b(dizi[birler]);
   delay_ms(7);
   output_low(seg_1);
   output_high(seg_2);
   output_b(dizi[onlar]);
   delay_ms(7);
      }
      }
      else{
         
      }
      if(sayi==100)
      {
      sayi=0;
      
      }

}

}


