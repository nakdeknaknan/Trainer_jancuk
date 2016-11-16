#include <mega32.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>

#define led_lcd PORTB.7 

unsigned char tampil[32];
int x;

int key=0;

//====array led
int led[8]={0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000};

//===lcd=====buat karakter sendiri di lcd masih error gk tau knp
void geser_lcd(){
    for(x=0;x<=12;x++){   
        lcd_gotoxy(x,0);
        lcd_putsf("saya"); 
        delay_ms(200);     
        lcd_clear();
    }      
    
    for(x=14;x>=0;x--){   
        lcd_gotoxy(x,1);
        lcd_putsf("ganteng"); 
        delay_ms(200);     
        lcd_clear();
    }
}

//===led
void lampu(){
    for(x=0;x<=7;x++){
        PORTA=led[x]; 
        delay_ms(500);
    } 
}

//===keypad
void keped(){
    lcd_gotoxy(0,0); 
    PORTC = 0b11111110;
    delay_ms(30);
    if (PINC.4 == 0) {while(PINC.4 == 0){key=0;}}
    if (PINC.5 == 0) {while(PINC.5 == 0){key=1;}}
    if (PINC.6 == 0) {while(PINC.6 == 0){key=2;}}
    if (PINC.7 == 0) {while(PINC.7 == 0){key=0;}}
    PORTC = 0b11111101;
    delay_ms(30);
    if (PINC.4 == 0) {while(PINC.4 == 0){key=3;}}
    if (PINC.5 == 0) {while(PINC.5 == 0){key=4;}}
    if (PINC.6 == 0) {while(PINC.6 == 0){key=5;}}
    if (PINC.7 == 0) {while(PINC.7 == 0){key=0;}}
    PORTC = 0b11111011;
    delay_ms(30);
    if (PINC.4 == 0) {while(PINC.4 == 0){key=6;}}
    if (PINC.5 == 0) {while(PINC.5 == 0){key=7;}}
    if (PINC.6 == 0) {while(PINC.6 == 0){key=8;}}
    if (PINC.7 == 0) {while(PINC.7 == 0){key=0;}}
    PORTC = 0b11110111;
    delay_ms(30);
    if (PINC.4 == 0) {while(PINC.4 == 0){key=9;}}
    if (PINC.5 == 0) {while(PINC.5 == 0){key=0;}}
    if (PINC.6 == 0) {while(PINC.6 == 0){key=0;}}
    if (PINC.7 == 0) {while(PINC.7 == 0){key=0;}}
    sprintf(tampil,"%d",key);
    lcd_puts(tampil);
}

void coba_pwm(){
    for(x=0;x<=255;x++){
        OCR1A = x;
        delay_ms(100);
    }
    for(x=255;x>=0;x--){
        OCR1A = x;
        delay_ms(100);
    }
}

void main(void)
{
    DDRB=PORTB=DDRA=PORTA=DDRD=0xff; 
    PORTD=0x00;
    DDRC=0x0f;
    PORTC=0xff;
    led_lcd=1;
    lcd_init(16);  
    
    TCCR1A=0b10100001;
    TCCR1B=0x04;
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x02;
    OCR1AL=0xFF;
    OCR1BH=0x00;
    OCR1BL=0x00;
    
while (1)
      {  
        coba_pwm();
      }
}
