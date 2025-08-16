#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>


// Functions

uint8_t read8(uint16_t address);
void write8(uint16_t address, uint8_t value);
void memory_init();

#endif
