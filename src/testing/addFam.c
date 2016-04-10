#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "stdcpu.h"
#include "op_to_func.h"

static struct pandora* getBox()
{
  struct pandora* box = NULL;
  if(box == NULL)
  {
    box = malloc(sizeof(struct pandora));  
  }
  return box;

}
void closeTheBox(struct pandora* box)
{
  free(box)
}

void addF(uint16_t input)
{
  uint32_t op = 0;
  struct pandora* box = getBox()
  uint16_t tmp = input;
  switch(tmp & 0x01C0)
  {
    //ADDA
    case(0x0060):
      break;
    case(0x00E0):
      break;
    //ADD 
    case(0x0000):
      box->mask = 0xFFFFFF00;
      box->src = regSelect(1,tmp & 0x0E00);
      box->dst = modSelect(input,1, &op);
      //add(box->mask, box->src, box->dst);
      *(box->dst) += op;
      break;
    case(0x0040):
      box->mask = 0xFFFF0000;
      box->src = regSelect(1,tmp & 0x0E00);
      box->dst = modSelect(input,1, &op);
      //add(box->mask, box->src, box->dst);
      *(box->dst) += op;
      //.w DN ea
      break;
    case(0x0080):
      box->mask = 0x00000000;
      box->src = regSelect(1,tmp & 0x0E00);
      box->dst = modSelect(input,1, &op);
      //add(box->mask, box->src, box->dst);
      *(box->dst) += op; 
      //.l DN ea
      break;
    case(0x0100):
      box->mask = 0xFFFFFF00;
      box->dst = regSelect(1,tmp & 0x0E00);
      box->src = modSelect(input,1, &op);
      //add(box->mask, box->src, box->dst);
      *(box->src) += op;
      //.b ea DN
      break;
    case(0x0120):
      box->mask = 0xFFFF0000;
      box->dst = regSelect(1,tmp & 0x0E00);
      box->src = modSelect(input, 1, &op);
      //add(box->mask, box->src, box->dst);
      *(box->src) += op;
      //.w ea DN
      break;
    case(0x0180):
      box->mask = 0x00000000;
      box->dst = regSelect(1,tmp & 0x0E00);
      box->src = modSelect(input, 1, &op);
      //add(box->mask, box->src, box->dst);
      *(box->src) += op
      //.l ea DN
      break; 
  }
  //call add(box->mask, box->src, box->dst)
  
}
uint32_t* modSelect(uint16_t input,int slew)
{
  switch (input & 0x001C)
  {
    case(0x0000):
      break;
    case(0x0001):
      break;
    case(0x0002):
      break;
    case(0x0003):
      break;
    case(0x0004):
      break;   
  }
}
