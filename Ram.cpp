#include "Ram.h"

Ram::Ram() {
}

Ram::~Ram() {
}

bool Ram::writeByte(uint32_t address, byte data) {
	if (checkAddress(address)) {
		ram[address] = data;
		return false;
	}

	return true;
}

bool Ram::writeWord(uint32_t address, uint16_t data) {
	return (writeByte(address, (data >> 8)) & writeByte(address+1, data));
}

bool Ram::writeDWord(uint32_t address, uint32_t data) {
	return (writeWord(address, (data >> 16)) & writeByte(address+2, data));
}

bool Ram::checkAddress(uint32_t address) {
	return (address < VRAMSIZE);
}

byte Ram::readByte(uint32_t address) {
	if (checkAddress(address)) {
		return ram[address];
	}
	return 0;
}

uint16_t Ram::readWord(uint32_t address) {
	return (((uint16_t)readByte(address)) << 8 & readByte(address+1));
}

uint32_t Ram::readDWord(uint32_t address) {
	return (((uint32_t)readWord(address)) << 16 & readWord(address));
}
