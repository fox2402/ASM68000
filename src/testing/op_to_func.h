# include <stdlib.h>
# include <stdint.h>

# include "stdcpu.h"

# ifndef OP_TO_FUNC_H
# define OP_TO_FUNC_H


struct pandora
{
  uint32_t mask;
  uint32_t* src;
  uint32_t* dst
}

uint32_t* regSelect(int slew, uint32_t n)
{
  struct cpu* p = get_cpu()
  switch(n)
  {
    case(0):
      return slew ? cpu->D : cpu->A;
    case(1):
      return slew ? cpu->D + 1 : cpu->A + 1;
    case(2)
      return slew ? cpu->D + 2 : cpu->A + 2;
    case(3): 
      return slew ? cpu->D + 3 : cpu->A + 3;
    case(4):
      return slew ? cpu->D + 4 : cpu->A + 4;
    case(5):
      return slew ? cpu->D + 5 : cpu->A + 5;
    case(6):
      return slew ? cpu->D + 6 : cpu->A + 6;
    case(7):
      return slew ? cpu->D + 7 : cpu->A + 7;
  
  } 


}


# endif
