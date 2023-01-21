#define F_CPU 12000000UL
#include <avr/io.h>
#include <util/delay.h>

int offset = 520;
void initServo(int _offset)
{
	DDRB |= 1 << PINB1; //pin 9 

	TCCR1A |= (1 << WGM11) | (1 << COM1A1);
	TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);


	ICR1 = 39999; // 39999
	
	//Offset for specific drivers
	offset = _offset;
}

void counterClockwise()
{
	OCR1A = 3999 + offset;
}

void clockwise()
{
	OCR1A = 1999 - offset;
}

void turnDegrees(int degrees)
{
	/* Works like in math - 0 is the most counterclockwise point*/   
	int step = ((3999 + offset) - (1999 - offset))/180;
	OCR1A = (1999 - offset) + (step * degrees);
}