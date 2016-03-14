# Makefile
 
# CC=clang -fsanitize=address
# CC=gcc -fsanitize=address
CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -O0 -g
LDFLAGS=
LDLIBS=
SRC= mem.c
OBJ=$(SRC:.c=.o)
OBJ2= ../../stdcpu.o
BIN= mem

all: $(OBJ) $(OBJ2)
	$(CC) $(CFLAGS) -o mem $(OBJ) $(OBJ2)

check: clean all
	./mem
 
clean:
	rm -f *.o $(BIN)
 
# END
