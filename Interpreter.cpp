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

			Serial.println("ipp: ");

			s1 = moveMiunsToMsb((uint32_t)reg->get((int)cmd->getData(true)));
			s2 = moveMiunsToMsb((uint32_t)reg->get((int)cmd->getData(false)));
			Serial.println((int32_t)s1);
			Serial.println((int32_t)s2);

			res = s1 + s2;

			Serial.println((uint32_t)(res >> 32));
			Serial.println((uint32_t)res);


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
			Serial.println((uint32_t)cmd->getBigData());
			break;
		case 1:
			Serial.println((uint32_t)reg->get((int)cmd->getBigData()));
			break;
		case 2:

			break;
		case 3:

			break;
		default:
			break;
	}
}

uint32_t Interpreter::moveMiunsToMsb(uint32_t data) {
	byte msb = 0;

	if (data <= 0xFF) {
		msb = data >> 7;
		data &= ~(1 << 8);
		Serial.println(data);
	} else if (data <= 0xFFFF) {
		msb = data >> 15;
		data &= ~((uint32_t)1 << 16);
	} else if (data <= 0xFFFFFFFF) {
		return data;
	}
	data ^= (-msb ^ data) & ((uint64_t)1 << 32);
	return data;
}
