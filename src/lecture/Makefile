# Makefile
 
# CC=clang -fsanitize=address
# CC=gcc -fsanitize=address
CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -O0 -g
LDFLAGS=
LDLIBS=
SRC= test.c lecture.c main.c
OBJ=$(SRC:.c=.o)
BIN= lecture

all: $(OBJ)
	$(CC) $(CFLAGS) -o lecture $(OBJ)

check: clean all
	./lecture fichier.asm
 
clean:
	rm -f *.o $(BIN)
 
# END
