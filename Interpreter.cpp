#include "Interpreter.h"

Interpreter::Interpreter(const uint64_t *raw) {
	this->cmd = new Command(raw);
}

Interpreter::~Interpreter() {
}

// returns: true if program is finished
bool Interpreter::run(const Register *reg) {
	switch (cmd->getCmd()) {
		case Command::EXIT:
			return true;
			break;
		case Command::MOV:
			move();
		default:
			break;
	}

	return false;
}

void Interpreter::move() {
	switch (cmd->getInfo()) {
		case 0:

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
