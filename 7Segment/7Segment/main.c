/****************************************** *
* Testprogram for Arduino 7?segment driver *
* *
* 7?segment forbundet til PORT D *
* *
*******************************************/
#define F_CPU 16000000UL
#define KORT_PAUSE _delay_ms(500)
#define PAUSE _delay_ms(2000)

#include <avr/io.h>
#include <util/delay.h>

#include "7segment.h"

int main()
{
	unsigned char i,j;
	// Test af "init7segmentport"
	initSegment();
	PAUSE;
	// Test af Segment
	turnOn();
	PAUSE;
	turnOff();
	PAUSE;
	// Test1 af "Skrivtal"
	for (j=0; j<10;j++)
	{
		for (i=0; i<6; i++)
		{
			PORTD = 1<<i;
			_delay_ms(100);
		}
	}
	turnOff();
	PAUSE;
	// Test2 af "Skrivtal"
	for (i=0; i<=9; i++)
	{
		writeSegment(i);
		KORT_PAUSE;
	}
	// Bliv her
	while (1)
	{}
	return 0;
}