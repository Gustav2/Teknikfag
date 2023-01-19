/********************************************************
* "SWITCH.C":                                           *
* Implementation file for læsning af 2 knapper          *
* Knapperne forbindes til PIN B 0 og 1                  *
*********************************************************/
#include <avr/io.h>

#define MAX_SWITCH_NR 2

// Klargør switch-porten
void initSwitchPort()
{
	DDRB = 0x00;
	PORTB = 0x00;
}

// Læser alle switches samtidigt
unsigned char switchStatus()
{
	if (PINB & 0b00000101){
		return (PINB & 0b00000101);
	}
	return 0;
}

// Returnerer TRUE, hvis switchen med nummeret
// "switch_nr" er aktiveret - ellers returneres FALSE
unsigned char switchOn(unsigned char switch_nr)
{
	if (switch_nr <= MAX_SWITCH_NR)
	{
		return (PINB & (1 << switch_nr));
	}
	return 0;
} 
