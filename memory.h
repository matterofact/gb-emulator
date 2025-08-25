#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>


// ROM Banks

extern uint8_t memory[0x10000];
extern uint8_t rom_bank0[0x4000]; // 16 KB
extern uint8_t rom_bankN[0x4000]; // 16 KB
extern uint8_t vram[0x2000];      // 8 KB
extern uint8_t eram[0x2000];      // 8 KB (External RAM)
extern uint8_t wram[0x4000];      // 16 KB (WRAM = banked WRAM for CGB
extern uint8_t unusable_echo_ram[0x7680]; // 7.5 KB, unusable echo RAM
extern uint8_t oam[0xA0];       // 160 bytes
extern uint8_t unusable[0x60];  // 96 bytes
extern uint8_t io[0x80];        // 128 bytes
extern uint8_t hram[0x7F];      // 127 bytes (fast internal RAM)
extern uint8_t ie;              // 1 byte

// Functions

uint8_t read8(uint16_t address);
void write8(uint16_t address, uint8_t value);
void memory_init();

#endif
