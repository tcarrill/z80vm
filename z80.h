#ifndef Z80_H
#define Z80_H

#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 65536

#define NOP 0x00
#define LD_BC_NN 0x01
#define LD_DE_NN 0x11
#define LD_HL_NN 0x21
#define LD_SP_NN 0x31

//Load register operations
#define LD_A_N 0x3E
#define LD_B_N 0x06
#define LD_C_N 0x0E
#define LD_D_N 0x16
#define LD_E_N 0x1E
#define LD_H_N 0x26
#define LD_L_N 0x2E

#define LD_A_A 0x7F
#define LD_A_B 0x78
#define LD_A_C 0x79
#define LD_A_D 0x7A
#define LD_A_E 0x7B
#define LD_A_H 0x7C
#define LD_A_L 0x7D

#define LD_B_A 0x47
#define LD_B_B 0x40
#define LD_B_C 0x41
#define LD_B_D 0x42
#define LD_B_E 0x43
#define LD_B_H 0x44
#define LD_B_L 0x45

#define LD_C_A 0x4F
#define LD_C_B 0x48
#define LD_C_C 0x49
#define LD_C_D 0x4A
#define LD_C_E 0x4B
#define LD_C_H 0x4C
#define LD_C_L 0x4D

#define LD_D_A 0x57
#define LD_D_B 0x50
#define LD_D_C 0x51
#define LD_D_D 0x52
#define LD_D_E 0x53
#define LD_D_H 0x54
#define LD_D_L 0x55

#define LD_E_A 0x5F
#define LD_E_B 0x58
#define LD_E_C 0x59
#define LD_E_D 0x5A
#define LD_E_E 0x5B
#define LD_E_H 0x5C
#define LD_E_L 0x5D

#define LD_H_A 0x67
#define LD_H_B 0x60
#define LD_H_C 0x61
#define LD_H_D 0x62
#define LD_H_E 0x63
#define LD_H_H 0x64
#define LD_H_L 0x65

#define LD_L_A 0x6F
#define LD_L_B 0x68
#define LD_L_C 0x69
#define LD_L_D 0x6A
#define LD_L_E 0x6B
#define LD_L_H 0x6C
#define LD_L_L 0x6D

#define LD_NN_A 0x32

#define LD_MM_HL 0x22

#define INC_A 0x3C
#define DEC_A 0x3D
#define INC_B 0x04
#define DEC_B 0x05
#define INC_C 0x0C
#define DEC_C 0x0D
#define INC_D 0x14
#define DEC_D 0x15
#define INC_E 0x1C
#define DEC_E 0x1D
#define INC_H 0x24
#define DEC_H 0x25
#define INC_L 0x2C
#define DEC_L 0x2D

#define ADD_A_B 0x80
#define SUB_B 0x90
#define AND_B 0xA0
#define OR_B 0xB0
#define XOR_B 0xA8
#define HALT 0x76

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define H 6
#define L 7

typedef struct VM {
	unsigned short ix;
	unsigned short iy;
	unsigned short sp;
	unsigned short pc;
	unsigned char r[8];
	unsigned char memory[MEM_SIZE];
} VM; 

VM *init_vm();
unsigned char fetch(VM *vm);
void execute(VM *vm, unsigned char instr);
int run(VM *vm);
void print_registers(VM *vm);
void free_vm(VM *vm);

#endif
