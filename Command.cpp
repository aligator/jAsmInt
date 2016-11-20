#include "Command.h"

Command::Command(const uint64_t *raw) {
	extractCmd((uint64_t)*raw);
	extractInfo((uint64_t)*raw);
	extractData((uint64_t)*raw)
}

Command::~Command() {
}

Command::Cmds Command::getCmd() {
	return cmd;
}

byte Command::getInfo() {
	return info;
}

uint32_t Command::getBigData() {
	return data;
}

uint16_t Command::getData(bool left) {
	if (left) {
		return data >> 16;
	} else {
		return data;
	}
}

void Command::extractCmd(uint64_t raw) {
	raw = (raw >> 34) & 0x3F;

	// Undefinded behavior if tmp is not in scope of Cmds!!!
	cmd = static_cast<Cmds>(raw);
}

void Command::extractInfo(uint64_t raw) {
	info = raw >> 32 & 0x3;
}

void Command::extractData(uint64_t raw) {
	data = raw & 0xFFFFFFFF;
}
