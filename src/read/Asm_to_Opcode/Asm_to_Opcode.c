# include <unistd.h>
# include <stdint.h>
# include <string.h>

int main()
{

}


char to_binary(char bin)
{
  //creve
  if (! bin)
  {
    return 0b00000000;
  }
  if (bin == 1)
  {
    return 0b00000001;
  }
  if (bin == 2)
  {
    return 0b00000010;
  }
  if (bin == 3)
  {
    return 0b00000011;
  }
  if (bin ==4)
  {
    return 0b00000100;
  }
  if (bin == 5)
  {
    return 0b00000101;
  }
  if (bin == 6)
  {
    return 0b00000110;
  }
  else
  {
    return 0b00000111;
  }
}


void ASM_To_OP(uint16_t * RAM, char ** text, uint32_t *PC)
{
  char kek;
  uint16_t opcode = 0;
  if (text[1] != NULL && strcmp(text[1],"MOVE") == 0)
  {
    opcode ^= (-0 ^ opcode) & (1 << 15);
    opcode ^= (-0 ^ opcode) & (1 << 14);
    if (text[2] != NULL && *text[2] == 'B' )
    {
      opcode ^= (-0 ^ opcode) & (1 << 13);
      opcode ^= (-1 ^ opcode) & (1 << 12);
      if(text[3] != NULL && *text[3] == 'D')
      {
        kek = to_binary(*(text[3]+1)-'0');
        opcode ^= (-0 ^ opcode) & (1 << 8);
        opcode ^= (-0 ^ opcode) & (1 << 7);
        opcode ^= (-0 ^ opcode) & (1 << 6);
        opcode ^= ((-(kek & 0b00000100) ^ opcode) & (1 << 11));
        opcode ^= ((-(kek & 0b00000010) ^ opcode) & (1 << 10));
        opcode ^= ((-(kek & 0b00000001) ^ opcode) & (1 << 9));
        if(text[4] != NULL && *text[4] == 'D')
        {
          kek = to_binary(*(text[4]+1)-'0');
          opcode ^= (-0 ^ opcode) & (1 << 5);
          opcode ^= (-0 ^ opcode) & (1 << 4);
          opcode ^= (-0 ^ opcode) & (1 << 3);
          opcode ^= ((-(kek & 0b00000100) ^ opcode) & (1 << 2));
          opcode ^= ((-(kek & 0b00000010) ^ opcode) & (1 << 1));
          opcode ^= ((-(kek & 0b00000001) ^ opcode) & (1 << 0));
          RAM[*PC] = opcode;
          *PC = *PC + 2;
        }
      }
    }
  }
}



