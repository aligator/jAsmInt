#ifndef INTERPRETER_H_
#define INTERPRETER_H_
#include "Command.h"
#include "Register.h"

class Interpreter {
public:
	Interpreter(const uint64_t *const raw, Register *const reg);
	virtual ~Interpreter();
	bool run();

private:
	Command *cmd;
	Register *reg;

	void move();
	void moveDw();
	void ipp(bool minus);
	void print();
	uint32_t toUint32_t(uint32_t data, bool left);
};

#endif /* INTERPRETER_H_ */
