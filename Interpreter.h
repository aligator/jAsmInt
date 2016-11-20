#ifndef INTERPRETER_H_
#define INTERPRETER_H_
#include "Command.h"
#include "Register.h"

class Interpreter {
public:
	Interpreter(const uint64_t *raw);
	virtual ~Interpreter();
	bool run(Register *reg);

private:

	Command *cmd;
	void move(Register *reg);
	void ipp(Register *reg);
	void print(Register *reg);
	uint32_t moveMiunsToMsb(uint32_t data);
};

#endif /* INTERPRETER_H_ */
