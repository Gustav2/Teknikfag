#include <avr/io.h>
unsigned char segment[] = {
	0b00111111,
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01100111
};

void initSegment(){
	DDRD = 0xFF;
	DDRB = 0x03;
	PORTD = 0x00;
	PORTB = 0x03;
}

void turnOn(int segmentNum){	
	if (segmentNum == 0)
	{
		PORTB = 0x02;
	}
	else {
		PORTB = 0x01;
	}
	
	PORTD = 0xFF;
}

void turnOff(){
	PORTD = 0x00;
	PORTB = 0x03;
}

void writeSegment(int number, int segmentNum){
	if (segmentNum == 0)
	{
		PORTB = 0x02;
	}
	else {
		PORTB = 0x01;
	}
	
	PORTD = segment[number];
}

