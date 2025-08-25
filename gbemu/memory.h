#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>


// ROM Banks

extern uint8_t oam[0xA0];       // 160 bytes
extern uint8_t unusable[0x60];  // 96 bytes
extern uint8_t io[0x80];        // 128 bytes
extern uint8_t hram[0x7F];      // 127 bytes
extern uint8_t ie;              // 1 byte
extern uint8_t oam[0xA0];       // 160 bytes
extern uint8_t unusable[0x60];  // 96 bytes
extern uint8_t io[0x80];        // 128 bytes
extern uint8_t hram[0x7F];      // 127 bytes
extern uint8_t ie;              // 1 byte

// Functions

uint8_t read8(uint16_t address);
void write8(uint16_t address, uint8_t value);
void memory_init();

#endif
