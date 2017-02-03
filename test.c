#include "z80.h"

void load_program(long length, unsigned char *program, VM *vm) {
	int program_origin = 0;
	vm->pc = program_origin;
	for(int i = 0; i < length; i++, program_origin++) {
		vm->memory[program_origin] = program[i];
	}
}

int test(int expected, int actual) {
	int success = 0;
	if (expected != actual) {
		printf("  -FAIL: Got %d, expected %d\n", actual, expected);
		success = 0;
	} else {	
		printf("  +PASS\n");
		success = 1;
	}
	return success;
}

int testAdd() {
	printf("testAdd()\n");
	VM *vm = init_vm();
	vm->memory[0] = LD_A_N;
	vm->memory[1] = 1;
	vm->memory[2] = LD_B_N;
	vm->memory[3] = 1;
	vm->memory[4] = ADD_A_B;
	vm->memory[5] = HALT;
	run(vm);
	
	int expected = 2;
	int actual = vm->r[A];
	int success = test(expected, actual);
	free_vm(vm);
	return success;
}

int testSub() {
	printf("testSub()\n");
	VM *vm = init_vm();
	vm->memory[0] = LD_A_N;
	vm->memory[1] = 5;
	vm->memory[2] = LD_B_N;
	vm->memory[3] = 3;
	vm->memory[4] = SUB_B;
	vm->memory[5] = HALT;
	run(vm);
	
	int expected = 2;
	int actual = vm->r[A];
	int success = test(expected, actual);
	free_vm(vm);
	return success;
}

int main(int argc, char *argv[]) {
	testAdd();
	testSub();
	return 0;		
}
