#include <avr/io.h>

#define PINS    6

inline void delay( void )
{
    volatile uint16_t count = 1000;

    while ( --count )
        ;
}


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
                delay();
                DDRB  = 0;
            }
        }
    }
}
