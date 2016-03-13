# Makefile
 
# CC=clang -fsanitize=address
# CC=gcc -fsanitize=address
CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -O0 -g
LDFLAGS=
LDLIBS=
SRC= test.c read.c main.c
OBJ=$(SRC:.c=.o)
OBJ2= memory/mem.o basic/basic.o ../stdcpu.o
BIN= read ../../read

all: $(OBJ) $(OBJ2)
	$(CC) $(CFLAGS) -o read $(OBJ) $(OBJ2)
	cp read ../../

check: clean all
	./read fichier.asm
 
clean:
	rm -f *.o $(BIN)
 
# END
