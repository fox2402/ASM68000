# include "head.h"
# include "test.h"

int main(int argc, char *argv[]){
  if (argc>1){
    int r;
    FILE *file = fopen(argv[1], "r");
    char **arg=arg_init();
    while((r=read_line(file,arg)) && (r!=-1)){
      test_read(arg);  // exec_line()
    }
    fclose(file);
    arg_free(arg);
  }
  else
    err(1,"no arg");
  return 0;
}
