#include <stdio.h>
#include "cpu.h"
#include "memory.h"


int main() {
	CPU cpu;
	cpu_init(&cpu); //Game Boy starts exec here
	memory_init();
	
	for (int i = 0; i < 5; i++) {
		printf("PC = %04X\n", cpu.PC);
		cpu_step(&cpu);
	}

	return 0;
}
