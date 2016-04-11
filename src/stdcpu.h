# include <stdlib.h>
# include <stdint.h>

# ifndef STDCPU_H
# define STDCPU_H

struct cpu {
  char RAM[16384]; // 16 mio de memoire ? ;
  uint32_t A[9]; //don't use after bit 23
  uint32_t D[8];
  uint16_t SR; // 8 lower = CCR 8 higher = SR
  uint32_t PC;
};


struct cpu* get_cpu(void);
void delete_core(struct cpu* c);

# endif
