/*
 * Register.h
 *
 *  Created on: 20.11.2016
 *      Author: johannes
 */

#ifndef REGISTER_H_
#define REGISTER_H_
#include "Arduino.h"

class Register {
public:
	Register();
	virtual ~Register();

	uint64_t get(int num);
	bool set(int num, uint64_t data);

private:
	byte a, b, c, d, e, f, g, h;
	uint32_t rx;
	uint16_t getWord(byte *b1, byte *b2);
	uint32_t getDWord(byte *b1, byte *b2, byte *b3, byte *b4);
	bool setByte(byte *reg, uint64_t data);
	bool setWord(byte *reg1, byte *reg2, uint64_t data);
	bool setDWord(byte *reg1, byte *reg2, byte *reg3, byte *reg4, uint64_t data);
	bool setDWord(uint32_t *reg1, uint64_t data);
};

#endif /* REGISTER_H_ */
