# ifndef EPITA_IP_SHARED_QUEUE_H_
# define EPITA_IP_SHARED_QUEUE_H_

# include <stdint.h>
# include <unistd.h>

struct cpu
{
  char* RAM;
  uint32_t* An; //32 bits adress reg, it is unisigned
  uint32_t* Dn;
  char CCR;
  uint32_t pc;

}



struct cpu* get_cpu(void);


void delete_core(struct cpu* c);
