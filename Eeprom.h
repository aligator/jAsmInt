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
};

#endif /* EEPROM_H_ */
