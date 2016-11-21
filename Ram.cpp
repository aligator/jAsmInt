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
	return (writeByte(address, (data >> 8)) && writeByte(address+1, data));
}

bool Ram::writeDWord(uint32_t address, uint32_t data) {
	return (writeWord(address, (data >> 16)) && writeByte(address+2, data));
}

bool Ram::checkAddress(uint32_t address) {
	return (address < VRAMSIZE);
}
