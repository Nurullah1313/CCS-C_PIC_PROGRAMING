#include <main.h>

#use fast_io(a)
#use fast_io(b)

void main()
{
set_tris_a(0x01);
set_tris_b(0x00);
setup_psp(psp_disabled);
setup_ccp1(ccp_off);
setup_ccp2(ccp_off);
setup_timer_1(t1_disabled);
setup_timer_2(t2_disabled,0,1);
setup_adc_ports(no_analogs);
setup_adc(adc_off);

int y=0;
   while(TRUE)
   {
    int led=1;
    
   for(int i=0;i<=7;i++)
   {
    output_c(led);
   led=led<<1;
   delay_ms(100);
   }
   led=0x80;
   output_c(led);
   delay_ms(100);
 for(int a=0;a<=7;a++)
      {
        output_c(led);
        led=led>>1;
        delay_ms(100);
      }
   
   }
   
   }


