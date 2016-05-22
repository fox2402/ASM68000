# Makefile
 
# CC=clang -fsanitize=address
# CC=gcc -fsanitize=address
CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -O0 -g
LDFLAGS=
LDLIBS=
SRC= move.c 
OBJ= ../stdcpu.o ../read/memory/mem.o
BIN=

all: $(OBJ)
	$(CC) $(CFLAGS) -o move $(OBJ)

check: clean all
 
clean:
	rm -f *.o $(BIN)
 
# END
