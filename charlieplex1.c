// charlieplex.c
// S. Foster
// 1-Mar-2007
//
// Description
//
#include <avr/io.h>
#include <avr/eeprom.h>

inline void delay( volatile uint16_t d )
{
	while ( --d )
		;				// Do nothing
}


int main( void )
{
	volatile uint16_t flash_data, i, j;

	while (1)
	{
		for ( i = 0; i < NUMBER_OF_LEDS; i++ )
		{
			flash_data = eeprom_read_word(i);
			if ( !flash_data ) break;

			PORTB 	= ( flash_data >>  0 ) & 0x003F;
			DDRB  	= ( flash_data >>  6 ) & 0x003F;

			for ( j = 0; i < (( flash_data >> 12 ) & 0x000F ); i ++ )
			{
				delay( eeprom_read_word(30) );
			}

			DDRB 	= 0;
			PORTB	= 0;

			for ( j = 0; i < eeprom_read_word(31); i ++ )
			{
				delay( 1000 );
			}
		}
	}
}
