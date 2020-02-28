#include <main.h>


int sutun(char a)
{
   switch(a)
   {
   case 0:return(0x10);break;
   case 1:return(0x08);break;
   case 2:return(0x04);break;
   case 3:return(0x02);break;
   case 4:return(0x01);break;
   }
}
void matris_karakter(char k[],char tekrar)
{
   for(int i=0;i<=tekrar;i++)
   {
      for(int j=0;j<=5;j++)
      {
         output_b(sutun(j));
         output_d(k[j]);
      delay_ms(5);
      }
   
   }

}


void main()
{
    int A[]={0x03,0x75,0x76,0x75,0x03};
    int B[]={0x00,0x36,0x36,0x36,0x49};
    int C[]={0x41,0x3e,0x3e,0x3e,0x5d};
    int D[]={0x00,0x3e,0x3e,0x3e,0x41};
    int E[]={0x00,0xb6,0xb6,0xb6,0xbe};
    int arti[]={0x77,0x77,0x41,0x77,0x77};
    int carpi[]={0x5d,0x6b,0x77,0x6b,0x5d};
    int cift_ok[]={0x6b,0x5d,0x00,0x5d,0x6b};
   setup_psp(psp_disabled);
   setup_ccp1(ccp_off);
   setup_ccp2(ccp_off);
   setup_timer_1(t1_disabled);
   setup_timer_2(t2_disabled,0,1);
   setup_adc_ports(no_analogs);
   setup_adc(adc_off);
   set_tris_b(0x00);
   set_tris_d(0x00);
while(TRUE)
   {
        matris_karakter(A,25);
        delay_ms(100);
        matris_karakter(B,25);
        delay_ms(100);
        matris_karakter(C,25);
        delay_ms(100);
        matris_karakter(D,25);
        delay_ms(100);
        matris_karakter(E,25);
        delay_ms(100);
        matris_karakter(arti,25);
        delay_ms(100);
        matris_karakter(carpi,25);
        delay_ms(100);        
        matris_karakter(cift_ok,25);
        delay_ms(100);      
        
   
   }
}
