/**********************************************************
* "SWITCH.H":                                             *
* Header file for l�sning af 2 knapper p� Arduino         *
* Knapperne forbindes til PIN B 0 og 1                    *
***********************************************************/
void initSwitchPort();
unsigned char switchStatus();
unsigned char switchOn(unsigned char switch_nr);
/**********************************************************/