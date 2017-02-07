z80vm: main.c z80.c
	gcc -o z80 main.c z80.c

test: test.c z80.c
	gcc -o test test.c z80.c
