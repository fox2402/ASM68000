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
BIN= read

all: $(OBJ)
	$(CC) $(CFLAGS) -o read $(OBJ)

check: clean all
	./read fichier.asm
 
clean:
	rm -f *.o $(BIN)
 
# END
