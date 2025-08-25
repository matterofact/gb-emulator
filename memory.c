#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"

// 64KB Game Boy address space

uint8_t memory[0x10000];
uint8_t rom_bank0[0x4000]; // 16 KB
uint8_t rom_bankN[0x4000]; // 16 KB
uint8_t vram[0x2000];      // 8 KB
uint8_t eram[0x2000];      // 8 KB (External RAM)
uint8_t wram[0x4000];      // 16 KB (WRAM = banked WRAM for CGB
uint8_t unusable_echo_ram[0x7680]; // 7.5 KB, unusable echo RAM
uint8_t oam[0xA0];       // 160 bytes
uint8_t unusable[0x60];  // 96 bytes
uint8_t io[0x80];        // 128 bytes
uint8_t hram[0x7F];      // 127 bytes (fast internal RAM)
uint8_t ie;              // 1 byte
//static uint8_t io[0x
//static uint8_t hram[0x
//static char 

uint8_t read8(uint16_t address) {
	return memory[address];
}

void write8(uint16_t address, uint8_t value) {
	memory[address] = value;
}

void memory_init() {
	memset(rom_bank0, 0, sizeof(rom_bank0));
	memset(rom_bankN, 0, sizeof(rom_bankN));
	memset(vram, 0, sizeof(vram));
	memset(eram, 0, sizeof(eram));
	memset(wram, 0, sizeof(wram));
	memset(unusable_echo_ram, 0, sizeof(unusable_echo_ram));
	memset(oam, 0, sizeof(oam));
	memset(unusable, 0, sizeof(unusable));
	memset(io, 0, sizeof(io));
	hram[0x7F-1] = 0;
	ie = 0;
}

