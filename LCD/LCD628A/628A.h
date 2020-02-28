#include <16F628A.h>

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#fuses XT,NOPROTECT,NOPUT,NOCPD
#use delay(crystal=8000000)

