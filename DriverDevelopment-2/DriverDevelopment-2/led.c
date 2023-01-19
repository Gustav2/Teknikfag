/*************************************************
* "LED.C":                                       *
* Implementation fil for Arduino LED driver.     *
* LED'erne er forbundet til PORT D.              *
**************************************************/
#include <avr/io.h>

#define MAX_LED_NR 7

void initLEDport()
{
	DDRD = 0xFF;
	PORTD = 0x00;
}

void writeAllLEDs(unsigned char pattern)
{
    PORTD = pattern;   
}

void turnOnLED(unsigned char led_nr)
{
  // Vi skal kun lave noget, hvis led_nr < 8
  if (led_nr <= MAX_LED_NR)
  {
    // T�nd den aktuelle lysdiode (de andre �ndres ikke)
     PORTD = (1 << led_nr);
  }   
}

void turnOffLED(unsigned char led_nr)
{
	if (led_nr <= MAX_LED_NR)
	{
		PORTD &= ~(1 << led_nr);
	}
}

void toggleLED(unsigned char led_nr)
{
	if (led_nr <= MAX_LED_NR)
	{
		PORTD ^= (1 << led_nr);
	}
}
