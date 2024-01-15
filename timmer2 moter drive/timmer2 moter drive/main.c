#include <avr/io.h>
#define F_CPU 1000000UL
#include "util/delay.h"


int main(void)
{
	DDRB = 0xFF;
	PORTB = 0x00;
	DDRC = 0x00;
	PORTC = 0xFF;
	
	TCCR2 |=  (1 << WGM20) ;
	TCCR2 |= (1 << COM20) | (1<<COM21);
	TCCR2 |= (1 << CS20);
	OCR2 = 255;
	while (1)
	{
		if ((PINC & (1 << 3))==0)
		{
		
		for (int i=255;i<0;i-30)
		{
			OCR2 = i;
			_delay_ms(100);
		}
		}
		
		
	}
}



