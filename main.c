#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cpu.h"
#include "memory.h"


int main(int argc, char *argv[]) {
	char* rom_name = argv[1];
	CPU cpu;
	cpu_init(&cpu); //Game Boy starts exec here
	memory_init();
//	load_rom();
	 
	for (int i = 0; i < 5; i++) {
		printf("PC = %04X\n", cpu.PC);
		cpu_step(&cpu);
	}

	return 0;
}

bool load_rom(const char *rom_name) {
	FILE *rom = fopen(rom_name, "rb");
	if (!rom) return false;

	fseek(rom, 0, SEEK_END);
	size_t rom_size = ftell(rom);
	fseek(rom, 0, SEEK_SET);

	fread(rom_bank0, 1, rom_size < 0x4000 ? rom_size : 0x4000, rom);

	fclose(rom);
	return true;
}
