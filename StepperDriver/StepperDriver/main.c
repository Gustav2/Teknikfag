#include <avr/io.h>
#include "Stepper.h"


int main(void)
{
    initStepper();
	moveRotations(1, 1, 40);
	
    while (1) 
    {
    }
}

