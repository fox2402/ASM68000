# include "test.h"

void test_read(char **arg){

  for(int i=0; i<5; i++){
    if(arg[i]!=NULL) {
      printf("%s|",arg[i]);
    }
    else
      printf(" |");
  }
  printf("\n");
}

void read_label(struct label *l) {
  printf("List of labels : \n");
  for(struct label *cur = l; cur; cur = cur->next) {
    printf("(%s, $%04x) -> ", cur->subroutine, cur->adress);
  }
  printf("\n");
}
