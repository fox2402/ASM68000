# include "head.h"

char **arg_init(){
  size_t size = 20,s = 20;
  char **arg=malloc(size*sizeof(char*));
  for(size_t i=0; i<size; i++){
    arg[i]=malloc(s*sizeof(char));
  }
  return arg;
}

void arg_free(char **arg){
  for(int i=0;i<20;i++){
    free(arg[i]);
  }
  free(arg);
}

ssize_t read_line(FILE *file, char **arg){
  char *line=NULL;
  size_t j=0,len;
  ssize_t r,i=0;
  if ((r = getline(&line, &len, file)) != -1) {
    while(i<r){
      size_t k=0;
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
      i++;
      j++;
    }
    arg[j]=NULL;
  }
  return r;
}
