#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "Servo.h"



int main(void) {
	
	initServo(900); // 1150 for 270
	
	int isOpen = 0;
	counterClockwise();
	
	while (1)
	{
		if (PINB & (1 << 0))
		{
			if (isOpen)
			{
				turnDegrees(0);
				isOpen = 0;
				_delay_ms(1000);
			} 
			else {
				turnDegrees(90);
				isOpen = 1;
				_delay_ms(1000);
			}	
		}
	}
	
	return 0;
}