#include "read_all.h"

void read_all() {
  struct cpu *cpu = get_cpu();
  uint32_t i = cpu->PC;
  int j = 0;
  printf("START\n");
  while((uint16_t) cpu->RAM[i] != 0x4afc && (uint64_t) cpu->RAM[i] != 0){
    if((uint64_t) cpu->RAM[i] != 0) {
      //exec()
      j = cpu->RAM[i];
      j >>= 4;
      j &= 15;
      if(j <= 3 && j >= 1) {
	//i += move();
	printf("move\n");
	uint16_t test = (uint16_t) cpu->RAM[i] & 0xFFFF;
	printf("%x\n", test);
      } else {
        printf("%04x\n",(uint16_t)cpu->RAM[i]);
      }
    }
    i += 2;
  }
  printf("END\n");
  cpu->PC = i;
}
