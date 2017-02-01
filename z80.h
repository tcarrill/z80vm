#ifndef Z80_H
#define Z80_H

#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 65536
#define NOP 0x00
#define LD_A_N 0x3E
#define LD_B_N 0x06
#define INC_B 0x04
#define DEC_B 0x05
#define LD_A_B 0x78
#define ADD_A_B 0x80
#define SUB_B 0x90
#define LD_NN_A 0x32
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

typedef struct {
	unsigned short ix;
	unsigned short iy;
	unsigned short sp;
	unsigned short pc;
	unsigned char r[8];
	unsigned char memory[MEM_SIZE];
} VM; 

extern VM vm;

void init_vm();
unsigned char fetch();
void execute(unsigned char instr);
void print_registers();

#endif
