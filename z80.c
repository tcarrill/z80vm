#include "z80.h"

VM vm;

void init_vm() {
	vm.pc = 0;
	vm.sp = 0;
	for (int i = 0; i < MEM_SIZE; i++) {
		vm.memory[i] = 0;
	}
	for (int i = 0; i < 8; i ++) {
		vm.r[i] = 0;
	}
}

unsigned char fetch() {
	if (vm.pc == MEM_SIZE) {
		vm.pc = 0;
	}
	return vm.memory[vm.pc++];
}

void add(unsigned char value) {
	vm.r[A] += value;
}

void sub(unsigned char value) {
	vm.r[A] -= value;
}

void and(unsigned char value) {
	vm.r[A] &= value;
}

void or(unsigned char value) {
	vm.r[A] |= value;
}

void xor(unsigned char value) {
	vm.r[A] ^= value;
}

void load_memory(unsigned char value) {
	unsigned short address = (fetch() << 8) | fetch();
	vm.memory[address] = value;
}

void execute(unsigned char instr) {
	switch(instr) {
		case LD_A_N:
			vm.r[A] = fetch();
			break;
		case LD_B_N: 
			vm.r[B] = fetch(); 
			break;
		case INC_B: 
			vm.r[B] += 1; 
			break;
		case DEC_B: 
			vm.r[B] -= 1; 
			break;
		case LD_A_B: 
			vm.r[A] = vm.r[B]; 
			break;
		case ADD_A_B: 
			add(vm.r[B]); 
			break;
		case SUB_B: 
			sub(vm.r[B]); 
			break;
		case AND_B: 
			and(vm.r[B]); 
			break;
		case OR_B: 
			or(vm.r[B]); 
			break;
		case XOR_B: 
			xor(vm.r[B]); 
			break;
		case LD_NN_A:
			load_memory(vm.r[A]);
			break; 
	}
}

void readBinary(char *const filename) {
    	FILE *fp = fopen(filename, "r");
    
	int nread;
	unsigned char *program = vm.memory;   
    	do {
       	 	nread = fread(program, 1, 1, fp);
        	program++;
    	} while (nread > 0);

	fclose(fp);
}

void print_registers() {
	printf("\nRegisters\n");
	char reg = 'A';
	for (int i = 0; i < 8; i++) {
		if (i == 6) {
			reg = 'H';
		} else if (i == 7) {
			reg = 'L';
		}
		printf("%c: %d\t", reg, vm.r[i]);
		reg++;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	init_vm();
	readBinary(argv[1]);
	vm.pc = 0;
	printf("Address  Opcode\n");	
	int running = 1;
	while(running) {
		unsigned char instr = fetch();
		printf("%05x    %02x\n", vm.pc - 1, instr);
		if (instr == HALT) {
			running = 0;
		} else {				
			execute(instr);
		}	
	}
	print_registers();
	printf("Result in memory: %i\n", vm.memory[65535]);

	return 0;
}
