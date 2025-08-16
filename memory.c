#include "memory.h"

// 64KB Game Boy address space

static uint8_t memory[0x10000];

uint8_t read8(uint16_t address) {
	return memory[address];
}

void write8(uint16_t address, uint8_t value) {
	memory[address] = value;
}

void memory_init() {
	memory[0x100] = 0x80;
}
