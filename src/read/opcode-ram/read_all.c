#include "read_all.h"
#include "../../acces_ram.h"
#include "../../interpreter.h"
void read_all() {
  struct cpu *cpu = get_cpu();
  int j = 0;
  uint32_t i;
  printf("\nSTART\n");
  //ram_write(0xffff0000,0x504,0x64);
  while(ram_read(0xFFFF0000, cpu->PC) != 0x4afc /*&& ram_read(0xFFFFFFFF, i) != 0*/){
   // if(ram_read(0xFFFFFFFF, i) != 0) {
      i = cpu->PC;
      j = cpu->RAM[i];
      j >>= 4;
      j &= 0xF;
      if(j <= 3 && j >= 1) {
	printf("move\n");
	//move(ram_read(0xFFFF0000, i));
	printf("%04x\n", ram_read(0xFFFF0000, i));
      }
      if (j == 13) {
	printf("add\n");
	add(ram_read(0xFFFF0000, i));
        printf("%04x\n", ram_read(0xFFFF0000, i));
      } else {
        printf("%04x\n", ram_read(0xFFFF0000, i));
	cpu->PC += 2;
      }
   // }
   // i += 2;
  }
  printf("Illegal\n");
  printf("%04x\n", ram_read(0xFFFF0000, i));
  printf("END\n");
  cpu->PC = i;
  DUMPMEM(cpu->RAM, 1000*sizeof(uint16_t));
  printf("D0 = %d |D1 = %d |D2 = %d\n", cpu->D[0], cpu->D[1], cpu->D[2]);
  printf("A0 = 0x%x |A1 = 0x%x |A2 = 0x%x\n", cpu->A[0], cpu->A[1], cpu->A[2]);
}
