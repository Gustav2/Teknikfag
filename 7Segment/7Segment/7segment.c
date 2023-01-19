#include <avr/io.h>
void initSegment(){
	DDRD = 0xFF;
	PORTD = 0;
}

void turnOn(){
	PORTD = 0xFF;
}

void turnOff(){
	PORTD = 0;
}

void writeSegment(int number){
	unsigned char segment[] = {
		0b11111100,
		0b01100001,
		0b11011010,
		0b11110010,
		0b01100110,
		0b10110110,
		0b10111110,
		0b11100000,
		0b11111110,
		0b11100110
	};
	PORTD = segment[number];
}