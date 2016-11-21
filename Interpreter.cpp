#include "Interpreter.h"

Interpreter::Interpreter(const uint64_t *const raw, Register *const reg, Ram *const ram) {
	this->cmd = new Command(raw);
	this->reg = reg;
	this->ram = ram;
}

Interpreter::~Interpreter() {
}

// returns: true if program is finished
bool Interpreter::run() {
	switch (cmd->getCmd()) {
		case Command::EXIT:
			return true;
			break;
		case Command::MOV:
			move();
			break;
		case Command::MOVDW:
			moveDw();
			break;
		case Command::IPP:
			ipp(false);
			break;
		case Command::IMM:
			ipp(true);
			break;
		case Command::PRINT:
			print();
			break;
		default:
			break;
	}

	return false;
}

void Interpreter::move() {
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

void Interpreter::moveDw() {
	switch (cmd->getInfo()) {
		case 0:
			reg->set(12, (uint64_t)cmd->getBigData());
			break;
		case 1:
			reg->set(13, (uint64_t)cmd->getBigData());
			break;
		case 2:

			break;
		case 3:

			break;
		default:
			break;
	}
}

void Interpreter::ipp(bool minus) {
	switch (cmd->getInfo()) {
		case 0:
			uint32_t s1, s2;
			uint64_t res;

			s1 = toUint32_t((uint32_t)reg->get((int)cmd->getData(true)), true);
			s2 = toUint32_t((uint32_t)reg->get((int)cmd->getData(false)), false);

			if (minus) {
				res = s1 - s2;
			} else {
				res = s1 + s2;
			}

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

void Interpreter::print() {
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
	if (msb) {
		data |= mask;
	}


	return data;
}
