# Makefile
 
# CC=clang -fsanitize=address
# CC=gcc -fsanitize=address
CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -O0 -g -lm
LDFLAGS=
LDLIBS=
SRC= test.c read.c main.c
OBJ=$(SRC:.c=.o)
OBJ2= memory/mem.o basic/basic.o ../stdcpu.o opcode-ram/get_op.o
BIN= read ../../read

all: $(OBJ) $(OBJ2)
	$(CC) $(CFLAGS) -o read $(OBJ) $(OBJ2)
	cp read ../../

check: clean all
	./read file.asm
 
clean:
	rm -f *.o $(BIN) $(OBJ2)
 
# END
