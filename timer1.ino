// this code sets up timer1 for a 1s  @ 16Mhz Clock (mode 4)


#include <avr/io.h>
#include <avr/interrupt.h>

ISR (TIMER1_COMPA_vect)
{
    Serial.println("IM IN");
}
int main(void)
{
    OCR1A = 0x3D08;

    TCCR1B |= (1 << WGM12);
    // Mode 4, CTC on OCR1A

    TIMSK1 |= (1 << OCIE1A);
    //Set interrupt on compare match

    TCCR1B |= (1 << CS12) | (1 << CS10);
    // set prescaler to 1024 and start the timer

Serial.begin(9600);
    sei();
    // enable interrupts


    while (1)
    {
        // we have a working Timer
    }
}
