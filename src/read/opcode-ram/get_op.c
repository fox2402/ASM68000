
#include "get_op.h"

void get_op(char *file, char *out) {
  if(!fork()) {
    char *arg[7] = {"exec","asmx", "-C 68000 -b 0 -o", out, "--", file, NULL};
    execvp(arg[0], arg);

  }
  wait(NULL);
  printf("Get Opcode");
}

void optoram(char *bin, struct cpu cpu) {
  char *buf = NULL;
  size_t len;
  FILE *file = fopen(bin, "r");
  int r = getline(&buf, &len, file);
  for(int i = 0; i < r; i++) {
    cpu.RAM[i] = buf[i];
  }
  free(buf);
  fclose(file);
}
