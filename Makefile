# Makefile
 
#CC=clang -fsanitize=address
#CC=gcc -fsanitize=address
CC=gcc
CPPFLAGS=
CFLAGS= -fdiagnostics-color=auto -Wall -Wextra -std=c99 
LDFLAGS=
LDLIBS=
XFILES =
EXEC = stdcpu.c
TESTS = 
all: CFLAGS+=-O3
all: $(EXEC)


alli:$(EXEC)
worker:

task_mgr:

 
clean:
	rm -f *.o
	$(RM) $(EXEC) 
check: CFLAGS+=-g3
check: alli
    
	
	
# END
