# Makefile
 
# CC=clang -fsanitize=address
# CC=gcc -fsanitize=address
CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -O0 -g
LDFLAGS=
LDLIBS=
SRC= 
OBJ=$(SRC:.c=.o)
BIN=
DIRS=  src/asmx src/read 
DIRS2= src src/read src/read/basic src/read/memory src/asmx
all:
	-for d in $(DIRS); do (cd $$d; $(MAKE)); done
#	$(MAkE) -C

check: clean all
	./read file.asm 
clean:
	-for d in $(DIRS2); do (echo "\nClean :" $$d; cd $$d; $(MAKE) clean ); done
	rm -f out.bin asmx
# END
