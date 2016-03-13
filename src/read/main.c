# include "head.h"
# include "test.h"

int main(int argc, char *argv[]){
  if (argc>1){
    int r;
    FILE *file = fopen(argv[1], "r");
    struct cpu *cpu = get_cpu();
    do {
      char **arg = arg_init();
      r = read_line(file,arg);
      if( r>2 ) {
        test_read(arg);  // exec_line()
      }
      arg_free(arg);
    } while(r && (r!=-1));
    fclose(file);
    dumpMem(cpu->RAM, 2000);
    delete_core(cpu);
  }
  else
    err(1,"no arg");
  return 0;
}
