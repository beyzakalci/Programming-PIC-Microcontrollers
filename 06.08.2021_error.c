#define ac portb.rb7
#define kapat portb.rb5
#define sil portb.rb6
#define sola portb.rb4
//#define rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
void ksarac(){  //araçlara kýrmýzý ve sarý yayalara kýrmýzý
 PORTC=0B00011011;
 PORTA=0B000101;

 }

 void yarac(){  //araçlara yeþil yayalara kýrmýzý
 PORTC=0B00100100;
 PORTA=0B000101;

 }

 void sarac(){   //araçlara sarý yayalara kýrmýzý
 PORTC=0B00010010;
 PORTA=0B000101;

 }

 void kksuresi(){  //kýrmýzý koruma süresi (herkes kýrmýzý)
 PORTC=0B00001001;
 PORTA=0B000101;

 }

 void yyaya(){  //araçlar kýrmýzý yayalar yeþil
 PORTC=0B00001001;
 PORTA=0B001010;


 }

 void kirmizi(){ //araçlara ve yayalara kýrmýzý
 PORTC=0B00001001;
 PORTA=0B000101;

 }

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
Lcd_Init();
Lcd_Cmd(_LCD_CURSOR_OFF);
Lcd_Cmd(_LCD_CLEAR);
Lcd_Out(1,1,"Istanbul 300 km");
Lcd_Out(2,1,"Hava bulutlu");

while(1){
if(ac){
Lcd_Cmd(_LCD_TURN_ON);
while(ac); }
if(kapat){
Lcd_Cmd(_LCD_TURN_OFF);
while(kapat);}
if(sil){
Lcd_Cmd(_LCD_CLEAR);
while(sil); }
if(sola){
Lcd_Cmd(_LCD_SHIFT_LEFT);
while(sola);}

TRISA=0B00000;
 PORTA=0;
 TRISC=0B00000000;
 PORTC=0;

 //while(1){

         ksarac();
          delay_ms(2000);
         yarac();
          delay_ms(10000);
         sarac();
          delay_ms(2000);
         kksuresi();
         delay_ms(500);
         yyaya();
          delay_ms(7000);
         kirmizi();
          delay_ms(2000);
}
}