# Makefile
 
# CC=clang -fsanitize=address
# CC=gcc -fsanitize=address
CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -O0 -g
LDFLAGS=
LDLIBS=
SRC= stdcpu.c 
OBJ=$(SRC:.c=.o) acces_ram.o interpreter.o
BIN=

all: $(OBJ)

check: clean all
 
clean:
	rm -f *.o $(BIN)
 
# END
