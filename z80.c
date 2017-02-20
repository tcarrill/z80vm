#include "z80.h"

VM *init_vm() {
	VM *vm = (VM *)malloc(sizeof(VM));
	if (vm == NULL) {
		return NULL;
	}
	vm->pc = 0;
	vm->sp = 0;

	for (int i = 0; i < MEM_SIZE; i++) {
		vm->memory[i] = 0;
	}

	for (int i = 0; i < 8; i ++) {
		vm->r[i] = 0;
	}

	return vm;
}

void free_vm(VM *vm) {
	free(vm);
}

unsigned char fetch(VM *vm) {
	if (vm->pc == MEM_SIZE - 1) {
		vm->pc = 0;
	}
	return vm->memory[vm->pc++];
}

void add(VM *vm, unsigned char value) {
	vm->r[A] += value;
}

void sub(VM *vm, unsigned char value) {
	vm->r[A] -= value;
}

void and(VM *vm, unsigned char value) {
	vm->r[A] &= value;
}

void or(VM *vm, unsigned char value) {
	vm->r[A] |= value;
}

void xor(VM *vm, unsigned char value) {
	vm->r[A] ^= value;
}

void load_register(VM *vm, unsigned short dest, unsigned short source) {
	vm->r[dest] = vm->r[source];
}

void load_memory(VM *vm, unsigned char value) {
	unsigned short address = (fetch(vm) << 8) | fetch(vm);
	vm->memory[address] = value;
}

void execute(VM *vm, unsigned char instr) {
	switch(instr) {
		case LD_A_N:
			vm->r[A] = fetch(vm);
			break;
		case LD_B_N: 
			vm->r[B] = fetch(vm); 
			break;
		case LD_C_N:
			vm->r[C] = fetch(vm);
			break;
		case LD_D_N:
			vm->r[D] = fetch(vm);
			break;
		case LD_E_N:
			vm->r[E] = fetch(vm);
			break;
		case LD_H_N:
			vm->r[H] = fetch(vm);
			break;
		case LD_L_N:
			vm->r[L] = fetch(vm);
			break;
		case INC_A:
			vm->r[A] += 1;
			break;
		case DEC_A:
			vm->r[A] -= 1;
			break;
		case INC_B: 
			vm->r[B] += 1; 
			break;
		case DEC_B: 
			vm->r[B] -= 1; 
			break;
		case INC_C:
			vm->r[C] += 1;
			break;
		case DEC_C:
			vm->r[C] -= 1;
			break;
		case INC_D:
			vm->r[D] += 1;
			break;
		case DEC_D:
			vm->r[D] -= 1;
			break;
		case INC_E:
			vm->r[E] += 1;
			break;
		case DEC_E:
			vm->r[E] -= 1;
			break;
		case INC_H:
			vm->r[H] += 1;
			break;
		case DEC_H:
			vm->r[H] -= 1;
			break;
		case INC_L:
			vm->r[L] += 1;
			break;
		case DEC_L:
			vm->r[L] -= 1;
			break;
		case LD_A_A:
			break;
		case LD_A_B: 
			load_register(vm, A, B);
			break;
		case LD_A_C:
			vm->r[A] = vm->r[C];
			break;
		case LD_A_D:
			vm->r[A] = vm->r[D];
			break;
		case LD_A_E:
			vm->r[A] = vm->r[E];
			break;
		case LD_A_H:
			vm->r[A] = vm->r[H];
			break;
		case LD_A_L:
			vm->r[A] = vm->r[L];
			break;
		case ADD_A_B: 
			add(vm, vm->r[B]); 
			break;
		case SUB_B: 
			sub(vm, vm->r[B]); 
			break;
		case AND_B: 
			and(vm, vm->r[B]); 
			break;
		case OR_B: 
			or(vm, vm->r[B]); 
			break;
		case XOR_B: 
			xor(vm, vm->r[B]); 
			break;
		case LD_NN_A:
			load_memory(vm, vm->r[A]);
			break;
		case LD_BC_NN:
			vm->r[C] = fetch(vm);
			vm->r[B] = fetch(vm);
			break;
		case LD_DE_NN:
			vm->r[E] = fetch(vm);
			vm->r[D] = fetch(vm);
			break;
		case LD_HL_NN:
			vm->r[L] = fetch(vm);
			vm->r[H] = fetch(vm);
			break;
	}
}

void print_registers(VM *vm) {
	printf("\nRegisters\n");
	printf("A    BC    DE    HL    IX    IY    SP\n");
	printf("%02x  %02x%02x  %02x%02x  %02x%02x  %04x  %04x  %04x\n", vm->r[A], vm->r[B], vm->r[C], vm->r[D], vm->r[E], vm->r[H], vm->r[L], vm->ix, vm->iy, vm->sp);
}

int run(VM *vm) {
	int running = 1;
	while(running) {
		unsigned char instr = fetch(vm);
		if (instr == HALT) {
			running = 0;
		} else {
			execute(vm, instr);
		}
	}
	return 0;
}
