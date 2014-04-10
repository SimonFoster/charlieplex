// charlieplex.c
// S. Foster
// 1-Mar-2007
//
// Description
//
#include <avr/io.h>
#include <avr/eeprom.h>

#define SLOWER 1

EEMEM uint16_t flash_data[] =
{
    #include "patterns/kitt.h"
};


inline void delay( volatile uint16_t d )
{
    uint8_t i;

    i = SLOWER;
    while ( --i )
        while ( --d )
            ;               // Do nothing
}


inline void drive_port( uint16_t pattern )
{
    PORTB   = ( pattern >>  0 ) & 0x003F;
    DDRB    = ( pattern >>  6 ) & 0x003F;
}

int main( void )
{
    volatile uint8_t i;

    while (1)
    {
        for ( i = 0; i < 30; i++ )
        {
            if ( !flash_data[i] ) break;

            drive_port( flash_data[i] );

            delay( flash_data[30] * ( flash_data[i] >> 12 ));

            DDRB  = 0;

            delay( flash_data[31] );
        }
    }
}
