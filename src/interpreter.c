#include<stdin.h>
#include<stdcpu.h>

/*void ccr(uint32_t mask, uint32_t* src, uint32_t* dst, uint32_t rslt)
{
 struct cpu* k = get_cpu();
 int i =0;
 uint32_t src2 = *src;
 uint32_t dst2 = *dst;
 if (!rslt)
 {
   //z a 1
 }
 else
 {
   //z a 0
 }
 while (mask !=0)
 {
   i++
   mask = mask >> 1; // exemple : cas du 16 bits i = 16
 }
 if (i < 32)
 {
    while (i >0)
    {
      src2 = src2 >> 1;
      dst2 = dst2 >> 1; //dst2, src2 et rslt = bit de poid fort
      rslt = rslt >> 1;
      i--
    }
    //n = rslt
    if (src2 == dst2 && rslt != dst2)
    {
      //v a 1
    }
    else
    {
      //v a 0
    }
    //cas de c
    rslt = rslt >>1;
    //c = rslt
    //x = c

 }
}*/

void move(uint32_t mask, uint32_t* src, uint32_t* dst)
{
  uint32_t dst2 = *src & mask;
  mask = !mask;
  *dst = mask & *dst;
  *dst = *dst | dst2;
}

void add(uint32_t mask, uint32_t* src, uint32_t* dst)
{
  //struct cpu* k = get_cpu();
  //int i =0;
  //uint32_t src3 = *src;
  //uint32_t dst3 = *dst;
  uint32_t src2 = src & mask;
  uint32_t dst2 = dst & mask;
  dst2 = dst2+src2;
  mask = !mask;
  *dst = mask & *dst;
  *dst = *dst | dst2;
  /*if (!dst2)
  {
    //z a 1
  }
  else
  {
    //z a 0
  }
  while (mask != 0)
  {
    i++;
    mask = mask >>1;
  }
  if(i < 32)
  {
    while(i>0)
    {
      src3 = src3>>1;
      dst3 = dst3>>1;
      dst2 = dst2>>1;
    }
    //n = rslt
    if(src3 == dst3 && dst2 != dst3)
    {
      //v a 1
    }
    else
    {
    }
  }*/
}

void sub(uint32_t mask, uint32_t* src, uint32_t* dst)
{
  uint32_t src2 = src & mask;
  uint32_t dst2 = dst & mask;
  dst2 = dst2-src2;
  mask = !mask;
  *dst = mask & *dst;
  *dst = *dst | dst2;
}

void jsr(uint32_t addr)
{
  struct cpu* k = get_cpu();
  //k->RAM[k->A[7]] = k->PC +2;
  int i =0;
  uint32_t pq = k->PC
  while (i <4)
  {
    k->A[7] = k ->A[7] -1;
    k->RAM[k->A[7]] = (char)pq;
    pq = pq >> 8;
    i++;
  }
  k->PC = k->PC +2;
  k->PC = addr;
}

void rts()
{
  struct cpu* k = get_cpu();
  int i =0;
  uint32_t tmp = 0;
  while (i < 4)
  {
    tmp = tmp || k->RAM[k->A[7]];
    tmp = tmp << 8;
    k->A[7] = k->A[7]+ 1;
    i++;
  }
  k->PC = tmp;
}

void beq(uint32_t addr)
{
  struct cpu* k = get_cpu();
  uint32_t z = (k->SR >> 2) & 1;
  if(z)
  {
    k->PC = addr;
  }
}

void bne(uint32_t addr)
{
  uint32_t z = (k->SR >>2) & 1;
  if (!z)
  {
    k->PC = addr;
  }
}

