#include <mega32.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>

#define led_lcd PORTB.7

//aktifin pin interruptnya trus isi code di dalamnya, jangan lupa pull-up nya

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_putsf("Interrupt NDES");  
                   
}

void main(void)
{
    DDRB=PORTB=DDRA=PORTA=0xff; 
    led_lcd=1;
    lcd_init(16);
// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Falling Edge
// INT1: Off
// INT2: Off
    GICR|=0x40;
    MCUCR=0x02;
    MCUCSR=0x00;
    GIFR=0x40;

    

#asm("sei")

while (1)
      {  
      lcd_clear();
      lcd_gotoxy(1,0);
      lcd_putsf("Coba Interrupt");
      }
}
