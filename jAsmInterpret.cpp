#include "jAsmInterpret.h"


void setup()
{
	eeprom = new Eeprom(0xFF);
}

void loop()
{
	uint64_t raw= eeprom->readNextCmd();
	RawCommand rawCmd(&raw);

}
