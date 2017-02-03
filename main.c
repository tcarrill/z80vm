#include "z80.h"

long readBinary(unsigned char **buffer, char *const filename) {
	FILE *fileptr = fopen(filename, "rb");

	fseek(fileptr, 0, SEEK_END);
	long filelen = ftell(fileptr);
	rewind(fileptr);
	*buffer = (unsigned char*)malloc((filelen + 1) * sizeof(char)); 
	fread(*buffer, filelen, 1, fileptr); 
	fclose(fileptr); 
	
	return filelen; 
}

void load_program(long length, unsigned char *program, VM *vm) {
	int program_origin = 0;
	vm->pc = program_origin;
	for(int i = 0; i < length; i++, program_origin++) {
		vm->memory[program_origin] = program[i];
	}
}

int main(int argc, char *argv[]) {
	VM *vm = init_vm();
	unsigned char *program = NULL;
	long length = readBinary(&program, argv[1]);
	load_program(length, program, vm);
	
	printf("Address  Opcode\n");
	int running = 1;
	while(running) {
		unsigned char instr = fetch(vm);
		printf("%05x    %02x\n", vm->pc - 1, instr);
		if (instr == HALT) {
			running = 0;
		} else {
			execute(vm, instr);
		}
	}
	print_registers(vm);
	free_vm(vm);
	return 0;		
}
