#define ac portb.rb7
#define kapat portb.rb5
#define sil portb.rb6
#define sola portb.rb4

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
Lcd_Out(1,1,"deneme1");
Lcd_Out(2,1,"deneme2");

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
            }
}


