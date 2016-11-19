// Do not remove the include below
#include "jAsmInterpret.h"


//The setup function is called once at startup of the sketch
void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
}

// The loop function is called in an endless loop
void loop()
{
	digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(100);                       // wait for a second
	digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
	delay(100);                       // wait for a second
}
