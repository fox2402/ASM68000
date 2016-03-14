# ifndef HEAD_H
# define HEAD_H

# define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <err.h>
# include <stdint.h>
# include "basic/basic.h"
# include "memory/mem.h"
# include "../stdcpu.h"

struct label {
  char *subroutine;
  uint32_t adress;
  struct label *next;
};

char **arg_init();
void arg_free(char **arg);
ssize_t read_line(FILE *file, char **arg);

# endif
