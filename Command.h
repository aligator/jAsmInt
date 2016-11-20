#ifndef COMMAND_H_
#define COMMAND_H_
#include "Arduino.h"

class Command {
public:
	enum Cmds {
				EXIT, MOV, MOVDW, IPP, IMM, PRINT=8
	};

	Command(const uint64_t *raw);
	virtual ~Command();
	Cmds getCmd();
	byte getInfo();
	uint32_t getBigData();
	uint16_t getData(bool left);

private:
	Cmds cmd;
	byte info;
	uint32_t data;

	void extractCmd(uint64_t raw);
	void extractInfo(uint64_t raw);
	void extractData(uint64_t raw);
};

#endif /* COMMAND_H_ */
