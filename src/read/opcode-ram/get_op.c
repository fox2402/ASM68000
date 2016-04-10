
#include "get_op.h"

void get_op(char *file, char *out) {
  if(!fork()) {
    char *arg[11] = {"asmx", "-C", "68000", "-b", "0", "-o", out, "--", file, NULL};
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
  while ((r = getline(&buf, &len, file)) != -1) {
    for(int i = 0; i < r; i++) {
      cpu->RAM[j] = buf[i];
      j++;
    }
  }
  free(buf);
  fclose(file);
}
