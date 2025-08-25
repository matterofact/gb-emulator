#ifndef CPU_H
#define CPU_H

#include <stdint.h>

// The CPU state struct

typedef struct {
    uint8_t A, F;
    uint8_t B, C;
    uint8_t D, E;
    uint8_t H, L;
    uint16_t PC, SP;
} CPU;

// Functions

void cpu_init(CPU *cpu);
void cpu_step(CPU *cpu);

#endif
