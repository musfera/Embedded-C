
/*
// 1
 // blink program
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

*/



 
//2
void MyDelay(unsigned long mSecondsApx);

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  unsigned char *portDDRB;
  portDDRB = (unsigned char*) 0x24;
  *portDDRB |= 0x20;
  
}

// the loop function runs over and over again forever
void loop() {

  unsigned char *portB;
  portB= (unsigned char*) 0x25;
  *portB = (unsigned char*) 0x25;
  *portB |= 0x20;
  MyDelay(1000);
  *portB &= 0xDF;
  MyDelay (1000);

 
}

void MyDelay(unsigned long mSecondsApx)
{
  volatile unsigned long i;
  unsigned long endTime = 1000 * mSecondsApx;

  for (i = 0; i < endTime; i++);
}




/*
//3. 

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //blink once 
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for a second

  //blink twice

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000); 

  //blink three times
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);

  return;
}

*/




/*
//4 -> modify ANSI C blink program 

void MyDelay(unsigned long mSecondsApx);

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  unsigned char *portDDRB;
  portDDRB = (unsigned char*) 0x24;
  *portDDRB |= 0x20;
  
}

// the loop function runs over and over again forever
void loop() {

  unsigned char *portB;
  portB= (unsigned char*) 0x25;
  *portB = (unsigned char*) 0x25;
  *portB |= 0x20;
  MyDelay(1000);
  *portB &= 0xDF;
  MyDelay (2000);


  *portB |= 0x20;
  MyDelay(1000);
  *portB &= 0xDF;
  MyDelay (1000);
  *portB |= 0x20;
  MyDelay(1000);
  *portB &= 0xDF;
  MyDelay (2000);


*portB |= 0x20;
  MyDelay(1000);
  *portB &= 0xDF;
  MyDelay (1000);
  *portB |= 0x20;
  MyDelay(1000);
  *portB &= 0xDF;
  MyDelay (1000);
  *portB |= 0x20;
  MyDelay(1000);
  *portB &= 0xDF;
  MyDelay (2000);
 
}

void MyDelay(unsigned long mSecondsApx)
{
  volatile unsigned long i;
  unsigned long endTime = 1000 * mSecondsApx;

  for (i = 0; i < endTime; i++);
}


*/



  

/*
//debugging 


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("LED ON");
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  Serial.println("LED OFF");
  delay(1000);                       // wait for a second
}

  //shows LED ON and then LED OFF
 
*/





/*
//compile time

void MyDelay (unsigned long mSecondsApx); 
 
void setup () { 
 
 unsigned char  *portDDRB; 
 
 portDDRB = (unsigned char *) 0x24; 
 
 *portDDRB |= 0x20;
 } 
 
void  loop () {    
  unsigned char  *portB;    
  portB = (unsigned char *) 0x25; 

 
 *portB |= 0x20;  
 MyDelay(1000); //semi colon needed and () instead of {} 
 *portB &= 0xDF; //semi colon needed , dereference
 MyDelay (1000);  //() and semi colon

}

void MyDelay (unsigned long  mSecondsApx) 
{  
  volatile unsigned long  i;  
  unsigned long endTime = 1000 * mSecondsApx; 
 
 for (i = 0; i < endTime; i++); 

}

*/




/*

//Program A

void NewDelay (unsigned long mSecondsApx); 
 
void  setup() {  
  unsigned char *portDDRB; 
  portDDRB = (unsigned char *) 0x24; 
 
 *portDDRB |= 0x20; 
 } 
 
void loop () {  
  unsigned char  *portB;  
  portB = (unsigned char  *) 0x25;  
  *portB |= 0x20;  //0010 0000 
  NewDelay (1000);  
  *portB &= 0xDF; //1101 1111 //** percent sign  to &
  NewDelay (1000); 
  } 
  
void NewDelay (unsigned long mSecondsApx){ //char to long
  //unsigned because otherwise you onl have half the values 
    
    volatile unsigned long i;  
    unsigned long endTime = 1000 * mSecondsApx;  
    for  (i = 0; i < endTime; i++); 
    
    }
*/







//Program B
void NewDelay (unsigned long mSecondsApx); 
void setup() {  
  unsigned char *portDDRB;  

portDDRB = (unsigned char *) 0x24;  
*portDDRB |= 0x20; 

} 

void loop () {  
  unsigned char *portB;  
  portB = (unsigned char *) 0x25;  
  *portB |= 0x20;  
  NewDelay (1000);  
  *portB &= 0xDF;  
  NewDelay (1000); } 
  
  void NewDelay (unsigned long mSecondsApx) {  
    volatile unsigned long i;  
    unsigned long j;  
    unsigned long k;  
    unsigned long endTime = 100 * mSecondsApx; 
 
 for (i = 0; i < endTime; i++)  {   
  j = 10;   
    do  {     
      j = j - i;     
      k = i/j;  
        } while (k>0);  
      } 
   }







//Program c 

void  NewDelay (unsigned long mSecondsApx); void  setup() {  unsigned char *portDDRB; 
 
 portDDRB = (unsigned char *) 0x24; 
 
 *portDDRB |= 0x20; } void loop () {  
  unsigned char *portB; 
 
 portB = (unsigned char *) 0x25; 
 
 *portB |= 0x20;  
 NewDelay (1000);  
 *portB &= 0xDF;  
 NewDelay (1000); 
 } 
 void NewDelay (unsigned long mSecondsApx) {  
  volatile unsigned long i;  
  unsigned long  j = 0;  
  unsigned long endTime = 100 * mSecondsApx;  
  i= 0;  
  while (j == 0)  {   
    i++;   
    if (i == endTime) {    
      j = 1;   
      }  
      } 
 }

 //divide 3*sin) /3) *2
 
