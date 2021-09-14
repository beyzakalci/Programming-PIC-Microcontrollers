void ksarac(){  //araçlara kýrmýzý ve sarý yayalara kýrmýzý
 PORTA=0B00101;
 PORTB=0B00011011;

 }

 void yarac(){  //araçlara yeþil yayalara kýrmýzý
 PORTA=0B00101;
 PORTB=0B00100100;

 }

 void sarac(){   //araçlara sarý yayalara kýrmýzý
 PORTA=0B00101;
 PORTB=0B00010010;

 }

 void kksuresi(){  //kýrmýzý koruma süresi (herkes kýrmýzý)
 PORTA=0B00101;
 PORTB=0B00001001;

 }

 void yyaya(){  //araçlar kýrmýzý yayalar yeþil
 PORTA=0B01010;
 PORTB=0B00001001;


 }

 void kirmizi(){ //araçlara ve yayalara kýrmýzý
 PORTA=0B00101;
 PORTB=0B00001001;

 }
 void main(){
 
 unsigned a; //eklenen kod bloðu
 a=PORTA.RA4;   
 PORTA.RA4 = a;  
 TRISA=0B00000;
 PORTA=0;
 TRISB=0B00000000;
 PORTB=0;
          while(1){
if(a==1){
           yyaya();
          delay_ms(7000);
       }
      else {
         while(1){
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

