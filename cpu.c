#include <stdio.h>
#include "cpu.h"
#include "memory.h"
#include <string.h>

// 10 Registers: A, B, C, D, E, F, H, L, SP, PC

//0x00

void op_nop(CPU *cpu) {
	printf("nop");
}

//0x01
void op_ld_bc_u16(CPU *cpu) {
	printf("ld bc,u16");
}

//0x02
void op_ld_bc_a(CPU *cpu) {
	printf("ld bc,a");
}

//0x03
void op_inc_bc(CPU *cpu) {
	printf("inc bc");
}

//0x04

void op_inc_b(CPU *cpu) {
	cpu->B++;
	printf("%i\n", cpu->B);
}

//0x05

void op_dec_b(CPU *cpu) {
	cpu->B--;
	printf("%i\n", cpu->B);
}

//0x06

 void op_ld_b_u8(CPU *cpu) {
	printf("ld b u8");
}

//0x07

void op_rlca(CPU *cpu) {
	printf("rlca");
}

//0x08

void op_ld_u16_sp(CPU *cpu) {
	printf("ld u16 sp");
}
//0x0A

void op_ld_a_bc(CPU *cpu) {
	printf("ld a bc");
}

//0x0B

void op_dec_bc(CPU *cpu) {
	printf("dec bc");
}

//0x0C

void op_inc_c(CPU *cpu) {
	cpu->C++;
	printf("%i\n", cpu->C);
}

//0x0D

void op_dec_c(CPU *cpu) {
	cpu->C--;
	printf("%i\n", cpu->C);
}

//0x0E

void op_ld_c_u8(CPU *cpu) {
	printf("ld c u8");
}

//0x0F

void op_rrca(CPU *cpu) {
	printf("rrca");
}


/*0x09

void op_add_hl_bc(CPU *cpu) {
	printf("add hl bc");
}

//0x10

void op_inc(CPU *cpu) {
	printf("inc bc");
}

//0x11

void op_inc_bc(CPU *cpu) {
	printf("inc bc");
}

//0x12


//0x13


//0x14


//0x15

//0x16

//0x17

//0x18

//0x19

//0x20

//0x21

//0x22

//0x23

//0x24

//0x25

//0x26

//0x27

//0x28

//0x29

//0x30

//0x31

//0x32

//0x33

//0x34

//0x35

//0x36

//0x37

//0x38

//0x39

//0x40

//0x41

//0x42
*/
//0x77
//void op_ld_a_hl(CPU *cpu) {
//	cpu-> A = cpu->HL
//}

// 0x78
void op_ld_a_b(CPU *cpu) {
	cpu->A = cpu->B;
}


// 0x80
void op_add_a_b(CPU *cpu) {

// Mathmatical ops have to be done on the A register, this does not change

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


void cpu_init(CPU *cpu) {
	memset(cpu, 0, sizeof(CPU));
	cpu->A = 20;
	cpu->B = 2;
	cpu->C = 3;
	cpu->D = 0;
	cpu->E = 0;
	cpu->F = 0;
	cpu->H = 0;
	cpu->L = 0;
	cpu->PC = 0x100;
	cpu->SP = 0xFFFE;
}

void cpu_step(CPU *cpu) {

	uint8_t opcode = read8(cpu->PC); //fetch the next byte from memory
	
	switch (opcode) {
		case 0x00: op_nop(cpu); break;
		case 0x01: op_ld_bc_u16(cpu); break;
		case 0x04: op_inc_b(cpu); break;
		case 0x05: op_dec_b(cpu); break;
		case 0x77: printf("Start"); break;
		case 0x78: op_ld_a_b(cpu); break;
		case 0x80: op_add_a_b(cpu); break;

		default: printf ("Unknown opcode %02X\n", opcode); break;
	}
	cpu->PC++;
}
