/*
 * Register.h
 *
 *  Created on: 20.11.2016
 *      Author: johannes
 */

#ifndef REGISTER_H_
#define REGISTER_H_

class Register {
public:
	Register();
	virtual ~Register();

	uint64_t get(int num);

private:
	byte a, b, c, d, e, f, g, h;
	uint32_t rx;
	uint16_t getWord(byte *b1, byte *b2);
	uint32_t getDWord(byte *b1, byte *b2, byte *b3, byte *b4);
};

#endif /* REGISTER_H_ */
