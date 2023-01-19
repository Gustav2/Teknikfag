/*********************************************
* Testprogram for Arduino kontakter          *
*                                            *
* Arduino Setup:                             *
* Forbind 8 LED'er til PORT D 0-7.           *
* Forbind 2 kontakter til PIN B 0-1.         *
*                                            *
**********************************************/
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "switch.h"
#include "led.h"



int main()
{
unsigned char i;

  // Klarg�ring af SWITCH-porten
  initSwitchPort();
  // Klarg�ring af LED-porten
  initLEDport();
  
  // Test af switchStatus():
  // Resultatet skrives til hele lysdiodeporten
  // Testen afsluttes, n�r man samtidigt
  // trykket p� SW0 og SW1
  
  i = 0;
  while (i != 0b00000101)
  {
    i = switchStatus();
    writeAllLEDs(i);
  }
  
  // T�nd alle lysdioder i 2 sekunder
  // og sluk s� alle lysdioder
  // S� kan vi se, at n�ste test starter
  writeAllLEDs(0xFF);
  _delay_ms(2000);  
  writeAllLEDs(0);
  
  // Test af switchOn():
  // L�s p� skift de 2 kontakter
  // Trykkes knappen p� PINB0, skal LED0 t�nde
  // For hver gang samme knap p�virkes, skal den t�ndte diode
  // rykke 1 mod venstre. Trykkes knappen p� PINB1, skal den 
  // t�ndte diode rykke 1 mod h�jre.
  int lednr = 5;
  turnOnLED(lednr);
  while (1)
  {
    lednr %= 8;
    if (switchOn(0)){
	    lednr++;
		_delay_ms(100);
    }
    else if (switchOn(2)){
	    lednr--;
		_delay_ms(100);
    }
    writeAllLEDs(1 << lednr);
    
  }
  return 0;  
}
