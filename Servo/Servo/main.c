#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "Servo.h"



int main(void) {
	
	initServo(900); // 1150 for 270
	
	counterClockwise();
	_delay_ms(3000);
	clockwise();


	
	return 0;
}