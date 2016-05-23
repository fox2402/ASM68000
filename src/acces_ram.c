#include "acces_ram.h"

uint32_t ram_read(uint32_t mask, uint32_t add)
{
  struct cpu* k = get_cpu();
  int i = 0;
  uint32_t ret = 0;
  int n;
  switch(mask) {
    case 0xFF000000:
      n = 8*3;
      break;
    case 0xFFFF0000:
      n = 8*2;
      break;
    default:
      n = 0;
      break;
  }
  while (i < 4)
  {
    ret = (uint32_t)((k->RAM[add+i]) & 0xFF) | ret;
    if (i != 3)
    {
      ret = (ret << 8);
    }
    i++;
  }
  return (ret & mask) >> n;
}

void ram_write(uint32_t mask, uint32_t add, uint32_t new)
{
  struct cpu* k = get_cpu();
  int i = 0;
  int n;
  switch(mask) {
    case 0xff000000:
      n = 8*3;
      break;
    case 0xffff0000:
      n = 8*2;
      break;
    default:
      n = 0;
      break;
  }
  uint32_t ret = (ram_read(~mask, add) | (new <<= n));
  while (i <= 3)
  {
    k->RAM[add+3-i] = (char)ret;
    if (i != 3)
    {
      ret >>= 8;
    }
    i++;
  }
}
