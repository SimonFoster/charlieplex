// charlieplex.c
// S. Foster
// 1-Mar-2007
//
// Description
//

#include <avr/io.h>
#include <avr/eeprom.h>

#define LEDS        6

uint8_t flash_data[][2] =
{
    { 3, 1 },
    { 5, 1 },
    { 3, 2 },
    { 6, 2 },
    { 5, 4 },
    { 6, 4 },
};


inline void delay( void )
{
   volatile uint16_t count = 1000;

   while ( --count )
        ;
}


void flash_sequence( uint8_t s )
{
    PORTB   = flash_data[s][1];
    DDRB    = flash_data[s][0];

    delay();

    DDRB  = 0;

    delay();
}

int main( void )
{
    volatile uint8_t i;

    while (1)
    {
        for ( i = 0; i < ( LEDS - 1 ); i++ )
        {
            flash_sequence(i);
        }

        for ( i = ( LEDS - 1 ); i > 0; i-- )
        {
            flash_sequence(i);
        }
    }
}
