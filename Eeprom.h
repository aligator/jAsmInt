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
			/*0x0400020009,
			0x04FFFF0008,
			0x0C00080009,
			0x210000000E,

			0x0400FF0000,
			0x04FFFF0009,
			0x0C00000009,
			0x210000000E,
*/
			0x047FFF0009,
			0x04FFFF0008,
			0x0C00090008,
			0x210000000E,

			0x0000000000
	};
};

#endif /* EEPROM_H_ */
