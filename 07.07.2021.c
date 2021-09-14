#define SIFIRLA PORTD.RD0


//short display = 0;

void main(){
TRISB=0;
PORTB=0;
//TRISD=0B00000011;
PORTD=0;

while(1){
//if(1)
PORTB=0x3F;
DELAY_MS(400);
//if(2)
PORTB=0x06;
DELAY_MS(400);
//if(3)
PORTB=0x5B;
DELAY_MS(400);
//if(4)
PORTB=0x4F;
DELAY_MS(400);
//if(5)
PORTB=0x66;
DELAY_MS(400);
//if(6)
PORTB=0x6D;
DELAY_MS(400);
//if(7)
PORTB=0x7C;
DELAY_MS(400);
//if(8)
PORTB=0x07;
DELAY_MS(400);
//if(9)
PORTB=0x7F;
DELAY_MS(400);
//if(10)
PORTB=0x6F;
DELAY_MS(500);


//{display++;
/*DELAY_MS(500);}
else
{PORTB=display;}   */

if(PORTD.RD0=0)
{PORTB=0x3F;}
if (PORTD.RD1=0)
{PORTB=PORTB;}


}}

