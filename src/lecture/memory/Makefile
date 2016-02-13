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
BIN= mem

all: $(OBJ)
	$(CC) $(CFLAGS) -o mem $(OBJ)

check: clean all
	./mem
 
clean:
	rm -f *.o $(BIN)
 
# END
