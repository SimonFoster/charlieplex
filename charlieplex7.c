#include <avr/io.h>

#define F_CPU   9600000/8

#include <util/delay.h>

int main( void )
{
    DDRB = 1;

    while (1)
    {

        PORTB = 1;
        _delay_ms( 50 );
        PORTB = 0;
        _delay_ms( 50 );
    }
}
