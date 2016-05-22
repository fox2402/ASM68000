
#include "get_op.h"

void get_op(char *file, char *out) {
  if(!fork()) {
    char *arg[11] = {"./asmx", "-C", "68000", "-b", "0", "-o", out, "--", file, NULL};
    execvp(arg[0], arg);
    exit(1);
    return;
  }
  wait(NULL);
  printf("Get Opcode\n");
}

void optoram(char *bin, struct cpu *cpu) {
  char *buf = NULL;
  size_t len = 0;
  FILE *file = fopen(bin, "r");
  int j = 0;
  ssize_t r;
  int b = 1;
  while ((r = getline(&buf, &len, file)) != -1) {
    for(int i=0; b; i+=2) {
      for(int k = 0; k < 2; k++) {
	if ((unsigned)(unsigned char)buf[i+k] != 255) {
	  b = 0;
	}
      }
      if (b) {
        j += 2;
      }
    }
    cpu->PC = j;
    for(; j < r; j++) {
      cpu->RAM[j] = buf[j];
    }
  }
  free(buf);
  fclose(file);
}
