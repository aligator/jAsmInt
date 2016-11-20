/*
 * Register.cpp
 *
 *  Created on: 20.11.2016
 *      Author: johannes
 */

#include "Register.h"

Register::Register() {
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
	g = 0;
	h = 0;
	rx = 0;
}

Register::~Register() {

}

void Register::printAll() {
	Serial.println("All registers:");
	Serial.print("a: ");
	Serial.println(a);
	Serial.print("b: ");
	Serial.println(b);
	Serial.print("c: ");
	Serial.println(c);
	Serial.print("d: ");
	Serial.println(d);
	Serial.print("e: ");
	Serial.println(e);
	Serial.print("f: ");
	Serial.println(f);
	Serial.print("g: ");
	Serial.println(g);
	Serial.print("h: ");
	Serial.println(h);
	Serial.print("w1: ");
	Serial.println((uint32_t)get(8));
	Serial.print("w2: ");
	Serial.println((uint32_t)get(9));
	Serial.print("w3: ");
	Serial.println((uint32_t)get(10));
	Serial.print("w4: ");
	Serial.println((uint32_t)get(11));
	Serial.print("ax: ");
	Serial.println((uint32_t)get(12));
	Serial.print("bx: ");
	Serial.println((uint32_t)get(13));
	Serial.print("rx: ");
	Serial.println((uint32_t)get(14));
}

uint64_t Register::get(int num) {

	switch (num) {
		case 0:
			return a;
			break;
		case 1:
			return b;
			break;
		case 2:
			return c;
			break;
		case 3:
			return d;
			break;
		case 4:
			return e;
			break;
		case 5:
			return f;
			break;
		case 6:
			return g;
			break;
		case 7:
			return h;
			break;
		case 8:
			return getWord(&a, &b);
			break;
		case 9:
			return getWord(&c, &d);
			break;
		case 10:
			return getWord(&e, &f);
			break;
		case 11:
			return getWord(&g, &h);
			break;
		case 12:
			return getDWord(&a, &b, &c, &d);
			break;
		case 13:
			return getDWord(&e, &f, &g, &h);
			break;
		case 14:
			return rx;
			break;
		default:
			return 0;
			break;
	}
}

// returns: false if no error
//          true if overflow
bool Register::set(int num, uint64_t data) {

	switch (num) {
		case 0:
			return setByte(&a, data);
			break;
		case 1:
			return setByte(&b, data);
			break;
		case 2:
			return setByte(&c, data);
			break;
		case 3:
			return setByte(&d, data);
			break;
		case 4:
			return setByte(&e, data);
			break;
		case 5:
			return setByte(&f, data);
			break;
		case 6:
			return setByte(&g, data);
			break;
		case 7:
			return setByte(&h, data);
			break;
		case 8:
			return setWord(&a, &b, data);
			break;
		case 9:
			return setWord(&c, &d, data);
			break;
		case 10:
			return setWord(&e, &f, data);
			break;
		case 11:
			return setWord(&g, &h, data);
			break;
		case 12:
			return setDWord(&a, &b, &c, &d, data);
			break;
		case 13:
			return setDWord(&e, &f, &g, &h, data);
			break;
		case 14:
			return setDWord(&rx, data);
			break;
		default:
			return true;
			break;
	}
}

bool Register::setByte(byte *reg, uint64_t data) {
	if (data > 0xFF) {
		*reg = data;
		return true;
	} else {
		*reg = data;
		return false;
	}
}

bool Register::setWord(byte *reg1, byte *reg2, uint64_t data) {
	bool ret = false;
	if (data > 0xFFFF) {
		ret = true;
	}
	setByte(reg1, (data >> 8));
	setByte(reg2, ((byte)data));

	return ret;
}

bool Register::setDWord(byte *reg1, byte *reg2, byte *reg3, byte *reg4, uint64_t data) {
	bool ret = false;
	if (data > 0xFFFFFFFF) {
		ret = true;
	}
	setByte(reg1, (data >> 24));
	setByte(reg2, (data >> 16));
	setByte(reg3, (data >> 8));
	setByte(reg4, (data));

	return ret;
}

bool Register::setDWord(uint32_t *reg1, uint64_t data) {
	bool ret = false;
	if (data > 0xFFFFFFFF) {
		ret = true;
	}

	*reg1 = data;

	return ret;
}

uint16_t Register::getWord(byte *b1, byte *b2) {
	return (uint16_t(*b1) << 8) | *b2;
}

uint32_t Register::getDWord(byte *b1, byte *b2, byte *b3, byte *b4) {
	return ((uint32_t)getWord(b1, b2) << 16) | getWord(b3, b4);
}
