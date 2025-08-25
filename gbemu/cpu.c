#include <stdio.h>
#include "cpu.h"
#include "memory.h"
#include <string.h>

// 10 Registers: A, B, C, D, E, F, H, L, SP, PC


void op_add_a_b (CPU *cpu) {
	uint16_t result = cpu->A + cpu->B; // Adds together values stored in A and B registers of cpu

	cpu->F = 0; // clears Flags
	if ((result & 0xFF) == 0) cpu->F |= 0x80; // Zero flag
	if ((cpu->A & 0xF) + (cpu->B & 0xF) > 0xF) cpu->F |= 0x20; // Half carry
	if (result > 0xFF) cpu->F |= 0x10; // Carry flag
					   //
	cpu->A = (uint8_t) result; // store result in A
	printf("%i\n", result);
}


// 
void op_ld_a_b(CPU *cpu) {
	cpu->A = cpu->B;
}


void cpu_init(CPU *cpu) {
	memset(cpu, 0, sizeof(CPU));
	cpu->PC = 0x100;
	cpu->SP = 0xFFFE;
	cpu->A = 1;
	cpu->B = 2;
}


void cpu_step(CPU *cpu) {

	uint8_t opcode = read8(cpu->PC); //fetch the next byte from memory
	
	switch (opcode) {
		case 0x77: printf("Start"); break;
		case 0x78: op_ld_a_b(cpu); break;
		case 0x80: op_add_a_b(cpu); break;

		default: printf ("Unknown opcode %02X\n", opcode); break;
	}
	cpu->PC++;
}
