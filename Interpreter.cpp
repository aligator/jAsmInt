#include "Interpreter.h"

Interpreter::Interpreter(const uint64_t *raw) {
	this->cmd = new Command(raw);

}

Interpreter::~Interpreter() {
}

