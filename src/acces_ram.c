#include "acces_ram.h"

uint32_t ram_read(uint32_t mask, int add)
{
  struct cpu* k = get_cpu();
  int i =0;
  uint32_t ret = 0;
  while (i < 3)
  {
    ret = (uint32_t)(k->RAM[add]);
    if (i != 2)
    {
      ret = (ret << 8);
      add++;
    }
    i++;
  }
  return (ret & mask);
}

void ram_write(uint32_t mask, int add, uint32_t new)
{
  struct cpu* k = get_cpu();
  int i =0;
  uint32_t ret = (ram_read(!mask, add) || (new & mask));
  while (i <= 3)
  {
    k->RAM[add] = (char)ret;
    if (i != 3)
    {
      ret = (ret >> 8);
      add++;
    }
    i++;
  }
}
