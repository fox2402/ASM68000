#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


void selectSubFunc(uint16_t input)
{
  uint32_t tmp = input;
  
  if(tmp & 0xC000)
  {
    switch(tmp & 0xF000)
    {
      case(0xD000):
        //ADD
        printf("ADD");
        break;
      case(0x9000):
        //SUB
        printf("SUB");
        break;
      case (0x4000):
        printf("jump instruction");
        //JSR RTS JMP
        break;
      
    }
  }
  else
  {
    printf("MOVE");
    //move
  }
}


int main()
{
  selectSubFunc(0xD456);
  selectSubFunc(0x0214);
  selectSubFunc(0x9022);
  selectSubFunc(0x4313);
  return 0;
}
