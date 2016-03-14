# include "head.h"

char **arg_init(){
  size_t size = 10,s = 20;
  char **arg=malloc(size*sizeof(char*));
  for(size_t i=0; i<size; i++){
    arg[i]=malloc(s*sizeof(char));
  }
  return arg;
}

void arg_free(char **arg){
  for(int i=0;i<10;i++){
    free(arg[i]);
  }
  free(arg);
}

ssize_t read_line(FILE *file, char **arg){
  char *line = NULL;
  size_t j = 0, len;
  ssize_t r, i = 0 ;
  if ((r = getline(&line, &len, file)) != -1) {
    if(line[i] == ' ') {
      free(arg[0]);
      arg[0] = NULL;
      j++;
      i++;
    }
    while(i < r){
      size_t k = 0;
      while(line[i]==' '){
        i++;
      }
      if(line[i]==';'){
        break;
      }
      if(line[i]){
        while((line[i]!=' ')&&(line[i]!='.')&&(line[i]!='\n')
	    &&(line[i]!=',')&&(line[i]!=';')&&(i<=r)){
	  arg[j][k]=line[i];
	  i++;
	  k++;
        }
      }
      arg[j][k]='\0';
      if(arg[j][0]=='\0'){
	free(arg[j]);
	arg[j]=NULL;
      }
      i++;
      j++;
    }
  }
  for(;j < 10; j++) {
    free(arg[j]);
    arg[j] = NULL;
  }
  if(arg[2]) {
    if(strlen(arg[2])>1){
      arg[4]=arg[3];
      arg[3]=arg[2];
      arg[2]=NULL;
    }
  }
  return r;
}
