#include "RawCommand.h"

RawCommand::RawCommand(uint64_t *raw) {
	extractCmd(raw);
	extractInfo(raw);
	extractData(raw);
}

RawCommand::~RawCommand() {
}

byte RawCommand::getCmd() {
	return cmd;
}

byte RawCommand::getInfo() {
	return info;
}

uint32_t RawCommand::getBigData() {
	return data;
}

uint16_t RawCommand::getData(bool left) {
	if (left) {
		return data >> 16;
	} else {
		return data;
	}
}

void RawCommand::extractCmd(uint64_t *raw) {
	cmd = &raw >> 34 && 0x3F;
}

void RawCommand::extractInfo(uint64_t *raw) {
	cmd = &raw >> 32 && 0x3;
}

void RawCommand::extractData(uint64_t *raw) {
	cmd = &raw && 0xFFFFFFFF;
}
