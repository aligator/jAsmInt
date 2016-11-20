#ifndef _jAsmInterpret_H_
#define _jAsmInterpret_H_

#include "Arduino.h"
#include "Eeprom.h"
#include "Register.h"

void setup();
void loop();

Eeprom *eeprom;
Register *reg;

#endif /* _jAsmInterpret_H_ */
