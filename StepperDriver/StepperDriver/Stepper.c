#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#define __DELAY_BACKWARD_COMPATIBLE__

int prevStepI = 3; // index 
int forwardOrder[] = {0,2,1,3}; // Pins
int reverseOrder[] = {3,1,2,0};

void varDelayMs(int ms)
{
	while (0 < ms)
	{
		_delay_ms(1);
		--ms;
	}
}

void initStepper() {
	DDRD = 0x0F;
}

void moveSteps(int amount, char forward, double stepTime) {
	int currStep;
	int singleStepTime = floor((stepTime / amount) * 1000);
	if (forward) {
		for (int i = 0; i < amount; i++) {
			currStep = (prevStepI + 1 + i) % 4;
			PORTD = 1<<forwardOrder[currStep];
			varDelayMs(singleStepTime);
		}
	}
	else {
		for (int i = 0; i < amount; i++) {
			currStep = (prevStepI + 1 + i) % 4;
			PORTD = 1<<reverseOrder[currStep];
			varDelayMs(singleStepTime);
		}
	}
}

void moveRotations(int amount, char forward, double rotTime) {
	moveSteps(200*amount, forward, rotTime);
}