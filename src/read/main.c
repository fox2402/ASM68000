# include "head.h"
# include "test.h"


void push_label(struct label *l, char *subroutine, uint32_t adress) {
  struct label *res=malloc(sizeof(struct label));
  res->subroutine = subroutine;
  res->adress = adress;
  res->next=NULL;
  if(l){
    struct label *cur = l;
    for(; cur->next; cur=cur->next){}
    cur->next = res;
  }
  else
    l = res;
}

int main(int argc, char *argv[]){
  if (argc > 1) {
    int r;
    FILE *file = fopen(argv[1], "r");
    struct cpu cpu = *get_cpu();
    uint32_t pc = 0;
    struct label *l = malloc(sizeof(struct label));
    do { // 1st parsing label
      char **arg = arg_init();
      r = read_line(file,arg);
      if((arg[1]||arg[3]||arg[4]) && r) {
        pc += 2;
	if(strcmp(arg[1],"org")==0){
	  pc = conv_hex(arg[2]);
	}
	if(arg[0]){
          push_label(l,arg[0],pc);
	}
      }
      arg_free(arg);
    } while(r && (r!=-1));
    close(file);
    read_label(l);
    FILE *file2 = fopen(argv[1], "r");
    printf("\nParsing : \n");
    do { // 2nd parsing
      char **arg = arg_init();
      r = read_line(file2,arg);
      if((arg[0]||arg[1]||arg[3]||arg[4]) && r) {
        test_read(arg); // exec_line()
      }
      arg_free(arg);
    } while(r && (r!=-1));
    fclose(file);
    printf("\n");
//    cpu.RAM[0]=100;
    DUMPMEM(cpu.RAM, 2000*sizeof(uint16_t));
  }
  else
    err(1,"no arg");
  return 0;
}
