/****************************************** *
* Testprogram for Arduino 7?segment driver *
* *
* 7?segment forbundet til PORT D *
* *
*******************************************/
#define F_CPU 16000000UL
#define KORT_PAUSE _delay_ms(500)
#define PAUSE _delay_ms(2000)
#define RATE 200/2

#include <avr/io.h>
#include <util/delay.h>

#include "7segment.h"

int main()
{

	// Test af "init7segmentport"
	initSegment();
	PAUSE;
	// Test af Segment
	writeSegment(4, 0);
    PAUSE;
	writeSegment(2, 1);
	PAUSE;
	turnOff();
	PAUSE;

	int num = 0;
	unsigned long i = 0;
	int d0 = 0;
	int d1 = 0;
	while (1){
		if (i > RATE)
		{
			num++;
			d0 = num % 10;
			d1 = num / 10;
			i = 0;
		}
		if (num > 99)
		{
			turnOn(0);
			PAUSE;
			turnOn(1);
			PAUSE;
			turnOff();
			break;
		}
		writeSegment(d0, 0);
		_delay_ms(1);
		writeSegment(d1, 1);
		_delay_ms(1);
		i++;
	}
	return 0;
}