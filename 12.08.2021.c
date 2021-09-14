#define ac portb.rb7
#define kapat portb.rb5
#define sil portb.rb6
#define sola portb.rb4

unsigned int sayac;

void kurulum(){
 ADCON1 |=0X0F;
 CMCON |=0X07;
 TRISC=0;
 PORTB=0;
 
// T0CON= 0XC0;
 INTCON= 0XC0;
 INTCON.TMR0IE=1;
 INTCON.TMR0IF=0;
}
/*void ksarac(){  //araçlara kýrmýzý ve sarý yayalara kýrmýzý
 PORTC=0B00010011; }

 void yarac(){  //araçlara yeþil yayalara kýrmýzý
 PORTC=0B00010100;}

 void sarac(){   //araçlara sarý yayalara kýrmýzý
 PORTC=0B00010010;}

 void kksuresi(){  //kýrmýzý koruma süresi (herkes kýrmýzý)
 PORTC=0B00010001;}

 void yyaya(){  //araçlar kýrmýzý yayalar yeþil
 PORTC=0B00100001;}

 void kirmizi(){ //araçlara ve yayalara kýrmýzý
 PORTC=0B00010001;}     */

 void kesme()
{
sayac++;

//TMR0L=0X06;
if (sayac<=20000)
{(PORTC=0B00100001);}
if (sayac>20000 && sayac<=30000)
{(PORTC=0B00010011);}
if (sayac>30000 && sayac<=50000)
{(PORTC=0B00010100);}
if (sayac>50000 && sayac<=60000)
{(PORTC=0B00010010);}
if (sayac>60000)
(sayac=0);}

sbit LCD_RS at RD2_bit;
sbit LCD_EN at RD3_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISD2_bit;
sbit LCD_EN_Direction at TRISD3_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;


void main(){
kurulum();

/*TRISA=0B00000;
 PORTA=0;

 TRISD=0B00000000;
 PORTD=0;            */
 TRISC=0B00000000;
 PORTC=0;

Lcd_Init();
Lcd_Cmd(_LCD_CURSOR_OFF);
Lcd_Cmd(_LCD_CLEAR);
Lcd_Out(1,1,"Istanbul 300 km");
Lcd_Out(2,1,"Hava bulutlu");

while(1){
kesme();
if(ac){
Lcd_Cmd(_LCD_TURN_ON);
Lcd_Cmd(_LCD_CURSOR_OFF);
Lcd_Cmd(_LCD_CLEAR);
Lcd_Out(1,1,"Istanbul 300 km");
Lcd_Out(2,1,"Hava bulutlu");
}
if(kapat){
Lcd_Cmd(_LCD_TURN_OFF);
}
if(sil){
Lcd_Cmd(_LCD_CLEAR);
}
if(sola){
Lcd_Cmd(_LCD_SHIFT_LEFT);
delay_ms(500);
}
}
}