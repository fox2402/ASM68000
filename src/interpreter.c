#include<stdin.h>

void move(uint32_t mask, uint32_t src, uint32_t dst)
{
  uint32_t src2 = src & mask;
  uint32_t dst2 = dst & mask;
  dst2 = src2;
  mask = !mask;
  dst = mask & dst;
  dst = dst | dst2;
}

void add(uint32_t, uint32_t src, uint32_t dst)
{
  uint32_t src2 = src & mask;
  uint32_t dst2 = dst & mask;
  dst2 = dst2+src2;
  mask = !mask;
  dst = mask & dst;
  dst = dst | dst2;
}

void jsr(uint32_t addr)
{
  A[7] = A[7] -4;
  RAM[A[7]] = PC +2;
  PC = addr;
}

void rts()
{
  PC = RAM[A[7]];
  A[7] = A[7] +4;
}


