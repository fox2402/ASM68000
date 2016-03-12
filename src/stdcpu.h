# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

# ifndef STDCPU_H
# define STDCPU_H

struct cpu {
  char* RAM;
  uint32_t* An; //32 bits adress reg, it is unisigned
  uint32_t* Dn;
  char CCR;
  uint32_t pc;
};


struct cpu* get_cpu(void);
void delete_core(struct cpu* c);

# endif
