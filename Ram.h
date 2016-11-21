#define VRAMSIZE 512

#ifndef RAM_H_
#define RAM_H_
#include "Arduino.h"

class Ram {
public:
	Ram();
	virtual ~Ram();
	bool writeByte(uint32_t address, byte data);
	bool writeWord(uint32_t address, uint16_t data);
	bool writeDWord(uint32_t address, uint32_t data);
private:
	byte ram[VRAMSIZE] = {0};
	bool checkAddress(uint32_t address);
};

#endif /* RAM_H_ */
