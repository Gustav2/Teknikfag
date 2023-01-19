#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "Servo.h"



int main(void) {
	/*
	DDRB |= 1 << PINB1; // Set pin 9 on arduino to output
	
	TCCR1A |= (1 << WGM11) | (1 << COM1A1);
	TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);
	
	ICR1 = 39999;

	int offset = 520;

	while(1) {
		OCR1A = 3999 + offset;
		_delay_ms(1000);
		OCR1A = 1999 - offset;
		_delay_ms(1000);
	}*/
	
	initServo(520);
	
	counterClockwise();
	_delay_ms(1000);
	turnDegrees(45);
	_delay_ms(1000);
	turnDegrees(90);
	_delay_ms(1000);
	turnDegrees(135);
	_delay_ms(1000);
	turnDegrees(180);

	
	return 0;
}