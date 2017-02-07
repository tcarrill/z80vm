CC = gcc
CFLAGS = -Wall -I.
OBJ = main.o z80.o 

z80: main.c z80.c
	$(CC) -o $@ $^ $(CFLAGS)

test: test.c z80.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f z80 test *.o
