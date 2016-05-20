#include <unistd.h>

#include "reg_select.h"
#include "stdcpu.h"

uint32_t* selectReg(uint16_t input, int sel)
{
  if (sel)
  {
    struct cpu* c = get_cpu();
    return c->A + input;
  } 
  else
  {
    struct cpu* c = get_cpu();
    return c->D + input;
  }
}


uint32_t* selectMod(uint16_t input)
{
  struct cpu* c;
  uint32_t* reg;
  uint32_t* rt;
  //here it's MODE - REG use the selectModRE for REG - MODE
  switch(input>>3)
  {
    case(0):
      //Dn
      return (selectReg(input & 0xFFF8, 0));
    case(1):
      return (selectReg(input & 0xFFF8, 1));
      //An
    case(2):
      c = get_cpu();
      reg = selectReg(input & 0xFFF8, 1);
      return (uint32_t*)(c->RAM[*reg]);
      //(An)
    case(3):
      c = get_cpu();
      reg = selectReg(input & 0xFFF8, 1);
      rt = (uint32_t*)(c->RAM[*reg]);
      *reg++;
      return rt;
      //An+
    case(4):
      c = get_cpu();
      reg = selectReg(input & 0xFFF8, 1);
      *reg--;
      return (uint32_t*)(c->RAM[*reg]);
      //-An
    case(5):
      //d16,An,Xi
      return 0;
    case(6):
      //d8,An,Xi
      return 0;
    case(7):
      return 0;
     //#data
  }  
  return 0;
}
uint32_t* slectModRE(uint16_t input)
{
  struct cpu* c;
  uint32_t* reg;
  uint32_t* rt;
  //here it's REG - MODE use the selectMod for MOD - REG
  switch(input & 0xFFF8)
  {
    case(0):
      return(selectReg(input>>3, 0));
    case(1):
      return(selectReg(input>>3, 1));
    case(2):
      c = get_cpu();
      reg = selectReg(input>>3, 1);
      return (uint32_t*)(c->RAM[*reg]);
    case(3):
      c = get_cpu();
      reg = selectReg(input>>3, 1);
      rt = (uint32_t*)(c->RAM[*reg]);
      *reg++;
      return rt;
    case(4):
      c = get_cpu();
      reg = selectReg(input>>3, 1);
      *reg--;
      return(uint32_t*)(c->RAM[*reg]);   
  }
  return 0;
}
