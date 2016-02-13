# Makefile
 
# CC=clang -fsanitize=address
# CC=gcc -fsanitize=address
CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Werror -Wextra -std=c99 -O0 -g
LDFLAGS=
LDLIBS=
SRC= basic.c
OBJ=$(SRC:.c=.o)
BIN= basic

all: $(OBJ)
	$(CC) $(CFLAGS) -o basic $(OBJ)

check: clean all
	./basic
 
clean:
	rm -f *.o $(BIN)
 
# END
