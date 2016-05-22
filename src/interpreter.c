#include<stdint.h>
#include<stdlib.h>
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

void add(uint16_t opcode)
{
  //recuperer les bits avec des bitwise, en deduire les modes d'addressage et les valeurs, faire le calcul
  char dn = 0;
  char opmode = 0;
  char eamode = 0;
  char earegister = 0;
  int i = 0;
  dn = (char)((opcode >> 9) & 0x7);
  opmode = (char)((opcode >> 6) & 0x7);
  eamode = (char)((opcode >> 3) & 0x7);
  earegister = (char)(opcode & 0x7);
  struct cpu* k = get_cpu();
  uint32_t mask = 0;
  if ((opmode == 0) || (opmode == 4))
  {
    mask = 0xFF;
  }
  else if ((opmode == 1) || (opmode == 5))
  {
    mask = 0xFFFF;
  }
  else
  {
    mask = 0xFFFFFFFF;
  }
  if (eamode == 0) //cas Dn
  {
    if((opmode == 0) || (opmode == 1) || (opmode = 2))
    {
      k->D[dn] = (k->D[dn] & !mask) || ((k->D[earegister] & mask) + (k->D[dn] & mask));
    }
    else
    {
      k->D[earegister] = (k->D[earegister] & !mask) || ((k->D[dn] & mask) + (k->D[earegister] & mask));
    }
  }
  if (eamode == 1) //cas An
  {
    if((opmode == 0) || (opmode == 1) || (opmode = 2))
    {
      k->D[dn] = (k->D[dn] & !mask) || ((k->A[earegister] & mask) + (k->D[dn] & mask));
    }
    else
    {
      k->A[earegister] = (k->A[earegister] & !mask) || ((k->D[dn] & mask) + (k->A[earegister] & mask));
    }
  }
  if (eamode == 2) //cas (An), demande bidouillage ram car en char, ferais demain
  {
    if((opmode == 0) || (opmode == 1) || (opmode = 2))
    {
      k->D[dn] = (k->D[dn] & !mask) || (ram_read(mask, k->A[earegister] & mask) + (k->D[dn] & mask));
    }
    else
    {
      ram_write(mask, k->A[earegister] & mask, ((k->D[dn] & mask) + (ram_read(mask, [k->A[earegister]]))));
    }
  }
  if (eamode == 3) //cas (An)+
  {
    if((opmode == 0) || (opmode == 1) || (opmode = 2))
    {
      k->D[dn] = (k->D[dn] & !mask) || (ram_read(mask, k->A[earegister] & mask) + (k->D[dn] & mask));
    }
    else
    {
      ram_write(mask, k->A[earegister] & mask, ((k->D[dn] & mask) + (ram_read(mask, [k->A[earegister]]))));
    }
    if (mask = 0xFF)
    {
      k->A[earegister] = k->A[earegister] + 1;
    }
    else if (mask = 0xFFFF)
    {
      k->A[earegister] = k->A[earegister] + 2;
    }
    else
    {
      k->A[earegister] = k->A[earegister] + 4;
    }
  }

  if (eamode == 3) //cas (An)+
  {
    if (mask = 0xFF)
    {
      k->A[earegister] = k->A[earegister] - 1;
    }
    else if (mask = 0xFFFF)
    {
      k->A[earegister] = k->A[earegister] - 2;
    }
    else
    {
      k->A[earegister] = k->A[earegister] - 4;
    }
    if((opmode == 0) || (opmode == 1) || (opmode = 2))
    {
      k->D[dn] = (k->D[dn] & !mask) || (ram_read(mask, k->A[earegister] & mask) + (k->D[dn] & mask));
    }
    else
    {
      ram_write(mask, k->A[earegister] & mask, ((k->D[dn] & mask) + (ram_read(mask, [k->A[earegister]]))));
    }
  }
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

