# include "test.h"

void test_read(char **arg){
  for(int i=0; arg[i]!=NULL; i++){
    printf("%s ",arg[i]);
  }
  printf("\n");
}
