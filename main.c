#include "mcc_generated_files/mcc.h"

void main(void)
{
   
    SYSTEM_Initialize();
    EPWM1_Initialize(); //inizializzazione del moduo epwm1

    
    while (1)
    {
       PSTR1CON = 0x01; //PWM Solo Su Bit 3 PORTB (0x08 attiva il pwm sul pin RB7)
        
        EPWM1_LoadDutyValue(46); //Duty 7.5%, 90°
        PORTB = 0b00000010;
        if(IO_RA2_GetValue()==1){
            EPWM1_LoadDutyValue(22); //Duty 3.75%, 0°
            PORTB = 0b00000001;
            __delay_ms(3000);
            EPWM1_LoadDutyValue(69); //Duty 11.25%, 180°
            PORTB = 0b00000100;
            __delay_ms(5000);
        }
        if(IO_RA3_GetValue()==1){
            int duty = 22;
            int inc = 8;
            do{
            EPWM1_LoadDutyValue(duty);
            __delay_ms(3000);
            if(IO_RA4_GetValue()==1){
                inc=-8;}
            duty=duty+inc;
            }while(duty<69&&duty>22);
           if(duty<23){
            PORTB = 0b00000001;
           } 
           if(duty>68){
            PORTB = 0b00000100;
           } 
           if(duty==46){
            PORTB = 0b00000010;
           } 
            
        }
    }
}