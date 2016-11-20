#ifndef EEPROM_H_
#define EEPROM_H_

#include "Wire.h"

class Eeprom {
public:
	Eeprom(int deviceaddress);
	virtual ~Eeprom();
	uint64_t readNextCmd();

private:
	bool chekPos();
	void incPos(int count);
	int device;
	uint16_t pos;

	bool debug = true;
	uint64_t debugData[5] = {
			0x0400010000,
			0x0400FF0001,
			0x0C00010000,
			//0x0C000E0000,
			//0x0C000E0000,
			//0x0C000E0000,
			//0x0C000E0000,
			0x210000000E,
			0x0000000000
	};
};

#endif /* EEPROM_H_ */
