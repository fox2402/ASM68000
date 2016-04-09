# include "stdcpu.h"


static struct cpu* get_cpu(void)
{
  int i;
  struct cpu* main_core = NULL;
  if(main_core == NULL)
  {
    main_core = malloc(sizeof(struct cpu));
    main_core->PC = 0;
    main_core->SR = 0;
    main_core->A[8] = 0;
    for(i =0; i<8;i++)
    {
      main_core->A[i]=0;
      main_core->D[i]=0;
    }
    for(i =0; i<8192;i++)
    {
      main_core->RAM[i] = 0;
    }
  }
  return main_core;


}
void delete_core(struct cpu* c)
{
  free(c);
}
