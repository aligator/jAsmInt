#include "jAsmInterpret.h"

#include "Command.h"
#include "Interpreter.h"

void setup()
{
	Serial.begin(9600);
	eeprom = new Eeprom(0xFF);
	reg = new Register();
	isFinished = false;
}

void loop()
{
	//const uint64_t raw= eeprom->readNextCmd();
	uint64_t raw = 0x0400010000;
	if (!isFinished) {
		Interpreter interpreter(&raw);
		isFinished = interpreter.run(reg);
	}
	raw = 0x0400020001;

	if (!isFinished) {
		Interpreter interpreter(&raw);
		isFinished = interpreter.run(reg);
	}

	raw = 0x0C00000001;

	if (!isFinished) {
		Interpreter interpreter(&raw);
		isFinished = interpreter.run(reg);
	}

	raw = 0x210000000E;

	if (!isFinished) {
		Interpreter interpreter(&raw);
		isFinished = interpreter.run(reg);
	}

	raw = 0x0000000000;
	if (!isFinished) {
		Interpreter interpreter(&raw);
		isFinished = interpreter.run(reg);
	}

	delay(1000);
}
