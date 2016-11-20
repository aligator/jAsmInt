#include "jAsmInterpret.h"

#include "Command.h"

void setup()
{
	eeprom = new Eeprom(0xFF);
}

void loop()
{
	const uint64_t raw= eeprom->readNextCmd();
	Interpreter interpreter(&raw);

}
