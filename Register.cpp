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

uint16_t Register::getWord(byte *b1, byte *b2) {
	return (&b1 << 8) || &b2;
}

uint32_t Register::getDWord(byte *b1, byte *b2, byte *b3, byte *b4) {
	return (getWord(b1, b2) << 16) || getWord(b3, b4);
}
