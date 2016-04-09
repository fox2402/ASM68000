# define _GNU_SOURCE
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

# ifndef GET_OP_H
# define GET_OP_H

#include "../head.h"
void get_op(char *file, char *out);
void optoram(char *bin, struct cpu cpu);

#endif
