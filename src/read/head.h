# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <err.h>
# include "basic/basic.h"
# include "memory/mem.h"
# include "../stdcpu.h"

char **arg_init();
void arg_free(char **arg);
ssize_t read_line(FILE *file, char **arg);
