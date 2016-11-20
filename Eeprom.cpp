#include "Eeprom.h"

Eeprom::Eeprom(int deviceaddress) {
	device = deviceaddress;
	pos = 0;
}

Eeprom::~Eeprom() {
}

uint64_t Eeprom::readNextCmd() {
	uint64_t rdata = 0;

	for (int i = 0; i < 5; ++i) {

		Wire.beginTransmission(device);
		Wire.write((int)(pos >> 8));   // MSB
		Wire.write((int)(pos & 0xFF)); // LSB
		Wire.endTransmission();

		Wire.requestFrom(device,1);

		if (Wire.available()) {

			rdata = rdata << 8;
			rdata = rdata | Wire.read();
		}

		incPos(1);
	}

	return rdata;
}

void Eeprom::incPos(int count) {
	pos += 5;
	if (chekPos()) {
		pos = 32767;
	}
}

bool Eeprom::chekPos() {
	if (pos > 32767) {
		return false;
	}

	return true;
}
