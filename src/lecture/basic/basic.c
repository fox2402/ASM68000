# include "basic.h"
# include "../head.h"
# include <ctype.h>

int conv_hex(char *num);
int conv_bin(char *num);


int get_number (char *arg) {
  int num;
  switch (arg[1]) {
    case '$' :
      num = conv_hex(arg);
      break;
    case '%' :
      num = conv_bin(arg);
      break;
    default :
      num = atoi(arg+1);
      break;
  }
  return num;
}

int conv_hex(char *num){
  int res=0;
  int size = strlen(num);
  for(int i=0;i<size;i++){
    if(num[size-i-1] <= '9' && num[size-i-1] >= '0'){
      res += (num[size-i-1]-'0') * pow(16,i);
    }
    else{
      char c = tolower(num[size-i-1]);
      if(c <= 'f' && c >= 'a'){
        res += (c-'a'+10) * pow(16,i);
      }
    }
  }
  return res;
}

int conv_bin(char *num){
  int res=0;
  int size = strlen(num);
  for(int i=0;i<size;i++){
    if(num[size-i-1]=='1'){
      res+=pow(2,i);
    }
  }
  return res;
}
// TEST
int main (){
  char *str="#$1A";
  //printf("%c\n",str[strlen(str)-1]);
  printf("%d\n",get_number(str));
  return 0;
}

