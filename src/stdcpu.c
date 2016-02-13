# include "stdcpu.h"


struct cpu* get_cpu(void)
{
  int memsize = 2000;
  static struct cpu* main_core = NULL;
  if(main_core == NULL)
  {
    main_core = malloc(sizeof(struct cpu));
    main_core->RAM = malloc(memsize*sizeof(char));
    main_core->An = malloc(8*sizeof(uint32_t));
    main_core->Dn = malloc(8*sizeof(uint32_t));
    main_core->An[7] = memsize;
  } 
  return main_core;


}
void delete_core(struct cpu* c)
{
  free(c->RAM);
  free(c->An);
  free(c->Dn);
  free(c);

}
