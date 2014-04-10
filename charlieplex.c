// charlieplex.c
// S. Foster
// 1-Mar-2007
//
// Description
//

#include <avr/io.h>
#include <avr/eeprom.h>

#define SLOWER 100

0   1
0   2
1   0
1   2
2   0
2   1

EEMEM uint16_t flash_data[] =
{
    0xf0c1,
    0xf141,
    0xf241,
    0xf441,
    0xf841,
    0xf0c2,
    0xf182,
    0xf282,
    0xf482,
    0xf882,
    0xf144,
    0xf184,
    0xf304,
    0xf504,
    0xf904,
    0xf248,
    0xf288,
    0xf308,
    0xf608,
    0xfa08,
    0xf450,
    0xf490,
    0xf510,
    0xf610,
    0xfc10,
    0xf860,
    0xf8a0,
    0xf920,
    0xfa20,
    0xfc20,

    10,         // On Time Scaler
    10,         // Off Time Scaler
};


inline void delay( volatile uint16_t d )
{
    volatile uint16_t c1, c2;

    c1 = SLOWER;
    while ( --c1 )
    {
        c2 = d;
        while ( --c2 )
            ;               // Do nothing
    }
}


uint16_t get_eeprom_data( uint8_t offset )
{
    return eeprom_read_word((const uint16_t*)( 2 * offset ));
}

void flash_sequence( uint8_t s )
{
    volatile uint16_t flash_data, on_delay, off_delay;

    flash_data = get_eeprom_data(s);

    PORTB   = ( flash_data >>  0 ) & 0x003F;
    DDRB    = ( flash_data >>  6 ) & 0x003F;

    on_delay = get_eeprom_data(30);
    on_delay *= ( flash_data >> 12 );
    delay( on_delay );

    DDRB  = 0;

    off_delay = get_eeprom_data(31);
    delay( off_delay );
}

int main( void )
{
    volatile uint8_t i;

    while (1)
    {
        for ( i = 0; i < 29; i++ )
        {
            flash_sequence(i);
        }

        for ( i = 29; i > 0; i-- )
        {
            flash_sequence(i);
        }
    }
}
