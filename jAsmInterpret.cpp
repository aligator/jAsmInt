#include "jAsmInterpret.h"

#include "Command.h"
#include "Interpreter.h"

void setup()
{
	Serial.begin(9600);
	eeprom = new Eeprom(0xFF);
	reg = new Register();
	isFinished = false;

	Serial.println("----------------");
}

void loop()
{
	const uint64_t raw= eeprom->readNextCmd();

	if (!isFinished) {
		Interpreter interpreter(&raw);
		isFinished = interpreter.run(reg);
	}
}
