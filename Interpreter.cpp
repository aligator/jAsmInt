#include "Interpreter.h"

Interpreter::Interpreter(const uint64_t *raw) {
	this->cmd = new Command(raw);
}

Interpreter::~Interpreter() {
}

// returns: true if program is finished
bool Interpreter::run(Register *reg) {
	switch (cmd->getCmd()) {
		case Command::EXIT:
			return true;
			break;
		case Command::MOV:
			move(reg);
			break;
		case Command::IPP:
			ipp(reg);
			break;
		case Command::PRINT:
			print(reg);
			break;
		default:
			break;
	}

	return false;
}

void Interpreter::move(Register *reg) {
	switch (cmd->getInfo()) {
		case 0:
			reg->set((int)cmd->getData(false), (uint64_t)cmd->getData(true));
			break;
		case 1:

			break;
		case 2:

			break;
		case 3:
			reg->set((int)cmd->getData(false), reg->get((int)cmd->getData(true)));
			break;
		default:
			break;
	}
}

void Interpreter::ipp(Register *reg) {
	switch (cmd->getInfo()) {
		case 0:
			uint32_t s1, s2;
			uint64_t res;

			s1 = toUint32_t((uint32_t)reg->get((int)cmd->getData(true)), true);
			s2 = toUint32_t((uint32_t)reg->get((int)cmd->getData(false)), false);

			res = s1 + s2;

			reg->set(14, (uint64_t)res);
			break;
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		default:
			break;
	}
}

void Interpreter::print(Register *reg) {
	switch (cmd->getInfo()) {
		case 0:
			Serial.println((int32_t)cmd->getBigData());
			break;
		case 1:
			Serial.println((int32_t)reg->get((int)cmd->getBigData()));
			break;
		case 2:

			break;
		case 3:

			break;
		default:
			break;
	}
}

uint32_t Interpreter::toUint32_t(uint32_t data, bool left) {
	int regNr = cmd->getData(left);

	byte msb = 0;
	uint32_t mask = 0;

	if (regNr >= 0 && regNr <= 7) {
		msb = data >> 7;
		mask = 0xFFFFFF00;
	} else if (regNr >= 8 && regNr <= 11) {
		msb = data >> 15;
		mask = 0xFFFF0000;
	} else if (regNr >= 12 && regNr <= 14) {
		return data;
	}
	if (msb ) {
		data |= mask;
	}


	return data;
}
