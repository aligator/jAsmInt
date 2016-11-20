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
			int64_t s1, s2, res;
			s1 = (int64_t)reg->get((int)cmd->getData(true));
			s2 = (int64_t)reg->get((int)cmd->getData(false));

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
