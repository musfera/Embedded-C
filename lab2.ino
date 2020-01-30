unsigned char *portDDRD;
 unsigned char *portD;
 unsigned char *pOCR0A;
 unsigned char *pOCR0B;
 unsigned char *pTCCR0A;
 unsigned char *pTCCR0B;
 unsigned char *pDDRC;

 unsigned char *pADMUX;

 unsigned char *pADCSRA;
 unsigned char *pADCSRB;
 unsigned char *pDIDR0;

void setup() {   // put your setup code here, to run once: 
  Serial.begin(9600); 


 

 
 portDDRD = (unsigned char *) 0x2A;
 pTCCR0A = (unsigned char *) 0x44;
 pTCCR0B = (unsigned char *) 0x45;
 pOCR0A = (unsigned char *) 0x47;
 pOCR0B = (unsigned char *) 0x48;
 pDDRC = (unsigned char *) 0x27;
 

 pADMUX = (unsigned char *) 0x7C;

 pADCSRA = (unsigned char *) 0x7A;
 pADCSRB = (unsigned char *) 0x7B;

 pDIDR0 = (unsigned char *) 0x7E;



 
 *portDDRD |= 0x20;

 //fast pwm
 *pTCCR0A |= 0x23;
 *pTCCR0B |= 0x0B;
 *pDDRC |= (0 << PC0);

 *pADMUX  |= 0x40;

 *pADCSRA  |= 0xE4;
 *pADCSRB |= 0x00;

 *pDIDR0 |= 0x01;

  }
 
void loop() {   // put your main code here, to run repeatedly: 
  float aval; 
  long x; 
  x = millis(); 
  *pOCR0A = 250;
  *pOCR0B = (aval*250)/3;
  aval =abs(3 * sin(2 * 3.141592654 * x / 1000)); 
  delay(1); 
  Serial.println(aval); 

  unsigned short *ADCData; 
  unsigned short ADCVal; 
  ADCData=(unsigned short *)0x78; 
  ADCVal=(*ADCData & 0x3FF); 

float fADCVal; 
fADCVal=((float)ADCVal)/1023 * 3;   

  Serial.print(abs(aval));  //Original rectified sinusoid 
  Serial.print(" "); 
  Serial.println(fADCVal);  //Analog voltage measured from ADC 
  }


/*
void setup() {
  // put your setup code here, to run once:
//DDRD|=1 << 5;
//DDRD |= 0x20;
DDRD |= 0x60; //Both 5 and 6 as outputs
//1KHz clock
OCR0A=250 /4;  //TOP
OCR0B=250 /2; //50% Duty Cycle
//TCCR0A=0x23; //Fast PWM, count up to OCR0A, set at 0, clr at match
//TCCR0A=0x33; //Fast PWM, count up to OCR0A, clear at 0, set at match
//TCCR0A=0xF3; //Fast PWM, both channels a and b, count up to OCR0A, clear at 0, set at match
TCCR0A=0xA3; //Fast PWM, both channels a and b, count up to OCR0A, set at 0, clear at match
//TCCR0B=0x0B; //clk/64 and 1 waveform bit
TCCR0B=0x03; //clk/64 and 1 waveform bit but now count to 255



}

void loop() {
  // put your main code here, to run repeatedly:

}

  */
