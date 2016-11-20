#ifndef INTERPRETER_H_
#define INTERPRETER_H_
#include "Command.h"

class Interpreter {
public:
	Interpreter(const uint64_t *raw);
	virtual ~Interpreter();
	bool run();

private:
	Command *cmd;
	void move();
};

#endif /* INTERPRETER_H_ */
