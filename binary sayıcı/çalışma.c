#include <�al��ma.h>
void main()
{
set_tris_a(0x01);
set_tris_c(0x00);
setup_timer_1(T1_DISABLED);
setup_timer_2(T2_DISABLED,0,1);
setup_psp(PSP_DISABLED);
setup_adc_ports(NO_ANALOGS);
setup_adc(adc_off);
setup_ccp1(ccp_off);
setup_ccp2(ccp_off);
setup_comparator(nc_nc_nc_nc);
setup_vref(false);

output_b(0x00);
int i=1;
while(1)
{
if(input(pin_a0))
{
   while(input(pin_a0));
   output_b(i);
   i++;
}
 }
}
   



