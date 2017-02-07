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

int testLoad() {
	printf("testLoad()\n");
	VM *vm = init_vm();
	vm->memory[0] = LD_A_N;
	vm->memory[1] = 5;
	vm->memory[2] = HALT;
	run(vm);
	printf("  LD_A_N:");
	int success = test(5, vm->r[A]);
	
	vm->memory[0] = LD_B_N;
	vm->memory[1] = 5;
	vm->memory[2] = HALT;
	run(vm);
	printf("  LD_B_N:");
	success = test(5, vm->r[B]);

	vm->memory[0] = LD_C_N;
	vm->memory[1] = 5;
	vm->memory[2] = HALT;
	run(vm);
	printf("  LD_C_N:");
	success = test(5, vm->r[C]);

	vm->memory[0] = LD_D_N;
	vm->memory[1] = 5;
	vm->memory[2] = HALT;
	run(vm);
	printf("  LD_D_N:");
	success = test(5, vm->r[D]);

	vm->memory[0] = LD_E_N;
	vm->memory[1] = 5;
	vm->memory[2] = HALT;
	run(vm);
	printf("  LD_E_N:");
	success = test(5, vm->r[E]);

	vm->memory[0] = LD_H_N;
	vm->memory[1] = 5;
	vm->memory[2] = HALT;
	run(vm);
	printf("  LD_H_N:");
	success = test(5, vm->r[H]);

	vm->memory[0] = LD_L_N;
	vm->memory[1] = 5;
	vm->memory[2] = HALT;
	run(vm);
	printf("  LD_L_N:");
	success = test(5, vm->r[L]);

	free_vm(vm);
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
	testLoad();
	testAdd();
	testSub();
	return 0;		
}
