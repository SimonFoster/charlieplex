#include <avr/io.h>

#define F_CPU   9600000/8

#include <util/delay.h>

#define PINS    6
#define LEDS	( PINS * ( PINS - 1 ))

int main( void )
{
    volatile uint8_t hi, lo;

    while (1)
    {
        for ( hi = 0; hi < PINS; hi++ )
        {
            for ( lo = 0; lo < PINS; lo++ )
            {
                if ( hi == lo ) continue;

                PORTB   = ( 1 << hi );
                DDRB    = ( 1 << hi ) +  ( 1 << lo );
                _delay_ms( 1000 / LEDS );
                DDRB  = 0;
            }
        }
    }
}
