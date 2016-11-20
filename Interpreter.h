#ifndef INTERPRETER_H_
#define INTERPRETER_H_
#include "Command.h"

class Interpreter {
public:
	Interpreter(const uint64_t *raw);
	virtual ~Interpreter();

private:
	Command *cmd;
};

#endif /* INTERPRETER_H_ */
