void setup() {
  // put your setup code here, to run once:
//ucsra
//uscrb
//ucsrc
//ubrr

/*//use macros directly 
unsigned char *pUCSR0A;
unsigned char *pUCSR0B;
unsigned char *pUCSR0C;
unsigned char *pUBRR0H;
unsigned char *pUBRR0L;

//pointers not working because of volatile issue 
pUCSR0A = (unsigned char*) 0xC0;
pUCSR0B = (unsigned char*) 0xC1;
pUCSR0C = (unsigned char*) 0xC2;
pUBRR0H = (unsigned char*) 0xC4;
pUBRR0L = (unsigned char*) 0xC5;


*/

UBRR0H = 0;
UBRR0L = 16;

UCSR0A |= 0x00;
UCSR0B |= 0x98;
UCSR0C |= 0x06;



//DDRD &= ~( 1<<PD2); //set as input - for arduino a
PCICR=0x04;
PCMSK2=0x04;

DDRB = (1 << PB5); //for setup arduino A so pin13 is output  

}

/*
 //arduino A
ISR (PCINT2_vect){

  if (((PIND & (1 << PD2))) == (1 << PD2)){
    UDR0 = 0x31;
  }
  else{
    UDR0 = 0x30;
  }
}

*/


//Arduino B - receiver 
ISR(USART_RX_vect){

  if (UDR0 == 0x31){ //if push button is pressed
    PORTB |= (1 << PB5); //LED is on
    UDR0 = 0x31;
  }
  else { //if push button is released 
    PORTB &= ~(1 << PB5); //1 is shifted, not the value -> just 0 : LED is off 
    UDR0 = 0x30;
  }
  
}

//same thing for arduino A


void loop() {
  // put your main code here, to run repeatedly:

}
